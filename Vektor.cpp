#include "Vektor.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
double Vektor::norm()
{
	return norm(p);
}

double Vektor::norm(double * a)//spo�te normu vektoru a
{
	double norma = 0;
	for (int i = 0; i < n; i++)
	{
		norma += pow(*(a+i), 2); //funkce pow() ud�l� druhou mocninu (2) z ��sla p[i].
	}
	norma = sqrt(norma);
	return norma;
}

void Vektor::vypis()//Vyp�e vektor
{
	for (int i = 0; i < n; i++)
	{
		cout << *(p+i)<< " ";
	}
	cout << endl;
}

double* Vektor::vektor()//Metoda na vytvo�en� vektoru. Tato metoda je vytvo�en� nejsp�e zbyte�n�. Vektor se zad�v� pomoc� konstruktoru.
{
	double* muj_vektor = new double[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Zadej ��slo" << endl;
		cin>>*(muj_vektor+i);
	}
	p = muj_vektor;
	return muj_vektor;
}

double Vektor::Ssoucin(double* p)//spo�te skal�rn� sou�in
{
   double s = 0;
   for (int i = 0; i < n; i++)
	{
		s += *(p+i) * *(this->p+i)	;
	}
	return s;
}

double * Vektor::normal(double* u)//Spo�te norm�lov� vektor
{
	if (n != 3)
		cout << "Nelze vytvo�it norm�lov� vektor" << endl;
	else
	{
		double* nVektor = new double[3];
		*(nVektor) = *(u + 1)* *(p + 2) - *(u + 2)* *(p + 1);
		*(nVektor + 1) = *(u + 2)* *(p)-*(u)* *(p + 2);
		*(nVektor + 2) = *(u)* *(p + 1) - *(u + 1)* *(p);
		cout << "Norm�lov� vektor t�chto p��mek je: " << *(nVektor)<<" " << *(nVektor + 1) << " " << *(nVektor + 2) << endl;
	}
	return nVektor;
}

double Vektor::Angle(double * p)//Metoda na spo�ten� �hlu
{
	double s= acos( Ssoucin(p) / (norm(this->p)*norm(p)) );	
	s *= (180 / 3.14159265359); //P�evede z radi�n� na stupn�
	return s;
}

Vektor::Vektor(){}
Vektor::Vektor(int n)//Konstrutkor na vytvo�en� vektoru
{
	this->n = n;
	double* muj_vektor = new double[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Zadej " + to_string(i) << ". slo�ku vektoru" << endl;
		cin >> *(muj_vektor + i);
	}
	p = muj_vektor;
}
Vektor::~Vektor() {}


