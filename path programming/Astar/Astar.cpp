#include <math.h>  //�õ���abs(���������ݵľ���ֵ)
#include "Astar.h"

void Astar::InitAstar(vector<vector<int>>& _maze) {
	maze = _maze;
}

int Astar::calcG(Point* temp_start, Point* point) {  //��㾭�����ڵ㵽��ǰ�ڵ�ľ���
	int extraG = (abs(point->x - temp_start->x) + abs(point->y - temp_start->y)) == 1 ? kCost1 : kCost2;
	int parentG = point->parent == NULL ? 0 : point->parent->G; //����ǳ�ʼ�ڵ㣬���丸�ڵ��ǿ�
	return parentG + extraG;
}

int Astar::calcH(Point* point, Point* end) {  //��ǰ�㵽�յ��Ԥ������
	//�ü򵥵�ŷ����þ������H�����H�ļ����ǹؼ������кܶ��㷨��û�����о�^_^
	return  ((double)(end->x - point->x) * (double)(end->x - point->x) + (double)(end->y - point->y) * (double)(end->y - point->y)) * kCost1;
	//����ϵͳ���Զ���double����������ת��Ϊint�������ݰɣ�
}

int Astar::calcF(Point* point) {  //��㵽�յ��Ԥ������
	return point->G + point->H;
}


list<Point*> Astar::GetPath(Point& startPoint, Point& endPoint, bool isIgnoreCorner) {  //isIgnoreCorner��ʼ��Ϊfalse
	Point* result = findPath(startPoint, endPoint, isIgnoreCorner);
	list<Point*> path;  //ʵ����·��
	//����·�������û�ҵ�·�������ؿ�����
	while (result) {
		path.push_front(result);
		result = result->parent;
	}

	// �����ʱ�����б���ֹ�ظ�ִ��GetPath���½���쳣
	openList.clear();
	closeList.clear();

	return path;
}

Point* Astar::findPath(Point& startPoint, Point& endPoint, bool isIgnoreCorner) {
	openList.push_back(new Point(startPoint.x, startPoint.y)); //�������,��������һ���ڵ㣬�������
	while (!openList.empty()) {  //��������б�Ϊ�գ�����ֹѰ·
		Point* curPoint = getLeastFpoint(); //�ҵ�Fֵ��С�ĵ�
		openList.remove(curPoint); //�ӿ����б���ɾ��
		closeList.push_back(curPoint); //�ŵ��ر��б�
		//1,�ҵ���ǰ��Χ�˸����п���ͨ���ĸ���
		vector<Point*> surroundPoints = getSurroundPoints(curPoint, isIgnoreCorner);
		for (auto& target : surroundPoints) { 
			//2,��ĳһ�����ӣ���������ڿ����б��У����뵽�����б����õ�ǰ��Ϊ�丸�ڵ㣬����F G H
			if (!isInList(openList, target)) {
				target->parent = curPoint;

				target->G = calcG(curPoint, target);
				target->H = calcH(target, &endPoint);
				target->F = calcF(target);

				openList.push_back(target);
			}
			//3����ĳһ�����ӣ����ڿ����б��У�����Gֵ, �����ԭ���Ĵ�, ��ʲô������, �����������ĸ��ڵ�Ϊ��ǰ��,������G��F
			else {
				int tempG = calcG(curPoint, target);
				if (tempG < target->G) {
					target->parent = curPoint;

					target->G = tempG;
					target->F = calcF(target);
				}
			}
			Point* resPoint = isInList(openList, &endPoint);  //����յ��ڿ����б��У�����ֹѰ·�������յ��ָ��
			if (resPoint)
				return resPoint; //�����б���Ľڵ�ָ�룬��Ҫ��ԭ�������endpointָ�룬��Ϊ���������
		}
	}
	return NULL;
}

Point* Astar::getLeastFpoint() {  //���������б��ҵ�Fֵ��С�ĵ�
	if (!openList.empty()) {  //�жϿ����б��Ƿ�Ϊ��
		Point* resPoint = openList.front();
		for (auto& point : openList) {  //auto& point : openList === list<Point*>::iterator point = openList.begin(); point != openList.end(); point ++
			if (resPoint->F > point->F) {
				resPoint = point;
			}	
			return resPoint;
		}  		
	}
	return NULL;
}

vector<Point*> Astar::getSurroundPoints(const Point* point, bool isIgnoreCorner) const {  //Ѱ�ҵ�ǰ����Χ�İ˸������п���ͨ���ĸ���
	vector<Point*> surroundPoints;
	for (int x = point->x - 1; x <= point->x + 1; x++) {
		for (int y = point->y - 1; y <= point->y + 1; y++) {
			if (isCanreach(point, new Point(x, y), isIgnoreCorner)) {  //new Point(x, y)��������
				surroundPoints.push_back(new Point(x, y));
			}
		}
	}
	return surroundPoints;
}

bool Astar::isCanreach(const Point* point, const Point* target, bool isIgnoreCorner) const {
	//�����(target)������ͼ�����ϰ���뵱ǰ�ڵ�(point)�غϡ������ڹر��б��У�����false
	if (target->x<0 || target->x>maze.size() - 1 || target->y<0 || target->y>maze[0].size() - 1  //������ͼ����
		|| maze[target->x][target->y] == 1  //�ϰ�������
		|| target->x == point->x && target->y == point->y  //��ǰ���غ�����
		|| isInList(closeList, target)) {  //�ڹر��б�����
		return false;
	}	
	else {
		if (abs(point->x - target->x) + abs(point->y - target->y) == 1) {  //���������ĸ���  abs����ѧ�����������������ľ���ֵ
			return true;
		}	
		else {
			//б�Խ��ĸ���Ҫ�ж��Ƿ��ס����б�Խǵ�͵�ǰ�����ߵ������������Ƿ�Ϊ�ϰ���
			if (maze[point->x][target->y] == 0 && maze[target->x][point->y] == 0) { //����߼��룬��������б���ߣ�����߼��򣬼�����б����
				return true;
			}
			else {
				return isIgnoreCorner;  //isIgnoreCorner��GetPath()�Ĳ����б��г�ʼ��Ϊfalse,���ﷵ��false������ס
			}		
		}
	}
}

Point* Astar::isInList(const list<Point*>& list, const Point* point) const {
	//�ж�ĳ���ڵ��Ƿ����б��У����ﲻ�ܱȽ�ָ�룬��Ϊÿ�μ����б����¿��ٵĽڵ㣬ֻ�ܱȽ�����
	for (auto& listpoint : list) {
		if (listpoint->x == point->x && listpoint->y == point->y) {
			return listpoint;
		}	
	}
	return NULL;
}