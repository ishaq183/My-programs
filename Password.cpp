#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

string getpassword(int length){
   string password="";
   string characters=
       "aquickbrownfoxjumpoverthelezydogABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890@#$_&-+(\)/\"%";
  
   int charSize=characters.size();
   srand(time(0));
  
   for(int i=0 ; i<length ; i++){
      int randomIndex=rand()%charSize;
      password=password+characters[randomIndex];
    }
    return password;
}


int main(){
    char choice;
    do{
        int length;
        cout << "Enter the length of Password: ";
        cin >> length;
        string password=getpassword(length);
        cout << "Password is " <<password<< endl;
        cout << "\nCan you run program again(Y/N): " << endl;
        cin >> choice;
    }while(choice=='y'||choice=='Y');
    cout << "Thank you" << endl;
    return 0;
}
