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

using namespace std;
#define  int          long long
#define  sz(s)        (int)s.size()
#define  all(v)       (v).begin(),(v).end()

template <typename A, typename B> ostream& operator<< (ostream &cout, pair<A, B> const &p) { return cout << '(' << p.first << ',' << p.second << ')'; }
template <typename A, typename B> istream& operator>> (istream& cin, pair<A, B> &p) {cin >> p.first; return cin >> p.second;}
template <typename A> ostream& operator<< (ostream &cout, vector<A> const &v) {cout << '['; for(int i = 0; i < v.size(); i++) {if (i) cout << ','; cout << v[i];} return cout << ']';}
template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }

const long long mod = 1e9+7;
const long long inf = 1e18;

int solve() {
    int n ;
    cin>>n;
    vector<int> arr(n);
    cin>>arr;
    vector<int>left(n,0), right(n,0);
 
    map<int, int> mp;

    
    mp[n - 1] = -1;
    mp[0] = 1;
    for (int i = 1; i < n - 1; i++)
    {
            int r = abs(arr[i+1] - arr[i]);
        int l = abs(arr[i-1] - arr[i]);
        if (l >= r)    mp[i] = 1;
        else   mp[i] = -1;
    }
    left[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (mp[i] != -1)left[i] = left[i - 1] + abs(arr[i] - arr[i - 1]);
        else left[i] = 1 + left[i - 1]; 
    }
    right[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (mp[i] != 1)  right[i] = right[i + 1] + abs(arr[i] - arr[i + 1]);
        else      right[i] = 1 + right[i + 1];
        
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (x == y)
        {
            cout << 0 << "\n";
            continue;
        }
        if(x!=y)
        {
            if (y <= x)cout << left[x - 1] - left[y - 1] << "\n";
            else  cout << right[x - 1] - right[y - 1] << "\n";
        }
    }
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