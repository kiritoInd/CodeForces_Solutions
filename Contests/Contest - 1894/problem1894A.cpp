#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int ll;

using namespace std;

int solve() {
     int n;
    cin >> n;
    string s;
    cin >> s;

    int cA;
    int cB;
    for(int i = 0 ; i < s.size(); i++){
        if(s[i] == 'A') cA++;
        else cB++;
    }
    if(cA == cB) 
    {
        cout << "?" <<endl;
        return 0;
    }
    
    cout<<s.back()<<endl;
    return 0;
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