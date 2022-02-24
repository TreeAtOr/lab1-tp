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
        cout << "Enter a number:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Bad entry.  Enter a NUMBER: ";
        cin >> tmp;
    }
    return tmp;
}

void help(){
    cout << "0 - Add new number to queue"   << endl;
    cout << "1 - Pop a number from queue"   << endl;
    cout << "2 - Calculate even number"     << endl;
    cout << "3 - Print a queue"             << endl;
    cout << "4 - Quit the program"          << endl;
    cout << "5 - Create new queue"          << endl;
    cout << "6 - Create copy of last queue" << endl;
    cout << "7 - Concat queues"             << endl;
}

int extended(){
    PublicQueue* temp = NULL;
    PublicQueue *last = NULL;
    PublicQueue *queue = new PublicQueue();

    help();
    while (true) {
        int in;
        cout << "> ";
        in = input();
        try {
            switch (in) {
            case 0:
                cout << "Enter a number/:\n";
                in = input();
                queue->push(in); break;
            case 1:
                cout << queue->pop() << endl; break;
            case 2:
                cout << queue->calc() << endl; break;
            case 3:
                queue->print(); break;
            case 4: return 0;
            case 5: 
                if(last) delete last;
                last = queue;
                queue = new PublicQueue();
                break;
            case 6:
                if(last) delete last;
                last = queue;
                queue = new PublicQueue(last->copy());
                break;
            case 7:
                temp = new PublicQueue(Queue::concat(last, queue));
                delete last;
                last = queue;
                queue = temp;
                break;
            default:
                help();
            }
        } catch (string ex) {
            cout << ex << endl;
        }
    }
}

int wrapped(){
    ProtectedQueue* temp = NULL;
    ProtectedQueue *last = NULL;
    ProtectedQueue *queue = new ProtectedQueue();

    help();
    while (true) {
        int in;
        cout << "> ";
        in = input();
        try {
            switch (in) {
            case 0:
                cout << "Enter a number/:\n";
                in = input();
                queue->wrappedPush(in); break;
            case 1:
                cout << queue->wrappedPop() << endl; break;
            case 2:
                cout << queue->calc() << endl; break;
            case 3:
                queue->wrappedPrint(); break;
            case 4: return 0;
            case 5: 
                if(last) delete last;
                last = queue;
                queue = new ProtectedQueue();
                break;
            case 6:
                if(last) delete last;
                last = queue;
                queue = new ProtectedQueue(last->wrappedCopy());
                break;
            case 7:
                temp = new ProtectedQueue(ProtectedQueue::concat(last, queue));
                delete last;
                last = queue;
                queue = temp;
                break;
            default:
                help();
            }
        } catch (string ex) {
            cout << ex << endl;
        }
    }
}

int privatizated(){
    PrivateQueue* temp = NULL;
    PrivateQueue *last = NULL;
    PrivateQueue *queue = new PrivateQueue();

    help();
    while (true) {
        int in;
        cout << "> ";
        in = input();
        try {
            switch (in) {
            case 0:
                cout << "Enter a number/:\n";
                in = input();
                queue->wrappedPush(in); break;
            case 1:
                cout << queue->wrappedPop() << endl; break;
            case 2:
                cout << queue->calc() << endl; break;
            case 3:
                queue->wrappedPrint(); break;
            case 4: return 0;
            case 5: 
                if(last) delete last;
                last = queue;
                queue = new PrivateQueue();
                break;
            case 6:
                if(last) delete last;
                last = queue;
                queue = new PrivateQueue(last->wrappedCopy());
                break;
            case 7:
                temp = new PrivateQueue(PrivateQueue::concat(last, queue));
                delete last;
                last = queue;
                queue = temp;
                break;
            default:
                help();
            }
        } catch (string ex) {
            cout << ex << endl;
        }
    }
}

int main()
{
    cout << "================================"<< endl;
    cout << "You a running Lab1 program" << endl;
    cout << "================================"<< endl;
    cout << "NOTE: In this program you can use and store two queues in memory - 'last' and 'current'. If you create a new queue it will be automatically put in 'current' slot, preveus current become 'last' and 'last' queue will be deleted."  << endl << endl;
    cout << "Choose queue type:" << endl;
    cout << "0 - Public Queue" << endl;
    cout << "1 - Protected Queue" << endl;
    cout << "2 - Private Queue" << endl;

    int in = input();

    switch (in) {
        case 0: return extended();
        case 1: return wrapped();
        case 2: return privatizated();
    default:
        break;
    }
}
