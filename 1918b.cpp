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

void solve() {
    ll n;
    cin>>n;
    vector<vector<ll>> l(n , vector<ll>(2));
    for(ll i = 0 ; i < n ;i++){
        ll j = 0;
        cin>>l[i][j];
    }
    for(ll i = 0 ; i < n ;i++){
        ll j = 1;
        cin>>l[i][j];
    }
    sort(l.begin(), l.end());

    for(ll i = 0 ; i < n ;i++){
        ll j = 0;
        cout<<l[i][j]<<" ";
    }
    cout<<endl;
    for(ll i = 0 ; i < n ;i++){
        ll j = 1;
        cout<<l[i][j]<<" ";
    }
    cout<<endl;

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