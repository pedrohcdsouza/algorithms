#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int shortest_path = INT_MAX; 

bool is_valid(int r, int c, int row, int col, vector<vector<int>>& labyrinth) {
    return r >= 0 && c >= 0 && r < row && c < col && labyrinth[r][c] == 0;
}

void labyrinth_bt(int row, int col, int r, int c, vector<vector<int>>& labyrinth, int dist) {

    if (!is_valid(r, c, row, col, labyrinth)) {
        return;
    }

    if (r == row - 1 && c == col - 1) {
        shortest_path = min(shortest_path, dist); 
        return;
    }

    
    labyrinth[r][c] = 2;

    
    labyrinth_bt(row, col, r + 1, c, labyrinth, dist + 1); 
    labyrinth_bt(row, col, r, c + 1, labyrinth, dist + 1); 
    labyrinth_bt(row, col, r - 1, c, labyrinth, dist + 1); 
    labyrinth_bt(row, col, r, c - 1, labyrinth, dist + 1); 

    labyrinth[r][c] = 0;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    
    vector<vector<int>> labyrinth(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> labyrinth[i][j];
        }
    }

    
    shortest_path = INT_MAX;

    labyrinth_bt(rows, cols, 0, 0, labyrinth, 1);

    if (shortest_path != INT_MAX) {
        cout << shortest_path;
    } else {
        cout << -1;
    }

    return 0;
}
