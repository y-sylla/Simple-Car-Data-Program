// Main.cpp : Defines the entry point for the console application.
//

//****************************************************
// File: Main.cpp
//
// Purpose: Uses Car.lib to process data of Car
//
// Written By: Yasia Sylla 
//****************************************************


#include "stdafx.h"
#include "Car.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Car c1;
	Car *c2 = NULL;

	c2 = new Car;

	c1.Load("CarData.txt");

	c2->SetManufact("Honda");
	c2->SetModel("Civic");
	c2->SetYearBuilt("2012");
	c2->SetMilesPerGallon(30);

	cout << *c2 << endl;

	if (*c2 == c1)
		cout << "Equal" << endl;
	else
		c1.Store("output.txt");

	*c2 = c1;

	cout << *c2 << endl;

	cout << "Manufacturer: " << c1.GetManufact() << endl;
	cout << "Model: "<< c1.GetModel() << endl;
	cout << "Year Built: " << c1.GetYearBuilt() << endl;
	cout << "Miles Per Gallon: " << c1.GetMilesPerGallon() << endl;

	delete c2;

	return 0;
}