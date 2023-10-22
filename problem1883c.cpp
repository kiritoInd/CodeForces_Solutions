#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

typedef long long int ll;

using namespace std;

int solve() {
    int n, k;
    cin>> n >> k;
    vector<int> v(n);
    vector<int> nums;
    int prod = 1;
    for(int i = 0  ; i<n ; i++){
        cin>>v[i];
        prod *= v[i];
    }
    for(int i = 0; i < n; i++){
        nums.push_back(v[i]%k);
        if(v[i]%k == 0) return 0;
    }
    int res = INT_MAX;

    for(int i = 0 ; i < n; i++){
        res =  min(res, k - nums[i]);
    }

    if(k % 2 == 0 && k != 2) {
        res = prod%k;
    }
    return res;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cout<<solve()<<" ";
    }
}