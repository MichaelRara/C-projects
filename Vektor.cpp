#include "Vektor.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
double Vektor::norm()
{
	return norm(p);
}

double Vektor::norm(double * a)//spoète normu vektoru a
{
	double norma = 0;
	for (int i = 0; i < n; i++)
	{
		norma += pow(*(a+i), 2); //funkce pow() udìlá druhou mocninu (2) z èísla p[i].
	}
	norma = sqrt(norma);
	return norma;
}

void Vektor::vypis()//Vypíše vektor
{
	for (int i = 0; i < n; i++)
	{
		cout << *(p+i)<< " ";
	}
	cout << endl;
}

double* Vektor::vektor()//Metoda na vytvoøení vektoru. Tato metoda je vytvoøená nejspíše zbyteènì. Vektor se zadává pomocí konstruktoru.
{
	double* muj_vektor = new double[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Zadej èíslo" << endl;
		cin>>*(muj_vektor+i);
	}
	p = muj_vektor;
	return muj_vektor;
}

double Vektor::Ssoucin(double* p)//spoète skalární souèin
{
   double s = 0;
   for (int i = 0; i < n; i++)
	{
		s += *(p+i) * *(this->p+i)	;
	}
	return s;
}

double * Vektor::normal(double* u)//Spoète normálový vektor
{
	if (n != 3)
		cout << "Nelze vytvoøit normálový vektor" << endl;
	else
	{
		double* nVektor = new double[3];
		*(nVektor) = *(u + 1)* *(p + 2) - *(u + 2)* *(p + 1);
		*(nVektor + 1) = *(u + 2)* *(p)-*(u)* *(p + 2);
		*(nVektor + 2) = *(u)* *(p + 1) - *(u + 1)* *(p);
		cout << "Normálový vektor tìchto pøímek je: " << *(nVektor)<<" " << *(nVektor + 1) << " " << *(nVektor + 2) << endl;
	}
	return nVektor;
}

double Vektor::Angle(double * p)//Metoda na spoètení úhlu
{
	double s= acos( Ssoucin(p) / (norm(this->p)*norm(p)) );	
	s *= (180 / 3.14159265359); //Pøevede z radiánù na stupnì
	return s;
}

Vektor::Vektor(){}
Vektor::Vektor(int n)//Konstrutkor na vytvoøení vektoru
{
	this->n = n;
	double* muj_vektor = new double[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Zadej " + to_string(i) << ". složku vektoru" << endl;
		cin >> *(muj_vektor + i);
	}
	p = muj_vektor;
}
Vektor::~Vektor() {}


