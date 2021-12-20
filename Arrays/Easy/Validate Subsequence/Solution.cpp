#include <vector>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
    int s_arr = array.size();
    int s_seq = sequence.size();
    if (s_seq > s_arr) {
        return false;   // Subsequence cannot be longer than orig array
    }

    int i = 0, j = 0;
    while (i < s_arr && j < s_seq) {    //break if you reach any end
        while (array[i] != sequence[j]) {
            i++;
        }
        i++;j++;
    }

    if (j == s_seq && i <= s_arr) {
        return true;
    }

    return false;
}