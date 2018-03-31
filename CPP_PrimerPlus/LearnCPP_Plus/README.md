# 第一章 预备知识
## 特点
- c   **面向过程**
- C++ **面向对象**


## C++标准
- C98/C03
- C11

# 第二章 开始学习C++
## main函数
``` c++
int main()
{
return 0;
}

``` 
等同于
``` c++
int main(void) //void表示没有参数 C语言的表示方法
{
return 0;
}

``` 
## 头文件约定
头文件类型 | 约定 |示例 | 说明
--------- | ---- |-----|-----
C++旧式风格| 以.h结尾|iostream.h|c++都可以使用
C旧式风格| 以.h结尾|math.h|c,c++都可以使用
C++新式风格|没有扩展名|iostream|C++可以使用，使用namespace std
转换后的c|加上前缀c，没有扩展名|cmath|C++程序可以使用，可以使用不是c的特性,如namespace std

## C++输出
``` c++
//两种换行方式
std::cout<<"do something\n"
std::cout<<"do something"<<endl
```
# 第三章 处理数据
- 内置C++类型 
1.基本类型（整数，浮点数） 
2.复合类型（数组，字符串，指针和结构）

## 整型 
`char,short,int,long,long long`
`short至少16位`
`int至少与short一样长`
`long至少32位，且至少与Int一样长`
`long long 至少64位 且至少与long一样长`

``` c++
int main(){
    using namespace std;
    int n_int=INT_MAX;

    cout<<"int is<<size of n_int<<"bytes."<<endl; //int is 4 bytes
    cout<<"Maximum values:"<<endl;
    cout<<"int: "<<n_int<<endl;//int:2147483647
}
```
- 初始化
``` c++
int num=5;//常规方式

//C++ 11
int num={24};
int num{24};
int num={};//默认初始化位0
int num{};//默认初始化位0
```
- cout表示 进制的用法
`dex,hex,oct eg:-->cout<<hex`

- signed char 和 unsigned char
`默认情况既不是没有符号也不是有符号 具体情况又C++实现决定`
`unsigned char(0-255)`
`signed char (-128-127)`

- wchat_t
`当无法用8字节表示（日本汉字）`
``` c++
wchar_t bob=L'p'; //前缀L 表示是宽字符串
wcout<<L"tall"<<endl; //使用wcin wcout输入输出
```
- char16_t char32_t
``` c++
char16_t cha1=u 'q'; //小写u 匹配char16_t
char32_t cha2=U '\0000222B';//大写U 匹配char32_t
```
## 浮点数
- 书写浮点数
  ``` c++
  float f=0.32;
  float f2=32E-2;//32/10^2
  ```

 - 浮点类型 `float double long double`

 - 浮点数精度`float 6位 doble 15位`
    
## 类型转换
- c++自动转换
  - **将一种算术类型的值赋给另一种算术类型的值**
  `1.较大浮点数转换位小浮点数 --> 精度降低 结果不确定`
  `2.浮点数转位整型 -->小数部分丢失 结果不确定`
  `3.较大整型转为较小整型，如long转为short-->原来的值可能超出目标类型取值范围，通常只复制右边的字节`
  
  - **以{ }方式初始化（C++ 11）**
  `不允许缩窄（不允许浮点数转整型）`
  - **表达式中包含不同类型**
  - **参数传递给函数**
  - **强制类型转换**
  ``` c++
   int a=5; long l=(long)a; //强制转型不会改变原来的值 而是生成新的值
  ```
# 第四章 复合类型
## 数组
 `short months[12]; (typeName arraryName[arrarySize])`
 - C++数组从0 开始编号
 - 大括号初始化
 ``` c++
  int arrary[3]={20,30,40};
  std::cout<<arrary[0]+arrary[1]+arrary[2]<<std::endl;//90
  float temps[5]={2.0f,3.5f};//只初始化前两个元素 其他默认初始值 0
  char things[]={2,3,4,5};//如果元素没有设置 C++会计算元素个数

 ```
 - c++11初始化
 ``` c++
double books[4]{1.2e4,1.6e4,2.5e6};
unsigned int boats[100]={}; //所有元素为默认值0
unsigned int teas[100]{}; //所有元素为默认值0
 ```
 **禁止缩窄** 
 ``` c++
  long l[]={25,92,3.0};//不允许 浮点数转换整型是缩窄 
  char c[4]{'h','i',1122011,'0'};//不允许 int类型超越了8位char最大值
 ```
## 字符串
  ### C风格字符串 `以空字符结尾（'\0' ASCII码为0）`
  - 初始化
  ``` c++
  char dogs[4]={'b','i','g','o'};//普通数组
  char cats[5]={'c','a','t','s','\0'};//字符串
  
  //简化申明方式  隐士的包含了'\0'
  char cats[5]="cats";
  char dogs[]="dogs";  
  
 //字符串常量 不能与 字符常量互换
  char s='s';//字符常量 ASCII编码 83
  //"s" ->'s','\0' 由两个字符构成的字符串 实际上表示的是字符串所在的内存地址

  ```
  - 拼接字符串
   ``` c++
    std::cout << "one" "two"
    "three"<<std::endl; //空格 制表符 换行符分隔的字符串都会自动拼接
   ```

 - 在数组中使用字符串
  ``` C++
   char names[]="name is Lin";
   std::cout<<sizeof(names)<<std::endl;//12个字节 数组大小
   std::cout<<strlen(names)<<std::endl;//11个字符 字符串长度
  ```
 - 读取整行的方法 cin.getline() 舍弃换行符  cin.get() 保留换行符

 - 其他方法
  ``` c++
  char c1[20];
  char c2[20]="qdsadada";

  strcpy(c1,c2); //拷贝
  strcat(c1,"another");//附加
  ```
   
  ### string类库
 - 和C风格字符串 主要区别:
   1.String对象可以申明为简单变量 而不是数组
   2.类设计让程序能够自动处理string的大小 更安全更方便

 - 赋值，拼接和附加
 ``` c++
   string s1;
   string s2="i am s2";
   s1=s2;
   
   char c1[];
   char c2[]="i am c2";
   c1-c2;//非法 数组不可以复制给另一个数组

   string s3=s1+s2;//string拼接 
   s3+="end";//附加
 ```
## 结构简介
 - 创建初始化
 ``` C++
struct myStruct{
  int id;
  unsigned int hp;
  std::string name;
}
 
  //初始化
  myStruct Lin={1,56,"Lin"};
     
  std::cout<<Lin.id<<std::endl;

 //同时完成创建和初始化
 struct coat{
   int num;
   float price;
 }ship,duck;

 ```
 - 结构数组
 ``` c++
  struct m_s{
    int num;
    float hp;
  };
  m_s nums[20];
  nums[0]={5,30.0f};

 ```
 - 结构中的位字段 `字段类型为整型或枚举`
  ``` c++
   struct register={
    unsigned int SN:4; //SN的值 4bit
    unsigned int :4; //类型 4bit
    bool goodin:1; //1 bit 
    bool goodTorgele :1;
   };
  ```
## 共用体 
` 存储不同数据 但同时只能使用一种`

``` c++
union one4all{
   int int_val;
   long long_val;
   double double_val;
}

 //匿名共同体 
  struct widget{
    char brand[20];
    int type;
    union{
     long id_num;
     char id_char[20];
    };
  }

  widget price;
  if(price.type==1)
  std::cin>>price.id_num;
  else
  std::cin>>price.id_char;
```
## 枚举

``` c++
//对应数值从0开始
 enum spectrum{ red,green,yellow,blue,grey,purple};
  spectrum color;
  color=red;
  color=spectrum[3];//不能越界
 
 //设置枚举的量
   enum sport={football=1,basketball=2};
   //显示设置
    enum peopel={man,woman=500,earth,marth};//man是0 woman 500 earth 501 marth 502
```
## 指针和自由存储空间
``` c++
int main(){
using namespace std;
 int updates=6;
 int *p_updates=&updates;

 cout<<"values : Updates"<<updates<<endl;//6
 cout<<"*p_updates= "<<*p_updates<<endl;//6

 cout<<"p_updates="<<p_updates<<endl;//0x0065fd48
 cout<<"&updates="<<&updates<<endl;//0x0065fd48
}
```
- 使用new来分配内存 delete释放内存
``` c++
using namespace std;
//可以通过nights 或*p_nights 得到1001的值 变量的内存在stack栈中
int nights=1001;
int* p_nights=&nights;

//只能通过*pt 得到值 new出的内存都在堆中
int *pt=new int;
*pt=1001;
delete pt;
```

-使用new 来创建动态数组
``` c++
using namespace std;
int*psome=new int[4];
psome[0]=1;
psome[1]=3;
psome[2]=5;
psome[3]=7;

//数组的指针就是第一个元素的地址
cout<<*psome<<endl;//1
cout<<psome[0]<<endl;//1

//数组的指针+1 -1 就是移动数组一个元素的地址
psome=psome+1;
cout<<"new pSome[0]"<<*psome<<endl;//new psome[0] 3
psome=psome-1;
cout<<"Back To Old pSome[0]"<<*psome<<endl;//back to old psome[0] 1

delete []psome;

```
`不要使用delete释放一个不是new分配的内存`
`不要使用delete释放一个内存块两次`
`如果使用new[]为数组分配内存，应该使用delete[]来释放`
`如果使用new[]来为一个实体分配内存，应该使用delete(没有方括号)来释放`
`对空指针应用delete是安全的`

## 指针，数组和指针算术

- 数组的地址
``` c++
using namespace std;
int*psome=new int[3];
psome[0]=1;
psome[1]=3;
psome[2]=5;

cout<<psome<<endl;//第一个元素的地址
cout<<&psome<<endl;//整个数组（3个元素）的地址

/* 可以理解为 int(*pas)[3]=&psome; 必须加小括号 不然代码int数组的指针
   *pas=psome; -> *pas[0]=psome[0]=psome; 第一个元素
  */
```
- 指针和字符串
`在cout和多数C++表达式中，char数组名、char指针以及用引号括起的字符串常量都被解释为字符串第一个字符的地址`

``` c++
int main(){
using namespace std;
char animals[5]="duck";
const char*bird="tom";

//cout 收到字符串的指针就会 找到指针指向的内容输出 一直遇到空字符('\0')
cout<<animal<<endl;//duck
cout<<bird<<endl;//tom
}
```
- 使用new 创造动态结构
``` c++
using namespace std;
struct things{
  int id;
  const char* describe;
}coat;

coat={1,"i am a coat"};
things *p_coat=&coat;

cout<<p_coat->id<<endl;//1

things *any=new things;
(*any).id=9527;
any->describe="i am 9527";

cout<<any->id<<endl;//9527
cout<<(*any).describe<<endl;//i am 9527

delete any;
```

- 自动存储,静态存储,动态存储

`函数内部定义的变量 使用自动存储空间 函数调用时候产生 结束时消亡`

`静态存储（整个程序执行期间都存在） 1.函数外面定义 2.使用static关键字 `

`动态存储 new delete `

# 第五章 循环和关系表达式

## for 循环
``` c++
using namespace std;
//C循环写法 （兼容C++）
int i;
for(i=5;i<10;i++)
cout<<i<<endl;
//C++新写法
for(int i=5；i；i--) //i为0的时候停止 非0为ture 0为false
cout<<i<<endl;
```

- `++i和i++   --i和i--`
``` c++
int a=20;
int b=30;

std::cout<<a++<<std::endl;//20
std::cout<<++b<<std::endl;//31

std::cout<<a<<std::endl;//21
std::cout<<b<<std::endl;//21
```
## while 循环
``` c++
while(true)
std::cout<<"while loop is doing"<<std::endl;

for(;;)
std::cout<<""for loop forever"<<std::endl;
```
## 基于范围的for循环(C++11)
``` c++
int nums[5]={1,2,3,4,5};
for(int x::nums)
std::cout<<x<<std::endl;//1,2,3,4,5
```
# 第六章 分支语句和逻辑运算符
`if `
`if else `
`&& || !`
` ? ：`
`switch`
`continue break`

#第七章 函数-C++编程模块
## 基本概念
`提供函数原型`
`提供函数定义`
`调用函数`

## 函数参数和按值传递
` argument 实参 parameter 形参`
`函数传递的都是副本 不会对数据源进行任何修改（指针 引用除外） `

## 函数和数组
` 函数数组参数 传递的其实是数组的指针（第一个元素）`
  1.数组申明使用数组名来标记存储位置
  2.对数组名使用sizeof将得到整个数组的长度（以字节为单位）
  3.将地址运算符&用于数组名时，返回整个数组的地址

  ``` c++
  //下面2个sum方法的参数 等价 都是数组
   void sum(int[]array){};
    
   void sum(int*arrary); 

   //const 代表参数是常量数据 不可更改 只读 
   void dosth(const int*arrary){}
  ```

## 函数和C风格字符串
 ` 表示字符串的三种方式`
  1.char数组
  2.用引号括起的字符串常量（也称字符串字面值）
  3.被设置为字符串的地址的char指针

  ``` c++
  char ghost[15]="gogogo";
  char*str="gogogo";

  int n1=strlen(ghost);//&ghost[0]
  int n2=strlen(str);//char指针
  int n3=strlen("gogogo");//字符串指针的地址
  ```

## 函数和结构
 1.传递函数的副本
 2.传递指针
 3.传递引用

 ## 函数指针
  ``` c++
  //申明
  double pam(int);
  doublt(*pf)(int);
  //赋值
  pf=pam;
  //调用
  (*pf)(32.6);
  pf(32.6);
   ```
  
# 第八章 函数探幽
## c++内联函数
` 效率更高，副作用：占用更多的内存`
` 在函数申明前加上关键字inline`
` 在函数定义前加上关键字inline`

``` c++
inline double square(double x){return x*x};

int main(){
   int result=square(5);
   std::cout<<result<<std::endl;
  return 0;
}
```

## 引用变量
``` c++
int rats;
int & rodents=rats;//此处& 不是地址运算符 而是类型标识符 （引用）
```

`引用和指针的区别 引用必须初始化（和常量指针的特性相同）`

`引用`
``` c++
int main(){
using namespace std;
int rats=101;
int & rodents=rats;
int bunnies=50;
rodents=bunnies;

 cout<<rats<<endl;//50
 cout<<rodents<<endl;//50
 cout<<bunnies<<endl;//50
 return 0；
 } 
```
` 指针`
``` c++
int main(){
using namespace std;  
  int rats=101;
  int *pt=&rats; 
  int &rodents=*pt;
  int bunnies=50;
  pt=&bunnies;
  cout<<rats<<endl;//101
  cout<<rodents<<endl;//101
  cout<<bunnies<<endl; //50 
   return 0；
}
```

`临时变量，引用参数，const `
 - - 创建临时参数的条件
    1.引用参数是const
     2.实参的类型正确但不是左值
      3.实参的类型不正确但可以转换为正确的类型

 `左值：可被引用的数据对象（eg:变量，数组元素，结构成员，引用和解除引用的指针都是左值） `

 ``` c++
  double refcube(const double &ra){return ra*ra*ra};
   
   double side=3.0;
   double *pd=&side;
   double &rd=side;
   lng edge=5L;
   double lens[4]={2.0,3.0,4.0,5.0};

  int main(){
   double c1=refcube(side);//传递引用
   double c2=refcube(lens[2]);//传递引用
   double c3=refcube(rd);//传递引用
   double c4=refcube(*pd);//传递引用
   double c5=refcube(edge);//临时变量 实参类型不正确
   double c6=refcube(7.0);//临时变量   类型正确 不是左值
   double c7=refcube(side+10.0);//临时变量  类型正确不是左值   
    return 0;
  }
 ```
 `应尽可能使用const `
  - - 使用const可以避免无意中修改数据的编程错误
  - - 使用const使函数能够处理const和非const实参，否则只能接受非const数据
  - - 使用const引用函数能够正确生产并使用临时变量
 
  ` c++ 11 新加入->右值引用 使用&&申明 `
  ``` c++
  int main(){
    using namespace std;
    double && rref=std::qurt(36.00);
    double j=15.0;
    double &&jref=2.0*j+18.5;
    cout<<rref<<'\n';//6.0
    cout<<jref<<'\n';//48.5    
    return 0;}
  ```
## 默认参数
## 函数重载
``` c++
void print(const char*str,int width); //#1
void print(double d,int width);       //#2
void print(long l,int width);         //#3
void print(int i,int width);          //#4
void print(const char*str);           //#5

print("something",15); //#1
print("something");    //#5
print(1999.0,10);      //#2
print(1999,11);        //#4
print(1999L,12);       //#3

unsigned int year=1998;
print(year,6);//不与任何匹配 编译器进行强制转化时候 会发现3个可转化选择这种情况下 编译器拒绝这种函数调用

/* 下面2个重载方法不成立 返回值不同 特征标（参数）也必须不同 */
long drongk(int n,float m);
double drongk(int n,float m);
```
## 函数模板

-  基本描述
``` c++
 template<typename AnyType>
 void swap(AnyType &a,AnyType &b){
   AnyType temp;
   temp=a;
   a=b;
   b=temp;
 }
```
- 重载的模板
``` c++
template<typename T>
void Swap(T &a,T &b);

template<typename T>
void Swap(T *a,T *b,int n);
```
- 显示具体化
`1.对于给定的函数名，可以有非模板函数、模板函数和显示具体化模板函数以及
它们的重载模板`
`2.显示具体化的原型和定义应以template<>打头，并通过名称来指出类型 `
`3.具体化优先于常规模板，而非模板函数优于具体化和常规模板 `

``` c++
//非模板函数
void swap(job&,job&);

//模板函数
template<typename T>
void swap(T &.T &);

//显示具体化
template<> void swap<job>(job&,job&);
//显示具体化的第二种写法 省略<job>
template<> void swap(job&,job&);
```

- 实例化和具象化
- 编译器选择哪个函数版本
- 模板函数的发展
` c++11 新增关键字 decltype`
``` c++
 int x;
 decltype(x) y;//让y和x同一个类型

template<typename T1,typename T2>
 void ft(T1 x,T2 y){
  decltype(x+y)xpy=x+y;
 }
```
`c++11 后置返回值类型 `
``` c++
 auto h(int x,float y)->double{body};
```
# 内存模型和名称空间
## 单独编译
``` c++
#ifndef DEF_H
#define DEF_H
  //do something
  
#endif

//防止头文件被多次include
```
## 存储持续性、作用域和链接性
- 自动存储持续性
` 自动变量的存储位置在栈中 函数开始入栈 函数结束出栈`
- 静态存储持续性
- - 外部链接性
` extern 使用外部变量`
- - 内部链接性
- - 无链接性
``` c++
int global=886;//外部链接性 静态存储
static int one_file=688;//内部链接性 静态存储
int main(){
  return 0;
}

void foo(int n)
{
  static int count=0;//无链接性 静态存储
  int llama=0;//自动变量
}
```
- 线程存储持续性（C++11）` thread_local`
- 动态存储持续性

- 说明符 和 限定符 
 - - 存储说明符
  ` auto(c++11中不再是说明符)`
  ` register`
  ` static`
  ` extern`
  ` thread_local`
  ` mutable（即使结构或类成员为const 其变量也可以修改）`

- - cv_限定符
` const`
` volatile(变量可能被修改)`

- 函数的链接性

## 命名空间
` 解决名称冲突`

# 对象和类
## 抽象和类
``` c++
//stock.h头文件
class Stock{
 private:
  char company[30];
  int shares;
  double share_val;
  double total_val;
  void set_tot(){total_val=shares*share_val};
  public:
  void acquire(const char*co,int n,double pr);
  void buy(int num,double price);
  void sell(int num,double price);
  void show();
}
```
```c++
//stock.cpp文件
#include "stock.h"
void Stock::acquire(const char*co,int n,double pr)
{
 //implement function
}

void Stock::buy(int num,double price){
 //implement function

}
  
void Stock::sell(int num,double price){
 //implement function

}

void Stock::show(){
 //implement function
}
```
##类的构造函数和析构函数
- 基本写法
``` c++
Stock::Stock(const string&co,long n=0,double pr){
  //init 
}

Stock::Stock(){

}

Stock::~Stock(){

}
```

- 具体调用
``` c++
 int main(){
    /*初始化类的两种方式*/
    //初始化一个类
    Stock stock1("stock1",12,20.0);
    
    //C++编译器有两种处理方式
    //1.和stock(....)相同直接初始化
    //2.初始化一个临时变量 再复制给stock2 临时变量销毁时会调用析构函数
    Stock stock2=Stock("stock2",10,5.0);
    //将sotck2的值复制到stock1中
    stock1=stock2;
    
    //stock1已经存在 不是初始化而是申请一个临时变量赋值到stock1 再销毁临时变量
    stock1=Stock("new stock1",15,98.0);
    return 0;
 }
```
`C++11列表初始化`
``` c++
 Stock st={"c11 init way",100,45.0};
 Stock st1{"no = init"};//参数不足 按照类型默认值初始化
 Stock temp{};
```

`const成员函数`
``` c++
  const Stock m_stock=Stock("const foo");
  m_stock.show();//编译器无法通过 无法保证对象不被修改

  //可以将const关键字放在函数后面 表示此函数不会修改调用对象
   void show()const;
    
   Stock::show()const;

```

## this 指针
## 对象数组
## 类作用域
``` C++
/*作用域为类的常量*/
class Bakery{
  private:
  //创建对象前 没有存储
  const int Months=12;
  double costs[Months];
}

/*解决方式*/
//A.申明一个枚举（作用域为整个类）
class Bakery{
  private:
   enum{Months=12};
   double costs[Months];
}

//B.static 会创建一个常量和其他静态变量存储在一起而不是存储在对象中
 class Bakery{
   private:
   static const int Months=12;
   double cost[Months];
 }

```

## 抽象数据类型

# 第十一章 使用类
## 运算符重载
``` c++
/* .h*/
class Time
{
  private:
  int hours;
  int minutes;
  public:
  Time();
  Time(int h,int m=0);
  void AddMin(int m);
  void AddHour(int h);
  void Reset(int h=0,int m=0);
  Time opertator+(const Time & t) const;
  void Show()const;
}

/* .cpp*/
  Time::Time()
  {
    hours=minutes=0;
  }

  Time::Time(int h,int m=0)
  {
     hours=h;
     minutes=m;
  }
  
  void Time::AddMin(int m){
     //do sth
  }
  void Time::AddHour(int h){
     //do sth
  }
  void Time::Reset(int h=0,int m=0){
     //do sth
  }
  Time Time::opertator+(const Time & t) const{
     Time sum;
     sum.minutes=minutes+t.minutes;
     sum.hours=hours+t.hours+sum.minutes/60;
     sum.minutes%=60;
     return sum;
  }
  void Time::Show()const{
     //do sth
  }
```
## 友元
` 虽然在类中申明但不是成员函数  不能使用成员运算符来调用`
` 虽然不是成员函数 但是访问权限和成员函数相同`
``` c++
/*.h*/
friend Time operator*(double m,const Time&t); 

/*.cpp*/
Time operator*(double m,const Time&t){

};
```
