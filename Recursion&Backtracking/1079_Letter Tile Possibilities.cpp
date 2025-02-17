// Question: You have n  tiles, where each tile has one letter tiles[i] printed on it.
// Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    void solve(string s, string &res,unordered_set<string> &ans,vector<bool>&vis){

        ans.insert(res);

        for(int i =0;i<n;i++){ // always start from i=0;
            if(vis[i])
                continue;
            
            // TRY
            vis[i] = true;
            res.push_back(s[i]);

            // Explore
            solve(s,res,ans,vis);

            // UNOD
            vis[i]=false;
            res.pop_back();
        }   

    }

    int numTilePossibilities(string tiles) {

        n = tiles.size();
        unordered_set<string> ans;
        vector<bool> vis(n,false);
        string res="";
        solve(tiles,res,ans,vis);

        return ans.size()-1;
    }
};