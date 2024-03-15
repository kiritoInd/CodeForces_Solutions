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
    string s1, s2;
    cin>>s1>>s2;
    pair<int, int> start = {0 , 0};
    pair<int, int> end = {1, n-1};

    vector<vector<bool>> visited(2, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        if (cur == end) {
            return true;
        }

        int row = cur.first;
        int col = cur.second;

        // Check the cell on the right
        if (col+1 < n && !visited[row][col+1] && ((row == 0 && s1[col+1] == '>') || (row == 1 && s2[col+1] == '>'))) {
            q.push({row, col+1});
            visited[row][col+1] = true;
        }

        // Check the cell on the left
        if (col-1 >= 0 && !visited[row][col-1] && ((row == 0 && s1[col-1] == '<') || (row == 1 && s2[col-1] == '<'))) {
            q.push({row, col-1});
            visited[row][col-1] = true;
        }

        // Check the cell above
        if (row-1 >= 0 && !visited[row-1][col] && ((row == 0 && s1[col] == '<') || (row == 1 && s2[col] == '>'))) {
            q.push({row-1, col});
            visited[row-1][col] = true;
        }

        // Check the cell below
        if (row+1 < 2 && !visited[row+1][col] && ((row == 0 && s1[col] == '>') || (row == 1 && s2[col] == '<'))) {
            q.push({row+1, col});
            visited[row+1][col] = true;
        }
    }

    return false;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        if (solve()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}