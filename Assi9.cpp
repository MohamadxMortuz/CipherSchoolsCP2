#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class SquareRootDecomposition {
    vector<int> arr, block;
    int blockSize, n;

public:
    SquareRootDecomposition(vector<int>& input) {
        n = input.size();
        blockSize = sqrt(n);
        arr = input;
        block.assign((n + blockSize - 1) / blockSize, 0);

        for (int i = 0; i < n; i++)
            block[i / blockSize] += arr[i];
    }

    void update(int index, int value) {
        int blockIndex = index / blockSize;
        block[blockIndex] += value - arr[index];
        arr[index] = value;
    }

    int query(int L, int R) {
        int sum = 0;
        while (L <= R && L % blockSize != 0)
            sum += arr[L++];

        while (L + blockSize - 1 <= R) {
            sum += block[L / blockSize];
            L += blockSize;
        }

        while (L <= R)
            sum += arr[L++];

        return sum;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SquareRootDecomposition sqrtDecomp(arr);

    while (q--) {
        string type;
        cin >> type;
        if (type == "UPDATE") {
            int index, value;
            cin >> index >> value;
            sqrtDecomp.update(index - 1, value);
        } else if (type == "QUERY") {
            int L, R;
            cin >> L >> R;
            cout << sqrtDecomp.query(L - 1, R - 1) << endl;
        }
    }

    return 0;
}
