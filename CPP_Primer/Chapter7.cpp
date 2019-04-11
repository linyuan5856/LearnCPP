#include <iostream>
#include <vector>

using namespace std;

class A
{
private:
    string name;
    int a;
    char *des;

public:
    A();
    void foo(int) const;
    A &Combain(const A &);
    void Print() const;
};

A::A() : a(1)
{
}

void A::foo(int value) const //常量成员函数  表示隐式参数this 是一个指向常量的指针,不能改变其调用它的对象的内容
{
    //this->a = value;  //invalid
    cout << value << endl;
}

A &A::Combain(const A &other)
{
    this->a += other.a;
    return *this; //返回自身的引用
}

void A::Print() const
{
    cout << this->a << endl;
}

class B
{
public:
    B(int a){};
};

class C
{
public:
    C() = default; //c++ 11 说明该类需要默认构造函数
    C(int a){};
};

void TestConstruct()
{
    //B b;  --Class B 申明了一个 int 类型的构造函数 编译器不会再自动生成默认构造函数
    C c;
}


int main()
{
    A a;
    a.foo(5);
    A other;
    A cls = a.Combain(other);
    cls.Print();

    return 0;
}