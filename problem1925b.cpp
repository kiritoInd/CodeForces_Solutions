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



ll solve()
{   
    ll x, n , ans;
    cin >> x >> n;
   for(int i=1; i*i<=x; i++){
			if(x%i==0){
				if(x/i>=n)ans=i;
				if(i>=n){
					ans=x/i;break;
				}
			}
		}
	cout<<ans<<endl;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
       solve();
    }
}