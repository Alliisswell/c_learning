#include<iostream>
using namespace std;

//���ã�ͨ�����ص����������ʵ���Լ�����������

//�Զ��������
class MyInteger {
	
	friend ostream& operator<<(ostream& out, MyInteger myint);

public:
	MyInteger() {
		m_num = 0;
	}

	//���� ǰ��++ �����  ����������Ϊ��һֱ��һ�����ݽ��е�����������ʽ��̣�
	MyInteger& operator++() {
		//�Ƚ���++����
		m_num++;
		//�ٽ�����������
		return *this;
	}
	//���� ����++ �����  ��סҪ����ֵ��������������
	//void operator++(int)  ��� int ����ռλ������������������ ǰ�õ��� �� ���õ���
	MyInteger operator++(int) {  //���ﷵ�ز������ã�����Ϊtemp�Ǿֲ�����������������ͱ��ͷţ�����������õķ�ʽ���ؾ����ڷǷ�����
		//�� ��¼��ʱ���
		MyInteger temp = *this;
		//�� ����
		m_num++;
		//��� ����¼���������
		return temp;
	}


private:
	int m_num;
};

//�������������
ostream& operator<<(ostream& out,MyInteger myint) {
	out << myint.m_num;
	return out;
}

//ǰ��++ ��++ �ٷ���
void test01() {
	MyInteger myint;
	//cout << ++(++myint) << endl;
	//cout << myint << endl;
	cout << ++(++myint) << " "<< myint << endl;

}
	

//����++ �ȷ��� ��++
void test02() {
	MyInteger myint;
	//cout << myint++ << endl;
	//cout << myint << endl;
	cout << myint++ <<" "<< myint << endl;	//����������������ȫ�ֺ����еĵڶ�������ʹ�����þͻᱨ��
}

int main() {

	test01();
	test02();


	system("pause");
	return 0;
}

//�ܽ᣺ǰ�õ����������ã����õ�������ֵ