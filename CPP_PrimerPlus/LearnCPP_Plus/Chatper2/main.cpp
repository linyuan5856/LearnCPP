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

void Chapter4_Pointer()
{
	
	using namespace  std;
	double num = 52.30;
	int id = 32;

	cout << "num Value->" << num << endl;//53.2
	cout << "num pointer->" << &num << endl;//006FFA44

	cout << "id Value->" << id << endl;//53.2
	cout << "id pointer->" << &id << endl;//006FFA38

	cin.get();
}

void Chapter4_ArraryWithNew()
{
	using namespace std;
	int*psome = new int[4];
	psome[0] = 1;
	psome[1] = 3;
	psome[2] = 5;
	psome[3] = 7;

	cout << *psome << endl;
	cout << psome[0] << endl;

	psome = psome + 1;
	cout << "new pSome[0] ->  " << *psome << endl;
	psome = psome - 1;
	cout << "Back To Old pSome[0]  ->  " << *psome << endl;


	delete[]psome;
	cin.get();
}

void Chapter4_StringPointer()
{
		using namespace std;
		char animals[5] = "duck";
		const char*bird = "tom";

		cout << animals << endl;//duck
		cout << bird << endl;//tom

		cin.get();
}

void Chapter4_NewStruct()
{
	using namespace std;
	struct things {
		int id;
		const char* describe;
	}coat;

	coat = { 1,"i am a coat" };
	things *p_coat = &coat;

	cout << p_coat->id << endl;//1

	things *any = new things;
	(*any).id = 9527;
	any->describe = "i am 9527";

	cout << any->id << endl;
	cout << (*any).describe << endl;
	cin.get();

	delete any;
}

int  main()
{
	//chapter1_helloWorld();
	//chapter3_FLoat();
	//chapter4_Arrary();
	//Chapter4_String();
	//Chapter4_Pointer();
	//Chapter4_ArraryWithNew();
	//Chapter4_StringPointer();
	Chapter4_NewStruct();
	return 0;
}

