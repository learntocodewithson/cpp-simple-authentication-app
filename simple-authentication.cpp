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

int main(){
  string email, password, confirm_password;

  // cout << "Registration" << endl;
  // cout << "Enter your email: ";
  // cin >> email;
  
  // cout << "Enter your password: ";
  // cin >> password;

  // cout << "Confirm your password: ";
  // cin >> confirm_password;
  
  // SimpleAuthentication user_account(email, password, confirm_password);

  // if(user_account.confirmPasswordMatch()){
  //   user_account.create();
  //   cout << "Create account successfully.";
  // } else {
  //   cout << "Password didn't match.";
  // }

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
  // if(login.getEmail() == user_account.getEmail() && login.getPassword() == user_account.getPassword()){
  //  cout << "Login successfully";
  //  break;
  // }else {
  //  cout << "Incorrect password";
  //  if(i == 4){
  //   cout << endl << "You've reached 5 attempts. Please try again after 5mins.";
  //  }
  // }
 }

 return 0;
}
