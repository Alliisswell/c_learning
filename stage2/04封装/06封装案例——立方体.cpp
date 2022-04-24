#include<iostream>

using namespace std;

//1������������
//2���������  ��������
//3�������Ϊ  ��ȡ��������������
//4���ֱ�����ȫ�ֺ����ͳ�Ա���� �ж������������Ƿ����

class Cube {
public:
	//���ó�
	void setL(int l) {
		m_l = l;
	}
	//��ȡ��
	int getL() {
		return m_l;
	}
	//���ÿ�
	void setW(int w) {
		m_w = w;
	}
	//��ȡ��
	int getW() {
		return m_w;
	}
	//���ø�
	void setH(int h) {
		m_h = h;
	}
	//��ȡ��
	int getH() {
		return m_h;
	}
	//��ȡ���������
	int calculateS() {
		return 2 * (m_l * m_w + m_w * m_h + m_h * m_l);
	}
	//��ȡ���������
	int calculateV() {
		return m_l * m_w * m_h;
	}
	//���ó�Ա�����ж� �����������Ƿ����
	bool isSameByClass(Cube& c) {
		if (getL() == c.getL() && getW() == c.getW() && getH() == c.getH()) {
			return true;
		}
		return false;
	}
private:
	int m_l = 0;	//��
	int m_w = 0;	//��
	int m_h = 0;	//��
};

//����ȫ�ֺ����ж� �����������Ƿ����
bool isSame(Cube& c1, Cube& c2) {	//ʹ�� ���� ����ԭʼ���ݣ������Ǹ������ݽ��뺯��
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH()) {
		return true;
	}
	return false;
}
int main() {
	//�������������
	Cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);

	cout << "c1�����Ϊ��" << c1.calculateS() << endl;
	cout << "c1�����Ϊ��" << c1.calculateV() << endl;

	//�����ڶ���������
	Cube c2;
	c2.setL(10);
	c2.setW(10);
	c2.setH(11);

	//����ȫ�ֺ����ж�
	bool ret = isSame(c1, c2);
	if (ret) {
		cout << "��Ա�����жϣ�c1��c2����ȵ�" << endl;
	}
	else {
		cout << "��Ա�����жϣ�c1��c2�ǲ���ȵ�" << endl;
	}

	//���ó�Ա�����ж�
	ret = c1.isSameByClass(c2);
	if (ret) {
		cout << "��Ա�����жϣ�c1��c2����ȵ�" << endl;
	}
	else {
		cout << "��Ա�����жϣ�c1��c2�ǲ���ȵ�" << endl;
	}

	system("pause");
	return 0;
}