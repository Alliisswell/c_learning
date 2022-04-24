#include"circle.h"

////点类
//class Point {
//public:
//	//设置x
//	void setX(int x) {
//		m_x = x;
//	}
//	//获取x
//	int getX() {
//		return m_x;
//	}
//	//设置y
//	void setY(int y) {
//		m_y = y;
//	}
//	//获取y
//	int getY() {
//		return m_y;
//	}
//private:
//	int m_x = 0;	//x坐标
//	int m_y = 0;	//y坐标
//};

////圆类
//class Circle {
//public:
//	//设置半径
//	void setR(int r) {
//		m_r = r;
//	}
//	//获取半径
//	int getR() {
//		return m_r;
//	}
//	//设置圆心
//	void setCenter(Point center) {
//		m_center = center;
//	}
//	//获取圆心
//	Point getCenter() {
//		return m_center;
//	}
//private:
//	int m_r = 0;	//半径
//	//在类中可以让另一个类作为本类中的成员
//	Point m_center;	//圆心
//};

//判断点和圆关系
void isInCircle(Circle& c, Point& p) {
	//计算两点之间距离的平方
	int distance =
		(c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	//计算半径的平方
	int rdistance = c.getR() * c.getR();
	//判断
	if (distance == rdistance) {
		cout << "点在圆上" << endl;
	}
	else if (distance > rdistance) {
		cout << "点在圆外" << endl;
	}
	else {
		cout << "点在圆内" << endl;
	}
}
int main() {

	//创建圆和圆心
	Circle c;
	c.setR(10);
	Point center;
	center.setX(10);
	center.setY(0);
	c.setCenter(center);

	//创建点
	Point p;
	p.setX(10);
	p.setY(10);

	//判断关系
	isInCircle(c, p);

	system("pause");
	return 0;
}