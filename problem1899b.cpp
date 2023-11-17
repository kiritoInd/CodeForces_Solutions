#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

typedef long long int ll;

using namespace std;

ll solve() {
    ll n;
    cin >> n;
    vector<ll> ax(n);

    for (ll i = 0; i < n; i++) {
        cin >> ax[i];
    }

    vector<ll> kth;

    for (ll x = 1; x <= n; x++) {
        if (n % x == 0) {
            kth.push_back(x);
        }
    }

    vector<ll> result;
    ll res = LLONG_MIN;

    for (ll k : kth) {
        for (ll i = 0; i < n; i += k) {
            ll sum = 0;
            for (ll j = i; j < min(i + k, n); j++) {
                sum += ax[j];
            }
            result.push_back(sum);
        }
        
        ll mini = *min_element(result.begin(), result.end());
        ll maxi = *max_element(result.begin(), result.end());
        res = max(res, abs(maxi - mini));
        result.clear();
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        cout << solve() << endl;
    }

    return 0;
}
