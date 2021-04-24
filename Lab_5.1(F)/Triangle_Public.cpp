#include "Triangle_Public.h"


//конструктор ініціалізації(параметри за умовчанням)
Triangle_Public::Triangle_Public(const number v_x, const number v_y, const number v_z) : Triad(v_x, v_y, v_z) {}

//конструктор копіювання
Triangle_Public::Triangle_Public(const Triangle_Public& obj) : Triad(obj) {}

Triangle_Public& Triangle_Public::operator ++ () {   //перевантаження операції "інкременту"(префіксна форма) --- x
	Set_x((Get_x() + 1));
	return *this;
}

Triangle_Public& Triangle_Public::operator -- () {   //перевантаження операції "дикременту"(префіксна форма) --- y
	Set_y((Get_y() - 1));
	return *this;
}

Triangle_Public Triangle_Public::operator ++ (int) {  //перевантаження операції "інкременту"(постфіксна форма) --- z
	Triangle_Public a(*this);
	Set_z((Get_z() + 1));
	return a;
}

Triangle_Public Triangle_Public::operator -- (int) {  //перевантаження операції "дикременту"(постфіксна форма) --- x
	Triangle_Public a(*this);
	Set_x((Get_x() - 1));
	return a;
}

double Triangle_Public::Calcul_Square() {  //обчислення площі
	double a, b, c;
	a = this->Get_x();
	b = this->Get_y();
	c = this->Get_z();

	double half_p;
	half_p = (a + b + c) / 2;
	return sqrt(half_p * (half_p - a) * (half_p - b) * (half_p - c));
}

void Triangle_Public::Calcul_Angles(angle& alpha, angle& beta, angle& sigma, double square) {  //обчислення кутів трикутника
	double a, b, c;
	a = this->Get_x();
	b = this->Get_y();
	c = this->Get_z();

	alpha = asin((2.0 * square) / (b * c));
	beta = asin((2.0 * square) / (a * c));
	sigma = asin((2.0 * square) / (a * b));
}