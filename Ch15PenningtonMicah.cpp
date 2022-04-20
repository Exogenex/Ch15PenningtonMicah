// Micah Pennington
// April 12 2022 ©
// Chapter 14 Program

#pragma region Not_Micah_Penningtons_Code
// Specification for the Employee class
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Employee {
private:
	string name;		// Employee name
	string number;		// Employee number
	string hireDate;	// Hire date

public:
	// Default constructor
	Employee() { name = ""; number = ""; hireDate = ""; }

	// Constructor
	Employee(string aName, string aNumber, string aDate) { name = aName; number = aNumber; hireDate = aDate; }

	// Mutators
	void setName(string n) { name = n; }
	void setNumber(string num) { number = num; }
	void setHireDate(string date) { hireDate = date; }

	// Accessors
	string getName() const { return name; }
	string getNumber() const { return number; }
	string getHireDate() const { return hireDate; }
};


// Specification for the ProductionWorker Class

#include <string>
using namespace std;

class ProductionWorker : public Employee {
private:
	int shift;	// The worker's shift
	double payRate;	// The worker's hourly pay rate

public:
	// Default constructor
	ProductionWorker() : Employee() { shift = 0; payRate = 0.0; }

	// Constructor
	ProductionWorker(string aName, string aNumber, string aDate, int aShift, double aPayRate) : Employee(aName, aNumber, aDate) { shift = aShift; payRate = aPayRate; }

	// Mutators
	void setShift(int s) { shift = s; }
	void setPayRate(double r) { payRate = r; }

	// Accessors
	int getShiftNumber() const { return shift; }

	string getShiftName() const {
		if (shift == 1) return "Day";
		else if (shift == 2) return "Night";
		else return "Invalid";
	}
	double getPayRate() const { return payRate; }
};
#pragma endregion All code in this region was provided to me by my teacher

class ShiftSupervisor : public Employee {
private:
	double annualSalary;
	double annualBonus;
public:
	// Constructor
	ShiftSupervisor(string nameIN = "", string numberIN = "", string hireDateIN = "", double annualSalaryIN = 0, double annualBonusIN = 0) :
		Employee(nameIN, numberIN, hireDateIN) { annualSalary = annualSalaryIN; annualBonus = annualBonusIN; }

	// Setters
	void setAnnualSalary(double annualSalaryIN) { annualSalary = annualSalaryIN; }
	void setAnnualBonus(double annualBonusIN) { annualBonus = annualBonusIN; }

	// Getters
	double getAnnualSalary() { return annualSalary; }
	double getAnnualBonus() { return annualBonus; }
};

class TeamLeader : public ProductionWorker {
private:
	double monthlyBonus;
	int trainingHoursRequired;
	int trainingHoursAttended;
public:
	TeamLeader(string nameIN = "", string numberIN = "", string dateIN = "", int shiftIN = 0, double payRateIN = 0.0, double monthlyBonusIN = 0.0, int trainingHoursRequiredIN = 0, int trainingHoursAttendedIN = 0) :
		ProductionWorker(nameIN, numberIN, dateIN, shiftIN, payRateIN) {
		monthlyBonus = monthlyBonusIN;  trainingHoursRequired = trainingHoursRequiredIN; trainingHoursAttended = trainingHoursAttendedIN;
	}

	// Setters
	void setMonthlyBonus(double monthlyBonusIN) { monthlyBonus = monthlyBonusIN; }
	void setTrainingHoursRequired(int trainingHoursRequiredIN) { trainingHoursRequired = trainingHoursRequiredIN; }
	void setTrainingHoursAttended(int trainingHoursAttendedIN) { trainingHoursAttended = trainingHoursAttendedIN; }

	// Getters
	double getMonthlyBonus() { return monthlyBonus; }
	int getTrainingHoursRequired() { return trainingHoursRequired; }
	int getTrainingHoursAttended() { return trainingHoursAttended; }
};

#pragma region Not_Micah_Penningtons_Code
// Chapter 15, Programming Challenge 1: Employee and ProductionWorker classes
// Function prototype
void displayInfo(ProductionWorker);
#pragma endregion All code in this region was provided to me by my teacher
void displayInfo(ShiftSupervisor);
void displayInfo(TeamLeader);



int main() {
#pragma region Not_Micah_Penningtons_Code
	ProductionWorker pw("John Jones", "123", "10/12/2010", 2, 18.00);
	displayInfo(pw);
#pragma endregion All code in this region was provided to me by my teacher
	cout << '\n';
	ShiftSupervisor ss("David Smith", "007", "3/25/2015", 90000.00, 2000.00);
	displayInfo(ss);
	cout << '\n';
	TeamLeader tl("Kaladin Stormblessed", "10", "8/31/2010", 1, 16.61, 108.01, 8, 0);
	displayInfo(tl);

	return EXIT_SUCCESS;
}

#pragma region Not_Micah_Penningtons_Code
/// <summary>
/// The displayInfo function displays a production worker's employment information.
/// </summary>
/// <param name="e">The production worker to display</param>
void displayInfo(ProductionWorker e) {
	cout << setprecision(2) << fixed << showpoint;
	cout << "Name: " << e.getName() << endl;
	cout << "Employee number: " << e.getNumber() << endl;
	cout << "Hire date: " << e.getHireDate() << endl;
	cout << "Shift: " << e.getShiftName() << endl;
	cout << "Shift number: " << e.getShiftNumber() << endl;
	cout << "Pay rate: " << e.getPayRate() << endl;
}
#pragma endregion All code in this region was provided to me by my teacher

/// <summary>
/// The displayInfo function displays a shift supervisor's employment information.
/// </summary>
/// <param name="e">The shift supervisor to display</param>
void displayInfo(ShiftSupervisor e) {
	cout << setprecision(2) << fixed << showpoint
		<< "Name: " << e.getName() << '\n'
		<< "Employee number: " << e.getNumber() << '\n'
		<< "Hire date: " << e.getHireDate() << '\n'
		<< "Annual Salary: " << e.getAnnualSalary() << '\n'
		<< "Annual Bonus: " << e.getAnnualBonus() << '\n';
}

/// <summary>
/// The displayInfo function displays a shift supervisor's employment information.
/// </summary>
/// <param name="e">The shift supervisor to display</param>
void displayInfo(TeamLeader e) {
	cout << setprecision(2) << fixed << showpoint
		<< "Name: " << e.getName() << '\n'
		<< "Employee number: " << e.getNumber() << '\n'
		<< "Hire date: " << e.getHireDate() << '\n'
		<< "Monthly Bonus: " << e.getMonthlyBonus() << '\n'
		<< "Shift: " << e.getShiftName() << '\n'
		<< "Shift number: " << e.getShiftNumber() << '\n'
		<< "Pay rate: " << e.getPayRate() << '\n'
		<< "Training Hours Required: " << e.getTrainingHoursRequired() << '\n'
		<< "Training Hours Attended: " << e.getTrainingHoursAttended() << '\n';
}