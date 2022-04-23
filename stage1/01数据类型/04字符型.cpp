#include<iostream>

using namespace std;

int main4()
{
	//字符型变量创建方式
	char ch = 'a';
	cout << ch << endl;
	
	//字符型变量所占内存大小
	cout << "char所占内存空间大小为：" << sizeof(char) << endl;  //C和C++中字符型变量只占用1个字节

	//字符型变量常见错误
	//char ch2 = "a";
	//char ch2 = 'abcdef';

	//字符型变量并不是把字符本身放到内存中存储，而是将对应的ASCII编码放入到存储单元
	//字符型变量对应ASCII编码：
	//a---97
	//A---65
	cout << (int)ch << endl;//强制以十进制数输出ch



	system("pause");

	return 0;


}