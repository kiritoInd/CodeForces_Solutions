#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL); 
    int t;
    cin >> t; 
    while (t--) {
        ll n;
        cin >> n; 
        vector<vector<ll>> setcontainer;  
        set<ll> completeSet; 

        for(int i = 0; i < n; i++) {
            ll k;
            cin >> k;  
            vector<ll> sset(k);

            for(int j = 0; j < k; j++) {
                cin >> sset[j];  
                completeSet.insert(sset[j]);  
            }

            setcontainer.push_back(sset);  
        }

        ll ans = 0;  

        for (auto &i : completeSet) {
            // Check those sets which don't have the 'i' element
            set<ll> rest;  // A set to store elements not containing 'i'
            for(int j=0 ; j<n; j++){
                bool kp = true;
                for (auto &x : setcontainer[j]) {
                    if (x == i) {
                        kp = false;
                        break;
                    }
                }
                if (kp) {
                    for (auto &x : setcontainer[j]) {
                        rest.insert(x);  // Add elements from sets that don't have 'i'
                    }
                }
            }
            ll sizo = rest.size();
            ans = max(ans, sizo);  // Update the answer with the maximum size
        }

        cout << ans << endl;  // Print the maximum size of the set without 'i'
    }

    return 0;
}
