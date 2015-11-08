#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int inline parent(int i)
{
	return (i-1)>>1;
}

int inline lChild(int i)
{
	return 2*i+1;
}

int inline rChild(int i)
{
	return 2*i+2;
}

void heapify(vector<int>& heap, int idx)
{
	int size = heap.size();
	if(idx >= size)
		return;
	int maxIdx = idx;
	if(lChild(idx) < size && heap[lChild(idx)] > heap[idx])
		maxIdx = lChild(idx);
	if(rChild(idx) < size && heap[rChild(idx)] > heap[maxIdx])
		maxIdx = rChild(idx);
	if(maxIdx != idx)
	{
		swap(heap[maxIdx], heap[idx]);
		heapify(heap, maxIdx);
	}
}

void buildHeap(vector<int>& heap)
{
	int size = heap.size();
	for(int idx = (size-1)>>1; idx >= 0; idx--)
		heapify(heap, idx);
}

void insert(vector<int>& heap, int elem)
{
	heap.push_back(elem);
	int maxIdx = (heap.size()-1);
	bool flag = true;
	while(flag && maxIdx >= 0)
	{
		if(heap[parent(maxIdx)] < heap[maxIdx])
		{
			swap(heap[parent(maxIdx)], heap[maxIdx]);
			maxIdx = parent(maxIdx);
		}
		else
			flag = false;
	}
}

int extractMax(vector<int>& heap)
{
	if(!heap.size())
		return -1;
	int temp = heap[0];
	heap[0] = heap.back();
	heap.pop_back();
	heapify(heap, 0);
	return temp;
}

void heapSort(vector<int>& heap)
{
	while(!heap.empty())
		cout<<extractMax(heap)<<" ";
	cout<<endl;
}

int main()
{
	int heap[] = {1, 2, 3, 4, 5, 6};
	vector<int> array(heap, heap+sizeof(heap)/sizeof(heap[0]));
	buildHeap(array);
	for(int i = 0; i < 6; i++)
		cout<<array[i]<<" ";
	cout<<endl;
	insert(array, 7);
	for(int i = 0; i < array.size(); i++)
		cout<<array[i]<<" ";
	cout<<endl;
	heapSort(array);
	
	vector<int> arr2(heap, heap+6);
	make_heap(arr2.begin(), arr2.end());
	arr2.push_back(7); push_heap(arr2.begin(), arr2.end());
	while(!arr2.empty())
	{
		cout<<arr2[0]<<" ";
		pop_heap(arr2.begin(), arr2.end());
		arr2.pop_back();
	}

	return 0;
}