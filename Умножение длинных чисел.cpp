// Умножение длинных чисел Погнаев Д.С.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

/*int ddd(int x, int y) {
	int res = 0;
	for (int i = 0; i < y; i++) {
		res += x;
	}
	return res;
}*/ //это по сути получилось обычное умножение ((((

int main() //Это конечная версия и я не понимаю, что я делаю не так :с
{
    setlocale(LC_ALL, "Russian");

	typedef std::vector<int> lnum;
	const int base = 1000 * 1000 * 1000;

	std::vector <int> a{2,1};// Ввод чисел, пока так
	std::vector <int> b{2,1};

	lnum c(a.size() + b.size());
	for (size_t i = 0; i < a.size(); ++i)
		for (int j = 0, carry = 0; j < (int)b.size() || carry; ++j) {
			long long cur = c[i + j] + a[i] * 1ll * (j < (int)b.size() ? b[j] : 0) + carry;
			c[i + j] = int(cur % base);
			carry = int(cur / base);
		}
	while (c.size() > 1 && c.back() == 0)
		c.pop_back();

	for (int r = 0;r<c.size();r++) {
		std::cout << c[r];
	}
	std::cout<<std::endl;
	system("pause");
}
