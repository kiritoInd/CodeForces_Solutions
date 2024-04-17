#include <iostream>
#include <vector>
#include <unordered_map>

typedef long long int ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ll n,k,x;
        cin>>n>>k>>x;
        ll minsum=(k*(k+1))/2;
        ll maxsum=((n*(n+1))/2)-(((n-k)*(n-k+1))/2);
        if(x<=maxsum && x>=minsum)
        cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
