#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int ll;

using namespace std;

bool solve() {
    int n ;
    cin>>n;
 
    string s;
    cin>>s;


    int countn = 0;
    int countzero = 0;
    int countone = 0;

    for(int i = 0 ; i < n ; i++){
        if(s[i] == '0') countzero++;
        if(s[i] == '1') countone++;
    }
    if(countzero > countone) return true;

    for(int i = 1 ; i<n ; i++){
        if(s[i] != s[i - 1]) countn++;
    }
 

    if(countn > 0){
        return true;
    }

    return false;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        if(solve()){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}