//P157_2   维数为m*p的迷宫最长路径长度为m*p

//P157_3
#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 4;
const int COLS = 4;

void printPath(vector<pair<int, int>>& path)
{
    for (int i = 0; i < path.size(); ++i) 
        cout << "(" << path[i].first << ", " << path[i].second << ") ";
}

bool findPath(vector<vector<int>>& maze, int row, int col, vector<pair<int, int>>& path)
{
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || maze[row][col] == 1) 
        return false;

    path.push_back(make_pair(row, col));

    if (row == ROWS - 1 && col == COLS - 1) 
        return true; 

    if (findPath(maze, row, col + 1, path)) 
        return true;
    
    if (findPath(maze, row + 1, col, path)) 
        return true;
    
    path.pop_back();
    return false;
}

int main() {
    vector<vector<int>> maze = { {0, 1, 0, 0}, {0, 0, 0, 0}, {1, 1, 0, 1}, {0, 0, 0, 0} };

    vector<pair<int, int>> path;

    if (findPath(maze, 0, 0, path)) 
    {
        cout << "find the path：" << endl;
        printPath(path);
    }
    else 
        cout << "cannot find the path：" << endl;

    return 0;
}
//时间复杂度为：O(2^{m*p})