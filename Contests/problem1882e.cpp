#include <bits/stdc++.h>
using namespace std;

// Function to sort the array 'a' by performing swaps and record the operations
vector<int> swap_sort(vector<int>& a) {
    int n = a.size();
    vector<int> ans; // Vector to store swap operations

    for (int i = 0; i < n; i++) {
        if (a[i] == i + 1)
            continue;

        // Find the position of the element that should be at index 'i'
        int j = i + 1;
        while (j < n && a[j] != i + 1)
            j++;

        // Swap elements to bring the correct element to its position
        swap(a[i], a[j]);

        // Record the swap operations
        ans.push_back(i + 1);   // Position of the first swapped element
        ans.push_back(j - i);   // Number of elements between the swapped elements
        ans.push_back(n - j);   // Number of elements after the second swapped element
    }
    return ans;
}

// Main function to solve the problem
void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);

    // Read the input sequences
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++)
        cin >> b[j];

    // Sort the sequences and record swap operations
    vector<int> opa = swap_sort(a);
    vector<int> opb = swap_sort(b);

    // Ensure that the number of swap operations in both sequences is consistent
    if (opa.size() % 2 != opb.size() % 2) {
        if (n % 2 == 0 && m % 2 == 0) {
            cout << -1 << endl;
            return;
        }
        if (n & 1) {
            for (int i = 0; i < n; i++)
                opa.push_back(1);
        } else {
            for (int i = 0; i < m; i++)
                opb.push_back(1);
        }
    }

    // Make both sequences have the same number of swap operations
    while (opa.size() < opb.size()) {
        opa.push_back(1);
        opa.push_back(n);
    }
    while (opb.size() < opa.size()) {
        opb.push_back(1);
        opb.push_back(m);
    }

    // Output the number of swap operations and the swap details
    cout << opa.size() << endl;
    for (int i = 0; i < opa.size(); i++)
        cout << opa[i] << " " << opb[i] << endl;
}

int main() {
    solve();
}
