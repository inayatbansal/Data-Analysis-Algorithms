#include <iostream>
using namespace std;

int main() {
    int n = 3;
    float value[] = {100, 60, 120};
    float weight[] = {20, 10, 40};
    float W = 50;

    float ratio[n];
    for (int i = 0; i < n; i++)
        ratio[i] = value[i] / weight[i];

    float totalValue = 0;

    for (int i = 0; i < n; i++) {
        if (weight[i] <= W) {
            W -= weight[i];
            totalValue += value[i];
        } else {
            totalValue += ratio[i] * W;
            break;
        }
    }

    cout << "Maximum value = " << totalValue;
    return 0;
}

/* 
Output: Maximum value = 220
 */