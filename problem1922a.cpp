#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <climits>
#include <unordered_set>
#include <set>
#include <map>
#include <string.h>

typedef long long int ll;

using namespace std;

int solve() {
    int n;
    cin>>n;
    vector<string> st(3);
    for(int i = 0 ; i< 3; i++){
        cin>>st[i];
    }
    for(int i = 0 ; i<n;i++){
        if(st[0][i] == st[1][i] && st[2][i] != st[0][i]) {
            cout<<"YES"<<endl;
            return 0;
        }
        if(st[0][i] != st[1][i] && st[1][i] != st[2][i] && st[2][i] !=  st[0][i]){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
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