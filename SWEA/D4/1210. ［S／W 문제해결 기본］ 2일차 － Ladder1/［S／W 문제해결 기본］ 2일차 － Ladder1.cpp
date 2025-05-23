#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int map[100][100];

	for (int test_case = 1; test_case <= 10; test_case++)
	{
		int case_num;
		cin >> case_num;

		// 입력
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				cin >> map[i][j];

		// 도착지점(2)의 좌표 찾기
		int x = 99, y = 0;
		for (int j = 0; j < 100; j++) {
			if (map[99][j] == 2) {
				y = j;
				break;
			}
		}

		// 위로 올라가기
		while (x > 0) {
			// 왼쪽 확인
			if (y > 0 && map[x][y - 1] == 1) {
				while (y > 0 && map[x][y - 1] == 1) y--;
			}
			// 오른쪽 확인
			else if (y < 99 && map[x][y + 1] == 1) {
				while (y < 99 && map[x][y + 1] == 1) y++;
			}
			// 위로 이동
			x--;
		}

		cout << "#" << test_case << " " << y << "\n";
	}
}