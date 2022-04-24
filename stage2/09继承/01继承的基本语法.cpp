#include<iostream>
using namespace std;

//普通实现页面

////Java页面
//class Java {
//
//public:
//	void Header() {
//		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
//	}
//	void Footer() {
//		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
//	}
//	void Left() {
//		cout << "Java、Python、C++...（公共分类列表）" << endl;
//	}
//	void Content() {
//		cout << "Java学科视频" << endl;
//	}
//
//};
//
////Python页面
//class Python {
//
//public:
//	void Header() {
//		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
//	}
//	void Footer() {
//		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
//	}
//	void Left() {
//		cout << "Java、Python、C++...（公共分类列表）" << endl;
//	}
//	void Content() {
//		cout << "Python学科视频" << endl;
//	}
//
//};
//
////C++页面
//class Cpp {
//
//public:
//	void Header() {
//		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
//	}
//	void Footer() {
//		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
//	}
//	void Left() {
//		cout << "Java、Python、C++...（公共分类列表）" << endl;
//	}
//	void Content() {
//		cout << "C++学科视频" << endl;
//	}
//
//};

//继承实现页面	
class BasePage {
public:
	void Header() {
		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
	}
	void Footer() {
		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl;
	}
	void Left() {
		cout << "Java、Python、C++...（公共分类列表）" << endl;
	}

};

//优点：减少重复代码
//语法：class 子类名 :继承方式 父类名 {};
//子类也称为派生类
//父类也称为基类


//Java页面
class Java :public BasePage {
public:
	void Content() {
		cout << "Java学科视频" << endl;
	}

};
//Python页面
class Python :public BasePage {
public:
	void Content() {
		cout << "Python学科视频" << endl;
	}

};
//C++页面
class Cpp :public BasePage {
public:
	void Content() {
		cout << "C++学科视频" << endl;
	}

};

void test01() {
	cout << "Java下载视频页面如下：" << endl;
	Java ja;
	ja.Header();
	ja.Footer();
	ja.Left();
	ja.Content();
	cout << "---------------------------------" << endl;

	cout << "Python下载视频页面如下：" << endl;
	Python py;
	py.Header();
	py.Footer();
	py.Left();
	py.Content();
	cout << "---------------------------------" << endl;

	cout << "C++下载视频页面如下：" << endl;
	Cpp cpp;
	cpp.Header();
	cpp.Footer();
	cpp.Left();
	cpp.Content();
	cout << "---------------------------------" << endl;
}




int main() {

	test01();

	system("pause");
	return 0;
}

/*
#include<iostream>
using namespace std;







int main() {



	system("pause");
	return 0;
}
*/