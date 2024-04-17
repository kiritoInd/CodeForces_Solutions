#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        int fnd=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==k)
            {
                fnd=1;
                cout<<"YES"<<"\n";
                break;
            }
        }
        if(fnd==0)
            cout<<"NO"<<"\n";
    }
    return 0;
}