// Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.


// Example 1:

// Input:
// nums = {2, 8, 5, 4}
// Output:
// 1
// Explanation:
// swap 8 with 4.
// Example 2:

// Input:
// nums = {10, 19, 6, 3, 5}
// Output:
// 2
// Explanation:
// swap 10 with 3 and swap 19 with 5.

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int, int>> v;
	    int n=nums.size();
	    for(int i=0; i<n; i++){
	       v.push_back({nums[i],i});
	    }
	    int swaps=0;
	    sort(v.begin(), v.end());
	    for(int i=0; i<n; i++){
	        if(v[i].second!=i){
	            swaps++;
	            swap(v[i], v[v[i].second] );
	            i--;
	        }
	    }
	    return swaps;
	}
};