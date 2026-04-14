#include <iostream>
using namespace std;

template <class T>
class Employee
{
public:
    virtual T calculateSalary() = 0;
};

template <class T>
class FullTimeEmployee : public Employee<T>
{
private:
    T salary;

public:
    FullTimeEmployee(T s)
    {
        salary = s;
    }

    T calculateSalary()
    {
        return salary;
    }
};

template <class T>
class PartTimeEmployee : public Employee<T>
{
private:
    T hours;
    T rate;

public:
    PartTimeEmployee(T h, T r)
    {
        hours = h;
        rate = r;
    }

    T calculateSalary()
    {
        return hours * rate;
    }
};

int main()
{
    FullTimeEmployee<float> f(50000);
    PartTimeEmployee<float> p(40, 500);

    cout << "Full Time Employee Salary: " << f.calculateSalary() << endl;
    cout << "Part Time Employee Salary: " << p.calculateSalary() << endl;

    return 0;
}