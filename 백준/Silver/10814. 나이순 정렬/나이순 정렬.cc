#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Person{
	int age;
	string name;
	int index;
};

bool compare(const Person& a, const Person& b)
{
	if (a.age == b.age) return a.index < b.index;
	return a.age < b.age;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<Person> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i].age >> v[i].name;
		v[i].index = i;
	}

	sort(v.begin(), v.end(), compare);

	for (auto e : v)
		cout << e.age << " " << e.name << "\n";
}