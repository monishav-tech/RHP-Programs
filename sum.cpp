#include <iostream>
#include <vector>
using namespace std;

int sumAdjacentCells(vector<vector<int>>& grid, int row, int col) {
    int n = grid.size();
    int m = grid[0].size();

    vector<pair<int, int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1},  {1, 0},  {1, 1}
    };

    int sum = 0;

    for (auto& d : directions) {
        int newRow = row + d.first;
        int newCol = col + d.second;

        if (newRow >= 0 && newRow < n &&
            newCol >= 0 && newCol < m) {
            sum += grid[newRow][newCol];
        }
    }

    return sum;
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << sumAdjacentCells(grid, 1, 1);
    return 0;
}
