class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {

                if (i * j == 0 || i == n - 1 || j == m - 1)
                {
                    if (grid[i][j] == 1)
                    {
                        grid[i][j] = 0;
                        q.push({i, j});
                    }
                }
            }
        }

        while (!q.empty())
        {

            pair<int, int> x = q.front();
            q.pop();
            int nx[4] = {1, -1, 0, 0};
            int ny[4] = {0, 0, 1, -1};

            for (int i = 0; i < 4; i++)
            {
                int new_x = nx[i] + x.first;
                int new_y = ny[i] + x.second;

                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && grid[new_x][new_y] == 1)
                {
                    grid[new_x][new_y] = 0;
                    q.push({new_x, new_y});
                }
            }
        }

        int count = 0;

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {

                if (grid[i][j] == 1)
                {
                    count++;
                }
            }
        }

        return count;
    }
};