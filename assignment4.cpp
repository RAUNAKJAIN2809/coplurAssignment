#include <iostream>
#include <string>

using namespace std;


class IEmployee {
public:
    virtual void GetDetails(int EmpID, string EmpName, string EmpType) = 0;
    virtual void Payroll() = 0;
    virtual void CalculateSalary() = 0;
};


class ContractEmployee : public IEmployee {
private:
    int hourlyRate;
    int hour;

public:
    ContractEmployee(int hourlyRate, int hour) {
        this->hourlyRate = hourlyRate;
        this->hour = hour;
    }

    void GetDetails(int EmpID, string EmpName, string EmpType) override {
        cout << "EmpID : " << EmpID << " | EmpName : " << EmpName << " | EmpType : " << EmpType << endl;
    }

    void Payroll() override {
    cout << "Payroll Details for Contract Employee:" << endl;
    cout << "Payment Schedule: 3-4 business days following submission" << endl;
    cout << "Total Compensation: " << (hourlyRate * hour) << endl;
}

    void CalculateSalary() override {
        cout << "Contract Employee Salary: " << (hourlyRate * hour) << endl;
    }
};


class PermanentEmployee : public IEmployee {
private:
    int basicPay;
    int bonus;

public:
    PermanentEmployee(int basicPay, int bonus) {
        this->basicPay = basicPay;
        this->bonus = bonus;
    }

    void GetDetails(int EmpID, string EmpName, string EmpType) override {
        cout << "EmpID : " << EmpID << " | EmpName : " << EmpName << " | EmpType : " << EmpType << endl;
    }

    void Payroll() override {
    cout << "Payroll Information for Permanent Employee:" << endl;
    cout << "Payment Date: On the 1st of each month" << endl;
    cout << "Total Payment: " << (basicPay + bonus) << endl;
}

    void CalculateSalary() override {
        cout << "Permanent Employee Salary: " << (basicPay + bonus) << endl;
    }
};


class NewEmployee : public IEmployee {
private:
    int basicPay;
    int bonus;
    int hourlyRate;
    int hour;

public:
    NewEmployee(int basicPay, int bonus, int hourlyRate, int hour) {
        this->basicPay = basicPay;
        this->bonus = bonus;
        this->hourlyRate = hourlyRate;
        this->hour = hour;
    }

    void GetDetails(int EmpID, string EmpName, string EmpType) override {
        cout << "New Employee!" << endl;
        cout << "EmpID : " << EmpID << " | EmpName : " << EmpName << " | EmpType : " << EmpType << endl;
    }

    void Payroll() override {
        cout << "Payroll Information for New Employee:" << endl;
        cout << "Payment Date: Within 3-4 business days following submission" << endl;
        cout << " Total Amount : " << (hourlyRate * hour) << endl;
    }

    void CalculateSalary() override {
        cout << "New Employee Salary: " << (hourlyRate * hour) << endl;
    }
};


IEmployee* GetEmployee(string type) {
    if (type == "Permanent") {
        return new PermanentEmployee(100000, 5000);
    } else if (type == "new") {
        return new NewEmployee(100000, 5000, 500, 50);
    } else {
        return new ContractEmployee(500, 50);
    }
}


int main() {
    IEmployee* Raunak = GetEmployee("Permanent");
    Raunak->GetDetails(1, "Raunak", "Permanent worker");
    Raunak->CalculateSalary();
    Raunak->Payroll();
    cout << endl;

    IEmployee* Uday = GetEmployee("An");
    Uday->GetDetails(2, "Uday", "Freelancer worker");
    Uday->CalculateSalary();
    Uday->Payroll();
    cout << endl;

    IEmployee* Divyansh = GetEmployee("new");
    Divyansh->GetDetails(3, "Divyansh", "Intern worker");
    Divyansh->CalculateSalary();
    Divyansh->Payroll();

    
    delete Raunak;
    delete Uday;
    delete Divyansh;

    return 0;
}