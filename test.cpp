#include <algorithm>
#include <memory>
#include <iostream>
#include <cstring>
#include <typeinfo>
#include <vector>
using namespace std;
// template Fac
template<unsigned n>
struct Fac {
	enum {
		value = n*Fac<n-1>::value
	};
};
template<>
struct Fac<0> {
	enum {
		value = 1
	};
};

// tempalte Fib function
typedef unsigned long long llu;
template<int n>
struct Fib {
	static const llu value = Fib<n-1>::value + Fib<n-2>::value;
};
template<>
struct Fib<0> {
	static const llu value = 0;
};
template<>
struct Fib<1> {
	static const llu value = 1;
};

// template more than
template<typename T>
class isMoreThan { // Functor
public:
	explicit isMoreThan(T num) : limit(num) {}
	bool operator()(T num) {
		return num > limit;
	}
private:
	T limit;
};

template<typename InputIt, typename Pred>
int count_occurences(InputIt begin, InputIt end, Pred pred) {
	int cnt = 0;
	for (auto it = begin; it != end; ++it) {
		if (pred(*it)) ++cnt;
	}
	return cnt;
}

int main() {
	vector<int> vec{1, 2, 3, 4, 5, 6};
	int res_fun = count_occurences(vec.begin(), vec.end(), isMoreThan<int>(3));
	int limit = 3;
	auto foo = [&limit](int n){ return n > limit; };
	int res_foo = count_occurences(vec.begin(), vec.end(), foo);
	cout << res_fun << endl;
	cout << res_foo << endl;
    return 0;
}