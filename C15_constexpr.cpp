#include <iostream>
using namespace std;

class Point
{
public:
	constexpr Point(double _x, double _y) : x(_x), y(_y) {}
	
	constexpr double GetX() const noexcept { return x; }
	constexpr double GetY() const noexcept { return y; }

	//constexpr void SetX(double newX) noexcept { x = newX; }


private:
	double x, y;
};

constexpr Point
GetPointAdded(const Point& p1, const Point& p2)
{
	return{ p1.GetX() + p2.GetX(), p1.GetY() + p2.GetY() };
}

void main()
{
	constexpr auto t = GetPointAdded(Point(3,4), Point(5,2));
}
