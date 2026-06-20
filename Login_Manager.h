#ifndef LOGIN_MANAGER_H_INCLUDED
#define LOGIN_MANAGER_H_INCLUDED
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cctype>
#include<windows.h>
#include "Doubly_Linked_List.h"
#include "Arrays_PartB.h"
#include "Binary_Search_Trees.h"


using namespace std;

HANDLE ConsoleColour = GetStdHandle(STD_OUTPUT_HANDLE);
// ---------------- Login Manager ----------------
class LoginManager {
private:
    string username;
    string password;
    string role;

public:
    bool runLogin = false;

    string getRole() const { return role; }

    void login() {
        cout << "=== Login ===\nUsername: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (username == "admin" && password == "admin123") {
            role = "admin";
            runLogin = true;
            cout << "Login successful. Welcome, Admin!" << endl;
            return;
        }

        if ((username == "m1@capetown" && password == "pass1") ||
            (username == "m2@bloemfontein" && password == "pass2") ||
            (username == "m3@johannesburg" && password == "pass3") ||
            (username == "m4@kimberley" && password == "pass4") ||
            (username == "m5@mahikeng" && password == "pass5")||
            (username == "m6@bisho" && password == "pass6")||
            (username == "m7@pietermaritzburg " && password == "pass7")||
            (username == "m8@polokwane" && password == "pass8")||
            (username == "m9@mbombela" && password == "pass9"))
        {
            role = "manager";
            runLogin = true;
            cout << "Login insuccessful. Welcome, Manager!" << endl;
            return;
        }
        SetConsoleTextAttribute(ConsoleColour, 11);
        cout << "Invalid credentials! Try again.\n" << endl;
        SetConsoleTextAttribute(ConsoleColour, 7);
        role = "guest";
        runLogin = false;
    }
};



#endif // LOGIN_MANAGER_H_INCLUDED
