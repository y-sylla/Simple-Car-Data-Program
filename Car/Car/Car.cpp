//****************************************************
// File: Car.cpp
//
// Purpose: Calculate and store information for a car.
//
// Written By: Yasia Sylla
//****************************************************


#include "Car.h"


//****************************************************
// Function: Car
//
// Purpose: Constructor for Car.
//****************************************************

Car::Car()
{
	m_Manufacturer = "MANUFACTURER";
	*m_Model = "MODEL";
	m_YearBuilt = "0";
	*m_MilesPerGallon = 0;
	*m_YearlyMileage = new double [12];
}

//****************************************************
// Function: Car
//
// Purpose: Copy constructor for Car.
//****************************************************

Car::Car(const Car &cSource)
{
	//m_nCents = cSource.m_nCents;
	m_Manufacturer = cSource.m_Manufacturer;
	*m_Model = *cSource.m_Model;
	m_YearBuilt = cSource.m_YearBuilt;
	*m_MilesPerGallon = *cSource.m_MilesPerGallon;
	*m_YearlyMileage = *cSource.m_YearlyMileage;
}

//****************************************************
// Function: GetManufact
//
// Purpose: Gets Manufacturer member variable.
//****************************************************


string Car::GetManufact()
{
	return m_Manufacturer;
}

//****************************************************
// Function: SetManufact
//
// Purpose: Sets Manufacturer member variable.
//****************************************************

void Car::SetManufact (string manufacturer)
{
	m_Manufacturer = manufacturer;
}

//****************************************************
// Function: GetModel
//
// Purpose: Gets Model member variable.
//****************************************************

string Car::GetModel()
{
	return *m_Model;
}

//****************************************************
// Function: SetModel
//
// Purpose: Sets Model member variable.
//****************************************************

void Car::SetModel (string model)
{
	*m_Model = model;
}

//****************************************************
// Function: GetYearBuilt
//
// Purpose: Gets YearBuilt member variable.
//****************************************************

string Car::GetYearBuilt()
{
	return m_YearBuilt;
}

//****************************************************
// Function: SetYearBuilt
//
// Purpose: Sets YearBuilt member variable.
//****************************************************

void Car::SetYearBuilt (string yearBuilt)
{
	m_YearBuilt = yearBuilt;
}

//****************************************************
// Function: GetMilesPerGallon
//
// Purpose: Gets MilesPerGallon member variable.
//****************************************************

double Car::GetMilesPerGallon()
{
	return *m_MilesPerGallon;
}

//****************************************************
// Function: SetMilesPerGallon
//
// Purpose: Sets MMilesPerGallon member variable.
//****************************************************

void Car::SetMilesPerGallon (double milesPerGallon)
{
	*m_MilesPerGallon = milesPerGallon;
}

//****************************************************
// Function: TotalYearlyMileage
//
// Purpose: Calculates the total YearlyMileage of a car.
//****************************************************
double Car::TotalYearlyMileage()
{
	int i;
	double total = 0;

	for (i=0; i<12; i++)
		total += *m_YearlyMileage[i];
	return total;
}

//*********************************************************************
// Function: TotalCostPerYearOnGas(
//
// Purpose: Calculates the total amound of money spend on gas a year.
//*********************************************************************
double Car::TotalCostPerYearOnGas(double gasCostPerGallon)
{
	double totalMiles, totalCost=0;

	totalMiles = TotalYearlyMileage();

	totalCost = (totalMiles / *m_MilesPerGallon) * gasCostPerGallon;

	return totalCost;
}

//******************************************************
// Function: Load
//
// Purpose: Loads values for member variables from file.
//******************************************************

void Car::Load (string filename)
{
	ifstream file;
	file.open (filename.c_str());
	file >> m_Manufacturer;
	file >> *m_Model;
	file >> m_YearBuilt;
	file >> *m_MilesPerGallon;

	for (int i=0; i<12; i++)
		file >> *m_YearlyMileage[i];
	file.close();
}

//*****************************************************
// Function: Store
//
// Purpose: Stores values for member variables in file.
//*****************************************************

void Car::Store (string filename)
{
	ofstream file;
	file.open(filename.c_str());

	file << "Manufacturer: " << m_Manufacturer << endl;
	file << "Model: " << *m_Model << endl;
	file << "Year Built: " << m_YearBuilt << endl;
	file << "Miles Per Gallon: " << *m_MilesPerGallon << endl;
	file << "Total YearlyMileage: " << TotalYearlyMileage() << endl;
	file << "Total Cost Per Year on Gas: " << TotalCostPerYearOnGas(3.39) << endl;
}

//****************************************************
// Function: Operator=
//
// Purpose: Operator overload for =.
//****************************************************

Car& Car::operator=(const Car& rhs)
{
	if (this == &rhs)
		return *this;

	m_Manufacturer = rhs.m_Manufacturer;
	m_Model = rhs.m_Model;
	m_YearBuilt = rhs.m_YearBuilt;
	m_MilesPerGallon = rhs.m_MilesPerGallon;

	return *this;
}

//****************************************************
// Function: Operator==
//
// Purpose: Operator overload for ==.
//****************************************************

bool operator==(const Car& lhs, const Car& rhs)
{
	bool ret;

	if (lhs.m_Manufacturer == rhs.m_Manufacturer && *lhs.m_Model == *rhs.m_Model)
		ret = true;
	else
		ret = false;

	return ret;
}

//****************************************************
// Function: Operator<<
//
// Purpose: Operator overload for <<.
//****************************************************

ostream & operator<<(ostream &out, const Car&  rhs)
{
	out << "Manufacturer: " << rhs.m_Manufacturer << endl;
	out << "Model: " << *rhs.m_Model << endl;
	out << "Year Built: " << rhs.m_YearBuilt << endl;
	out << "Miles Per Gallon: " << *rhs.m_MilesPerGallon << endl;
	out << "Total YearlyMileage: " << rhs.m_YearlyMileage << endl;

	return out;
}

Car::~Car()
{
	cout << "Destructor Called" <<endl;

	delete m_Model;
	delete m_MilesPerGallon;

	delete [] m_YearlyMileage;
}