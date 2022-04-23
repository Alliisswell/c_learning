#include<iostream>

using namespace std;

int main5()
{
	//转义字符作用：用于表示一些不能显示出来的ASCII字符，所以转义字符本质就是ASCII字符
	
	//c++中可以使用 endl 来进行换行操作，但是c中没有这样的命令，通常使用转义字符 \n 来进行换行操作
	//换行符：\n
	cout << "hello world\n";

	//输出反斜杠：\\

	cout<<"\\"<<endl;

	//水平制表符：\t	作用：可以整齐地输出数据
	cout << "aaaa\thello world" << endl;
	cout << "aa\thello world" << endl;
	cout << "aaaaaa\thello world" << endl;

	system("pause");

	return 0;
}

/*
ASCII 码大致由以下**两部分组**成：
* ASCII 非打印控制字符： ASCII 表上的数字 **0-31** 分配给了控制字符，用于控制像打印机等一些外围设备。
* ASCII 打印字符：数字 **32-126** 分配给了能在键盘上找到的字符，当查看或打印文档时就会出现。
*/