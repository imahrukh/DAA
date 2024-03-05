#include <iostream>
#include <algorithm>

using namespace std;

bool compareMembers(int a, int b) {
    return a == b;
}

int findPassableResolution(int members[], int size) {
    sort(members, members + size);

    int half = size / 2;
    for (int i = 0; i <= size - half; i++) {
        if (compareMembers(members[i], members[i + half - 1])) {
            return members[i];
        }
    }
    return -1;
}

void print(int members[], int size) {
    for (int i = 0; i < size; i++) {
        cout << members[i] << " ";
    }
}

void initializeArray(int arr[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
       int r = rand() % 4 +1;
       arr[i] = r;
    }
}

int main() {
    //int members[10] = { 1080, 1000, 1240, 1240, 80, 1240, 1240, 680, 2080, 1240 };
    int members[10];
    int size = sizeof(members) / sizeof(members[0]);
    initializeArray(members, size);
    cout << "The voted resolutions are: \n";
    print(members, size);
    int passed = findPassableResolution(members, size);
    if (passed != -1) {
        cout << "\nPassable resolution: " << passed << "p" << endl;
    }
    else {
        cout << "\nNo passable resolution found" << endl;
    }
    return 0;
}
