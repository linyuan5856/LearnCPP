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

    //引用（引用不能为空 必须初始化）

    int value = 2048;
    int &refVal = value;
    refVal = 1; //value的值 会呗更改

    std::cout << value << std::endl;

    //指针（可以不初始化 为nullptl）
    int val = 1024;
    int *p = &val;
    std::cout << val << std::endl;
    std::cout << p << std::endl;
    std::cout << *p << std::endl;

    //void* 任意对象的地址
    double obj = 3.1415926;
    double *pd = &obj;

    void *pv = &obj;
    if (pv == pd)
    {
        std::cout << "pv == pd " << std::endl;
    }

    double *test = static_cast<double *>(pv);

    std::cout << *test << std::endl;

    return 0;
}