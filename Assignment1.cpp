#include <iostream>
using namespace std;

//Q1
int binarySearch(int arr[], int low, int high, int key)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            return binarySearch(arr, low, mid - 1, key);
        else
            return binarySearch(arr, mid + 1, high, key);
    }
    return -1;
}

//Q2
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

//Q3
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//Q4
int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

int maxCrossingSum(int arr[], int l, int m, int h)
{
    int sum = 0, left_sum = arr[m];

    for (int i = m; i >= l; i--)
    {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = arr[m + 1];

    for (int i = m + 1; i <= h; i++)
    {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}

int maxSubArraySum(int arr[], int l, int h)
{
    if (l == h)
        return arr[l];

    int m = (l + h) / 2;

    return maximum(
        maximum(maxSubArraySum(arr, l, m),
                maxSubArraySum(arr, m + 1, h)),
        maxCrossingSum(arr, l, m, h));
}

int main()
{
    //Q1

    int a1[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    cout << "Q1 Output: " << binarySearch(a1, 0, 9, 23) << endl;

    //Q2

    int a2[] = {12, 11, 13, 5, 6, 7};
    int a3[] = {38, 27, 43, 3, 9, 82, 10};

    mergeSort(a2, 0, 5);
    mergeSort(a3, 0, 6);

    cout << "Q2 Output 1: ";
    for (int i = 0; i < 6; i++) cout << a2[i] << " ";

    cout << "\nQ2 Output 2: ";
    for (int i = 0; i < 7; i++) cout << a3[i] << " ";

    //Q3

    int a4[] = {4, 2, 6, 9, 2};
    quickSort(a4, 0, 4);

    cout << "\nQ3 Output: ";
    for (int i = 0; i < 5; i++) cout << a4[i] << " ";

    //Q4

    int a5[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    cout << "\nQ4 Output: " << maxSubArraySum(a5, 0, 7) << endl;

    return 0;
}


/*
OUTPUT:

Q1 Output:
Binary Search: Element found at index 5

Q2 Output:
Merge Sort Result 1: 5 6 7 11 12 13
Merge Sort Result 2: 3 9 10 27 38 43 82

Q3 Output:
Quick Sort Result: 2 2 4 6 9

Q4 Output:
Maximum Subarray Sum = 7
*/
