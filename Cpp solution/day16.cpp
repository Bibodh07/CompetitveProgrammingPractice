#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <limits>


std::vector<int> nextWarmerDay(const std::vector<int>& arr)
{
    std::vector<int> retVal(arr.size(), 0);
    std::stack<int> indices;

    for (size_t i = 0; i < arr.size(); i++)
    {
        while (!indices.empty() && arr[indices.top()] < arr[i])
        {
            int j = indices.top();
            indices.pop();
            retVal[j] = i - j;
        }
        indices.push(i);
    }
    return retVal;
}


int calc_sum(int start, int end, std::vector<int> arr)
{
    int diff = end - start + 1; 
    int sum = 0;
    for(int i=0; i < diff; i++)
    {
         sum += arr[start+i];
    }

    return sum;
}

int findMinSum(int windowSize, const std::vector<int>& planks, int total)
{
    int l = 0;
    int currSum = calc_sum(0, windowSize - 1, planks);  // first window
    int minSum = currSum;
    int bestStart = 0;                                  // first window starts at 0

    for (int r = windowSize; r < total; r++)
    {
        currSum += planks[r];
        currSum -= planks[l];
        l++;

        if (currSum < minSum)
        {
            minSum = currSum;
            bestStart = l;
        }
    }
    return bestStart + 1;  // 1-indexed
}