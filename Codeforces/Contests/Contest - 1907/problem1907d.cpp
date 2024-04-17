#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
typedef long long int ll;

using namespace std;

bool check(vector<pair<int, int>> &seg , int mid){
    int l = 0 , r = 0;
    for(auto &x : seg){
        l = max(x.first , l - mid);
        r = min(x.second , r + mid);
        if(r < l){
            return false;
        }
    }
    return true;

}
int solve() {
    int n;
    cin>>n;
    vector<pair<int, int>> seg(n);
    for(int i = 0 ; i < n; i++){
        cin>>seg[i].first>>seg[i].second;
    }
    int result = -1;

    int left = seg[0].first;
    int right = 1e9;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(check(seg , mid)){
            result =  mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
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