#include <iostream>
#include <chrono>
using namespace std;

void heapify(int arr[], int count, int root)
{
    // maximum  root
    int Max_number = root;
    int leftnode = 2 * root + 1;
    int rightnode = 2 * root + 2;

    // check left child
    if (leftnode < count && arr[leftnode] > arr[Max_number])
        Max_number = leftnode;

    // check right child 
    if (rightnode < count && arr[rightnode] > arr[Max_number])
        Max_number = rightnode;

    // check if largest root
    if (Max_number != root) {
        swap(arr[root], arr[Max_number]);

        heapify(arr, count, Max_number);
    }
}

// heap sort algorithm
void heapSort(int arr[], int n)
{
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extracting elements from heap one by one
    for (int i = n - 1; i > 0; i--) {

        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

//print an array
void displayArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// main program
int main()
{
    int number; // code to get elements from the user
    cout << "Enter the size of the array ";
    cin >> number;

    int heap_arr[number];
   
    for (int i = 0; i < number; i++) {
        cin >> heap_arr[i];
    }
    int n = sizeof(heap_arr)/sizeof(heap_arr[0]);

    auto start = chrono::high_resolution_clock::now(); 

    heapSort(heap_arr, n);

    auto end = chrono::high_resolution_clock::now(); 
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start); 

    cout << "after sorting: ";
    displayArray(heap_arr, n);

    cout <<"Execution time"<< duration.count() << " microseconds" << endl; }