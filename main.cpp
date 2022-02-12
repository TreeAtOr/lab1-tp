#include <iostream>
#include <string>
#include <limits>
#include "./PublicQueue/publicqueue.h"
#include "./ProtectedQueue/protectedqueue.h"
#include "./PrivateQueue/privatequeue.h"
#include "Queue/queue.h"
using namespace std;

int input(){
    int tmp;
    cin >> tmp;
    while(cin.fail()) {
        cout << "Enter a number/:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Bad entry.  Enter a NUMBER: ";
        cin >> tmp;
    }
    return tmp;
}

int extended(){
    PublicQueue queue;
    while (true) {
        int in;
        cout << "0 - Add new number to queue" << endl;
        cout << "1 - Pop a number from queue" << endl;
        cout << "2 - Calculate odd number"    << endl;
        cout << "3 - Print a queue"           << endl;
        cout << "4 - Quit the program"        << endl;

        cout << "> ";
        in = input();
        try {
            switch (in) {
            case 0:
                cout << "Enter a number/:\n";
                in = input();
                queue.push(in); break;
            case 1:
                cout << queue.pop(); break;
            case 2:
                cout << queue.calc(); break;
            case 3:
                queue.print(); break;
            default:
                return 0;
            }
        } catch (string ex) {
            cout << ex << endl;
        }
    }
}

int wrapped(){
    ProtectedQueue queue;
    while (true) {
        int in;
        cout << "0 - Add new number to queue" << endl;
        cout << "1 - Pop a number from queue" << endl;
        cout << "2 - Calculate odd number"    << endl;
        cout << "3 - Print a queue"           << endl;
        cout << "4 - Quit the program"        << endl;

        cout << "> ";
        in = input();
        try {
            switch (in) {
                case 0:
                    cout << "Enter a number/:\n";
                    in = input();
                    queue.wrappedPush(in); break;
                case 1:
                    cout << queue.wrappedPop(); break;
                case 2:
                    cout << queue.calc(); break;
                case 3:
                    queue.wrappedPrint(); break;
                default:
                    return 0;
            }
        } catch (string ex) {
            std::cout << ex << std::endl;
        }
    }
}

int privatizated(){
    PrivateQueue queue;
    while (true) {
        int in;
        cout << "0 - Add new number to queue" << endl;
        cout << "1 - Pop a number from queue" << endl;
        cout << "2 - Calculate odd number"    << endl;
        cout << "3 - Print a queue"           << endl;
        cout << "4 - Quit the program"        << endl;

        cout << "> ";
        in = input();
        try {
            switch (in) {
                case 0:
                    in = input();
                    queue.wrappedPush(in); break;
                case 1:
                    cout << queue.wrappedPop(); break;
                case 2:
                    cout << queue.calc(); break;
                case 3:
                    queue.wrappedPrint(); break;
                default:
                    return 0;
            }
        } catch (string ex) {
            std::cout << ex << std::endl;
        }
    }
}

int main()
{
    
    int in = input();
    cout << "0 - Public Queue" << endl;
    cout << "1 - Protected Queue" << endl;
    cout << "2 - Private Queue" << endl;
    switch (in) {
        case 0: return extended();
        case 1: return wrapped();
        case 2: return privatizated();
    default:
        break;
    }
}
