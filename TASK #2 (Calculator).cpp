#include<iostream>
using namespace std;

class Calculator {
private:
    int a;
    int b;
    int Result;
   
public:
    void add() {
        cout << "\n\n+++ ADDITION +++\n";
        cout << "Enter 1st whole number: ";
        cin >> a;
        cout << "Enter 2nd whole number: ";
        cin >> b;
        Result = a + b;
        cout << "\nANSWER: (" << Result << ")\n";
    }

    void sub() {
        cout << "\n\n--- SUBTRACTION ---\n";
        cout << "Enter 1st whole number: ";
        cin >> a;
        cout << "Enter 2nd whole number: ";
        cin >> b;
        Result = a - b;
        cout << "\nANSWER: (" << Result << ")\n";
    }

    void mul() {
        cout << "\n\nxxx MULTIPLICATION xxx\n";
        cout << "Enter 1st whole number: ";
        cin >> a;
        cout << "Enter 2nd whole number: ";
        cin >> b;
        Result = a * b;
        cout << "\nANSWER: (" << Result << ")\n";
    }

    void div() {
        cout << "\n\n/// DIVISION ///\n";
        cout << "Enter 1st whole number: ";
        cin >> a;
        cout << "Enter 2nd natural number: ";
        cin >> b;
        if (b > 0) {
            Result = a / b;
            cout << "\nANSWER: (" << Result << ")\n";
        } else {
            cout << "!!! INVALID INPUT !!!\n\n";
        }
    }
};

int main() {
    Calculator c;
    int choice;
    char opt;

    do {
        cout << "\n********** CALCULATOR **********\n\n";
        cout << "           Hi there\n";
        cout << "\n*** Please select an operation you want to perform ***\n\n";
        cout << "Press 1 to select ADDITION (+)\n";
        cout << "Press 2 to select SUBTRACTION (-)\n";
        cout << "Press 3 to select MULTIPLICATION (X)\n";
        cout << "Press 4 to select DIVISION (/)\n";
        cin >> choice;

        switch (choice) {
            case 1:
                c.add();
                break;
            case 2:
                c.sub();
                break;
            case 3:
                c.mul();
                break;
            case 4:
                c.div();
                break;
            default:
                cout << "\nError: Invalid operation.\n\n";
                break;
        }

        cout << "\nDo you want to continue? (y/n)\n\n ";
        cin >> opt;
    } while (opt == 'y' || opt == 'Y');

    return 0;
}
