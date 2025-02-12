// Q. Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
//  Find the leftmost occurrence of the substring part and remove it from s.Return s after removing all occurrences of part.

// Answer: We can use a stack to store the characters of the string s. We can keep on pushing the characters of the string s into the stack.
// If the top of the stack is equal to the last character of the string part, then we can check if the last n characters of the stack are equal to the string part.
// If they are equal, then we can pop the last n characters from the stack. We can keep on doing this until we reach the end of the string s.
// Finally, we can pop all the characters from the stack and return the string formed by the characters in the stack.
// The time complexity of this approach is O(n*n) and the space complexity is O(n).

// String and Stack
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // Optimal Approach using String as Stack
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    string removeOccurrences(string s, string part) {
        string res="";
        int m = part.length();
        for(int i=0;i<s.length();i++){
            res += s[i];
            int n = res.length();
            if(n>=m){
                if(res.substr(n-m) == part)
                    res.erase(n-m);
            }
        }

        return res;
    }



    // Optimal Approach using Stack
    // Time Complexity: O(n*n)
    // Space Complexity: O(n)
    // bool check(stack<char>&st, string part, int n){
    //     stack<char> temp = st;
    //     if(temp.size() < n)
    //         return false;
        
    //     for(int i=n-1;i>=0;i--){
    //         if(temp.top() != part[i])
    //             return false;
            
    //         temp.pop();
    //     }
    //     return true;
    // }
    // string removeOccurrences(string s, string part) {
    //     stack<char> st;
    //     int m = s.length();
    //     int n = part.length();

    //     for(int i=0;i<m;i++){
    //         st.push(s[i]);
    //         if(st.size() >= part.length() and check(st,part,n)){
    //             for(int i=0;i<n;i++)
    //                 st.pop();
                
    //         }
    //     }

    //     string ans = "";
    //     while(!st.empty()){
    //         ans += st.top();
    //         st.pop();
    //     }
    //     reverse(ans.begin(),ans.end());
    //     return ans;
    // }


    // Brute Force
    // Time Complexity: O(n*m)
    // Space Complexity: O(1)
    // string removeOccurrences(string s, string part) {
    //     while(true){
    //         int i = s.find(part);

    //         if(i== string::npos)
    //             break;
            
    //         s.erase(i,part.length());
    //     }

    //     return s;
    // }
};