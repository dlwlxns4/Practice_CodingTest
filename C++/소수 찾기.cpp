#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

bool IsPrime(int n) {
	if (n < 2) return false;

	// 에라토스테네스의 체
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0) return false;

	return true;
}



int solution(string numbers) {
	int answer = 0;
	vector<char> ch;
	vector<int> num;



	for (int i = 0; i < numbers.size(); i++) {
		ch.push_back(numbers[i]);
	}

	sort(ch.begin(), ch.end());

	do {
		string str = "";
		for (int i = 0; i < ch.size(); i++) {
			str += ch[i];
			cout << stoi(str) << endl;;
			num.push_back(stoi(str));
		}
	} while (next_permutation(ch.begin(), ch.end()));

	sort(num.begin(), num.end());
	num.erase(unique(num.begin(), num.end()), num.end());
	cout << endl;

	for (int i = 0; i < num.size(); i++) {
		cout << num[i] << endl;
		if (IsPrime(num[i]))
			answer++;
	}

	return answer;
}