#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <climits>
#include <unordered_set>
#include <set>
#include <map>
#include <string.h>
using namespace std;

typedef long long ll;

ll solve() {
    ll n;
    cin >> n;
    
    vector<ll> a(n);
    vector<int> cnt(n + 1);

    for (int i = 0; i < n; i++) {
        cin>>a[i];
        cnt[a[i]]++;
    }
   
    ll result = 0;
    int smaller = 0;
    for (int i = 0; i <= n; i++) {
            result += 1LL * cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
            result += 1LL * cnt[i] * (cnt[i] - 1) / 2 * smaller;
            smaller += cnt[i];
        }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }

    return 0;
}