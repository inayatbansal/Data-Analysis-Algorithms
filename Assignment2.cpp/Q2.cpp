#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n = 5;
    int arr[] = {900, 910, 920, 1100, 1120};
    int dep[] = {940, 1200, 950, 1130, 1140};

    sort(arr, arr + n);
    sort(dep, dep + n);

    int platform = 1, result = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arr[i] < dep[j]) {
            platform++;
            i++;
        } else {
            platform--;
            j++;
        }
        result = max(result, platform);
    }

    cout << "Minimum number of platforms required = " << result;
    return 0;
}

/*
Ouput : Minimum number of platforms required = 3
 */