#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>

using std::string;
using std::vector;

//** 标准库 String*/
void study1()
{
    string s1;            //直接初始化
    string s2(s1);        //拷贝初始化
    string s3("值value"); //拷贝初始化
    string s4(5, 'c');    //直接初始化

    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    std::cout << s4 << std::endl;

    if (!s3.empty())
    {
        std::cout << "s3 Size->  " << s3.size() << std::endl;
    }

    s1 = s3 + s4;
    std::cout << s1 << std::endl;

    const char *c = "i like it that way";
    string s(c);
    std::cout << s << std::endl;

    c = s.c_str();
}

//** 标准库 String   cctype函数*/
void study2()
{

    string num = "3";
    bool result = isalpha(num[0]); //字母
    std::cout << result << std::endl;

    num = "A";
    result = isalnum(num[0]); //字母和字符
    std::cout << result << std::endl;
}

//**标准库类型 Vector*/
void study3()
{
    vector<int> v;
    std::cout << "Is Empty->" << v.empty() << std::endl;
    v.push_back(5);
    v.push_back(1314);
    v.push_back(2048);

    for (auto &&i : v)
    {
        std::cout << i << std::endl;
    }

    std::cout << "Front-> " << v.front() << std::endl;
    std::cout << "Back->" << v.back() << std::endl;

    std::cout << "Index 1->" << v[1] << std::endl;
    std::cout << "Size->" << v.size() << std::endl;
    std::cout << "Index 5->" << v[5] << std::endl;

    //使用数组初始化Vector对象
    int int_arr[] = {1, 3, 1, 4, 5, 2, 0};
    vector<int> ivec(std::begin(int_arr), std::end(int_arr));
    for (auto &&i : ivec)
    {
        std::cout << i << std::endl;
    }
}

//**迭代器*/
void study4()
{
    string s = "learn Cpp";

    if (s.begin() != s.end())
    {
        auto it = s.begin();
        *it = toupper(*it);
    }

    std::cout << s << std::endl;

    //iterator 能读能写 const_iterator 只读
}

//**数组*/
void study5()
{
    int a[] = {0, 1, 2};
    // int a2[] = a; 数组不允许直接初始化另一个数组
    int a3[3];
    //a3 = a; 不能把一个数组直接赋值给另一个数组

    //int &ref[10];//不允许引用数组

    int *ptrs[10]; //含有10个整数指针的数组
    int(*ptr)[10]; //ptr是一个指向拥有10个整数类型的数组

    //使用数组时 编译器会把它转换为指针
    string nums[] = {"ab", "cd", "efg"};
    string *p = &nums[0];

    std::cout << *p << std::endl;
    std::cout << *(p + 1) << std::endl;

    int ia[] = {1024, 2, 3, 4, 5, 6};
    auto ia2(ia);

    std::cout << ia2 << std::endl;
    std::cout << *ia2 << std::endl;

    //指针也可以作为迭代器
    ++p;
    std::cout << *p << std::endl;
    ++p;
    std::cout << *p << std::endl;
}

//**C风格字符串*/
void study6()
{
    string s = "Hello World";
    const char *ch = s.c_str();
    const char *ch2 = "Hello World";

    std::cout << (s == ch) << std::endl;
    std::cout << (s == ch2) << std::endl;
    std::cout << (ch == ch2) << std::endl;
}

int main()
{
    //study1();
    //study2();
    //study3();
    //study4();
    //study5();
    study6();

    return 0;
}