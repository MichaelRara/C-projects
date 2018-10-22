#pragma once
#include "Matice.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Matice
{
public:
	
	Matice(double** matrix,int r, int s);
	Matice(double** matrix, int n);
	Matice(int r, int s);
	~Matice();
	void vypis(double** N,int r, int s);//Vypíše matici
	void vypis();//Vypíše matici
	double** Diagonal();//Pøevede na diagonální tvar
	int Hodnost();//Spoète hodnost matice
	double Determinant();//Spoète determinant matice
	double* Cramer(double* p);//Vyøeší soustavu Cramerovým pravidlem
	double** Copy(double** matrix, int r, int s);// Metoda zkopíruje zadanou matici do výstupního parametru
	
	//Atributy	
	double** M; // Matice soustavy
	double* p; // vektor pravé strany

private:
	int r, s, n; // r = øádky, s = sloupce, n = øádky (pro ètvercovou matici)
	int h; // h=hodnost
	double d; // d=determinant
	double* result; // vektor øešení
	int sgn;// sgn = poèet prohození øádkù u metody Diagonal(). Využije se v metodì Determinant(), protože pøi zámìnì øádkù se zmìní znaménko. 
};

