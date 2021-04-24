#pragma once

#include "Triad.h"

typedef double angle;

class Triangle : public Triad {   //клас для представлення трикутника(обчислення площі та куті)
public:
	Triangle(const number v_x = 3, const number v_y = 4, const number v_z = 5);  //конструктор ініціалізації(параметри за умовчанням)
	Triangle(const Triangle& obj);   //конструктор копіювання

	friend std::ostream& operator << (std::ostream& out, Triangle& obj);  //операції виводу
	friend std::istream& operator >> (std::istream& in, Triangle& obj);   //операції вводу  

	double Calcul_Square();                                  //обчислення площі
	void Calcul_Angles(angle&, angle&, angle&, double);      //обчислення кутів трикутника
};