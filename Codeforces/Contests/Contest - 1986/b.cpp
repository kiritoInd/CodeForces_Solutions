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

int solve() {
    int n , m;
    cin>>n>>m;
    vector<vector<int>> nums(n , vector<int> (m));
    for(int i = 0 ; i < n ;i++){
        cin>>nums[i];
    }
    for(int i = 0; i < n ;i++){
        for(int j = 0 ; j < m ; j++){
            bool isup = false;
            bool isdown = false;
            bool isleft = false;
            bool isright = false;
            int mini = -inf;
            if(i > 0 && nums[i][j] > nums[i - 1][j]) {
                isup = true;
                mini = max(nums[i - 1][j] , mini);
            }else if(i == 0 ) isup = true;

            if(j > 0 && nums[i][j] > nums[i][j - 1]){
                isdown = true;
                mini = max(nums[i][j - 1] , mini);
            }else if(j == 0 ) isdown = true;

            if(i < n - 1 && nums[i][j] > nums[i + 1][j]){
                isleft = true;
                mini = max(nums[i + 1][j] , mini);
            }else if(i == n - 1 ) isleft = true;

            if(j < m - 1 && nums[i][j] > nums[i][j + 1]){
                isright = true;
                mini = max(nums[i][j + 1] , mini);
            }else if(j == m - 1 ) isright = true;

            if(isup && isdown && isleft && isright){
                nums[i][j] = mini;
            }
        }
    }
    for(int i = 0; i < n ;i++){
        for(int j = 0 ; j < m ; j++){
            cout<<nums[i][j]<<" ";
        }
        cout<<enl;
    }
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
   return 0;
}