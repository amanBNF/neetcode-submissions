class Solution {
   public:
    int m, n;
    int drow[4] = {0, 1, 0, -1};
    int dcol[4] = {1, 0, -1, 0};

    int solve(int r, int c, vector<vector<int>>& arr) {
        queue<pair<int, int>> q;
        q.push({r, c});
        vector<vector<int>> vis(m, vector<int>(n, 0));

        vis[r][c] = 1;
        int stp = 0;

        while (!q.empty()) {
            int len = q.size();

            for (int i = 0; i < len; i++) {
                auto [row, col] = q.front();
                q.pop();

                if (arr[row][col] == 0) return stp;

                for (int i = 0; i < 4; i++) {
                    int nrow = drow[i] + row;
                    int ncol = dcol[i] + col;

                    if (nrow >= 0 and nrow < m and ncol >= 0 and ncol < n and
                        arr[nrow][ncol] != -1 and vis[nrow][ncol] == 0) {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
            stp++;
        }

        return INT_MAX;
    }

    void islandsAndTreasure(vector<vector<int>>& arr) {
        m = arr.size();
        n = arr[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == INT_MAX) {
                    arr[i][j] = solve(i, j, arr);
                }
            }
        }
    }
};
