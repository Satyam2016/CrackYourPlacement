// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
 

 class Solution {
public:
    void backtrack(stack<char> para, int openN, int closeN, int n, vector<string>& ans){
        if(openN==n && closeN==n){
            string s="";
            while (!para.empty()) {
                s.push_back(para.top());
                para.pop();
            }
            reverse(s.begin(), s.end());
            ans.push_back(s);
            return ;
        }
        if(openN<n){
            para.push('(');
            backtrack(para, openN+1, closeN, n, ans);
            para.pop();
        }
        if(closeN<openN){
            para.push(')');
            backtrack(para, openN, closeN+1, n, ans);
            para.pop();
        }
    }
    vector<string> generateParenthesis(int n) {
        stack<char> para;
        vector<string> ans;
        backtrack(para, 0,0, n, ans);
        return ans;
    }
};