#include <math.h>  //用到了abs(求整型数据的绝对值)
#include "Astar.h"

void Astar::InitAstar(vector<vector<int>>& _maze) {
	maze = _maze;
}

int Astar::calcG(Point* temp_start, Point* point) {  //起点经过父节点到当前节点的距离
	int extraG = (abs(point->x - temp_start->x) + abs(point->y - temp_start->y)) == 1 ? kCost1 : kCost2;
	int parentG = point->parent == NULL ? 0 : point->parent->G; //如果是初始节点，则其父节点是空
	return parentG + extraG;
}

int Astar::calcH(Point* point, Point* end) {  //当前点到终点的预估距离
	//用简单的欧几里得距离计算H，这个H的计算是关键，还有很多算法，没深入研究^_^
	return  ((double)(end->x - point->x) * (double)(end->x - point->x) + (double)(end->y - point->y) * (double)(end->y - point->y)) * kCost1;
	//这里系统会自动将double浮点型数据转换为int整型数据吧？
}

int Astar::calcF(Point* point) {  //起点到终点的预估距离
	return point->G + point->H;
}


list<Point*> Astar::GetPath(Point& startPoint, Point& endPoint, bool isIgnoreCorner) {  //isIgnoreCorner初始化为false
	Point* result = findPath(startPoint, endPoint, isIgnoreCorner);
	list<Point*> path;  //实例化路径
	//返回路径，如果没找到路径，返回空链表
	while (result) {
		path.push_front(result);
		result = result->parent;
	}

	// 清空临时开闭列表，防止重复执行GetPath导致结果异常
	openList.clear();
	closeList.clear();

	return path;
}

Point* Astar::findPath(Point& startPoint, Point& endPoint, bool isIgnoreCorner) {
	openList.push_back(new Point(startPoint.x, startPoint.y)); //置入起点,拷贝开辟一个节点，内外隔离
	while (!openList.empty()) {  //如果开启列表为空，则终止寻路
		Point* curPoint = getLeastFpoint(); //找到F值最小的点
		openList.remove(curPoint); //从开启列表中删除
		closeList.push_back(curPoint); //放到关闭列表
		//1,找到当前周围八个格中可以通过的格子
		vector<Point*> surroundPoints = getSurroundPoints(curPoint, isIgnoreCorner);
		for (auto& target : surroundPoints) { 
			//2,对某一个格子，如果它不在开启列表中，加入到开启列表，设置当前格为其父节点，计算F G H
			if (!isInList(openList, target)) {
				target->parent = curPoint;

				target->G = calcG(curPoint, target);
				target->H = calcH(target, &endPoint);
				target->F = calcF(target);

				openList.push_back(target);
			}
			//3，对某一个格子，它在开启列表中，计算G值, 如果比原来的大, 就什么都不做, 否则设置它的父节点为当前点,并更新G和F
			else {
				int tempG = calcG(curPoint, target);
				if (tempG < target->G) {
					target->parent = curPoint;

					target->G = tempG;
					target->F = calcF(target);
				}
			}
			Point* resPoint = isInList(openList, &endPoint);  //如果终点在开启列表中，则终止寻路并返回终点的指针
			if (resPoint)
				return resPoint; //返回列表里的节点指针，不要用原来传入的endpoint指针，因为发生了深拷贝
		}
	}
	return NULL;
}

Point* Astar::getLeastFpoint() {  //遍历开启列表，找到F值最小的点
	if (!openList.empty()) {  //判断开启列表是否为空
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

vector<Point*> Astar::getSurroundPoints(const Point* point, bool isIgnoreCorner) const {  //寻找当前点周围的八个格子中可以通过的格子
	vector<Point*> surroundPoints;
	for (int x = point->x - 1; x <= point->x + 1; x++) {
		for (int y = point->y - 1; y <= point->y + 1; y++) {
			if (isCanreach(point, new Point(x, y), isIgnoreCorner)) {  //new Point(x, y)匿名对象
				surroundPoints.push_back(new Point(x, y));
			}
		}
	}
	return surroundPoints;
}

bool Astar::isCanreach(const Point* point, const Point* target, bool isIgnoreCorner) const {
	//如果点(target)超出地图、是障碍物、与当前节点(point)重合、或者在关闭列表中，返回false
	if (target->x<0 || target->x>maze.size() - 1 || target->y<0 || target->y>maze[0].size() - 1  //超出地图条件
		|| maze[target->x][target->y] == 1  //障碍物条件
		|| target->x == point->x && target->y == point->y  //当前点重合条件
		|| isInList(closeList, target)) {  //在关闭列表条件
		return false;
	}	
	else {
		if (abs(point->x - target->x) + abs(point->y - target->y) == 1) {  //上下左右四个点  abs是数学函数，用来求整数的绝对值
			return true;
		}	
		else {
			//斜对角四个点要判断是否绊住，即斜对角点和当前点连线的两边两个点是否为障碍物
			if (maze[point->x][target->y] == 0 && maze[target->x][point->y] == 0) { //如果逻辑与，即不允许斜着走，如果逻辑或，即允许斜着走
				return true;
			}
			else {
				return isIgnoreCorner;  //isIgnoreCorner在GetPath()的参数列表中初始化为false,这里返回false即被绊住
			}		
		}
	}
}

Point* Astar::isInList(const list<Point*>& list, const Point* point) const {
	//判断某个节点是否在列表中，这里不能比较指针，因为每次加入列表是新开辟的节点，只能比较坐标
	for (auto& listpoint : list) {
		if (listpoint->x == point->x && listpoint->y == point->y) {
			return listpoint;
		}	
	}
	return NULL;
}