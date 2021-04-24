#include <iostream>

#include "Triangle_Private.h"


//конструктор ініціалізації(параметри за умовчанням)
Triangle_Private::Triangle_Private(const number v_x, const number v_y, const number v_z) : Triad(v_x, v_y, v_z) {}

//конструктор копіювання
Triangle_Private::Triangle_Private(const Triangle_Private& obj) : Triad(obj) {}

std::ostream& operator << (std::ostream& out, Triangle_Private& obj) {  //операції виводу
	out << "\n\nEnter the number x: " << obj.Get_x();
	out << "\nEnter the number y: " << obj.Get_y();
	out << "\nEnter the number z: " << obj.Get_z();

	return out;
}

std::istream& operator >> (std::istream& in, Triangle_Private& obj) throw(std::out_of_range) {    //операції вводу
	number a, b, c;

	std::cout << "\n\nEnter the side: ";
	std::cout << "\n\nEnter the number x: "; in >> a;
	std::cout << "Enter the number y: ";     in >> b;
	std::cout << "Enter the number z: ";     in >> c;

	/*Використання стандартного винятка
	Успадкований від std :: logic_error.
	Визначає виняток, яке повинно бути кинуто в тому випадку,
	коли відбувається вихід за межі допустимого діапазону значень об'єкта*/
	if ((c > (a + b)) || (a > (c + b)) || (b > (a + c)))
		throw std::out_of_range{ "\n\n!!!Data entered incorrectly!!!" };	//генерування об'єкта винятка

	obj.Set_x(a);
	obj.Set_y(b);
	obj.Set_z(c);
	return in;
}

Triangle_Private& Triangle_Private::operator ++ () {   //перевантаження операції "інкременту"(префіксна форма) --- x
	Set_x((Get_x() + 1));
	return *this;
}

Triangle_Private& Triangle_Private::operator -- () {   //перевантаження операції "дикременту"(префіксна форма) --- y
	Set_y((Get_y() - 1));
	return *this;
}

Triangle_Private Triangle_Private::operator ++ (int) {  //перевантаження операції "інкременту"(постфіксна форма) --- z
	Triangle_Private a(*this);
	Set_z((Get_z() + 1));
	return a;
}

Triangle_Private Triangle_Private::operator -- (int) {  //перевантаження операції "дикременту"(постфіксна форма) --- x
	Triangle_Private a(*this);
	Set_x((Get_x() - 1));
	return a;
}

double Triangle_Private::Calcul_Square() {  //обчислення площі
	double a, b, c;
	a = this->Get_x();
	b = this->Get_y();
	c = this->Get_z();

	double half_p;
	half_p = (a + b + c) / 2;
	return sqrt(half_p * (half_p - a) * (half_p - b) * (half_p - c));
}

void Triangle_Private::Calcul_Angles(angle& alpha, angle& beta, angle& sigma, double square) {  //обчислення кутів трикутника
	double a, b, c;
	a = this->Get_x();
	b = this->Get_y();
	c = this->Get_z();

	alpha = asin((2.0 * square) / (b * c));
	beta = asin((2.0 * square) / (a * c));
	sigma = asin((2.0 * square) / (a * b));
}