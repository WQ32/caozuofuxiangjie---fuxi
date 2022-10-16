#include <stdio.h>
//
// sizeof

//void test1(int arr[])
//{
//	printf("%d\n", sizeof(arr)); // 4 
//}
//void test2(char ch[])
//{
//	printf("%d\n", sizeof(ch));  // 4
//}
//int main()
//{
//	int arr[10] = { 0 };
//	char ch[10] = { 0 };
//	test1(arr);
//	test2(ch);
//	return 0;
//}
// 1.算术操作符
// + - * / %
//  / 操作符的两边两个操作数是整数，执行整数除法，只要有浮点数就执行浮点数除法
//  % 操作符的两个操作数必须是整数，返回的是整除之后的余数
//  其他操作符都可以作用于整数和浮点数

// 2.移位操作符   - 二进制
// <<左移操作符   - 左边丢弃，右边补0
// >>右移操作符   - 右边丢弃，逻辑右移：左边补0 ；算术右移：左边用原该值的符号位填充
// 移位操作符的操作数只能是整数

// 0000 0000 0000 0001  1 
// 0000 0000 0000 0100  1<<2
// 0000 0000 0000 1011  a=11
// 0000 0000 0000 1111  a = a|<<2 = 15
// 0000 0000 0000 0100  1<<2
// 1111 1111 1111 1011  ~1<<2
// 0000 0000 0000 1111  a
// 0000 0000 0000 1011  a&(~(1<<2))

// 3.位操作符  - 操作数必须是整数
// & 按位与
// | 按位或
// ^ 按位异或

//int main()
//{
//	int num1 = 1;
//	int num2 = 2;
//	// 0000 0000 0000 0001
//	// 0000 0000 0000 0010
//	printf("%d\n",num1 & num2);
//	// 0000 0000 0000 0000        - 0
//	printf("%d\n", num1 | num2);
//	// 0000 0000 0000 0011        - 3
//	printf("%d\n", num1 ^ num2);
//	// 0000 0000 0000 0011        - 3
//	return 0;
//}

//// 不能创建临时变量（第三个变量），实现两个数的交换。
//
//int main()
//{
//	int a = 7;
//	int b = 16;
//	//法一：
//	//// 0000 0000 0000 0001 - a
//	//// 0000 0000 0000 0011 - b
//	//a = a ^ b;
//	//// 0000 0000 0000 0010 - a
//	//b = a ^ b;
//	//// 0000 0000 0000 0001 - b
//	//a = a ^ b;
//	//// 0000 0000 0000 0011 - a
//	//法二：
//	a = b - a;
//	b = b - a;
//	a = a + b;
//	printf("a = %d b=%d\n", a, b);
//	return 0;
//}

// 编写代码实现：求一个整数存储在内存中的二进制中1的个数。

// 法一： - 不好

//int main()
//{
//	int num = 10;
//	int count = 0;
//	while (num)
//	{
//		if (num % 2 == 1)
//		{
//			count++;
//		}
//		num = num / 2;
//		// 0000 0000 0000 1010
//	}
//	printf("二进制中1的个数 = %d\n", count);
//	return 0;
//}

//// 法二：
//
//int main()
//{
//	int num = -1;
//	// 1111 1111 1111 1111
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (num & (1 << i))
//		{
//			count++;
//		}
//	}
//	printf("二进制中1的个数 = %d\n", count);
//	return 0;
//
//}

//// 法三 - 法二的优化
//int main()
//{
//	int num = -1;
//	// 1111 1111 1111 1111
//	int i = 0;
//	int count = 0;
//	while (num)
//	{
//		count++;
//		num = num & (num - 1);
//	}
//	printf("二进制中1的个数 = %d\n", count);
//	return 0;
//}

// 前置++，先++,后使用
// 后置++，先使用，再++


// int a = (int)3.14
// int a = int(3.14)   error

//// 逻辑反操作  -  ！
//
//int main()
//{
//	int a = -10;
//	int* p = NULL;
//	printf("%d\n", !2);  // - 0 (任意值为True)
//	printf("%d\n", !0);  // - 1
//	a = -a;
//	p = &a;
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof a);       //这样写ok
//	// printf("%d\n", sizeof int);  //这样写error
//	return 0;
//}

//// 逻辑操作符   - 值为0或1
//// 逻辑或  -  ||
//// 逻辑与  -  &&
////
//int main()
//{
//	int a = 0;
//	int b = 5;
//	int c = a && b;
//	printf("%d\n", c);   //0
//	return 0;
//}

////360笔试题
//
//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	// i = a++ && ++b && d++;
//	// a++先使用后加加，a开始等于0，后面是&&，逻辑与，false,不会算下去了,结果 1 2 3 4
//	i = a++||++b||d++;
//	// a++先使用时是0，但这里是逻辑或，后面会继续进行运算，结果 1 3 3 4
//	printf(" a = %d\n b = %d\n c = %d\n d = %d\n", a, b, c, d);
//	return 0;
//}

//// 条件操作符
//// exp1 ? exp2 : exp3
////例：
//int main()
//{
//	int a = 7;
//	int b = 4;
//	if (a > 5)
//		b = 3;
//	else
//		b = -3;
//	// 等价于 a > 5 ? b = 3 : b = -3
//}

// 逗号表达式   -   从左向右依次执行。整个表达式的结果是最后一个表达式的结果。

//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c = (a > b, a = b + 10, a, b = a + 1);
//	printf("%d\n", c);
//	// c = b = a + 1 = b + 10 + 1 = 13
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	a = get_val();
//	count_val(a);
//	/*while (a > 0)
//	{
//		a = get_val();
//		count_val(a);
//	}*/
//	// while循环等价于
//	// while(a=get_val(),count_val(a),a>0)
//	//{
//		//	业务处理
//	//}
//	return 0;
//}

//// 条件操作符求最大值
//
//int get_max(int x, int y)
//{
//	return x > y ? x : y;
//}
//
//int main()
//{
//	int x = 0;
//	int y = 0;
//	printf("请输入两个数：>");
//	scanf("%d%d", &x, &y);
//	int max = get_max(x, y);
//	printf("max = %d\n", max);
//	return 0;
//}

////结构体
//
//struct Stu
//{
//	char name[20];
//	int age;
//	char sex[5];
//};
// 
// // 结构体引用
//int main()
//{
//	struct Stu s = { "张周吉",18,"男"};
//	struct Stu* ps = &s;
//	//法一：
//	printf("姓名：%s\n", ps->name);
//	printf("年龄：%d\n", ps->age);
//	printf("性别：%s\n", ps->sex);
//	//法二：
//	printf("姓名：%s\n", (*ps).name);
//	printf("年龄：%d\n", (*ps).age);
//	printf("性别：%s\n", (*ps).sex);
//	//法三：
//	printf("姓名：%s\n", s.name);
//	printf("年龄：%d\n", s.age);
//	printf("性别：%s\n", s.sex);
//	return 0;
//}

//整型提升
//整型提升是按照变量的数据类型的符号位来提升的
// 负数的整形提升：char c1=-1   二进制补码11111111  -> 变成32个bit位（32个1）
// 正数的整型提升：char c2=1     00000001   -> 0000000000000000000000000000000001

//// 两数如何相加
//
//int main()
//{
//	char a = 3;
//	char b = 127;
//	// a: 0000 0011
//	//整型提升： 0000 0000 0000 0011  （32位）
//	// b: 0111 1111
//	char c = a + b;
//	//整型提升： 0000 0000 0111 1111
//	// a+b       0000 0000 1000 0010
//	// c         1000 0010
//	//整型提升   1111 1111 1000 0010  -补码
//	//           1111 1111 1000 0001  -反码
//	//           1000 0000 0111 1110  -原码
//	// 原码 -   取反 -> 反码   -    反码+1 -> 补码
//	// 补码-1   -  反码   - 符号位不变，剩下取反 -> 原码
//	printf("%d\n", c);   // 打印出原码，在内存中存补码  - -126
//	return 0;
//}

//int main()
//{
//	char c = 1;
//	// c只要参与表达式运算，就会发生整型提升
//	printf("%u\n", sizeof(c));
//	printf("%u\n", sizeof(+c));
//	printf("%u\n", sizeof(-c));
//	// %u 表示按unsigned int格式输入或输出数据
//	// +c  和 -c进行了表达式运算，所以变成了unsigned int 类型，占4个字节，
//	// 而c未进行表达式运算，只是char类型，在内存中占1个字节
//	return 0;
//}


//复杂表达式的求值有三个影响的因素
//1.操作符的优先级
//2.操作符的结合性
//3.是否控制求值顺序

//int fun()
//{
//	static int count = 1;
//	return ++count;
//}
//int main()
//{
//	int answer;
//	answer = fun() - fun() * fun();
//	printf("%d\n", answer);//输出多少？   -    -10
//	return 0;
//	// 其实有问题：我们可知道先算 * ,但函数调用顺序无法通过操作符的优先级确定
//}

//#include <stdio.h>
//int main()
//{
//	int i = 1;
//	int ret = (++i) + (++i) + (++i);
//	printf("%d\n", ret);     // 12
//	printf("%d\n", i);       // 4
//	return 0;
//}

//int main()
//{
//	short s = 0;
//	int a = 10;
//	printf("%d\n", sizeof(s = a + 5));
//	// a+5虽然是一个整型，但是赋给s后，就得按s的类型来，就是short类型，所以打印2个字节
//	printf("%d\n", s);
//	return 0;
//}

//int main()
//{
//	/*printf("%d\n", sizeof(char*));
//	printf("%d\n", sizeof(short*));
//	printf("%d\n", sizeof(int*));
//	printf("%d\n", sizeof(double*));*/
//	// 指针都占4个字节
//
//	int a = 0x11223344;
//	int* pa = &a;
//	char* pc = &a;
//	printf("%p\n", pa);
//	printf("%p\n", pa+1);
//	//跳过一个整形的地址
//	printf("%p\n", pc);
//	printf("%p\n", pc+1);
//	//跳过一个字符的地址
//	return 0;
//}
