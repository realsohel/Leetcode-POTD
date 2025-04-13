#include <bits/stdc++.h>
using namespace std;



int main() {
    int t;
    cin >> t;
    string TARGET = "01032025";
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        

        unordered_map<char, int> mp;
        for (char c : TARGET) 
            mp[c]++;
        
        unordered_map<char, int> count;
        bool flag=true;
        for (int i = 0; i < n; i++) {
            char c = '0' + a[i];
            count[c]++;
            
            bool cf = true;
            for (char ch : TARGET) {
                if (count[ch] < mp[ch]) {
                    cf = false;
                    break;
                }
            }
            if (cf) {
                cout << (i + 1) << "\n";
                flag=false;
                break;
            }
        }
        
        if(flag)
            cout << "0"<< endl;
    }
    
    return 0;
}

