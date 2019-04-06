#include <iostream>

class A
{
  private:
    /* data */
  public:
    A(/* args */);
    A(int value);
    ~A();

    A *operator+(const A &a)
    {
        this->num += a.num;
        return this;
    };
    int num;
};

A::A()
{
}

A::A(int value) : num(value)
{
}

A::~A()
{
}

//**运算符 重载*/
void study1()
{
    A a(1314);
    A b(-2468);

    std::cout << a.num << std::endl;
    std::cout << b.num << std::endl;
    std::cout << ((a + b)->num) << std::endl;
}

//**左值（lvalue）  右值（rvalue）*/
void study2()
{
    //左值 在内存中的位置
    //右值 对象的内容
}

//**强制转换  static_cast dynamic_cast  const_cast reinterpret_cast */
void study3()
{
    //1.static_cast
    double d = 3.1415926;
    void *p = &d;

    auto pointer = static_cast<double *>(p);

    std::cout << *pointer << std::endl;

    //2.const_cast
    const char *ch = "hello world";
    char *ch2 = const_cast<char *>(ch);

    std::cout << ch2 << std::endl;

    //3. reinterpret_cast （几乎不用  高风险）
    int *ip;
    char *pc = reinterpret_cast<char *>(ip); //pc 所指的真实对象是int 不是字符串

    // std::cout<<*pc<<std::endl;  导致Exception
}

int main()
{

    //study1();
    study3();
    return 0;
}