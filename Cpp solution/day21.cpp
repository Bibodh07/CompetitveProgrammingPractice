#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <iostream>



std::vector<int> twoSum (std::vector<int> arr, int target)
{
    std::unordered_map<int, int> map;


    for(int i = 0; i < (int) arr.size(); i++)
    {
                            // nums = [2,7,11,15], target = 9   →  [0,1]    (2 + 7 = 9)
                                                  //2 : 1 
                                                  //  9 -2 in map? nah so we move on 
                                                  //7 : 2 
                                                  // 9-7 in map? yeah return [1, 0]

        if(map.count((target - arr[i])) > 0)
        {
            return {map[(target - arr[i])], i};
        }

        map[arr[i]] = i;      
    }

    return {-1, -1};
}



int longestStringVersion_dos(std::string s)
{
    int best_length = 0; 
    int l = 0; 
    std::unordered_set<char> cs;
    for(int r = 0; r < s.length(); r++)
    {
        
        while(cs.count(s[r]) > 0)          //pwwkew
                                           // s[r] is p, p isnt in the set 
                                           // cs = {p}
                                           // best length is 1 
                                           // s[r] = w, which isnt in cs 
                                           // cs ={p, w}
                                           // best_length = 2 
                                           // s[r] = w 
                                           // since w is in set, p gets removed then w gets removed 
                                           // cs = {}
                                           // l = 2 
                                           // then k is added, e is added and a 2 is added 
                                           // 5 - 3 + 1 = 3 
        {
            cs.erase(s[l]);
            l++;
        }

        cs.insert(s[r]);
        best_length = std::max(best_length, r-l+1);
    }

    return best_length;
}




void dfs(std::vector<std::vector<char>> &grid, int r, int c)
{
    int row_length = (int)grid.size();
    int column_length = (int)grid[0].size(); 

    if(r<0 || r>=row_length || c<0 || c>=column_length || grid[r][c] == '0')
    {
        return;
    }

    grid[r][c] = '0'; 

    dfs(grid, r+1, c);
    dfs(grid, r-1, c); 
    dfs(grid, r, c+1); 
    dfs(grid, r, c-1);
}

int coundIslands(std::vector<std::vector<char>> &grid)
{
    int count = 0;

    int row_length = (int)grid.size();
    int column_length = (int)grid[0].size(); 

    for(int i = 0; i < row_length; i++){
        for (int j = 0; j< column_length; j++){
            if(grid[i][j] == '1')
            {
                dfs(grid, i, j);
                count ++;
            }
            
        }
    }

    return count;
}

//6 / 2 2 1 3 4 1 → 3
// bestl = 0/ l = 0
// r=1, arr[r] = 2 is 2 less than 2 no best length is 1-0+1 = 2 
// r = 2 l = 2  2-2+1 = 1 
// 3,4,1,  4-2+1 = 3 


int MaxProfits(std::vector<int> &arr)

{

    if((int)arr.size() == 1)
    {
        return 1;
    }


    int best_length = 0;

    int l = 0;
    for(int r = 1; r < (int)arr.size(); r++)
    {
        if(arr[r] < arr[r-1])
        {
            l = r;
        }

        best_length = std::max(best_length, r-l+1);
    }

    return best_length;
}



int majorityElements(std::vector<int> arr)
{

    std::unordered_map<int, int> map; 

    int n = (int)arr.size();
    int target = n/2;

    for(int  i=0; i<n; i++)
    {
        if(map[arr[i]] == target)
        {
            return arr[i];
        }

        map[arr[i]]++;
    }

    return -1;

}


int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin>>n;  //length

    std::vector<int> profits(n, 0);

    for(int i = 0; i < n; i++)
    {
        std::cin >> profits[i];
    }

    int streak = MaxProfits(profits);

    std::cout<<streak;


    return 0;

}