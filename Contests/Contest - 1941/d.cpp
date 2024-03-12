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
#define int long long
#define sz(s) (int)s.size()
#define all(v) (v).begin(), (v).end()
#define enl '\n'

template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) { return cout << '(' << p.first << ',' << p.second << ')'; }
template <typename A, typename B>
istream &operator>>(istream &cin, pair<A, B> &p)
{
    cin >> p.first;
    return cin >> p.second;
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v)
{
    cout << '[';
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ',';
        cout << v[i];
    }
    return cout << ']';
}
template <typename A>
istream &operator>>(istream &cin, vector<A> &x)
{
    for (int i = 0; i < x.size() - 1; i++)
        cin >> x[i];
    return cin >> x[x.size() - 1];
}
template <typename A, typename B>
A amax(A &a, B b)
{
    if (b > a)
        a = b;
    return a;
}
template <typename A, typename B>
A amin(A &a, B b)
{
    if (b < a)
        a = b;
    return a;
}

const long long mod = 1e9 + 7;
const long long inf = 1e18;

void solve()
{
    int n , m , x;
    cin>>n>>m>>x;
    vector<pair<int, char>>v(m);
    vector<int> cur;
    vector<int> next;
    //jha sai start karna wo push kardiay joki hai x;

    cur.push_back(x);

    for (int i = 0; i < m; i++)
        cin >> v[i].first >> v[i].second;

    for(int i=0 ; i<m ; i++){
        int r = v[i].first;
        char c = v[i].second;
        if(c == '?'){
            //cur position sai itrate kiya counter clock wise and clock wise both
            for(int y : cur){
                next.push_back((y + v[i].first - 1)%n + 1);
                next.push_back((y - v[i].first - 1 + n)%n + 1);
            }
            
        }else if(c == '0'){
            for(int y : cur){
                next.push_back((y + v[i].first - 1)%n + 1);
            }
        }else{
            for(int y : cur){
                next.push_back((y - v[i].first - 1 + n)%n + 1);
            }
        }
        
        sort(next.begin() ,next.end());

        //sare number unique kardiye | iski jagha set bhi le sakta but yeh sahi lag rha tha

        next.erase(unique(next.begin() , next.end()) , next.end());

        //yeh karte karte ultimatily sare possible soltion mill jayengai at end 
        cur = next;

        // khali kardiya taki algi queries le sake

        next.clear();
    }

    //mere code mai enl == "\n" sai define hai 
    cout<<cur.size()<<enl;
    for(int t : cur) cout<<t<<" ";
    cout<<enl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}