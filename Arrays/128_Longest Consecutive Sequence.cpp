
// Q. Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence. You must write an algorithm that runs in O(n) time.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:


// Optimal Approach
//  Time = O(3n) ~~ O(n)
// Space = O(n)
    int longestConsecutive(vector<int>& nums) {
        int n =nums.size();
        
        if(n==0)
            return 0;
        
        unordered_set<int> st;

        for(int x:nums)
            st.insert(x);
        
        int ans=1;

        for(auto x:st){
            
            if(st.find(x-1)==st.end()){
                int count=1;
                int it=x;
                while(st.find(it+1)!=st.end()){
                    it++;
                    count++;
                }

                ans=max(ans,count);
            }
        }

        return ans;
    }

// Brute Force.
//  Time = O(n*logn)
// Space = O(1)
    // int longestConsecutive(vector<int>& nums) {

    //     int n =nums.size();
        
    //     if(n==0)
    //         return 0;
        
    //     sort(nums.begin(),nums.end());
    //     int ans=1;
    //     int count=1;
        
    //     for(int i=1;i<nums.size();i++){
    //         if(nums[i]==nums[i-1])
    //             continue;
            
    //         if(abs(nums[i]-nums[i-1])==1 ){
    //             count++;
    //         }
    //         else{
    //             ans=max(ans,count);
    //             count=1;
    //         }
    //     }

    //     ans=max(ans,count);

    //     return ans;
    // }
};