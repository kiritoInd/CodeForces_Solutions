#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void solve(){
    long long n;
    cin>>n;
    vector<long long> result(n);
    for(int i = 0; i <n; i++) cin>>result[i];
    int minDiff = INT_MAX;
    for(int i = 0; i<n-1; i++)
    {
        int diff = result[i+1] - result[i];
        if(diff < 0) {
            cout<<0<<endl;
            return;
        }
        if(diff < minDiff){
            minDiff = min(minDiff,diff);
        }
    }
    cout<<minDiff/2+1<<endl;
}
int main(){
    ios_base::sync_with_stdio(false); //diables syncronization b/w cin cout
    cin.tie(NULL); //unties the cin stream from the cout stream improves performance
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
}

// std::ios_base::sync_with_stdio(false);: This line disables the synchronization between
// C++ streams (e.g., cin, cout, cerr) and C-style I/O functions (e.g., scanf, printf). 
//Disabling this synchronization can improve the performance of input and output operations
// when mixing C++ streams with C-style I/O.

// std::cin.tie(nullptr);: This line unties the cin stream from the cout stream.
// When streams are tied, it means that an operation on one stream flushes the other. 
//By setting cin's tie to nullptr, you prevent this automatic flushing,
// which can also improve performance in some cases.