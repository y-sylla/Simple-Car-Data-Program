//****************************************************
// File: Car.h
//
// Purpose: Calculate and store information for a car.
//
// Written By: Yasia Sylla
//****************************************************

#include <vsgcapture.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#ifndef CARH
#define CARH

class Car {
protected:
	string m_Manufacturer;
	string *m_Model;
	string m_YearBuilt;
	double *m_MilesPerGallon;
	double *m_YearlyMileage[12];

public:
	Car ();
	Car(const Car &cSource);
	~Car();
	
	string GetManufact();
	void SetManufact(string manufacturer);
	
	string GetModel();
	void SetModel(string model);
	
	string GetYearBuilt();
	void SetYearBuilt(string yearBuilt);
	
	double GetMilesPerGallon();
	void SetMilesPerGallon(double milesPerGallon);
	
	double TotalCostPerYearOnGas(double gasCostPerGallon);
	double TotalYearlyMileage();
	void Load (string filename);
	void Store (string filename);

	Car& Car::operator=(const Car& rhs);

	friend bool operator==(const Car& lhs, const Car& rhs);
	friend ostream & operator<<(ostream &out, const Car&  rhs);
};

#endif