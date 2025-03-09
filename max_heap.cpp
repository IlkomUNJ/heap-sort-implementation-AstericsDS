#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    // Set the given node as a parent, then set the index for left and right child
    int parent = i;
    int left = i*2 + 1;
    int right = i*2 + 2;
    
    // Check if left/right child exist by checking if it is less than the array size. If there any child with a greater value than parent, swap the index.
    if(left < n && arr[left] > arr[parent]) {
        parent = left;
    }

    if(right < n && arr[right] > arr[parent]) {
        parent = right;
    }

    // If any index swapping has occured, then the parent isn't equal to i (initialized node), then we for real swap the value. The recursive part is setting the swapped index as the new parent node and redo the process.
    if(parent != i) {
        swap(arr[i], arr[parent]);
        heapify(arr, n, parent);
    }
}

void build_max_heap(int arr[], int n) {
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
}

int main() {
    // Initializing primitive array
    int num[5] = {4, 10, 1, 3, 17};

    cout << "Unsorted array: ";
    for(int i = 0; i < 5; i++) {
        cout << num[i] << " ";
    }
    cout << endl;

    // Heapify process
    int member = sizeof(num)/ sizeof(num[0]);
    build_max_heap(num, member);

    // Output
    cout << "Max heap: ";
    for(int i = 0; i < 5; i++) {
        cout << num[i] << " ";
    }
    cout << endl;

    return 0;
}