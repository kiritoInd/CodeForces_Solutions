#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int ll;

using namespace std;

int solve() {
    string s;
    cin>>s;
    string f = s;
    string x = s;

    for(int i = 1; i <= 8; i++){
        f[1] = '0' + i;
        if(('0' + i) != s[1]) cout<<f<<endl;
    }
    for(int i = 0 ; i < 8; i++){
        x[0] = 'a' + i;
        if('a' + i != s[0]) cout<<x<<endl;
    }
    return 0;
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
