#include "ItemTracker.h"
#include <fstream>
#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

ItemTracker::ItemTracker(const string& inputFileName, const string& backupFileName) {
    inputFile = inputFileName;
    backupFile = backupFileName;

    LoadItems();
    WriteBackupFile(); // creates frequency.dat automatically at start
}

string ItemTracker::Trim(const string& s) {
    size_t start = 0;
    while (start < s.size() && isspace(static_cast<unsigned char>(s[start]))) {
        start++;
    }

    size_t end = s.size();
    while (end > start && isspace(static_cast<unsigned char>(s[end - 1]))) {
        end--;
    }

    return s.substr(start, end - start);
}

string ItemTracker::ToLowerCopy(string s) {
    transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return static_cast<char>(tolower(c)); });
    return s;
}

void ItemTracker::LoadItems() {
    ifstream inFS(inputFile);

    if (!inFS.is_open()) {
        cout << "ERROR: Could not open input file: " << inputFile << endl;
        return;
    }

    string item;
    while (getline(inFS, item)) {
        item = Trim(item);
        if (item.empty()) {
            continue;
        }

        string key = ToLowerCopy(item);

        itemCounts[key]++;

        // Save the first-seen casing for printing
        if (displayNames.find(key) == displayNames.end()) {
            displayNames[key] = item;
        }
    }

    inFS.close();
}

void ItemTracker::WriteBackupFile() const {
    ofstream outFS(backupFile);

    if (!outFS.is_open()) {
        cout << "WARNING: Could not write backup file: " << backupFile << endl;
        return;
    }

    for (const auto& pair : itemCounts) {
        // print with original casing
        auto it = displayNames.find(pair.first);
        string nameToPrint = (it != displayNames.end()) ? it->second : pair.first;

        outFS << nameToPrint << " " << pair.second << endl;
    }

    outFS.close();
}

int ItemTracker::GetItemCount(const string& item) const {
    string key = ToLowerCopy(Trim(item));
    auto it = itemCounts.find(key);

    if (it == itemCounts.end()) {
        return 0;
    }
    return it->second;
}

void ItemTracker::PrintAllCounts() const {
    for (const auto& pair : itemCounts) {
        auto it = displayNames.find(pair.first);
        string nameToPrint = (it != displayNames.end()) ? it->second : pair.first;

        cout << nameToPrint << " " << pair.second << endl;
    }
}

void ItemTracker::PrintHistogram(char symbol) const {
    for (const auto& pair : itemCounts) {
        auto it = displayNames.find(pair.first);
        string nameToPrint = (it != displayNames.end()) ? it->second : pair.first;

        cout << nameToPrint << " ";
        for (int i = 0; i < pair.second; i++) {
            cout << symbol;
        }
        cout << endl;
    }
}