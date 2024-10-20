// Solution 1
class Solution {
public:
    bool parseBoolExpr(string expr) {
        if (expr.size() == 1) {
            if (expr[0] == 't')
                return true;
            
            return false;
        }

        if (expr[0] == '&') {
            index += 2;
            return eval_expr(expr, true);
        }

        if (expr[0] == '|') {
            index += 2;
            return eval_expr(expr, false);
        }
        
        if (expr[0] == '!') {
            index += 2;
            return !eval_expr(expr, false);
        }

        return false;
    }

private:
        /*
        keep track of current expression
        recursive solution
        
        any & ! or | will be immediately followed by a bracket
            brackets will only appear for these compound expressions
            inside brackets may be another operation or subexpressions
            subtring to be passed in can be cut 2 indexes ahead instead of 1

            while closing brace has not been found, determine next 
        
        else gather subexpressions and evaluate
        */
        
    bool eval_expr(std::string expr, bool is_and) {
        auto subexprs = std::vector<bool>{};

        while (index < expr.size() and expr[index] != ')') {
            // std::cout << expr[index] << std::endl;
            // find sub expressions
            if (expr[index] == '&') {
                // figure out all subexpr's with a while loop?
                index += 2;
                subexprs.push_back(eval_expr(expr, true));
            } else if (expr[index] == '|') {
                index += 2;
                subexprs.push_back(eval_expr(expr, false));
            } else if (expr[index] == '!') {
                index += 2;
                subexprs.push_back(!eval_expr(expr, false));
            } else {
                if (expr[index] == 't')
                    subexprs.push_back(true);
                else if (expr[index] == 'f')
                    subexprs.push_back(false);
            }

            index++;
        }

        bool res = subexprs[0];

        for (auto i = 1; i < subexprs.size(); ++i) {
            if (is_and)
                res &= subexprs[i];
            else
                res |= subexprs[i];
        }

        return res;
    }

    int index = 0;
};


// Solution 2
class Solution {
public:
    bool andd(string exp){
        int n = exp.length(), j=0;
        string subexp;
        int active = 0;
        while(j<n){
            if(active == 0 && exp[j]==','){
                if(!parseBoolExpr(subexp)) return false;
                subexp = "";
                j++;
                continue;
            }
            if(exp[j]=='(') active++;
            if(exp[j]==')') active--;
            subexp += exp[j++];
        }
        if(!parseBoolExpr(subexp)) return false;
        return true;
    }

    bool orr(string exp){
        int n = exp.length(), j=0;
        string subexp;
        int active = 0;
        while(j<n){
            if(active==0 && exp[j]==','){
                if(parseBoolExpr(subexp)) return true;
                subexp = "";
                j++;
                continue;
            }
            if(exp[j]=='(') active++;
            if(exp[j]==')') active--;
            subexp += exp[j++];
        }
        if(parseBoolExpr(subexp)) return true;
        return false;
    }

    bool parseBoolExpr(string exp) {
        int n = exp.length();
        if(n==1) return (exp[0]=='t');
        if(exp[0] == '!') return !parseBoolExpr(exp.substr(2, n-3));
        if(exp[0] == '&') return andd(exp.substr(2, n-3));
        if(exp[0] == '|') return orr(exp.substr(2, n-3));
        return false;
    }
};
