#pragma once
class Component
{
public:
	// Constructor
	Component(class Actor* owner, int updateOrder = 100);
	// Destructor
	virtual ~Component();
	// Update this component by delta time
	virtual void Update(float deltaTime);

	int GetUpdateOrder() const { return mUpdateOrder; }

protected:
	class Actor* mOwner;
	// Update order of component
	int m_UpdateOrder;
};