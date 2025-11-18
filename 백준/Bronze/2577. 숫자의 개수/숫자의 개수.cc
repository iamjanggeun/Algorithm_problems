#include <iostream>
#include <string>

using namespace std;

int freq[10];

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	long long result = A * B * C;
	string s = to_string(result);

	for (auto c : s) freq[c - '0']++;
	for (int i = 0; i < 10; i++) cout << freq[i] << "\n";

	return 0;
}