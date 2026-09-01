#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

std::vector<int> twoSum(std::vector<int> nums, int k)
{
    std::unordered_map<int, int> indexBook;

    for (int i = 0; i < nums.size(); i++)
    {
        int needed = k - nums[i];

        if (indexBook.count(needed))
        {
            return {indexBook[needed], i};
        }

        indexBook[nums[i]] = i;
    }

    return {};
}


bool hasDups(std::vector<int> nums)
{
    bool result = false; 
    std::unordered_set<int> dups;

    for(auto it = nums.begin(); it != nums.end(); ++it )
    {
        if(dups.count(*it))
        {
            return true;
        }

        dups.insert(*it);
    }

    return result;

}




std::vector<std::vector<int>> mergeInterval(
    std::vector<std::vector<int>> nums)
{
    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> result;

    auto running_vector = nums[0];

    for (auto current_vector : nums)
    {
        if (current_vector[0] <= running_vector[1])
        {
            // Overlap → extend running interval
            running_vector[1] =
                std::max(current_vector[1], running_vector[1]);
        }
        else
        {
            // No overlap → save completed interval
            result.push_back(running_vector);
            running_vector = current_vector;
        }
    }

    // Don't forget the final interval
    result.push_back(running_vector);

    return result;
}


std::vector<std::pair<int,int>> kdups(std::vector<int> nums, int k)
{
    std::unordered_map<int, int> hashmap;
    std::vector<std::pair<int,int>> vec;
    std::vector<std::pair<int,int>> result;

    for(auto num : nums)
    {

        hashmap[num]++ ;

    }

    for(auto pair : hashmap){

        vec.push_back({pair.first, pair.second});
        
    }
    std::sort(vec.begin(), vec.end());

    for(int i =0; i<k; i++)
    {
        result.push_back(vec[i]);
    }

    return result;



}

int main()
{
    return 0;
}