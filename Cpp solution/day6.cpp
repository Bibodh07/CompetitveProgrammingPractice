#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>



struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) :
     val(x), left(nullptr), right(nullptr) 
     {}

     public:
     void preOrder(TreeNode *root){

        if (!root)
        {
            return;
        }

        std::cout<< root->val << " ";

        preOrder(root->left);
        preOrder(root->right);


     }

     void bfs(TreeNode *root)
     {

        std::queue<TreeNode*> Node;
        Node.push(root);
        std::vector<int> result;

        while (!(Node.empty()))
        {

             TreeNode *curr = Node.front();

             result.push_back(curr->val);

             if (curr->left){
                Node.push(curr->left);
             }

             if (curr -> right)
             {
                Node.push(curr->right);
             }

             Node.pop();



        }
     }


     void levelOrder(TreeNode *root)
{
    if (!root)
        return;

    std::queue<TreeNode*> Node;
    Node.push(root);

    std::vector<std::vector<int>> result;

    while (!Node.empty())
    {
        std::vector<int> level;
        int levelSize = Node.size();

        for (int i = 0; i < levelSize; i++)
        {
            TreeNode* curr = Node.front();
            Node.pop();

            level.push_back(curr->val);

            if (curr->left)
                Node.push(curr->left);

            if (curr->right)
                Node.push(curr->right);
        }

        result.push_back(level);
        }
    }

    int LowestCommonAncestorBST(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int result = root->val;

        if(result >p->val && result>q->val)
        {
            result = LowestCommonAncestorBST(root->left, p, q);
        }

        if(result < p->val && result < q->val)
        {
             result = LowestCommonAncestorBST(root->right, p, q);
        }

        return result;
    }

    TreeNode* LowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(root == nullptr || root == p || root == q)
        {
            return root;
        }

        TreeNode* leftTree = LowestCommonAncestor(root->left, p, q);
        TreeNode* rightTree = LowestCommonAncestor(root->right, p, q);

        if (leftTree && rightTree)
        {
            return root;
        }

        if(leftTree){
            return leftTree;
        }

        return rightTree;
    }
};


std::vector<std::vector<int>> mergeInterval(std::vector<std::vector<int>> arr)
{
    std::vector<std::vector<int>> result;

    std::sort(arr.begin(), arr.end());

    std::vector<int> curr = arr[0];

    for (size_t i = 1; i < arr.size(); i++)
    {
        if (arr[i][0] <= curr[1])
        {
            curr[1] = std::max(curr[1], arr[i][1]);
        }
        else
        {
            result.push_back(curr);
            curr = arr[i];
        }
    }

    result.push_back(curr);

    return result;
}

std::vector<std::vector<int>> insertInterval(
    std::vector<std::vector<int>> arr,
    std::vector<int> nums)
{
    std::vector<std::vector<int>> result;
    

    bool inserted = false;

    for (size_t i = 0; i < arr.size(); i++)
    {
        // Current interval is completely before nums
        if (arr[i][1] < nums[0])
        {
            result.push_back(arr[i]);
        }

        // Current interval is completely after nums
        else if (arr[i][0] > nums[1])
        {
            if (!inserted)
            {
                result.push_back(nums);
                inserted = true;
            }

            result.push_back(arr[i]);
        }

        // Overlap → merge
        else
        {
            nums[0] = std::min(nums[0], arr[i][0]);
            nums[1] = std::max(nums[1], arr[i][1]);
        }
    }

    // If nums was never inserted
    if (!inserted)
    {
        result.push_back(nums);
    }

    return result;
}


int meetingRoomsII(std::vector<int> start, std::vector<int> end)
{
    int roomInUse = 0;
    int endPointer = 0;
    int maxRooms = 0;
    std::sort(start.begin(), start.end());
    std::sort(end.begin(), end.end());
    
    for(size_t i= 0; i< start.size(); i++)
    {

        if(start[i] < end[endPointer])
        {
            roomInUse++;
        }
        else{

            endPointer+=1;
        }

        maxRooms = std::max(maxRooms, roomInUse);

    }

    return maxRooms;
}


int nonOverlappingIntervals(std::vector<std::vector<int>> nums)
{
    int removals = 0;


    std::sort(nums.begin(), nums.end(),
        [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
    
    std::vector<int> current = nums[0];


    for(size_t i = 1; i < nums.size(); i++)
    {
        if(nums[i][0] < current[1])
        { 
            removals++;
        }
        else{
            current = nums[i];
        }
    }
    return removals;
}




int main()
{
    return 0;
}