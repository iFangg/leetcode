// Solution 1
class Solution {
public:
    int minLength(string s) {
        /*
        scan intial string for filter strings
        return string length if no filters exist
        else NO
            recursive backtracking solution to find minimum possible string length
            every time we come across the filter,
                cut out filter and recurse with new string
            
            recurse until string has no filters left
            OVERCOMPLICATED
        
        use a stack
            if current letter and top of stack make filter, pop top of stack and cont
        */
        auto char_stack = std::stack<char>{};
        char_stack.push(s[0]);

        for (auto i = 1; i < s.size(); ++i) {
            auto filter = std::string{};
            if (!char_stack.empty())
                filter += char_stack.top();
            filter += s[i];

            if (filter == "AB" or filter == "CD")
                char_stack.pop();
            else
                char_stack.push(s[i]);
        }

        return char_stack.size();
    }
};


// Solution 2
class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(!st.empty() && ((st.top() == 'A' && s[i] == 'B') ||
                
                (st.top() =='C' && s[i]=='D')
                 
                )){
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
      
        return st.size();

    }
};
