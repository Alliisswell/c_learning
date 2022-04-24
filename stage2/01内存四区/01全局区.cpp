/*
## 1 内存分区模型

C++程序在执行时，将内存大方向划分为**4个区域**

- 代码区：存放函数体的二进制代码，由操作系统进行管理的
- 全局区：存放全局变量和静态变量以及常量，该区域的数据在程序结束后由操作系统释放
- 栈区：由编译器自动分配释放, 存放函数的参数值,局部变量等
- 堆区：由程序员分配和释放,若程序员不释放,程序结束时由操作系统回收

**内存四区意义：**

不同区域存放的数据，赋予不同的生命周期, 给我们更大的灵活编程

### 1.1 程序运行前

​	在程序编译后，生成了exe可执行程序，未执行该程序前，分为两个区域

​	**代码区：**

​		存放 CPU 执行的机器指令（二进制代码）

​		代码区是**共享**的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可

​		代码区是**只读**的，使其只读的原因是防止程序意外地修改了它的指令

​	**全局区：**

​		全局变量和静态变量存放在此

​		全局区还包含了常量区，包含字符串常量和其他常量（const修饰的变量）

​		该区域的数据在程序结束后由操作系统释放
*/

#include<iostream>

using namespace std;

//全局区：全局变量，静态变量，常量

//全局变量
int g_a = 10;
int g_b = 10;

//静态全局变量
static int s_g_a = 10;
static int s_g_b = 10;

//const修饰的全局变量
int c_g_a = 10;
int c_g_b = 10;

int main1() {

	//局部变量
	int l_a = 10;
	int l_b = 10;
	cout << "局部变量l_a的地址为：" << "\t" << (int)&l_a << endl;
	cout << "局部变量l_b的地址为：" << "\t" << (int)&l_b << endl;

	cout << "全局变量g_a的地址为：" << "\t" << (int)&g_a << endl;
	cout << "全局变量g_b的地址为：" << "\t" << (int)&g_b << endl;
	
	//静态变量：在变量前面加static，属于静态变量
	//静态局部变量
	static int s_l_a = 10;
	static int s_l_b = 10;
	cout << "静态局部变量s_l_a的地址为：" << "\t" << (int)&s_l_a << endl;
	cout << "静态局部变量s_l_b的地址为：" << "\t" << (int)&s_l_b << endl;

	cout << "静态全局变量s_g_a的地址为：" << "\t" << (int)&s_g_a << endl;
	cout << "静态全局变量s_g_b的地址为：" << "\t" << (int)&s_g_b << endl;

	//常量：字符串常量，const修饰的变量
	//字符串常量
	cout << "字符串常量的地址为：" << "\t" << (int)&"hello world" << endl;

	//const修饰的变量：const修饰的全局变量，const修饰的局部变量
	//const修饰的局部变量
	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "const修饰的局部变量c_l_a的地址为：" << "\t" << (int)&c_l_a << endl;
	cout << "const修饰的局部变量c_l_b的地址为：" << "\t" << (int)&c_l_b << endl;
	
	cout << "const修饰的全局变量c_g_a的地址为：" << "\t" << (int)&c_g_a << endl;
	cout << "const修饰的全局变量c_g_b的地址为：" << "\t" << (int)&c_g_b << endl;

	system("pause");
	return 0;
}
/*

总结：
* C++中在程序运行前分为全局区和代码区
* 代码区特点是共享和只读
* 全局区中存放全局变量、静态变量、常量区
* 常量区中存放 字符串常量 和 const修饰的全局变量
*/

/*
#include<iostream>

using namespace std;

int main() {


	system("pause");
	return 0;
}
*/