#include <bits/stdc++.h>
using namespace std;



int main() {
    int t;
    cin >> t;

    while(t--){
        int n,x ;
        cin >> n >> x;
        vector<int> a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());

        long long t=0,m=0;
        int sk = INT_MAX;

        for(int b:a){
            m++;
            sk=min(sk,b);

            if(m*sk >=x){
                t++;
                m=0;
                sk=INT_MAX;
            }
        }

        cout << t << endl;
    }

    return 0;
}