// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // int flag=0;
        // vector<int> index_list(2,0);
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]+nums[j]==target){
        //             index_list[0]=i;
        //             index_list[1]=j;
        //             flag=1;
        //             break;
        //         }
        //     }
        //     if(flag==1){
        //         break;
        //     }
        // }
        // return index_list;
        
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(mpp.find(target-nums[i])!=mpp.end()){
                ans.push_back(i);
                ans.push_back(mpp[target-nums[i]]);
                break;
            }
            mpp[nums[i]]=i;
        }
        return ans;
    }
};