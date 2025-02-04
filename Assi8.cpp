#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<string>& arr, int pos) {
    int n = arr.size();
    vector<string> output(n);
    vector<int> count(26, 0);

    for (int i = 0; i < n; i++)
        count[arr[i][pos] - 'a']++;

    for (int i = 1; i < 26; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i][pos] - 'a'] - 1] = arr[i];
        count[arr[i][pos] - 'a']--;
    }

    arr = output;
}

void radixSort(vector<string>& arr) {
    int len = arr[0].size();

    for (int pos = len - 1; pos >= 0; pos--)
        countingSort(arr, pos);
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    radixSort(arr);

    for (const string& str : arr)
        cout << str << " ";

    return 0;
}
