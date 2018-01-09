#include <iostream>

template <class T>
void Func(T&& t)
{
	FuncFunc(std::forward<T>(t));
}

template <class T>
void FuncFunc(T&& t)
{
	std::cout << "t is rvalue\n";
}

template <class T>
void FuncFunc(T& t)
{
	std::cout << "t is lvalue\n";
}


void f(int& t)
{
	std::cout << "f's lvalue\n";
}

void main()
{
	int t = 3;
	Func(t);
	Func(3);

	int&& tt = 3;
	FuncFunc(std::forward<decltype(tt)>(tt));

}