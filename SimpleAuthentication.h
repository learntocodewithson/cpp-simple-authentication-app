#ifndef SIMPLEAUTHENTICATION_H
#define SIMPLEAUTHENTICATION_H

#include<iostream>
#include<string>
#include <sstream>
#include <fstream>
using namespace std;

class SimpleAuthentication {
 string email, password, confirm_password; // private atts

 public:
  SimpleAuthentication(string _email, string _password, string _confirm_password){
   email = _email;
   password = _password;
   confirm_password = _confirm_password;
  }

  SimpleAuthentication(string _email, string _password){
   email = _email;
   password = _password;
  }

  void create(){
    ofstream Users("users.csv");
    Users << email << "," << password;
    Users.close();
  }

  bool login(){
    string data, _email, _password;
    bool found = 0;
    ifstream Users("users.csv");
    
    while (getline(Users, data)) {
      istringstream ss(data);
     
      getline(ss, _email, ',');
      getline(ss, _password);

      if(email == _email && password == _password){
        cout << "Login successfully";
        found = 1;
        break;
      }
    }
    Users.close();

    if(found == 0){
      cout << "Incorrect password";
    }

    return found;
  }

  // getter
  string getEmail(){
   return email;
  }

  string getPassword(){
   return password;
  }

  string getConfirmPassword(){
   return confirm_password;
  }

  bool confirmPasswordMatch(){
   return password == confirm_password;
  }

};
#endif
