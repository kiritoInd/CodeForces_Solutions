#include <iostream>
#include <string>
#include <vector>

using namespace std;
// 7 2
// taagaak
bool solve(string s, int k) {
    int n = s.size();
    vector<int> freq(26, 0);

    for (char ch : s) {
        freq[ch - 'a']++;
    }
    int evenCount = 0;
    int oddCount = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            oddCount++;
        }
        else if(freq[i] != 0 && freq[i] % 2 == 0) evenCount++;
    }
    if(oddCount - 1 == k) return true;
    if (oddCount  > k ) {
        return false;
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        if (s.size()== 1 ||  solve(s, k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
