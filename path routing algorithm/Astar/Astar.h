#pragma once
#include<iostream>
using namespace std;
#include <vector>
#include <list>


const int kCost1 = 10; //ֱ��һ������
const int kCost2 = 14; //б��һ������

struct Point
{
	int x, y; //�����꣬����Ϊ�˷��㰴��C++�����������㣬x������ţ�y��������
	int F, G, H; //F=G+H��·������
	Point* parent; //���ڵ�
	Point(int _x, int _y) :x(_x), y(_y), F(0), G(0), H(0), parent(NULL)  //�����вι��캯����ʼ������
	{
	}
};

class Astar
{
public:
	void InitAstar(vector<vector<int>>& _maze);
	list<Point*> GetPath(Point& startPoint, Point& endPoint, bool isIgnoreCorner);

private:
	Point* findPath(Point& startPoint, Point& endPoint, bool isIgnoreCorner);
	vector<Point*> getSurroundPoints(const Point* point, bool isIgnoreCorner) const;
	bool isCanreach(const Point* point, const Point* target, bool isIgnoreCorner) const; //�ж�ĳ���Ƿ����������һ���ж�
	Point* isInList(const list<Point*>& list, const Point* point) const; //�жϿ���/�ر��б����Ƿ����ĳ��
	Point* getLeastFpoint(); //�ӿ����б��з���Fֵ��С�Ľڵ�
	//����FGHֵ
	int calcG(Point* temp_start, Point* point);
	int calcH(Point* point, Point* end);
	int calcF(Point* point);
private:
	vector<vector<int>> maze;
	list<Point*> openList;  //�����б�
	list<Point*> closeList; //�ر��б�
};