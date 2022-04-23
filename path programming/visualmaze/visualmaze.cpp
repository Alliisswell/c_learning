#include <graphics.h>
#include <Windows.h>
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

#define WIDTH 800//�ֱ���
#define HEIGHT 600
#define BLOCK_XY 20//С����߳�
const int BLOCK_WIDTH = WIDTH / (BLOCK_XY);//x��С��������
const int BLOCK_HEIGHT = HEIGHT / (BLOCK_XY);//y��С��������

#define kongqi COLORREF RGB(200,200,200)//������ɫ����ɫ
#define qiangbi COLORREF RGB(50,50,50)//ǽ����ɫ����ɫ
#define daixuan COLORREF RGB(0,255,0)//��ѡ��ɫ����ɫ
#define xuanzhong COLORREF RGB(255,0,0)//ѡ����ɫ����ɫ

struct block {
public:
	int x;
	int y;
	block(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int map[BLOCK_WIDTH][BLOCK_HEIGHT];
vector<block*> openlist;//��ѡ�б�
vector<block*> list;

/*��������*/
void clearscreen(COLORREF RGB);//��յ�ͼΪRGB��ɫ(��������)
void gamedrawpixal(int x, int y, COLORREF RGB);//��x��yλ�û���ɫΪRGB�ķ���
void init();//��ʼ��
void join(int x, int y);//��x,y���ܲ���·��·������ѡ�б�
void display();//ˢ����Ļ
void prim_main();//prim��ѭ��
void through(int x, int y);//��x,y��������һ������Ѿ����·��·���ͨ
/*********/

void init() {
	openlist.clear();
	/*��ͼ��ʼ��Ϊǽ*/
	for (int y = 0; y < BLOCK_HEIGHT; y++) {
		for (int x = 0; x < BLOCK_WIDTH; x++) {
			map[x][y] = 1;
		}
	}
	/*���ѡһ��·�㣬�������·*/
	map[1][1] = 0;
	/*��·�����ܲ���·��·������ѡ�б�*/
	join(1, 1);
	prim_main();
}

void prim_main() {
	while (openlist.size() > 0) {
		/*�Ӵ�ѡ·�����ѡһ��·��A*/
		int AIndexea = rand() % openlist.size();
		block* A = openlist[AIndexea];
		/*��A��������һ������Ѿ����·��·���ͨ*/
		through(A->x, A->y);
		/*��A���·*/
		map[A->x][A->y] = 0;
		/*��A���ܲ���·��·������ѡ�б�*///(ע�⣬��Ҫ�ظ����·�㣡)
		join(A->x, A->y);
		/*�Ӵ�ѡ·�����Ƴ�A*/
		openlist.erase(openlist.begin() + AIndexea);

		gamedrawpixal(A->x, A->y, xuanzhong);
		FlushBatchDraw();
		display();
	}
	openlist.clear();
}

void through(int x, int y) {
	list.clear();
	//��
	if (y - 2 >= 0 && map[x][y - 2] == 0) {
		block* a = new block(x, y - 1);
		list.push_back(a);
	}
	//��
	if (y + 2 <= BLOCK_HEIGHT && map[x][y + 2] == 0) {
		block* b = new block(x, y + 1);
		list.push_back(b);
	}
	//��
	if (x - 2 >= 0 && map[x - 2][y] == 0) {
		block* c = new block(x - 1, y);
		list.push_back(c);
	}
	//��
	if (x + 2 <= BLOCK_WIDTH && map[x + 2][y] == 0) {
		block* d = new block(x + 1, y);
		list.push_back(d);
	}
	int BIndexea = rand() % list.size();
	block* B = list[BIndexea];
	/*��x��y��B��ͨ*/
	map[B->x][B->y] = 0;
}

void join(int x, int y) {
	//��
	if (y - 2 >= 0 && map[x][y - 2] == 1) {
		block* a = new block(x, y - 2);
		openlist.push_back(a);
		map[x][y - 2] = 2;
	}
	//��
	if (y + 2 <= BLOCK_HEIGHT && map[x][y + 2] == 1) {
		block* b = new block(x, y + 2);
		openlist.push_back(b);
		map[x][y + 2] = 2;
	}
	//��
	if (x - 2 >= 0 && map[x - 2][y] == 1) {
		block* c = new block(x - 2, y);
		openlist.push_back(c);
		map[x - 2][y] = 2;
	}
	//��
	if (x + 2 <= BLOCK_WIDTH && map[x + 2][y] == 1) {
		block* d = new block(x + 2, y);
		openlist.push_back(d);
		map[x + 2][y] = 2;
	}
}

void display() {
	for (int y = 0; y < BLOCK_HEIGHT; y++) {
		for (int x = 0; x < BLOCK_WIDTH; x++) {
			if (map[x][y] == 1) {
				gamedrawpixal(x, y, qiangbi);
			}
			else if (map[x][y] == 0) {
				gamedrawpixal(x, y, kongqi);
			}
			else if (map[x][y] == 2) {
				gamedrawpixal(x, y, daixuan);
			}
		}
	}
	FlushBatchDraw();
}

void clearscreen(COLORREF RGB) {
	for (int y = 0; y < BLOCK_HEIGHT; y++) {
		for (int x = 0; x < BLOCK_WIDTH; x++) {
			gamedrawpixal(x, y, RGB);
		}
	}
}

void gamedrawpixal(int x, int y, COLORREF RGB) {
	setfillcolor(RGB); setlinecolor(COLORREF RGB(0, 0, 0));
	fillrectangle(x * BLOCK_XY, y * BLOCK_XY, BLOCK_XY + x * BLOCK_XY, BLOCK_XY + y * BLOCK_XY);
}

int main() {
	srand((unsigned)time(NULL));	//���������
	initgraph(WIDTH, HEIGHT);//������ͼ����
	BeginBatchDraw();//��ʼ������ͼ
	cleardevice();//�����ʾ


	init();
	display();
	//FlushBatchDraw();//�������������Ļ



	while (1);
}