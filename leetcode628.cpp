// Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

// Example 1:

// Input: nums = [1,2,3]
// Output: 6
// Example 2:

// Input: nums = [1,2,3,4]
// Output: 24
// Example 3:

// Input: nums = [-1,-2,-3]
// Output: -6

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // int n=nums.size();
        // return max(nums[n-1]*nums[n-2]*nums[n-3], nums[0]*nums[1]*nums[n-1]);
        
        int a = nums[0], b = nums[1], c = nums[2];
        if (a > b) {
            swap(a, b);
        }
        if (a > c) {
            swap(a, c);
        }
        if (b > c) {
            swap(b, c);
        }

        int top1 = c, top2 = b, top3 = a;
        int bot1 = a, bot2 = b;
        for (int i = 3; i < ssize(nums); ++i) {
            if (nums[i] <= bot1) {
                bot2 = bot1;
                bot1 = nums[i];
            } else if (nums[i] <= bot2) {
                bot2 = nums[i];
            }
            if (nums[i] >= top1) {
                top3 = top2;
                top2 = top1;
                top1 = nums[i];
            } else if (nums[i] >= top2) {
                top3 = top2;
                top2 = nums[i];
            } else if (nums[i] >= top3) {
                top3 = nums[i];
            }
        }
        return max(top1*top2*top3, top1*bot1*bot2);
    }
};