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
    int n;
    cin>>n;
    vector<int> a(n);
    cin>>a;

    int m;
    cin>>m;
    vector<int> b(m);
    cin>>b;

    int l;
    cin>>l;
    vector<int> c(l);
    cin>>c;

    int q;
    cin>>q;
    vector<int> x(q);
    cin>>x;

    set<int> st;
    for(int i : x){
        st.insert(i);
    }
    set<int> res;

    for(int i = 0; i< n;i++){
        for(int j = 0; j < m ; j++){
            for(int k = 0; k < l ; k++){
                int p = a[i] + b[j] + c[k];
                if(st.find(p) != st.end()){
                    res.insert(p);
                }
            }
        }
    }
    for(int y : x){
        if(res.find(y) !=  res.end()){
            cout<<"Yes"<<enl;
        }else cout<<"No"<<enl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    solve();
}