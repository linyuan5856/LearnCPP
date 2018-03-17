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
