/*
�Ķ�ʱ�䣺2022/4/15
�Ķ��ˣ�������
����У�
*/


#include "Astar.h"

bool InPath(const int& row, const int& col, const list<Point*>& path) {  //�ж��жϵ�ͼ�����Ƿ�Ϊ·���㣬������������Ϊbool
    for (const auto& p : path) {
        if (row == p->x && col == p->y) {
            return true;
        }
    }
    return false;
}

int main() {
    //��ʼ����ͼ���ö�ά��������ͼ��1��ʾ�ϰ��0��ʾ��ͨ
    vector<vector<int>> map = { {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1},
                                {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
                                {1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1},
                                {1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
                                {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1},
                                {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };  //8*12��С�ĵ�ͼ
    Astar astar;  //ʵ��������
    astar.InitAstar(map);  //��ʼ���㷨��ͼ

    //������ʼ�ͽ�����
    Point start(1, 1);
    Point end(1, 10);

    //����·�������յ�������
    list<Point*> path = astar.GetPath(start, end, false);

    // ��ӡ·���������
    //auto��ԭ����Ǹ��ݺ����ֵ�����Լ��Ʋ�ǰ���������ʲô
    //auto�����þ���Ϊ�˼򻯱�����ʼ����������������һ���ܳ��ܳ��ĳ�ʼ�����ͣ��Ϳ�����auto����
    //auto& it : path === list<Point*>::iterator it = path.begin(); it != path.end(); it ++
    //for (auto& it : path) {  
    //    cout << "(" << it->x << "," << it->y << ") ";
    //}
    //cout << "\n";
    for (list<Point*>::iterator it = path.begin(); it != path.end(); it++) {  
        cout << "(" << (*it)->x << "," << (*it)->y << ") ";
    }
    cout << "\n";

    //��ӡ�� * ����·����ĵ�ͼ  ��ӡ����ı�׼�㷨
    for (int row = 0; row < map.size(); ++row) {  //��ӡ��
        for (int col = 0; col < map[0].size(); ++col) {  //��ӡ��
            if (InPath(row, col, path)) {  //�жϵ�ͼ�����Ƿ�Ϊ·���㣬������������Ϊbool
                //if (map[row][col] != 0) {  //��·�������� * ������Ķ����ж�ע�͵�֮�������������
                //    cout << "e ";
                //}
                //else {
                    cout << "* ";
                //}
            }
            else {  //����·����
                cout << map[row][col] << " ";
            }
        }
        cout << "\n";
    }
    system("pause");
    return 0;
}