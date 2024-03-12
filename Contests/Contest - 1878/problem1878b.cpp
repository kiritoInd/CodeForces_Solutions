#include <iostream>
#include <vector>

using namespace std;


int main(){
int t;
   cin>>t; 
   while(t--){ 
        int n;
        cin>>n;
        int k=3;
        for(int i=0;i<n;i++){
            cout<<k<<" ";
            k+=2;
        }
        cout<<endl;
    }
    return 0;
}