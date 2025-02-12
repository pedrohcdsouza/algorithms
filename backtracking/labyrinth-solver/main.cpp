#include <iostream>
#include <vector>

using namespace std;

bool labyrinth_bt(int row, int column, int r, int c, vector<vector<int>>& labyrinth){
    
    // BASE CASE //
    if(r<0 || c<0 || r>=row || c>=column || labyrinth[r][c] == 1)
        return false;
    
    if(r == row - 1 && c == column - 1) 
        return true;
    
    labyrinth[r][c] = 2;

    // RECURSIVE CALL // 
    bool route =    labyrinth_bt(row, column, r+1, c, labyrinth) ||   
                    labyrinth_bt(row, column, r, c+1, labyrinth) ||   
                    labyrinth_bt(row, column, r-1, c, labyrinth);     

    
    return route;
}

int main(){
    int a, b;
    cin >> a >> b;
    vector<vector<int>> c(a, vector<int>(b, 0));

    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            cin >> c[i][j]; 
        }
    }

    if(labyrinth_bt(a, b, 0, 0, c))
        cout << true;
    else
        cout << false;

    return 0;
}
