#include<iostream>

using namespace std;

//在C++中，函数的形参列表中的形参是可以有默认值的。

//语法：返回值类型  函数名 （参数 = 默认值）{}

//如果我们自己传入数据，就用自己的数据，如果没有，那么就用默认值
int func11(int a, int b = 20, int c = 30) {
	return a + b + c;
}



//注意事项
//1、如果某个位置已经有了默认参数，那么从这个位置往后，从左往右都必须有默认值
//int func2(int a, int b = 20, int c) {
//	return a + b + c;
//}

//2、如果函数声明有默认参数，函数实现就不能有默认参数
//声明和实现只能有一个有默认参数
int func12(int a = 10, int b = 10);

int func12(int a, int b) {
	return a + b;
}

int main1() {

	cout << func11(10, 30) << endl;	//10赋值给a，30赋值给，而c使用默认值
	cout << func12(10, 10) << endl;



	system("pause");
	return 0;
}

/*
#include<iostream>

using namespace std;

int main() {



	system("pause");
	return 0;
}
*/