#include "RingBuffer.h"

RingBuffer::RingBuffer(int size)
	: mBuffer(nullptr)
	, mBufferFront(nullptr)
	, mBufferRear(nullptr)
	, mBufferEnd(nullptr)
	, mCapacity(size)
	, mSize(0)
{
	mBuffer = new char[mCapacity];
	mBufferFront = mBuffer;
	mBufferRear = mBuffer;
	mBufferEnd = mBuffer + mCapacity - 1;
}

RingBuffer::~RingBuffer()
{

}

bool RingBuffer::Enqueue(char* data, int size)
{
	if (size > GetRemainQueueSize())
	{
		return false;
	}

	// 넣으려는 사이즈가 버퍼의 남은 공간보다 작을 때
	// 이때는 데이터가 한번에 들어간다.
	if (size <= (mBufferEnd - mBufferRear - 1))
	{
		CopyMemory(mBufferRear, data, size);
		mBufferRear += size;
	}
	else
	{
		int tempSize = mBufferEnd - mBufferRear;
		CopyMemory(mBufferRear, data, tempSize);
		mBufferRear = mBuffer;

		CopyMemory(mBufferRear, data + tempSize, size - tempSize);
		mBufferRear += (size - tempSize);
	}

	mSize += size;
	return true;
}

bool RingBuffer::Dequeue(char* outData, int size)
{
	if (size > mSize)
	{
		return false;
	}

	//데이터를 한번에 가져올 수 있는경우
	//일단 End앞에 데이터가 다 있으면 된다. 그럼 한번에 가져올 수 있음
	if (size <= (mBufferEnd - mBufferFront - 1))
	{
		CopyMemory(outData, mBufferFront, size);
		mBufferFront += size;
	}
	else
	{
		//가져올 데이터가 애매하게 end와 front에 걸친경우
		//우선 end까지 읽고
		int tempSize = mBufferEnd - mBufferFront;
		CopyMemory(outData, mBufferFront, tempSize);
		mBufferFront = mBuffer;

		CopyMemory(outData + tempSize, mBufferFront, size - tempSize);
		mBufferFront += (size - tempSize);
	}

	mSize -= size;
	return true;
}

bool RingBuffer::Peek(char* outData, int size)
{
	if (size > mSize)
	{
		return false;
	}

	//데이터를 한번에 가져올 수 있는경우
	//일단 End앞에 데이터가 다 있으면 된다. 그럼 한번에 가져올 수 있음
	if (size <= (mBufferEnd - mBufferFront - 1))
	{
		CopyMemory(outData, mBufferFront, size);		
	}
	else
	{
		//가져올 데이터가 애매하게 end와 front에 걸친경우
		//우선 end까지 읽고
		int tempSize = mBufferEnd - mBufferFront;
		CopyMemory(outData, mBufferFront, tempSize);
		CopyMemory(outData + tempSize, mBuffer, size - tempSize);		
	}
	
	return true;
}

void RingBuffer::MoveFront(int size)
{	
	if (size <= (mBufferEnd - mBufferFront - 1))
	{		
		mBufferFront += size;
	}
	else
	{	
		int tempSize = mBufferEnd - mBufferFront;
		
		mBufferFront = mBuffer;		
		mBufferFront += (size - tempSize);
	}

	mSize -= size;
}

bool RingBuffer::IsEmpty()
{
	return mBufferFront == mBufferRear;
}

int RingBuffer::GetRemainQueueSize()
{
	return mCapacity - 1 - mSize;
}