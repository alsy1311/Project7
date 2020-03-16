#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include <cmath>
#include <numeric>
bool p(int x);
bool p1(int x1);
int square(int x2);
int subtraction(int x, int y);
bool ziro(int x);
bool p2(int x);
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
	std::vector<int> v2;
	for (int i = 0; i < v.size(); i++) {

		v2.push_back(rand());
	}
	for (int i = 0; i < v2.size(); i++)
	{
		std::cout << v2[i] << std::endl;
	}
	int sum = std::accumulate(v2.begin(), v2.end(), 0);
	std::cout << sum << std::endl;
	std::fill_n(v2.begin(), 3, 1);
	for (int i = 0; i < v2.size(); i++)
	{
		std::cout << v2[i] << std::endl;
	}
	std::vector<int> v3;
	v3.resize(v.size());
	std::transform(v.begin(), v.end(), v2.begin(), v3.begin(), subtraction);
	std::replace_if(v3.begin(), v3.end(), ziro, 0);
	auto last2 = std::remove(v3.begin(), v3.end(), 0);
	//v3.erase(last2, v3.end());
	for (int i = 0; i < v3.size(); i++)
	{
		std::cout << v3[i] << std::endl;
	}
	std::reverse(std::begin(v3), std::end(v3));
	for (int i = 0; i < v3.size(); i++)
	{
		std::cout << v3[i] << std::endl;
	}
	
	std::nth_element(v3.begin(), std::next(v3.begin(), 3), v3.end(), std::greater<int>());
	for (int i = 0; i < 3; i++) {
		std::cout << v3[i] << std::endl;
	}
	std::sort(v.begin(), v.end());
	std::sort(v2.begin(), v2.end());
	std::vector<int> v4;
	v4.resize(v.size());
	std::merge(v.begin(), v.end(), v2.begin(), v2.end(), std::back_inserter(v4));
	std::copy(v4.begin(), v4.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << '\n';
	std::vector<int> v5;
	v5.resize(v4.size());
	std::remove_copy_if(v4.begin(), v4.end(),v5.begin(), p2);
	std::cout << "v : "<< std::endl;
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << '\n';
	std::cout << "v2 : " << std::endl;
	std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << '\n';
	std::cout << "v3 : " << std::endl;
	std::copy(v3.begin(), v3.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << '\n';
	std::cout << "v4 : " << std::endl;
	std::copy(v4.begin(), v4.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << '\n';
	std::cout << "v5 : " << std::endl;
	std::copy(v5.begin(), v5.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << '\n';
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
	return x * x;
}
 int subtraction(int x, int y) {
	 return x - y;
 }
 bool ziro(int x) {
	 if (x < 0)
	 {
		 return true;
	 }
	 else
	 {
		 return false;
	 }
 }
 bool p2(int x ) {
	 if (x <= 1) {
		 return false ;
	 }
	 else
	 {
		 return true;
	 }

 }


