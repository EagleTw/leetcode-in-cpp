# Cheet sheet

<!-- vscode-markdown-toc -->

- 1. [Array & Two Pointer & Sliding window & Stacks](#ArrayTwoPointerSlidingwindowStacks)
  - 1.1. [Good-to-know algorithm](#Good-to-knowalgorithm)
    - 1.1.1. [Boyer-Moore Majority Voting Algorithm](#Boyer-MooreMajorityVotingAlgorithm)
- 2. [Linked list](#Linkedlist)
- 3. [Bitwise Operation](#BitwiseOperation)
  - 3.1. [Default need-to-know](#Defaultneed-to-know)
  - 3.2. [Builtin usefull bitwise](#Builtinusefullbitwise)
- 4. [Binary Search](#BinarySearch)
- 5. [Binary Tree](#BinaryTree)
- 6. [Back-Tracking](#Back-Tracking)
- 7. [BFS / DFS / Flood Fill](#BFSDFSFloodFill)
- 8. [Graph](#Graph)
- 9. [Hash tables](#Hashtables)
- 10. [Union Find](#UnionFind)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

## 1. <a name='ArrayTwoPointerSlidingwindowStacks'></a>Array & Two Pointer & Sliding window & Stacks

### 1.1. <a name='Good-to-knowalgorithm'></a>Good-to-know algorithm

#### 1.1.1. <a name='Boyer-MooreMajorityVotingAlgorithm'></a>Boyer-Moore Majority Voting Algorithm

Finding majority element -- [[YouTube]](https://www.youtube.com/watch?v=n5QY3x_GNDg&t=274s)

## 2. <a name='Linkedlist'></a>Linked list

## 3. <a name='BitwiseOperation'></a>Bitwise Operation

[[Jserv-Bitwise-Operation]](https://hackmd.io/@sysprog/c-bitwise)
[[利用 LeetCode easy 題目來精通 C++ bitwise]](https://steveyang.blog/zh_tw/2022/07/02/leetcode-easy-bitwise-xor-summary/)

### 3.1. <a name='Defaultneed-to-know'></a>Default need-to-know

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

### 3.2. <a name='Builtinusefullbitwise'></a>Builtin usefull bitwise

- `int __builtin_ffs (int x)` → find first set
  - Returns one plus the index of the least significant 1-bit of x, or if x is zero, returns zero.
- `int __builtin_clz (unsigned int x)` → count leading zero
  - Returns the number of leading 0-bits in x, starting at the most significant bit position. If x is 0, the result is undefined.
- `int __builtin_ctz (unsigned int x)` → count trailing zero
  - Returns the number of trailing 0-bits in x, starting at the least significant bit position. If x is 0, the result is undefined.
- `int __builtin_popcount (unsigned int x)` → population count
  - Returns the number of 1-bits in x.

## 4. <a name='BinarySearch'></a>Binary Search

[[Lucifer-二分]](https://leetcode-solution-leetcode-pp.gitbook.io/leetcode-solution/thinkings/binary-search-1)

- 一個中心：折半
- 二個類型：最左插入、最右插入
- 三個基本概念：解空間、序列有序、極值
- 四大應用
  - 能力檢測二分
  - 前綴和二分
  - 插入排序二分
  - 計數二分

## 5. <a name='BinaryTree'></a>Binary Tree

[[Lucifer-樹]](https://github.com/azl397985856/leetcode/blob/master/thinkings/tree.md)

- 一個中心：樹的 Traverse
- 兩個基本點：BFS / DFS
- 三種類型：Search, Modify, Construct
- 四個重要觀念：
  - Binary Search Tree
  - Complete Search Tree
  - Path
  - Distance

## 6. <a name='Back-Tracking'></a>Back-Tracking

[[Lucifer-Backtracking]](https://leetcode-solution-leetcode-pp.gitbook.io/leetcode-solution/thinkings/backtrack)

## 7. <a name='BFSDFSFloodFill'></a>BFS / DFS / Flood Fill

## 8. <a name='Graph'></a>Graph

- 移動上下左右

```cpp
int dir[] = {1, 0, -1, 0, 1};
for (int i = 0; i < 4; i++) {
  int dx = x + dir[i];
  int dy = y + dir[i + 1];
}
```

## 9. <a name='Hashtables'></a>Hash tables

## 10. <a name='UnionFind'></a>Union Find

Leetcode:

- 648 redundant connection

整理

- 一個中心：合併
- 兩個觀念：
  - 初始點，自己父親連自己
  - 如果父親一樣，就是同一個 Union 的
- 三個 Operation
  - Find()
  - Union()
  - Connected() → 有沒有一樣的 parent
