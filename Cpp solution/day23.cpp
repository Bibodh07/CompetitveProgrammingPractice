#include <iostream>

std::string shortSubstrings(std::string b)
{
    std::string result; 
    result += b[0];

    for(int i = 1; i<(int)b.length(); i+=2)
    {
        result+=b[i];
    }

    return result;
}

int minMoves(int a, int b)
{
    int distance = abs(a - b);
    int result = distance / 10;
    if (distance % 10 != 0)
        result++;
    return result;
}

int main()
{    
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--)
    {
    std::string b;
    std::cin >> b;
    std::cout << shortSubstrings(b) << "\n";
    }
    

    return 0;
}