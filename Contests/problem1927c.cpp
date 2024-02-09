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
#include <unordered_set>


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

void solve() {
    int n , m , k;
    cin>> n>>m>>k;
    vector<int> a(n);
    vector<int> b(m);
    cin>>a;
    cin>>b;
    unordered_set<int> st1;
    unordered_set<int> st2;

    for(int i = 0 ; i < a.size() ; i++){
        st1.insert(a[i]);
    }
    for(int i = 0 ; i < b.size() ; i++){
        st2.insert(b[i]);
    }

    int pt1  = 0;
    int pt2 = 0;
    int exinb = 0;
    
    for(int i = 1; i <= k; i++ ){
        if(st1.find(i) != st1.end() && st2.find(i) != st2.end()){
            exinb++;
             pt1++;
              pt2++;
        }else if(st1.find(i) != st1.end()){
            pt1++;
        }else if(st2.find(i) != st2.end()){
            pt2++;
        }
    }
    k += exinb*2;
    if(pt1 <= k /2 && pt2 <= k/2 && (pt1 + pt2 + exinb) == k) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

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