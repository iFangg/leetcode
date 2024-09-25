// Solution 1 - TOO SLOW
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        /*
        for every prefix of current string
            find how many other words in the vector have that same prefix
        */

        auto scores = std::vector<int>(words.size(), 0);

        for (auto i = 0; i < words.size(); ++i) {
            auto curr = std::string{words[i][0]};
            auto index = 1;
            auto total = 0;
            
            while (curr.size() <= words[i].size()) {
                for (auto& w : words) {
                    if (curr == w.substr(0, curr.size()))
                        total++;
                }

                curr += words[i][index];
                index++;
            }

            scores[i] = total;
        }

        return scores;
    }
};


// Solution 2- FASTER, but still TOO SLOW
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        auto scores = std::vector<int>(words.size(), 0);
        auto prefixes = std::unordered_map<std::string, int>{};

        for (auto i = 0; i < words.size(); ++i) {
            for (auto j = 1; j <= words[i].size(); ++j) {
                auto prefix = words[i].substr(0, j);
                if (!prefixes.contains(prefix))
                    prefixes[prefix] = 0;
                
                prefixes[prefix]++;
            }
        }

        for (auto i = 0; i < words.size(); ++i) {
            auto total = 0;
            for (auto j = 1; j <= words[i].size(); ++j) {
                auto prefix = words[i].substr(0,j);
                total += prefixes[prefix];
            }

            scores[i] = total;
        }

        return scores;
    }
};


// Solution 3
struct Node{
    int count=0;
    Node *list[26]={NULL};
    bool containKey(char ch){
        return list[ch-'a']!=NULL;
    }
    Node *get(char ch){
        return list[ch-'a'];
    }
    void put(char ch,Node *new_node){
        list[ch-'a']=new_node;
    }
    void inc(char ch){
        list[ch-'a']->count+=1;
    }
    int retCount(char ch){
        return list[ch-'a']->count;
    }
};
class Solution {
private:
Node *root;
public:
    Solution(){
        root=new Node;
    }
    void insert(string word){
        Node *node=root;
        for(auto ch:word){
            if(!node->containKey(ch)){
                node->put(ch,new Node);
            }
            node->inc(ch);
            node=node->get(ch);
        }
    }
    int search(string word){
        Node *node=root;
        int preCount=0;
        for(auto ch:word){
            preCount+=node->retCount(ch);
            node=node->get(ch);
        }
        return preCount;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        //This problem can be solved using the trie data structure
        for(auto word:words){
            insert(word);
        }
        int n=words.size();
        vector<int>res(n);
        for(int i=0;i<n;i++){
            int preCount=search(words[i]);
            res[i]=preCount;
        }
        return res;
    }
};
