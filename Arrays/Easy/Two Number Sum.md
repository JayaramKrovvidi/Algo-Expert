## Two Number Sum

Write a function that takes in a non-empty array of distinct integers and an integer representing target sum. If any two numbers in the input array sum up to the target sum, the function should return them in an array, in any order. If no two numbers sum up to the target sum, the function should return an empty array.

Note that the target sum has to be obtained by summing two different integers in the array; you can't add a single integer to itself in order to obtain the target sum.

You can assume that there will be at most one pair of numbers summing up to the target sum.

<br/>

---

### Sample Input:

```cpp
    array = [3, 5, -4, 8, 11, 1, -1, 6]
    targetSum = 10
```

### Sample Output:

```cpp
    [-1, 11] // the numbers could be in reverse order
```

<br/>

---

## Hints:

> 1. Try using two for loops to sum all possible pairs of numbers in the input array. What are the time and space implications of this approach?
>
> ---
>
> 2. Realize that for every number X in the input array, you are essentially trying to find a corresponding number Y such that X + Y = targetSum. With two variables in this equation known to you, it shouldn't be hard to solve for Y.
>
> ---
>
> 3. Try storing every number in a hash table, solving the equation mentioned in Hint #2 for every number, and checking if the Y that you find is stored in the hash table. What are the time and space implications of this approach?

<br/>

### Optimal Space & Time Complexity:

```
    O(n) time | O(n) space - where n is the length of the input array
```

## Solution:

```cpp
#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  set<int> complements;
	for(int i : array) {
		if(complements.find(i) != complements.end()) {
			return {i, targetSum-i};
		}
		complements.insert(targetSum-i);
	}
  return {};
}
```

## <center>Test Case 1</center>

```json
{
  "array": [-21, 301, 12, 4, 65, 56, 210, 356, 9, -47],
  "targetSum": 164
}
```

## <center>Test Case 2</center>

```json
{
  "array": [4, 6],
  "targetSum": 10
}
```

## <center>Test Case 3</center>

```json
{
  "array": [4, 6, 1],
  "targetSum": 5
}
```

## <center>Test Case 4</center>

```json
{
  "array": [4, 6, 1, -3],
  "targetSum": 3
}
```

## <center>Test Case 5</center>

```json
{
  "array": [1, 2, 3, 4, 5, 6, 7, 8, 9],
  "targetSum": 17
}
```
