#include <iostream>

void foo(int);

void foo(int num)
{
    std::cout << num << std::endl;
}

int foo_local(int param)
{
    int index = 1; //函数调用结束后 自动释放
    return param + index;
}

size_t foo_Static()
{
    static size_t ctr = 0; //函数调用结束后，这个值仍然有效
    return ctr;
}

//**局部对象 自动对象 静态对象*/
void study1()
{
    foo_local(-1);
    foo_Static();
}

const int *foo3()
{
    int temp[] = {1, 3, 4, 5};
    return temp;
}

//**不要Retrun 一个局部变量*/
void study2()
{
    const int *arrary = foo3();

    std::cout << (*arrary) << std::endl;
}

int main()
{
    foo(3.14); //实参转为了Int 类型
    //study1();
    study2();
    return 0;
}