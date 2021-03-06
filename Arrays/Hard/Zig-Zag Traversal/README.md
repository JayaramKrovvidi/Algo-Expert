## Zig-Zag Traversal:

Write a function that takes in an n x m two-dimensional array (that can be square-shaped when n == m) and returns a one-dimensional array of all the array's elements in zigzag order.

Zigzag order starts at the top left corner of the two-dimensional array, goes down by one element, and proceeds in a zigzag pattern all the way to the bottom right corner.

---

### Sample Input:

```cpp
array = [
  [1,  3,  4, 10],
  [2,  5,  9, 11],
  [6,  8, 12, 15],
  [7, 13, 14, 16],
]
```

![Zig Zag](https://i.ibb.co/RDYtQZZ/zigzag.png)

### Sample Output:

```cpp
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
```

---

## Hints:

> 1. Don't overthink this question by trying to come up with a clever way of getting the zigzag order. Think about the simplest checks that need to be made to decide when and how to change direction throughout the zigzag traversal.
>
> ---
>
> 2. Starting at the top left corner, iterate through the two-dimensional array by keeping track of the direction that you're moving in (up or down). If you're moving up, you know that you need to move in an up-right pattern and that you need to handle the case where you hit the top or the right borders of the array. If you're moving down, you know that you need to move in a down-left pattern and that you need to handle the case where you hit the left or the bottom borders of the array.
>
> ---
>
> 3. When going up, if you hit the right border, you'll have to go down one element; if you hit the top border, you'll have to go right one element. Similarly, when going down, if you hit the left border, you'll have to go down one element; if you hit the bottom border, you'll have to go right one element.

<br/>

### Optimal Space & Time Complexity:

```
    O(n) time | O(n) space - where n is the total number of elements in the two-dimensional array
```

<br/>

## Solution 1: (Manually travel in the array with changing directions)

```cpp
#include <vector>
using namespace std;

bool isDiagUp(int x, int y, int m) {
	if((x-1) >= 0 && (y+1) < m)
		return true;
	return false;
}

bool isRight(int x, int y, int m) {
	if((y+1) < m)
		return true;
	return false;
}

bool isDown(int x, int y, int n) {
	if((x+1) < n)
		return true;
	return false;
}

bool isDiagDown(int x, int y, int n, int m) {
	if((x+1) < n && (y-1) >= 0)
		return true;
	return false;
}

vector<int> zigzagTraverse(vector<vector<int>> array) {
  int n = array.size();
	int m = array[0].size();
	int x =0, y = 0;
	bool up = false;
	vector<int> out;
	while(x != n-1 || y != m-1) {
		out.push_back(array[x][y]);
		if(up) {
			if(isDiagUp(x,y,m)) {
				x--; y++;
			} else if (isRight(x,y,m)) {
				y++; up = false;
			} else if (isDown(x,y,n)) {
				x++; up = false;
			}
		} else {
			if(isDiagDown(x,y,n,m)) {
				x++; y--;
			} else if (isDown(x,y,n)) {
				x++; up = true;
			} else if (isRight(x,y,m)) {
				y++; up = true;
			}
		}
	}
	out.push_back(array[x][y]);
  return out;
}
```

## Solution 2: (Create a map with all the possible diagonals (m+n-1) and print them)

```cpp
#include <vector>
using namespace std;

vector<int> flattenMap(map<int, vector<int>> seq) {
	vector<int> out;
	for(auto it : seq) {
		for(int i : it.second){
			out.push_back(i);
		}
	}
	return out;
}

vector<int> zigzagTraverse(vector<vector<int>> array) {
	int m = array.size();
	int n = array[0].size();
  	map<int, vector<int>> seq;

	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			if((i+j)%2 == 0) {
				seq[i+j].push_back(array[i][j]);
			} else {
				seq[i+j].insert(seq[i+j].begin(), array[i][j]);
			}
		}
	}
  	return flattenMap(seq);
}
```

## <center>Test Case 1</center>

```json
{
  "array": [[1]]
}
```

## <center>Test Case 2</center>

```json
{
  "array": [[1, 2, 3, 4, 5]]
}
```

## <center>Test Case 3</center>

```json
{
  "array": [[1], [2], [3], [4], [5]]
}
```

## <center>Test Case 4</center>

```json
{
  "array": [
    [1, 3],
    [2, 4],
    [5, 7],
    [6, 8],
    [9, 10]
  ]
}
```

## <center>Test Case 5</center>

```json
{
  "array": [
    [1, 3, 4, 7, 8],
    [2, 5, 6, 9, 10]
  ]
}
```
