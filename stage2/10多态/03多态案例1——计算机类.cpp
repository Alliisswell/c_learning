#include<iostream>
using namespace std;

//����������
//�ֱ�������ͨд���Ͷ�̬���������ʵ��������������������ļ�������

//������ͨд��ʵ�ּ�����
class Caculator {

public:
	int getResult(string oper) {
		if (oper == "+") {
			return m_num1 + m_num2;
		}
		else if (oper == "-") {
			return m_num1 - m_num2;
		} 
		else if(oper == "*") {
			return m_num1 * m_num2;
		}
	}
	
	//�������չ�µĹ��ܣ���Ҫ�޸�Դ��
	//����ʵ�����У��ᳫ ����ԭ��
	//����ԭ�򣺶���չ���п��������޸Ľ��йر�

	int m_num1;	//������1
	int m_num2;	//������2
};

//���ö�̬ʵ�ּ�����
//��̬���ŵ㣺
//* ������֯�ṹ����
//* �ɶ���ǿ
//* ����ǰ�ںͺ��ڵ���չ�Լ�ά��

//ʵ�ּ����������
class AbstractCaculator {

public:
	virtual int getResult() {
		return 0;
	}

	int m_num1;
	int m_num2;
};

//�ӷ���������
class addCaculator :public AbstractCaculator {

public:
	int getResult() {
		return m_num1 + m_num2;
	}

};

//������������
class subCaculator :public AbstractCaculator {

public:
	int getResult() {
		return m_num1 - m_num2;
	}

};

//�˷���������
class mulCaculator :public AbstractCaculator {

public:
	int getResult() {
		return m_num1 * m_num2;
	}

};

void test01() {
	Caculator c;
	c.m_num1 = 10;
	c.m_num2 = 10;
	
	cout << c.m_num1 << " + " << c.m_num2 << " = " << c.getResult("+") << endl;
	cout << c.m_num1 << " - " << c.m_num2 << " = " << c.getResult("-") << endl;
	cout << c.m_num1 << " * " << c.m_num2 << " = " << c.getResult("*") << endl;
}

void test02() {
	//��̬��̬ʹ��
	//�����ָ������� ָ���������

	//�ӷ�����
	AbstractCaculator* abc = new addCaculator;
	abc->m_num1 = 100;
	abc->m_num2 = 100;
	cout << abc->m_num1 << " + " << abc->m_num2 << " = " << abc->getResult() << endl;
	//�����ǵ�����
	delete abc;

	//��������
	abc = new subCaculator;
	abc->m_num1 = 100;
	abc->m_num2 = 100;
	cout << abc->m_num1 << " - " << abc->m_num2 << " = " << abc->getResult() << endl;
	delete abc;

	//�˷�����
	abc = new mulCaculator;
	abc->m_num1 = 100;
	abc->m_num2 = 100;
	cout << abc->m_num1 << " * " << abc->m_num2 << " = " << abc->getResult() << endl;
	delete abc;
}




int main() {

	//test01();

	test02();

	system("pause");
	return 0;
}