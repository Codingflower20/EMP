#include <iostream>
#include<mysql.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <mysqld_error.h>
#include <sstream>
#include <C:\Program Files\MySQL\Connector C++ 1.1\include\cppconn\driver.h>
using namespace std;
void createEmployee() {
    string emp_ID;
    string Name;
    string Department;
    int age;
    string Position;
    string mail_ID;
    int Phone;
    int LeavesL;
    int DOJ, hrs;
    double wph, hra, da, bonus, nps, inf, ins, sav, gross, tax, net, in;
    cout << "Enter Employee Id:\t";
    cin >> emp_ID;
    cout << "Enter Employee Name:\t";
    cin >> Name;
    cout << "Enter Employee Department:\t";
    cin >> Department;
    cout << "Enter Employee age:\t";
    cin >> age;
    cout << "Enter Employee Position:\t";
    cin >> Position;
    cout << "Enter Employee mail:\t";
    cin >> mail_ID;
    phonein:cout << "Enter Employee Phone Number:\t";
    cin >> Phone;
    if (Phone.length()< 10||Phone.length()>10) {
        cout << "Invalid Phone\n";
       goto phonein;
    }
    cout << "Enter the number of leaves left:\t";
    cin >> LeavesL;
    dojin:cout << "Enter Employee's date of joining:\t";
    cin >> DOJ;
    cout << "Enter Employee's working hours :\t";
    cin >> hrs;
    cout << "Enter Employee's wages per hour:\t";
    cin >> wph;
    cout << "Enter Employee's Housing and rental allowance:\t";
    cin >> hra;
    cout << "Enter Employee's dearness allowance:\t";
    cin >> da;
    cout << "Enter Employee's contribution to nps:\t";
    cin >> nps;
    cout << "Enter Employee's general insurance premium:\t";
    cin >> ins;
    cout << "Enter Employee's savings(max-50000):\t";
    cin >> sav;
    cout << "Enter rate of inflation:\t";
    cin >> inf;
    if (LeavesL < 5)
        LeavesL = 0;
    bonus = wph * inf + LeavesL * 5000;
    in = (wph * hrs) + hra + da + bonus;
    double ded = nps + ins + sav;
    gross = in - ded;
    if (gross <= 300000)
        tax = 0;
    else if (gross <= 500000)
        tax = gross * 0.05;
    else if (gross <= 750000)
        tax = gross * 0.10;
    else if (gross <= 1000000)
        tax = gross * 0.15;
    else
        tax = gross * 0.2;
    net = gross - tax;
    cout << "Gross Salary\tTax\tNet Salary\n";
    cout << gross << "\t" << tax << "\t" << net << endl;
    MYSQL* conn;
    MYSQL_RES* result;
    MYSQL_ROW row;

    const char* server = "localhost";
    const char* user = "root";
    const char* password = "";
    const char* database = "empmanagement";

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        cerr << "Error connecting to database: " << mysql_error(conn) << endl;
    }
    string insert = "INSERT INTO employee (`Emp_ID`, `Name`, `Department`, `Age`, `Position`, `Mail_ID`, `Phone`, `LeavesL`, `DOJ`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)";

    MYSQL_STMT* stmt = mysql_stmt_init(conn);
    if (!stmt) {
        cerr << "Error creating prepared statement: " << mysql_stmt_error(stmt) << endl;
        mysql_close(conn);
    }

    MYSQL_BIND bind[9]; // Array to bind variables to placeholders

    // Bind values to placeholders using appropriate data types
    memset(bind, 0, sizeof(bind));

    bind[0].buffer_type = MYSQL_TYPE_LONG;
    bind[0].buffer = (void*)&emp_ID;
    bind[0].buffer_length = sizeof(emp_ID);

    bind[1].buffer_type = MYSQL_TYPE_STRING;
    bind[1].buffer = (void*)Name.c_str();
    bind[1].buffer_length = Name.length();

    bind[2].buffer_type = MYSQL_TYPE_STRING;
    bind[2].buffer = (void*)Department.c_str();
    bind[2].buffer_length = Department.length();

    bind[3].buffer_type = MYSQL_TYPE_LONG;
    bind[3].buffer = (void*)&age;
    bind[3].buffer_length = sizeof(age);

    bind[4].buffer_type = MYSQL_TYPE_STRING;
    bind[4].buffer = (void*)Position.c_str();
    bind[4].buffer_length = Position.length();

    bind[5].buffer_type = MYSQL_TYPE_STRING;
    bind[5].buffer = (void*)mail_ID.c_str();
    bind[5].buffer_length = mail_ID.length();

    bind[6].buffer_type = MYSQL_TYPE_STRING;
    bind[6].buffer = (void*)&Phone;
    bind[6].buffer_length = sizeof(Phone);

    bind[7].buffer_type = MYSQL_TYPE_LONG;
    bind[7].buffer = (void*)&LeavesL;
    bind[7].buffer_length = sizeof(LeavesL);

    bind[8].buffer_type = MYSQL_TYPE_STRING;
    bind[8].buffer = (void*)&DOJ;
    bind[8].buffer_length = sizeof(DOJ);

    if (mysql_stmt_bind_param(stmt, bind)) {
        cerr << "Error binding parameters: " << mysql_stmt_error(stmt) << endl;
        mysql_stmt_close(stmt);
        mysql_close(conn);
    }
}

int main() {
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt = nullptr;
    sql::ResultSet* res = nullptr; // Initialize res to nullptr

    // Connect to the database
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("localhost", "root", ""); 
    con->setSchema("Empmanagement");  
    std::string us, password;

    /*std::cout << "Do you want to sign up (s) or log in (l)? ";
    std::cin >> choice;

    if (choice == 's') {
        std::cout << "Enter your name: ";
        std::cin >> name;
        std::cout << "Enter your email: ";
        std::cin >> email;
        std::cout << "Enter your phone number: ";
        std::cin >> phoneNumber;

        // Generate employee number and password
        firstName = name.substr(0, name.find(' '));
        employeeNumber = generateEmployeeNumber(firstName, phoneNumber);
        password = generatePassword(phoneNumber);

        // Insert user information into the database
        stmt = con->createStatement();
        stmt->execute("INSERT INTO employee (Name, Email, Phone, Emp_ID, Password) VALUES ('" + name + "', '" + email + "', '" + phoneNumber + "', '" + employeeNumber + "', '" + password + "')");

        std::cout << "Your employee number is: " << employeeNumber << std::endl;
        std::cout << "Your password is: " << password << std::endl;
   }*/
    cout << "Enter User name:\t";
    cin >> us;
    cout << "Enter password:\t";
    cin >> password;

        if (us=="admin"&&password=="admin123") {

            std::cout << "Login successful!" << std::endl;
            char c;
           choice: cout << "Enter \n C for adding new employee\n R for reading employee data\n U for updating employee data D to delete empolyee from database:\t";
            switch (c)
            {
            case 'C':   createEmployee(); break;
            //case 'R':   readEmployee(); break;
            //case 'U':   updateEmployee(); break;
            //case 'D':   deleteEmployee(); break;
            default:
                cout << "Wrong choice try again\n";
                goto choice;
                break;
            }
        }
        else {
            std::cout << "Login failed. Invalid credentials." << std::endl;
        }
        return 0;
    }
