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
    int n, k;
    cin>>n>>k;
    vector<int> nums(n);
    cin>>nums;
    int atone = 0;
    int attwo = 0;
    if(k % 2 != 0){
        atone = k/2 + 1;
    }else atone = k/2;
    attwo = k/2;
    // cout<<atone<<" "<<attwo;
    int left = 0;
    for(int i = 0; i< n;i++){
        if(atone - nums[i] >= 0){
            atone -= nums[i];
            nums[i] = 0;
        }else{
            nums[i] -= atone;
            atone = 0;
        }
    }
    for(int i = n - 1; i >= 0;i--){
        if(attwo - nums[i] >= 0){
            attwo -= nums[i];
            nums[i] = 0;
        }else{
            nums[i] -= attwo;
            attwo = 0;
        }
    }
    int res = 0;
    for(int x :nums){
        if(x > 0)res++;
    }
    cout<<n - res<<enl;
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