class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int min = 0;

        int fresh = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                }
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        if (fresh == 0) {
            return 0;
        }
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!q.empty()) {
            int size = q.size();
            bool rotted = true;
            while (size--) {
                // process one orange

                auto [cr, cc] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nr = cr + dr[i];
                    int nc = cc + dc[i];
                    if ((nr >= 0 && nr < n) && (nc >= 0 && nc < m) &&
                        grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        rotted = false;
                        q.push({nr, nc});
                    }
                }
            }
            if (!rotted) {
                min++;
            }
        }

        if (fresh != 0) {
            return -1;
        }
        return min;
    }
};