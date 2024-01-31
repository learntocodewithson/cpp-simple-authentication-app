/*
Simple Authentication App
- Login & registration

Input fields: email & password
Attempts: 5 ( error message: ma block for 5 mins)

Registration:
 - email  - password - confirmation password

Login
 - email - password

Technical requirements:  - OOP - Loop ( login scenario )

hii! Pano po ba yung register system? Yung simple lang c++ language. Using class &object and For loop. Tapos mag 5 attempts siya
*/

#include "SimpleAuthentication.h"

void login(){
  string email, password;

  for(int i = 0; i < 5; i++){
    cout << endl;
    cout << endl << "Login" << endl;
    cout << "Enter your email: ";
    cin >> email;
    
    cout << "Enter your password: ";
    cin >> password;

    SimpleAuthentication login_user(email, password);
    if(login_user.login()){
      break;
    }else{
    if(i == 4){
      cout << endl << "You've reached 5 attempts. Please try again after 5mins.";
    }
    }
  }
}

void signup(){
  string email, password, confirm_password;

  cout << endl << "Registration" << endl;
  cout << "Enter your email: ";
  cin >> email;
  
  cout << "Enter your password: ";
  cin >> password;

  cout << "Confirm your password: ";
  cin >> confirm_password;
  
  SimpleAuthentication user_account(email, password, confirm_password);

  if(user_account.confirmPasswordMatch()){
    user_account.create();
  } else {
    cout << "Password didn't match.";
  }
}

int main(){
  int choice;

  do {
    cout << "Login or Register" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter the number: ";
    cin >> choice;

    switch(choice){
      case 1:
        login();
        break;
      case 2:
        signup();
        break;
      case 3:
        cout << endl << "Thank you for using this app. Good bye.";
        break;
      default:
        cout << endl << "Please choose from 1 to 2 only." << endl;
    }
  } while(choice != 1 && choice != 2 && choice != 3);

 return 0;
}
