#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include<unistd.h>
using namespace std;

#define MAX 100  //Max

class Book{
    string title, author, genre, ISBN;
    bool isAvailable = true;
    string borrowedBy;
public:
    void setBookDetails(const string &title, const string &author, const string &genre, const string &ISBN) {
        this->title = title;
        this->author = author;
        this->genre = genre;
        this->ISBN = ISBN;
        isAvailable = true;
        borrowedBy = "";
    }
    string getTitle() const {
        return title;
    }
};
class Member{
    fstream file;
    string id,name,CNIC,address,contact;
public:
    void setMemberDetails(string &id,string &name,string &CNIC, string &address, string &contact) {
        this->id=id;
        this->name=name;
        this->CNIC=CNIC;
        this->address=address;
        this->contact=contact;
    }
    string getID() const {
        return id;
    }
    string getName() const {
        return name;
    }
};
class Staff{
    string id,name,CNIC,address,contact,role;
public:
    void setStaffDetails(string &id,string &name,string &CNIC, string &address, string &contact,string &role) {
        this->id=id;
        this->name=name;
        this->CNIC=CNIC;
        this->address=address;
        this->contact=contact;
        this->role=role;
    }
    string getID() const {
        return id;
    }
    string getName() const {
        return name;
    }
};
class LibraryManagementSystem{
    fstream file;
    Member members[MAX];
    Staff staffs[MAX];
    Book books[MAX];
    int memberCount = 0, staffCount=0, bookCount = 0;
    string id,name,CNIC, address, contact,role,title, author, genre, ISBN;
public:
    void MemberDetail(){
        file.open("Members.txt", ios::in);
        if (!file.is_open()) {
            cout << "Error: Member file does not exist.\n";
            return;
        }
        while (getline(file, id, '*') && getline(file, name, '*') &&
               getline(file, CNIC, '*') && getline(file, address, '*') &&
               getline(file, contact)) {
            cout << "ID: " << id << "\nName: " << name 
                 << "\nCNIC: " << CNIC << "\nAddress: " << address
                 << "\nContact: " << contact << endl<<endl;
        }
        file.close();
        cout << "\n" << endl;
    }
    void StaffDetail(){
        file.open("Staffs.txt", ios::in);
        if (!file.is_open()) {
            cout << "Error: Staff file does not exist.\n";
            return;
        }
        while (getline(file, id, '*') && getline(file, name, '*') &&
               getline(file, CNIC, '*') && getline(file, address, '*') &&
               getline(file, contact, '*') && getline(file, role)) {
            cout << "ID: " << id << "\nName: " << name 
                 << "\nRole: " << role << "\nCNIC: " << CNIC
                 << "\nAddress: " << address << "\nContact: " << contact << endl<<endl;
        }
        file.close();
        cout << "\n" << endl;
    }
    void BookDetail() {
        file.open("Books.txt", ios::in);
        if (!file.is_open()) {
            cout << "Error: Book file does not exist.\n";
            return;
        }
        while (getline(file, title, '*') && getline(file, author, '*') &&
               getline(file, genre, '*') && getline(file, ISBN)) {
            cout << "Title: " << title << "\nAuthor: " << author 
                 << "\nGenre: " << genre << "\nISBN: " << ISBN << endl<<endl;
                 
        }
        file.close();
        cout << "\n" << endl;
    }
    void addMember(){
        Member &member = members[memberCount++];
        cin.ignore();
        cout << "Enter Member ID: ";
        getline(cin,id);
        cout << "Enter Member Name: ";
        getline(cin, name);
        cout << "Enter Member CNIC: ";
        getline(cin,CNIC);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Contact: ";
        getline(cin, contact);
        member.setMemberDetails(id, name,CNIC, address, contact);

        //Creat a Member file
        file.open("Members.txt",ios::out | ios::app);
        if(!file.is_open()) {
            cout << "Member File Not Exist." << endl;
            return;
        }
        file<<id<<'*'<<name<<'*'<<address <<'*'<<contact<<'*'<<CNIC<<endl;
        file.close();
        cout << "Member added successfully with ID: " << id << endl;
    }
    void removeMember() {
        string search_id;
        cout << "Enter the ID of Member to Remove: ";
        cin>>search_id;

        fstream tampfile;

        bool found=false;
        file.open("Members.txt",ios::in);
        tampfile.open("temp.txt",ios::out);
        if(!file.is_open()) {
            cout << "Unable to access Member File." << endl;
        }
        while(getline(file, id, '*')&&
                getline(file, name, '*')&&
                getline(file, CNIC, '*')&&
                getline(file, address, '*')&&
                getline(file, contact)) {

            if(id!=search_id) {
                tampfile<<id<<"*"<<name<<"*"<<CNIC<<"*"<<address<<"*"<<contact<<endl;
            } else {
                found=true;
            }
        }
        file.close();
        tampfile.close();

        remove("Members.txt");
        rename("tamp.txt","Members.txt");
        if(found) {
            cout << "Member Remove Successfully." << endl;
        }
        else {
            cout << "Member with ID "<<id<<"not found." << endl;
        }
    }
    void addStaff() {
        Staff & staff = staffs[staffCount++];
        cin.ignore();
        cout << "Enter Candidate ID: ";
        getline(cin,id);
        cout << "Enter Name of Candidate: ";
        getline(cin, name);
        cout << "Enter Candidate CNIC: ";
        getline(cin,CNIC);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Contact: ";
        getline(cin, contact);
        cout << "Enter Role: ";
        getline(cin,role);
        staff.setStaffDetails(id, name,CNIC, address, contact,role);
        fstream file;
        file.open("Staffs.txt",ios::out | ios::app);
        if(!file.is_open()) {
            cout << "Staff File Not Exist." << endl;
            return;
        }
        file<<id<<"*"<<name<<"*"<<CNIC<<"*"<<address<<"*"<<contact<<"*"<<role<<endl;
        file.close();
        cout << "Staff added successfully with ID: " << id << endl;
    }
    void removeStaff() {
        string search_id;
        cout << "Enter the ID of Staff for removing" << endl;
        cin >> search_id;

        fstream tampfile;
        bool found=false;
        file.open("Staffs.txt",ios::in);
        tampfile.open("temp.txt",ios::out);
        if(!file.is_open()) {
            cout << "Unable to access Staff File." << endl;
        }
        while(getline(file,id,'*')&&getline(file,name,'*')&&getline(file,CNIC,'*')&&getline(file,address,'*')&&getline(file,contact,'*')&&getline(file,role) ) {

            if(id!=search_id) {
                tampfile<<id<<"*"<<name<<"*"<<CNIC<<"*"<<address<<"*"<<contact<<"*"<<role<<endl;
            } else {
                found=true;
            }
        }
        file.close();
        tampfile.close();

        remove("Staffs.txt");
        rename("tamp.txt","Staffs.txt");
        if(found) {
            cout << "Staff Remove Successfully." << endl;
        }
        else {
            cout << "Staff with ID "<<search_id<<"not found." << endl;
        }
    }
    void addBook() {
        Book &book = books[bookCount++];
        string title, author, genre, ISBN;
        cin.ignore();
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
        cout << "Enter Genre: ";
        getline(cin, genre);
        cout << "Enter ISBN: ";
        getline(cin, ISBN);
        book.setBookDetails(title, author, genre, ISBN);
        file.open("Books.txt",ios::out | ios::app);
        if(!file.is_open()) {
            cout << "Books File Not Exist." << endl;
            return;
        }
        file<<title<<"*"<<author<<"*"<<genre<<"*"<<ISBN<<endl;
        file.close();
        cout << "Book added successfully.\n";
    }
    void removeBook() {
        string search_title;
        cout << "Enter the Title of Book to Remove: ";
        cin>>search_title;

        fstream tampfile;

        bool found=false;
        file.open("Books.txt",ios::in);
        tampfile.open("temp.txt",ios::out);
        if(!file.is_open()) {
            cout << "Unable to access Books File." << endl;
        }
        while(getline(file,title, '*')&&
                getline(file, author, '*')&&
                getline(file, genre, '*')&&
                getline(file, ISBN)) {

            if(title!=search_title) {
                tampfile<<title<<"*"<<author<<"*"<<genre<<"*"<<ISBN<<"*"<<endl;
            } else {
                found=true;
            }
        }
        file.close();
        tampfile.close();

        remove("Books.txt");
        rename("tamp.txt","Book.txt");
        if(found) {
            cout << "Member Remove Successfully." << endl;
        }
        else {
            cout << "Member with ID "<<id<<"not found." << endl;
        }
    }
    void showDetails()  {
        cout << "\nMembers:\n";
        MemberDetail();
        cout << "\nStaff:\n";
        StaffDetail();
        cout << "\nBooks:\n";
        BookDetail();
    }
};
int main() {
    LibraryManagementSystem library;
    int choice;

    do {
        //  system("clear");
        cout << "Library Management System Menu:\n"<<endl;
        cout << "1. Member\n";
        cout << "2. Staff" << endl;
        cout << "3. Book\n";
        cout << "4. Show Library Details\n";
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            int choice1;
            system("clear");
            cout << "Members Menu\n" << endl;
            cout << "1. Add Member\n";
            cout << "2. Remove Member\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice1;
            switch(choice1) {
            case 1:
                library.addMember();
                break;
            case 2:
                library.removeMember();
                break;
            case 0:
                break;
            default:
                cout << "You enter wrong option\n";
            }
            break;
        case 2:
            int choice2;
            system("clear");
            cout << "Staff Menu\n" << endl;
            cout << "1. Add Staff\n";
            cout << "2. Remove Staff\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice2;
            switch(choice2) {
            case 1:
                library.addStaff();
                break;
            case 2:
                library.removeStaff();
                break;
            case 3:
                break;
            default:
                cout << "You enter wrong option\n";
            }
            break;
        case 3:
            int choice3;
            system ("clear");
            cout << "Book Menu\n" << endl;
            cout << "1. Add Book\n";
            cout << "2. Remove Book\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice3;
            switch(choice3) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.removeBook();
                break;
            case 3:
                break;
            default:
                cout << "You enter wrong option\n";
            }
            break;
        case 4:
            system ("clear");
            library.showDetails();
            break;
        case 0:
            break;
        default:
            cout << "You enter wrong option." << endl;
        }
    } while(choice!=0);
    return 0;
}