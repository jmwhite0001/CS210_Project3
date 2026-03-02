#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <string>
#include <map>
#include <unordered_map>

class ItemTracker {
public:
    ItemTracker(const std::string& inputFileName, const std::string& backupFileName);

    int GetItemCount(const std::string& item) const;
    void PrintAllCounts() const;
    void PrintHistogram(char symbol = '*') const;

private:
    std::string inputFile;
    std::string backupFile;

    // key = lowercase item name (for case-insensitive matching)
    std::map<std::string, int> itemCounts;

    // key = lowercase, value = original casing from first time we saw it (for nice printing)
    std::unordered_map<std::string, std::string> displayNames;

    static std::string Trim(const std::string& s);
    static std::string ToLowerCopy(std::string s);

    void LoadItems();
    void WriteBackupFile() const;
};

#endif