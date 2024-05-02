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

int solve() {
    int n , k , pa , pb;
    cin>>n>>k>>pa>>pb;
    vector<int> p(n);
    cin>>p;
    vector<int> a(n);
    cin>>a;
    for(int i = 0 ;i < n;i++){
        p[i]--;
    }
    pa--;
    pb--;
    int res1 = 0;
    int res2 = 0;

    int scoreA = 0;
    int scoreB = 0;

    for(int i= 0 ;i <= min(k,n ) ;i++){
            res1 = max(res1 ,scoreA + (k - i)*a[pa]);
            res2 = max(res2 ,scoreB + (k - i)*a[pb]);
            scoreA += a[pa];
            scoreB += a[pb];
            pa = p[pa];
            pb = p[pb];
    }
    // cout<<res1<<" "<<res2<<" ";
    // cout<<scoreA<<" "<<scoreB;
    if(res1 > res2){
        cout<<"Bodya"<<enl;
    }else if(res1 < res2){
        cout<<"Sasha"<<enl;
    }else cout<<"Draw"<<enl;

    return 0;
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