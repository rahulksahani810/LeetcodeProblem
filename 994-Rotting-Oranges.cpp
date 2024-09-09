class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0)); // Properly initialize the visited array
        queue<pair<pair<int, int>, int>> q; // Queue to store the position and time
        int cntFresh = 0; // Count of fresh oranges

        // Initialize the queue with all initially rotten oranges and count fresh oranges
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2; // Mark rotten oranges as visited
                } else {
                    vis[i][j] = 0; // Mark other cells as unvisited
                }
                if (grid[i][j] == 1) cntFresh++; // Count fresh oranges
            }
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int tm = 0;
        int cnt = 0;

        // BFS to rot adjacent fresh oranges
        while (!q.empty()) {
            int newrow = q.front().first.first;
            int newcol = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();

            // Check all four directions
            for (int i = 0; i < 4; i++) {
                int r = newrow + delrow[i];
                int c = newcol + delcol[i];
                // Check boundaries and conditions for fresh orange
                if (r >= 0 && r < row && c >= 0 && c < col && vis[r][c] == 0 && grid[r][c] == 1) {
                    q.push({{r, c}, t + 1});
                    vis[r][c] = 2; // Mark the fresh orange as visited (rotten now)
                    cnt++;
                }
            }
        }

        // If not all fresh oranges are rotten, return -1
        if (cnt != cntFresh) return -1;

        return tm;
    }
};