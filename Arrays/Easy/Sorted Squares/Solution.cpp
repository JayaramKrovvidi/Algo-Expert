#include<bits/stdc++.h>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
    int n = array.size();
    int i = 0, j = n - 1;
    vector<int> out;

    // Iterate from both sides, till the indexes cross each other.
    // Insert the biggest square into the array and change indices.
    while (i <= j) {
        int sq_i = array[i] * array[i];
        int sq_j = array[j] * array[j];
        out.insert(out.begin(), max(sq_i, sq_j));
        (sq_j >= sq_i) ? j-- : i++;
    }
    return out;
}