#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {


        long long sum1 =0, sum2=0;
        long long z1 =0, z2=0;

        for(int x:nums1){
            sum1+=x;
            if(x==0){
                z1++;
                sum1++;
            }
        }
        
        for(int y:nums2){
            sum2+=y;
            if(y==0){
                z2++;
                sum2++;
            }
        }
        

        if((sum1>sum2 and z2==0) or (sum2>sum1 and z1==0)){
            return -1;
        }
        else 
            return max(sum1, sum2);
    }
};