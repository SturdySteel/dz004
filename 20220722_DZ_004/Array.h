#ifndef ARRAY_H
#define ARRAY_H

#include<iostream>
#include<typeinfo>



using namespace std;

template<class T>
class Array
{
	T* arr = nullptr;
	int size{ 0 };

public:
	Array() 
	{}

	explicit Array(int n)
	{
		size = n;
		arr = new T[n]{ 0 };
	}

	~Array()
	{
		delete[] arr;
	}

	Array(const Array& obj)
	{		
		size = obj.size;
		arr = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
	}

	void set(int min = 0, int max = 9) const
	{
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = rand() % (max - min + 1) + min;
		}
	}

	void print() const
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

public:
	
	template<class T2>
	void addElem(T2&& temp, int n);

	void delElem(int count);

	void findElem(T temp);
		
	void sortArrInc();
	
	void sortArrDec();

	T& operator[](int ind);
	Array<T>& operator+(const Array& temp);

	
};

template<class T>
inline void Array<T>::delElem(int count)
{	
	int newSize = count > size ? 1 : size - count;

	T* arr1 = new T[ newSize ];

	for (int i{}; i < (newSize); ++i)
		arr1[i] = arr[i];
	
	size = newSize;
	delete[] arr;
	arr = arr1;
}

template<class T>
inline void Array<T>::findElem(T temp)
{	
	for (int i{}, j{}; i < size; ++i)
	{
		if (arr[i] == temp)
		{
			++j;
			cout << "\nElement " << temp << " finded in pos: " << i << "\n";
		}
		if(i == (size-1) && j == 0 )
			cout << "\nElement <" << temp << "> not finded in array\n";
	}
}



template<class T>
inline void Array<T>::sortArrInc()
{
	T temp{};
	for(int i{ size - 1 }; i > 0 (); --i)
		for (int j{}; j < (i); ++j)
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}		
}

template<class T>
inline void Array<T>::sortArrDec()
{
	T temp{};
	for (int i{ size - 1 }; i > 0 (); --i)
		for (int j{}; j < (i); ++j)
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
}

template<class T>
T& Array<T>::operator[](int ind)
{
	return arr[ind];
}

template<class T>
inline Array<T>& Array<T>::operator+(const Array& temp)
{
	T add{};
	int n = temp.size - size;
	if (n > 0)
		addElem(add, n);

	for(int i{};i < (size); ++i)
	{
		if (i < temp.size )
			arr[i] += temp.arr[i];
		else
			arr[i] += add;
	}

	return *this;
}

#endif // !ARRAY_H

template<class T>
template<class T2>
inline void Array<T>::addElem(T2&& temp, int n)
{	
	T* arr1 = new T[size + n];	
	for (int i{}; i < (size + n); ++i)
	{
		if (i < size)
		{			
			arr1[i] = arr[i];		
			continue;
		}
		arr1[i] = temp;
	}
	size+=n;	
	delete[] arr;
	arr = arr1;	
}	
