// Question: 2161. Partition Array According to Given Pivot

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

// // APPROACH 3 - 
// // TIME = O(2N) ~~ O(N)
// // SPACE = O(N)
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        
        int i=0, j=n-1;
        int start=0, end= n-1;
        
        while(i<n and j>=0){
            if(nums[i]<pivot){
                ans[start]=nums[i];
                start++;
            }
            if(nums[j]>pivot){
                ans[end]=nums[j];
                end--;
            }
            i++;
            j--;
        }

        for(int i=start;i<=end;i++){
            ans[i]=pivot;
        }

        return ans;
    }

// // APPROACH 2 - Just a more cleaner code than Approach 1 
// // TIME = O(2N) ~~ O(N)
// // SPACE = O(N)
//     vector<int> pivotArray(vector<int>& nums, int pivot) {
//         int n = nums.size();
//         vector<int> ans(n);

//         int startcount = 0, midcount = 0;
//         for(int x : nums){
//             if(x < pivot)
//                 startcount++;
//             else if(x == pivot){
//                 midcount++;
//             }
//         }
        
//         int ls = 0;
//         int eq = startcount;
//         int gt = startcount + midcount;
        
//         for(int x : nums){
//             if(x < pivot){
//                 ans[ls]= x;
//                 ls++;
//             }
//             else if(x==pivot){
//                 ans[eq]=x;
//                 eq++;
//             }
//             else{
//                 ans[gt] = x;
//                 gt++;
//             }
//         }

//         return ans;
//     }


// // APPROACH 1 - 
// // TIME = O(3N) ~~ O(N)
// // SPACE = O(N)
//     vector<int> pivotArray(vector<int>& nums, int pivot) {
//         int n = nums.size();
//         vector<int> ans(n);

//         int startcount = 0, midcount = 0;
//         for(int x : nums){
//             if(x < pivot)
//                 startcount++;
//             else if(x == pivot){
//                 midcount++;
//             }
//         }

//         // Place pivot values in the correct middle section
//         for(int i = startcount; i < startcount + midcount; i++){
//             ans[i] = pivot;
//         }

//         // Place elements < pivot and > pivot
//         int left = 0;
//         int right = startcount + midcount;

//         for(int i = 0; i < n; i++){
//             if(nums[i] < pivot){
//                 ans[left++] = nums[i];
//             } else if(nums[i] > pivot){
//                 ans[right++] = nums[i];
//             }
//         }

//         return ans;
//     }
};
    