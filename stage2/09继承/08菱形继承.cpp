#include<iostream>
using namespace std;

class Animal {	//������

public:
	int m_a = 0;
};

//������̳�  ������μ̳е�����
//�ڼ̳�֮ǰ���Ϲؼ��� virtual ��Ϊ��̳�
//Animal�� ��Ϊ �����
class Sheep :virtual public Animal {	//����
};

class Tuo :virtual public Animal {	//����
};

class SheepTuo :public Sheep, public Tuo {	//������


};

void test01() {
	SheepTuo st;
	st.Sheep::m_a = 18;
	st.Tuo::m_a = 28;
	//���μ̳�ʱ����������ӵ����ͬ���ݣ���Ҫ������������
	cout << "st.Sheep::m_a = " << st.Sheep::m_a << endl;
	cout << "st.Tuo::m_a = " << st.Tuo::m_a << endl;
	//�����������֪����ֻҪ��һ�ݾͿ����ˣ����μ̳е������������ݣ������Դ�˷�

	//��̳�֮�󣬲�����ֶ�����
	cout << "st.m_a = " << st.m_a << endl;
}

int main() {

	test01();

	system("pause");
	return 0;
}

//�ܽ᣺

//*���μ̳д�������Ҫ����������̳�������ͬ�����ݣ�������Դ�˷��Լ���������
//* ������̳п��Խ�����μ̳�����