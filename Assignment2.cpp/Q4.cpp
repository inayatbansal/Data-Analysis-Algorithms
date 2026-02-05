#include <iostream>
using namespace std;

int main() {
    int n = 5;

    string job[] = {"J1", "J2", "J3", "J4", "J5"};
    int deadline[] = {2, 1, 2, 1, 3};
    int profit[] = {100, 19, 27, 25, 15};

    bool slot[3] = {false};
    int totalProfit = 0;

    cout << "Selected Jobs: ";

    for (int i = 0; i < n; i++) {
        for (int j = deadline[i] - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                totalProfit += profit[i];
                cout << job[i] << " ";
                break;
            }
        }
    }

    cout << "\nMaximum Profit = " << totalProfit;
    return 0;
}

/*
Output: 
Selected Jobs: J1 J2 J5 
Maximum Profit = 134
*/