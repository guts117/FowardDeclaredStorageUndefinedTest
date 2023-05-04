#pragma once
#include <vector>
#include "ForwardDeclaredStorage.h"
class ManHandler
{
public:
	ManHandler();
	~ManHandler();
	void AddMan();
private:
	struct Impl;	

	const Impl& Pimpl() const { return m_pImpl.Get(); }
	Impl& Pimpl() { return m_pImpl.Get(); }

	ForwardDeclaredStorage<Impl, alignof(void*) * 4, alignof(void*)> m_pImpl;
};

