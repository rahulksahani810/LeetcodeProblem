class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Vector to store the distance results, initialized to a large value
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));

        // Queue for BFS
        queue<pair<int, int>> q;

        // Initialize BFS with all 0s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dis[i][j] = 0; // Distance to itself is 0
                }
            }
        }

        // Direction vectors for moving up, down, left, and right
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // Perform BFS
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Explore all 4 directions
            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                // Check if within bounds and if a shorter distance is found
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    if (dis[nrow][ncol] > dis[row][col] + 1) {
                        dis[nrow][ncol] = dis[row][col] + 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }

        return dis;
    }
};
