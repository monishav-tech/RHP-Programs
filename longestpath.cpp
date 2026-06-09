#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    int dfs(int row, int col,
            vector<vector<int>>& matrix,
            vector<vector<int>>& dp) {

        if (dp[row][col] != -1)
            return dp[row][col];

        int bestPath = 1;

        for (auto& dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;

            if (newRow >= 0 && newRow < matrix.size() &&
                newCol >= 0 && newCol < matrix[0].size() &&
                matrix[newRow][newCol] > matrix[row][col]) {

                bestPath = max(
                    bestPath,
                    1 + dfs(newRow, newCol, matrix, dp)
                );
            }
        }

        return dp[row][col] = bestPath;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int answer = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                answer = max(
                    answer,
                    dfs(row, col, matrix, dp)
                );
            }
        }

        return answer;
    }
};
