#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

typedef long long int ll;

using namespace std;

int solve() {
    int n , x;
    cin>>n>>x; 
    vector<int> gas(n);
    for(int i = 0; i < n ; i++) cin>>gas[i];
    int minfuel = INT_MIN;

    for(int i = 1 ; i < n ; i++){
        minfuel = max(minfuel , gas[i] - gas[i - 1]);
    }
    minfuel = max(minfuel, gas[0]);

   
    minfuel = max(minfuel , 2*(x - gas.back()));
    return minfuel;

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