// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int max=0,pre=0;
        // int index=0;
        // for(int i=0;i<nums.size()-1;i++){
        //     if(nums[i]==nums[i+1]){
        //         max++;
        //         if(pre<max){
        //             pre=max;
        //             index=i;
        //         }
        //     }
        //     else{
        //         if(pre==max){
        //             pre=max+1;
        //         }
        //         max=1;
        //     }
        // }
        // return nums[index];
        int cnt=0;
        int ele;
        for(int i=0; i<nums.size(); i++){
            if(cnt==0){
                cnt=1;
                ele=nums[i];
            }else if(ele==nums[i])  cnt++;
            else cnt--;
        }
        return ele;

    }
};