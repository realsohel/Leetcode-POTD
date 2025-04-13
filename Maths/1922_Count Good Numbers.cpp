
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9+7;

// Optimal Solution
// Time Complexity: O(log n) for power function
// Space Complexity: O(1) for the power function
// The number of good numbers is equal to the number of even digits (0, 2, 4, 6, 8) and prime digits (2, 3, 5, 7) at odd positions
    long long power(long long a,long long b){
        if(b==0)
            return 1;
        
        long long half = power(a,b/2);
        long long res = (half*half)%mod;

        if(b%2==1)
            res = (res*a)%mod;

        return res;
    }


    int countGoodNumbers(long long n) {
        long long even = power(5,(n+1)/2);
        long long odd = power(4,(n)/2);
    
        return (even*odd)%mod;
    }

    // BRUTE FORCE SOLUTION
    // Time Complexity: O(10^n * n) where n is the length of the number
    // Space Complexity: O(n) for the string conversion
    // TLE 
    bool isGood(string s){
        if(s.length()==1){
            return (s[0] -'0') % 2;
        }

        for(int i=0;i<s.length();i+=2){
            int num = s[i]-'0';
            if(num%2!=0)
                return false;
        
            if((s[i+1]!='2' and s[i+1]!='3') and (s[i+1]!='5' and s[i+1]!='7'))
                return false;
            
        }

        return true;
    }

    int countGoodNumbers(long long n) {

        int ans =0;

        for(int i=0;i<10^n;i++){
            if(isGood(to_string(i))){
                ans%=mod;
                ans++;
            }
        }    

        return ans%mod;
    }
};