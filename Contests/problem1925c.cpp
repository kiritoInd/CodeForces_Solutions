#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <climits>
#include <unordered_set>
#include <set>
#include <map>
#include <string.h>

typedef long long int ll;

using namespace std;

ll solve() {
        ll n, k, m, count=0,  kk=0;
		cin >> n >> k >> m;
		string s, ks;
		cin >> s;
		vector <vector <bool> > a(n, vector <bool> (k, 0));
		for (int i=0; i<m && kk!=n ; i++) {
			count += !a[kk][s[i]-'a'];
			a[kk][s[i]-'a']=1;
			if (count==k) {
				count=0;
				kk++;
				ks+=s[i];
               
			}
		}
		for (int l=0; l<k&&kk!=n; l++) {
			if (!a[kk][l]) {
				while (ks.size()!=n) {
					ks+='a'+l;
				}
				break;
			}
		}
		cout << (kk<n?"NO\n"+ks:"YES") << endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}