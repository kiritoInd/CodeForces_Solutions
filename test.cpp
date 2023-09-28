#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solve() {
    int n;
    cin >> n;
    vector<int> task_mem(n);
    
    for(int i = 0; i<n;i++){
        cin>>task_mem[i];
    }

    cin >> n;
    vector<int> task_type(n);

    for(int i = 0; i<n;i++){
        cin>>task_type[i];
    }
    int maxmem;
    cin>>maxmem;
    vector<pair<int,int>> p(n);
    for(int i = 0 ; i<n;i++){
        p[i].first = task_type[i];
        p[i].second = task_mem[i];
    }
  
    sort(p.begin(),p.end());

    int ans = 0;
    int sum = 0;
    for(int i = 0; i < n;i++){
        sum = p[i].second;
        if(p[i].first == p[i-1].first){
            sum += p[i].second;
        }
        else{
            if(sum > p[i].second) ans++;
            ans += (sum/maxmem) + 1;
            sum = p[i].second;
        }

    }

    cout<<ans<<endl;

    return 0;


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    solve();
    return 0 ;
}
