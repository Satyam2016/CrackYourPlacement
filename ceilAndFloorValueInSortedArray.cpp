// Given a sorted array and a value x,
//  the ceiling of x is the smallest element in an array greater than or equal to x,
//   and the floor is the greatest element smaller than or equal to x.
//    Assume that the array is sorted in non-decreasing order. 
//    Write efficient functions to find the floor and ceiling of x. 

// Examples : 

// For example, let the input array be {1, 2, 8, 10, 10, 12, 19}
// For x = 0:    floor doesn't exist in array,  ceil  = 1
// For x = 1:    floor  = 1,  ceil  = 1
// For x = 5:    floor  = 2,  ceil  = 8
// For x = 20:   floor  = 19,  ceil doesn't exist in array

int ceilSearch(vector<int> nums, int x){
     int n=nums.size();
     int low=0;
     int high=n-1;
     if(n==0) return -1;
     if (x > nums[high]) return -1;

     while(low<=high){
          int mid=low+(high-low)/2;
          if(nums[mid]==x) return nums[mid];
          if(nums[mid]<x) low=mid+1;
          else high=mid-1;
     }
     if(low<n) return nums[low];
     return -1;
}

int floorSearch(vector<int> nums, int x){
     int n=nums.size();
     int low=0;
     int high=n-1;
     if(n==0) return -1;
     if(x< nums[low]) return -1;

     while(low<=high){
          int mid=low+(high-low)/2;
          if(nums[mid]==x) return nums[mid];
          if(nums[mid]<x) high=mid-1;
          else{
               low=mid+1;
          } 
     }
     if(high>=0) return nums[high];
     return -1;
}