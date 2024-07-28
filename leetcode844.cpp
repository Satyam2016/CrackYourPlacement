// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

// Note that after backspacing an empty text, the text will continue empty.

 

// Example 1:

// Input: s = "ab#c", t = "ad#c"
// Output: true
// Explanation: Both s and t become "ac".
// Example 2:

// Input: s = "ab##", t = "c#d#"
// Output: true
// Explanation: Both s and t become "".
// Example 3:

// Input: s = "a#c", t = "b"
// Output: false
// Explanation: s becomes "c" while t becomes "b".

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> a;
        stack<char> b;
        int n1=s.size();
        int n2=t.size();
        for(int i=0;i<n1; i++){
            if(s[i]!='#'){
                a.push(s[i]);
            }else if(!a.empty()){
                a.pop();
            }
        }
        for(int i=0;i<n2; i++){
            if(t[i]!='#'){
                b.push(t[i]);
            }else if(!b.empty()){
                b.pop();
            }
        }
        if(a.size()!=b.size()){
            return false;
        }
        int n=a.size();
        while(n--){
            if(a.top()!=b.top()){
                return false;
            }
            a.pop();
            b.pop();
        }
        return true;
    }
};