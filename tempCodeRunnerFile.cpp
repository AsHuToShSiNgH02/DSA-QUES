#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
protected:
    string name;
    string address;
    string phone_no;
public:
    void accept() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter address: ";
        cin >> address;
        cout << "Enter phone number: ";
        cin >> phone_no;
    }
};

class Employee : public Person {
protected:
    int eno;
    string ename;
public:
    void accept() {
        Person::accept();
        cout << "Enter employee number: ";
        cin >> eno;
        cout << "Enter employee name: ";
        cin >> ename;
    }
};

class Manager : public Employee {
private:
    string designation;
    string department_name;
    double basic_salary;
public:
    void accept() {
        Employee::accept();
        cout << "Enter designation: ";
        cin >> designation;
        cout << "Enter department name: ";
        cin >> department_name;
        cout << "Enter basic salary: ";
        cin >> basic_salary;
    }
    double get_salary() const {
        return basic_salary;
    }
};

int main() {
    int choice, n;
    vector<Manager> managers;
    while (true) {
        cout << "Menu" << endl;
        cout << "1. Add new manager" << endl;
        cout << "2. Display manager with highest salary" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter details of manager:" << endl;
                Manager new_manager;
                new_manager.accept();
                managers.push_back(new_manager);
                break;
            case 2:
                if (managers.empty()) {
                    cout << "No managers added yet!" << endl;
                } else {
                    Manager highest_salary_manager = managers[0];
                    for (int i = 1; i < managers.size(); i++) {
                        if (managers[i].get_salary() > highest_salary_manager.get_salary()) {
                            highest_salary_manager = managers[i];
                        }
                    }
                    cout << "Manager with the highest salary is:" << endl;
                    cout << "Name: " << highest_salary_manager.name << endl;
                    cout << "Employee Number: " << highest_salary_manager.eno << endl;
                    cout << "Designation: " << highest_salary_manager.designation << endl;
                    cout << "Department Name: " << highest_salary_manager.department_name << endl;
                    cout << "Salary: " << highest_salary_manager.get_salary() << endl;
                }
                break;
            case 3:
                cout << "Exiting program!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter a valid choice." << endl;
        }
    }
}
