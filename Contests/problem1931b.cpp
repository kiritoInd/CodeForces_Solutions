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

template <typename A, typename B> ostream& operator<< (ostream &cout, pair<A, B> const &p) { return cout << '(' << p.first << ',' << p.second << ')'; }
template <typename A, typename B> istream& operator>> (istream& cin, pair<A, B> &p) {cin >> p.first; return cin >> p.second;}
template <typename A> ostream& operator<< (ostream &cout, vector<A> const &v) {cout << '['; for(int i = 0; i < v.size(); i++) {if (i) cout << ','; cout << v[i];} return cout << ']';}
template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }

const long long mod = 1e9+7;
const long long inf = 1e18;

bool solve() {
    int n;
    cin>>n;
    vector<int> nums(n);
    cin>>nums;
    int sum = 0;
    for(int x : nums) sum += x;

    int x = sum/n;
    int extra = 0;
    for(int i = 0 ; i< nums.size(); i++){
        if(nums[i] + extra < x ) return false;
        else{
            int p = nums[i] - x;
            extra += p;
        }
    }
    return true;

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        if(solve()){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}