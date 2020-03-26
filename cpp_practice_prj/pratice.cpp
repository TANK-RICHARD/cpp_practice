// pratice.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <iomanip>
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

//int
//swap(int& a, int& b)
//{
//	int c;
//	c = a;
//	a = b;
//	b = c;
//
//	return 0;
//}


//int main()
//{

	//std::cout << "Hello World" << endl;
	//cout << setw(5) << setprecision(5) << 3.141592653589793;

	//--------------------------------------------------
	
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

	//--------------------------------------------------

	//int a[10] = {0};
	//int& ref_a = a[4];

	//for (int i = 0; i < 10; ++i) {
	//	a[i] = i;
	//}

	//cout << &ref_a << endl; // have the same address
	//cout << &a[4] << endl;

	//a[4] = 100;
	//cout << ref_a << endl;

	//--------------------------------------------------

	//int c = 13;
	//double d = 2.9, &rd = d;

	//c = rd;
	//cout << c << endl;
	//rd = 4.5;
	//cout << rd << endl;

	//--------------------------------------------------

	//int i = 2, &r1 = i;
	//double d = 4.5, &r2 = d;

	//r2 = 3.14;
	//r2 = r1;
	//i = r2;
	//r1 = d;

	//cout << r2 << i << r1 << endl;
	//
	//cout << sizeof r2 << "  " << sizeof r1 << endl; // 8, 4

	//--------------------------------------------------

	//int i, & ri = i;
	//i = 5;
	//ri = 10;
	//int* p = &i;
	//int& a = *p;
	//////////// int& a = p; // syntax error

	//cout << a << endl;

	//cout << i << " " << ri << endl; // output: 10 10

	//------------------------------------------------------------------

	//int* p = nullptr;
	//cout << p << endl; // 0

	//int* a = 0;
	//cout << a << endl; // 0

	//------------------------------------------------------------------

	//int i = 43;
	//int* p = nullptr;
	//int*& r = p;

	//int b = 10; // if use double b = 10, the next sentence will be syntax error;
	//r = &b;

	//cout << *r << endl;
//}

//------------------------------------------------------

//class Box
//{
//private:
//	double length;
//	double breadth;
//	double height;
//
//public:
//	// declare member function
//	double getVolume(void);
//	void setLength(double l);
//	void setBreadth(double b);
//	void setHeight(double h);
//};
//
//// define member function
//double Box::getVolume(void)
//{
//	return length * breadth * height;
//}
//
//void Box::setLength(double l)
//{
//	length = l;
//}
//
//void Box::setBreadth(double b)
//{
//	breadth = b;
//}
//
//void Box::setHeight(double h)
//{
//	height = h;
//}
//
//
//int main()
//{
//	Box Box1;
//	Box Box2;
//	double volume = 0.0;
//
//	// Box1 set attribute
//	Box1.setLength(6.0);
//	Box1.setBreadth(7.0);
//	Box1.setHeight(5.0);
//
//	// Box2 set attribute
//	Box2.setLength(12.0);
//	Box2.setBreadth(13.0);
//	Box2.setHeight(10.0);
//
//	// volume of Box1
//	volume = Box1.getVolume();
//	cout << "volume of Box1: " << volume << endl;
//
//	// volume of Box2
//	volume = Box2.getVolume();
//	cout << "voume of Box2: " << volume << endl;
//}


//----------------------- constructor / copy constructor / destructor-------------------------------------

//class Line
//{
//public: 
//	int getLength(void);
//	Line(int len); // declare constructor
//	Line(const Line& obj); // declare copy constructor
//	~Line(); // destructor
//
//private:
//	int* ptr;
//
//};
//
//// define constructor, no return value
//Line::Line(int len)
//{
//	cout << "calling constructor: " << endl;
//	// allocate space for pointer
//	ptr = new int;
//	*ptr = len;
//}
//
//// defien copy constructor
//Line::Line(const Line& obj)
//{
//	cout << "calling copy constructor: " << endl;
//	ptr = new int;
//	*ptr = *obj.ptr;
//}
//
//// destructor
//Line::~Line(void)
//{
//	cout << "destructor: " << endl;
//	delete ptr;
//}
//
//int Line::getLength(void)
//{
//	return *ptr;
//}
//
//void display(Line obj)
//{
//	cout << "line: " << obj.getLength() << endl;
//}
//
//int main()
//{
//	Line line1(10);
//	display(line1);
//
//	Line line2 = line1;
//	display(line2);
//
//	return 0;	
//}


//------------------ extend -----------------------------------------

//class Animal
//{
//public:
//	void eat(Animal &obj);
//	void walk(Animal &obj);
//	void set_name(std::string name);
//	void set_height(float h);
//	string get_name();
//	float get_height();
//
//	Animal();
//	~Animal();
//
///* if use private or protected, these 2 variables can not be accessed, public can */
//private:
////protected:
////public:
//	string name;
//	float height;
//};
//
//Animal::Animal(void)
//{
//	name = "animal";
//	height = 0;
//}
//
//Animal::~Animal(void)
//{
//	// do nothing
//}
//
//void Animal::eat(Animal &obj)
//{
//	cout << obj.get_name() << " is eating" << endl;
//}
//
//void Animal::walk(Animal &obj)
//{
//	cout << obj.get_name() << " is walking" << endl;
//}
//
//void Animal::set_name(string name)
//{
//	Animal::name = name;
//}
//
//void Animal::set_height(float h)
//{
//	Animal::height = h;
//}
//
//string Animal::get_name(void)
//{
//	return Animal::name;
//}
//
//float Animal::get_height(void)
//{
//	return Animal::height;
//}
//
//// extend
//class Dog : public Animal // if there is no public, default is private
//{
//public:
//	void run(Dog &obj);
//	void bark(Dog &obj);
//	void set_dog_speed(float speed);
//	float get_dog_speed(Dog &obj);
//private:
//	float speed;
//};
//
//void Dog::run(Dog& obj)
//{
//	cout << obj.get_name() << " is running" << endl;
//}
//
//void Dog::bark(Dog& obj)
//{
//	cout << obj.get_name() << " is barking" << endl;
//}
//
//void Dog::set_dog_speed(float spd)
//{
//	Dog::speed = spd;
//	cout << "set speed is " << spd << endl;
//}
//
//float Dog::get_dog_speed(Dog& obj)
//{
//	return speed;
//}
//
//int main(void)
//{
//	Animal bob;
//	Animal& bob_ref = bob;
//	bob.set_name("bob");
//	bob.set_height(3.4);
//	cout << "bob's name: " << bob.get_name() << endl;
//	cout << "bob's height: " << bob.get_height() << endl;
//	bob.eat(bob_ref);
//	bob.walk(bob_ref);
//
//	/* Dog extends Animal with public mode, so all of the public member in class Animal, 
//	   including methods and members, can be accessed */
//	Dog paul;
//	Dog& paul_ref = paul;
//	paul.set_name("paul");
//	paul.set_height(5.6);
//	cout << "paul's name: " << paul.get_name() << endl;
//	cout << "paul's height: " << paul.get_height() << endl;
//	paul.bark(paul_ref);
//	paul.run(paul_ref);
//	paul.eat(paul_ref);
//	paul.set_dog_speed(12.4);
//	cout << paul.get_name() << "'s speed is: " << paul.get_dog_speed(paul_ref) << endl;	
//}

// ------------------------------------------------------------------------------


