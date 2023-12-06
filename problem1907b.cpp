#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
typedef long long int ll;

using namespace std;

void solve() {
    string s;
    cin>> s;
    vector<bool> vs(s.size() , 0);
    stack<ll> upper; 
    stack<ll> lower; 
    for(ll i = 0 ; i < s.size(); i++){
        if(s[i] == 'b'){
            if(!lower.empty()){
                vs[lower.top()] = true;
                lower.pop();
            }
            vs[i]=true;
        }else if(s[i] == 'B'){
            if(!upper.empty()){
                vs[upper.top()] =true;
                upper.pop();

            }
            vs[i] = true;
        }else if(isupper(s[i])){
            upper.push(i);
        }
        else lower.push(i);
    }

    for(int i = 0 ; i< s.size() ; i++){
        if(!vs[i]) cout<<s[i];
    }
    cout<<endl;
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}