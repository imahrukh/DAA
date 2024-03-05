#include <iostream>
#include <string>

using namespace std;

void sortColors(char balls[], int size) {

    int low = 0, mid = 0, high = size - 1;
    while (mid <= high) {
        switch (balls[mid]) {
        case 'R':
            swap(balls[low], balls[mid]);
            low++;
            mid++;
            break;
        case 'O':
            mid++;
            break;
        case 'G':
            swap(balls[mid], balls[high]);
            high--;
            break;
        }
    }
}

void initializeArray(char balls[], char color1, char color2, char color3, int size) {
    if (color1 == color2 || color1 == color3 || color2 == color3) {
        cerr << "Error: Color characters cannot be the same." << endl;
        exit(1);  
    }

    srand(time(0)); 
    for (int i = 0; i < size; i++) {
        int randomIndex = rand() % 3;
        balls[i] = (randomIndex == 0) ? color1 : (randomIndex == 1) ? color2 : color3;
    }
}

void print(char balls[], int size) {
    for (int i = 0; i < size; i++) {
        cout << balls[i] << " ";
    }
    cout << endl;
}

int main() {
    char array[50];
    initializeArray(array, 'R', 'O', 'G', sizeof(array));
    cout << "Original balls: \n";
    print(array, sizeof(array));
    sortColors(array, sizeof(array));
    cout << "Sorted balls in order (Red, Orange, Green): \n";
    print(array, sizeof(array));
    return 0;
}
