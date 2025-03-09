// Question: 2379. Minimum Recolors to Get K Consecutive Black Blocks


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
// SLIDING WINDOW
// TIME => O(N)
// SPACE => O(1)
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int wc=0, ans=INT_MAX ;
        int i=0,j=0;

        while(j<n){
            if(blocks[j]=='W')
                wc++;
            
            if(j-i+1==k){
                ans = min(ans,wc);
                if(blocks[i]=='W')
                    wc--;
                i++;
            }
            j++;
        }

        return ans;
    }

// BRUTE FORCE
// TIME => O(n*k)
// SPACE => O(1)
// Failed at 109th testcase out of 122
    // int minimumRecolors(string blocks, int k) {
    //     // int black_count = 0, ans = INT_MAX;
    //     int n = blocks.size();
    //     int ans = INT_MAX;
    //     for (int i = 0; i <n-k; i++) {
    //        int chk=0;
    //        for(int j=i;j-i+1 <=k;j++){
    //             if(blocks[j]=='W')
    //                 chk++;
    //        }
    //        ans = min(ans,chk);
    //     }
        
    //     return ans;
    // }
};
    
    
    