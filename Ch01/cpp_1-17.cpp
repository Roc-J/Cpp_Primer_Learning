#include<iostream> 

int main()
{
    int currval=0, val=0;
    int cnt = 0;
    std::cout << "input your numbers: " << std::endl;
    if(std::cin >> currval) 
        cnt = 1;
        while(std::cin >> val)
        {
            if (currval == val)
            {
                cnt +=1;
            }
            else
            {
                std::cout << "input value:" << currval << " times: " << cnt << std::endl;
                currval = val;
                cnt = 1;
            }
            
        }
        std::cout << "input value:" << currval << " times: " << cnt << std::endl;
    return 0;
}