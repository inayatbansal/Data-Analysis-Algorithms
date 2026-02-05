#include <iostream>
using namespace std;

int main() {
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};

    int count = 1;
    int lastFinish = finish[0];

    cout << "Selected activities:\n";
    cout << "(" << start[0] << ", " << finish[0] << ")\n";

    for (int i = 1; i < n; i++) {
        if (start[i] >= lastFinish) {
            cout << "(" << start[i] << ", " << finish[i] << ")\n";
            count++;
            lastFinish = finish[i];
        }
    }

    cout << "Maximum number of activities = " << count;
    return 0;
}


/*
Output: 
Selected activities:
(1, 2)
(3, 4)
(5, 7)
(8, 9)
Maximum number of activities = 4
*/