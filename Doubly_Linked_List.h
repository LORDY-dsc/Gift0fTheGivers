#ifndef DOUBLY_LINKED_LIST_H_INCLUDED
#define DOUBLY_LINKED_LIST_H_INCLUDED
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cctype>
#include<windows.h>
#include "Login_Manager.h"
#include "Arrays_PartB.h"
#include "Binary_Search_Trees.h"

using namespace std;


// ---------------- Shipment doubly-linked list ----------------
struct Shipment {
    int id;
    string type;
    string destination;
    int quantity;
    Shipment* prev;
    Shipment* next;
    Shipment(int i, string t, string d, int q) : id(i), type(t), destination(d), quantity(q), prev(nullptr), next(nullptr) {}
};

int generateID() {
    static int counter = 1;
    return counter++;
}

class ShipmentList {
private:
    Shipment* head;
    Shipment* tail;
    SupplyManager &manager;

    // valid capital cities (simple list)
    vector<string> validDestinations = {
        "Pretoria", "Bloemfontein", "Pietermaritzburg", "Polokwane",
        "Mbombela", "Kimberley", "Mahikeng", "Bhisho", "CapeTown", "Johannesburg", "Durban"
    };

    static string toLowerCopy(string s) {
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::tolower(c); });
        return s;
    }

    bool isValidDestination(const string& city) {
        string cLower = toLowerCopy(city);
        for (auto &v : validDestinations) {
            if (toLowerCopy(v) == cLower) return true;
        }
        return false;
    }

public:
    ShipmentList(SupplyManager &m) : head(nullptr), tail(nullptr), manager(m) {}

    void addShipment(const string& type, const string& destination, int quantity) {
        int idx = manager.searchSupply(type);
        if (idx == -1) {
            cout << "Request denied! '" << type << "' is not in the supply list.\n";
            return;
        }

        if (!isValidDestination(destination)) {
            cout << "Invalid destination! Please use a valid capital city.\n";
            return;
        }

        if (quantity <= 0) {
            cout << "Quantity must be > 0.\n";
            return;
        }

        if (quantity > manager.supplies[idx].Quantity) {
            cout << "Request denied! Only " << manager.supplies[idx].Quantity
                 << " units of " << manager.supplies[idx].name << " available.\n";
            return;
        }

        // deduct
        manager.reduceSupplyByIndex(idx, quantity);

        int id = generateID();
        Shipment* node = new Shipment(id, manager.supplies[idx].name, destination, quantity);

        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }

        // Ticket
        cout << "\n=========================\n";
        cout << "   Shipment Ticket   \n";
        cout << "-------------------------\n";
        cout << "Shipment ID : " << id << "\n";
        cout << "Type        : " << node->type << "\n";
        cout << "Destination : " << node->destination << "\n";
        cout << "Quantity    : " << node->quantity << "\n";
        cout << "=========================\n";
    }

    void displayForward() {
        Shipment* cur = head;
        if (!cur) {
            cout << "No shipments to display.\n";
            return;
        }
        cout << "\nAll Shipments:\n";
        while (cur) {
            cout << "ID: " << cur->id << " | " << cur->type << " -> " << cur->destination
                 << " | Qty: " << cur->quantity << '\n';
            cur = cur->next;
        }
    }
};


#endif // DOUBLY_LINKED_LIST_H_INCLUDED
