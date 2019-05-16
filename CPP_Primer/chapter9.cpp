#include <iostream>
#include <vector>

using namespace std;
//vector,deque,list,forward_list,arrary,string  常用容器

void foo()
{
    vector<int> c = {1314, 2468, 9988};
    c.push_back(1);
    c.push_back(2);

    cout << c.front() << endl;
    cout << c.back() << endl;
    cout << c.capacity() << endl;
    cout << c.size() << endl;

    cout << "....." << endl;
    for (int &v : c)
    {
        cout << v << endl;
    }
}

void foo2_Iterator()
{
    vector<string> strs = {"love", "super", "Link", "C++"};

    auto begin = strs.cbegin();

    while (begin != strs.end())
    {
        cout << (*begin).c_str() << endl;
        ++begin;
    }
}

void foo3_init()
{

    vector<string> strs(10, "love c++");

    for (auto &s : strs)
    {
        cout << s.c_str() << endl;
    }
}

int main(int argc, char **argv)
{
    //foo();
    //foo2_Iterator();
    foo3_init();

    return 0;
}