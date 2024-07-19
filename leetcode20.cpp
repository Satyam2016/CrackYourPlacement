// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false

class Solution {
public:
    bool isValid(string s) {
        // stack<char> a;
        // if(s.length()%2!=0){
        //     return false;
        // }
        // int c=0;
        // for(int i=0;i<s.length() ; i++){
        //     if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
        //         a.push(s[i]);
        //         c++;
        //     }
        //     else if((s[i]==')' || s[i]==']' || s[i]=='}') && i!=0 && !a.empty()){
        //        if(isMatching(a.top(),s[i]) && !a.empty()){
        //            a.pop();
        //        } 
        //        else{
        //            return false;
        //        }
        //     }
        // }
        // if(c==(s.length())/2 && a.empty() ){
        //     return true;
        // }
        // else{
        //     return false;
        // }

        stack<char> a;
        if(s.size()%2!=0){
            return false;
        }
        int c=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                a.push(s[i]);
            }else if(a.empty()){
                return false;
            }
            else if((s[i] == ')' && a.top() == '(') ||
                (s[i] == ']' && a.top() == '[') ||
                (s[i] == '}' && a.top() == '{')) {
                a.pop();
            }
            else{
                return false;
            }
        }
        return a.empty();
    }

private:
    bool isMatching(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '[' && close == ']') ||
               (open == '{' && close == '}');
    }
};