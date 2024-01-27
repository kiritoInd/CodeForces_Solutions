#include <bits/stdc++.h>

class Solution {
public:
    int t[201][201];

    int solve(int i, int j, std::vector<std::vector<int>>& grid) {
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return grid[i][j];
        }

        if (t[i][j] != -1) return t[i][j];

        int take_r = (j + i < grid[0].size() - 1) ? grid[i][j] + solve(i, j + i, grid) : INT_MAX;
        int take_d = (i + j< grid.size() - 1) ? grid[i][j] + solve(i + j, j, grid) : INT_MAX;

        return t[i][j] = std::min(take_r, take_d);
    }

    int minPathSum(std::vector<std::vector<int>>& grid) {
        if (grid.empty()) return 0;
        memset(t, -1, sizeof(t));
        return solve(0, 0, grid);
    }
};

int main() {
    Solution solution;

    // Example grid
    std::vector<std::vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int result = solution.minPathSum(grid);
    std::cout << "Minimum path sum: " << result << std::endl;

    return 0;
}
