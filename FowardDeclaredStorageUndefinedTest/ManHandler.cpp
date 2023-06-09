#include "ManHandler.h"
#include "Man.h"

struct alignas(alignof(void*)) ManHandler::Impl
{
	std::vector<Man> men;

	void AddMan()
	{
		//ToDo: Figure out why commenting this out gives a successful compile + run
		men.push_back(Man{0, 1});//       <-----Notice how this causes "use of undefined type Man::Impl"
	}
};

ManHandler::ManHandler() : m_pImpl{ Impl() } {}

ManHandler::~ManHandler() = default;

ManHandler::ManHandler(ManHandler&& rhs) noexcept = default;
ManHandler& ManHandler::operator=(ManHandler&& rhs) noexcept = default;

void ManHandler::AddMan() 
{
	Pimpl().AddMan();
}

