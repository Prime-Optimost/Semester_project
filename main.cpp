#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <iomanip>
using namespace std;

// Defines the Student structure
struct Student {
    string fullname;
    int hostel_number;
    string telephone_number;
    string program;
    string level;
    int age;
    string index_number;
    string id;
    float gpa;
};

// Function to print text in green color style
void printGreenText(string text) {
    cout << "\033[1;32m" << text << "\033[0m" << endl;
}

// Function to save student details to the database, As in a text document
void saveStudentDetails(Student student) {
    ofstream database("database.txt", ios::app);
    // Write student details to the database file (text document)
    database << student.fullname <<"," 
	         << student.hostel_number <<","
	         << student.telephone_number <<","
             << student.program <<"," 
			 << student.level<<"," 
			 << student.age  <<"," ;
	database << student.index_number <<","
			 << student.id <<","
             << student.gpa << endl;
    database.close();
    printGreenText("Student details saved successfully!");
}

// This function helps  to display all student details
void displayStudentDetails() {
    ifstream database("database.txt");
    string line;
    printGreenText("Student Details:");
    // Display header like in a table form
    cout << "------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << left << setw(20) << "Full Name" << setw(10) << "Hostel #" << setw(15) << "Telephone #" << setw(30)
         << "Program" << setw(20) << "Level" << setw(5) << "Age" << setw(15) << "Index #" << setw(5) << "ID # " << setw(5) << " GPA" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    // Loop through each line in the database and display student details
    while (getline(database, line)) {
        // ... Extract and display student details
        string fullname, telephone_number, program, level, index_number,id;
        int hostel_number, age;
        float gpa;
        stringstream ss(line);
        getline(ss, fullname, ',');
        ss >> hostel_number;
        ss.ignore(1);
        getline(ss, telephone_number, ',');
        getline(ss, program, ',');
        getline(ss, level, ',');
        ss >> age;
        ss.ignore(1);
        getline(ss, index_number, ',');
        getline(ss,id,',');
        ss >> gpa;
        cout << left << setw(20) << fullname << setw(10) << hostel_number << setw(15) << telephone_number << setw(30)
             << program << setw(20) << level << setw(5) << age << setw(15) << index_number << setw(5) << id << setw(5) << gpa << endl;
    }
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    database.close();
}


int main() {
    string admin_password = "admin123";
    string password_attempt;
    
    // Display main system header
    printGreenText("=====================Student Database Management System=================");
    printGreenText("             ================ Project work 2 ===============           ");
    
    // Authenticate the administrator
    while (true) {
         printGreenText("Enter administrator password:");
        cin >> password_attempt;
        
        if (password_attempt == admin_password) {
            break;
        } 
        else {
            printGreenText("Invalid password! Try again.");
        }
    }
    system("cls");
    
    // Display menu and handle user options
    while (true) {
        cout << "  ==========Select an option============  " << endl;
        cout << "1. Add Student Details" << endl;
        cout << "2. Display Student Details" << endl;
        cout << "0. Exit" << endl;
        
        int option;
        cin >> option;
        system("cls");
        // Prompts user for student details and saves them
        switch (option) {
            case 1: {
                Student student; 
                cout << "Enter ID :"<<endl;
                cin.ignore();
                getline(cin,student.id);
                system("cls");
                
                cout<<"Enter student details:"<<endl;
                cout << "Full Name: "<< endl;
                cin.ignore();
                getline(cin, student.fullname);
                system("cls");
                
                cout<<"Enter student details:"<<endl;
                cout << "Hostel #: "<< endl;
                cin >> student.hostel_number;
                system("cls");
                
                cout<<"Enter student details:"<<endl;
                cout << "Telephone #: "<< endl;
                cin.ignore();
                getline(cin, student.telephone_number);
                system("cls");
                
                cout<<"Enter student details:"<<endl;
                cout << "Program: "<< endl;
                getline(cin, student.program);
                system("cls");
                
                cout<<"Enter student details:"<<endl;
                cout << "Level: "<< endl;
                getline(cin, student.level);
                system("cls");
            
                cout<<"Enter student details:"<<endl;
                cout << "Age: "<< endl;
                cin >> student.age;
                system("cls");
                
                cout<<"Enter student details:"<<endl;
                cout << "Index #: "<< endl;
                cin.ignore();
                getline(cin, student.index_number);
                system("cls");
                
                cout<<"Enter student details:"<<endl;
                cout << "GPA: "<< endl;
                cin >> student.gpa;
                saveStudentDetails(student);
				break;
            }
            system("cls");
            
            // Displays all the students details
            case 2: {
            displayStudentDetails();
            break;
            }
            
            case 0: {
                cout << "Existing the Student Database Management System!";
                return 0;
            }
            default: {
                cout << "Invalid option! Please select again.";
                break;
            }
        }
    }

}
