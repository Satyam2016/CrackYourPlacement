// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int cnt=0;
        // for(int i=0; i<nums.size(); i++){
        //     int sum=0;
        //     for(int j=i; j<nums.size(); j++){
        //         sum+=nums[j];
        //         if(sum==k){
        //              cnt++; 
        //         }
        //     }
        // }
        // return cnt;
        unordered_map<int, int>mpp;
        mpp[0]=1;
        int presum=0, cnt=0;
        for(int i=0; i<nums.size();i++){
            presum+=nums[i];
            int left=presum-k;
            cnt+=mpp[left];
            mpp[presum]+=1;
        }
        return cnt;
    }
};