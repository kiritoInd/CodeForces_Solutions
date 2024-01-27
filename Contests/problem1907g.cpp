#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue> 
typedef long long int ll;

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> arr(n);
        unordered_map<ll, vector<ll>> graph;
        vector<ll> indegree(n, 0);
        vector<bool> visited(n, false);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr[i]--;
            graph[i].push_back(arr[i]);
            indegree[arr[i]]++;
        }
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

        for (ll i = 0; i < n; i++)
        {
            pq.push({indegree[i], i});
        }
        ll ans = 0;

        vector<ll> an;
        while (!pq.empty())
        {
            pair<ll, ll> pr = pq.top();
            pq.pop();
            if (pr.first != 0 || visited[pr.second])
            {
                continue;
            }
            ll v = pr.second;

            visited[v] = true;
            bool check = false;
            if (s[pr.second] == '1')
            {
                check = true;
                s[pr.second] = '0';
                an.push_back(pr.second+1);
                ans++;
            }
            // cout<<v<<endl;

            for (auto u : graph[v])
            {
                if (check)
                {
                    if (s[u] == '1')
                    {
                        s[u] = '0';
                    }
                    else
                    {
                        s[u] = '1';
                    }
                }
                indegree[u]--;
                pq.push({indegree[u], u});
            }
        }

        // bool check=false;
        // cout << s << endl;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '1' && !visited[i])
            {
                queue<ll> q;
                q.push(i);
                vector<ll> vec;
                ll cnt=0;
                while (!q.empty())
                {
                    ll v = q.front();
                    q.pop();
                    if(!visited[v]){
                        if(s[v]=='1'){
                            cnt++;
                        }
                        
                        vec.push_back(v);
                    }

                    visited[v] = true;

                    
                    // cout<<s<<endl;
                    for (auto u : graph[v])
                    {
                        
                        if (!visited[u])
                        {
                            q.push(u);
                        }
                    }
                    // cout << s << endl;
                }

                if(cnt%2==1){
                    ans=-1;
                    break;
                }

                cnt=0;

                ll m=vec.size();
                vector<ll> v[2];
                for(ll i=0;i<m;i++){
                    if(s[vec[i]]=='1'){
                        cnt++;
                        bool check=false;
                        for(ll j=0;j<m;j++){
                            if(s[vec[(i+j)%m]]=='1'){
                                if(check){
                                    check=false;

                                }else{
                                    check=true;
                                    v[cnt-1].push_back(vec[(i+j)%m]);
                                }
                            }else{
                                if(check){                                    
                                    v[cnt-1].push_back(vec[(i+j)%m]);
                                }

                            }

                        }

                    }

                    if(cnt==2){
                        break;
                    }
                }

                ll a=0,b=1;

                if(v[a].size()>v[b].size()){
                    swap(a,b);
                }

                for(auto yy:v[a]){
                    ans++;
                    an.push_back(yy+1);
                }

                for(ll i=0;i<m;i++){
                    s[vec[i]]='0';
                }


                


            }
        }

        if(ans==-1){
            cout<<ans<<endl;
            continue;
        }

        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                ans = -1;
            }
        }

        

        // cout << s << endl;

        cout << ans << endl;

        if(ans==-1){
            continue;
        }

        for(auto i:an){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}