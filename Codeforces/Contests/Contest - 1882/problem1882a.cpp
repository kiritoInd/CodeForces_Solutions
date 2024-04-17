#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int ll;

using namespace std;

int solve() {
    int n;
    cin>>n;
    vector<int>a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ans;
    int init=1;
        
    for(int i=0;i<n;i++)
    {
        if(init==a[i])
            init++;
        ans=init;
        init++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cout << solve() <<endl;
    }
    return 0;
}

