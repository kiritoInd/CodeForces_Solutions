#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
typedef long long int ll;

using namespace std;
 
using namespace std;
int main()
{
    int t;cin >> t;
    while(t--){
        int n,s,e,a,b;cin >> n >> s >> e;
        int A=s;
        for(int i=1;i<n ;i++)
        {
            cin>>a>>b;
            if(a>=s&&b>=e)A=-1;
        }
        cout<<A<<endl;
    }
}