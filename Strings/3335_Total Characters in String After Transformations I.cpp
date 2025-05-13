#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int mod = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        int n = s.size();
        vector<int> mp(26,0);

        for(char ch:s)
            mp[ch-'a']++;

        for(int i=1;i<=t;i++){
            vector<int> tmp(26,0);

            for(int i=0;i<26;i++){
                int val = i+'a';
                int freq= mp[i];

                if(val!='z'){
                    tmp[val+1-'a'] = (tmp[val+1-'a']+freq)%mod;
                }
                else{
                    tmp['a'-'a'] = (tmp['a'-'a']+freq)%mod;
                    tmp['b'-'a'] = (tmp['b'-'a']+freq)%mod;
                }
            }

            mp = move(tmp);
        }

        int sum =0;

        for(int i=0;i<26;i++)
            sum= (sum+mp[i])%mod;

        return sum;
    }

};
    // int lengthAfterTransformations(string s, int t) {
    //     int n = s.size();
    //     unordered_map<char,int> mp;

    //     for(char ch:s)
    //         mp[ch]++;

    //     for(int i=1;i<=t;i++){
    //         unordered_map<char,int> tmp;

    //         for(auto & it:mp){
    //             int val = it.first;
    //             int freq = it.second;

    //             if(val!='z'){
    //                 tmp[val+1] = (tmp[val+1]+freq)%mod;
    //             }
    //             else{
    //                 tmp['a'] = (tmp['a']+freq)%mod;
    //                 tmp['b'] = (tmp['b']+freq)%mod;
    //             }
    //         }

    //         mp = move(tmp);
    //     }

    //     long long sum =0;

    //     for(auto &itr:mp)
    //         sum= (sum+itr.second)%mod;

    //     return sum;
    // }
    // int lengthAfterTransformations(string s, int t) {
    //     int n = s.size();
    //     int zc=0;
    //     int nc = 0;

    //     for(int i=0;i<n;i++){
    //         int c= 'z'-s[i];

    //         if(s[i]=='z')
    //             zc++;
    //         else if(c<t)
    //             nc++;
    //     }

    //     return n+zc+nc;
    // }
// };