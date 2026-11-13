#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[parent] >= heap[index])
                break;

            swap(heap[parent], heap[index]);
            index = parent;
        }
    }

    void heapifyDown(int index) {
        int n = heap.size();

        while (true) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < n && heap[left] > heap[largest])
                largest = left;

            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest == index)
                break;

            swap(heap[index], heap[largest]);
            index = largest;
        }
    }

public:

    // Insert a new value
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Search for a value
    int search(int value) {
        for (int i = 0; i < heap.size(); i++) {
            if (heap[i] == value)
                return i;
        }

        return -1;
    }

    // Delete a value
    bool deleteValue(int value) {
        int index = search(value);

        if (index == -1)
            return false;

        // Replace the element with the last element
        heap[index] = heap.back();
        heap.pop_back();

        if (index < heap.size()) {
            // Decide whether to move up or down
            if (index > 0 &&
                heap[index] > heap[(index - 1) / 2]) {
                heapifyUp(index);
            }
            else {
                heapifyDown(index);
            }
        }

        return true;
    }

    // Display heap
    void display() {
        if (heap.empty()) {
            cout << "Heap is empty.\n";
            return;
        }

        cout << "Heap: ";

        for (int value : heap)
            cout << value << " ";

        cout << endl;
    }
};

int main() {

    MaxHeap h;

    // Read initial heap from tree.txt
    ifstream file("tree.txt");

    if (!file) {
        cout << "Error: Could not open tree.txt\n";
        return 1;
    }

    int n;
    file >> n;

    for (int i = 0; i < n; i++) {
        int value;
        file >> value;
        h.insert(value);
    }

    file.close();

    cout << "Initial ";
    h.display();

    int choice, value;

    do {
        cout << "\n===== HEAP MENU =====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value to insert: ";
            cin >> value;

            h.insert(value);

            cout << "Value inserted successfully.\n";
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;

            if (h.deleteValue(value))
                cout << "Value deleted successfully.\n";
            else
                cout << "Value not found.\n";

            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;

            if (h.search(value) != -1)
                cout << "Value found at index "
                     << h.search(value) << ".\n";
            else
                cout << "Value not found.\n";

            break;

        case 4:
            h.display();
            break;

        case 5:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}