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
	int a;
	cin>>a;
    vector<int> nua(a);
    vector<int> nub(a);
    cin>>nua;
    cin>>nub;
    vector<int> nba(a);
    vector<int> nbb(a);
    cin>>nba;
    cin>>nbb;
    int xa = accumulate(nua.begin() , nua.end() , 0);
    int xd = accumulate(nub.begin() , nub.end() , 0);
    int ya = accumulate(nba.begin() , nba.end() , 0);
    int yd = accumulate(nbb.begin() , nbb.end() , 0);
    if(xa > ya && xd > yd){
        cout<<"A"<<enl;
    }else if(xa < ya && xd < yd){
        cout<<"P"<<enl;
    }else{
        cout<<"DRAW"<<enl;
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