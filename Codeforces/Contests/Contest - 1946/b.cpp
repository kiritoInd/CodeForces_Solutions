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
#include <climits>

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

const int mod = 1e9+7;
const long long inf = 1e18;
int kadanes(vector<int>& arr){
        int sumSofar = 0;
        int sumEndingHere = 0;
        for ( int i = 0 ; i< arr.size();i++)
        {
            sumEndingHere = (sumEndingHere+ arr[i]);

            if(sumEndingHere > sumSofar)
                sumSofar = sumEndingHere;
            
            if(sumEndingHere < 0)
                sumEndingHere = 0;
            
        }
        return sumSofar;
}
int solve() {
    int n , k;
    cin>>n>>k;
    vector<int> nums(n);
    cin>>nums;
    int maxs = kadanes(nums);
    int sum = 0;
    for(int x : nums){
        sum = (sum + x + mod);
    }
    while(k--){
        sum = (sum + maxs)%mod;
        maxs  = (maxs%mod + maxs%mod);
    }
    cout<<sum<<enl;
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