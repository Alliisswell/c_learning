#include"circle.h"

//���ð뾶
void Circle::setR(int r) {
	m_r = r;
}
//��ȡ�뾶
int Circle::getR() {
	return m_r;
}
//����Բ��
void Circle::setCenter(Point center) {
	m_center = center;
}
//��ȡԲ��
Point Circle::getCenter() {
	return m_center;
}
