#include<iostream>

using namespace std;

//continue
//**���ã�**��==ѭ�����==�У���������ѭ����������δִ�е���䣬����ִ����һ��ѭ��

int main()
{
	for (int i = 0;i<=100;i++)
	{
		//��������������ż�������
		if (i % 2 == 0)
		{
			continue;//����ɸѡ������ִ�е��˾Ͳ�������ִ�У�ִ����һ��ѭ��
		}

		cout << i << endl;
	}
	system("pause");

	return 0;
}

//ע�⣺continue��û��ʹ����ѭ����ֹ����break������ѭ��

