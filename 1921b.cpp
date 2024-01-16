#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int ll;

using namespace std;

int solve() {
    int x;
    cin>>x;
    string s , d;
    cin>>s;
    cin>>d;
 
    int count = 0;
    int count2 = 0;
    int count3 = 0;
    for(int i = 0 ;i < x; i++){
        if(s[i] != d[i]) count++;
        if(d[i] == '1' && s[i] != '1') count2++;
        if(s[i] == '1' && d[i] != '1') count3++;
    }

    return count - min(count2 , count3);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cout<<solve()<<endl;
    }
}