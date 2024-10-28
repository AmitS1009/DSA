// without DP : TLE : 

class Solution {
public:
    int n, m;
    int solve(int i, int j, vector<vector<int>> &mat){

        if(i >= n || j >= m) return 0;
        
        if(mat[i][j] == 0) return 0;

        int right = solve(i + 1, j, mat);
        int down = solve(i, j + 1, mat);
        int diag = solve(i + 1, j + 1, mat);

        return 1 + min({right, down, diag}); 

    }

    int countSquares(vector<vector<int>>& mat) {

        n = mat.size();  // Corrected here by using class member variables
        m = mat[0].size();

        int ans = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1){
                    ans += solve(i, j, mat);
                }
            }
        }
        return ans;
    }
};


// with DP : 

class Solution {
public:
    int n, m;
    
    int solve(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if (i >= n || j >= m) return 0;
        if (mat[i][j] == 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];
        
        int right = solve(i + 1, j, mat, dp);
        int down = solve(i, j + 1, mat, dp);
        int diag = solve(i + 1, j + 1, mat, dp);
        
        dp[i][j] = 1 + min({right, down, diag});
        
        return dp[i][j];
    }

    int countSquares(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();

        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    ans += solve(i, j, mat, dp);
                }
            }
        }
        
        return ans;
    }
};

