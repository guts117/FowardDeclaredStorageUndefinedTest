#pragma once
#include <vector>
#include "ForwardDeclaredStorage.h"
class ManHandler
{
public:
	explicit ManHandler();

	ManHandler(ManHandler&& rhs) noexcept;
	ManHandler& operator=(ManHandler&& rhs) noexcept;

	ManHandler(const ManHandler& rhs) noexcept = delete;
	ManHandler& operator=(const ManHandler& rhs) = delete;

	~ManHandler();
	void AddMan();
private:
	struct Impl;	

	const Impl& Pimpl() const { return m_pImpl.Get(); }
	Impl& Pimpl() { return m_pImpl.Get(); }

	//Made this a forward declared storage to show how at main() creating ManHandler instance does not cause the "use of undefined type ManHandler::Impl" issue
#ifdef NDEBUG
	ForwardDeclaredStorage<Impl, alignof(void*) * 3, alignof(void*)> m_pImpl;
#else
	ForwardDeclaredStorage<Impl, alignof(void*) * 4, alignof(void*)> m_pImpl;
#endif;
	
};

