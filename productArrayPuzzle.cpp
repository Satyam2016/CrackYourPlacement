// Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i] is equal to the product of all the elements of nums except nums[i].

 

// Example 1:

// Input:
// n = 5
// nums[] = {10, 3, 5, 6, 2}
// Output:
// 180 600 360 300 900
// Explanation: 
// For i=0, P[i] = 3*5*6*2 = 180.
// For i=1, P[i] = 10*5*6*2 = 600.
// For i=2, P[i] = 10*3*6*2 = 360.
// For i=3, P[i] = 10*3*5*2 = 300.
// For i=4, P[i] = 10*3*5*6 = 900.
// Example 2:

// Input:
// n = 2
// nums[] = {12,0}
// Output:
// 0 12

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here 
        vector<long long int> product(n,1);
        long long int pro=1;
        int zero=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                zero++;
            }else{
                pro*=nums[i];
            }
        }
        
        if(zero==1){
            for(int i=0; i<n; i++){
                if(nums[i]==0){
                    product[i]=pro;
                }
                else{
                    product[i]=0;
                }
            }
        }else if(zero>1){
             for(int i=0; i<n; i++){
                product[i]=0;
            }
        }
        else{
            for(int i=0; i<n; i++){
                product[i]=pro/nums[i];
            }
        }
        return product;
    }
};
