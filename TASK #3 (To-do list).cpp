#include <iostream>
#include <string>
using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        string data;
        bool completed;
        struct Node* prev;
        struct Node* next;
    };

    struct Node* head = NULL;

public:
    void insert() {
        string newdata;
        cout << "\nEnter data to insert: ";
        cin.ignore();
        getline(cin, newdata);

        struct Node* newnode = new Node;
        newnode->data = newdata;
        newnode->completed = false;
        newnode->prev = nullptr;
        newnode->next = head;

        if (head != nullptr)
            head->prev = newnode;

        head = newnode;
    }

    void display() {
        struct Node* ptr;
        ptr = head;
        int taskNumber = 1;
        while (ptr != nullptr) {
            cout <<"|   "<< taskNumber << ". ";
            if (ptr->completed)
            { cout << "[Completed] ";
                cout << ptr->data<<"       |"<<endl ;
            }
            else
            {
                cout << "[Pending] ";
                cout << ptr->data<<"         |"<<endl ;
                
            }
            ptr = ptr->next;
            taskNumber++;
        }
        cout << "|                                |"<<endl;
    }

    void markCompleted(int taskNumber) {
        struct Node* ptr = head;
        int currentTask = 1;

        while (ptr != nullptr) {
            if (currentTask == taskNumber) {
                ptr->completed = true;
                cout << "Task " << taskNumber << " marked as completed." << endl;
                return;
            }
            ptr = ptr->next;
            currentTask++;
        }

        cout << "Task " << taskNumber << " not found." << endl;
    }

    void deleteNode(string value) {
        struct Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                if (current->prev != nullptr)
                    current->prev->next = current->next;
                else
                    head = current->next;

                if (current->next != nullptr)
                    current->next->prev = current->prev;

                delete current;
                cout << "Node with value " << value << " deleted." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Node with value " << value << " not found." << endl;
    }
};

int main() {
    DoublyLinkedList list;

    while (true) {
        cout << "*********************************"<<endl;
        cout << "*                               *"<<endl;
        cout << "*          MAIN MENU:           *"<<endl;
        cout << "*                               *"<<endl;
        cout << "*   1. Insert                   *" << endl;
        cout << "*   2. Mark Task as Completed   *" << endl;
        cout << "*   3. Delete                   *" << endl;
        cout << "*   4. Display                  *" << endl;
        cout << "*   5. Exit                     *" << endl;
        cout << "*                               *"<<endl;
        cout << "*                               *"<<endl;
        cout << "*********************************"<<endl;
        cout << "\n Enter your choice:";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                list.insert();
                break;
            case 2: {
                int taskNumber;
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                cin.ignore(); // Ignore the newline character in the input buffer
                list.markCompleted(taskNumber);
                break;
            }
            case 3: {
                string valueToDelete;
                cout << "\nEnter task name to delete: ";
                cin.ignore(); // Ignore the newline character in the input buffer
                getline(cin, valueToDelete);
                list.deleteNode(valueToDelete);
                break;
            }
            case 4:
                cout <<endl;
                cout << " --------------------------------"<<endl;
                cout << "|                                |"<<endl;
                cout << "|          MY TO-DO LIST:        |"<<endl;
                cout << "|                                |"<<endl;
                list.display();
                cout << " --------------------------------"<<endl;
                cout<<endl;
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
