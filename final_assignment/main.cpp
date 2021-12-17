#include <iostream>
#include <vector>
#include <chrono>
#include <array>
#include <random>
using namespace std;
using namespace std::chrono;
void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}
// Bubble Sort
vector<int> bubble_sort(vector<int>& list, int size)
{
	for(int i = 0; i < size-1; ++i)
	{
		for(int j = 0; j< size-i-1; ++j)
		{
			if(list[j] > list[j+1])
			{
				swap(list[j], list[j+1]);
			}
		}
	}
	return list;
}
// Quick Sort
int partition(vector<int>& list, int first_index, int last_index)
{
	int pivot = list[first_index];
	int i = first_index;
	int j;
	for(int j = first_index + 1;  j < last_index; ++j)
	{
		if(list[j] <= pivot )
		{
			i++;
			swap(list[i], list[j]);
		}
	}
	swap(list[i], list[first_index]);
	return i;
}
void quick_sort(vector<int>& list,int first_index, int last_index)
{
	int pivot;
	if(first_index < last_index)
	{
		pivot = partition(list, first_index, last_index);
		quick_sort(list,first_index, pivot);
		quick_sort(list,pivot + 1, last_index);
	}
}
// Merge Sort
void merge(int list[], int first_index, int middle_index, int last_index)
{
	int i, j, k, sub_first, sub_last;
	sub_first = middle_index - first_index + 1;
	sub_last = last_index - middle_index;
	int temp_first[sub_first];
	int temp_last[sub_last];
	for(i = 0; i < sub_first; i++ )
	{
		temp_first[i] = list[first_index + i]; 
	}
	for(j = 0; j < sub_last; j++)
	{
		temp_last[j] = list[middle_index + 1 + j];
	}
	i = 0;
	j = 0;
	k = first_index;
	while(i < sub_first && j < sub_last)
	{
		if(temp_first[i] <= temp_last[j])
		{
			list[k] = temp_first[i];
			i++;
			k++;
		}
		else
		{
			list[k] = temp_last[j];
			j++;
			k++;
		}
	}
	while(i < sub_first)
	{
		list[k] = temp_first[i];
		i++;
		k++;
	}
	while(j < sub_last)
	{
		list[k] = temp_last[j];
		j++;
		k++;
	}
}
void merge_sort(int list[], int first_index, int last_index)
{
	int middle_index;
	if(first_index < last_index)
	{
		middle_index = first_index + (last_index - first_index) / 2;
		merge_sort(list, first_index, middle_index);
		merge_sort(list, middle_index +1, last_index);
		merge(list, first_index, middle_index, last_index);
	}
}
// selection sort
void selection_sort(vector<int>& list, int size)
{
	int i, j, min_index;
	for(int i = 0; i < size - 1; ++i)
	{
		min_index = i;
		for(j = i + 1; j < size; ++j)
		{
			if(list[j] < list[min_index])
			{
				min_index = j;
			}
		}
		swap(list[min_index], list[i]);
	}
}
vector<int> fill_up_vector()
{
	int n = 0;
	cout << "Amount of numbers to sort: " << endl;
	cin >> n;
	vector<int> list;
	int value;
	for(int i = 0; i < n; ++i)
	{
		value = (rand() % 1000);
		list.push_back(value);
	}
	return list;
}
int main()
{
	vector<int> list = fill_up_vector();
	int size = list.size();
	int array[size];
       	for(int i = 0; i < size; ++i)
	{
		array[i] = list[i];
	}
	// bubble	
	auto start = high_resolution_clock::now();
	bubble_sort(list, size);
	auto stop = high_resolution_clock::now();
	auto time = duration_cast<microseconds>(stop - start);
	cout << "\nBubble sort total time: " << time.count() << " microseconds" << endl;
	//quick
	auto start1 = high_resolution_clock::now();
        quick_sort(list, 0, size - 1);
        auto stop1 = high_resolution_clock::now();
        auto time1 = duration_cast<microseconds>(stop1 - start1);
        cout << "Quick sort total time: " << time1.count() << " microseconds" << endl;
	//merge
	auto start2 = high_resolution_clock::now();
        merge_sort(array, 0, size - 1);
        auto stop2 = high_resolution_clock::now();
        auto time2 = duration_cast<microseconds>(stop2 - start2);
        cout << "Merge sort total time: " << time2.count() << " microseconds" << endl;
	//selection
	auto start3 = high_resolution_clock::now();
        selection_sort(list, size);
        auto stop3 = high_resolution_clock::now();
        auto time3 = duration_cast<microseconds>(stop3 - start3);
        cout << "Selection sort total time: " << time3.count() << " microseconds" << endl;
	cout << endl;
	return 0;
}
