#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
int main()
{
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	for (int t = 0; t < 3; t++) {
		int l = 0;
		std::cin >> l;
		std::fill_n(std::back_inserter(v), 1, l);
	}
	/*for (int i = 0; i < 13; i++)
	{
		std::cout << v[i] << std::endl;
	}
	*/
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(v.begin(), v.end(), g);
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}
	system("pause");
}
