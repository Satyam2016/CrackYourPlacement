// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.






class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       
        // set<vector<int>> st;
        // int n=nums.size();
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         for(int k=j+1; k<n; k++){
        //             if(nums[i]+nums[j]+ nums[k]==0){
        //                 vector<int> temp= {nums[i], nums[j], nums[k]};
        //                 sort(temp.begin(), temp.end());
        //                 st.insert(temp);
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>> ans(st.begin(), st.end());
        // return ans;

        // int n=nums.size();
        // set<vector<int>> st;
        // for(int i=0; i<n; i++){
        //     set<int> tempset;
        //     for(int j=i+1; j<n; j++){
        //         int remain=-(nums[i]+nums[j]);
        //         if(tempset.find(remain)!=tempset.end()){
        //             vector<int> temp={nums[i], nums[j], remain};
        //             sort(temp.begin(), temp.end());
        //             st.insert(temp);
        //         }
        //         tempset.insert(nums[j]);
        //     }
        // }        
        // vector<vector<int>> ans(st.begin(), st.end());
        // return ans;


        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // set<vector<int>> set;
        // vector<vector<int>> output;
        // for(int i=0; i<n-2; i++){
        //     int low = i+1, high = n-1;
        //     while(low < high){
        //         if(nums[i] + nums[low] + nums[high] < 0){
        //             low++;
        //         }
        //         else if(nums[i] + nums[low] + nums[high] > 0){
        //             high--;
        //         }
        //         else{
        //             set.insert({nums[i], nums[low], nums[high]});
        //             low++;
        //             high--;
        //         }
        //     }
        // }
        // for(auto it : set){
        //     output.push_back(it);
        // }
        // return output;

        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int low=i+1;
            int high=n-1;
            while(low<high){
                int sum=nums[i]+nums[low]+nums[high];
                if(sum<0){
                    low++;
                }else if(sum>0){
                    high--;
                }
                else{
                    vector<int> temp={nums[i], nums[low],nums[high]};
                    ans.push_back(temp);
                    low++;
                    high--;
                    while(low<high && nums[low]==nums[low-1]) low++;
                    while(low<high && nums[high]==nums[high+1]) high--;
                }
            }
        }
        return ans;
    }
};