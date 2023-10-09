#include <bits/stdc++.h>


typedef long long int ll;

using namespace std;

int solve() {
    int n;
    cin>> n;
    
    for(int a = 1; a<= n - 2; a++){
        if(a % 3 == 0) continue;
        for(int b = a + 1; b <= n -1; b++){
             if(b % 3 == 0) continue;
             int c = n - a - b;
            if(c != a && c!= b && c % 3 != 0 && c > 0){
                cout<<"YES"<<endl;
                cout<<a<<" "<<b<<" "<<c<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}