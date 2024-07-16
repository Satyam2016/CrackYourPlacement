// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]



class Solution {
public:
    void sortColors(vector<int>& nums) {
            // sol-1     
            // time complexity O(n*n) and space complexity O(1)
        // for(int j=0;j<nums.size();j++){
        //     for(int i=0;i<nums.size();i++){
        //         if(nums[i]>nums[j]){
        //             int t=nums[i];
        //             nums[i]=nums[j];
        //             nums[j]=t;
        //         }    
        //     }
        // }


          // sol-2
     // time complexity O(nlogn) and space complexity O(1)
          //    sort(nums.begin(), nums.end());

          // sol-3
          // time complexity O(n) and space complexity O(1)

        int low=0, mid=0, high=nums.size()-1;

        while(high>=mid){
            if(nums[mid]==0){
              swap(nums[low], nums[mid]);
              low++;
              mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};