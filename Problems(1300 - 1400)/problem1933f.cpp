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
const long long INF = 1e18;

int solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    for(auto &v:a)
        for(auto &x:v){
            cin>>x;
            x=!x;
        }
 
    const int N = n*m;
    vector<vector<int>> e(N);
 
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(!a[i][j])
                continue;
            const int cur=i*m+j;
            if(a[(i+1)%n][j]&&a[(i+2)%n][j]){
                const int nI=(i+2)%n,nJ=j;
                e[cur].emplace_back(nI*m+nJ);
            }
            if(j+1<m&&a[(i+1)%n][j+1]){
                const int nI=(i+1)%n,nJ=j+1;
                e[cur].emplace_back(nI*m+nJ);
            }
        }
 
    vector<int> dist(N,INF);
    dist[0]=0;
    set<pair<int,int>> pq;
    pq.insert(pair<int,int>{0,0});
    while(!pq.empty()){
        const auto tp=*pq.begin();
        pq.erase(tp);
        const int t=tp.first,u=tp.second;
        for(const auto &v:e[u]){
            if(dist[v]<=t+1)
                continue;
            if(dist[v]!=INF)
                pq.erase(pair<int,int>{dist[v],v});
            dist[v]=t+1;
            pq.insert(pair<int,int>{dist[v],v});
        }
    }
 
    int ans = INF;
 
    for(int i=0;i<n;i++){
        const int t=dist[i*m+m-1];
        if(t>=INF)
            continue;
        const int curIdx = ((i-t)%n + n)%n;
        const int extraT = (curIdx+1)%n;
        ans=min(ans,t+extraT);
    }
 
    if(ans>=INF/2)
        ans=-1;
    cout<<ans<<endl;
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