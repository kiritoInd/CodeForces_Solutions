#include <iostream>
#include <vector>
#include <algorithm>

typedef long long int ll;

using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> s(n);

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    s = a;
    sort(s.begin(), s.end());

    ll l = -1, r = -1;
    bool found = false;

    for (ll i = 0; i < n; i++) {
        if (s[i] != a[i]) {
            if (!found) {
                l = i;
                
                found = true;
            }
            r = i;
        }
    }

    if (!found) { 
        cout << "yes\n1 1";
    } else {
        reverse(a.begin() + l, a.begin() + r + 1);

        bool sorted = true;
        for (ll i = 0; i < n; i++) {
            if (s[i] != a[i]) {
                sorted = false;
                break;
            }
        }

        if (sorted) cout << "yes\n" << l + 1 << " " << r + 1;
        else cout << "no";
        
    }
    return 0;
}
