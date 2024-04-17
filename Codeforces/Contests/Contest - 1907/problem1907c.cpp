#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int ll;

using namespace std;

int solve() {
    int n;
    string s;
    cin>>n;
    cin>>s;
    vector<int> count(26, 0);
    int maxc = 0;
    for(int i = 0 ; i < n; i++){
        count[s[i] - 'a']++;
        maxc = max(maxc , count[s[i] - 'a']);
    }
    int result = max(2*maxc - n, n%2);

    return result;
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