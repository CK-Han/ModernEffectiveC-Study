#include <iostream>

auto GetFunc()
{
	return [](int t) { return t; };
}

void main()
{
	int (*t)(int) = GetFunc();
	std::cout << t(3);
}