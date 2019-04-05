//第二章 变量和基本类型

#include <iostream>

//**变量初始化*/
void study1()
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
}

//**引用和指针*/
void study2()
{
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
}

//**引用和指针拓展*/
void study3()
{
    //1.指向指针的指针
    int val = 1024;
    int *p = &val;
    int **ppl = &p;

    std::cout << " 指针p->  " << p << std::endl;
    std::cout << " 指针ppl->  " << ppl << std::endl;
    std::cout << " 解开 指针p->  " << *p << std::endl;
    std::cout << " 解开 指针ppl->  " << *ppl << std::endl;
    std::cout << " Double 解开 指针ppl->  " << **ppl << " \n " << std::endl;

    //2.只想指针的引用
    int value = 2046;
    int *pointer;
    int *&r = pointer;

    r = &value;
    std::cout << " pointer指针的值-> " << pointer << std::endl;
    std::cout << " 解开pointer指针-> " << *pointer << std::endl;
    std::cout << " value的值-> " << value << std::endl;
    *r = 0;

    std::cout << " value最新的值->" << value << std::endl;
}

//1.初始化常量（仅在文件中有效）
const int buffer = 1024;
//buffer=2048; --invalid

//2. 在文件件共享的变量
extern const int buffer2 = 2048;

//**Const限定符*/
void study4()
{
    //3.Const的引用
    const int c = 1;
    const int &r1 = c; //对常量的引用
    //r1=42;  --invalid 常量引用不可变更
    //int &r2=c; --invalid 非常量引用 不能引用常量

    int value = 2;
    const int &r2 = value; //允许将 const int &绑定到一个普通int对象上

    int i = 42;
    int &ref = i;
    const int &ref2 = i;
    ref = 0;
    //ref2=0; --invalid 常量引用不可以赋值

    //4.指针和Const
    double d = 3.1415926;
    const double *const p = &d;
    double *p2 = &d;

    double d2 = 1.14;
    //p = &d2; const指针不可被修改
    p2 = &d2;
}

//**顶层Const --指针本身是个常量  底层Const 指针所指的对象是一个常量*/
void study5()
{
    int i = 9;
    int *const p1 = &i;  //顶层Const
    const int ci = 39;   //顶层Const
    const int *p2 = &ci; //底层Constr
    const int &r = ci;   //底层Const （申明引用的是底层Const）
}

//**类型别名*/
void study6()
{
    typedef double wages;   //wages 就是Double类型的别名
    typedef wages base, *p; //base,wages,double类型 等价,申明了一个double类型的指针 命名为p
    typedef struct
    {
        char c;
    } s; //申明了一个类型为s的结构体

    s s1;
    s1.c = 'a';
    base value = 3.1415926;
    p point = &value;

    std::cout << s1.c << std::endl;
    std::cout << value << std::endl;
    std::cout << point << std::endl;
    std::cout << *point << '\n'
              << std::endl;

    typedef int A[]; //申明了一个 int类型数组 类型名称为A

    A a{3, 5};
    std::cout << a[0] << std::endl;
    std::cout << a[1] << std::endl;
}

int main()
{

    //study1();

    //study2();

    //study3();

    //study4();

    study6();
    return 0;
}