// Q. Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.

// Answer. We can use the property of the tuple (a, b, c, d) such that a * b = c * d. 
// We can store the product of all pairs of elements in a hashmap and then iterate over the hashmap to find the number of tuples (a, b, c, d) such that a * b = c * d.
// We can use the formula nC2 = n*(n-1)/2 to find the number of tuples (a, b, c, d) such that a * b = c * d.
// The time complexity of this approach is O(n^2) where n is the number of elements in the array nums.
// The space complexity of this approach is O(n) where n is the number of elements in the array nums.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

//  Optimal Approach
// Time = O(n^2)
// Space = O(n)
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int tuple=0;
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]]++;
            }
        }

        for(auto itr=mp.begin(); itr!=mp.end();itr++){
            int freq = itr->second;
            int comb = (freq*(freq-1))/2;
            tuple+=comb;
        }

        return tuple*8;
    }


// ==================================================================================

//  Better Approach
// Time = O(n^3)
// Space = O(n)
    // int tupleSameProduct(vector<int>& nums) {
    //     int n = nums.size();
    //     int tuple=0;
    //     sort(nums.begin(),nums.end());

    //     for(int i=0;i<n;i++){
    //         for(int j=n-1;j>i;j--){
    //             int prod = nums[i]*nums[j] ;
    //             unordered_set<int> st;
    //             for(int k=i+1; k<j;k++){
    //                 if(prod%nums[k]==0){
    //                     int val = prod/nums[k];
    //                     if(st.find(val) != st.end())
    //                         tuple++;
    //                     else
    //                         st.insert(nums[k]);
    //                 }

    //             }
    //         }
    //     }

    //     return tuple*8;
    // }


// ==================================================================================

//  Thoda Behtar Brute Force
// Time = O(n^4)
// Space = O(1)
// TLE
    // int tupleSameProduct(vector<int>& nums) {
    //     int n = nums.size();
    //     int tuple=0;
    //     sort(nums.begin(),nums.end());
    //     for(int i=0;i<n;i++){
    //         for(int j=n-1;j>i;j--){
    //             for(int k=i+1;k<j;k++){
    //                 for(int l=j-1;l>k;l--){
    //                     if(nums[i]*nums[j] == nums[k]*nums[l])
    //                         tuple++;
    //                 }
    //             }
    //         }
    //     }

    //     return tuple*8;
    // }

// ==================================================================================

//  Ekdum Brute Force
// Time = O(n^4)
// Space = O(1)
//  TLE
    // int tupleSameProduct(vector<int>& nums) {
    //     int n = nums.size();
    //     int tuple=0;

    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             for(int k=0;k<n;k++){
    //                 for(int l=k+1;l<n;l++){
    //                     if(i!=k and i!=l and j!=k and j!=l)
    //                         if(nums[i]*nums[j] == nums[k]*nums[l])
    //                             tuple++;
    //                 }
    //             }
    //         }
    //     }

    //     return (tuple/2)*8;
    // }
};

int main(){
    return 0;
}