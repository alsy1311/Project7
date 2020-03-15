#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include <cmath>
bool p(int x);
bool p1(int x1);
int square(int x2);
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
	std::cout << "Delete duplicates     ";
		for (int i = 0; i < v.size(); i++)
		{
			std::cout << v[i] << std::endl;
		}
	int count = std::count_if(v.begin(), v.end(), p);
	std::cout << "Ñount if 2N + 1     ";
	std::cout << count << std::endl;
	std::vector<int>::iterator result;
	result = std::max_element(v.begin(), v.end());
	int max = v[std::distance(v.begin(), result)];
	std::cout << "MAX    ";
	std::cout << max << std::endl;
	std::vector<int>::iterator result2;
	result2 = std::min_element(v.begin(), v.end());
	int min = v[std::distance(v.begin(), result2)];
	std::cout << "MIN      ";
	std::cout << min << std::endl;
	auto result1 = std::find_if(v.begin(), v.end(), p1);
	if ((result1 != v.end())||(p1(v.back()) == true)) {
		int foundEl = v[std::distance(v.begin(), result1)];
		std::cout << "SIMPLE COUNT:      ";
		std::cout << foundEl << std::endl;
	}
	else {
		std::cout << "Not found simple count    ";
	}
	std::transform(v.begin(), v.end(),v.begin(), square);

	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}
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
bool p1(int x) 
{
	int l = 0;
	for (int i = 2; i < x - 1; i++) {
		float k = x / i;
		if (k == int(k)) {
			l += 1;
		}
	}
	if (l >= 1){
		return false;
	}
	else {
		return true;
	}
}
 int square(int x)
{
	return x = x * x;
	//return h;
}


