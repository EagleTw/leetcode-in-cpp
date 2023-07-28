# Ypaskell's Leetcode Cheatsheet

Useful links

- [GitHub - WisdomPeak](https://github.com/wisdompeak/LeetCode)
- [Googele OA](https://leetcode.com/discuss/interview-question/352460/Google-Online-Assessment-Questions)

```text
This is a personal note mainly in C++
Please give me a star if you think there is something useful.
```

<!-- vscode-markdown-toc -->

- 1. [Array & Two Pointer & Sliding window & Stacks](#ArrayTwoPointerSlidingwindowStacks)
  - 1.1. [Good-to-know algorithm or techniques](#Good-to-knowalgorithmortechniques)
    - 1.1.1. [Prefix sum](#Prefixsum)
    - 1.1.2. [Counting sort](#Countingsort)
    - 1.1.3. [Boyer-Moore Majority Voting Algorithm](#Boyer-MooreMajorityVotingAlgorithm)
    - 1.1.4. [Write compare function / operator / lamda](#Writecomparefunctionoperatorlamda)
    - 1.1.5. [Ceil() without ceil](#Ceilwithoutceil)
- 2. [Two Pointers and Sliding Window](#TwoPointersandSlidingWindow)
- 3. [Linked list](#Linkedlist)
  - 3.1. [Indirect pointer technique](#Indirectpointertechnique)
- 4. [Bitwise Operation](#BitwiseOperation)
  - 4.1. [Default need-to-know](#Defaultneed-to-know)
  - 4.2. [Builtin usefull bitwise](#Builtinusefullbitwise)
- 5. [Binary Search](#BinarySearch)
- 6. [Binary Tree](#BinaryTree)
- 7. [Back-Tracking](#Back-Tracking)
- 8. [BFS / DFS / Flood Fill](#BFSDFSFloodFill)
- 9. [Graph](#Graph)
  - 9.1. [矩陣圖模擬](#)
  - 9.2. [Union find (Disjoint Set)](#UnionfindDisjointSet)
  - 9.3. [Topological sort 拓樸排序](#Topologicalsort)
  - 9.4. [Minimum Spanning Trees (MST) 最小生成樹](#MinimumSpanningTreesMST)
  - 9.5. [Shortest Path 最短路问题](#ShortestPath)
  - 9.6. [8.6 連通性問題](#-1)
  - 9.7. [網路流量](#-1)
- 10. [Hash tables](#Hashtables)
- 11. [Dynamic Programming](#DynamicProgramming)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

## 1. <a name='ArrayTwoPointerSlidingwindowStacks'></a>Array & Two Pointer & Sliding window & Stacks

### 1.1. <a name='Good-to-knowalgorithmortechniques'></a>Good-to-know algorithm or techniques

#### 1.1.1. <a name='Prefixsum'></a>Prefix sum

Leetcode:

- 238 product of array except self
- 724 find pivot index

#### 1.1.2. <a name='Countingsort'></a>Counting sort

Leetcode:

- 49. Group Anagrams

```cpp
string strSort(string s) {
  int counter[26] = {0};
  for (char c : s) {
      counter[c - 'a']++;
  }
  string t;
  for (int c = 0; c < 26; c++) {
      t += string(counter[c], c + 'a');
  }
  return t;
}
```

#### 1.1.3. <a name='Boyer-MooreMajorityVotingAlgorithm'></a>Boyer-Moore Majority Voting Algorithm

Finding majority element -- [[YouTube]](https://www.youtube.com/watch?v=n5QY3x_GNDg&t=274s)

#### 1.1.4. <a name='Writecomparefunctionoperatorlamda'></a>Write compare function / operator / lamda

> a, b ---compare---> in compare is true, need swap position

- Compare operator

```cpp
struct compare {
  inline bool operator()(std::vector<int> x, std::vector<int> y) {
    return x[0] < y[0];
  }
};
```

#### 1.1.5. <a name='Ceilwithoutceil'></a>Ceil() without ceil

```cpp
double d;
int intPart = static_cast<int> d;
int ceil = (d > int_part) ? intPart + 1; intPart;
```

or

```cpp
double d;
int ceil = static_cast<int>(d - 1) + 1;
```

- Compare function

```cpp
static inline bool compare(std::vector<int> x, std::vector<int> y) {
  return x[0] < y[0];
}
```

## 2. <a name='TwoPointersandSlidingWindow'></a>Two Pointers and Sliding Window

手法：

1. 兩邊往中間走: 戀人相遇
2. Fast/Slow Pointers

   - Sliding Window: 跛腳走路

3. 兩個 Pointer 速度不一樣


FAANG:

Sliding Window Questions :

- [Average of any contiguous subarray of size k](https://leetcode.com/problems/maximum-average-subarray-i/)
- [Maximum sum of any contiguous subarray of size k](https://leetcode.com/problems/maximum-subarray/)
- [Smallest subarray with a given sum](https://leetcode.com/problems/minimum-size-subarray-sum/)
- [Longest substring with k distinct characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/)
- [Fruits into baskets](https://leetcode.com/problems/fruit-into-baskets/)
- [Longest substring without repeating characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
- [Longest substring after k replacements](https://leetcode.com/problems/longest-repeating-character-replacement/)
- [Permutation in string](https://leetcode.com/problems/permutation-in-string/)
- [String anagrams](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

## 3. <a name='Linkedlist'></a>Linked list

### 3.1. <a name='Indirectpointertechnique'></a>Indirect pointer technique

- [Jserv Linked List](https://hackmd.io/@sysprog/c-linked-list)

## 4. <a name='BitwiseOperation'></a>Bitwise Operation

Links:

- [Jserv-Bitwise-Operation](https://hackmd.io/@sysprog/c-bitwise)
- [利用 LeetCode easy 題目來精通 C++ bitwise](https://steveyang.blog/zh_tw/2022/07/02/leetcode-easy-bitwise-xor-summary/)

### 4.1. <a name='Defaultneed-to-know'></a>Default need-to-know

- Set a bit

```cpp
unsigned char b |= (1 << n);
```

- Clear a bit

```cpp
unsigned char b &= ~(1 << n);
```

- Toodle a bit

```cpp
unsigned char b ^= (1 << n);
```

- Test a bit

```cpp
unsigned char e = d & (1 << n); //d has the byte value.
```

- The right/left most byte
  assuming 16 bit, 2-byte short integer:

```cpp
unsigned char right = val & 0xff; /* right most (least significant) byte */
unsigned char left = (val >> 8) & 0xff; /* left most (most significant) byte */
```

- sign bit
  assuming 16 bit, 2-byte short integer, two’s complement:

```cpp
bool sign = val & 0x8000; // sign bit
```

### 4.2. <a name='Builtinusefullbitwise'></a>Builtin usefull bitwise

- `int __builtin_ffs (int x)` → find first set
  - Returns one plus the index of the least significant 1-bit of x, or if x is zero, returns zero.
- `int __builtin_clz (unsigned int x)` → count leading zero
  - Returns the number of leading 0-bits in x, starting at the most significant bit position. If x is 0, the result is undefined.
- `int __builtin_ctz (unsigned int x)` → count trailing zero
  - Returns the number of trailing 0-bits in x, starting at the least significant bit position. If x is 0, the result is undefined.
- `int __builtin_popcount (unsigned int x)` → population count
  - Returns the number of 1-bits in x.

## 5. <a name='BinarySearch'></a>Binary Search

[[二分搜尋法（Binary Search）完整教學（一）]](https://medium.com/appworks-school/binary-search-%E9%82%A3%E4%BA%9B%E8%97%8F%E5%9C%A8%E7%B4%B0%E7%AF%80%E8%A3%A1%E7%9A%84%E9%AD%94%E9%AC%BC-%E4%B8%80-%E5%9F%BA%E7%A4%8E%E4%BB%8B%E7%B4%B9-dd2cd804aee1) \
[[Lucifer-二分]](https://leetcode-solution-leetcode-pp.gitbook.io/leetcode-solution/thinkings/binary-search-1)

My 整理

- 基本型

  程式碼

  ```c++
  int l = 0, r = v.size() - 1;
  while (l <= r) {
    const int mid = l + (r - l) / 2;
    if (v[mid] == target) {
      return mid;
    } else if (v[mid] < target) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  ```

- 找不到怎麼辦？

  ```text
  [1, 3, 5, 7, 9]  target: 4
      ^  ^
      r  l

  // 找比 4 大的 --> l
  // 找比 4 小的 --> r
  ```

- 重複值怎麼辦？

  - 向左插入：std::lower_bound()

    ```text
    [1, 2, 2, 2, 3]  target: 2
     ^  ^
     r  l

    // 找第一個 2 --> l
    // 找比 2 小的最大 --> r
    ```

  - 向右插入：std::upper_bound()

    ```text
    [1, 2, 2, 2, 3]  target: 2
              ^  ^
              r  l

    // 找第最後一個 2 --> r
    // 找比 2 大的最小 --> l
    ```

## 6. <a name='BinaryTree'></a>Binary Tree

[[Lucifer-樹]](https://github.com/azl397985856/leetcode/blob/master/thinkings/tree.md)

- 一個中心：樹的 Traverse
- 兩個基本點：BFS / DFS
- 三種類型：Search, Modify, Construct
- 四個重要觀念：
  - Binary Search Tree
  - Complete Search Tree
  - Path
  - Distance

Hints:

- 遞迴 → Iteration
  - 雙色 Stack 法：下去白色，回來灰色。**返回的時候，才做事**

## 7. <a name='Back-Tracking'></a>Back-Tracking

[[Lucifer-Backtracking]](https://leetcode-solution-leetcode-pp.gitbook.io/leetcode-solution/thinkings/backtrack)

## 8. <a name='BFSDFSFloodFill'></a>BFS / DFS / Flood Fill

## 9. <a name='Graph'></a>Graph

### 9.1. <a name=''></a>矩陣圖模擬

- 1. DFS / BFS
- 2. 從四邊向內出發
- 3. Union find (spanning tree, redundant connection)

ps.

- 移動上下左右

  ```cpp
  int dir[] = {1, 0, -1, 0, 1};
  for (int i = 0; i < 4; i++) {
    int dx = x + dir[i];
    int dy = y + dir[i + 1];
  }
  ```

### 9.2. <a name='UnionfindDisjointSet'></a>Union find (Disjoint Set)

Leetcode: 648 redundant connection

整理

- 一個中心：合併
- 兩個觀念：
  - 初始點，自己父親連自己
  - 如果父親一樣，就是同一個 Union 的
- 三個 Operation

  - Find()
  - Union()
  - Connected() → 有沒有一樣的 parent

### 9.3. <a name='Topologicalsort'></a>Topological sort 拓樸排序

Leetcode:

- 207 Course Schedule
- 329 (TODO)

```cpp
bool dfs(std::vector<std::vector<int>> &graph, std::vector<int> &state,
         std::vector<int> &ans, int cur) {
  if (state[cur] == 1)
    return true;
  else if (state[cur] == 2)
    return false;

  state[cur] = 1;
  for (const auto &i : graph[cur]) {
    if (dfs(graph, state, ans, i))
      return true;
  }
  state[cur] = 2;
  ans.push_back(cur);

  return false;
}
```

### 9.4. <a name='MinimumSpanningTreesMST'></a>Minimum Spanning Trees (MST) 最小生成樹

prim 算法和 kruskal 算法

### 9.5. <a name='ShortestPath'></a>Shortest Path 最短路问题

Dijkstra, Bellman-Ford, Floyd-Warshall

### 9.6. <a name='-1'></a>8.6 連通性問題

### 9.7. <a name='-1'></a>網路流量

## 10. <a name='Hashtables'></a>Hash tables

- 2-D Hash Table 好用 (直接把 HashTable 當 Array 用)
  - Leetcode 399. Evaluate Division
  - `map[a][b]`
  - `map.count(a)`, `map[a].count(b)`, ...

## 11. <a name='DynamicProgramming'></a>Dynamic Programming

[[21 道 LeetCode 題解帶你搞懂動態規劃！]](https://www.readfog.com/a/1661529855046553600) \
[[告别动态规划，连刷 40 道题，我总结了这些套路，看不懂你打我（万字长文）]](https://zhuanlan.zhihu.com/p/91582909) \

什麼情況可以用 DP：

1. 最優子結構 - 它指的是問題的最優解包含着子問題的最優解。
2. 重疊子問題 - 在遞歸的過程中，出現了反覆計算的情況。
3. 無後效性 - 只關注最後結果，不用知道走了什麼路徑。

怎麼做題目：

1. 狀態定義：找出子問題抽象定義。
2. 確定狀態轉移方程：找出狀態與狀態之間的遞推關係。
3. 初始狀態和邊界情況：最簡單的子問題的結果，也是程序的出口條件 。
4. 返回值：對於簡單問題，返回值可能就是最終狀態；對於複雜問題可能還需對最終狀態做一些額外處理。

題目分類：

1. Path - 路徑問題
   - Unique Path
   - Unique Path II (障礙物)
   - 最小路徑和
   - 三角形最小路徑和
2. House Rober
   - Fibonacci Sequence
   - House Rober
   - House Rober II (Circular)
   - House Rober III (Tree)
3. 買賣股票問題
4. 回文串問題
5. 子序列問題
6. 其他問題

 
