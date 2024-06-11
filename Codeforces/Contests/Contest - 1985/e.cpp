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
int calculateLocations(int x, int y, int z, int dx, int dy, int dz) {
    return (int)(x - dx + 1) * (y - dy + 1) * (z - dz + 1);
}
int solve() {
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    int mxl = 0;
    for (int dx = 1; dx * dx <= k; dx++) {
        if (k % dx == 0) {
            int area = k / dx;
            for (int dy = 1; dy * dy <= area; dy++) {
                if (area % dy == 0) {
                    int dz = area / dy;
                    if (dx <= x && dy <= y && dz <= z) mxl = max(mxl, calculateLocations(x, y, z, dx, dy, dz));
                    if (dx <= x && dz <= y && dy <= z) mxl = max(mxl, calculateLocations(x, y, z, dx, dz, dy));
                    if (dy <= x && dx <= y && dz <= z) mxl = max(mxl, calculateLocations(x, y, z, dy, dx, dz));
                    if (dy <= x && dz <= y && dx <= z) mxl = max(mxl, calculateLocations(x, y, z, dy, dz, dx));
                    if (dz <= x && dx <= y && dy <= z) mxl = max(mxl, calculateLocations(x, y, z, dz, dx, dy));
                    if (dz <= x && dy <= y && dx <= z) mxl = max(mxl, calculateLocations(x, y, z, dz, dy, dx));
                }
            }
        }
    }
    cout << mxl << '\n';
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