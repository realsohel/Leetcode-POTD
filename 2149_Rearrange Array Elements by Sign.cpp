

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // OPTIMIZED APPROACH
    // Time Complexity: O(N)
    // Space Complexity: typically O(1) but we will take ans vector so... O(N)
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n,0);

        int posCount=0, negCount=1;

        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[posCount]=nums[i];
                posCount+=2;
            }
            else{
                ans[negCount]=nums[i];
                negCount+=2;
            }
        }

        return ans;
    }


    // BRUTE FORCE APPROACH
    // Time Complexity: O(N + N)
    // Space Complexity: O(N)
    // vector<int> rearrangeArray(vector<int>& nums) {
    //     int n = nums.size();

    //     vector<int> pos;
    //     vector<int> neg;

    //     for(int x:nums){
    //         if(x>0)
    //             pos.push_back(x);
    //         else
    //             neg.push_back(x);
    //     }

    //     int posCount=0, negCount=0;

    //     for(int i=0;i<n;i++){
    //         if(i%2==0){
    //             nums[i]=pos[posCount];
    //             posCount++;
    //         }
    //         else{
    //             nums[i]=neg[negCount];
    //             negCount++;
    //         }
    //     }

    //     // for(int i=0;i<n/2;i++){
            
    //     //     A[2*i] = pos[i];
    //     //     A[2*i+1] = neg[i];
    //     // }

    //     return nums;
    // }
};

int main(){

    return 0;
}