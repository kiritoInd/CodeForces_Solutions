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
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
bool check(vector<int> &nums ,int i){
    vector<int> temp;
    for(int k = 0; k < nums.size() ; k++){
        if(k != i ){
            temp.push_back(nums[k]);
        }
    }
    vector<int> gc;
    for(int k = 0 ; k < temp.size() - 1;k++){
        gc.push_back(gcd(temp[k ] , temp[k + 1]));
    }
    if(is_sorted(gc.begin() , gc.end())){
        return true;
    }
    return false;
}
int solve() {
   // Your solution here
    int n;
    cin>>n;
    vector<int> nums(n);
    cin>>nums;
    vector<int> gc;
    for(int i = 0; i < n - 1 ;i++){
           gc.push_back(gcd(nums[i] , nums[i + 1]));
    }
    if(is_sorted(gc.begin() , gc.end())){
            cout<<"YES"<<enl;
            return 0;
    }
    int i = 0;
    for(i = 0 ; i < n - 2; i++){
        if(gc[i] > gc[i + 1]){
            break;
        }
    }
    if(check(nums , i)){
        cout<<"YES"<<enl;
        return 0; 
    }
    if(check(nums , i + 1)){
        cout<<"YES"<<enl;
        return 0; 
    }
    if(check(nums , i + 2)){
        cout<<"YES"<<enl;
        return 0; 
    }
    cout<<"NO"<<enl;

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