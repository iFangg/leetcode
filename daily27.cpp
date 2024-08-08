// Solution 1 - too slow
class Solution {
public:
    std::unordered_map<std::string, int> get_num(std::unordered_map<std::string, int>& chems, string& formula, int& pos) {
        // keep track of chemicals in current level
        std::unordered_map<std::string, int> curr_chems{};
        auto prev = std::string{""};

        while (pos < formula.size()) {
            auto& c = formula[pos];
            // go down another level of recursion
            if (c == '(') {
                pos++;
                auto next = get_num(chems, formula, pos);
                for (const auto& ch : next) {
                    if (curr_chems.contains(ch.first))
                        curr_chems[ch.first] += ch.second;
                    else
                        curr_chems[ch.first] = ch.second;
                }
                continue;
            }

            // check multiplier
            // come up one level of recursion
            if (c == ')' or std::isdigit(c)) {
                auto next = pos + 1;
                if (next < formula.size()) {
                    if (!std::isdigit(formula[next])) {
                        if (c == ')')
                            return curr_chems;
                        else
                            if (curr_chems.contains(prev))
                                curr_chems[prev]++;
                            continue;
                    }
                    
                    auto num_str = std::string{""};
                    while (next < formula.size()) {
                        if (!std::isdigit(formula[next]))
                            break;
                        num_str += formula[next];
                        next++;
                    }

                    auto num = std::stoi(num_str);
                    if (c == ')') {
                        for (auto& elem : curr_chems) {
                            elem.second *= num;
                        }
                    } else {
                        if (!prev.empty())
                            curr_chems[prev] *= num;
                        
                        prev.clear();
                    }
                }

                return curr_chems;
            }

            // add current element
            if (!std::isdigit(c)) {
                auto name = std::string{""};
                name += c;
                auto next = pos + 1;
                if (next < formula.size()) {
                    while (next < formula.size() and !std::isdigit(formula[next])) {
                        if (!std::islower(formula[next]))
                            break;

                        name += formula[next];
                        next++;
                    }

                }

                if (!curr_chems.contains(name))
                    curr_chems[name] = 1;

                prev = name;
            }

            pos++;
        }

        if (!prev.empty())
            curr_chems[prev]++;

        return curr_chems;
    }

    string countOfAtoms(string formula) {
        auto pos = 0;
        std::unordered_map<std::string, int> chems{};
        auto res = get_num(chems, formula, pos);

        std::vector<std::pair<std::string, int>> atoms(res.begin(), res.end());
        std::sort(atoms.begin(), atoms.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            return a.first < b.first;
        });

        auto all_atoms = std::string{""};
        for (auto i : atoms) {
            all_atoms += i.first;
            all_atoms += std::to_string(i.second);
        }

        return all_atoms;
    }
};


// Solution 2
class Solution {
public:
    std::unordered_map<std::string, int> get_num(std::unordered_map<std::string, int>& chems, string& formula, int& pos) {
        // keep track of chemicals in current level
        std::unordered_map<std::string, int> curr_chems{};
        auto prev = std::string{""};

        while (pos < formula.size()) {
            auto& c = formula[pos];
            // go down another level of recursion
            if (c == '(') {
                pos++;
                auto next = get_num(chems, formula, pos);
                for (const auto& ch : next) {
                    if (curr_chems.contains(ch.first))
                        curr_chems[ch.first] += ch.second;
                    else
                        curr_chems[ch.first] = ch.second;
                }
                continue;
            }

            // check multiplier
            // come up one level of recursion
            if (c == ')' or std::isdigit(c)) {
                auto next = pos + 1;
                if (next < formula.size()) {
                    if (!std::isdigit(formula[next])) {
                        if (c == ')')
                            return curr_chems;
                        else
                            if (curr_chems.contains(prev))
                                curr_chems[prev]++;
                            continue;
                    }
                    
                    auto num_str = std::string{""};
                    while (next < formula.size()) {
                        if (!std::isdigit(formula[next]))
                            break;
                        num_str += formula[next];
                        next++;
                    }

                    auto num = std::stoi(num_str);
                    if (c == ')') {
                        for (auto& elem : curr_chems) {
                            elem.second *= num;
                        }
                    } else {
                        if (!prev.empty())
                            curr_chems[prev] *= num;
                        
                        prev.clear();
                    }
                }

                return curr_chems;
            }

            // add current element
            if (!std::isdigit(c)) {
                auto name = std::string{""};
                name += c;
                auto next = pos + 1;
                if (next < formula.size()) {
                    while (next < formula.size() and !std::isdigit(formula[next])) {
                        if (!std::islower(formula[next]))
                            break;

                        name += formula[next];
                        next++;
                    }

                }

                if (!curr_chems.contains(name))
                    curr_chems[name] = 1;

                prev = name;
            }

            pos++;
        }

        if (!prev.empty())
            curr_chems[prev]++;

        return curr_chems;
    }

    string countOfAtoms(string formula) {
        auto pos = 0;
        std::unordered_map<std::string, int> chems{};
        auto res = get_num(chems, formula, pos);

        std::vector<std::pair<std::string, int>> atoms(res.begin(), res.end());
        std::sort(atoms.begin(), atoms.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            return a.first < b.first;
        });

        auto all_atoms = std::string{""};
        for (auto i : atoms) {
            all_atoms += i.first;
            all_atoms += std::to_string(i.second);
        }

        return all_atoms;
    }
};

// Solution 3
class Solution 
{
    struct Element
    {
        string el;
        int count;
    };
public:
    string countOfAtoms(string formula) {
        
        vector<Element> form{};
        
        auto num = 0;
        for (auto r = 0; r < std::size(formula); r++)
        {
            if (formula[r] == '(')
            {
                form.push_back({"(", 0});
            }
            else if (formula[r] == ')')
            {
                form.push_back({")", 0});
            }
            else if (isdigit(formula[r]))
            {
                auto num = formula[r] - '0';
                while (r+1 < std::size(formula) && isdigit(formula[r+1]))
                {
                    num = num*10+(formula[++r]-'0');
                }
                auto& prev = form.back();
                if (prev.count == 1)
                {
                    prev.count = 0;
                }
                form.back().count += num;
            }
            else if (isupper(formula[r]))
            {
                string element = {};
                element += formula[r];
                while (r+1 < std::size(formula) && islower(formula[r+1]))
                {
                    element += formula[++r];
                }
                form.push_back({element, 1});
            }
        }
        
        deque<int> open{};
        
        for (auto i = 0; i < std::size(form); i++)
        {
            if (form[i].el == "(")
            {
                open.push_back(i+1);
            }
            else if (form[i].el == ")")
            {
                if (form[i].count == 0)
                {
                    open.pop_back();
                    continue;
                }
                auto multiplier = form[i].count;
                auto start = open.back();
                open.pop_back();
                for(; start < i; start++)
                {
                    form[start].count*=multiplier;
                }
            }
        }
        
        map<string, int> elementCounts{};
        for (auto& element: form)
        {
            if (element.el != "(" && element.el != ")")
            {
                elementCounts[element.el] += element.count;
            }
        }
        string output = {};
        for (auto& [k, v] : elementCounts)
        {
            output += k;
            if (v > 1)
            {
                output += to_string(v);
            }
        }
        return output;
    }
};
