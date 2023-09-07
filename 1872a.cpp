#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int ll;

using namespace std;


void solve(){

    vector<ll>v(3, -1);
    for(int i=0; i<3; i++){
    	cin>>v[i];
	}

    int count = 0;
    int maxB = max(v[0], v[1]);
    int minB = min(v[0], v[1]);


    while(maxB > minB){
        maxB = maxB - v[2];
        minB = minB + v[2];
        count++;
    }

    cout<<count<<endl;


}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t ;
    cin>>t;
	while(t--){
		solve();
	}
}