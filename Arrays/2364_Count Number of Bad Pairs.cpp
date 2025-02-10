

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// Optimal Approach - 2
// Time = O(n)
// Space = O(n)
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            int diff = nums[i]-i;
            int totalPairs=i;

            int goodPairs = mp[diff];
            ans += totalPairs - goodPairs;
            mp[diff]++;
        }
        
        return ans;
    }

// Optimal Approach - 1 
// Time = O(n)
// Space = O(2n) = O(n)
    // long long countBadPairs(vector<int>& nums) {
    //     int n = nums.size();
    //     long long ans = 0;
    //     unordered_map<int,int> mp;

    //     for(int i=0;i<n;i++){
    //         nums[i] -= i;
    //     }

    //     for(int i=0;i<n;i++){
    //         int totalNums=i;
    //         ans += totalNums - mp[nums[i]];
    //         mp[nums[i]]++;
    //     }
        
    //     return ans;
    // }

//  Brute Force
// Time = O(n^n)
// Space = O(1)
    // long long countBadPairs(vector<int>& nums) {
    //     long long ans =0;
    //     int n = nums.size();

    //    for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if((j-i) != (nums[j]-nums[i]))
    //             ans++;
    //     }
    //    } 

    //    return ans;
    // }
};