#pragma once
#include "CommonLibrary.h"

class Connection;

class ConnectionPool
{
public:
	ConnectionPool(int count);
	~ConnectionPool();

	Connection* Pop();
	void Push(Connection* connection);

	int GetFreeSize();
	bool IsEmpty();
private:
	std::stack<Connection*> mPool;
	int mCapacity;
	int mSize;
};