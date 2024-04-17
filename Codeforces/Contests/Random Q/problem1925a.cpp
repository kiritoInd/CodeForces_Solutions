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
    ll n , k ;
    cin>> n >> k ; 
    
    int i = 0;
    string result = "";

    for(int i = 0 ; i < n;i++){
        int j = 0;
        while(j < k){
            result.push_back('a' + j);
            j++;
        }
    }


    cout<<result<<endl;

    return 0;

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