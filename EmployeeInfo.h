/**************************************
File: EmployeeInfo.h
header file for Employee Data
***************************************/

#ifndef EMPLOYEEINFO_
#define EMPLOYEEINFO_

#include <string>

class EmployeeInfo
{
	private:
		std::string empName;
		int empID;
	public:
		bool operator==(const EmployeeInfo empRightSide)const;
		bool operator<(const EmployeeInfo empRightSide)const;
		bool operator>(const EmployeeInfo empRightSide) const;
		EmployeeInfo(); // default constructor
		EmployeeInfo(std::string name, int id);
		void setName(std::string name);
		void setID(int newID);
		std::string getName() const;
		int getID() const;
	
};

#include "EmployeeInfo.cpp"
#endif