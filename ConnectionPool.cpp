#include "ConnectionPool.h"
#include "Connection.h"
#include "Util.h"

ConnectionPool::ConnectionPool(int count)
	: mPool { }
	, mCapacity(MAX_CCU)
	, mSize(count)
{
	for (int i = 0; i < mSize; i++)
	{		
		mPool.push(new Connection());
	}
}

ConnectionPool::~ConnectionPool()
{
	while(!mPool.empty())
	{
		auto con = mPool.top();
		mPool.pop();

		delete con;
	}
}

Connection* ConnectionPool::Pop()
{
	if (mPool.empty())
	{
		Util::GetInstance().PrintError(L"ConnectionPool Pop");
		return nullptr;
	}

	auto connection = mPool.top();
	mPool.pop();
	mSize -= 1;

	return connection;
}

void ConnectionPool::Push(Connection* connection)
{
	if (mSize >= MAX_CCU)
	{
		Util::GetInstance().PrintError(L"ConnectionPool is full");
		return;
	}

	if (connection == nullptr)
	{
		Util::GetInstance().PrintError(L"connection is null");
		return;
	}

	connection->Release();
	mSize += 1;
	mPool.push(connection);
}

bool ConnectionPool::IsEmpty()
{
	return mPool.empty();
}