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
    int n , k; 
    cin>>n>>k;
    vector<int> nums(n);
    cin>>nums;
    if(k == 2){
        for(auto x : nums){
            if(x%2 == 0){
                cout<<0<<enl;
                return;
            }
        }
        cout<<1<<enl;
        return;
    }else if(k == 3){
        int res = inf;
        for(int i = 0; i< n;i++){
            if(nums[i] % 3 == 0){
                cout<<0<<enl;
                return;
            }else{
                res = min(3 - nums[i]%3 , res);
            }
        }
        cout<<res<<enl;
        return ;
    }else if(k == 4){
        int evecount = 0;
        int res = inf;
        for(int x : nums){
            res = min((4 - x%4), res);
            if(x % 4 == 0) {
                cout<<0<<enl;
                return;
            }
            if(x % 2 == 0){
                evecount++;
            }
        }
        if(evecount >= 2){
            int x =0 ;
            cout<<min(res , (int)0)<<enl;
        }else if(evecount == 1){
            int x =1;
            cout<<min(res , (int)1)<<enl;
        }else{
            int x =2;
            cout<<min(res , (int)2)<<enl;
        }

        return ;
    }else if(k == 5){
        int res = inf;
        for(int x : nums){
            if(x % 5 == 0) {
                cout<<0<<enl;
                return;
            }
            int j = (5 - x%5);
            res = min(res , j);
        }
        cout<<res<<enl;
        return;
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