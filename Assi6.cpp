#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr, int& totalSwaps, int& totalPasses) {
    int n = arr.size();
    totalSwaps = 0;
    totalPasses = 0;

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        totalPasses++;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
                totalSwaps++;
            }
        }

        if (!swapped) 
            break;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int totalSwaps, totalPasses;
    bubbleSort(arr, totalSwaps, totalPasses);

    cout << "Sorted Array: [";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) cout << ", ";
    }
    cout << "]\n";

    cout << "Total Swaps: " << totalSwaps << endl;
    cout << "Total Passes: " << totalPasses << endl;

    return 0;
}
