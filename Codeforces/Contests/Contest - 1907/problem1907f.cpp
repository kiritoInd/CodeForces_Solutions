#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
 
#define ll long long
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        vector<int> arr(n);
 
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        ll an=0;
        for(ll i=1;i<n;i++){
            if(arr[i]<arr[i-1]){
                an=-1;
            }
        }
 
        if(an==0){
            cout<<"0"<<endl;
            continue;
        }
        an=1;
 
        for(ll i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                an=-1;
            }
        }
 
        if(an==1){
            cout<<"1"<<endl;
            continue;
        }
 
        bool check=false;
        ll ans=INT_MAX;
        for(ll i=1;i<n;i++){
            if(arr[i]<arr[i-1]){
                bool ch=true;
                ll prev=INT_MIN;
                for(ll j=0;j<n;j++){
                    if(arr[(i+j)%n]>=prev){
                        prev=arr[(i+j)%n];
                    }else{
                        ch=false;
                        break;
                    }
                }
                if(ch){
                    ans=min((n-i),i+2);
                }
                break;
            }
        }
 
 
        for(ll i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                bool ch=true;
                ll prev=INT_MAX;
 
                for(ll j=0;j<n;j++){
                    if(arr[(i+j)%n]<=prev){
                        prev=arr[(i+j)%n];
                    }else{
                        ch=false;
                        break;
                    }
                }
 
                if(ch){
                    ll val=min(n-i,i)+1;
                    ans=min(ans,val);
                }
                break;
            }
        }
 
        if(ans==INT_MAX){
            ans=-1;
            
        }
 
        cout<<ans<<endl;
 
 
 
 
    }
    return 0;
}