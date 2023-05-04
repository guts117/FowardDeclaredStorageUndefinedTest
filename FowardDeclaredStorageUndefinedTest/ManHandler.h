#pragma once
#include <vector>
#include "ForwardDeclaredStorage.h"
class ManHandler
{
public:
	explicit ManHandler();

	ManHandler(ManHandler&& rhs) noexcept = default;
	ManHandler& operator=(ManHandler&& rhs) noexcept = default;

	ManHandler(const ManHandler& rhs) noexcept = delete;
	ManHandler& operator=(const ManHandler& rhs) = delete;

	~ManHandler();
	void AddMan();
private:
	struct Impl;	

	const Impl& Pimpl() const { return m_pImpl.Get(); }
	Impl& Pimpl() { return m_pImpl.Get(); }

	ForwardDeclaredStorage<Impl, alignof(void*) * 4, alignof(void*)> m_pImpl;
};

