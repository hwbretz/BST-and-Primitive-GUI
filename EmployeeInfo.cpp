/****************************
	EmployeeInfo.cpp	
	implementation file for Employee Info
*****************************/

//#include EmployeeInfo.h

bool EmployeeInfo::operator==(const EmployeeInfo empRightSide) const
{
	bool equal = true;
	if (empRightSide.getID() != empID)
	{
		equal = false;
	}
	return equal;
}

bool EmployeeInfo::operator>(const EmployeeInfo empRightSide) const
{
	bool greater = true;
	if (empRightSide.getID() < empID)
	{
		greater = false;
	}
	return greater;
}

bool EmployeeInfo::operator<(const EmployeeInfo empRightSide) const
{
	bool lesser = true;
	if (empRightSide.getID() > empID)
	{
		lesser = false;
	}
	return lesser;
}
EmployeeInfo::EmployeeInfo() : empName(""), empID(-1)
{
	
} // end default constructor

EmployeeInfo::EmployeeInfo(std::string name, int id) : empName(name), empID(id)
{
	
} // end constructor

void EmployeeInfo::setName(std::string name)
{
	empName = name;
}

void EmployeeInfo::setID(int id)
{
	empID = id;
}

std::string EmployeeInfo::getName() const
{
	return empName;
}

int EmployeeInfo::getID() const
{
	return empID;
}
