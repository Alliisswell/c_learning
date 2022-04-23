#include"Dijkstra.h"
//���캯��
Graph_DG::Graph_DG(int vexnum, int edge) {
    //��ʼ���������ͱ���
    this->vexnum = vexnum;
    this->edge = edge;
    //Ϊ�ڽӾ��󿪱ٿռ�͸���ֵ
    arc = new int* [this->vexnum];
    dis = new Dis[this->vexnum];
    for (int i = 0; i < this->vexnum; i++) {
        arc[i] = new int[this->vexnum];
        for (int k = 0; k < this->vexnum; k++) {
            //�ڽӾ����ʼ��Ϊ�����
            arc[i][k] = INT_MAX;
        }
    }
}
//��������
Graph_DG::~Graph_DG() {
    delete[] dis;
    for (int i = 0; i < this->vexnum; i++) {
        delete this->arc[i];
    }
    delete arc;
}
// �ж�����ÿ������ĵıߵ���Ϣ�Ƿ�Ϸ�
//�����1��ʼ���
bool Graph_DG::check_edge_value(int start, int end, int weight) {
    if (start<1 || end<1 || start>vexnum || end>vexnum || weight < 0) {
        return false;
    }
    return true;
}
void Graph_DG::createGraph() {
    cout << "������ÿ���ߵ������յ㣨�����Ŵ�1��ʼ���Լ���Ȩ��" << endl;
    int start;
    int end;
    int weight;
    int count = 0;
    while (count != this->edge) {
        cin >> start >> end >> weight;
        //�����жϱߵ���Ϣ�Ƿ�Ϸ�
        while (!this->check_edge_value(start, end, weight)) {
            cout << "����ıߵ���Ϣ���Ϸ�������������" << endl;
            cin >> start >> end >> weight;
        }
        //���ڽӾ����Ӧ�ϵĵ㸳ֵ
        arc[start - 1][end - 1] = weight;
        //����ͼ��������д���
        arc[end - 1][start - 1] = weight;
        ++count;
    }
}
void Graph_DG::print() {
    cout << "ͼ���ڽӾ���Ϊ��" << endl;
    int count_row = 0; //��ӡ�еı�ǩ
    int count_col = 0; //��ӡ�еı�ǩ
    //��ʼ��ӡ
    while (count_row != this->vexnum) {
        count_col = 0;
        while (count_col != this->vexnum) {
            if (arc[count_row][count_col] == INT_MAX)
                cout << "��" << " ";
            else
                cout << arc[count_row][count_col] << " ";
            ++count_col;
        }
        cout << endl;
        ++count_row;
    }
}
void Graph_DG::Dijkstra(int begin) {
    //���ȳ�ʼ�����ǵ�dis�����value��path
    int i;
    for (i = 0; i < this->vexnum; i++) {
        dis[i].path = "v" + to_string(begin) + "-->v" + to_string(i + 1);
        dis[i].value = arc[begin - 1][i];  //�ڽӾ����һ�и�ֵ��dis����
    }
    //�������ĵ�����valueΪ0���������뵽���㼯
    dis[begin - 1].value = 0;
    dis[begin - 1].visit = true;

    int count = 1;
    //���������Ķ����value��С��·����ʣ��this->vexnum-1�����㣩
    while (count != this->vexnum) {
        //��dis�����е�value���бȽϣ��ҳ�value��С���Ǹ�����
        //temp���ڱ��浱ǰdis������value��С���Ǹ������±�
        //min��¼�ĵ�ǰ����Сֵ      
        int temp = 0;
        int min = INT_MAX;
        for (i = 0; i < this->vexnum; i++) {
            if (!dis[i].visit && dis[i].value < min) {
                min = dis[i].value;
                temp = i;
            }
        }
        //cout << temp + 1 << "  "<<min << endl;
        //��temp��Ӧ�Ķ�����뵽���㼯
        dis[temp].visit = true;
        ++count;
        //�ҵ�value��С��֮�󣬸��¸ö���ɵ���Ķ����value��path
        for (i = 0; i < this->vexnum; i++) {
            //ע�����������arc[temp][i]!=INT_MAX����ӣ���Ȼ�����������Ӷ���ɳ����쳣
            if (!dis[i].visit && arc[temp][i] != INT_MAX && (dis[temp].value + arc[temp][i]) < dis[i].value) {
                //�����valueС��ԭ����value���Ǿ;͸��¸ö����value��path
                dis[i].value = dis[temp].value + arc[temp][i];
                dis[i].path = dis[temp].path + "-->v" + to_string(i + 1);
            }
        }
    }
}
void Graph_DG::print_path(int begin) {
    string str;
    str = "v" + to_string(begin);
    cout << "��" << str << "Ϊ����ͼ�����·��Ϊ��" << endl;
    for (int i = 0; i != this->vexnum; i++) {
        if (dis[i].value != INT_MAX)
            cout << dis[i].path << "=" << dis[i].value << endl;
        else {
            cout << dis[i].path << "�������·����" << endl;
        }
    }
}