#pragma once
//#pragma once��һ���Ƚϳ��õ�C/C++��ע��
//ֻҪ��ͷ�ļ����ʼ����������ע��
//���ܹ���֤ͷ�ļ�ֻ������һ�Ρ�
#include<iostream>
#include<string>
using namespace std;
struct Dis {
    string path;
    int value;
    bool visit;
    Dis() {
        visit = false;
        value = 0;
        path = "";
    }
};
class Graph_DG {
public:
    //���캯��
    Graph_DG(int vexnum, int edge);
    //��������
    ~Graph_DG();
    // �ж�����ÿ������ĵıߵ���Ϣ�Ƿ�Ϸ�
    //�����1��ʼ���
    bool check_edge_value(int start, int end, int weight);
    //����ͼ
    void createGraph();
    //��ӡ�ڽӾ���
    void print();
    //�����·��
    void Dijkstra(int begin);
    //��ӡ���·��
    void print_path(int);
private:
    int vexnum;   //ͼ�Ķ���(vertex)����
    int edge;     //ͼ�ı�(edge)��
    int** arc;   //�ڽӾ���
    Dis* dis;   //(distance)��¼�����������·������Ϣ
};
