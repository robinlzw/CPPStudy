// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "first.h"
#include "algo.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

//TEST

int panny_call_back(int a, int b)
{
	int c;
	c = a + b;
	printf("输出：%d\n", c);
	return 11;
}

int main()
{
	char *str = new char[100];
	strcpy_s(str,6,"hello");
	showStrIn_Blue(str);
	showStrIn_Red_Yello(str);
	SetConsoleStrIn_Blue_White();

	printf("%f",MAX(9,10));
	std::cout << MIN(100, 101) << endl;
	SetConsoleDefault();
	system("pause");

    return 0;
}

