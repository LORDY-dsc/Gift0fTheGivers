#ifndef ARRAYS_PARTB_H_INCLUDED
#define ARRAYS_PARTB_H_INCLUDED
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cctype>
#include<windows.h>
#include "Login_Manager.h"
#include "Doubly_Linked_List.h"
#include "Binary_Search_Trees.h"

using namespace std;

// ---------------- Supply arrays & manager ----------------
const int NUM_ITEMS = 7;

struct Supply {
    int ID;
    string name;
    int Quantity;
    string expiry;
};

class SupplyManager {
public:
    Supply supplies[NUM_ITEMS];

    SupplyManager() {
        supplies[0] = {101, "Food", 2000, "2025-12"};
        supplies[1] = {102, "Water", 2010, "None"};
        supplies[2] = {103, "Medicine", 150, "2029-09"};
        supplies[3] = {104, "Clothes", 150, "None"};
        supplies[4] = {105, "Blankets", 160, "None"};
        supplies[5] = {106, "Tents", 60, "None"};
        supplies[6] = {107, "HygieneKits", 100, "2029-03"};
    }

   static string toLowerCopy(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

int searchSupply(const string& key_in) {
    string key = toLowerCopy(key_in);
    for (int i = 0; i < NUM_ITEMS; ++i) {
        if (toLowerCopy(supplies[i].name) == key)
            return i;
    }
    return -1;
}

    void displaySupplies() {
        cout << "\nWarehouse Supplies:\n";
        for (int i = 0; i < NUM_ITEMS; ++i) {
            cout << "- " << supplies[i].name << " (ID: " << supplies[i].ID
                 << ") : " << supplies[i].Quantity << " units, Expiry: " << supplies[i].expiry << '\n';
        }
    }

    bool reduceSupplyByIndex(int idx, int qty) {
        if (idx < 0 || idx >= NUM_ITEMS) return false;
        if (supplies[idx].Quantity < qty) return false;
        supplies[idx].Quantity -= qty;
        return true;
    }

    // Simple bubble sort by quantity (keeps arrays aspect requested)
    void bubbleSortByQuantity() {
        for (int i = 0; i < NUM_ITEMS - 1; ++i) {
            for (int j = 0; j < NUM_ITEMS - i - 1; ++j) {
                if (supplies[j].Quantity > supplies[j+1].Quantity) {
                Supply temp = supplies[j];
                supplies[j] = supplies[j+1];
                supplies[j+1] = temp;
                }
            }
        }
    }
};

#endif // ARRAYS_PARTB_H_INCLUDED
