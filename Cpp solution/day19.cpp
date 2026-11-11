#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
  
    if(root == NULL)
    {
        return NULL;
    }

    if(root == p || root == q)
    {
        return root;
    }

  

    TreeNode* val_Inleft = lowestCommonAncestor(root->left, p, q);
    TreeNode* val_Inright = lowestCommonAncestor(root->right, p, q);

    if(val_Inleft && val_Inright)
    {
        return root;
    }
    else if (val_Inleft && !val_Inright)
    {
        return val_Inleft;
    }
    else if (val_Inright && !val_Inleft)
    {
        return val_Inright;
    }
    else{
        return NULL;
    }
    
    
}



int decodeWays(std::string s)
{
    int n = s.length();
    std::vector<int> dp(n + 1, 0); 
    dp[0] = 1;
    dp[1] = (s[0] != '0') ? 1 : 0; 

    for (int i = 2; i <= s.length(); i++)
    {

         int ones = s[i-1] - '0';
         int tens = s[i-2] - '0';
         int twoDigits = tens * 10 + ones; 

         if(ones != 0)
         {
            dp[i] += dp[i-1];
         }

         if(twoDigits >= 10 && twoDigits <= 26)
         {
            dp[i] += dp[i-2];
         }
   
    }
    return dp[n];
}



int longestContinuousAscending(const std::vector<int>& nums)
{
    int best_length = 0;
    int l = 0;
    for (int r = 0; r < (int)nums.size(); r++)
    {
        if (r > 0 && nums[r] <= nums[r-1])
            l = r;
        best_length = std::max(best_length, r - l + 1);
    }
    return best_length;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    std::cout << longestContinuousAscending(arr) << "\n";
    return 0;
}



