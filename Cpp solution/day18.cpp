#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <unordered_set>



int largestRectangleArea(std::vector<int> heights)
{
    int best_area = 0;
    std::stack<int> indices;   // indices, heights increasing bottom to top
    heights.push_back(0);      // sentinel: forces every bar to pop

    for (int i = 0; i < (int)heights.size(); i++)   // < not <=
    {
        while (!indices.empty() && heights[indices.top()] > heights[i])
        {
            int j = indices.top();
            indices.pop();

            int L = indices.empty() ? -1 : indices.top();
            best_area = std::max(best_area, heights[j] * (i - L - 1));
        }
        indices.push(i);
    }
    return best_area;
}