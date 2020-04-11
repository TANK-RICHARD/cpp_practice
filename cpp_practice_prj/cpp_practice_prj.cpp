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

#if 0
int
swap(int& a, int& b)
{
	int c;
	c = a;
	a = b;
	b = c;

	return 0;
}


int main()
{

	std::cout << "Hello World" << endl;
	cout << setw(5) << setprecision(5) << 3.141592653589793;

	--------------------------------------------------

	/*
	int a = 1, b = 4;
	int& ra = a;

	cout << "ra:" << ra << "a:" << a << endl;
	cout << &a << endl;

	swap(a, b);
	cout << "a:" << a << "b:" << b << endl;

	b = 6;
	ra = b;
	cout << ra << endl;
	cout << a << endl;*/

	--------------------------------------------------

	int a[10] = {0};
	int& ref_a = a[4];

	for (int i = 0; i < 10; ++i) {
		a[i] = i;
	}

	cout << &ref_a << endl; // have the same address
	cout << &a[4] << endl;

	a[4] = 100;
	cout << ref_a << endl;

	--------------------------------------------------

	int c = 13;
	double d = 2.9, &rd = d;

	c = rd;
	cout << c << endl;
	rd = 4.5;
	cout << rd << endl;

	--------------------------------------------------

	int i = 2, &r1 = i;
	double d = 4.5, &r2 = d;

	r2 = 3.14;
	r2 = r1;
	i = r2;
	r1 = d;

	cout << r2 << i << r1 << endl;

	cout << sizeof r2 << "  " << sizeof r1 << endl; // 8, 4

	--------------------------------------------------

	int i, & ri = i;
	i = 5;
	ri = 10;
	int* p = &i;
	int& a = *p;
	////////// int& a = p; // syntax error

	cout << a << endl;

	cout << i << " " << ri << endl; // output: 10 10

	------------------------------------------------------------------

	int* p = nullptr;
	cout << p << endl; // 0

	int* a = 0;
	cout << a << endl; // 0

	------------------------------------------------------------------

	int i = 43;
	int* p = nullptr;
	int*& r = p;

	int b = 10; // if use double b = 10, the next sentence will be syntax error;
	r = &b;

	cout << *r << endl;
}
#endif

//------------------------------------------------------
#if 0
class Box
{
private:
	double length;
	double breadth;
	double height;

public:
	// declare member function
	double getVolume(void);
	void setLength(double l);
	void setBreadth(double b);
	void setHeight(double h);
};

// define member function
double Box::getVolume(void)
{
	return length * breadth * height;
}

void Box::setLength(double l)
{
	length = l;
}

void Box::setBreadth(double b)
{
	breadth = b;
}

void Box::setHeight(double h)
{
	height = h;
}


int main()
{
	Box Box1;
	Box Box2;
	double volume = 0.0;

	// Box1 set attribute
	Box1.setLength(6.0);
	Box1.setBreadth(7.0);
	Box1.setHeight(5.0);

	// Box2 set attribute
	Box2.setLength(12.0);
	Box2.setBreadth(13.0);
	Box2.setHeight(10.0);

	// volume of Box1
	volume = Box1.getVolume();
	cout << "volume of Box1: " << volume << endl;

	// volume of Box2
	volume = Box2.getVolume();
	cout << "voume of Box2: " << volume << endl;
}
#endif

//----------------------- constructor / copy constructor / destructor-------------------------------------
#if 0
class Line
{
public:
	int getLength(void);
	Line(int len); // declare constructor
	Line(const Line& obj); // declare copy constructor
	~Line(); // destructor

private:
	int* ptr;

};

// define constructor, no return value
Line::Line(int len)
{
	cout << "calling constructor: " << endl;
	// allocate space for pointer
	ptr = new int;
	*ptr = len;
}

// defien copy constructor
Line::Line(const Line& obj)
{
	cout << "calling copy constructor: " << endl;
	ptr = new int;
	*ptr = *obj.ptr;
}

// destructor
Line::~Line(void)
{
	cout << "destructor: " << endl;
	delete ptr;
}

int Line::getLength(void)
{
	return *ptr;
}

void display(Line obj)
{
	cout << "line: " << obj.getLength() << endl;
}

int main()
{
	Line line1(10);
	display(line1);

	Line line2 = line1;
	display(line2);

	return 0;
}
#endif

//------------------ extend -----------------------------------------
#if 0
class Animal
{
public:
	void eat(Animal &obj);
	void walk(Animal &obj);
	void set_name(std::string name);
	void set_height(float h);
	string get_name();
	float get_height();

	Animal();
	~Animal();

/* if use private or protected, these 2 variables can not be accessed, public can */
private:
//protected:
//public:
	string name;
	float height;
};

Animal::Animal(void)
{
	name = "animal";
	height = 0;
}

Animal::~Animal(void)
{
	// do nothing
}

void Animal::eat(Animal &obj)
{
	cout << obj.get_name() << " is eating" << endl;
}

void Animal::walk(Animal &obj)
{
	cout << obj.get_name() << " is walking" << endl;
}

void Animal::set_name(string name)
{
	Animal::name = name;
}

void Animal::set_height(float h)
{
	Animal::height = h;
}

string Animal::get_name(void)
{
	return Animal::name;
}

float Animal::get_height(void)
{
	return Animal::height;
}

// extend
class Dog : public Animal // if there is no public, default is private
{
public:
	void run(Dog &obj);
	void bark(Dog &obj);
	void set_dog_speed(float speed);
	float get_dog_speed(Dog &obj);
private:
	float speed;
};

void Dog::run(Dog& obj)
{
	cout << obj.get_name() << " is running" << endl;
}

void Dog::bark(Dog& obj)
{
	cout << obj.get_name() << " is barking" << endl;
}

void Dog::set_dog_speed(float spd)
{
	Dog::speed = spd;
	cout << "set speed is " << spd << endl;
}

float Dog::get_dog_speed(Dog& obj)
{
	return speed;
}

int main(void)
{
	Animal bob;
	Animal& bob_ref = bob;
	bob.set_name("bob");
	bob.set_height(3.4);
	cout << "bob's name: " << bob.get_name() << endl;
	cout << "bob's height: " << bob.get_height() << endl;
	bob.eat(bob_ref);
	bob.walk(bob_ref);

	/* Dog extends Animal with public mode, so all of the public member in class Animal,
	   including methods and members, can be accessed */
	Dog paul;
	Dog& paul_ref = paul;
	paul.set_name("paul");
	paul.set_height(5.6);
	cout << "paul's name: " << paul.get_name() << endl;
	cout << "paul's height: " << paul.get_height() << endl;
	paul.bark(paul_ref);
	paul.run(paul_ref);
	paul.eat(paul_ref);
	paul.set_dog_speed(12.4);
	cout << paul.get_name() << "'s speed is: " << paul.get_dog_speed(paul_ref) << endl;
}
#endif

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

#if 0
class Box
{
public:
	double getVolume(void)
	{
		return length * breadth * height;
	}
	void setLength(double len)
	{
		length = len;
	}

	void setBreadth(double bre)
	{
		breadth = bre;
	}

	void setHeight(double hei)
	{
		height = hei;
	}
#if 0
	// reload operator "+" to plus 2 obj
	Box operator+(const Box& b)
	{
		Box box;
		box.length = this->length + b.length;
		box.breadth = this->breadth + b.breadth;
		box.height = this->height + b.height;
		return box;
	}
#endif
	// e.g.: Box3 = Box2 + b;
	Box operator+(const double b)
	{
		Box box;
		box.length = this->length + b; // this points to obj Box2
		box.breadth = this->breadth + b;
		box.height = this->height + b;
		return box; // return and assign the result to obj Box3
	}

private:
	double length;
	double breadth;
	double height;
};

int main(void)
{
	Box Box1, Box2, Box3;
	double volume = 0.0;

	Box1.setLength(6.0);
	Box1.setBreadth(7.0);
	Box1.setHeight(5.0);

	Box2.setLength(12.0);
	Box2.setBreadth(13.0);
	Box2.setHeight(10.0);

	volume = Box1.getVolume();
	cout << "Volume of Box1: " << volume << endl;

	//Box3 = Box1 + Box2;
	Box3 = Box1 + 5.6;

	volume = Box3.getVolume();
	cout << "Volume of Box3: " << volume << endl;

	double a = 5.6, b = 4.5;
	double c = a + b; // OK
	cout << "c is : " << c << endl;

	return 0;
}

#endif

//------------------- method rewrite --------------------------------------------
// difference between method reload and rewrite:
// reload: one class includes multi-method which use the same name
// rewrite: multi-class inherits the base class and rewrite the method
//			of the same name in base class

class Shape {
protected:
	int width, height;
public:
	Shape(int a = 0, int b = 0)
	{
		width = a;
		height = b;
	}
#if 0
	virtual int area() // virtual means this method is not entity, so do not use it directly
	{
		cout << "Parent class area: " << endl;
		return 0;
	}
#else
	// pure virtual function
	virtual int area() = 0;
#endif
};

class Rectangle : public Shape
{
public:
	Rectangle(int a = 0, int b = 0) : Shape(a, b) {}
	int area()
	{
		cout << "Rectangle class area: " << endl;
		return (width * height);
	}
};

class Triangle : public Shape
{
public:
	Triangle(int a = 0, int b = 0) : Shape(a, b) {}
	int area()
	{
		cout << "Triangle class area: " << endl;
		return (width * height / 2);
	}
};

int main(void)
{
	Shape* shape;
	Rectangle rec(10, 7);
	Triangle tri(10, 5);

	shape = &rec;
	shape->area();

	shape = &tri;
	shape->area();

	return 0;
}

//------------------------------------------------------------------------

