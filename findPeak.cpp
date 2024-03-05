#include <iostream>
using namespace std;

void initializeArray(int A[], int size) {
    srand(time(0));
    int mid = rand() % (size-5);
    int entry = rand() % 20;
    for (int i = 0; i < size; i++) {
        if (i < mid)
            A[i] = entry++;
        else if (i == mid)
            A[i] = entry++;
        else 
            A[i] = entry--;
    }
}

void print(int A[], int size) {
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
}

int findPeak(int A[], int low, int high) {
    if (low == high) {
        return low;
    }

    int mid = low + (high - low) / 2;
    if (A[mid] > A[mid + 1]) {
        return findPeak(A, low, mid); 
    }
    else {
        return findPeak(A, mid + 1, high); 
    }
}

int main() {
    int A[20] = {};
    int size = sizeof(A) / sizeof(A[0]);
    initializeArray(A, size);
    cout << "The original data: \n";
    print(A, size);
    int peak =findPeak(A, 0,size);
    cout << "\nThe peak entry is: " << A[peak] << "\n";
}
