#include <iostream>
#include <vector>

using namespace std;

// InsertionSort:
int shifts = 0; // Global shifts
void insertionSort(int * ar, int ar_size) {
    for (int i = 1; i < ar_size; i++) {
        int j = i;
        int value = ar[i];
        while (j > 0 && ar[j-1] > value) {
            ar[j] = ar[j-1];
            j--;
            shifts++;
        }
        ar[j] = value;
    }
}

// QuickSort:
int swaps = 0; // global swaps;
void swap(int * A, int * B){
    int temp = *A;
    *A = *B;
    *B = temp;
}

int partition(int * ar, int left, int right) {    
    int pivotValue = ar[right];
    int storeIndex = left;
    for (int i = left; i < right; i++){
        if (ar[i] <= pivotValue) {
            swaps++;
            swap(ar[i], ar[storeIndex]);
            storeIndex++;
        }
    }
    swaps++;
    swap(ar[storeIndex], ar[right]);
    return storeIndex;
}

void quickSort(int * ar, int i, int k) {
    if (i < k) {
        int p = partition (ar, i, k);
        quickSort(ar, i, p-1);
        quickSort(ar, p+1, k);
    }
}

int main() {
    int len;
    cin >> len; // Array size
    
    int arQ[len], arI[len];
    for (int i = 0; i < len; i++){
        cin >> arQ[i];
        arI[i] = arQ[i];
    }
    quickSort(arQ, 0, len-1);
    insertionSort(arI, len);
    
    cout << shifts - swaps;
    
}