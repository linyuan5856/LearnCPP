#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void foo1()
{

    cout << unitbuf;
    cout << "1";
    cout << nounitbuf;
    cout << "2";
    cout << "3" << endl; //+换行后 刷新缓冲区
    cout << "4";
    cout << "5" << flush; //仅仅刷新缓冲区
    cout << "6" << ends;  //+1个空字符 刷新缓冲区
    cout << "7";

    cin.tie(&cout); //绑定流
    char *str;
    cin >> str;
}

struct Data
{
    std::string name;
    unsigned int id;
    double value;
};

istream &read(istream &is, Data &data)
{
    string str;
    is >> str;
    int lastIndex = -1;
    int last=str.length();
    cout<<str<<endl;

    data.id = str[0];
    data.name = str[1];
    data.value = str[2];
    return is;
}

ostream &print(ostream &os, const Data &data)
{
    os << data.id << endl
       << data.name << endl
       << data.value;
    return os;
}

void foo2()
{
    Data data;
    string openfileName = "test.txt";
    string saveFileName = "testout.txt";
    ifstream input(openfileName);
    ofstream output(saveFileName);

    if (!input)
    {
        cerr << "can't open FILE->  " << openfileName << endl;
    }

    while (read(input, data))
    {
    }
    // cout << data.name << endl;
    // cout << data.id << endl;
    //cout << data.value << endl;
    print(output, data);

    input.close();
    output.close();
    //文件模式 1.in 2.out 3.app（每次写操作前定位到文件末尾） 4.ate（打开后定位到文件末尾） 5.trunc(清空) 6.binary
    //eg. ofstream out; out.open("fileName",ofstream::app);
}

int main(int argc, char **argv)
{

    //foo1();
    foo2();
    return 0;
}