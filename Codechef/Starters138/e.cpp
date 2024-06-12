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

vector<bool> sieve(int limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

vector<int> generate_primes(int limit) {
    vector<bool> is_prime = sieve(limit);
    vector<int> primes;
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int solve() {
    int n;
    cin >> n;
    int limit = sqrt(n);
    vector<int> primes = generate_primes(limit);
    vector<int> squares;
    for (int prime : primes) {
        squares.push_back(prime * prime);
    }
    for (int i = 0; i < primes.size(); i++) {
        for (int j = i + 1; j < primes.size(); j++) {
            int c_squared = n - squares[i] - squares[j];
            if (c_squared <= 0) continue;
            int c = sqrt(c_squared);
            if (c_squared == c * c && c > primes[j] && binary_search(primes.begin(), primes.end(), c)) {
                cout << "YES" << enl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
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