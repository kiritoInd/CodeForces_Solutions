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
#include <string>

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
int reverse_and_count_digits(int number) {
    int reversed_number = 0;
    while (number > 0) {
        reversed_number = reversed_number * 10 + number % 10;
        number /= 10;
    }
    int count = 0;
    while (reversed_number > 0) {
        count++;
        reversed_number /= 10;
    }
    return count;
}

int count_digits(int number) {
    string number_str = to_string(number);
    
    return number_str.length();
}

void solve() {
    int n , m;
    cin>>n>>m;
    vector<int> nums(n);
    cin>>nums;
    vector<int> revcount;
    vector<int> digcount;
    for(int x : nums){
        revcount.push_back(reverse_and_count_digits(x));
        digcount.push_back(count_digits(x));
    }
    vector<int> diff;
    for(int i = 0 ; i < n ;i++){
        diff.push_back(digcount[i] - revcount[i]);
    }
    int sum = accumulate(digcount.begin() ,digcount.end() , 0);
    sort(diff.begin(), diff.end());

    bool anna = true;
    for(int i = n -1 ; i >=0; i--){
        if(anna){
            sum -= diff[i];
            anna = false;
        }else{
            anna = true;
        }
    }
    if(sum >= m + 1){
        cout<<"Sasha"<<"\n";
    }
    else cout<<"Anna" << "\n";
    return ; 
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