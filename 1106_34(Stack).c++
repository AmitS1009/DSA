// I could right this much only (On the way to be Sadist) : 


class Solution {
public:

    bool solve(vector<char> s, char op){
        // code
    }

    bool parseBoolExpr(string exp) {
        int n = exp.size();

        stack<char> st;
        vector<char>s;

        for(int i=0; i<n; i++){
            st.push(s[i]);
            if(s[i] == ')') {
                break;
                s.push_back(st.pop());
                return solve(s, op)
            }
        }

    }
};


// right one : 

class Solution {
public:
    // Function to evaluate the subexpression given the operator
    bool solve(vector<char> &s, char op) {
        bool result;
        
        if (op == '&') {
            result = true;  // Initialize as true, as AND requires all true
            for (char c : s) {
                if (c == 'f') {
                    result = false;  // If any false, AND results in false
                    break;
                }
            }
        } else if (op == '|') {
            result = false;  // Initialize as false, as OR requires any true
            for (char c : s) {
                if (c == 't') {
                    result = true;  // If any true, OR results in true
                    break;
                }
            }
        } else if (op == '!') {
            result = (s[0] == 'f');  // NOT just flips a single boolean value
        }
        
        return result;
    }

    bool parseBoolExpr(string exp) {
        stack<char> st;

        for (char c : exp) {
            if (c == ',') continue;  // Skip commas
            if (c != ')') {
                st.push(c);  // Push all characters except ')'
            } else {
                // When encountering a closing bracket ')', process the expression inside
                vector<char> s;
                while (!st.empty() && st.top() != '(') {
                    s.push_back(st.top());  // Collect the expression
                    st.pop();
                }

                st.pop();  // Pop the '('
                char op = st.top();  // Get the operator (&, |, !)
                st.pop();  // Remove the operator
                
                // Solve the subexpression
                bool res = solve(s, op);
                
                // Push the result back into the stack
                st.push(res ? 't' : 'f');
            }
        }
        
        // The final result is the only element left in the stack
        return st.top() == 't';
    }
};
