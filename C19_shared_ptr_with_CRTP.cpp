#include <iostream>
#include <memory>

//Curiously Recurring Template Pattern
class Widget 
	: public std::enable_shared_from_this<Widget>
{
public:
	static std::shared_ptr<Widget> create()
	{
		//Widget 초기화에 필요한 인자를 받아 미리 생성하고, 그것의 shared_ptr를 반환한다.
		std::shared_ptr<Widget> ptr(new Widget());
		return ptr->GetThisSharedPtr();
	}
	
	std::shared_ptr<Widget> GetThisSharedPtr()
	{
		return shared_from_this();
		//shared_from_this는 현재 객체에 대한 제어블록을 조사하고 그에 대한 shared_ptr를 반환한다.
		//다른 말로, 제어블록이 생성되어 있어야 한다. 생성되어있지 않으면 미정의 행동을 낳는다.
		//이를 해결하기 위해 std::enable_shared_from_this<Widget>를 상속받은 클래스는
		//자신의 생성자를 private로 은닉하고, 클라이언트가 객체를 생성할 수 있도록 팩토리 함수를 제공하는 식
	}

	~Widget() { std::cout << "dtor called\n"; }

private:
	Widget() { std::cout << "ctor called\n"; }
	
};

//////////////////////////////////////////////////////////////////
///////////// Curiously Recurring Template Pattern 사용 예시
template <typename CountedType>
class ObjectCounter {
private:
	static size_t count;    // 존재하는 객체 수

protected:
	// 기본 생성자
	ObjectCounter() {
		++ObjectCounter<CountedType>::count;
	}

	// 복사 생성자 
	ObjectCounter(ObjectCounter<CountedType> const&) {
		++ObjectCounter<CountedType>::count;
	}

	// 소멸자
	~ObjectCounter() {
		--ObjectCounter<CountedType>::count;
	}

public:
	// 존재하는 객체 수를 반환 
	static size_t live() {
		return ObjectCounter<CountedType>::count;
	}
};

// 카운터를 0으로 초기화
template <typename CountedType>
size_t ObjectCounter<CountedType>::count = 0;


template <typename CharT>
class MyString : public ObjectCounter<MyString<CharT> > {
	
};

int main()
{
	auto ptr = Widget::create();

	MyString<char> s1, s2;
	MyString<wchar_t> ws;
	std::cout << "number of MyString<char>: "
		<< MyString<char>::live() << std::endl;
	std::cout << "number of MyString<wchar_t>: "
		<< ws.live() << std::endl;
}