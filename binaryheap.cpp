#include<bits/stdc++.h>
using namespace std;
class maxheap{
    private:
        vector<int>heap;
        
        void maxheapify(vector<int>&heap, int idx){\
            int n = heap.size();

            if(idx >= heap.size()){
                cout<<"ERROR!! Invalid Index"<<endl;
                return;
            }

            int large = idx;
            int left = idx*2 + 1;
            int right = 2*idx + 2;

            if(left < n && heap[left] > heap[large])large = left;
            if(right < n && heap[right] > heap[large])large = right;

            if(large != idx){
                swap(heap[large] , heap[idx]);
                maxheapify(heap,large);
            }
            return;
        }

        public:
            // INSERTION
            void insert(int val){
                heap.push_back(val);
                maxheapify(heap,heap.size()-1);
            }

            // SEARCHING
            int search(int val){
                for(int i = 0; i < heap.size();i++){
                    if(heap[i] == val)return i;
                }
                return -1;
            }

            // DELETE
            void delete_(int val){
                int idx = search(val);
                if(idx == -1){
                    cout<<"ERROR!! Value Not Found"<<endl;
                    return;
                }

                heap[idx] = heap.back();
                heap.pop_back();

                maxheapify(heap,idx);

                cout<<"Value is Deleted\n";
            }

            // DISPLAY HEAP
            void display(){
                for(int i : heap)cout<<i<<" ";
                cout<<endl;
            }
};

int main(){
    

    // Reading input from .txt file
    ifstream file("tree.txt");

    if(!file){
        cout<<"ERROR!! Could Not Open tree.txt\n";
        return 1;
    }

    int n;
    file>>n;

    if(n < 0){
        cout<<"ERROR!! Invalid Size Input\n";
        file.close();
    }
    maxheap h;
    for(int i = 0; i < n;i++){
        int val;
        file>>val;
        h.insert(val);
    }

    file.close();

    cout<<"Initial Heap:\n";
    h.display();

    int choice , val;

    do{
        cout << "\n===== HEAP MENU =====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){

        case 1:
            cout << "Enter value to insert: ";
            cin >> val;

            h.insert(val);

            cout << "Value inserted successfully.\n";
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            h.delete_(val);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> val;

            if (h.search(val) != -1)
                cout << "Value found at index "
                     << h.search(val) << ".\n";
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
    }while(choice != 5);

    return 0;
}