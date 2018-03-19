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
  