#include<iostream>
using namespace std;
#include<fstream>	//系统头文件用 <>
#include<string>

/*
程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放

通过**文件可以将数据持久化**

C++中对文件操作需要包含头文件 == fstream ==

文件类型分为两种：

1. **文本文件**   -  文件以文本的**ASCII码**形式存储在计算机中
2. **二进制文件** -  文件以文本的**二进制**形式存储在计算机中，用户一般不能直接读懂它们

操作文件的三大类:

1. ofstream：写操作
2. ifstream：读操作
3. fstream ：读写操作
*/

void test01() {
	//1、包含头文件  fstream
	
	////2、创建流对象

	//ofstream ofs;

	////3、指定打开方式
	//ofs.open("test.txt",ios::out);  //文件路径可以是绝对路径，相对路径和文件名（只写文件名则路径和源文件相同）

	//2、3两步可以合为一步,利用的是ofs对象所属类的构造函数
	ofstream ofs("test.txt", ios::out);

	//4、写内容
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;

	//5、关闭文件
	ofs.close();

}

int main() {

	test01();

	system("pause");
	return 0;
}

/*
#include<iostream>
using namespace std;






int main(){



	system("pause");
	return 0;
}
*/

