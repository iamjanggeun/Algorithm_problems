#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int a[10001];
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	double max_score = *max_element(a, a + N);
	double new_score[1001];
	double sum = 0;

	for (int i = 0; i < N; i++) {
		new_score[i] = (a[i]/max_score)*100;
	}

	for (int i = 0; i < N; i++)
	{
		sum += new_score[i];
	}

	double answer = sum / N;

	cout << answer;
}