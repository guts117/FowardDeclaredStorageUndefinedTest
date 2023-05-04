#include "ManHandler.h"
#include "Man.h"

struct alignas(alignof(void*)) ManHandler::Impl
{
	std::vector<Man> men;

	void AddMan()
	{
		//ToDo: Figure out why commenting this out gives a successful compile + run
		men.push_back(Man{0, 1});
	}
};

ManHandler::ManHandler() : m_pImpl{ Impl() } {}

ManHandler::~ManHandler() = default;

void ManHandler::AddMan() 
{
	Pimpl().AddMan();
}

