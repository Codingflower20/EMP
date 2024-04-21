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
using namespace  sql;
using namespace std;
class employee {
    //DataMembers
    string emp_ID;
    string Name;
    string Department;
    int age=0;
    string Position;
    string mail_ID;
    string Phone;
    int LeavesL=0;
    int DOJ=0;
public:
    employee() {
        emp_ID="";
        Name="";
        Department="";
        age = 0;
        Position="";
        mail_ID="";
        Phone="";
        LeavesL = 0;
         DOJ = 0;
    }
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
        case 4:return nps;
        case 5:return inf;
        case 6:return ins;
        case 7:return sav;
        case 8:return gross;
        case 9:return tax;
        case 10:return net;
        case 11: return in;
        case 12:return hrs;
        default:return 0;
        }
    }
};
void updateEmp(employee& e, Salary& s) {
    char ch;
    string u, user = e.getData('a'), insertemp;
    int wph=s.getData(1), LeavesL=stoi(e.getData('H'));
    double tax=s.getData(9), gross=s.getData(8), net=s.getData(10), hra=s.getData(2), da=s.getData(3), nps=s.getData(4), ins=s.getData(6), bonus, inf = 5 , in, sav=s.getData(7), hrs=s.getData(12);
    MYSQL* conn; conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "root", "", "empmanagement", 3306, NULL, 0)) {
        cout << "Error: " << mysql_error(conn) << endl;
    }
    else {
        cout << "UPDATE" << endl;
    }
    cout << "Enter the field to be updated:\nA)Position\nB)Email\nC)Phone\nD)Department\nE)wage per hour\nF)Housing and Rental allowance\nG)Dearness allowance\nH)contribution to nps\nI)General Insurance Premium\nJ)Savings\n";
    cin >> ch;
    if (ch >= 'A' || ch <= 'D') {
        switch (ch)
        {
        case'A':
            cout << "Enter The New Position:\t";
            cin >> u;
            
             insertemp = "UPDATE employee SET Position = '"+u+"' WHERE Emp_ID= '"+user+"' ";
            if (mysql_query(conn, insertemp.c_str())) {
                cout << "Error: " << mysql_error(conn) << endl;
            }
            else {
                cout << "Updated Successfuly!" << endl;
            } 
            break;
        case'B':
            cout << "Enter The New Email Id:\t";
            cin >> u;

            insertemp = "UPDATE employee SET Mail_ID = '" + u + "' WHERE Emp_ID= '" + user + "' ";
            if (mysql_query(conn, insertemp.c_str())) {
                cout << "Error: " << mysql_error(conn) << endl;
            }
            else {
                cout << "Updated Successfuly!" << endl;
            }
            break;
        case'C':
            cout << "Enter The New Phone Number:\t";
            cin >> u;

            insertemp = "UPDATE employee SET Phone = '" + u + "' WHERE Emp_ID= '" + user + "' ";
            if (mysql_query(conn, insertemp.c_str())) {
                cout << "Error: " << mysql_error(conn) << endl;
            }
            else {
                cout << "Updated Successfuly!" << endl;
            }
            break;
        case'D':
            cout << "Enter The New Department:\t";
            cin >> u;

            insertemp = "UPDATE employee SET Department = '" + u + "' WHERE Emp_ID= '" + user + "' ";
            if (mysql_query(conn, insertemp.c_str())) {
                cout << "Error: " << mysql_error(conn) << endl;
            }
            else {
                cout << "Updated Successfuly!" << endl;
            }
            break;

        }
    }
    else if (ch >= 'E' || ch <= 'J') {
        switch (ch) {
        case'E':cout << "Enter The New Wages Per Hour:\t";
            cin >> u;
            wph = stod(u);
            insertemp = "UPDATE salary SET wph = " + u + "WHERE Emp_ID= '" + user + "' ";
            if (mysql_query(conn, insertemp.c_str())) {
                cout << "Error: " << mysql_error(conn) << endl;
            }
            else {
                cout << "Updated Successfuly!" << endl;
            }
            break;
        case'F':
            cout << "Enter The New House and rental Allowance:\t";
            cin >> u;
            hra = stod(u);
            insertemp = "UPDATE salary SET hra = " + u + " WHERE Emp_ID= '" + user + "' ";
            if (mysql_query(conn, insertemp.c_str())) {
                cout << "Error: " << mysql_error(conn) << endl;
            }
            else {
                cout << "Updated Successfuly!" << endl;
            }
            break;
        case'G':
            cout << "Enter The Dearness Allowance:\t";
            cin >> u;
            da = stod(u);
            insertemp = "UPDATE salary SET da = " + u + "WHERE Emp_ID= '" + user + "' ";
            if (mysql_query(conn, insertemp.c_str())) {
                cout << "Error: " << mysql_error(conn) << endl;
            }
            else {
                cout << "Updated Successfuly!" << endl;
            }
            break;
        case'H':
            cout << "Enter The New Contribution To Nps:\t";
            cin >> u;
            nps = stod(u);
            insertemp = "UPDATE salary SET nps = " + u + " WHERE Emp_ID= '" + user + "' ";
            if (mysql_query(conn, insertemp.c_str())) {
                cout << "Error: " << mysql_error(conn) << endl;
            }
            else {
                cout << "Updated Successfuly!" << endl;
            }
            break;
        case'I':
            cout << "Enter The New General Insurance Premium:\t";
            cin >> u;
            ins = stod(u);
            insertemp = "UPDATE salary SET ins = " + u + " WHERE Emp_ID= '" + user + "' ";
            if (mysql_query(conn, insertemp.c_str())) {
                cout << "Error: " << mysql_error(conn) << endl;
            }
            else {
                cout << "Updated Successfuly!" << endl;
            }
            break;
        case'J':
            cout << "Enter The New Savings:\t";
            cin >> u;
            sav== stod(u);
            insertemp = "UPDATE salary SET sav = " +u + "WHERE Emp_ID = '" + user + "' ";
            if (mysql_query(conn, insertemp.c_str())) {
                cout << "Error: " << mysql_error(conn) << endl;
            }
            else {
                cout << "Updated Successfuly!" << endl;
            }
            break;
        }

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
        insertemp = "DELETE FROM salary WHERE `salary`.`emp_ID` = '"+user+"'";
        if (mysql_query(conn, insertemp.c_str())) {
            cout << "Error: " << mysql_error(conn) << endl;
        }
        else {
            cout << "Updating other fields!" << endl;
        }
        string insertsal = "INSERT INTO `salary`(`emp_ID`, `wph`, `hra`, `da`, `bonus`, `nps`, `ins`, `sav`, `gross`, `tax`, `net`) VALUES (";
        insertsal += "'" + user + "',";
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
            cout << "UpatedSuccessfuly!" << endl;
        }

    }
}
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
void show(employee& e, Salary& s) {
    cout << "HI\n";
    cout << "Name:\t" << e.getData('b') << endl;
    cout << "Employee ID:\t" << e.getData('a') << endl;
    cout << "Department:\t" << e.getData('c') << endl;
    cout << "Age:\t" << e.getData('d') << endl;
    cout << "Position:\t" << e.getData('e') << endl;
    cout << "Mail Id:\t" << e.getData('f') << endl;
    cout << "Phone Number:\t" << e.getData('g') << endl;
    cout << "Leaves Left:\t" << e.getData('h') << endl;
    cout << "Date Of Joining:\t" << e.getData('i') << endl;
    cout << "Wages per Hour:\t" << s.getData(1) << endl;
    cout << "Housing and Rental Allowance:\t" << s.getData(2) << endl;
    cout << "Dearness Allowance:\t" << s.getData(3) << endl;
    //cout << "Total Income:\t" << s.getData(11) << endl;
    cout << "Contribution To NPS:\t" << s.getData(4) << endl;
   // cout << ":\t" << s.getData(5);
    cout << "general insurance premium:\t" << s.getData(6) << endl;
    cout << "Savings:\t" << s.getData(7) << endl;
    cout << "Gross Salary:\t" << s.getData(8) << endl;
    cout << "Tax:\t" << s.getData(9) << endl;
    cout << "Net Salary:\t" << s.getData(10) << endl;
    
}
void readEmployee(char update) {
    
    employee e;
    Salary s;
    string emp_ID;
    int logCounter = 0;
    double wph=0.0, hra=0, da=0, bonus=0, nps=0, inf=0, ins=0, sav=0, gross=0, tax=0, net=0, in=0;
    int hrs=0;
    cout << "Enter the Employee ID:\t";
    cin >> emp_ID;
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::ResultSet* res;
    // Connect to the database
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("localhost", "root", "");
    con->setSchema("Empmanagement");
    // Execute a query to retrieve all data from the 'users' table
    stmt = con->createStatement();
    res = stmt->executeQuery("SELECT * FROM employee WHERE Emp_ID='" + emp_ID + "'");
    // Iterate over the result set and print the data
    while (res->next()) {
        //cout << "Hi\n";
        e.setData(emp_ID, res->getString("Name"), res->getString("Department"), res->getInt("age"), res->getString("Position"), res->getString("mail_ID"), res->getString("Phone"), res->getInt("LeavesL"), res->getInt("DOJ"));
        //std::cout << "Login successful!" << std::endl;
        logCounter++;
    }
    
    res = stmt->executeQuery("SELECT * FROM salary WHERE emp_ID='" + emp_ID + "'");
    // Iterate over the result set and print the data
    while (res->next()) {
            wph= res->getDouble("wph");
            hra= res->getDouble("hra");
            da= res->getDouble("da");
            bonus= res->getDouble("bonus");
            nps= res->getDouble("nps");
            //inf= res->getDouble("inf");
            ins= res->getDouble("ins");
            sav= res->getDouble("sav");
            gross= res->getDouble("gross");
            tax= res->getDouble("tax");
            net= res->getDouble("net");
           // in= res->getDouble("in");
            hrs = res->getInt("hrs");
    }
    if (logCounter < 0) {
        std::cout << "No such employee exists " << std::endl;
        exit(0);
    }
    
    s.setData(hrs, wph, hra, da, bonus, nps, inf, ins, sav, gross, tax, net, in);
    show(e, s);
    
    if (update == 'Y') {
        updateEmp(e, s);
    }
    if (update == 'D') {
        cout << "DELETING EMPLYOEE:\t" << emp_ID << endl;

        MYSQL* conn; conn = mysql_init(NULL);
        if (!mysql_real_connect(conn, "localhost", "root", "", "empmanagement", 3306, NULL, 0)) {
            cout << "Error: " << mysql_error(conn) << endl;
        }
        else {
            cout << "logged in Databsse" << endl;
        }
        string insert = "DELETE FROM employee WHERE `employee`.`Emp_ID` ='" + emp_ID + "' ";
        if (mysql_query(conn, insert.c_str())) {
            cout << "Error: " << mysql_error(conn) << endl;
        }
        else {
            cout << "Data deleted Successfuly!" << endl;
        }
         insert = "DELETE FROM salary WHERE `salary`.`Emp_ID` ='" + emp_ID + "' ";
        if (mysql_query(conn, insert.c_str())) {
            cout << "Error: " << mysql_error(conn) << endl;
        }
        else {
            cout << "Data deleted Successfuly!" << endl;
        }

    }
    delete res;
    delete stmt;
    delete con;
}
int main() {
    
    std::string us, password;

    cout << "Enter User name:\t";
    cin >> us;
    cout << "Enter password:\t";
    cin >> password;

    if (us == "admin" && password == "admin123") {

       std::cout << "Login successful!" << std::endl;
        char c;
    choice: cout << "Enter \n C for adding new employee\n R for reading employee data\n U for updating employee data\n D to delete empolyee from database\n E to exit\t";
        cin >> c;
        switch (c)
        {
            case 'C':   createEmployee(); 
                        goto choice;
                        break;
            case 'R':   readEmployee('n'); 
                        goto choice;
                        break;
            case 'U':   readEmployee('Y'); 
                        goto choice;
                        break;
            case 'D':   readEmployee('D'); 
                         goto choice;
                         break;
             case 'E': break;
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
