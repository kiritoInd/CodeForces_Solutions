#include <iostream>
#include <algorithm>
#include <vector>

typedef long long int ll;

using namespace std;

int solve() {
    int x;
    cin >> x;
    vector<int> v(4);
    for(int i  = 3; i >= 0 ; i--){
        int val = x%10;
        if(val == 0) v[i] = 10;
        else v[i] = val;
        x /= 10;
    }
    int sum = 4;
    if(v[0] != 1 && v[0] != 0) sum += v[0] - 1;
    if(v[0] == 0) sum += 10;

    for(int i = 1 ; i < 4; i++){
        sum += abs(v[i] - v[i - 1]);
    }
    return sum;
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

//    if(v[i] == 0 && v[i - 1] != 0 ) {
//             int y = 10 - v[i];
//             sum += y;
//         }
//         else if(v[i - 1] == 0 && v[i] != 0){
//             int y = 10 - v[i];
//             sum += y;
//         }
//         else