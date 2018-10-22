#include "Primka.h"
#include <iostream>
#include <string>
#include <math.h>
#include "Vektor.h"
#include "Matice.h"
#include <stdio.h>  
#include <stdlib.h>
using namespace std;

Primka::Primka(){}
Primka::Primka(int n): Vektor(n) //Konstruktor na zad�n� bodu p��mky. Nejprve se zad� vektor pomoc� konstruktoru ze t��dy Vektor.h
{
	P = new double[n];
	double f;
	for (int i = 0; i < n; i++)
	{
		cout << "Zadej " + to_string(i) << ". bod p��mky" << endl;
		cin >> f;
		*(P + i)=f;
	}
}
Primka::~Primka()
{
	//for (int i = 0; i < n; i++)
	//{
		delete[] P;
	//}
	cout << "SMAZAL JSEM===========================================" << endl;
}

void Primka::vypis()//Vyp�e parametrickou rovnici p��mky
{
	cout<<"Bod p��mky"<<endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(P+i)<<" ";
	}
	cout << endl;
	cout << "Vektor p��mky" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(p + i) << " ";
	}
	cout << endl;
	cout << "Parametrick� rovnice p��mky " << endl;
	for (int i = 0; i < n; i++)
	{
		if (i < (n - 1))
			cout << "X" + to_string(i) << " = " << *(P + i) << " + " << *(p + i) << "t"<<endl;
		else
			cout << "X" + to_string(i) << " = " << *(P + i) << " + " << *(p + i) << "t" << "; t in R"<<endl;
	}
}
void Primka::poloha(Primka v)
{
	if (n>3)
			cout << "Algoritmus funguje jen pro p��mky v rovin� nebo 3D prostoru" << endl;
	else 
	{
		double** M = new double*[3];//Matice M bude m�t 3 ��dky
		double* g = new double[n];
		for (int i = 0; i < n; i++)
		{
			*(g+i) = *(v.p+i);//Vektor v
		}
		M[0] = g;//Vektor v
		double* x = new double[n];
		for (int i = 0; i < n; i++)
		{
			*(x+i) = *(p + i);//Vektor v
		}
		M[1] = x;//Vektor u
		double* R = new double[n];
		R = M[1];
		double* c = new double[n];
		for (int i = 0; i < n; i++)//Spo�te vektor A-B
		{
			c[i] = *(P + i) - *(v.P + i);
		}
		M[2] = c;
		Matice m(M, 3, n);
		m.vypis();
		//Zjist� hodnost matice a submatice
		//double** N = m.Diagonal(3,n);
		double** N = m.Diagonal();
		int k = 1;//Hodnost matice 
		int l = 1;//Hodnost roz���en� matice
		bool u=true;
		for (int j = 0; j < n; j++)//Zjist�, jestli je ��dek nulov�
		{
			if (*(N[1] + j) != 0)
			{
				u = false;
				break;
			}
		}
		if (u==false)//pokud je ��dek nenulov�, tak se zvedne hodnost matic k, l o jedni�ku
		{
			k++;
			l++;
		}
		u = true;
		for (int j = 0; j < n; j++)//Zjist�, jestli je ��dek nulov�
		{
			if (*(N[2] + j) != 0)
			{
				u = false;
				break;
			}
		}
		if (u ==false)//pokud je ��dek nenulov�, tak se zvedne hodnost roz���en� matice l o jedni�ku
			l++;
		int d = k + l;// se�te hodnost matic l, k
		cout << "k = " << k << endl;
		cout << "l = " << l << endl;
		cout << "d = " << d << endl;
		switch (d)
		{
		case 2:
			cout << "Tyto p��mky jsou toto�n� " << endl;//funguje
			cout << "�hel mezi t�mito p��mkami je: " + to_string(Angle(v.p)) << "�" << endl;
			break;
		case 3:
			cout << "Tyto p��mky jsou rovnob�n�" << endl;//funguje
			cout << "�hel mezi t�mito p��mkami je: " + to_string(Angle(v.p)) << "�" << endl;
			break;
		case 4:
			cout << "Tyto p��mky jsou r�znob�n�" << endl;//funguje
			cout << "�hel mezi t�mito p��mkami je: " + to_string(Angle(v.p)) << "�" << endl;
			normal(v.p);
			break;
		case 5:
			cout << "Tyto p��mky jsou mimob�n�" << endl;//funguje
			cout << "�hel mezi t�mito p��mkami je: " + to_string(Angle(v.p)) << "�" << endl;
			normal(v.p);
			break;
		}
	}
}

double Primka::Angle(double* les)//Spo�te �hel mezi dv�ma p��mkami
{
	double s = acos(abs(Ssoucin(les)) / (norm(p)*norm(les)));
	s *= (180 / 3.14159265359); //P�evede z radi�n� na stupn�
	return s;
}

