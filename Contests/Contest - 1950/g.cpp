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
int solve() {
    int n;
    cin>>n;
    
    vector<vector<string>> v;
    for(int i = 0 ; i<n;i++){
        string s1 , s2;
        cin>>s1>>s2;
        v.push_back({s1 , s2});
    }
    bool flag = true;
    unordered_map<string, vector<string>> adj;
    unordered_map<string, int> count;
    int p = 0;
    
    for(int i = 0 ; i< n;i++){
        string s = v[i][0] + v[i][1];
        if(adj.find(s) != adj.end()){
            count[s]++;
        }
        adj[s];

    }
    for(int i = 0 ; i< n;i++){
        string s = v[i][0] + v[i][1];
        for(int j = 0 ; j < n;j++){
            if(v[i][0] == v[j][0] || v[i][1] == v[j][1]){
                adj[s].push_back(v[j][0] + v[j][1]);
            }
        }
    }

  
    int res = -inf;
    for(auto& it : adj){
        unordered_map<string, bool> visited;
        for(auto x : adj){
            visited[x.first] = false;
        }
        dfs(it.first, adj, visited);
        int c = 0;
        for(auto l : visited){
            if(l.second == true){
                if(count.find(l.first) != count.end()){
                    c += count[l.first] + 1;
                }else c++;
            }
        }
         res = max(res, c );
    }
    if(res == inf){
        res = (n - 1);
    }
    cout<<n - res <<enl;
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