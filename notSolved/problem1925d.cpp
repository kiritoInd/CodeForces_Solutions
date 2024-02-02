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


using namespace std;
#define  int          long long
#define  sz(s)        (int)s.size()
#define  all(v)       (v).begin(),(v).end()

template <typename A, typename B> ostream& operator<< (ostream &cout, pair<A, B> const &p) { return cout << "(" << p.first << ", " << p.second << ")"; }
template <typename A, typename B> istream& operator>> (istream& cin, pair<A, B> &p) {cin >> p.first; return cin >> p.second;}
template <typename A> ostream& operator<< (ostream &cout, vector<A> const &v) {cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";}
template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }

const long long mod = 1e9+7;
const long long inf = 1e18;

int binpow(int a,int b) {
    if(b<0) return 0;
    int res = 1;
    while(b > 0) {
        if(b & 1) res = res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
 
int divide(int a,int b) {
    return a*binpow(b,mod-2)%mod;
}
 
int nc2(int n) {
    return n*(n-1)/2%mod;
}
 
int inv_nc2(int n) {
    return 2*binpow(n,mod-2)*binpow(n-1,mod-2)%mod;
}
 
void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    int ans = 0;
 
    for(int i=0;i<m;i++) {
        int a,b,f;
        cin>>a>>b>>f;
        ans += f;
    }
 
    ans = ans%mod*k%mod*nc2(n)%mod;
 
    ans += m*nc2(k)%mod;
 
    ans = ans%mod*inv_nc2(n)%mod*inv_nc2(n)%mod;
 
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