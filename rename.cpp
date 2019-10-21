#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l+(r-l)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);

		merge(arr, l, m, r);
	}
}

int partition(int arr[], int l, int r, int k);
int findMedian(int arr[], int n)
{
	mergeSort(arr,0,n-1);
	return arr[n/2];
}
int kthSmallest(int arr[], int l, int r, int k)
{
	if (k > 0 && k <= r - l + 1)
	{
		int n = r-l+1;
		int i, median[(n+4)/5];
		for (i=0; i<n/5; i++)
			median[i] = findMedian(arr+l+i*5, 5);
		if (i*5 < n)
		{
			median[i] = findMedian(arr+l+i*5, n%5);
			i++;
		}
		int medOfMed = (i == 1)? median[i-1]:
								kthSmallest(median, 0, i-1, i/2);
		int pos = partition(arr, l, r, medOfMed);
		if (pos-l == k-1)
			return arr[pos];
		if (pos-l > k-1)
			return kthSmallest(arr, l, pos-1, k);
		return kthSmallest(arr, pos+1, r, k-pos+l-1);
	}
	return INT_MAX;
}
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int arr[], int l, int r, int x)
{
    int i;
	for (i=l; i<r; i++)
		if (arr[i] == x)
		break;
	swap(&arr[i], &arr[r]);
	i = l;
	for (int j = l; j <= r - 1; j++)
	{
		if (arr[j] <= x)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[r]);
	return i;
}
int main()
{
	int arr[] = {1,2,7,6,5,11,12,8,9,6,3,6,};
	int n = sizeof(arr)/sizeof(arr[0]), k = 3;
	cout << "K'th smallest element is "
		<< kthSmallest(arr, 0, n-1, k);
	return 0;
}
