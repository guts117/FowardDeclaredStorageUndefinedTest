#include "Man.h"

struct alignas(alignof(int)) Man::Impl
{
	int id;
	int age;
};

Man::Man(int id, int age) : m_pImpl{ Impl{id, age} } {};

Man::~Man() = default;
