#include<iostream>
#include <stdio.h>



bool canSplit(int w)
{
    return w > 2 && w % 2 == 0;
}

int newProb(int n)
{
    int two_counter = 0;
    int three_counter = 0;
    int total = 0;

    int pseudo = n;

    if( n == 1)
    {
        return 0;
    }

    while(pseudo > 1)
    {
       
        if(pseudo%2 == 0)
        {
             
            two_counter += 1;
            pseudo /= 2;

        }

        else if(pseudo%3 == 0)
        {
            
            three_counter += 1;
            pseudo /=3;

        }
        
        else
        {
            return -1;
        }
    }
    


    if (two_counter > three_counter){
        return -1;
    }
    
    total = three_counter + (three_counter - two_counter);
    
    return total;
    
}



int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int w;
    std::cin >> w;

    if (canSplit(w))
        std::cout << "YES\n";
    else
        std::cout << "NO\n";

    return 0;
}