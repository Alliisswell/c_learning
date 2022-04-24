#include<iostream>

using namespace std;

/*
**案例描述：**封装一个函数，利用冒泡排序，实现对整型数组的升序排序

例如数组：int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
*/


//冒泡排序函数	参数1	数组首地址（数组名）	参数2	数组长度  
void bubbleSort(int* arr, int len) {  //int* arr 也可以写成 int arr[]
	//总结：当数组名传入到函数作为参数时，被退化为指向首地址的指针
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0;j < len - 1 - i;j++) {
			if (arr[j]>arr[j+1]) {  //数组的索引方式决定了传递类型是值传递，因为arr[j]是下标为j的元素的地址，这样理解正确吗？
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1]=temp;
			}
		}
	}
}

//打印数组函数
void printArray(int* arr, int len) {
	for (int i = 0;i < len;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main8()
{

	//1、创建数组
	int arr[10] = {2,5,4,6,8,3,9,1,10,7};
	//数组长度
	int len = sizeof(arr) / sizeof(arr[0]);
	
	//2、创建函数，实现冒泡排序
	bubbleSort(arr, len);//既然数组名就是数组首地址，那么当然要用指针来接收，所以形参定义为指针类型变量 int* arr
	//另外，我们除了要将数组名传入函数外，为了规范化，我们还要将数组的大小也要作为参数传入，而不是在函数内部去定义大小。
	
	//3、打印排序后的数组
	printArray(arr, len);

	system("pause");

	return 0;
}

