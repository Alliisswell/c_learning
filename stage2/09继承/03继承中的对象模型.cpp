#include<iostream>
using namespace std;

class Base {

public:
	int m_a = 0;
protected:
	int m_b = 0;
private:
	int m_c = 0;
};

class Son :public Base {
public:
	int m_d;
};

//���ÿ�����Ա������ʾ�����߲鿴����ģ��
//��ת�̷�  �̷�:
//��ת·��  cd ����·��
//�鿴Ŀ¼  dir
//�鿴����  cl /d1 reportSingleClassLayout���� �ļ���  ��clӢ�ģ�d1����һ���ļ�����Tab����ȫ��

void test01() {
	cout << "size of Son = " << sizeof(Son) << endl;
	//16
	//���������зǾ�̬��Ա���Զ��ᱻ����̳���ȥ
	//������˽�г�Ա���ԣ��Ǳ��������������ˣ�����Ƿ��ʲ���������ȷʵ���̳���ȥ��
	cout << "size of Base = " << sizeof(Base) << endl;
	//12
}





int main() {

	test01();

	system("pause");
	return 0;
}