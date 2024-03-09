#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <list>
#include <numeric>
#include <limits>
#include <functional>
#include <utility>
#include <unordered_map>
#include <unordered_set>


using namespace std;
#define  sz(s)        (int)s.size()
#define  all(v)       (v).begin(),(v).end()
#define  enl  	  '\n'

template <typename A, typename B> ostream& operator<< (ostream &cout, pair<A, B> const &p) { return cout << '(' << p.first << ',' << p.second << ')'; }
template <typename A, typename B> istream& operator>> (istream& cin, pair<A, B> &p) {cin >> p.first; return cin >> p.second;}
template <typename A> ostream& operator<< (ostream &cout, vector<A> const &v) {cout << '['; for(int i = 0; i < v.size(); i++) {if (i) cout << ','; cout << v[i];} return cout << ']';}
template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }

const long long mod = 1e9+7;
const long long inf = 1e18;


int dp(int i, string t, vector<vector<string>> &strs, vector<vector<int>> &memo) {
    if (i >= strs.size()) return t.empty() ? 0 : INT_MAX;
    if (memo[i][t.size()] != -1) return memo[i][t.size()];
    int res = INT_MAX;
    for (string &s : strs[i]) {
        if (t.substr(0, s.size()) == s) {
            int next = dp(i + 1, t.substr(s.size()), strs, memo);
            if (next != INT_MAX) res = min(res, 1 + next);
        }
    }
    res = min(res, dp(i + 1, t, strs, memo));
    return memo[i][t.size()] = res;
}

void solve() {
    string t;
    cin >> t;
    int n;
    cin >> n;
    vector<vector<string>> strs(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        strs[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> strs[i][j];
        }
    }
    vector<vector<int>> memo(n, vector<int>(t.size() + 1, -1));
    int res = dp(0, t, strs, memo);
    cout << (res == INT_MAX ? -1 : res) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}