#pragma once
#include "Vektor.h"
#include <iostream>
#include <string>
#include <math.h>
#include "Matice.h"
using namespace std;
class Primka :
	public Vektor
{
public:
	Primka();
	Primka(int n);//Konstuktor na zad�n� bodu p��mky a vektoru
	~Primka();

	void vypis();//Vyp�e parametrickou rovnici p��mky
	void poloha(Primka v);
	double Angle(double* les);//Spo�te �hel mezi dv�ma p��mkami
	double* P;//Bod
};

