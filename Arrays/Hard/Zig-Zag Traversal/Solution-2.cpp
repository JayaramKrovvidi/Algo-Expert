#include <bits/stdc++.h>
using namespace std;

vector<int> flattenMap(map<int, vector<int>> seq) {
	vector<int> out;
	for (auto it : seq) {
		for (int i : it.second) {
			out.push_back(i);
		}
	}
	return out;
}

vector<int> zigzagTraverse(vector<vector<int>> array) {
	int m = array.size();
	int n = array[0].size();
	map<int, vector<int>> seq;

	for (int i = 0; i < m + n - 1; i++) {
		seq.insert(pair<int, vector<int>>(i, {}));
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if ((i + j) % 2 == 0) {
				seq[i + j].push_back(array[i][j]);
			} else {
				seq[i + j].insert(seq[i + j].begin(), array[i][j]);
			}
		}
	}
	return flattenMap(seq);
}