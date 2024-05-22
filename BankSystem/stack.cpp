#include "stack.h"

struct stack::UserInformation {
	std::string fName = "", lName = "", userName = "", password = "";
	float balance = 0;
};

struct stack::NodeUserInformation {
	NodeUserInformation* next;
	UserInformation userInformation;
};

void stack::AddUserInformation() {
	NodeUserInformation* temp;
	temp = new NodeUserInformation;

	if (tailActive) {
		temp->next = tailActive;
	}
	else {
		temp->next = NULL;
	}
	temp->userInformation = SetUserInformation();

	tailActive = temp;
	std::cout << "Success!\n";
	system("pause");
	system("cls");
}

stack::UserInformation stack::SetUserInformation() {
	UserInformation temp;

	std::cout << "First Name: ";
	std::cin >> temp.fName;

	std::cout << "Last Name: ";
	std::cin >> temp.lName;

	std::cout << "User Name: ";
	std::cin >> temp.userName;

	std::cout << "Password: ";
	std::cin >> temp.password;

	system("cls");

	return temp;
}

void stack::CheckUserList(std::string state) {
	int number = 1;
	NodeUserInformation* tail = state == "active" ? tailActive : tailDeactive;
	NodeUserInformation* currNode = tail;

	if (tail)
	{
		std::cout << "This is the current clients\n";
		do
		{
			std::cout << number << ". " << currNode->userInformation.fName << " " << currNode->userInformation.lName << "\n";

			if (currNode->next == NULL)
				break;

			currNode = currNode->next;
			number++;
		} while (true);
	}
	else
	{
		std::cout << "No Clients\n";
	}

	system("pause");
	system("cls");
}

void stack::DeactivateUser() {
	NodeUserInformation* currNode = tailActive,* prevNode = NULL;
	std::string whoToDeactivate;

	CheckUsernameList();

	std::cout << "Who to deactivate: ";
	std::cin >> whoToDeactivate;

	if (tailActive)
	{
		do
		{
			if (whoToDeactivate == currNode->userInformation.userName)
			{

				if (NULL != prevNode)
				{
					prevNode->next = currNode->next;
				}

				if (tailActive == currNode)
				{
					tailActive = currNode->next;
				}

				TransferNode(currNode);

				std::cout << "User Deactivated!\n";
				system("pause");
				system("cls");

				return;
			}

			if (currNode->next == NULL)
				break;

			prevNode = currNode;
			currNode = currNode->next;
		} while (true);
	}
	else
	{
		std::cout << "No Clients\n";
	}

	std::cout << "User Can't be Found!\n";

	system("pause");
	system("cls");
}

void stack::CheckUsernameList() {
	int number = 1;
	NodeUserInformation* currNode = tailActive;

	if (tailActive)
	{
		std::cout << "This is the current clients usernames\n";
		do
		{
			std::cout << number << ". " << currNode->userInformation.userName << "\n";

			if (currNode->next == NULL)
				break;

			currNode = currNode->next;
			number++;
		} while (true);
	}
	else
	{
		std::cout << "No Clients\n";
	}
}

void stack::TransferNode(NodeUserInformation* tobeTransfered) {
	if (tailDeactive) {
		tobeTransfered->next = tailDeactive;

		tailDeactive = tobeTransfered;
	}
	else {
		tailDeactive = tobeTransfered;
		tailDeactive->next = NULL;
	}
}