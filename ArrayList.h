#pragma once
#include <string>
#include <iostream>
#include <sstream>

class ArrayList
{
private:
	int capacity;                  //������� �������
	int size;                      //������ �������
	int* data;                     //������ �������
	static double k;                  //���������� ���������� �������
	const int max_capacity = 50;  //����������� ���������� ������ �������
public:
	// ����������� �� ���������
	ArrayList();
	// ������������ � �����������
	ArrayList(int size);                   
	ArrayList(int size, int val);
	// ����������� �����������
	ArrayList(const ArrayList& other);	   
	// ����������
	~ArrayList();	

	// getters & setter
	int get_size();
	int get_capacity();
	int get_elem(int index);
	void set_elem(int index, int val);
	static double get_K() { return k; }

	// ��������: ���� �� ������� � ����� ��������
	bool data_index(int index);
	// ��������: ������ �� ������
	bool is_empty();

	bool add_back(int val);               // �������� ������� � ����� �������
	void add_front(int val);              // �������� ������� � ������ �������
	void add_index(int index, int val);   // �������� ������� �� �������
	bool delete_back();                   // ������� ������� � ����� �������
	void delete_front();                  // ������� ������� � ������ �������
	void delete_index(int index);         // ������� ������� �� �������
	void shrink();

	std::string to_string();		      // ��������� � ���� ������
};

