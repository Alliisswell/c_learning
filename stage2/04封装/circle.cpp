#include"circle.h"

//设置半径
void Circle::setR(int r) {
	m_r = r;
}
//获取半径
int Circle::getR() {
	return m_r;
}
//设置圆心
void Circle::setCenter(Point center) {
	m_center = center;
}
//获取圆心
Point Circle::getCenter() {
	return m_center;
}
