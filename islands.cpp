#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (row < 0 || col < 0 || row >= n || col >= m)
            return;

        if (grid[row][col] != '1')
            return;

        grid[row][col] = '0';

        dfs(row + 1, col, grid);
        dfs(row - 1, col, grid);
        dfs(row, col + 1, grid);
        dfs(row, col - 1, grid);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;

        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {

                if (grid[row][col] == '1') {
                    islands++;
                    dfs(row, col, grid);
                }
            }
        }

        return islands;
    }
};
