#include <bits/stdc++.h>

using namespace std;

void printArray(int *array, int size)
{
	for(int i = 0; i < size; i++)
		cout<<array[i]<<" ";
	cout<<endl;
}

int* copyArray(int *array, int size)
{
	int* cpyArray = new int[size];
	for(int i = 0; i < size; i++)
		cpyArray[i] = array[i];
	return cpyArray;
}

int* bubbleSort(int *array, int size)
{
	int *cpyArray = copyArray(array, size);
	for(int i = (size-1); i >= 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			if(cpyArray[j] > cpyArray[j+1])
				swap(cpyArray[j], cpyArray[j+1]);
		}
	}
	return cpyArray;
}

int* insertionSort(int *cpyArray, int size)
{
	int *array = copyArray(cpyArray, size);
	for(int i = 1; i < size; i++)
	{
		int j = 0, temp2 = 0;
		for(; j < i && array[i] > array[j]; j++);
		temp2 = array[j]; array[j++] = array[i];
		for(; j <= i; j++)
			swap(temp2, array[j]);
	}
	return array;
}

int* selectionSort(int *cpyArray, int size)
{
	int *array = copyArray(cpyArray, size);
	for(int i = 0; i < size; i++)
	{
		int min_idx=i;
		for(int j = i; j < size; j++)
			if(array[min_idx] > array[j])
				min_idx=j;
		swap(array[i], array[min_idx]);
	}
	return array;
}

int partition(int *array, int sIdx, int eIdx)
{
	int pivot = rand() % (eIdx - sIdx) + sIdx;
	// int pivot = eIdx-1;
	int less = sIdx;
	swap(array[pivot], array[eIdx-1]);
	for(int i = sIdx; i < eIdx; i++)
	{
		if(array[i] < array[eIdx-1])
			{ swap(array[less], array[i]); less++; }		
	}
	swap(array[less], array[eIdx-1]);
	return less;
}

void quickSort(int *array, int sIdx, int eIdx)
{
	if(sIdx >= eIdx)
		return;
	int pivot = partition(array, sIdx, eIdx);
	// cout<<"\tafter partition pivot: "<<pivot<<" s/e:"<<sIdx<<"/"<<eIdx<<" ->";
	// printArray(array, 4);
	quickSort(array, sIdx, pivot);
	quickSort(array, pivot+1, eIdx);
}

void combine(int *array, int sIdx, int eIdx)
{
	int temp[eIdx-sIdx];
	int mid = (sIdx + eIdx)>>1, ctr=0;
	int curOne = sIdx, curTwo = mid;
	while(curOne < mid && curTwo < eIdx)
	{
		if(array[curOne] < array[curTwo])
			temp[ctr++] = array[curOne++];
		else
			temp[ctr++] = array[curTwo++];
	}
	while(curOne < mid)
		temp[ctr++] = array[curOne++];
	while(curTwo < eIdx)
		temp[ctr++] = array[curTwo++];
	for(int i = 0; i < ctr; i++)
		array[sIdx + i] = temp[i];
}

void mergeSort(int *array, int sIdx, int eIdx)
{
	if(sIdx >= eIdx || (eIdx - sIdx) == 1)
		return;
	int mid = (sIdx + eIdx)>>1;
	mergeSort(array, sIdx, mid);
	mergeSort(array, mid, eIdx);
	combine(array, sIdx, eIdx);
}

int* countingSort(int *cpyArray, int size, int range)
{
	if(!cpyArray || (size <= 0))
		return NULL;
	int count[range];
	int *array = new int[size];
	for(int i = 0; i < range; i++)
		count[i] = 0;
	for(int i = 0; i < size; i++)
		count[cpyArray[i]]++;
	for(int i = 1; i < range; i++)
		count[i] += count[i-1];
	for(int i = 0; i < range; i++)
		count[i]--;	
	for(int i = (size-1); i >= 0; i--)
	{
		assert(count[cpyArray[i]] >= 0);
		array[count[cpyArray[i]]] = cpyArray[i];
		// cout<<"currently on "<<array[count[cpyArray[i]]]<<"-cnt:"<<count[cpyArray[i]]<<endl;		
		count[cpyArray[i]]--;
	}
	return array;
}

class descComparator
{
public:
	bool operator() (int i, int j)
	{
		return i>j;
	}
};

bool descComp(int i, int j)
{
	return i>j;
}

int binarySearch(int *array, int size, int key)
{
	int left=0, right=size-1, mid;
	while(left <= right)
	{
		mid = (left+right)>>1;
		if(array[mid] == key)
			return mid;
		cout<<"l: "<<left<<" r: "<<right<<" mid: "<<mid<<" key: "<<key<<" val: "<<array[mid]<<endl;
		if(array[mid] < key)
			left = mid+1;
		else
			right = mid-1;
	}	
	return -1;
}

int main(int argc, char const *argv[])
{
	int array[] = {10, 4, 5, 2, 3, 7, 1, 8, 9, 6};
	vector<int> wrapperArray(array, array + (sizeof(array)/sizeof(array[0])) );
	cout<<"Org ";
	printArray(array, 10);
	// printArray(bubbleSort(array, 10), 10);
	// printArray(insertionSort(array, 10), 10);
	// printArray(selectionSort(array, 10), 10);
	// printArray(countingSort(array, 10, 11), 10);
	// descComparator comp;
	// sort(wrapperArray.begin(), wrapperArray.end(), comp);
	// for(int i = 0; i < 10; i++)
	// 	cout<<wrapperArray[i]<<" ";
	// cout<<endl;
	// int *cpyArray = copyArray(array, 10);
	// mergeSort(cpyArray, 0, 10);
	// printArray(cpyArray, 10);
	quickSort(array, 0, 10);
	cout<<binarySearch(array, 10, 3)<<endl<<binarySearch(array, 10, 14)<<endl;
	// printArray(array, 10);
	return 0;
}