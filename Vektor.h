#pragma once
class Vektor
{
public:
	double norm();//Spo�te normu vektoru
	double norm(double* a);//Spo�te normu vektoru a
	virtual void vypis();//vyp�e vektor
	double* vektor();//Metoda na vytvo�en� vektoru
	double Ssoucin(double* p);//spo�te skal�rn� sou�in
	double* normal(double* u);//spo�te norm�lov� vektor
	virtual double Angle(double* p);//spo�te �hel mezi vektory
	Vektor();
	Vektor(int n);//Konstruktor na vytvo�en� vektoru
	~Vektor();

	double* nVektor;//norm�lov� vektor
	double* p;//vektor
	int n;//dimenze vektoru

	
private:
	double norma;
};

