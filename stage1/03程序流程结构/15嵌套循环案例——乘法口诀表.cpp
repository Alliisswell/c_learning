#include<iostream>

using namespace std;

//��������
//����*����=������
//ÿһ���У�����<=��ǰ����

int main15()
{
	//���ִ��һ�Σ��ڲ�ִ��һ��
	
	//��ӡ����
	for (int i = 1; i <=9; i++)
	{
		//cout << i << endl;
		
		//��ӡ����
		for (int j = 1; j <=i; j++)  //ʵ�� ����<=��ǰ����
		{
			cout << j << "*" << i << "=" << j * i <<"\t";//"\t"ˮƽ�Ʊ����������ÿ����������������
		}
		cout << "\n";//�ȼ��� cout << '\n'; �� cout << endl;
		
		cout << endl;
	}
	


	system("pause");

	return 0;
}