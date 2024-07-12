#include "user.h"

User::User() {}

void User::setUsername(string username)
{
    this->username = username;
}

void User::setPassword(string password){
    this->password = password;
}

void User::setEmail(string email){
    this->email = email;
}
