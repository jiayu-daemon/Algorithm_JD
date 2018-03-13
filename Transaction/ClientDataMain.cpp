/*
要写入定长记录文件，必须要以二进制格式打开，这是必要的
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ClientData.h"

using namespace std;

int main()
{
	ofstream outCredit("credit.dat",ios::out | ios::binary);

	if(!outCredit)
	{
		cerr << "File could not be opened. " << endl;
		exit(1);
	}


	ClientData blankClient;

	for(int i = 0 ; i < 100 ; i++)
	{
		outCredit.write(reinterpret_cast < const char * > (&blankClient), sizeof(ClientData));
	}


	return 0;
}

/*
操作符修改了操作数类型,但仅仅是重新解释了给出的对象的比特模型而没有进行二进制转换。
例如：int *n= new int;
double *d=reinterpret_cast<double*> (n);
在进行计算以后, d 包含无用值. 这是因为 reinterpret_cast 仅仅是复制 n 的比特位到 d, 没有进行必要的分析。
因此, 需要谨慎使用 reinterpret_cast static_cast 与 reinterpret_cast
reinterpret_cast是为了映射到一个完全不同类型的意思，这个关键词在我们需要把类型映射回原有类型时用到它。
我们映射到的类型仅仅是为了故弄玄虚和其他目的，这是所有映射中最危险的。(这句话是C++编程思想中的原话)
*/