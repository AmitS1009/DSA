class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> ans;

        for (int i = 0; i < exp.length(); i++) {
            if (exp[i] == '*' || exp[i] == '+' || exp[i] == '-') {
                vector<int> left = diffWaysToCompute(exp.substr(0, i));
                vector<int> right = diffWaysToCompute(exp.substr(i + 1));

                for (auto l : left) {
                    for (auto r : right) {
                        if (exp[i] == '*') ans.push_back(l * r);
                        else if (exp[i] == '+') ans.push_back(l + r);
                        else ans.push_back(l - r);
                    }
                }
            }
        }

        if (ans.empty()) ans.push_back(stoi(exp));
        return ans;
    }
};
