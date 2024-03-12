#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int ll;

using namespace std;

vector<int> dp = {1 ,3 ,6, 10, 15, 21, 28, 36, 45, 55};

ll solve() {
    ll n ;
    cin>> n;
    ll x = n;
    ll digit = 0;
    ll result = 1;
    while(x != 0){
        digit = x%10;
        result *= dp[digit];
        x = x/10;
    }
    return result;
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
