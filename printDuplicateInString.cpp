// Given a string S, the task is to print all the duplicate characters with their occurrences in the given string.

// Example:

// Input: S = “geeksforgeeks”
// Output:

// e, count = 4
// g, count = 2
// k, count = 2
// s, count = 2

// Explanation: e,g,k,and s are characters which are occured in string in more than one times.

#include<bits/stdc++.h>
using namespace std;

void printDuplicate(string s){
    unordered_map<char,int> m;
    for(int i=0; i<s.size(); i++){
        m[s[i]]++;
    }
    for(auto x: m){
        if(x.second>1){
            cout<<x.first<<", count = "<<x.second<<endl;
        }
    }
}

int main(){
    string s = "geeksforgeeks";
    printDuplicate(s);
    return 0;
}
