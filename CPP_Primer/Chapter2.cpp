//第二章 变量和基本类型

#include <iostream>

int main()
{

    //变量的初始化方式
    int sold = 0;
    int sold1 = {1};
    int sold2(2);
    int sold3{3};

    std::cout << sold << sold1 << sold2 << sold3 << std::endl;

    //默认初始化
    std::string str;
    unsigned int index;
    if (str.empty())
    {
        std::cout << "ste is null" << std::endl;
    }

    std::cout << index << std::endl;
    return 0;
}