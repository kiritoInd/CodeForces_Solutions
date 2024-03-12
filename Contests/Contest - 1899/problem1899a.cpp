#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int ll;

using namespace std;

string solve() {
    int n;
    cin>>n;
    if((n + 1)%3 == 0 || (n - 1)%3 == 0) return "First";

    return "Second";
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