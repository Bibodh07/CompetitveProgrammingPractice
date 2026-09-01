#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <utility>
#include <vector>



int smallestFreq(std::vector<int> nums)
{
    std::map<int, int> book;
    int result = -1;
    int target = 1;

    for (auto n : nums)
    {
        book[n]++;
    }

    for (auto pair : book)
    {

        if(pair.second == target)
        {
            return pair.first;
        }


    }

    return -1;
}

std::vector<std::pair<int,int>> mapPair(std::vector<int> nums)
{

    std::map<int, int> book;
    std::vector<std::pair<int,int>> result;
    for (auto n : nums)
    {
        book[n]++;
    }

    for (auto pair: book)
    {
        result.push_back({pair.first, pair.second});
    }

    return result;

}

std::vector<std::pair<int,int>> sortStudents(std::vector<std::pair<int,int>> students)
{
    std::sort(students.begin(),
     students.end(),
    [] (const auto&a, const auto&b)
     {
        if (a.first != b.first)
        {
            return a.first > b.first;
        }

        return a.second < b.second;

     }
        
    );

}


int firstUnique(std::vector<int> nums)
{
    int result = -1;

    std::map<int, int> freq;

    for (auto num: nums)
    {
        freq[num]++;
    }

    for(auto num: nums)
    {
        if (freq[num] == 1)
        {
            return num;
        }
    }
    return result;
}


int main() {
    return 0;
}