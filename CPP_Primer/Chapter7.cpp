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

//**----------类的其他特性------------*/
class Screen
{
public:
    typedef std::string::size_type pos; //定义类型 还可以使用     using pos=std::string::size_type;

    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const { return contents[cursor]; } //a.隐式内联
    inline char get(pos ht, pos wd) const;        //b.显式内联
    Screen &move(pos r, pos wd);                  //c.之后设置为 内联

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr; //可变数据成员 即使对象是const 也可以修改
};

//b
char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    access_ctr = 3; //mutable变量可以变更
    //height=5; 不可以改变
    return contents[row + c];
}

//c
inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

//**----------类的其他特性  end------------*/

//**----------友元------------*/
class Screen2
{
    friend class Window; //友元类 可以Read Write Screen2的Private字段

public:
    Screen2();

private:
    float width, height, scale;
};

Screen2::Screen2() : height(30.0), width(20.0), scale(0.5)
{
}

class Window
{
public:
    void Clear();
    void PrintScreen();

private:
    Screen2 screen;
};

void Window::Clear()
{
    this->screen.height = 0.0f;
    this->screen.width = 0.0f;
    this->screen.scale = 1.0f;
}

void Window::PrintScreen()
{
    std::cout << "Height->  " << this->screen.height << std::endl;
    std::cout << "Width->  " << this->screen.width << std::endl;
    std::cout << "Scale->  " << this->screen.scale << std::endl;
}

//**----------友元  end-----------*/

int main()
{
    // A a;
    // a.foo(5);
    // A other;
    // A cls = a.Combain(other);
    // cls.Print();

    Window win;
    win.PrintScreen();
    win.Clear();
    std::cout << "After Clear" << std::endl;
    win.PrintScreen();
    return 0;
}