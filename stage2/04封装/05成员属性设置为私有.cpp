#include<iostream>
#include<string>

using namespace std;

//��Ա��������Ϊ˽�еĺô�
//**�ŵ�1��** �����г�Ա��������Ϊ˽�У�Ȼ��ͨ�����ýӿڣ�����Ȩ�޵ĳ�Ա��Ϊ�����������Լ����Ƴ�Ա���ԵĶ�дȨ��
//**�ŵ�2��** ����дȨ�ޣ����ǿ��Լ�����ݵ���Ч��

//�������
class Person {
public:
	//��������
	void setName(string name) {
		m_name = name;
	}
	//��ȡ����
	string getName() {
		return m_name;
	}

	//��������
	void setAge(int age) {  //����дȨ�ޣ����ǿ��Լ���û��������ݵ���Ч��
		if (age < 0 || age > 150) {
			m_age = 0;
			cout << "���������!" << endl;
			return;
		}
		m_age = age;
	}
	//��ȡ����
	int getAge() {
		m_age = 0;
		return m_age;
	}

	//��������
	void setLover(string lover) {
		m_lover = lover;
	}

private:
	string m_name = "����";	//����	�ɶ���д
	int m_age;	//����	�ɶ���д
	string m_lover;	//����	ֻд
};


int main() {

	Person p;
	//����	�ɶ���д
	p.setName("����");
	cout << "������" << p.getName() << endl;

	//����	�ɶ���д
	p.setAge(1000);
	cout << "���䣺" << p.getAge() << endl;

	//����	ֻд
	p.setLover("�־�");

	system("pause");
	return 0;
}