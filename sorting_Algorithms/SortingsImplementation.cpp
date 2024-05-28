#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = LONG_MAX >> 1;

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(vector<int> &arr, int start, int mid, int end)
{
    int length1st = mid - start + 1;
    int length2nd = end - mid;
    vector<int> arr1st(length1st);
    vector<int> arr2nd(length2nd);

    for (int i = 0; i < length1st; i++)
    {
        arr1st[i] = arr[start + i];
    }
    for (int i = 0; i < length2nd; i++)
    {
        arr2nd[i] = arr[mid + 1 + i];
    }

    int index1 = 0, index2 = 0, index = start;
    while (index1 < length1st && index2 < length2nd)
    {
        if (arr1st[index1] <= arr2nd[index2])
        {
            arr[index] = arr1st[index1];
            index1++;
        }
        else
        {
            arr[index] = arr2nd[index2];
            index2++;
        }
        index++;
    }

    while (index1 < length1st)
    {
        arr[index] = arr1st[index1];
        index1++;
        index++;
    }

    while (index2 < length2nd)
    {
        arr[index] = arr2nd[index2];
        index2++;
        index++;
    }
}

void mergeSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
//-------------------------------------------------------------------------------->quicksort
void quickSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int pivot = arr[end];
        int i = start - 1;
        for (int j = start; j < end; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[end]);
        int partitionIndex = i + 1;
        quickSort(arr, start, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, end);
    }
}

void print(const vector<int> &arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> originalArr = {5, 4, 3, 2, 1};

    vector<int> arr = originalArr;
    bubbleSort(arr);
    cout << "Bubble Sort:" << endl;
    print(arr);
    cout << endl;

    arr = originalArr;
    selectionSort(arr);
    cout << "Selection Sort:" << endl;
    print(arr);
    cout << endl;

    arr = originalArr;
    insertionSort(arr);
    cout << "Insertion Sort:" << endl;
    print(arr);
    cout << endl;

    arr = originalArr;
    mergeSort(arr, 0, arr.size() - 1);
    cout << "Merge Sort:" << endl;
    print(arr);
    cout << endl;

    arr = originalArr;
    quickSort(arr, 0, arr.size() - 1);
    cout << "Quick Sort:" << endl;
    print(arr);
    cout << endl;

    return 0;
}
