/*
    Using Stack create a bank system with this following features:
    - Manage Money
    - Store History Transactions
    - Manage User Information
    - User Type Admin & User
*/

#include <iostream>
#include "stack.h"

void MainMenuUser(int&);
void MainMenuAdmin(int&);
bool LoginMenu();

int main()
{
    stack Stack;
    int choice;

    if (LoginMenu())
    {
        do
        {
            MainMenuAdmin(choice);
            switch (choice)
            {
            case 1:
                Stack.AddUserInformation();
                break;
            case 2:
                Stack.CheckUserList("active");
                break;
            case 3:
                Stack.DeactivateUser();
                break;
            case 4:
                Stack.CheckUserList("deactive");
                break;
            case 0:
                exit(0);
                break;
            default:
                break;
            }
        } while (true);
    }

}

void MainMenuUser(int& choice) {
    std::cout
        << "-- Welcome to Bank: Username Here --\n"
        << "1. Deposit\n"
        << "2. Withdraw\n"
        << "3. Balance\n"
        << "4. Transaction History\n"
        << ":: ";
    std::cin >> choice;
}

void MainMenuAdmin(int& choice) {
    std::cout
        << "-- Bank System --\n"
        << "1. Add a User\n"
        << "2. User Active List\n"
        << "3. Deactivate a User\n"
        << "4. User Deactive List\n"
        << "0. Exit\n"
        << ":: ";
    std::cin >> choice;

    system("cls");
}

bool LoginMenu() {
    std::string user, password;

    std::cout << "User: ";
    std::cin >> user;
    std::cout << "Password: ";
    std::cin >> password;

    system("cls");

    if ("admin" == user && "admin" == password)
    {
        return true;
    }
    else {
        return false;
    }
}