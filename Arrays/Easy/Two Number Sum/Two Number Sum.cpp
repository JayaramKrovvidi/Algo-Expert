#include <bits/stdc++.h>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
    set<int> complements;
    for (int i : array) {
        if (complements.find(i) != complements.end()) {
            return { i, targetSum - i };
        }
        complements.insert(targetSum - i);
    }
    return {};
}