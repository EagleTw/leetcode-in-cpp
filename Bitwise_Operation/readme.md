# Bitwise Operation Techniques

## Links

[Jserv Bitwise Operation](https://hackmd.io/@sysprog/c-bitwise)

## 1. Set nth bit of integer x
```x | (1<<n)```
Example
```
#include<stdio.h>
int main() 
{
	int x = 10; //1010
	int n = 2;
	int result = x | (1<<n);  //1110
	printf("%d\n", result); //14	
	return 0;
}
```

## 2. Unset nth bit of integer x
```x & ~(1<<n)```
Example

```
#include<stdio.h>
int main() 
{
	int x = 10; //1010
	int n = 1;
	int result = x & ~(1<<n); //1000
	printf("%d", result2); 	//8
	return 0;
}
```
## 3. Toggle nth bit of x
```x ^ (1<<n)```
Example
```
#include<stdio.h>
int main() 
{
	int x = 10; //1010
	int n = 0;
	int result = x ^ (1<<n); //1011
	n = 3;
	result = result ^ (1<<n); //0011
	printf("%d\n", result); //3
	return 0;
}
```
## 4. Multiply integer x by the nth power of 2
```x << n```
Example
```
#include<stdio.h>
int main() 
{
	int x = 10;
	int n = 3;
	int result = x << n;  // 10 * (2^3)
	printf("%d\n", result); //80
	return 0;
}
```
5. Divide integer x by the nth power of 2
```x >> n;```
Example
```
#include<stdio.h>
int main() 
{
	int x = 80;
	int n = 3;
	int result = x >> n;  // 80 / (2^3)
	printf("%d\n", result); //10
	return 0;
}
```
## 6. Check equality of two integer
```(num1 ^ num2) == 0; // num1 == num2```
Example
```
#include<stdio.h>
int main() 
{
	int num1 = 10;
	int num2 = 10;
	if ((num1 ^ num2) == 0) 
		printf("Equal");
	else
		printf("Not Equal");
	return 0;
}
```
## 7. Check if an integer number is odd
```(num & 1) == 1```
Example
```
#include<stdio.h>
int main() 
{
	int num = 13;
	if ((num & 1) == 1)
		printf("Odd");
	else
		printf("Even");
	return 0;
}
```
## 8. Swap two integer values
//version 1
```
a ^= b;
b ^= a;
a ^= b;
```

//version 2
```
a = a ^ b ^ (b = a)
```
Example

```
#include<stdio.h>
int main() 
{
	int a = 5;
	int b = 7;
	
	//Version 1
	a ^= b;
	b ^= a;
	a ^= b;
	
	printf("a = %d & b = %d\n", a, b); // a = 7 & b = 5
	
	//Version 2
	a = a ^ b ^ (b = a);
	
	printf("a = %d & b = %d", a, b); // a = 5 & b = 7
	return 0;
}
```
## 9. Get the max of two integer values
```b & ((a-b) >> 31) | a & (~(a-b) >> 31);```
Example

```
#include<stdio.h>
int main() 
{
	int a = 5;
	int b = 7;
	
	int max = b & ((a-b) >> 31) | a & (~(a-b) >> 31);
	printf("%d", max);
	
	return 0;
}
```
## 10. Get the min of two integer values
```a & ((a-b) >> 31) | b & (~(a-b) >> 31);```
Example
```
#include<stdio.h>
int main() 
{
	int a = 5;
	int b = 7;
	
	int min = a & ((a-b) >> 31) | b & (~(a-b) >> 31);
	printf("%d", min);
	
	return 0;
}
```
## 11. Check whether both integer numbers have the same sign
```(num1 ^ num2) >= 0;```
Example
```
#include<stdio.h>
int main() 
{
	int num1 = 5;
	int num2 = -7;
	
	if ((num1 ^ num2) >= 0)
		printf("Same Sign");
	else
		printf("Different Sign");

	return 0;
}
```
## 12. Flip the sign of an integer number
```num = ~num + 1;```
Example
```
#include<stdio.h>
int main() 
{
	int num = 5;
	
	num = ~num + 1;
	printf("num = %d", num);

	return 0;
}
```
## 13. Check whether a integer number is power of 2
```num > 0 && (num & (num - 1)) == 0;```
Example
```
#include<stdio.h>
int main() 
{
	int num = 16;
	
	if (num > 0 && (num & (num - 1)) == 0)
		printf("Number is power of 2");
	else
		printf("Number is not power of 2");
	return 0;
}
```
## 14. Increment by 1 (num + 1)
```-~num```
Example
```
#include<stdio.h>
int main() 
{
	int num = 16;
	
	num = -~num;
	printf("num = %d", num);
	
	return 0;
}
```
## 15. Decrement by 1 (num - 1)
```~-num```
Example

```
#include<stdio.h>
int main() 
{
	int num = 16;
	
	num = ~-num;
	printf("num = %d", num);
	
	return 0;
}
```
