#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
 
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
 
        vector<int> cnt(26, 0);
        string ans = "";
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                if (cnt[j] == a[i]) {
                    ans += (char) ('a' + j);
                    cnt[j]++;
                    break;
                }
            }
        }
 
        cout << ans << endl;
    }
    
    return 0;
}