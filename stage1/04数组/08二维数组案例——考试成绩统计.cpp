#include<iostream>
#include<string>

using namespace std;

//��λ���鰸���������Գɼ�ͳ��

int main8()
{
	
	//1��������ά����
	int score[3][3] =
	{
		{100,100,100},
		{90,50,100},
		{60,70,80}
	};
	string name[] = {"����","����","����"};

	cout << "��λͬѧ�ɼ����£�" << endl;

	for (int i = 0; i < 3; i++)
	{
		int sum = 0;//��������ۺϱ���
		
		cout << name[i] << "���Ƴɼ�Ϊ��";

		for (int j = 0; j < 3; j++)
		{
			sum += score[i][j];  //sum = sum + score[i][j];
			
			cout << score[i][j] << " ";
		}
		
		cout << endl;

		cout <<"�ܳɼ�Ϊ��"<<sum << endl;
	}


	system("pause");

	return 0;
}

