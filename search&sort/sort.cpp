#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class SortArray
{
public:
	SortArray(int = 9);
	~SortArray()
	{
		delete [] dataPtr;
	}
	void fill_data(T & pushValue);
	void fill_user_data(int * userData);
	int mp_sort() const;
	int xz_sort() const;
	void printData() const;
private:
	int size;
	T * dataPtr;
};


// constructor template
template <typename T>
SortArray <T>::SortArray(int s):size(s>0?s:9),dataPtr(new T[size])
{
	//empty body

}

//填充数据
template <typename T>
void SortArray <T>::fill_data(T & pushValue)
{
	int i;
	for(i = 0; i < size; i++){
		dataPtr[i] = pushValue;
	}
}

//填充用户数据
template <typename T>
void SortArray <T>::fill_user_data(int * userData)
{
	for(int i = 0; i < size; i++)
		dataPtr[i] = userData[i];
}


//冒泡排序 
template <typename T>
int SortArray <T> ::mp_sort() const
{

}


// 选择排序
template <typename T>
int SortArray <T>::xz_sort() const
{

}

// 打印数据
template <typename T>
void SortArray <T>::printData() const
{
	int i;
	for(i = 0; i < size; i++)
		cout << dataPtr[i] << " ";
	cout << "\n\n";
}


int main()
{
	int intData[] = {3,4,6,8,1,2,7,9,5};
	SortArray <int> intSortArray(9);

	intSortArray.fill_user_data(intData);
	cout << "row data\n";
	intSortArray.printData();

	cout << "begin mp sort\n";
	intSortArray.mp_sort();
	cout << "mp sort result\n";
	intSortArray.printData();

	cout << "begin xz sort\n";
	intSortArray.xz_sort();
	cout << "xz sort result\n";
	intSortArray.printData();

	return 0;
}