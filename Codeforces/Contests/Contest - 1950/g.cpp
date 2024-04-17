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
#define  int          long long
#define  sz(s)        (int)s.size()
#define  all(v)       (v).begin(),(v).end()
#define  enl  	  '\n'

vector<int> count_divisors_to_n(int n){
    vector<int> res(n + 1);
    for(int i = 1 ; i <= n ; i++){
        for(int j = i ; j <= n; j += i){
            res[j]++;
        }
    }
    return res;
}
int count_divisors(int n){
    int count = 0;
    for(int i = 1 ; i * i <= n;i++){
        if(n % i == 0){
            count++;
            if(n/i != i){
                count++;
            }
        }

    }
    return count;
}
template <typename A, typename B> ostream& operator<< (ostream &cout, pair<A, B> const &p) { return cout << '(' << p.first << ',' << p.second << ')'; }
template <typename A, typename B> istream& operator>> (istream& cin, pair<A, B> &p) {cin >> p.first; return cin >> p.second;}
template <typename A> ostream& operator<< (ostream &cout, vector<A> const &v) {cout << '['; for(int i = 0; i < v.size(); i++) {if (i) cout << ','; cout << v[i];} return cout << ']';}
template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }

const long long mod = 1e9+7;
const long long inf = 1e18;

void dfs(string node, unordered_map<string, vector<string>>& adj, unordered_map<string, bool>& visited) {
    visited[node] = true;
    for(auto& it : adj[node]) {
        if(!visited[it]) {
            dfs(it, adj, visited);
        }
    }
}
string s[20], t[20];

// f is the DP table where f[mask][i] indicates whether there's a valid sequence ending with pair i under the mask.
// g is an adjacency matrix where g[i][j] is 1 if pairs i and j share a string, otherwise 0.
int f[70000][16], g[20][20];

void solve() {
    int n, ans = 0;
    cin >> n; // Number of pairs

    // Reading the pairs
    for(int i = 0; i < n; ++i) cin >> s[i] >> t[i];

    // Initializing the adjacency matrix g
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(s[i] == s[j] || t[i] == t[j]) {
                g[i][j] = 1; // Pairs i and j share a string
            } else {
                g[i][j] = 0; // Pairs i and j do not share any string
            }
        }
    }

    memset(f, 0, sizeof(f)); // Initializing the DP table to 0

    // Base case: single pairs
    for(int i = 0; i < n; ++i) f[1 << i][i] = 1;

    // Iterating over all possible combinations of pairs
    for(int mask = 0; mask < (1 << n); ++mask) {
        for(int j = 0; j < n; ++j) {
            // If pair j is in the current combination and f[mask][j] is true
            if((mask & (1 << j)) && f[mask][j]) {
                ans = max(ans, (int)__builtin_popcountll(mask)); // Update the answer with the size of the current combination

                // Trying to extend the combination by adding a new pair k
                for(int k = 0; k < n; ++k) {
                    if(!(mask & (1 << k)) && g[j][k]) { // If pair k is not in the combination and pairs j and k share a string
                        f[mask | (1 << k)][k] = 1; // Mark the new combination as valid
                    }
                }
            }
        }
    }

    cout << n - ans << '\n'; // Output the minimum number of pairs to remove
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
