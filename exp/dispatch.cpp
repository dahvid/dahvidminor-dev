#include <boost/variant.hpp>
#include <string>

using namespace std;
using namespace boost;


//find a way to dispatch on something dynamic
 
template<class Return>
struct type_builder {
	Return make_type()
	{
	}
};

template<>
struct type_builder {
	int make_type() {
		return 23;
	}
};

template<>
struct type_builder {
	float make_type() {
		return 2.3;
	}
};



//builder has to be staically declared
//???I can't build a builder for each type because they are recursive
auto build_type(const type_builder& builder) -> decltype(builder.make_type())
{
	auto val = builder();
	return val;
}
 
int main(int argc, char* argv[])
{
	string s(argv[1]);

	if (s == "int")
		cout << 

	dispatcher d;
	cout << build_type(type_builder<int);
	cout << d("float");
}

