#include <bits/stdc++.h>
using namespace std;

// Hard: Rat Ans in "DRUL" format
void solveRatMaze(int row, int col, int n, vector<vector<int>> &mat, vector<string> &Ans, string S, vector<vector<int>> &visited) {
    if (row == n-1 && col == n-1) {
        Ans.push_back(S);
        return;
    }
    // Down:
    if (row+1 < n && !visited[row+1][col] && mat[row+1][col] == 1) {
        visited[row][col] = 1;
        solveRatMaze(row+1, col, n, mat, Ans, S + 'D', visited);
        visited[row][col] = 0;
    }
    // Left:
    if (col-1 >= 0 && !visited[row][col-1] && mat[row][col-1] == 1) {
        visited[row][col] = 1;
        solveRatMaze(row, col-1, n, mat, Ans, S + 'L', visited);
        visited[row][col] = 0;
    }
    // Right:
    if (col+1 <= n && !visited[row][col+1] && mat[row][col+1] == 1) {
        visited[row][col] = 1;
        solveRatMaze(row, col+1, n, mat, Ans, S + 'R', visited);
        visited[row][col] = 0;
    }
    // Up:
    if (row-1 >= 0 && !visited[row-1][col] && mat[row-1][col] == 1) {
        visited[row][col] = 1;
        solveRatMaze(row-1, col, n, mat, Ans, S + 'U', visited);
        visited[row][col] = 0;
    }
}

vector<string> ratMaze(vector<vector<int>> &mat) {
    vector<string> Ans;
    string S = "";
    int n = mat.size();
    vector<vector<int>> visited(n, vector<int> (n, 0));
    if (mat[0][0] == 1) {       // If starting point is not 0
        solveRatMaze(0, 0, n, mat, Ans, S, visited);
    }
    return Ans;
}

// Time -> T(2^(N^2))
// Space -> T(N^2)


// Hard: Rat Ans in Matrix format
void ratInMazeHelper(vector<vector<int>> &maze,int i,int j,vector<int> &ds,vector<vector<int>> &ans){
  int n = maze.size();
  if(i < 0 || j < 0 || i >= n || j >= n)return ;
  if(i == n-1 && j == n-1){
    ds[n*n-1] = 1;
    ans.push_back(ds);
    return ;
  }
  if(maze[i][j] == 0 || maze[i][j] == 2)return ;

  maze[i][j] = 2;
  ds[(n*i)+j] = 1;

  ratInMazeHelper(maze, i+1, j, ds, ans); 
  ratInMazeHelper(maze, i-1, j, ds, ans); 
  ratInMazeHelper(maze, i, j-1, ds, ans); 
  ratInMazeHelper(maze, i, j+1, ds, ans); 

  ds[(n*i)+j] = 0;
  maze[i][j] = 1;
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  vector<vector<int> > ans;
  vector<int> ds(n*n, 0);
  ratInMazeHelper(maze, 0, 0, ds, ans);
  return ans;
}

// Time -> T(2^(N^2))
// Space -> T(N^2)

// GFG:
class Solution{
    public:
    
    void solve(vector<vector<int>>&m,int n,string curr,vector<string>&ans,int row,int col,vector<vector<bool>>&vis){
        if(row==n-1 && col==n-1){
            ans.push_back(curr);
            return;
        }
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        char dir[4]={'U','R','D','L'};
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0 && nc>=0 && nr<n && nc<n && !vis[nr][nc] && m[nr][nc]==1){
                vis[nr][nc]=1;
                solve(m,n,curr+dir[i],ans,nr,nc,vis);
                vis[nr][nc]=0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {//usinf dfs 
        vector<string>ans;
        string curr="";
        if(m[0][0]==0){
            return ans;
        }
        vector<vector<bool>>vis(n,vector<bool>(n,0));
        vis[0][0]=1;
        solve(m,n,curr,ans,0,0,vis);
        return ans;
    }
};

// Time -> O(2^(N^2))
// Space -> O(N^2)
