#pragma once
#include <string>
#include <iostream>
#include <sstream>

class ArrayList
{
private:
	int capacity;                  //ёмкость массива
	int size;                      //размер массива
	int* data;                     //данные массива
	static double k;                  //коэфициент расширения массива
	const int max_capacity = 50;  //максимально допустимый размер массива
public:
	// конструктор по умолчанию
	ArrayList();
	// конструкторы с параметрами
	ArrayList(int size);                   
	ArrayList(int size, int val);
	// конструктор копирования
	ArrayList(const ArrayList& other);	   
	// деструктор
	~ArrayList();	

	// getters & setter
	int get_size();
	int get_capacity();
	int get_elem(int index);
	void set_elem(int index, int val);
	static double get_K() { return k; }

	// Проверка: есть ли элемент с таким индексом
	bool data_index(int index);
	// Проверка: пустой ли массив
	bool is_empty();

	bool add_back(int val);               // добавить элемент в конец массива
	void add_front(int val);              // добавить элемент в начало массива
	void add_index(int index, int val);   // добавить элемент по индексу
	bool delete_back();                   // удалить элемент с конца массива
	void delete_front();                  // удалить элемент с начала массива
	void delete_index(int index);         // удалить элемент по индексу
	void shrink();

	std::string to_string();		      // получение в виде строки
};

