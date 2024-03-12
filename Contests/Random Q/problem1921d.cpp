#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int ll;

using namespace std;

ll solve() {
    ll n , x;
    cin>>n>>x;
    vector<ll> p(n);
    vector<ll> v(x);
    for(ll i = 0 ; i<n;i++){
        cin>>p[i];
    }
    for(ll i = 0 ; i<x;i++){
        cin>>v[i];
    }
    sort(p.begin(), p.end());
    sort(v.begin(), v.end());
    ll left = n-1 ; ll right = x - 1;
    ll ans = 0;
    ll k = 0 ;
    ll l = 0;
    while(n--){
        if(abs(v[right] - p[k]) > abs(p[left] - v[l])){
            ans += abs(v[right] - p[k]);
            right--;
            k++;
        }else{
            ans += abs(p[left] - v[l]);
            left--;
            l++;
        }
      
    }
    return ans;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cout<<solve()<<endl;
    }
}