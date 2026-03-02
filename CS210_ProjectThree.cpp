#include <iostream>
#include <limits>
#include <string>
#include "ItemTracker.h"

using namespace std;

static int ReadMenuChoice() {
    int choice;

    while (true) {
        cout << endl;
        cout << "Corner Grocer Menu" << endl;
        cout << "1. Search item frequency" << endl;
        cout << "2. Print all item frequencies" << endl;
        cout << "3. Print histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";

        if (cin >> choice && choice >= 1 && choice <= 4) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }

        cout << "Invalid input. Please enter a number from 1 to 4." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    const string inputFileName = "CS210_Project_Three_Input_File.txt";
    const string backupFileName = "frequency.dat";

    ItemTracker tracker(inputFileName, backupFileName);

    while (true) {
        int choice = ReadMenuChoice();

        if (choice == 1) {
            string item;
            cout << "Enter the item you want to look for: ";
            getline(cin, item);

            int count = tracker.GetItemCount(item);
            cout << "Frequency of \"" << item << "\": " << count << endl;
        }
        else if (choice == 2) {
            tracker.PrintAllCounts();
        }
        else if (choice == 3) {
            tracker.PrintHistogram('*');
        }
        else if (choice == 4) {
            cout << "Goodbye." << endl;
            break;
        }
    }

    return 0;
}