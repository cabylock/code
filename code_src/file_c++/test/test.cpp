#include<iostream>
using namespace std; 

int len = 0; 
int heap[100];

void swim(int i) {   
    if (i <= 0) return; 
    if (heap[i] < heap[(i-1)/2]) {
        swap(heap[i], heap[(i-1)/2]);
        swim((i-1)/2);
    }
}

void sink(int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < len && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < len && heap[right] < heap[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        sink(smallest);
    }
}

void erase() {
    swap(heap[0], heap[len-1]);
    len--;
    sink(0);
}

void insert(int data) {
    heap[len] = data;
    swim(len);
    len++;
}

void print_() {
    for (int i = 0; i < len; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void heapsort() {   
  
    while (len > 0) {
        cout << heap[0] << " "; 
        erase(); 
    }
    // Reset heap length after sorting
}

int main() {   
    insert(95);
    insert(61);
    insert(83);
    insert(53);
    insert(39);
    insert(72);
    insert(16);
    insert(24);
    insert(48);
      
    heapsort();
    return 0;
}
