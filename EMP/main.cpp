#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

// Function to generate employee number
std::string generateEmployeeNumber(const std::string& firstName, const std::string& phoneNumber) {
    return firstName + phoneNumber.substr(phoneNumber.length() - 4);
}

// Function to generate password
std::string generatePassword(const std::string& phoneNumber) {
    return phoneNumber.substr(phoneNumber.length() - 4);
}

int main() {
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt = nullptr;
    sql::ResultSet* res = nullptr; // Initialize res to nullptr

    // Connect to the database
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("localhost", "root", ""); // Replace with your database credentials
    con->setSchema("Empmanagement"); // Replace with your database name

    char choice;
    std::string name, email, phoneNumber, firstName, employeeNumber, password;

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
    else if (choice == 'l') {
        // Implement login logic here
        std::string empID, inputPassword;
        std::cout << "Enter your employee number: ";
        std::cin >> empID;
        std::cout << "Enter your password: ";
        std::cin >> inputPassword;

        // Check if the employee number and password match
        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * FROM employee WHERE Emp_ID = '" + empID + "' AND Password = '" + inputPassword + "'");
        if (res->next()) {

            std::cout << "Login successful!" << std::endl;
        }
        else {
            std::cout << "Login failed. Invalid credentials." << std::endl;
        }
    }
    else {
        std::cout << "Invalid choice. Please try again." << std::endl;
    }

    // Clean up
    delete res;
    delete stmt;
    delete con;

    return 0;
}
