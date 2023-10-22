#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;

int solve() {
    int a, b, c;
    cin >> a >> b >> c;

    // Find the maximum length
    int max_length = max(a, max(b, c));

    // Calculate the sum of the threadlet lengths
    int sum_lengths = a + b + c;

    // Check if it's possible to make all threadlets of equal length within three operations
    if ((sum_lengths % 9 == 0) && (sum_lengths / 9 <= max_length)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
