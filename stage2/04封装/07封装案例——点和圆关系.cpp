#include"circle.h"

////����
//class Point {
//public:
//	//����x
//	void setX(int x) {
//		m_x = x;
//	}
//	//��ȡx
//	int getX() {
//		return m_x;
//	}
//	//����y
//	void setY(int y) {
//		m_y = y;
//	}
//	//��ȡy
//	int getY() {
//		return m_y;
//	}
//private:
//	int m_x = 0;	//x����
//	int m_y = 0;	//y����
//};

////Բ��
//class Circle {
//public:
//	//���ð뾶
//	void setR(int r) {
//		m_r = r;
//	}
//	//��ȡ�뾶
//	int getR() {
//		return m_r;
//	}
//	//����Բ��
//	void setCenter(Point center) {
//		m_center = center;
//	}
//	//��ȡԲ��
//	Point getCenter() {
//		return m_center;
//	}
//private:
//	int m_r = 0;	//�뾶
//	//�����п�������һ������Ϊ�����еĳ�Ա
//	Point m_center;	//Բ��
//};

//�жϵ��Բ��ϵ
void isInCircle(Circle& c, Point& p) {
	//��������֮������ƽ��
	int distance =
		(c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	//����뾶��ƽ��
	int rdistance = c.getR() * c.getR();
	//�ж�
	if (distance == rdistance) {
		cout << "����Բ��" << endl;
	}
	else if (distance > rdistance) {
		cout << "����Բ��" << endl;
	}
	else {
		cout << "����Բ��" << endl;
	}
}
int main() {

	//����Բ��Բ��
	Circle c;
	c.setR(10);
	Point center;
	center.setX(10);
	center.setY(0);
	c.setCenter(center);

	//������
	Point p;
	p.setX(10);
	p.setY(10);

	//�жϹ�ϵ
	isInCircle(c, p);

	system("pause");
	return 0;
}