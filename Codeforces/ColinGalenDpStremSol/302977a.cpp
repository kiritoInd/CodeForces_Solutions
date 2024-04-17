#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int ll;

using namespace std;

int solve() {
    int n;
    cin>> n;
    if(n < 2) return 0;

    vector<int> dp(n , -1);
    dp[0] = 0;
    dp[1] = 2;
    for(int i = 2 ; i< n; i++){
        if(n % 3 == 0 && n%2 != 0) {
            dp[i] = 0;
        }
        else dp[i] = dp[i - 2]*2;
    }
    return dp.back();
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout<<solve()<<endl;
}