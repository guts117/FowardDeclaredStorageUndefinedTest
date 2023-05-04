#pragma once
#include "ForwardDeclaredStorage.h"
class Man
{
public:
	explicit Man() = delete;
	explicit Man(int id, int age);
	~Man();
private:
	struct Impl;

	const Impl& Pimpl() const { return m_pImpl.Get(); }
	Impl& Pimpl() { return m_pImpl.Get(); }

	ForwardDeclaredStorage<Impl, alignof(int) * 2, alignof(int)> m_pImpl;
};

