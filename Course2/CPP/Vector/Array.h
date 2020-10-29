#pragma once
#include <iostream>

const unsigned int DEFAULT_CAPACITY = 10;

class ArrayException {};

template <class T> class Array
{
private:
	T* ptr;						// указатель на массив в динамической памяти
	unsigned int size;			// текущий размер массива
	unsigned int capacity;		// общая вместимость массива
	void increaseCapacity(unsigned int newCapacity);
public:
	explicit Array(unsigned int startCapacity = DEFAULT_CAPACITY, T elem = (T)0);
	explicit Array(std::initializer_list<T>);
	~Array();
	Array(const Array& arr);
	Array& operator = (const Array& arr);
	T get(unsigned int index) const;
	void set(unsigned int index, T elem);
	T& operator [](unsigned int index);
	void insert(unsigned int index, T elem);
	void insert(T elem);
	void insert(unsigned int index, Array arr);
	void insert(Array arr);
	void remove(unsigned int index);
	unsigned int getSize() const;
	
	friend std::istream& operator >>(std::istream& in, Array& arr)
	{
		for (unsigned int i = 0; i < arr.size; i++)
			in >> arr.ptr[i];
		return in;
	}

	friend std::ostream& operator <<(std::ostream& out, const Array& arr)
	{
		for (unsigned int i = 0; i < arr.size; i++)
			out << arr.ptr[i] << " ";
		out << std::endl;
		return out;
	}

	// Функции шаблона <vector>
	void resize(unsigned int newSize);
	void resize(unsigned int newSize, T elem);
	void reserve(unsigned int newCapacity);
	unsigned int max_size() const;
	bool operator == (const Array& arr);
	void clear();
	void push_back(T elem);
	void pop_back();
	bool empty() const;
};

template <class T> Array<T>::Array(unsigned int startCapacity, T elem)
{
	if (startCapacity <= 0)
		capacity = DEFAULT_CAPACITY;
	else
		capacity = startCapacity;
	ptr = new T[capacity];

	size = startCapacity;
	for (unsigned int i = 0; i < size; i++)
		ptr[i] = elem;
}

template <class T> Array<T>::Array(std::initializer_list<T> list)
{
	capacity = list.size();
	ptr = new T[capacity];
	size = capacity;
	
	unsigned int i = 0;
	for (T x : list)
	{
		ptr[i] = x;
		i++;
	}
}

template <class T> Array<T>::~Array()
{
	delete[] ptr;
}

template <class T> Array<T>::Array(const Array& arr)
{
	capacity = arr.capacity;
	size = arr.size;
	ptr = new T[capacity];
	for (unsigned int i = 0; i < size; i++)
		ptr[i] = arr.ptr[i];
}

template <class T> Array<T>& Array<T>::operator = (const Array& arr)
{
	if (this == &arr)
		return *this;
	if (capacity != arr.capacity)
	{
		delete[] ptr;
		ptr = new T[arr.capacity];
		capacity = arr.capacity;
	}
	size = arr.size;
	for (unsigned int i = 0; i < size; i++)
		ptr[i] = arr.ptr[i];
	return *this;
}

template <class T> T& Array<T>::operator [](unsigned int index)
{
	if (index >= size)
		throw ArrayException();
	else
		return ptr[index];
}

template <class T> T Array<T>::get(unsigned int index) const
{
	if (index >= size)
		throw ArrayException();
	else
		return ptr[index];
}

template <class T> void Array<T>::set(unsigned int index, T elem)
{
	if (index >= size)
		throw ArrayException();
	else
		ptr[index] = elem;
}

template <class T> void Array<T>::increaseCapacity(unsigned int newCapacity)
{
	capacity = newCapacity < capacity * 2 ? capacity * 2 : newCapacity;
	T* newPtr = new T[capacity];
	for (unsigned int i = 0; i < size; i++)
		newPtr[i] = ptr[i];
	delete[] ptr;
	ptr = newPtr;
}

template <class T> void Array<T>::insert(unsigned int index, T elem)
{
	if (index > size)
		throw ArrayException();
	if (size == capacity)
		increaseCapacity(size + 1);
	for (unsigned int j = size - 1; j >= index; j--)
		ptr[j + 1] = ptr[j];
	size++;
	ptr[index] = elem;
}

template <class T> void Array<T>::insert(T elem)
{
	insert(size, elem);
}

template <class T> void Array<T>::insert(unsigned int index, Array arr)
{
	if (index > size)
		throw ArrayException();
	if (size + arr.size > capacity)
		increaseCapacity(size + arr.size);
	size += arr.size;
	for (unsigned int i = size - 1; i >= index + arr.size; i--)
		ptr[i] = ptr[i - arr.size];
	for (unsigned int i = 0; i < arr.size; i++)
		ptr[i + index] = arr.ptr[i];
}

template <class T> void Array<T>::insert(Array arr)
{
	insert(size, arr);
}

template <class T> void Array<T>::remove(unsigned int index)
{
	if (index >= size)
		throw ArrayException();
	for (unsigned int j = index; j < size - 1; j++)
		ptr[j] = ptr[j + 1];
	ptr[size - 1] = 0;
	size--;
}

template <class T> unsigned int Array<T>::getSize() const
{
	return size;
}

template <class T> void Array<T>::resize(unsigned int newSize, T elem)
{
	if (newSize > size)
	{
		if (newSize > capacity)
			increaseCapacity(newSize);
		for (unsigned int i = size; i < newSize; i++)
			ptr[i] = elem;
	}
	size = newSize;
}

template <class T> void Array<T>::resize(unsigned int newSize)
{
	resize(newSize, 0);
}

template <class T> void Array<T>::reserve(unsigned int newCapacity)
{
	capacity = newCapacity;
	T* newPtr = new T[capacity];
	if (size > capacity) size = capacity;
	for (unsigned int i = 0; i < capacity; i++)
		newPtr[i] = ptr[i];
	delete[] ptr;
	ptr = newPtr;
}

template <class T> unsigned int Array<T>::max_size() const
{
	return capacity;
}

template <class T> void Array<T>::clear()
{
	size = 0;
}

template <class T> void Array<T>::push_back(T elem)
{
	insert(size, elem);
}

template <class T> void Array<T>::pop_back()
{
	if (size == 0)
		throw ArrayException();
	else
		size--;
}

template <class T> bool Array<T>::empty() const
{
	if (size > 0)
		return false;
	else
		return true;
}

template <class T> bool Array<T>::operator == (const Array& arr)
{
	if (size == arr.size)
	{
		for (unsigned int i = 0; i < size; i++)
			if (ptr[i] != arr.ptr[i])
				return false;
		return true;
	}
	return false;
}
