
// Question: 2401. Longest Nice Subarray


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

//  Time Complexity = O(n)
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 1;
        
        int ans =1;
        int i=0,j=0,mask=0;

        while(j<n){
            while((mask&nums[j])!=0){ // Shrinking
                mask^=nums[i];
                i++;
            }
            mask|=nums[j];
            ans= max(ans,j-i+1);
            j++;
            
        }

        return ans;
    }

//  Time Complexity = O(n*n)
    // int longestNiceSubarray(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n==1)
    //         return 1;
        
    //     int ans =1;

    //     for(int i=0;i<n;i++){
    //         int mask=0;

    //         for(int j=i;j<n;j++){

    //             if((mask&nums[j]) !=0)
    //                 break;
                
    //             // mask &=nums[j]; 
    //             mask |=nums[j]; 
    //             ans = max(ans,j-i+1);
    //         }
    //     }

    //     return ans;
    // }
};