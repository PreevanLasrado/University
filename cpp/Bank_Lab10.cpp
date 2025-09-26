#include<iostream>
#include<string>
using namespace std;

class Person {
protected:
    int person_id; 
    string person_fname;
    string person_lname;
    string person_phone;  
    string person_address;

public:
    Person() {
        person_id = 0;
        person_fname = "Default";
        person_lname = "Person";
        person_phone = "0000000000";
        person_address = "Unknown";
    }

    Person(int id, string fname, string lname, string phone, string address) {
        person_id = id;
        person_fname = fname;
        person_lname = lname;
        person_phone = phone;
        person_address = address;
    }

    void addPersonDetails() {
        do {
            cout << "Enter 4-digit ID: ";
            cin >> person_id;
            if (person_id<1000 || person_id>9999) {
                cout << "Invalid ID. Please enter a 4-digit number.\n";
            }
        } while (person_id<1000 || person_id>9999);
        cin.ignore();
        cout << "Enter First Name: ";
        getline(cin, person_fname);
        cout << "Enter Last Name: ";
        getline(cin, person_lname);
        cout << "Enter Phone Number: ";
        getline(cin, person_phone);
        cout << "Enter Address: ";
        getline(cin, person_address);
    }
    
    void displayPerson() {
        cout << "ID : " << person_id << endl;
        cout << "Name : " << person_fname << " " << person_lname << endl;
        cout << "Phone : " << person_phone << endl;
        cout << "Address : " << person_address << endl;
    }

    int getID() { 
        return person_id; 
    }
};

class Customer : public Person {
private:
    string customer_account_type; 
    float customer_balance;
    int customer_pin_code;
 
    static int total_customers; 

public:
    Customer() : Person() { 
        customer_account_type = "Savings";
        customer_balance = 0.0;
        customer_pin_code = 0000;
    }

    Customer(int id, string fname, string lname, string phone, string address, string acc_type, float balance, int pin) 
        : Person(id, fname, lname, phone, address) {
        customer_account_type = acc_type;
        customer_balance = balance;
        customer_pin_code = pin;
        total_customers++;
    }

    Customer(const Customer &c) : Person(c) {
        customer_account_type = c.customer_account_type;
        customer_balance = c.customer_balance;
        customer_pin_code = c.customer_pin_code;
        total_customers++;
    }

    void addCustomer() {
        cout << "--- Adding Person Details ---\n";
        addPersonDetails();
        cout << "--- Adding Customer-Specific Details ---\n";
        do {
            cout << "Enter Account Type (Savings/Current/Fixed Deposit): ";
            getline(cin,customer_account_type);
            if (customer_account_type!="Savings" && customer_account_type!="Current" && customer_account_type!="Fixed Deposit") {
                cout << "Invalid account type. Please try again.\n";
            }
        } while (customer_account_type!="Savings" && customer_account_type!="Current" && customer_account_type!="Fixed Deposit");
        cout << "Enter Balance: ";
        cin >> customer_balance;
        do {
            cout << "Enter 4-digit PIN Code: ";
            cin >> customer_pin_code;
            if (customer_pin_code<1000 || customer_pin_code>9999) {
                cout << "Invalid PIN. Please enter a 4-digit number.\n";
            }
        } while (customer_pin_code<1000 || customer_pin_code>9999);
        cin.ignore();
        cout << "Customer data added successfully!\n"; 
        total_customers++;
    }

    void updateCustomer() {
        int choice;
        do {
            cout << "\nUpdate Menu:\n";
            cout << "1. First Name\n2. Last Name\n3. Account Type\n4. Balance\n5. Phone\n6. Address\n7. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore(); 
            switch (choice) {
                case 1: 
                    cout << "New First Name: "; 
                    getline(cin, person_fname); break; 
                case 2: cout << "New Last Name: "; getline(cin, person_lname); break; 
                case 3:
                    do {
                        cout << "Enter Account Type (Savings/Current/Fixed Deposit): ";
                        getline(cin,customer_account_type);
                        if (customer_account_type!="Savings" && customer_account_type!="Current" && customer_account_type!="Fixed Deposit") {
                            cout << "Invalid account type. Please try again.\n";
                        }
                    } while (customer_account_type!="Savings" && customer_account_type!="Current" && customer_account_type!="Fixed Deposit");
                    break;
                case 4: cout << "New Balance: "; cin >> customer_balance; cin.ignore(); break;
                case 5: cout << "New Phone: "; getline(cin, person_phone); break;
                case 6: cout << "New Address: "; getline(cin, person_address); break; 
                case 7: cout << "Exiting update menu...\n"; break;
                default: cout << "Invalid choice!\n";
            }
        } while (choice!=7);
    }

    int CustomerID() {
        return person_id; 
    }

    void depositCustomer(int amount) {
        if (amount > 0) {
            customer_balance += amount;
            cout << "Deposited (int): " << amount << endl;
            cout << "New Balance: " << customer_balance << endl;
        } 
        else {
            cout << "Invalid deposit amount!\n";
        }
    }

    void depositCustomer(double amount) {
        if (amount > 0) {
            customer_balance += amount;
            cout << "Deposited (double): " << amount << endl;
            cout << "New Balance: " << customer_balance << endl;
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }
    
    static void showTotalCustomers() { 
        cout << "Total Customers: " << total_customers << endl;
    }

    friend void displayCustomer(Customer c);

    bool operator!() {
        return customer_balance == 0;
    }

    void operator-() {
        customer_balance = -customer_balance;
        cout << "Balance converted to overdraft: " << customer_balance << endl;
    }

    void operator-(Customer &receiver) {
        double amount;
        cout << "Enter amount to transfer: ";
        cin >> amount;

        if (amount > 0 && amount <= customer_balance) {
            customer_balance -= amount;
            receiver.customer_balance += amount; 
            cout << "Transfer successful!\n";
        } 
        else {
            cout << "Transfer failed!\n";
        }
    }

    bool operator>(Customer &c) {
        return customer_balance > c.customer_balance;
    }

    bool operator<(Customer &c) {
        return customer_balance < c.customer_balance;
    }
};

int Customer::total_customers = 0; 

void displayCustomer(Customer c) {
    cout << "--- Customer Details ---\n";
    c.displayPerson(); 
    cout << "Account Type : " << c.customer_account_type << endl;
    cout << "Balance : " << c.customer_balance << endl;
    cout << "PIN Code : " << c.customer_pin_code << endl;
}

class Employee : public Person {
protected: 
    string employee_position;
    float employee_salary;
    static int total_employees; 

public:
    Employee() : Person() {
        employee_position = "Clerk";
        employee_salary = 0.0;
    }

    Employee(int id, string fname, string lname, string phone, string address, 
             string position, float salary) 
        : Person(id, fname, lname, phone, address) {
        employee_position = position;
        employee_salary = salary;
        total_employees++;
    }

    Employee(const Employee &e) : Person(e) {
        employee_position = e.employee_position;
        employee_salary = e.employee_salary;
        total_employees++;
    }

    void addEmployee() {
        cout << "--- Adding Person Details ---\n";
        addPersonDetails();
        cout << "--- Adding Employee-Specific Details ---\n";
        do {
            cout << "Enter Position (Clerk/Officer): ";
            getline(cin,employee_position);
            if (employee_position!="Clerk" && employee_position!="Officer") {
                cout << "Invalid position. Please try again.\n";
            }
        } while (employee_position!="Clerk" && employee_position!="Officer");
        
        cout << "Enter Salary: ";
        cin >> employee_salary;
        cin.ignore();
        
        cout << "Employee data added successfully!\n";
        total_employees++;
    }

    void updateEmployees() {
        int choice;
        do {
            cout << "\nUpdate Menu:\n";
            cout << "1. First Name\n2. Last Name\n3. Position\n4. Salary\n5. Phone\n6. Address\n7. Exit\n";
            cout << "Enter your choice: "; 
            cin >> choice;
            cin.ignore();
            switch (choice) {
                case 1: cout << "New First Name: "; getline(cin, person_fname); break;
                case 2: cout << "New Last Name: "; getline(cin, person_lname); break;
                case 3: 
                    do {
                        cout << "Enter Position (Clerk/Officer): ";
                        getline(cin, employee_position);
                        if (employee_position!="Clerk" && employee_position!="Officer") {
                            cout << "Invalid position. Please try again.\n";
                        }
                    } while (employee_position!="Clerk" && employee_position!="Officer");
                    break;
                case 4: cout << "New Salary: "; cin >> employee_salary; cin.ignore(); break;
                case 5: cout << "New Phone: "; getline(cin, person_phone); break;
                case 6: cout << "New Address: "; getline(cin, person_address); break;
                case 7: cout << "Exiting update menu...\n"; break;
                default: cout << "Invalid choice!\n";
            }
        } while (choice!=7);
    }

    int EmployeeID() {
        return person_id; 
    }

    static void showTotalEmployees() { 
        cout << "Total Employees (including Managers): " << total_employees << endl;
    }

    friend void displayEmployee(Employee e);

    void operator~() {
        if (employee_position == "Clerk") employee_position = "Officer";
        else if (employee_position == "Officer") employee_position = "Clerk";
        cout << "Position changed to: " << employee_position << endl;
    }

    void operator+() {
        employee_salary += 5000;
        cout << "Bonus of 5000 added. New Salary: " << employee_salary << endl;
    }
};

int Employee::total_employees = 0;

void displayEmployee(Employee e) {
    cout << "--- Employee Details ---\n";
    e.displayPerson(); 
    cout << "Position : " << e.employee_position << endl;
    cout << "Salary : " << e.employee_salary << endl;
}

class Manager : public Employee {
private:
    string department;
    int team_size;
    static int total_managers; 

public:
    Manager() : Employee() {
        employee_position = "Manager"; 
        department = "General";
        team_size = 0;
    }

    Manager(int id, string fname, string lname, string phone, string address, float salary, string dept, int t_size)
        : Employee(id, fname, lname, phone, address, "Manager", salary) {
        department = dept;
        team_size = t_size;
        total_managers++;
    }

    Manager(const Manager &m) : Employee(m) { 
        department = m.department;
        team_size = m.team_size;
        total_managers++;
    }

    void addManager() {
        cout << "--- Adding Person Details for Manager ---\n";
        addPersonDetails(); 
        cout << "--- Adding Manager-Specific Details ---\n";
        
        employee_position = "Manager";
        
        cout << "Enter Salary: ";
        cin >> employee_salary;
        cin.ignore();
        
        cout << "Enter Department: ";
        getline(cin, department);
        
        cout << "Enter Team Size: ";
        cin >> team_size;
        cin.ignore();
        
        cout << "Manager data added successfully!\n";
        total_employees++; 
        total_managers++;  
    }

    void updateManager() {
        int choice;
        do {
            cout << "\nUpdate Manager Menu:\n";
            cout << "1. First Name\n2. Last Name\n3. Salary\n4. Phone\n5. Address\n6. Department\n7. Team Size\n8. Exit\n";
            cout << "Enter your choice: "; 
            cin >> choice;
            cin.ignore();
            switch (choice) {
                case 1: cout << "New First Name: "; getline(cin, person_fname); break;
                case 2: cout << "New Last Name: "; getline(cin, person_lname); break;
                case 3: cout << "New Salary: "; cin >> employee_salary; cin.ignore(); break;
                case 4: cout << "New Phone: "; getline(cin, person_phone); break;
                case 5: cout << "New Address: "; getline(cin, person_address); break;
                case 6: cout << "New Department: "; getline(cin, department); break;
                case 7: cout << "New Team Size: "; cin >> team_size; cin.ignore(); break;
                case 8: cout << "Exiting update menu...\n"; break;
                default: cout << "Invalid choice!\n";
            }
        } while (choice != 8);
    }

    static void showTotalManagers() { 
        cout << "Total Managers: " << total_managers << endl;
    }

    friend void displayManager(Manager m);
};

int Manager::total_managers = 0;

void displayManager(Manager m) {
    cout << "--- Manager Details ---\n";
    m.displayPerson();
    cout << "Position : " << m.employee_position << endl; 
    cout << "Salary : " << m.employee_salary << endl;   
    cout << "Department : " << m.department << endl;   
    cout << "Team Size : " << m.team_size << endl;     
}

int main() {
    cout << "--- Constructor Demonstration ---\n";

    Customer c_default;
    cout << "\nDefault Customer Constructor\n";
    displayCustomer(c_default);

    Customer c_param(1234, "John", "Doe", "9876543210", "New York", "Current", 5000.0, 4321);
    cout << "\nParameterized Customer Constructor\n";
    displayCustomer(c_param);

    Customer c_copy(c_param);
    cout << "\nCopy Customer Constructor\n";
    displayCustomer(c_copy);

    Employee e_default;
    cout << "\nDefault Employee Constructor\n";
    displayEmployee(e_default);

    Employee e_param(1111, "Alice", "Smith", "1112223333", "Chicago", "Clerk", 75000.0);
    cout << "\nParameterized Employee Constructor\n";
    displayEmployee(e_param);

    Manager m_param(2222, "Bob", "Brown", "4445556666", "Boston", 120000.0, "IT", 10);
    cout << "\nParameterized Manager Constructor\n";
    displayManager(m_param);

    cout << "\n--- End of Constructor Demo ---\n";

    int choice, i;
    bool found;
    Customer customer[100]; 
    int customer_count = 0; 
    Employee employee[100];
    int employee_count = 0;
    Manager manager[100];  
    int manager_count = 0;
 
    do {
        cout << "\nBank Management System\n";
        cout << "1. Add Customer\n";
        cout << "2. Add Employee (Clerk/Officer)\n";
        cout << "3. Add Manager\n"; 
        cout << "4. Display Customers\n";
        cout << "5. Display Employees\n";
        cout << "6. Display Managers\n"; 
        cout << "7. Update Customer Data\n";
        cout << "8. Update Employee Data\n";
        cout << "9. Update Manager Data\n"; 
        cout << "10. Deposit Amount\n";
        cout << "11. Show Total Customers & Employees\n";
        cout << "12. Unary Operator Demo\n";
        cout << "13. Transfer Funds\n";
        cout << "14. Compare Customer Balances\n";
        cout << "15. Exit\n"; 
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                if (customer_count<100) {
                    customer[customer_count].addCustomer();
                    customer_count++;
                } else {
                    cout << "Customer limit reached!\n";
                }
                break;
            case 2:
                if (employee_count<100) {
                    employee[employee_count].addEmployee();
                    employee_count++;
                } else {
                    cout << "Employee limit reached!\n";
                }
                break;
            case 3:
                if (manager_count<100) {
                    manager[manager_count].addManager();
                    manager_count++;
                } else {
                    cout << "Manager limit reached!\n";
                }
                break;
            case 4: 
                if (customer_count==0) {
                    cout << "Invalid: No customers data to display.\n";
                } else {
                    for (i=0;i<customer_count;i++) {
                        cout << "\nCustomer " << i+1 << ":\n";
                        displayCustomer(customer[i]);
                    }
                }
                break;
            case 5:
                if (employee_count==0) {
                    cout << "Invalid: No employee data to display.\n";
                } else {
                    for (i=0;i<employee_count;i++) {
                        cout << "\nEmployee " << i+1 << ":\n";
                        displayEmployee(employee[i]);
                    }
                }
                break;
            case 6:
                if (manager_count==0) {
                    cout << "Invalid: No manager data to display.\n";
                } else {
                    for (i=0;i<manager_count;i++) {
                        cout << "\nManager " << i+1 << ":\n";
                        displayManager(manager[i]);
                    }
                }
                break;
            case 7: 
                int search_cusid;
                cout << "Enter Customer ID to update the data: ";
                cin >> search_cusid;
                found = false;
                for (i=0; i<customer_count; i++) {
                    if (customer[i].CustomerID() == search_cusid) {
                        cout << "\nCustomer Found:\n";
                        displayCustomer(customer[i]);
                        customer[i].updateCustomer();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Customer ID not found.\n";
                }
                break;
            case 8:
                int search_empid;
                cout << "Enter Employee ID to update the data: ";
                cin >> search_empid;
                found = false;
                for (i=0; i<employee_count; i++) {
                    if (employee[i].EmployeeID() == search_empid) {
                        cout << "\nEmployee Found:\n";
                        displayEmployee(employee[i]);
                        employee[i].updateEmployees();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Employee ID not found.\n";
                }
                break;
            case 9:
                int search_manid;
                cout << "Enter Manager ID to update the data: ";
                cin >> search_manid;
                found = false;
                for (i=0; i<manager_count; i++) {
                    if (manager[i].getID() == search_manid) { 
                        cout << "\nManager Found:\n";
                        displayManager(manager[i]);
                        manager[i].updateManager(); 
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Manager ID not found.\n";
                }
                break;
            case 10:
                int deposit_id;
                cout << "Enter Customer ID to deposit amount: ";
                cin >> deposit_id;
                found = false;
                for (i=0; i<customer_count; i++) {
                    if (customer[i].CustomerID() == deposit_id) {
                        cout << "Enter amount to deposit: ";
                        double amount;
                        cin >> amount;
                        if (amount==int(amount)) {
                            customer[i].depositCustomer(int(amount));
                        }
                        else {
                            customer[i].depositCustomer(amount);
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Customer ID not found.\n";
                }
                break; 
            case 11: 
                Customer::showTotalCustomers();
                Employee::showTotalEmployees(); 
                Manager::showTotalManagers();  
                break;
            case 12:
                cout << "\n--- Unary Operator Demo ---\n";
                if (customer_count > 0) {
                    cout << "\nTesting Customer Operators (on ID " << customer[0].CustomerID() << "):\n";
                    if (!customer[0]) {
                        cout << "Customer has ZERO balance!\n";
                    } else {
                        cout << "Customer has some balance.\n";
                    }
                    -customer[0]; 
                } else {
                    cout << "No customer available to test.\n";
                }
                if (employee_count > 0) {
                    cout << "\nTesting Employee Operators (on ID " << employee[0].EmployeeID() << "):\n";
                    ~employee[0]; 
                    +employee[0]; 
                } else {
                    cout << "No non-manager employee available to test.\n";
                }
                if (manager_count > 0) {
                    cout << "\nTesting Manager Operators (on ID " << manager[0].getID() << "):\n";
                    ~manager[0];
                    +manager[0]; 
                } else {
                    cout << "No manager available to test.\n";
                }
                break;
            case 13:
                if (customer_count < 2) {
                    cout << "Need at least 2 customers for transfer.\n";
                } 
                else {
                    int id1, id2;
                    cout << "Enter Sender Customer ID: "; cin >> id1;
                    cout << "Enter Receiver Customer ID: "; cin >> id2;
                    if (id1 == id2) {
                        cout << "Sender and receiver cannot be the same.\n";
                        break;
                    }
                    int senderIndex = -1, receiverIndex = -1;
                    for (i = 0; i < customer_count; i++) {
                        if (customer[i].CustomerID() == id1) senderIndex = i;
                        if (customer[i].CustomerID() == id2) receiverIndex = i;
                    }
                    if (senderIndex != -1 && receiverIndex != -1) {
                        customer[senderIndex] - customer[receiverIndex];
                    } else {
                        cout << "One or both Customer IDs not found.\n";
                    }
                }
                break;
            case 14: 
                if (customer_count < 2) {
                    cout << "Need at least 2 customers for comparison.\n";
                } 
                else {
                    int id1, id2;
                    cout << "Enter first Customer ID: "; cin >> id1;
                    cout << "Enter second Customer ID: "; cin >> id2;
                    int index1 = -1, index2 = -1;
                    for (i = 0; i < customer_count; i++) {
                        if (customer[i].CustomerID() == id1) index1 = i;
                        if (customer[i].CustomerID() == id2) index2 = i;
                    }
                    if (index1 != -1 && index2 != -1) {
                        if (customer[index1] > customer[index2]) {
                            cout << "Customer " << customer[index1].CustomerID() << " has more balance.\n";
                        } 
                        else if (customer[index1] < customer[index2]) {
                            cout << "Customer " << customer[index2].CustomerID() << " has more balance.\n";
                        } 
                        else {
                            cout << "Both customers have equal balance.\n";
                        }
                    } else {
                        cout << "One or both Customer IDs not found.\n";
                    }
                }
                break;
            case 15:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while(choice != 15);

    return 0;
}

