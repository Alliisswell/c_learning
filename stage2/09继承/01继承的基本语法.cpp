#include<iostream>
using namespace std;

//��ͨʵ��ҳ��

////Javaҳ��
//class Java {
//
//public:
//	void Header() {
//		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
//	}
//	void Footer() {
//		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;
//	}
//	void Left() {
//		cout << "Java��Python��C++...�����������б�" << endl;
//	}
//	void Content() {
//		cout << "Javaѧ����Ƶ" << endl;
//	}
//
//};
//
////Pythonҳ��
//class Python {
//
//public:
//	void Header() {
//		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
//	}
//	void Footer() {
//		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;
//	}
//	void Left() {
//		cout << "Java��Python��C++...�����������б�" << endl;
//	}
//	void Content() {
//		cout << "Pythonѧ����Ƶ" << endl;
//	}
//
//};
//
////C++ҳ��
//class Cpp {
//
//public:
//	void Header() {
//		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
//	}
//	void Footer() {
//		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;
//	}
//	void Left() {
//		cout << "Java��Python��C++...�����������б�" << endl;
//	}
//	void Content() {
//		cout << "C++ѧ����Ƶ" << endl;
//	}
//
//};

//�̳�ʵ��ҳ��	
class BasePage {
public:
	void Header() {
		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
	}
	void Footer() {
		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;
	}
	void Left() {
		cout << "Java��Python��C++...�����������б�" << endl;
	}

};

//�ŵ㣺�����ظ�����
//�﷨��class ������ :�̳з�ʽ ������ {};
//����Ҳ��Ϊ������
//����Ҳ��Ϊ����


//Javaҳ��
class Java :public BasePage {
public:
	void Content() {
		cout << "Javaѧ����Ƶ" << endl;
	}

};
//Pythonҳ��
class Python :public BasePage {
public:
	void Content() {
		cout << "Pythonѧ����Ƶ" << endl;
	}

};
//C++ҳ��
class Cpp :public BasePage {
public:
	void Content() {
		cout << "C++ѧ����Ƶ" << endl;
	}

};

void test01() {
	cout << "Java������Ƶҳ�����£�" << endl;
	Java ja;
	ja.Header();
	ja.Footer();
	ja.Left();
	ja.Content();
	cout << "---------------------------------" << endl;

	cout << "Python������Ƶҳ�����£�" << endl;
	Python py;
	py.Header();
	py.Footer();
	py.Left();
	py.Content();
	cout << "---------------------------------" << endl;

	cout << "C++������Ƶҳ�����£�" << endl;
	Cpp cpp;
	cpp.Header();
	cpp.Footer();
	cpp.Left();
	cpp.Content();
	cout << "---------------------------------" << endl;
}




int main() {

	test01();

	system("pause");
	return 0;
}

/*
#include<iostream>
using namespace std;







int main() {



	system("pause");
	return 0;
}
*/