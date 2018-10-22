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
	void vypis(double** N,int r, int s);//Vyp�e matici
	void vypis();//Vyp�e matici
	double** Diagonal();//P�evede na diagon�ln� tvar
	int Hodnost();//Spo�te hodnost matice
	double Determinant();//Spo�te determinant matice
	double* Cramer(double* p);//Vy�e�� soustavu Cramerov�m pravidlem
	double** Copy(double** matrix, int r, int s);// Metoda zkop�ruje zadanou matici do v�stupn�ho parametru
	
	//Atributy	
	double** M; // Matice soustavy
	double* p; // vektor prav� strany

private:
	int r, s, n; // r = ��dky, s = sloupce, n = ��dky (pro �tvercovou matici)
	int h; // h=hodnost
	double d; // d=determinant
	double* result; // vektor �e�en�
	int sgn;// sgn = po�et prohozen� ��dk� u metody Diagonal(). Vyu�ije se v metod� Determinant(), proto�e p�i z�m�n� ��dk� se zm�n� znam�nko. 
};

