#include<iostream>

using namespace std;

int main()
{
	//1.单精度 float 4个字节（7位有效数字）
	//2.双精度 double 8个字节（15-16位有效数字）
	

	float f1 = 3.1415926f;	//默认情况：系统认为实型数据位双精度（double），我们在数值后边加f，就省去了系统的自动转换过程
	cout << "f1= " << f1 << endl;	//默认情况下，输出一个小数，会显示出六位有效数字，
									

	double d1 = 3.1415926;
	cout << "d1= " << d1 << endl;  //这里 单，双精度 都只输出六位数字，如果想要输出更多位，需要配置环境，此内容超纲


	//统计float和double占用内存空间
	cout << "float占用内存空间为：" << sizeof(float) << endl;  //4字节
	cout << "double占用内存空间为：" << sizeof(double) << endl;  //8字节  

	//科学计数法
	float f2 = 3e2;//3 * 10 ^ 2
	cout << "f2=" << f2 << endl;
	float f3 = 3e-2;//3 * 0.1 ^ 2
	cout << "f3=" << f3 << endl;

	system("pause");

	return 0;
}