#include <iostream>
#include <cmath>




void findRoundNums(int n)
{
int power = 1;
int pseudo = n;

while (pseudo > 0)
{
    int remainder = pseudo % 10;

    if (remainder != 0)
    {
        int result = remainder * power;
        std::cout << result << " ";
    }

    pseudo /= 10;
    power *= 10;
}
}


int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


    int t;
std::cin >> t;
while (t--)
{
    int n;
    std::cin >> n;
    findRoundNums(n);
}

    return 0;


}