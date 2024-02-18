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

int solve() {
    int n;
    cin>>n;
    char ch;
    cin>>ch;
    vector<int> c;
    vector<int> d;
    vector<int> h;
    vector<int> s;
    int k = 2*n;
    for(int i = 0 ; i< k ;i++){
        string y;
        cin>>y;
        if(y[1] == 'C'){
            c.push_back(y[0] - '0');
        }
        if(y[1] == 'H'){
            h.push_back(y[0] - '0');
        }
        if(y[1] == 'D'){
            d.push_back(y[0] - '0');
        }
        if(y[1] == 'S'){
            s.push_back(y[0] - '0');
        }
    }
    sort(c.begin() , c.end() );
    sort(d.begin() , d.end() );
    sort(h.begin() , h.end() );
    sort(s.begin() , s.end() );

    int i = 0; 
    int j = 0;
    int p = 0;
    int l = 0;
    vector<string> result;

    for(p ; p < c.size() ; p +=2){
        if(p + 1 >= c.size()) break;

        cout<<c[p]<<'C'<<" "<<c[p + 1]<<'C'<<endl;
    }
    for(j ; j < d.size() ; j +=2){
        if(j + 1 >= d.size()) break;

        cout<<d[j]<<'D'<<" "<<d[j + 1]<<'D'<<endl;
    }
    for(i ; i < s.size() ; i +=2){
        if(i + 1 >= s.size()) break;

        cout<<s[i]<<'S'<<" "<<s[i + 1]<<'S'<<endl;
    }
    for(l ; l < h.size() ; l +=2){
        if(l + 1 >= h.size()) break;

        cout<<s[l]<<'H'<<" "<<s[l + 1]<<'H'<<endl;
    }

    if(ch == 'S' && i < s.size()){
        if(l < h.size()){
            cout<<s[i]<<'S'<<" "<<h[l]<<'H'<<endl;
        }
        if(j < d.size()){
            cout<<s[i]<<'S'<<" "<<d[j]<<'D'<<endl;
        }
        if(p < c.size()){
            cout<<s[i]<<'S'<<" "<<c[p]<<'C'<<endl;
        }
    }
    if(ch == 'D' && j < d.size()){
        if(i < s.size()){
            cout<<d[j]<<'D'<<" "<<s[i]<<'S'<<endl;
        }
        if(l < h.size()){
            cout<<d[j]<<'D'<<" "<<h[l]<<'H'<<endl;
        }
        if(p < c.size()){
            cout<<d[j]<<'D'<<" "<<c[p]<<'C'<<endl;
        }

    }
    if(ch == 'C' && p < c.size()){
        if(i < s.size()){
            cout<<c[j]<<'C'<<" "<<s[i]<<'S'<<endl;
        }
        if(l < h.size()){
            cout<<c[j]<<'C'<<" "<<h[l]<<'H'<<endl;
        }
        if(j < d.size()){
            cout<<c[j]<<'C'<<" "<<d[j]<<'D'<<endl;
        }
        
    }
    if(ch == 'H' && l < h.size()){
        if(i < s.size()){
            cout<<h[l]<<'H'<<" "<<s[i]<<'S'<<endl;
        }
        if(p < c.size()){
            cout<<h[l]<<'H'<<" "<<c[p]<<'C'<<endl;
        }
        if(j < d.size()){
            cout<<h[l]<<'H'<<" "<<d[j]<<'D'<<endl;
        }
        
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