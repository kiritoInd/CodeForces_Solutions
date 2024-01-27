#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <climits>
#include <unordered_set>
#include <set>
#include <map>
#include <string.h>
#include <cmath>

typedef long long int ll;

using namespace std;
void solve() {
  ll H, W, ha, wa, hb, wb;
    cin >> H >> W >> ha >> wa >> hb >> wb;
 
    if (ha >= hb) {
        cout<<"Draw";
        return;
    }
    ll dist = hb - ha;
    if (dist % 2 == 1) {
        ll amove = ceil(dist / 2.0);
        ll bmove = dist / 2;
        ll la = max(wa - amove, 1LL);
        ll ra = min(wa + amove, W);
        ll lb = max(wb - bmove, 1LL);
        ll rb = min(wb + bmove, W);
        if (la <= lb  && rb <= ra) {
            cout<<"Alice";
        } else {
            cout<<"Draw";
        }
    } else {
        ll bmove = dist / 2;
        ll amove = dist / 2;
        ll lb = max(wb - bmove, 1LL);
        ll rb = min(wb + bmove, W);
        ll la = max(wa - amove, 1LL);
        ll ra = min(wa + amove, W);
        if (lb <= la && ra <= rb) {
            cout<<"Bob";
        } else {
            cout<<"Draw";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout<<endl;
    }
}