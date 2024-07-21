// Given an array arr[] of size n and an integer x, return 1 if there exists a pair of elements in the array whose absolute difference is x, otherwise, return -1.

// Example 1:

// Input:
// n = 6
// x = 78
// arr[] = {5, 20, 3, 2, 5, 80}
// Output:
// 1
// Explanation:
// Pair (2, 80) have absolute difference of 78.
// Example 2:

// Input:
// n = 5
// x = 45
// arr[] = {90, 70, 20, 80, 50}
// Output:
// -1
// Explanation:
// There is no pair with absolute difference of 45.

class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        int i=0, j=1;
        while(i<n && j<n){
            if(i!=j && (arr[j]-arr[i])==x) return 1;
            if((arr[j]-arr[i]) < x) j++;
            else i++;
        }
        return -1;
    }
    
};
