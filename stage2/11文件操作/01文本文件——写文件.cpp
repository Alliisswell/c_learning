#include<iostream>
using namespace std;
#include<fstream>	//ϵͳͷ�ļ��� <>
#include<string>

/*
��������ʱ���������ݶ�������ʱ���ݣ�����һ�����н������ᱻ�ͷ�

ͨ��**�ļ����Խ����ݳ־û�**

C++�ж��ļ�������Ҫ����ͷ�ļ� == fstream ==

�ļ����ͷ�Ϊ���֣�

1. **�ı��ļ�**   -  �ļ����ı���**ASCII��**��ʽ�洢�ڼ������
2. **�������ļ�** -  �ļ����ı���**������**��ʽ�洢�ڼ�����У��û�һ�㲻��ֱ�Ӷ�������

�����ļ���������:

1. ofstream��д����
2. ifstream��������
3. fstream ����д����
*/

void test01() {
	//1������ͷ�ļ�  fstream
	
	////2������������

	//ofstream ofs;

	////3��ָ���򿪷�ʽ
	//ofs.open("test.txt",ios::out);  //�ļ�·�������Ǿ���·�������·�����ļ�����ֻд�ļ�����·����Դ�ļ���ͬ��

	//2��3�������Ժ�Ϊһ��,���õ���ofs����������Ĺ��캯��
	ofstream ofs("test.txt", ios::out);

	//4��д����
	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺18" << endl;

	//5���ر��ļ�
	ofs.close();

}

int main() {

	test01();

	system("pause");
	return 0;
}

/*
#include<iostream>
using namespace std;






int main(){



	system("pause");
	return 0;
}
*/

