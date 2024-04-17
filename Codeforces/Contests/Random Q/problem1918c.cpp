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
    ll a , b , r;
    cin >> a >> b >> r;
    if(b > a) swap(a , b);
    ll start = 0 ; 
    ll ok = 0, x = 0 , y =0 ; 
    for(ll j = 60; j>= 0; j--){
        ll abit = 0 , bbit = 0;
        if((a & (1ll << j))) abit = 1;
        if((b & (1ll << j))) bbit = 1;

        if(abit == bbit && (r & (1ll << j))) ok = 1;

        if(abit == bbit) continue;

        if(start == 0){
            start = 1;
            x += (1ll << j);
            if((r & (1ll << j))) ok = 1;
        }else{
            if(abit == 0 && bbit == 1){
                y += (1ll << j);
                if((r & (1ll << j))) ok = 1;
            }
            else{
                if((r & (1ll  << j)) || ok) y+= (1ll << j);
                else{
                    x += (1ll << j);
                    if((r & (1ll << j ))) ok = 1;
                }
            }
        }

    }
    cout << x - y << endl;
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