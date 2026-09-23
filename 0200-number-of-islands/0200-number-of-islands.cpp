class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visted(n, vector<bool>(m, false));

        int cnt = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                queue<pair<int, int>> q;
                if (grid[r][c] == '1' && !visted[r][c]) {

                    visted[r][c] = true;
                    cnt++;
                    q.push({r, c});
                }
                while (!q.empty()) {
                    auto [cr, cc] = q.front();
                    q.pop();

                    for (int i = 0; i < 4; i++) {
                        int nr = cr + dr[i];
                        int nc = cc + dc[i];

                        if ((nr >= 0 && nr < n) && (nc >= 0 && nc < m) &&
                            grid[nr][nc] == '1' && !visted[nr][nc]) {
                            visted[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
        return cnt;
    }
};