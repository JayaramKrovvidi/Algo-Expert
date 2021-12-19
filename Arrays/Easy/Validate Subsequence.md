## Validate Subsequence:

Given two non-empty arrays of integers, write a function that determines whether the second array is a subsequence of the first one.

A subsequence of an array is a set of numbers that aren't necessarily adjacent in the array but that are in the same order as they appear in the array. For instance, the numbers [1, 3, 4] form a subsequence of the array [1, 2, 3, 4], and so do the numbers [2, 4]. Note that a single number in an array and the array itself are both valid subsequences of the array.

---

### Sample Input:

```cpp
array = [5, 1, 22, 25, 6, -1, 8, 10]
sequence = [1, 6, -1, 10]
```

### Sample Output:

```cpp
true
```

---

## Hints:

> 1. You can solve this question by iterating through the main input array once.
>
> ---
>
> 2. Iterate through the main array, and look for the first integer in the potential subsequence. If you find that integer, keep on iterating through the main array, but now look for the second integer in the potential subsequence. Continue this process until you either find every integer in the potential subsequence or you reach the end of the main array.
>
> ---
>
> 3. To actually implement what Hint #2 describes, you'll have to declare a variable holding your position in the potential subsequence. At first, this position will be the 0th index in the sequence; as you find the sequence's integers in the main array, you'll increment the position variable until you reach the end of the sequence.

<br/>

### Optimal Space & Time Complexity:

```
    O(n) time | O(1) space - where n is the length of the array
```

<br/>

## Solution:

```cpp
#include <vector>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
	int s_arr = array.size();
	int s_seq = sequence.size();
	if(s_seq > s_arr) {
		return false;   // Subsequence cannot be longer than orig array
	}

	int i=0, j=0;
	while (i<s_arr && j<s_seq) {    //break if you reach any end
		while(array[i] != sequence[j]) {
			i++;
		}
		i++;j++;
	}

	if(j==s_seq && i<=s_arr) {
		return true;
	}

  return false;
}
```

## <center>Test Case 1</center>

```json
{
  "array": [5, 1, 22, 25, 6, -1, 8, 10],
  "sequence": [5, 1, 22, 25, 6, -1, 8, 10]
}
```

## <center>Test Case 2</center>

```json
{
  "array": [5, 1, 22, 25, 6, -1, 8, 10],
  "sequence": [5, 1, 22, 6, -1, 8, 10]
}
```

## <center>Test Case 3</center>

```json
{
  "array": [5, 1, 22, 25, 6, -1, 8, 10],
  "sequence": [5, 1, 22, 10]
}
```

## <center>Test Case 4</center>

```json
{
  "array": [5, 1, 22, 25, 6, -1, 8, 10],
  "sequence": [25]
}
```

## <center>Test Case 5</center>

```json
{
  "array": [5, 1, 22, 25, 6, -1, 8, 10],
  "sequence": [5, 1, 22, 25, 6, -1, 8, 10, 12]
}
```
