#include<iostream>

using namespace std;

int main5()
{
	//ת���ַ����ã����ڱ�ʾһЩ������ʾ������ASCII�ַ�������ת���ַ����ʾ���ASCII�ַ�
	
	//c++�п���ʹ�� endl �����л��в���������c��û�����������ͨ��ʹ��ת���ַ� \n �����л��в���
	//���з���\n
	cout << "hello world\n";

	//�����б�ܣ�\\

	cout<<"\\"<<endl;

	//ˮƽ�Ʊ����\t	���ã�����������������
	cout << "aaaa\thello world" << endl;
	cout << "aa\thello world" << endl;
	cout << "aaaaaa\thello world" << endl;

	system("pause");

	return 0;
}

/*
ASCII �����������**��������**�ɣ�
* ASCII �Ǵ�ӡ�����ַ��� ASCII ���ϵ����� **0-31** ������˿����ַ������ڿ������ӡ����һЩ��Χ�豸��
* ASCII ��ӡ�ַ������� **32-126** ����������ڼ������ҵ����ַ������鿴���ӡ�ĵ�ʱ�ͻ���֡�
*/