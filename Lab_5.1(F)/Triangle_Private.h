#pragma once

#include "Triad.h"


typedef double angle;
class Triangle_Private : private Triad {   //приватний клас для представлення трикутника(обчислення площі та куті)
public:
	Triangle_Private(const number v_x = 3, const number v_y = 4, const number v_z = 5);  //конструктор ініціалізації(параметри за умовчанням)
	Triangle_Private(const Triangle_Private& obj);										 //конструктор копіювання

	using Triad::Set_x;  //підключаєм метод встановлення значення поля "x"
	using Triad::Set_y;  //підключаєм метод встановлення значення поля "y"
	using Triad::Set_z;  //підключаєм метод встановлення значення поля "z"

	using Triad::Get_x;  //підключаєм метод отримання значення поля "x"
	using Triad::Get_y;  //підключаєм метод отримання значення поля "y"
	using Triad::Get_z;  //підключаєм метод отримання значення поля "z"

	friend std::ostream& operator << (std::ostream& out, Triangle_Private& obj);  //операції виводу
	friend std::istream& operator >> (std::istream& in, Triangle_Private& obj);   //операції вводу  

	using Triad::operator=;
	using Triad::operator std::string;

	Triangle_Private& operator ++ ();     //перевантаження операції "інкременту"(префіксна форма) --- x
	Triangle_Private& operator -- ();     //перевантаження операції "дикременту"(префіксна форма) --- y

	Triangle_Private operator ++ (int);   //перевантаження операції "інкременту"(постфіксна форма) --- z
	Triangle_Private operator -- (int);   //перевантаження операції "дикременту"(постфіксна форма) --- x

	using Triad::Addition;

	double Calcul_Square();                                  //обчислення площі
	void Calcul_Angles(angle&, angle&, angle&, double);      //обчислення кутів трикутника
};