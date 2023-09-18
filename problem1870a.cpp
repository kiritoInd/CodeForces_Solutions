#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int ll;

using namespace std;

int solve(int n, int k, int x) {
    if (k > n || k - 1 > x) {
        return -1;
    }
    vector<int> v(n, -1);

    for (int i = 0; i < k; i++) {
        v[i] = i;
    }

    if (k == x) x = x - 1;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == -1) v[i] = x;

        sum += v[i];
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    int n, k, x;

    while (t--) {
        cin >> n >> k >> x;
        int result = solve(n, k, x);
        cout << result << endl;
    }
}
