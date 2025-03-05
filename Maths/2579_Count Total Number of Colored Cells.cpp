// Question: 2579. Count Total Number of Colored Cells

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long coloredCells(int n) {
        if(n==1)
            return 1LL;
        
        long long colored=1LL;
        long long mul=0;
        while(n>0){
            colored+=mul;
            mul+=4;
            n--;
        }

        return colored;
    }
};

int main(){
    return 0;
}