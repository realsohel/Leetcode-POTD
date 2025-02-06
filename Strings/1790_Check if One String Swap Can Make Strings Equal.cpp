// Q. You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
// Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

// Ans. We can solve this problem by checking the number of differences between the two strings. 
// If the number of differences is greater than 2, then it is not possible to make the strings equal by performing at most one string swap. 
// If the number of differences is 1, then it is also not possible to make the strings equal by performing at most one string swap. 
// If the number of differences is 2, then we can swap the characters at the two different indices and check if the strings become equal. If the strings become equal, then we can return true. 
// Otherwise, we can return false.
// The time complexity of this approach is O(n), where n is the length of the strings s1 and s2. The space complexity of this approach is O(1).


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// Optimal
// Time = O(n)
// Space = O(1)
    bool areAlmostEqual(string s1, string s2) {
        
        int n = s1.size();

        int diffCount=0, first=-1, last=-1;

        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                diffCount++;

                if(first==-1){
                    first=i;
                }
                else if(last==-1){
                    last=i;
                }
            }

            if(diffCount>2){
                return false;
            }
        }

        if(diffCount==1)
            return false;

        if(first!=-1 and last!=-1){
            swap(s1[first],s1[last]);
            if(s1==s2){
                return true;
            }
            else
                return false;
        }

        return true;

    }


//  Brute Force
//  Time = O(1)
//  Space = O(n)
    // bool areAlmostEqual(string s1, string s2) {
        
    //     int n = s1.size();

    //     vector<int> diff;

    //     for(int i=0;i<n;i++){
    //         if(s1[i]!=s2[i]){
    //             diff.push_back(i);
    //         }
    //         if(diff.size()>2){
    //         return false;
    //         }   
    //     }

    //     if(diff.size()==2){
    //         swap(s1[diff[0]],s1[diff[1]]);

    //         if(s1==s2){
    //             return true;
    //         }
    //         else{
    //             return false;
    //         }
    //     }
    //     else if(diff.size()==1)
    //         return false;

    //     return true;
    // }
};

int main(){
    return 0;
}