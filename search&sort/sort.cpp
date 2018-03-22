#include <iostream>
#include <string>
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
    //T * tmpPtr = new T[size];
    int sum = 0;
    for(int i = 0; i < size -1; i++){
        for(int j = 0; j < size -i-1; j++){
            sum++;
            if(dataPtr[j] > dataPtr[j+1]){
                T temp;
                temp = dataPtr[j];
                dataPtr[j] = dataPtr[j+1];
                dataPtr[j+1] = temp;
            }
        }
    }
    //delete [] tmpPtr;
    return sum;
}


// 选择排序
template <typename T>
int SortArray <T>::xz_sort() const
{
    int sum = 0;
    int i,j,index;
    for(i = 0; i < size-1; i++){
        index = i;
        for(j = i+1; j < size; j++){
            sum++;
            if(dataPtr[j] < dataPtr[index]){
                index = j;
            }
        }
        if(index != i){
            T temp = dataPtr[index]; // Min value
            dataPtr[index] = dataPtr[i];//
            dataPtr[i] = temp;
        }
    }
    return sum;
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
    int intData[] = {3,4,6,8,1,2,7,9,5,10,11};
    int sum;

    SortArray <int> intSortArray(11);
    intSortArray.fill_user_data(intData);
    cout << "row data\n";
    intSortArray.printData();

    cout << "begin mp sort\n";
    sum = intSortArray.mp_sort();
    cout << "sum = " << sum << endl;
    cout << "mp sort result\n";
    intSortArray.printData();

    // cout << "begin xz sort\n";
    // sum = intSortArray.xz_sort();
    // cout << "sum = " << sum << endl;
    // cout << "xz sort result\n";
    // intSortArray.printData();

    return 0;
}
