#include "Element.h"
#include "User.h"
#include <iostream>
using namespace std;

User::User()
{
	id = 0;
}
User::User(unsigned long int idUser)
{
	this->id = idUser;
}

Element *User::clone()
{
	return new User(id);
}

ostream &User::print(ostream &output)
{
	output << id << " ";
	return output;
}

istream &User::read(istream &input)
{
	input >> id;
	return input;
}

int User::operator==(Element *other)
{
	User *otherUser = dynamic_cast<User *>(other);
	return otherUser && id == otherUser->id;
}

int User::operator!=(Element *other)
{
	return !((*this) == other);
}

int User::operator<(Element *other)
{
	User *otherUser = dynamic_cast<User *>(other);
	return otherUser && this->id < otherUser->id;
}
