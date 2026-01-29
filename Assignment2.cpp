#include <iostream>
#include <algorithm>
using namespace std;

//Q1
struct Activity
{
    int start, finish;
};

bool compare(Activity a, Activity b)
{
    return a.finish < b.finish;
}

//Q2
int main()
{
    // -------- Q1: Activity Selection --------
    Activity a[] = {{1,2}, {3,4}, {0,6}, {5,7}, {8,9}, {5,9}};
    int n = 6;

    sort(a, a + n, compare);

    cout << "Q1 Maximum number of activities: ";
    int count = 1;
    int lastFinish = a[0].finish;

    cout << "\nSelected activities: (" << a[0].start << ", " << a[0].finish << ")";

    for (int i = 1; i < n; i++)
    {
        if (a[i].start >= lastFinish)
        {
            cout << ", (" << a[i].start << ", " << a[i].finish << ")";
            lastFinish = a[i].finish;
            count++;
        }
    }

    cout << "\nTotal = " << count << endl;

    // -------- Q2: Minimum Platforms --------
    int at[] = {900, 910, 920, 1100, 1120};
    int dt[] = {940, 1200, 950, 1130, 1140};
    int t = 5;

    sort(at, at + t);
    sort(dt, dt + t);

    int platforms = 1, result = 1;
    int i = 1, j = 0;

    while (i < t && j < t)
    {
        if (at[i] <= dt[j])
        {
            platforms++;
            i++;
        }
        else
        {
            platforms--;
            j++;
        }
        result = max(result, platforms);
    }

    cout << "\nQ2 Minimum number of platforms required = " << result << endl;

    return 0;
}

/*
OUTPUT:

Q1 Output:
Selected activities: (1, 2), (3, 4), (5, 7), (8, 9)
Maximum number of activities = 4

Q2 Output:
Minimum number of platforms required = 3
*/

