
template<class T> 
void MaxHeap<T>::Push(const T& e)
{
	if (heapSize == capacity)
	{
		ChangeSize(heap, capacity, 2 * capacity);
		Capacity *= 2;
	}

    int low = 1;
    int currentNode = ++heapSize;
    int high = currentNode;

    while (currentNode > 1 && low <= high)
    {
        int mid = (low + high) / 2;

        if (heap[mid] < e)
        {
            heap[currentNode] = heap[mid];
            high = mid - 1;
        }
        else if (heap[mid] > e)
            low = mid + 1;

        currentNode = mid;
    }

	heap[currentNode] = e;
}
