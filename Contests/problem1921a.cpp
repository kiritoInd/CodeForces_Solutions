#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int ll;

using namespace std;

int solve() {
    int a , b , c , d ,e ,f , g , h;
    vector<pair<int,int>> sides(4);
    for(int i = 0 ; i< 4; i++){
        cin>>sides[i].first>>sides[i].second;
    }
    sort(sides.begin(),sides.end());
    int diff = abs(sides[1].second  - sides[0].second);
    
    return diff*diff;

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