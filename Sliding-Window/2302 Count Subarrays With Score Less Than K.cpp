#include<bits/stdc++.h>
using namespace std;


// Problem Link: https://leetcode.com/problems/count-subarrays-with-score-less-than-k/description/
// Problem Name: Count Subarrays With Score Less Than K
// Answer: To solve this problem, we need to count the number of contiguous subarrays (subarrays) of the given array nums such that the product of the sum of the elements in the subarray and its length is less than k.
// We can use a sliding window approach to efficiently count the valid subarrays.
// The idea is to maintain a window of elements and calculate the sum and length of the subarray within that window. We can then check if the product of the sum and length is less than k. If it is, we can count the number of valid subarrays ending at the current position.
// We can also use a two-pointer technique to adjust the window size as needed. The outer loop will iterate through the array, while the inner loop will adjust the start of the window until the product of the sum and length is less than k. This way, we can efficiently count the valid subarrays without having to check all possible subarrays explicitly.
// The time complexity of this approach is O(N), where N is the length of the input array nums. This is because we are iterating through the array once and adjusting the window size in a linear manner. The space complexity is O(1) since we are using a constant amount of extra space to store variables.
// The final answer will be the total count of valid subarrays.
// The code below implements this approach using C++.

class Solution {
public:

// Optimized Approach

// Time Complexity => O(2N) ~~ O(N) => Sliding Window
// Space Complexity => O(1)
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans =0;


        int i=0,j=0;
        long long sum =0;

        while(j<n){

            sum+=nums[j];
            long long sz = j-i+1;

            while(sz*sum >= k){
                sum-=nums[i];
                sz--;
                i++;
                
            }
            if(sz*sum < k){
                ans+= sz;
            }


            j++;
        }


        return ans ;

    }


// Brute Force
// Time Complexity => O(N^2) => TLE
// Space Complexity => O(1)
    // long long countSubarrays(vector<int>& nums, long long k) {
    //     int n = nums.size();
    //     long long ans =0;

    //     for(int i=0;i<n;i++){
    //         long long  sum =nums[i];
    //         long long sz=1;

    //         if(nums[i] < k)
    //             ans++;

    //         for(int j=i+1;j<n;j++){
    //             sum+=nums[j];
    //             sz++;

    //             if(sum*sz < k)
    //                 ans++;
    //             else
    //                 break;
                
    //         }

    //     }

    //     return ans;
    // }
};