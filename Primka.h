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
	Primka(int n);//Konstuktor na zadání bodu pøímky a vektoru
	~Primka();

	void vypis();//Vypíše parametrickou rovnici pøímky
	void poloha(Primka v);
	double Angle(double* les);//Spoète úhel mezi dvìma pøímkami
	double* P;//Bod
};

