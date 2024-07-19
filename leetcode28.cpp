// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

// Example 1:

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.
// Example 2:

// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.A

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        int m=haystack.size();
        int n=needle.size();
        if(n>m) return -1;
        for(int i=0; i<=m-n; i++){
            int j=0;
            while (j < n && haystack[i + j] == needle[j]) {
                j++;
            }
            if(j==n) return i;
        }
        return -1;
    }
};