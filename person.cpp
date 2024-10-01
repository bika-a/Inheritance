#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int age;
    std::string address;

public:
    Person(const std::string& n, int a, const std::string& addr) : name(n), age(a), address(addr) {}

    // Setter function to set person details
    void setDetails(const std::string& n, int a, const std::string& addr) {
        name = n;
        age = a;
        address = addr;
    }

    void display() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Address: " << address << std::endl;
    }
};

class Student : public Person {
private:
    int student_id;
    std::string college_name;
    int marks[5];
    float percentage;

public:
    Student(const std::string& n, int a, const std::string& addr, int id, const std::string& college)
        : Person(n, a, addr), student_id(id), college_name(college) {}

    // Setter function to set student details
    void setStudentDetails(int id, const std::string& college) {
        student_id = id;
        college_name = college;
    }

    void setMarks(const int m[]) {
        for (int i = 0; i < 5; ++i)
            marks[i] = m[i];
    }

    // Calculate total marks and percentage
    void showResult() {
        int total = 0;
        for (int i = 0; i < 5; ++i)
            total += marks[i];
        
        percentage = static_cast<float>(total) / 5;

        std::cout << "Total Marks: " << total << std::endl;
        std::cout << "Percentage: " << percentage << "%" << std::endl;

        if (percentage >= 75)
            std::cout << "Class: Distinction" << std::endl;
        else if (percentage >= 60)
            std::cout << "Class: First" << std::endl;
        else if (percentage >= 50)
            std::cout << "Class: Second" << std::endl;
        else
            std::cout << "Class: Pass" << std::endl;
    }
};

class Employee : public Person {
private:
    int emp_id;
    std::string qualification;
    float basic_salary;

public:
    Employee(const std::string& n, int a, const std::string& addr, int id, const std::string& qual, float salary)
        : Person(n, a, addr), emp_id(id), qualification(qual), basic_salary(salary) {}

    // Setter function to set employee details
    void setEmployeeDetails(int id, const std::string& qual, float salary) {
        emp_id = id;
        qualification = qual;
        basic_salary = salary;
    }

    // Calculate Net Salary
    float calculateNetSalary() {
        float da = 1.6 * basic_salary;
        float hra = 0.1 * basic_salary;
        float ta = 500;
        float income_tax = (basic_salary > 50000) ? (0.05 * basic_salary) : 0;
        float net_salary = (basic_salary + da + hra + ta) - income_tax;
        return net_salary;
    }

    void display() const {
        Person::display();
        std::cout << "Employee ID: " << emp_id << std::endl;
        std::cout << "Qualification: " << qualification << std::endl;
        std::cout << "Basic Salary: " << basic_salary << std::endl;
    }
};

int main() {
    // Creating a Student object
    Student student("carlo", 20, "221 Street, City", 1001, "ABC College");
    int marks[] = {85, 75, 80, 90, 88};
    student.setMarks(marks);

    // Displaying student details
    std::cout << "Student Details:" << std::endl;
    student.display();
    student.showResult();
    std::cout << std::endl;

    // Creating an Employee object
    Employee employee("Alice", 30, "456 Avenue, Town", 2001, "Masters", 60000);

    // Displaying employee details
    std::cout << "Employee Details:" << std::endl;
    employee.display();
    std::cout << "Net Salary: $" << employee.calculateNetSalary() << std::endl;

    return 0;
}