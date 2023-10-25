#include <iostream>
#include <vector>
using namespace std;

int findMaxMoves(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int maxMoves = 0;

    for (int i = 0; i < m; i++) {
        int row = i;
        int col = 0;
        int moves = 0;

        while (col < n - 1) {
            int currentValue = grid[row][col];
            int bestMove = -1;

            for (int j = row - 1; j <= row + 1; j++) {
                if (j >= 0 && j < m && grid[j][col + 1] > currentValue) {
                    if (bestMove == -1 || grid[j][col + 1] > grid[bestMove][col + 1]) {
                        bestMove = j;
                    }
                }
            }

            if (bestMove == -1) {
                break;
            }

            row = bestMove;
            col++;
            moves++;
        }

        maxMoves = max(maxMoves, moves);
    }
    cout<< maxMoves<< " ";
    return maxMoves;
}

int main() {
    vector<vector<int>> grid1 = {{2, 4, 3, 5}, {5, 4, 9, 3}, {3, 4, 2, 11}, {10, 9, 13, 15}};
    vector<vector<int>> grid2 = {{3, 2, 4}, {2, 1, 9}, {1, 1, 7}};
    
    vector<vector<int>> grid3 = {{2, 7, 25, 10}, {1, 5, 18, 0}, {15, 8, 9, 3}, {11, 45, 33, 50}};

    findMaxMoves(grid1);
    findMaxMoves(grid2);
    findMaxMoves(grid3);

    return 0;
}
