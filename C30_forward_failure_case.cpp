#include <iostream>
#include <string>
#include <set>
#include <vector>

void f1(const std::vector<int>& v)
{
}

void f2(void*)
{
}

class Temp
{
public:
	static constexpr int STATIC_CONSTEXPR_INT = 3;
};

void f3(int)
{
}

void f4_overload(int)
{
}

void f4_overload()
{
}

template <class T>
void f4_template(T)
{
}

void f4(void(*)(int))
{
}

struct Header
{
	std::uint32_t head : 2
		, data : 14
		, extra : 16;
};

void f5(std::uint32_t sz)
{}


template<typename Func, typename... Ts>
void fwd(Func func, Ts&&... param)
{
	func(std::forward<Ts>(param)...);
}



void main()
{
	//1. 중괄호 초기치에 의한 포워딩 실패
	auto t = { 1,2,3 };
	//fwd(f, {1,2,3 }); //연역하지 못함
	fwd(f1, t);

	//2. 널 포인터를 뜻하는 0, NULL
	//fwd(f2, NULL);
	//fwd(f2, 0);
	fwd(f2, nullptr);

	//3. 선언만 된 정수 static const 및 constexpr 멤버
	//컴파일러마다 다르다. 멤버 상수를 위해 공간할당을 하지 않는 경우, 이에 따라
	//링크 오류가 발생하는 경우가 있다.
	fwd(f3, Temp::STATIC_CONSTEXPR_INT);

	//4. 오버로딩 함수 이름과 템플릿 이름
	f4(f4_overload); //잘 찾음
	//fwd(f4, f4_overload); //못 찾음
	f4(f4_template); //잘 찾음
	//fwd(f4, f4_template); //못찾음

	//5. 비트필드
	Header h;
	f5(h.extra); //컴파일되나 실행오류
	//fwd(f5, h.extra); //컴파일도 되지 않음
}