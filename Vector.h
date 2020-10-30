#pragma once
const int DEFAULT_SIZE = 256;
template <typename T>
class D_array
{
public:
	D_array();
	D_array(const unsigned int);
	~D_array();

	void pushBack(const T&);
	void remove(const unsigned int);
	const T& operator[](const unsigned int) const;
	T& operator[](const unsigned int);
	D_array<T>& operator=(const D_array<T>& other);
	D_array<T>(const D_array<T>& other);
	const unsigned int getSize() const;
	const unsigned int getCapacity() const;
	//void printArray() const;
private:
	unsigned int size;
	unsigned int capacity;
	T* data;
	void extend();
	void copy(const D_array<T>& other);

};




template <typename T>
D_array<T>::D_array() :
	size(0),
	capacity(0),
	data(nullptr)
{
}

template <typename T>
D_array<T>::D_array(const unsigned int _capacity) :
	size(0),
	capacity(_capacity),
	data(new T[_capacity])
{}

template <typename T>
D_array<T>::~D_array()
{
	delete[] data;
}

template <typename T>
void D_array<T>::pushBack(const T& rhs)
{
	if (size == capacity - 1 || size == 0)
		extend();
	data[size++] = rhs;
}
template <typename T>
void D_array<T>::extend()
{

	unsigned int cap = capacity == 0 ? DEFAULT_SIZE : capacity * 2;

	T* tmp = new T[cap];
	memcpy(tmp, data, size * sizeof(T));

	delete[] data;
	data = tmp;

	capacity = cap;
}

template<typename T>
inline void D_array<T>::copy(const D_array<T>& other)
{
	capacity = other.capacity;
	size = other.size;
	data = new T[capacity];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}


}

template <typename T>
void D_array<T>::remove(const unsigned int index)
{
	if (index < size)
	{
		for (unsigned int i = index; i < size - 1; ++i)
			data[i] = data[i + 1];
	}
	--size;
}



template <typename T>
const T& D_array<T>::operator[](const unsigned int index) const
{
	if (index < size)
		return data[index];
	else
		throw std::out_of_range("Index was out of bounds of the array.\n");
}

template <typename T>
T& D_array<T>::operator[](const unsigned int index)
{
	if (index < size)
		return data[index];
	else
		throw std::out_of_range("Index was out of bounds of the array.\n");
}

template<typename T>
 inline D_array<T>& D_array<T>::operator=(const D_array<T>& other)
{
	 if (this != &other)
	 {
		 delete[] data;
		 copy(other);

	 }
	 return *this;
}
 

template <typename T>
const unsigned int D_array<T>::getSize() const
{
	return size;
}

template <typename T>
const unsigned int D_array<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
inline D_array<T>::D_array(const D_array<T>& other)
{
	copy(other);
}
