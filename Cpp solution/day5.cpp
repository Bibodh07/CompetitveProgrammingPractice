#include <iostream>
#include <vector>
#include <algorithm> 



bool meetingOverlap(std::vector<std::pair<int, int>> nums)
{


    if (nums.empty()){
        return true;
    }

    std::sort(nums.begin(),
              nums.end(),
              [](const auto &a, const auto&b){
                return a.first < b.first;
              }
             );
    auto current = nums[0];

    for(auto i = 1; i < nums.size(); i++)
    {

        if(current.second > nums[i].first){
            return false;
        }

        else{
            current = nums[i];
        }

    }


    return true;


}



int meetingII(std::vector<int> start, std::vector<int> end)
{
    int current_room = 0;
    int max = 0;
    int end_pointer = 0;


    std::sort(start.begin(),start.end());
    std::sort(end.begin(), end.end());



    for (size_t i = 0; i<start.size(); i++)
    {

        if(start[i] <= end[end_pointer])
        {
            current_room ++;
            max = std::max(current_room, max);
        }

        else
        {
            current_room -- ;
            end_pointer++;
        }

    }
    return max;
}


int main()
{


    std::vector<std::pair<int,int>> test1 = {{0,30}, {5,10}, {15,20}};
    std::cout<< meetingOverlap(test1);
    return 0;
}