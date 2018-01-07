#include <iostream>
#include <string>

using namespace std;

template <class T>
void f(T param)
{
	cout << "name of T : " << typeid(T).name() << " created\n";
	cout << "name of ParamType : " << typeid(param).name() << " created\n";
}

template<class T, std::size_t N>
std::size_t ArraySize(T(&param)[N])
{
	cout << "name of T : " << typeid(T).name() << " created\n";
	cout << "name of ParamType : " << typeid(param).name() << " created\n";
	return N;
}

void someFunc(int, double) {}
template <class T>
void f1(T param)
{
	cout << "name of T : " << typeid(T).name() << " created\n";
	cout << "name of ParamType : " << typeid(param).name() << " created\n";
}

template <class T>
void f2(T& param)
{
	cout << "name of T : " << typeid(T).name() << " created\n";
	cout << "name of ParamType : " << typeid(param).name() << " created\n";
}

void main()
{
	int nums[] = { 3,4,5 };
	cout << ArraySize(nums);

	f1(someFunc);
	puts("");
	f2(someFunc);
}