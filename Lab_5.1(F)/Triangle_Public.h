#pragma once

#include "Triad.h"


typedef double angle;
class Triangle_Public : public Triad {
public:
	Triangle_Public(const number v_x = 3, const number v_y = 4, const number v_z = 5);  //конструктор ініціалізації(параметри за умовчанням)
	Triangle_Public(const Triangle_Public& obj);										//конструктор копіювання  

	Triangle_Public& operator ++ ();     //перевантаження операції "інкременту"(префіксна форма) --- x
	Triangle_Public& operator -- ();     //перевантаження операції "дикременту"(префіксна форма) --- y

	Triangle_Public operator ++ (int);   //перевантаження операції "інкременту"(постфіксна форма) --- z
	Triangle_Public operator -- (int);   //перевантаження операції "дикременту"(постфіксна форма) --- x

	double Calcul_Square();                                  //обчислення площі
	void Calcul_Angles(angle&, angle&, angle&, double);      //обчислення кутів трикутника
};