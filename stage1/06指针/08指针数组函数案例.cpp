#include<iostream>

using namespace std;

/*
**����������**��װһ������������ð������ʵ�ֶ������������������

�������飺int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
*/


//ð��������	����1	�����׵�ַ����������	����2	���鳤��  
void bubbleSort(int* arr, int len) {  //int* arr Ҳ����д�� int arr[]
	//�ܽ᣺�����������뵽������Ϊ����ʱ�����˻�Ϊָ���׵�ַ��ָ��
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0;j < len - 1 - i;j++) {
			if (arr[j]>arr[j+1]) {  //�����������ʽ�����˴���������ֵ���ݣ���Ϊarr[j]���±�Ϊj��Ԫ�صĵ�ַ�����������ȷ��
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1]=temp;
			}
		}
	}
}

//��ӡ���麯��
void printArray(int* arr, int len) {
	for (int i = 0;i < len;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main8()
{

	//1����������
	int arr[10] = {2,5,4,6,8,3,9,1,10,7};
	//���鳤��
	int len = sizeof(arr) / sizeof(arr[0]);
	
	//2������������ʵ��ð������
	bubbleSort(arr, len);//��Ȼ���������������׵�ַ����ô��ȻҪ��ָ�������գ������βζ���Ϊָ�����ͱ��� int* arr
	//���⣬���ǳ���Ҫ�����������뺯���⣬Ϊ�˹淶�������ǻ�Ҫ������Ĵ�СҲҪ��Ϊ�������룬�������ں����ڲ�ȥ�����С��
	
	//3����ӡ����������
	printArray(arr, len);

	system("pause");

	return 0;
}

