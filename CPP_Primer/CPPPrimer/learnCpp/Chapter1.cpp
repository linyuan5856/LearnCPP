#include <iostream>
using namespace std;




int main() {
	std::cout << "hello world " << std::endl;
	int v1, sum, sum2;
	std::cin >> v1;

	//×¢ÊÍ1 Hello World

	/*
	×¢ÊÍ2 Hello WOrld
	*/

	v1 = 10;
	sum = 0;
	sum2 = 0;
	while (v1 > 0)
	{
		v1--;
		sum += 2;
	}

	std::cout << "Total Sum->" << sum << std::endl;


	for (int i = 0; i < 100; i++)
	{
		sum2 += 1;
	}

	std::cout << "Total Sum2->" << sum2 << std::endl;

	std::cin >> v1;
	return 0;
}