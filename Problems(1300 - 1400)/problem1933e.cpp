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
    vector<int> nums(n);
    
    cin>>nums;
    vector<int> preff(n);
    preff[0] = nums[0];
    for(int i = 1; i< n;i++){
        preff[i] = preff[i - 1]+ nums[i];
    }
    int q;
    cin>>q;
    while(q--){
        int l , u ;
        cin>>l>>u;
        l--;
        int x = u;
        if(l > 0) x +=  preff[l - 1];
        int lb =  lower_bound(preff.begin() , preff.end(), x) - preff.begin();
        if(lb <= l){
            cout<<l + 1<<" ";
        }else if(lb >= n){
            cout<<n<<" ";
        }else{
            if(abs(preff[lb]-x)<=abs(preff[lb-1]-x)){
                cout<<lb+1<<" ";
            }
            else{
                cout<<lb<<" ";
            }
        }
        cout<<enl;
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