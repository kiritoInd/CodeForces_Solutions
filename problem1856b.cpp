//good arrays   
#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int ll;

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<ll>v(n, -1);
    for(int i=0; i<n; i++){
    	cin>>v[i];
	}

    if(v.size() == 1) {
        cout<<"NO"<<endl;
        return;
    }

    ll sums = 0;
    ll ones = 0;

    for(int i = 0; i < n;i++){
      if(v[i]==1){
        ones++;
      }else{
        sums += (v[i]-1);

      }
    }
    cout<<sums<<" "<< ones;
    if(sums < ones){
      cout << "NO" << endl;
    }else{
      cout << "YES" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t ;
    cin>>t;
	while(t--){
		solve();
	}
	
}