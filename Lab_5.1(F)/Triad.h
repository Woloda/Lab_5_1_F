#pragma once

#include <sstream>


typedef double number;
class Triad {  //клас для представлення "трійки чисел"  --- базовий клас(клас-предок)
	number x;
	number y;
	number z;
public:
	Triad();													  //конструктор за умовчанням(без параметрів)
	Triad(const number v_x, const number v_y, const number v_z);  //конструктор ініціалізації
	Triad(const Triad& obj);								      //конструктор копіювання

	void Set_x(number value) { x = value; }   //встановлення значення поля "x"
	void Set_y(number value) { y = value; }   //встановлення значення поля "y"
	void Set_z(number value) { z = value; }   //встановлення значення поля "z"

	number Get_x()const { return x; }   //отримання значення поля "x"
	number Get_y()const { return y; }   //отримання значення поля "y"
	number Get_z()const { return z; }   //отримання значення поля "z"

	friend std::ostream& operator << (std::ostream& out, Triad& obj);  //операції виводу
	friend std::istream& operator >> (std::istream& in, Triad& obj);   //операції вводу  

	Triad& operator =(const Triad& obj);     //перевантаження операції "присвоєння"
	operator std::string() const;            //перетворення до літерного рядку --- "операції приведення типу"

	number Addition();  //обчислення суми чисел
};