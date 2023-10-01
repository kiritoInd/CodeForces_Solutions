#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	int a,b,n;
    	cin>>a>>b>>n;
    	ll ans=b;
        int x;
    	for(int i=0;i<n;i++){
    		cin>>x;
    		ans+=min(a-1,x);
    	}
    	cout<<ans<<endl;
    }
    return 0;
}
