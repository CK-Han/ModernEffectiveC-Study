#include <iostream>
#include <string>
#include <set>

template <class T>
void Func(T&& name)
{
	std::cout << typeid(T).name() << std::endl;
}

void main()
{
	Func("cacaru");
}