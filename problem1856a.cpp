#include <iostream>
#include <vector>

using namespace std;
typedef long long int ll;


void solve(){
    int n;
    cin>>n;
    vector<ll>v(n, -1);
    for(int i=0; i<n; i++){
    	cin>>v[i];
	}
	ll minNum = v[n-1];
	ll maxNum = 0;
	
	for(int i= n-2; i>=0; i--){	
	   minNum = min(minNum, v[i]);
	   if(v[i] > minNum){
	   	 maxNum = max(maxNum, v[i]);
	   } 
	}
	cout<<maxNum<<endl;
}

int main(){
     int t ;
     cin>>t;
	while(t--){
		solve();
	}
	
}