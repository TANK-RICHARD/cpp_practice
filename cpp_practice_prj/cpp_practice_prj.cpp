// cpp_practice_prj.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

//int main()
//{
//    std::cout << "Hello World!\n";
//}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件


//----------------------- friend function ---------------------------------------
#if 0
class Box
{
public:
	void setWidth(double width);
	double getWidth(Box &box);
	friend void printWidth(Box& box); // if no this declare, can not print width

private:
	double width;
};

void Box::setWidth(double w)
{
	width = w;
}

double Box::getWidth(Box& box)
{
	return width;
}

// friend function
void printWidth(Box& box)
{
	cout << "width of box: " << box.width << endl;
}

int main()
{
	Box box;
	Box& box_ref = box;
	box.setWidth(10.4);
	printWidth(box_ref);

	return 0;
}
#endif

//------------------------ this pointer -----------------------------
#if 0
class Box
{
public:
	// constructor
	Box(double l, double b, double h);
	double volume();
	int compare(Box box);
private:
	double length;
	double breadth;
	double heigth;
};

Box::Box(double l = 2.0, double b = 2.0, double h = 2.0)
{
	cout << "constructor" << endl;
	length = l;
	breadth = b;
	heigth = h;
}

double Box::volume(void)
{
	return length * breadth * heigth;
}

int Box::compare(Box box)
{
	cout << "this->volume(): " << this->volume() << endl;
	cout << "box.volume(): " << box.volume() << endl;
	cout << "this->breadth: " << this->breadth << endl;
	return this->volume() > box.volume(); // this pointer
}

int main(void)
{
	Box box1(3.3, 1.2, 1.5);
	Box box2(4.5, 6.6, 8.8);

	if (box1.compare(box2)) {
		cout << "box1 is bigger than box2" << endl;
	} else {
		cout << "box2 is bigger than box1" << endl;
	}
}
#endif

//----------------------- pointer of class ---------------------------------------
#if 0
class Box
{
public:
	Box(double l, double b, double h);
	double volume();
private:
	double length;
	double breadth;
	double height;
};

Box::Box(double l = 3.0, double b = 1.2, double h = 2.3)
{
	length = l;
	breadth = b;
	height = h;
}

double Box::volume(void)
{
	return length * breadth * height;
}

int main()
{
	Box box1(3.3, 4.5, 2.5);
	Box box2(3.2, 1.2, 7.7);
	Box* pBox;

	pBox = &box1; // just like normal pointer
	cout << "volume of box1: " << pBox->volume() << endl;

	pBox = &box2;
	cout << "volume of box1: " << pBox->volume() << endl;

	return 0;
}
#endif

//----------------- static variable of class ---------------------------
#if 0
class Box
{
public:
	/* static variable */
	static int objCount;
	// constructor
	Box(double l = 1.2, double b = 2.3, double h = 3.4)
	{
		cout << "consructor called" << endl;
		length = l;
		breadth = b;
		height = h;

		objCount++; //shared among all of the objects of class Box
	}

	double volume()
	{
		return length * breadth * height;
	}
private:
	double length;
	double breadth;
	double height;
};

// initialize the static variable of class
int Box::objCount = 0;

int main()
{
	Box box1(4.4, 5.5, 6.6);
	Box box2(7.8, 2.3, 3.4);

	cout << "total objects: " << Box::objCount << endl;
	cout << "total objects: " << box1.objCount << endl;
	cout << "total objects: " << box2.objCount << endl;
}
#endif

//--------------------- static function member of class ---------------
#if 0
class Box
{
public:
	static int objCount; // static variable member
	// constructor
	Box(double l, double b, double h);
	double volume();
	//static int getCount(); // static function variable
	static int getCount();
private:
	double length;
	double breadth;
	double height;
};

Box::Box(double l = 1.2, double b = 2.3, double h = 3.4)
{
	length = l;
	breadth = b;
	height = h;

	objCount++;
}

double Box::volume(void)
{
	return length * breadth * height;
}

int Box::getCount(void)
{
	return objCount;
}

int Box::objCount = 0; // note: int is needed

int main()
{
	cout << "Inital Stage Count: " << Box::getCount() << endl;

	Box box1(5.2, 4.3, 6.5);
	Box box2(9.9, 1.1, 9.8);

	cout << "final stage count: " << Box::getCount() << endl;

	return 0;
}
#endif

//---------------------- multi-inheritance ------------------------------
#if 0
class Shape // base class
{
public:
	void setWidth(int w);
	void setHeight(int h);
protected:
	int width;
	int height;
};

void Shape::setWidth(int w)
{
	width = w;
}

void Shape::setHeight(int h)
{
	height = h;
}

class PaintCost // base class
{
public:
	int getCost(int area);
private:
	int width;
};

int PaintCost::getCost(int area)
{
	return area * 70;
}

// derived class, multi-inheritance
class Rectangle : public Shape, public PaintCost
{
public:
	int getArea();
};

int Rectangle::getArea()
{
	return Shape::width * height; // 'cause width is both defined in Shape and PaintCost, we must specify the class
}

int main(void)
{
	Rectangle Rect;
	int area;

	Rect.setWidth(5);
	Rect.setHeight(10);
	
	area = Rect.getArea();

	cout << "total area: " << Rect.getArea() << endl;

	cout << "total paint cost: " << Rect.getCost(area) << endl;

	return 0;
}
#endif

//---------------------- function reload -----------------------
#if 0
class printData
{
public:
	void print(int i);
	void print(float f);
	void print(double d);
};

void printData::print(int i)
{
	cout << "int: " << i << endl;
}

void printData::print(float f)
{
	cout << "float: " << f << endl;
}
void printData::print(double d)
{
	cout << "double: " << d << endl;
}

int main()
{
	printData pd;

	pd.print(4);
	pd.print((float)3.4);
	pd.print(3.456789);
}
#endif

//-------------------- operator reload --------------------------------



















