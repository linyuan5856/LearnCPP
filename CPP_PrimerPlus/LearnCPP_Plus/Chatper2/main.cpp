#include <iostream>

void chapter1_helloWorld()
{
	std::cout << "Hello World" << std::endl;
	std::cin.get();
}

void chapter3_FLoat()
{
	using namespace  std;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	float tub = 10.0 / 3.0; //6位精度
	double mint = 10.0 / 3.0;//15位精度
	const float million = 1.0e6;

	cout << "tub=" << tub;//3.3333333
	cout << ",a million tubs=" << million * tub;//3333333.250000 float精度限制
	cout << ",\nand ten million tubs=";
	cout << 10 * million*tub << endl;//33333332.000000

	cout << "mint=" << mint << " and a million mints=";//3.333333
	cout << million * mint << endl;//3333333.333333
	cin.get();
}

void chapter4_Arrary()
{
	float foods[] = { 2,3,4 };
	short things[5]= { 20,30 };
	std::cout << things[3]<<std::endl;
	std::cout << things[1] << std::endl;
	//C++ 11 初始化方式
	double ds[50]{};
	int nums[20] = {};
	std::cin.get();
	
}

void Chapter4_String()
{
	char names[] = "name is Lin";
	std::cout << sizeof(names) << std::endl;
	std::cout << strlen(names) << std::endl;

	std::cin.get();

}

int  main()
{
	//chapter1_helloWorld();
	//chapter3_FLoat();
	//chapter4_Arrary();
	Chapter4_String();
	return 0;
}

