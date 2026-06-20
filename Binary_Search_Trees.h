#ifndef BINARY_SEARCH_TREES_H_INCLUDED
#define BINARY_SEARCH_TREES_H_INCLUDED

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cctype>
#include <iomanip>
#include <windows.h>

#include "Login_Manager.h"
#include "Doubly_Linked_List.h"
#include "Arrays_PartB.h"


using namespace std;

// ---------------- Binary Search Trees (warehouse supplies & orders) ----------------
class SupplyNode {
public:
    string itemName;
    int quantity;
    SupplyNode* left;
    SupplyNode* right;

    SupplyNode(const string& item, int qty)
        : itemName(item), quantity(qty), left(nullptr), right(nullptr) {}
};

class SupplyBST {
private:
    SupplyNode* root;

    SupplyNode* insert(SupplyNode* node, const string& item, int qty) {
        if (!node) return new SupplyNode(item, qty);
        if (item < node->itemName) node->left = insert(node->left, item, qty);
        else if (item > node->itemName) node->right = insert(node->right, item, qty);
        else node->quantity += qty;
        return node;
    }

    void inorder(SupplyNode* n) {
        if (!n) return;
        inorder(n->left);

        // print row
        cout << left << setw(20) << n->itemName
             << setw(10) << n->quantity << '\n';

        inorder(n->right);
    }

    SupplyNode* search(SupplyNode* n, const string& item) {
        if (!n) return nullptr;
        if (item == n->itemName) return n;
        if (item < n->itemName) return search(n->left, item);
        return search(n->right, item);
    }

public:
    SupplyBST() : root(nullptr) {}

    void addSupply(const string& item, int qty) { root = insert(root, item, qty); }

    void displaySupplies() {
        if (!root) {
            cout << "Warehouse BST is empty.\n";
            return;
        }

        cout << "\n================= Warehouse Supplies (BST) =================\n";
        cout << left << setw(20) << "Item"
             << setw(10) << "Quantity" << '\n';
        cout << string(30, '-') << '\n';

        inorder(root);

        cout << "===========================================================\n";
    }

    bool reduceSupply(const string& item, int qty) {
        SupplyNode* f = search(root, item);
        if (!f) {
            cout << "Item not found in warehouse BST.\n";
            return false;
        }
        if (f->quantity < qty) {
            cout << "Not enough " << item
                 << " in BST warehouse. Available: " << f->quantity << '\n';
            return false;
        }
        f->quantity -= qty;
        cout << "BST: dispatched " << qty << " " << item
             << ". Remaining: " << f->quantity << '\n';
        return true;
    }
};

// ---------------- Orders BST ----------------
class OrderNode {
public:
    string hubName;
    string itemName;
    int quantity;
    OrderNode* left;
    OrderNode* right;

    OrderNode(const string& hub, const string& item, int qty)
        : hubName(hub), itemName(item), quantity(qty), left(nullptr), right(nullptr) {}
};

class OrderBST {
private:
    OrderNode* root;

    OrderNode* insert(OrderNode* node, const string& hub, const string& item, int qty) {
        if (!node) return new OrderNode(hub, item, qty);
        if (hub < node->hubName) node->left = insert(node->left, hub, item, qty);
        else if (hub > node->hubName) node->right = insert(node->right, hub, item, qty);
        else {
            if (node->itemName == item) {
                node->quantity += qty;
                cout << "Updated order for " << hub
                     << " (" << node->itemName
                     << " now " << node->quantity << " units)\n";
            } else {
                cout << "Hub " << hub
                     << " already ordered a different item (" << node->itemName
                     << "). New item not added to this same node.\n";
            }
        }
        return node;
    }

    void inorder(OrderNode* n) {
        if (!n) return;
        inorder(n->left);

        // print row
        cout << left << setw(20) << n->hubName
             << setw(20) << n->itemName
             << setw(10) << n->quantity << '\n';

        inorder(n->right);
    }

public:
    OrderBST() : root(nullptr) {}

    void addOrder(const string& hub, const string& item, int qty) {
        root = insert(root, hub, item, qty);
        cout << "Order added: " << hub << " " << qty << " " << item << '\n';
    }

    void displayOrders() {
        if (!root) {
            cout << "No orders placed yet.\n";
            return;
        }

        cout << "\n================= Orders by Hubs (BST) =================\n";
        cout << left << setw(20) << "Hub"
             << setw(20) << "Item"
             << setw(10) << "Quantity" << '\n';
        cout << string(50, '-') << '\n';

        inorder(root);

        cout << "========================================================\n";
    }
};

#endif // BINARY_SEARCH_TREES_H_INCLUDED

