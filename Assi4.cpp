#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> dynamicArray;

    int numElements;
    cin >> numElements;
    cout << "Enter the number of elements you want to store:"<<numElements<<"\n";
   

    cout << "Enter " << numElements << " elements \n";
    for (int i = 0; i < numElements; ++i) {
        int element;
        cin >> element;
        dynamicArray.push_back(element);
    }

    cout << "Elements in the vector: ";
    for (const int& element : dynamicArray) {
        cout << element << " ";
    }
    cout << "\n";

    int newElement;
    cin >> newElement;
    cout << "Enter a new element to add to the vector: "<<newElement<<" \n";
    
    if (cin.fail()) {
        cout << "Invalid input. Exiting program.\n";
        return 1;
    }
    dynamicArray.push_back(newElement);

    cout << "Updated vector: ";
    for (const int& element : dynamicArray) {
        cout << element << " ";
    }
    cout << "\n";

    return 0;
}
