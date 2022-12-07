//Problem
/******************************************************************************
 
1219. Path with Maximum Gold
Medium

In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.
 

Example 1:

Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.
Example 2:

Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 15
0 <= grid[i][j] <= 100
There are at most 25 cells containing gold.

*******************************************************************************/
//Code
class Solution {
public:
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int dfs(vector<vector<int>>& grid, int i, int j){
        int ans = 0;
        int org = grid[i][j];
        grid[i][j] = 0;
        
        for(auto& direction : directions){
            int x = direction[0], y = direction[1];
            if(i + x >= 0 && j + y >= 0 && i + x < grid.size() && j + y < grid[0].size() && grid[i+x][j+y] != 0){
                ans = max(ans, grid[i+x][j+y] + dfs(grid, i + x, j + y));
            }
        }
        grid[i][j] = org;
        return ans;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]){
                    ans = max(ans, grid[i][j] + dfs(grid, i, j));
                }
            }
        }
        
        return ans;
    }
};


//Explanation

/************************************

 The code is a function that takes in two vectors of integers and returns the maximum value found.
 The code starts by declaring an int variable called ans, which is initialized to 0.
 Then it iterates over each element in the grid vector, starting with i and ending with j.
 The for loop then iterates through each element in the grid[i][j] vector, where i + x >= 0 && j + y >= 0 && i + x < grid.size() && j + y < grid[0].size() && grid[i+x][j+y] != 0) { int max = dfs(grid, i + x, j + y); ans = max; }
 The code will return the maximum value of gold in a grid.
 The code above takes in a vector of vectors and iterates through each row to find the maximum value for each row.

***************************************/