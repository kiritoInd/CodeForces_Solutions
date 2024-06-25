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
#include <string>
#include <climits>
using namespace std;
#define  int          long long
#define  sz(s)        (int)s.size()
#define  all(v)       (v).begin(),(v).end()
#define  enl         '\n'

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

int dp(int i, vector<int> &nums) {
    if(i >= nums.size())  return 1e9;
    if (i == nums.size() - 1) return nums[i];
    return min(nums[i] + dp(i + 1, nums) , nums[i] * dp(i + 1, nums));
}
void solve() {
    int n;
    cin >> n;
    string s;
    cin>>s;
    vector<int> nums;
    for(auto &c : s) {
        nums.push_back(c - '0');
    }
    int res = inf;
    for(int i = 0; i < n - 1; i++){
        vector<int> temp;
        for(int j = 0; j < i; j++){
            temp.push_back(nums[j]);
        }
        int x = nums[i] * 10;
        x += nums[i + 1];
        temp.push_back(x);
        for(int j = i + 2; j < n ;j++){
            temp.push_back(nums[j]);
        }
        res = min({res , dp(0  , temp) });
    }
    cout<<res<<enl;
}

signed main() {
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   int t;
   cin >> t;
   while (t--) {
       solve();
   }
   return 0;
}