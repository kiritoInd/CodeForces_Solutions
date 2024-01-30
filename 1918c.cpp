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

ll findxor(ll a,  ll b , ll r){
    return abs((a^r) - (b^r));
}

ll solve() {
    ll a , b , r;
    cin >> a >> b >> r;
    ll result = LLONG_MAX;
    for (int i = min(a , b); i <= r; i++) {
       result = min(result , findxor(a , b ,i));
    }
    return result;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cout<<solve()<<endl;
    }
}