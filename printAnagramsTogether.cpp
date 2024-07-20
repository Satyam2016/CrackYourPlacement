// Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.

// Note: The final output will be in lexicographic order.


// Example 1:

// Input:
// N = 5
// words[] = {act,god,cat,dog,tac}
// Output:
// act cat tac 
// god dog
// Explanation:
// There are 2 groups of
// anagrams "god", "dog" make group 1.
// "act", "cat", "tac" make group 2.
// Example 2:

// Input:
// N = 3
// words[] = {no,on,is}
// Output: 
// is
// no on
// Explanation:
// There are 2 groups of
// anagrams "is" makes group 1.
// "no", "on" make group 2.

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        unordered_map<string, int> mpp;
        vector<vector<string>> ans;
        for(int i=0; i<string_list.size(); i++){
            string s=string_list[i];
            sort(s.begin(), s.end());
            if(mpp.find(s)!=mpp.end()){
                ans[mpp[s]].push_back(string_list[i]);
            }else{
                mpp[s]=ans.size();
                ans.push_back({string_list[i]});
            }
        }
        return ans;
    }
};