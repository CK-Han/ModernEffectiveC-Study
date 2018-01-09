#include <iostream>
#include <string>
#include <set>
#include <vector>

void f(const std::vector<int>& v)
{

}

template<typename... Ts>
void fwd(Ts&&... param)
{
	f(std::forward<Ts>(param)...);
}



void main()
{
	auto t = { 1,2,3 };
	f({ 1,2,3 });
	//fwd({1,2,3 }); //연역하지 못함
	fwd(t);
}