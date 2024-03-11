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
        for (int i = 0; i < m; ++i)
            cin >> v[i].first >> v[i].second;
         set<int>possible;
        possible.insert(x);
        for(int i=0;i<m;++i)
        {
            int r = v[i].first;
            char c = v[i].second;
            set<int>next;
            for(auto xx : possible)
            {
                if(c=='0')
                {
                    int nxt = (xx+r-1)%n+1;
                    next.insert(nxt);
                }
                else if(c=='1')
                {
                    int nxt = (xx-r-1+n)%n+1;
                    next.insert(nxt);
                }
                else
                {
                    int nxt = (xx+r-1)%n+1;
                    int np = (xx-r-1+n)%n+1;
                    next.insert(nxt);
                    next.insert(np);
                }
            }
            possible=next;
        }
        cout<<possible.size()<<enl;
        for(auto j : possible)
        {
            cout<<j<<" ";
        }
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