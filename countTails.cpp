#include <iostream>

using namespace std;

void initializeArray(char arr[], int n) {
    srand(time(0));
    int mid = rand() % 50;
    for (int i = 0; i < n; i++) {
        if (i < mid)
            arr[i] = 'H';
        else
            arr[i] = 'T';
    }
}

void printArray(char arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int countTails(char coin[], int size) {
    int left = 0, right = size - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (coin[mid] == 'T') {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return size - left;
}


int main() {
    char coin[50];
    initializeArray(coin, sizeof(coin));
    cout << "The coin toss: \n";
    printArray(coin, sizeof(coin));
    int numTails = countTails(coin, sizeof(coin));
    cout << "Number of occurrences of tail: " << numTails << "\n";
    return 0;
}
