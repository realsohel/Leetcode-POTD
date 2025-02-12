

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

//  Approach 3 - using Array
// time complexity O(n)
// space complexity O(82) = O(1)
// Accepted
    int maximumSum(vector<int>& nums) {
        vector<int> arr(82,0);
        int ans =-1;
        for(int i=0;i<nums.size();i++){
            int sum = 0;
            int x = nums[i];
            while(x>0){
                sum+=x%10;
                x/=10;
            }
            if(arr[sum])
                ans=max(ans,arr[sum]+nums[i]);
                
            arr[sum] = max(arr[sum],nums[i]);
        }
        return ans;
    }
//  Approach 3 - using Map without Array
// time complexity O(n)
// space complexity O(n)
// Accepted
    // int maximumSum(vector<int>& nums) {
    //     unordered_map<int,int> mp;

    //     int ans = -1;
    //     for(int i=0;i<nums.size();i++){
    //         int sum = 0;
    //         int x = nums[i];
    //         while(x>0){
    //             sum+=x%10;
    //             x/=10;
    //         }

    //         if(mp[sum]){
    //             ans = max(ans,mp[sum]+nums[i]);
    //             mp[sum] = max(mp[sum],nums[i]);
    //         }
    //         else
    //             mp[sum] = nums[i];
    //     }

    //     return ans;
    // }

//  Approach 2 - using Map
// time complexity O(n*logn)
// space complexity O(n)
// Accepted
    // int maximumSum(vector<int>& nums) {
    //     unordered_map<int,vector<int>> mp;

    //     for(int i=0;i<nums.size();i++){
    //         int sum = 0;
    //         int x = nums[i];
    //         while(x>0){
    //             sum+=x%10;
    //             x/=10;
    //         }
    //         mp[sum].push_back(nums[i]);
    //     }

    //     int ans = -1;
    //     for(auto itr=mp.begin();itr!=mp.end();itr++){
    //         vector<int> v = itr->second;
    //         if(v.size()>=2){
    //             sort(v.begin(),v.end());
    //             ans = max(ans,v[v.size()-1]+v[v.size()-2]);
    //         }
    //     }

    //     return ans;
    // }


// Bruteforce approach
// time complexity O(n^2)
// space complexity O(1)
// TLE
    // int digitSum(int x){
    //     int sum=0;
    //     while(x>0){
    //         int dig = x%10;
    //         sum+=dig;
    //         x/=10;
    //     }
    //     return sum;
    // }
    
    // int maximumSum(vector<int>& nums) {
    //     int ans = -1;

    //     for(int i=0;i<nums.size();i++){
    //         for(int j=i+1;j<nums.size();j++){
    //             if(digitSum(nums[i]) == digitSum(nums[j]))
    //                 ans=max(ans,nums[i]+nums[j]);
    //         }
    //     }    

    //     return ans;
    // }
};