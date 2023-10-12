#include "ArrayList.h"

ArrayList::ArrayList()
	: ArrayList(0)
{
}

ArrayList::ArrayList(int size)
	: size{ size }, capacity{ 0 }
{
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = 0;
	}
}

ArrayList::ArrayList(int size, int val)
	: size{ size }, capacity{ size }
{
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = val;
	}
}

ArrayList::ArrayList(const ArrayList& other)
	: size{ other.size }, capacity{ other.capacity }
{
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
}

ArrayList::~ArrayList()
{
	delete[] data;
}

int ArrayList::get_size()
{
	return size;
}

int ArrayList::get_capacity()
{
	return capacity;
}

int ArrayList::get_elem(int index)
{
	if (data_index(index))
		return data[index];
	else
		return false;
		//std::cout << "There is no such element!" << std::endl;
}

void ArrayList::set_elem(int index, int val)
{
	if (data_index(index))
		data[index] = val;
	else
		std::cout << "The index exceeds the size of the array!" << std::endl;
}

bool ArrayList::data_index(int index)
{
	return index < capacity;
}

bool ArrayList::is_empty()
{
	return capacity == 0;
}

bool ArrayList::add_back(int val)
{
	if (capacity < size) {
		data[capacity++] = val;
		return true;
	}
	if (capacity == size && size < max_capacity) {
		size *= k;
		data[capacity++] = val;
		for (int i = capacity; i < size; i++)
			data[i] = 0;
		return true;
	}
	return false;
}

bool ArrayList::delete_back()
{
	if (is_empty()) {
		return false;
	}
	data[capacity - 1] = 0;
	capacity--;
	return true;
}

void ArrayList::add_front(int val)
{
	if (is_empty()) {
		data[capacity++] = val;
	}
	else
		add_index(0, val);
}

void ArrayList::delete_front()
{
	delete_index(0);
}

void ArrayList::add_index(int index, int val)
{
	if (is_empty())
		return;
	if (data_index(index)) {
		if (capacity < size) {
			int* arr = new int[size];
			for (int i = 0; i < index; i++)
				arr[i] = data[i];
			arr[index] = val;
			for (int i = index, j = index + 1; i < capacity; i++, j++)
				arr[j] = data[i];
			capacity++;
			for (int i = capacity; i < size; i++)
				arr[i] = 0;
			delete[] data;
			data = arr;
		}
		if (capacity == size && size < max_capacity) {
			size *= k;
			int* arr = new int[size];
			for (int i = 0; i < index; i++)
				arr[i] = data[i];
			arr[index] = val;
			for (int i = index, j = index + 1; i < capacity; i++, j++)
				arr[j] = data[i];
			capacity++;
			for (int i = capacity; i < size; i++)
				arr[i] = 0;
			delete[] data;
			data = arr;
		}
	}
}

void ArrayList::delete_index(int index)
{
	if (is_empty())
		return;
	if (data_index(index)) {
		int* arr = new int[size];
		for (int i = 0; i < index; i++)
			arr[i] = data[i];
		for (int i = index + 1, j = index; i < size; i++, j++)
			arr[j] = data[i];
		arr[size - 1] = 0;
		delete data;
		data = arr;
		capacity--;
	}
}

void ArrayList::shrink()
{
	while (size > capacity)
		size--;
}

std::string ArrayList::to_string()
{
	std::ostringstream out;
	for (int i = 0; i < capacity - 1; i++) {
		out << data[i] << " ";
	}
	out << data[capacity - 1];
	return out.str();
}

