#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

typedef long long ll;

using namespace std;
using ll=long long;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>v(n);
        
        for(auto &i:v)
        {
            cin>>i;
        }
        ll ans=v[0]-1;
        for(ll i=1;i<n;i++)
        {
            if(v[i]>v[i-1])
            {
                ans+=(v[i]-v[i-1]);
            }
        }
        cout<<ans<<endl;
       
    }
}
