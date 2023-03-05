// C++ program for implementation of Quick, Merge and Heap Sort
#include <iostream>

using namespace std;
void swap(int *a, int *b);
int partitioning(int array[], int low, int high);
void merging(int *array, int l, int m, int r);
void heaping(int arr[], int n, int i);
void printArray(int arr[], int size);
void quickSort(int arr[], int low, int high);
void mergeSort(int *array, int l, int r);
void heapSort(int arr[], int n);

int main()
{
    int myArrray[] = {12, 11, 13, 5, 6, 7, 9, 20, 3, 8, 15, 1};
    int arraySize = sizeof(myArrray) / sizeof(myArrray[0]);

    // Prompt the user to enter two numbers and an operation
    std::cout << "Enter 'Q' for Quick Sort, 'M' for Merge Sort and 'H' for Heap Sort : ";

    // Read the input numbers and operation

    char sort;
    std::cin >> sort;
    switch (sort)
    {
    case 'Q':
    case 'q':
        printf("Quick Sort :\n");
        quickSort(myArrray, 0, arraySize - 1);
        printArray(myArrray, arraySize);
        break;
    case 'M':
    case 'm':
        printf("Merge Sort :\n");
        mergeSort(myArrray, 0, arraySize - 1);
        printArray(myArrray, arraySize);
        break;
    case 'H':
    case 'h':
        printf("Heap Sort :\n");
        heapSort(myArrray, arraySize);
        printArray(myArrray, arraySize);
        break;
    default:
        std::cout << "Invalid Sort Algorithm" << std::endl;
        return 1;
    }
}
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partitioning(int arr[], int low, int high)
{

    int pivot = arr[high];

    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partitioning(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void merging(int *array, int l, int m, int r)
{
    int i, j, k, nl, nr;
    nl = m - l + 1;
    nr = r - m;
    int larr[nl], rarr[nr];
    for (i = 0; i < nl; i++)
        larr[i] = array[l + i];
    for (j = 0; j < nr; j++)
        rarr[j] = array[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < nl && j < nr)
    {
        if (larr[i] <= rarr[j])
        {
            array[k] = larr[i];
            i++;
        }
        else
        {
            array[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < nl)
    {
        array[k] = larr[i];
        i++;
        k++;
    }
    while (j < nr)
    {
        array[k] = rarr[j];
        j++;
        k++;
    }
}
void mergeSort(int *array, int l, int r)
{
    int m;
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merging(array, l, m, r);
    }
}
void heaping(int arr[], int n, int i)
{
    int largest = i;   // Initialize largest as root Since we are using 0 based indexing
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heaping(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heaping(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heaping(arr, i, 0);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    cout << "Sorted array is \n";
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
