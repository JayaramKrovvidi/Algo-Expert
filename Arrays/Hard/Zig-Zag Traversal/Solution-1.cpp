#include <bits/stdc++.h>
using namespace std;

bool isDiagUp(int x, int y, int m) {
	if ((x - 1) >= 0 && (y + 1) < m)
		return true;
	return false;
}

bool isRight(int x, int y, int m) {
	if ((y + 1) < m)
		return true;
	return false;
}

bool isDown(int x, int y, int n) {
	if ((x + 1) < n)
		return true;
	return false;
}

bool isDiagDown(int x, int y, int n, int m) {
	if ((x + 1) < n && (y - 1) >= 0)
		return true;
	return false;
}

vector<int> zigzagTraverse(vector<vector<int>> array) {
	int n = array.size();
	int m = array[0].size();
	int x = 0, y = 0;
	bool up = false;
	vector<int> out;
	while (x != n - 1 || y != m - 1) {
		out.push_back(array[x][y]);
		if (up) {
			if (isDiagUp(x, y, m)) {
				x--; y++;
			} else if (isRight(x, y, m)) {
				y++; up = false;
			} else if (isDown(x, y, n)) {
				x++; up = false;
			}
		} else {
			if (isDiagDown(x, y, n, m)) {
				x++; y--;
			} else if (isDown(x, y, n)) {
				x++; up = true;
			} else if (isRight(x, y, m)) {
				y++; up = true;
			}
		}
	}
	out.push_back(array[x][y]);
	return out;
}