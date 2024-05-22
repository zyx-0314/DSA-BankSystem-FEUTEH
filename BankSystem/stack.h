#pragma once

#include <iostream>

class stack
{
public:
	void AddUserInformation();
	void CheckUserList(std::string);
	void DeactivateUser();

private:
	struct UserInformation;
	struct NodeUserInformation;

	NodeUserInformation* tailActive = NULL;
	NodeUserInformation* tailDeactive = NULL;

	UserInformation SetUserInformation();
	void CheckUsernameList();
	void TransferNode(NodeUserInformation*);
};

