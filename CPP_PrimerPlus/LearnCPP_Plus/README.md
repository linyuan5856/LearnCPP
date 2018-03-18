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

- 整型 `char,short,int,long,long long`
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
