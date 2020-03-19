#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include <cmath>
#include <numeric>
int main()
{
	//1 Создала последовательность целых чисел от 1 до 10 
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	
	//2 Добавила еще несколько элементов через cin 
	std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::inserter(v, v.end()));

	//3 Перемешала V случайным образом 
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(v.begin(), v.end(), g);

	//4 Удалила дубликаты из V
	std::sort(v.begin(), v.end());
	auto last = std::unique(v.begin(), v.end());
	v.erase(last, v.end());
	std::cout << "Delete duplicates     ";
		for (int i = 0; i < v.size(); i++)
		{
			std::cout << v[i] << std::endl;
		}

	//5 Подсчитала количество нечетных в V
		int count = std::count_if(v.begin(), v.end(), [](int x) {
			return x % 2;
			});
	std::cout << "Сount if 2N + 1     ";
	std::cout << count << std::endl;

	//6 Определила минимальное и максимальное значение в V 
	auto result = std::max_element(v.begin(), v.end());
	int max = *result;
	std::cout << "MAX    ";
	std::cout << max << std::endl;
	auto result2 = std::min_element(v.begin(), v.end());
	std::cout << "MIN      ";
	std::cout << *result2 << std::endl;

	//7 Нашла хотя бы одно простое число 
	auto result1 = std::find_if(v.begin(), v.end(), [](auto x) {
		int l = 0;
		for (int i = 2; i < x - 1; i++) {
			float k = x / i;
			if (k == int(k)) {
				l += 1;
			}
		}
		if (l >= 1) {
			return false;
		}
		else {
			return true;
		}
		});
	if (result1 != v.end() {
		std::cout << "SIMPLE COUNT:      ";
		std::cout << *result1<< std::endl;
	}
	else {
		std::cout << "Not found simple count    ";
	}

	//8 Заменила все числа в V их квадратами 
	std::transform(v.begin(), v.end(), v.begin(), [](auto x) {
		return x * x ;

	});

	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}

	//9 Создала последовательность V2 из N случайных чисел, где N - длина V
	std::vector<int> v2;
	for (int i = 0; i < v.size(); i++) {

		v2.push_back(rand());
	}
	for (int i = 0; i < v2.size(); i++)
	{
		std::cout << v2[i] << std::endl;
	}

	//10 Вычислила сумму чисел в V2 
	int sum = std::accumulate(v2.begin(), v2.end(), 0);
	std::cout << sum << std::endl;

	//11 Заменила первые несколько чисел в V2 числом 1 
	std::fill_n(v2.begin(), 3, 1);
	std::cout << " Bla la "<< std::endl;
	for (int i = 0; i < v2.size(); i++)
	{
		std::cout << v2[i] << std::endl;
	}

	//12 Создала последовательность V3 как разность V и V2 
	std::vector<int> v3;
	v3.resize(v.size());
	std::transform(v.begin(), v.end(), v2.begin(), v3.begin(), [](auto x , auto y) {
		return x - y;	
	});
	for (int i = 0; i < v3.size(); i++)
	{
		std::cout << v3[i] << std::endl;
	}

	//13 Заменила каждый отрицательный элемент в V3 
	std::replace_if(v3.begin(), v3.end(), [](auto x) {
		if (x < 0)
		{
			return true;
		}
		else
		{
			return false;
		}
		}, 0);
	std::cout << "Nana" << std::endl;
	for (int i = 0; i < v3.size(); i++)
	{
		std::cout << v3[i] << std::endl;
	}

	//14 Удалила полностью все нулевые элементы в V3 
	auto last2 = std::remove(v3.begin(), v3.end(), 0);
	v3.erase(last2, v3.end());
	for (int i = 0; i < v3.size(); i++)
	{
		std::cout << v3[i] << std::endl;
	}

	//15 Изменила порядок следования в V3 на обратный 
	std::reverse(std::begin(v3), std::end(v3));
	for (int i = 0; i < v3.size(); i++)
	{
		std::cout << v3[i] << std::endl;
	}

	//16 Определила топ-3 элемента в V3 
	std::nth_element(v3.begin(), std::next(v3.begin(), 2), v3.end(), std::greater<int>());
	for (int i = 0; i < v3.size(); i++) {
		std::cout << v3[i] << std::endl;
	}

	//17 Отсортировала V и V2 по возрастанию 
	std::sort(v.begin(), v.end());
	std::sort(v2.begin(), v2.end());

	//18 Создала последовательность V4 как слияние V и V2 
	std::vector<int> v4;
	v4.resize(v.size());
	std::merge(v.begin(), v.end(), v2.begin(), v2.end(), std::back_inserter(v4));
	std::copy(v4.begin(), v4.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << '\n';

	//19 Определила диапазон для упорядоченной вставки числа 1 в V4 

	auto p = std::equal_range(v4.begin(), v4.end(), 1);
	for (auto i = p.first; i != p.second; i++) {
		std::cout << *i << std::endl;
	}

	//20 Вывела все последовательности в cout 
	std::cout << "v : " << std::endl;
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
	//std::cout << "v5 : " << std::endl;
	//std::copy(v5.begin(), v5.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << '\n';
	system("pause");

}




