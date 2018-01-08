#include "ForPimpl.h"
#include <string>
#include <vector>
using namespace std;

struct Widget::Impl
{
	std::string name;
	std::vector<double> data;
};

Widget::Widget()
	: pImpl(std::make_unique<Impl>())
{
}

Widget::~Widget() = default;
