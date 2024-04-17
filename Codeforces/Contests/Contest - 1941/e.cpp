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

template <typename A, typename B> ostream& operator<< (ostream &cout, pair<A, B> const &p) { return cout << '(' << p.first << ',' << p.second << ')'; }
template <typename A, typename B> istream& operator>> (istream& cin, pair<A, B> &p) {cin >> p.first; return cin >> p.second;}
template <typename A> ostream& operator<< (ostream &cout, vector<A> const &v) {cout << '['; for(int i = 0; i < v.size(); i++) {if (i) cout << ','; cout << v[i];} return cout << ']';}
template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }

const long long mod = 1e9+7;
const long long inf = 1e18;

void solve() {
       int n , m , k , d;
    cin>>n>>m>>k>>d;
    vector<vector<int>> arr(n,vector<int>(m));
    vector<int> ans(n);
    for(int i = 0 ; i < n;i++){
        for(int j = 0  ; j < m;j++){
            cin>>arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        deque<int> dq;
        vector<int> v(m);
        v[0] = 1;
        dq.push_back(0);
        for(int j = 1; j <= min(d+1, m-2); j++){
            v[j] = arr[i][j] + 2;
            while(!dq.empty() && v[dq.back()] >= v[j]){
                dq.pop_back();
            }
            dq.push_back(j);
        }
        for(int j = d+2; j < m-1; j++){
            while(!dq.empty() && dq.front() < j-d-1){
                dq.pop_front();
            }
            v[j] = arr[i][j] + 1 + v[dq.front()];
            while(!dq.empty() && v[dq.back()] >= v[j]){
                dq.pop_back();
            }
            dq.push_back(j);
        }
        while(!dq.empty() && dq.front() < m-d-2){
            dq.pop_front();
        }
        ans[i] = 1 + v[dq.front()];
    }

    for(int i = 1; i < n; i++){
        ans[i] += ans[i-1];
    }

    int res = inf;
    int i = 0;
    int j = k-1;
    while(j < n){
        if(i == 0){
            res = min(res, ans[j]);
        }
        else{
            res = min(res, ans[j] - ans[i-1]);
        }
        i++;
        j++;
    }
    cout << res << "\n";
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