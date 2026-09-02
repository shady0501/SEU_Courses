template <class T>
class Queue
{
public:
	Queue(int queueCapacity = 10)
	{
		if (capacity < 1)
			throw "Queue capacity must be > 0";
		queue = new T(capacity);
		front = rear = 0;
	}

	bool IsEmpty()
	{
		return (front == rear);
	}

	T& Front() const
	{
		if (IsEmpty())
			throw "Queue is empty.";
		return queue[(front + 1) % capacity];
	}

	void Push(const& x)
	{
		if ((rear + 1) % capacity == front)
			throw"Queue is full.";
		rear = (rear + 1) % capacity;
		queue[rear] = x;
	}

	void SplitQueue(T* queue)
	{
		queue1 = new T(queue.capacity);
		queue2 = new T(queue.capacity);

		int count = 0;

		while (queue.front != queue.rear)
		{
			if (count == 0)
			{
				queue1.Push(queue.Front());
				count = 1;
			}
			if (count == 1)
			{
				queue2.Push(queue.Front());
				count = 0;
			}
			queue.front = (queue.front + 1) % queue.capacity;
		}
	}// ±º‰∏¥‘”∂»£∫O(capacity)

private:
	T* queue;
	int front, rear, capacity;
};