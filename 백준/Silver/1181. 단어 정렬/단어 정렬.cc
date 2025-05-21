#include <bits/stdc++.h>

using namespace std;

int compare(string a, string b);

int main(void)
{
	int N;
	cin >> N;
	cin.ignore();

	vector<string> v;

	for (int i = 0; i < N; i++)
	{
		string word;
		getline(cin, word);
		v.push_back(word);
	}

	sort(v.begin(), v.end(), compare);
	v.erase(unique(v.begin(), v.end()), v.end());

	for (auto e : v) cout << e << "\n";

}

int compare(string a, string b)
{
	if (a.length() == b.length())
	{
		return a < b;
	}
	else return a.length() < b.length();
}