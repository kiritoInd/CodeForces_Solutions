#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

typedef long long int ll;

using namespace std;

int maxSubArraySum(vector<int> a)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < a.size(); i++) {
        if(a[i]&1 && a[i-1]&1){
            max_ending_here = 0;
        }
        if(a[i]%2==0 && a[i-1]%2==0){
            max_ending_here = 0;
        }
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int solve() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    return maxSubArraySum(nums);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        cout << solve() << endl;
    }

    return 0;
}
