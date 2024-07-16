// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.

 

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3
// Example 3:

// Input: nums = [3,3,3,3,3]
// Output: 3

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     // sol-1 
     // time complexity O(nlogn) and space complexity O(1)
        // sort(nums.begin(), nums.end());
        // for(int i=1; i<nums.size(); i++){
        //     if(nums[i]==nums[i-1]){
        //         return nums[i];
        //     }
        // }
        // return -1;

     // sol-2
     // time complexity O(n) and space complexity O(1)
        int i=1;
        while(1){
            int val=nums[i];
            if((nums[val]==val && val!=i) || nums[0]==val){
                return val;
            }
            if(nums[val]!=val){
                    swap(nums[val], nums[i]);
            }
            else{
                i++;
            }
        }
        return -1;
    }
};