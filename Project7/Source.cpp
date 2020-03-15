#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include <cmath>
bool p(int x);
int main()
{

	std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	for (int t = 0; t < 3; t++) {
		int l = 0;
		std::cin >> l;
		std::fill_n(std::back_inserter(v), 1, l);
	}

	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(v.begin(), v.end(), g);
	std::sort(v.begin(), v.end());
	auto last = std::unique(v.begin(), v.end());
	v.erase(last, v.end());
		for (int i = 0; i < v.size(); i++)
		{
			std::cout << v[i] << std::endl;
		}
		int count = std::count_if(v.begin(), v.end(), p);
		std::cout << count << std::endl;
		std::vector<int>::iterator result;
		result = std::max_element(v.begin(), v.end());
		int max = v[std::distance(v.begin(), result)];
		std::cout << max << std::endl;
		std::vector<int>::iterator result2;
		result2 = std::min_element(v.begin(), v.end());
		int min = v[std::distance(v.begin(), result2)];
		std::cout << min << std::endl;
		system("pause");

}
bool p(int x)
{
	if (x % 2 != 0) {
		return true;
	}
	else {
		return false;
	}
}


