// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix="";
        int flag=0;
        for(int i=0; i<strs[0].size(); i++){
            for(int k=1; k<strs.size(); k++){
                if(strs[0][i]!=strs[k][i]){
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                break;
            }
            else{
                prefix+=strs[0][i];        
            }
        }
        return prefix;
        // sort(strs.begin(), strs.end());
        // int n=strs.size();
        // string s=strs[0], l=strs[n-1], ans="";
        // for(int i=0; i<s.size(); i++){
        //     if(s[i]==l[i]) {
        //         ans+=s[i];
        //     }else{
        //         break;
        //     }
        // }
        // return ans;
    }
};