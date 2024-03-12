#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;
    cin>>t;
    vector<int> n(t);
    double sum = 0.0;
    double result = 0.0;
    for(int i = 0 ; i < t; i++){
        cin >> n[i];
        sum+= n[i];
    }
    result = sum/t;
    
    cout<<fixed<<setprecision(12)<<result<<endl;
    
    return 0;
}