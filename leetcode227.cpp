// Given a string s which represents an expression, evaluate this expression and return its value. 

// The integer division should truncate toward zero.

// You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

// Example 1:

// Input: s = "3+2*2"
// Output: 7
// Example 2:

// Input: s = " 3/2 "
// Output: 1
// Example 3:

// Input: s = " 3+5 / 2 "
// Output: 5

class Solution {
public:
    int calculate(string s) {
        int len=s.size();
        stack<int> exp;
        int number=0;
        char sign='+';
        for(int i=0; i<len; i++){
            char currentchar = s[i];
            if(isdigit(currentchar)){
                number=number*10+(currentchar-'0');
            }
            if(!isdigit(currentchar) && !iswspace(currentchar) || i==len-1){
                if(sign=='+'){
                    exp.push(number);
                }else if(sign=='-'){
                    exp.push(-number);
                }else if(sign=='*'){
                    int stacktop=exp.top();
                    exp.pop();
                    exp.push(stacktop*number);
                }else if(sign=='/'){
                    int stacktop=exp.top();
                    exp.pop();
                    exp.push(stacktop/number);
                }
                number=0;
                sign=currentchar;
            }
        }
        int total=0;
        while(!exp.empty()){
            total+=exp.top();
            exp.pop();
        }
        return total;
    }
};