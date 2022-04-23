/*
阅读时间：2022/4/15
阅读人：李晓宁
读后感：
*/


#include "Astar.h"

bool InPath(const int& row, const int& col, const list<Point*>& path) {  //判断判断地图各点是否为路径点，返回数据类型为bool
    for (const auto& p : path) {
        if (row == p->x && col == p->y) {
            return true;
        }
    }
    return false;
}

int main() {
    //初始化地图，用二维矩阵代表地图，1表示障碍物，0表示可通
    vector<vector<int>> map = { {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1},
                                {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
                                {1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1},
                                {1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
                                {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1},
                                {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };  //8*12大小的地图
    Astar astar;  //实例化对象
    astar.InitAstar(map);  //初始化算法地图

    //设置起始和结束点
    Point start(1, 1);
    Point end(1, 10);

    //接收路径，接收的是链表
    list<Point*> path = astar.GetPath(start, end, false);

    // 打印路径点的坐标
    //auto的原理就是根据后面的值，来自己推测前面的类型是什么
    //auto的作用就是为了简化变量初始化，如果这个变量有一个很长很长的初始化类型，就可以用auto代替
    //auto& it : path === list<Point*>::iterator it = path.begin(); it != path.end(); it ++
    //for (auto& it : path) {  
    //    cout << "(" << it->x << "," << it->y << ") ";
    //}
    //cout << "\n";
    for (list<Point*>::iterator it = path.begin(); it != path.end(); it++) {  
        cout << "(" << (*it)->x << "," << (*it)->y << ") ";
    }
    cout << "\n";

    //打印用 * 代替路径点的地图  打印矩阵的标准算法
    for (int row = 0; row < map.size(); ++row) {  //打印行
        for (int col = 0; col < map[0].size(); ++col) {  //打印列
            if (InPath(row, col, path)) {  //判断地图各点是否为路径点，返回数据类型为bool
                //if (map[row][col] != 0) {  //是路径点就输出 * ，这里的二次判断注释掉之后程序正常运行
                //    cout << "e ";
                //}
                //else {
                    cout << "* ";
                //}
            }
            else {  //不是路径点
                cout << map[row][col] << " ";
            }
        }
        cout << "\n";
    }
    system("pause");
    return 0;
}