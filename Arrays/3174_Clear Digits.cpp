
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // Optimal Approach
    // Time = O(n)
    // Space = O(1)
        // string clearDigits(string s) {
        //     int j = 0;
        //     for (int i = 0; i < s.size(); ++i)
        //         if (isdigit(s[i]))
        //             --j;
        //         else
        //             s[j++] = s[i];
        //     return s.substr(0, j);
        // }

    // Better Approach
    // Time = O(n)
    // Space = O(1)
        string clearDigits(string s) {
            stack<char> st;
            string ans="";
            for (int i = 0; i < s.size(); ++i){
                if(isdigit(s[i]) and !st.empty() )
                    st.pop();
                else{
                    st.push(s[i]);
                }
            }

            for(int i=0;i<st.size();i++){
                ans+=st.top();
                st.pop();
            }

            return ans;
        }
    

    // Brute force
    // Time = O(n)
    // Space = O(1)
        // string clearDigits(string s) {
        //     int i=0;
        //     while(i<s.length()){
        //         if (isdigit(s[i])){
        //             s.erase(i,1);
        //             if(i-1>=0){
        //                 s.erase(i-1,1);
        //                 i--;
        //             }
        //         }
        //         else
        //             i++;
        //     }
        //     return s;
        // }
    };