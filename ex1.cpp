#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <ctime>

using namespace std;

void prime_divisors(vector<int> &numbers, map<int, vector<int>> &data);
void print_map(const map<int, vector<int>> &data);

int main()
{
	srand(time(0));

	int N = 1 + rand() % 1500;
	vector<int> numbers;
	map<int, vector<int>> data;
	for (int i = 1; i <= N; ++i){
		numbers.push_back(i);
	}

	prime_divisors(numbers, data);
	print_map(data);

	system("pause");
	return 0;
}

void print_map(const map<int, vector<int>> &data)
{
	for (auto& n : data) {
		cout << n.first << ": ";
		for (auto& list : n.second) {
			cout << list << " ";
		}
		cout << endl;
	}
}

void prime_divisors(vector<int> &numbers, map<int, vector<int>> &data)
{
	for (auto& n : numbers) {
		int num = n;
		if (n <= 1) {
			data[num].push_back(n);
		}
		else {
			int t = sqrt(n);
			int k = 2;
			while (k <= t) {
				if (!(n%k)) {
					n /= k;
					data[num].push_back(k);
					while (!(n%k)) {
						n /= k;
						data[num].push_back(k);
					}
					t = sqrt(n);
				}
				k++;
			}
			if (n > 1)
				data[num].push_back(n);
		}
	}
}