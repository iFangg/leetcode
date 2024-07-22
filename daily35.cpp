// Solution 1
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        auto indices = std::vector<int>(names.size(), 0);
        for (auto i = 0; i < names.size(); ++i) {
            indices[i] = i;
        }

        std::sort(indices.begin(), indices.end(), [&heights](int a, int b) {
            return heights[a] > heights[b];
        });

        auto new_names = std::vector<string>(names.size());
        for (auto i = 0; i < indices.size(); ++i) {
            std::cout << indices[i] << ", ";
            new_names[i] = names[indices[i]];
        }

        return new_names;
    }
};


// Solution 2
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        std::vector<std::pair<std::string, int>> pairs{};
        for (std::size_t i = 0; i < names.size(); i++)
            pairs.push_back(std::make_pair(names[i], heights[i]));

        std::sort(std::execution::par_unseq, pairs.begin(), pairs.end(), [](const auto& a, const auto& b) -> bool
        {
            return a.second > b.second;
        });

        std::vector<std::string> ret;
        for (const auto& p : pairs)
            ret.push_back(p.first);

        return ret;
    }
};
