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

int solve() {
    int n;
    cin>>n;
    vector<int> nums(n);
    cin>>nums;
    vector<int> res;
    
    if (is_sorted(nums.begin(), nums.end())) {
        cout<<"YES"<<enl;
        return 0;
    } 
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        if(num < 10){
            res.push_back(num);
        } else {
            int temp = num;
            vector<int> digits;
            bool flag = true;
            while (num > 0) {
                if(!res.empty() && num%10 < res.back() ){
                    flag = false;
                }
                digits.push_back(num % 10);
                num /= 10;
            }
            reverse(digits.begin(), digits.end());
            if(is_sorted(digits.begin(), digits.end()) && flag){
                for(int x : digits){
                    res.push_back(x);
                }
                continue;
            }
            if(!res.empty() && is_sorted(digits.begin(), digits.end()) && temp < res.back() ) {
                for(int x : digits){
                    res.push_back(x);
                }
            }
            else res.push_back(temp);
        }
    }

    if (is_sorted(res.begin(), res.end())) {
        cout<<"YES"<<enl;
    } else {
         cout<<"NO"<<enl;
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
}