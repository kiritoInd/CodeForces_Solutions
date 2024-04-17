#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int ll;

using namespace std;

int solve() {
    ll n, f, a, b;
    cin>>n>>f>>a>>b;
    vector<ll> nums(n);
    for(int i =0; i< n; i++){
        cin>>nums[i];
    }
    ll inistate = 0;
    int i = 0;
    while(f > 0){
        if(i >= n) return true;
        if(((nums[i] - inistate)*a) < b){
            f -= (nums[i] - inistate)*a;
            inistate = nums[i];
        }else {
            f -= b;
            inistate = nums[i];
        }
        i++;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
       if(solve()) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
    }
}