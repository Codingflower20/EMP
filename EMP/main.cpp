#include <iostream>
#include<mysql.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <mysqld_error.h>
#include <sstream>
#include<string>
#include <C:\Program Files\MySQL\Connector C++ 1.1\include\cppconn\driver.h>
using namespace std;
class employee {
    //DataMembers
    string emp_ID;
    string Name;
    string Department;
    int age;
    string Position;
    string mail_ID;
    string Phone;
    int LeavesL;
    int DOJ;
public:
    employee() {}
    void setData(string emp_IDc,string Namec,string Departmentc, int agec,string Positionc,string mail_IDc,string Phonec,int LeavesLc,int DOJc) {
        Name = Namec;
        Phone = Phonec;
        mail_ID = mail_IDc;
        emp_ID=emp_IDc ;
        Department = Departmentc;
        age =agec;
        Position = Positionc;
        LeavesL = LeavesLc;
        DOJ = DOJc;
       
    }
    string getData(char ch) {
        switch (ch) {
        case 'b':return Name;
        case 'a':return emp_ID;
        case 'c':return Department;
        case 'd':return to_string(age);
        case 'e':return Position;
        case 'f':return mail_ID;
        case 'g':return Phone;
        case 'h':return to_string(LeavesL);
        case 'i':return to_string(DOJ);
        default:return "-1";
        }
    }
};
class Salary {
    double wph, hra, da, bonus, nps, inf, ins, sav, gross, tax, net, in;
    int hrs;
public:
    Salary(){
        wph = 0; hra = 0; da = 0;  bonus = 0; nps = 0; inf = 0; ins = 0; sav = 0; gross = 0; tax = 0; net = 0; in = 0;
        hrs = 0;
    }
    void setData(int hrsc, double wphc, double hrac, double dac, double bonusc, double npsc, double infc, double  insc, double savc, double grossc, double taxc, double netc, double inc) {
        hrs = hrsc;
        wph = wphc;
        hra = hrac;
        da = dac;
        nps = npsc;
        inf = infc;
        ins = insc;
        sav = savc;
        gross = grossc;
        tax = taxc;
        net = netc;
        in = inc;
    }
    double getData(int ch) {
        switch (ch) {
        case 1:return wph;
        case 2:return hra;
        case 3:return da;
        default:return 0;
        }
    }
};
void createEmployee() {
    string emp_ID;
    string Name;
    string Department;
    int age;
    string Position;
    string mail_ID;
    string Phone;
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
    if (Phone.length() < 10 || Phone.length() > 10) {
        cout << "Invalid Phone\n";
        goto phonein;
    }
    cout << "Enter the number of leaves left:\t";
    cin >> LeavesL;
dojin:cout << "Enter Employee's date of joining:\t";
    cin >> DOJ;
    string doj = to_string(DOJ);
    if (doj.length() != 6) {
        cout << "Invalid Date Of Joining\n";
        goto dojin;
    }
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

    MYSQL* conn; conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "root", "", "empmanagement", 3306, NULL, 0)) {
        cout << "Error: " << mysql_error(conn) << endl;
    }
    else {
        cout << "logged in Databsse" << endl;
    }
    string insertemp = "INSERT INTO `employee`(`Emp_ID`, `Name`, `Department`, `Age`, `Position`, `Mail_ID`, `Phone`, `LeavesL`, `DOJ`) VALUES (";
    insertemp += "'" + emp_ID + "',";
    insertemp += "'" + Name + "',";
    insertemp += "'" + Department + "',";
    insertemp += to_string(age) + ",";
    insertemp += "'" + Position + "',";
    insertemp += "'" + mail_ID + "',";
    insertemp += "'" + Phone + "',";
    insertemp += to_string(LeavesL) + ",";
    insertemp += to_string(DOJ) + ");";
    //string insert = "INSERT INTO users (Name, Phone, Email, User_ID, Passkey) VALUES ('" + Name + "',"< Phone1 >",'" + Email + "','" + User_ID + "','" + Passkey + "')";
    if (mysql_query(conn, insertemp.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    }
    else {
        cout << "Inserted Successfuly!" << endl;
    }
    string insertsal = "INSERT INTO `salary`(`emp_ID`, `wph`, `hra`, `da`, `bonus`, `nps`, `ins`, `sav`, `gross`, `tax`, `net`) VALUES (";
    insertsal += "'" + emp_ID + "',";
    insertsal += to_string(wph) + ",";
    insertsal += to_string(hra) + ",";
    insertsal += to_string(da) + ",";
    insertsal += to_string(bonus) + ",";
    insertsal += to_string(nps) + ",";
    insertsal += to_string(ins) + ",";
    insertsal += to_string(sav) + ",";
    insertsal += to_string(gross) + ",";
    insertsal += to_string(tax) + ",";
    insertsal += to_string(net) + ",";
    insertsal += to_string(hrs) + ");";
    if (mysql_query(conn, insertsal.c_str())) {
        cout << "Error: " << mysql_error(conn) << endl;
    }
    else {
        cout << "Inserted Successfuly!" << endl;
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

    if (us == "admin" && password == "admin123") {

        std::cout << "Login successful!" << std::endl;
        char c;
    choice: cout << "Enter \n C for adding new employee\n R for reading employee data\n U for updating employee data\n D to delete empolyee from database:\t";
        cin >> c;
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
