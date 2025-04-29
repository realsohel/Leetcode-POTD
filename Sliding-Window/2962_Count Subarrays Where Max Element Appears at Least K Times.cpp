#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://codeforces.com/problemset/problem/2962/C
// Problem Name: Count Subarrays Where Max Element Appears at Least K Times
// Answer: 
// The optimized sliding window approach counts the number of subarrays where the maximum element 
// appears at least `k` times. It does so by maintaining a sliding window [i, j] such that the count 
// of the maximum element within the window is at least `k`. For every valid window, the number of 
// subarrays ending at or after `j` and starting at `i` is (n - j). We keep shifting the window 
// and accumulating the total number of such subarrays in `ans`. This approach works in linear time O(n).

class Solution {
public:

// Optimized Approach
// Time Complexity: O(n) => Sliding Window
// Space Complexity: O(1)
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());

        long long ans =0;

        int i=0,j=0;
        int cnt=0;

        while(j<n){
            if(nums[j]==maxi)
                cnt++;
            
            while(cnt>=k){
                ans+=n-j;
                if(nums[i]==maxi)
                    cnt--;
                i++;
            }

            j++;
        }

        return ans ;
    }

// Brute Force Approach
// Time Complexity: O(n^2) => TLE
// Space Complexity: O(1)
    // long long countSubarrays(vector<int>& nums, int k) {
        
    //     int n = nums.size();
    //     int maxi = *max_element(nums.begin(),nums.end());

    //     long long ans =0;

    //     for(int i=0;i<n;i++){
    //         int cnt = 0;
    //         for(int j=i;j<n;j++){
    //             if(nums[j]==maxi)
    //                 cnt++;
                
    //             if(cnt==k){
    //                 ans+= n-j;
    //                 break;
    //             }
    //         }
    //     }

    //     return ans;
    // }
};