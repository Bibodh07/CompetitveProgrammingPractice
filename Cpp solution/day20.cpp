#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <unordered_set>
#include <iostream>

int MaximumSubarray(std::vector<int> arr)
{
    std::vector<int> dp(arr.size(), 0);

    dp[0] = arr[0];
    
    for(int i = 1; i <(int) arr.size(); i++)
    {
        dp[i] = std::max(dp[i-1] + arr[i], arr[i]);

    }

    auto ans_it = std::max_element(dp.begin(), dp.end());
    int ans = *ans_it;

    return ans;
    
}


int wrongSubtraction(int n, int k)
{
    for(int i = 0; i<k; i++)
    {
        int r = n % 10; 

        if(r != 0)
        {
            n--;
        }
        else{
             
              n /= 10;
        }
    }
    return n;
}



void dfs (std::vector<std::vector<int>> &grid, int r, int c, int new_color, int original_color)
{

    if(grid.size() == 0)
    {
        return;
    }

    int row_size = (int)grid.size();
    int column_size = (int)grid[0].size();

    if(r>=row_size || c>=column_size || r<0 || c<0 || grid[r][c] != original_color)
    {
       return;
    }

    grid[r][c] = new_color;

    dfs(grid, r+1, c, new_color, original_color);
    dfs(grid, r-1, c, new_color, original_color);
    dfs(grid, r, c+1, new_color, original_color);
    dfs(grid, r, c-1, new_color, original_color);

    return; 
}

void bfs(std::vector<std::vector<int>> &grid, int r, int c, int new_color, int original_color)
{

    std::queue<std::pair<int,int>> q;
    grid[r][c] = new_color;
    

    std::pair p = {r,c};
    q.push(p);

    while(!q.empty())
    {
        std::pair p2 = q.front();
        q.pop();

        int row_size = (int)grid.size();
        int column_size = (int)grid[0].size();

        int r1 = p2.first;
        int c1 = p2.second;

        int dr[4] = {1, -1, 0 , 0};
        int dc[4] = {0, 0, 1, -1};

        for(int i =0; i< 4; i++)
        {
            int nr = r1 + dr[i];
            int nc = c1 + dc[i];

            if(nr>=row_size || nc>=column_size || nr<0 || nc<0 || grid[nr][nc] != original_color)
            {
                continue;
            }
            else{
                q.push({nr, nc});
                grid[nr][nc] = new_color;
            }


        }


        

    }

}

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color)
{

    int original_color = image[sr][sc];
    if (original_color == color)
        return image;
    dfs(image, sr, sc, color, original_color);

    return image;
}


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::cout << wrongSubtraction(n, k) << "\n";
    return 0;


}