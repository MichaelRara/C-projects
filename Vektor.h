#pragma once
class Vektor
{
public:
	double norm();//Spoète normu vektoru
	double norm(double* a);//Spoète normu vektoru a
	virtual void vypis();//vypíše vektor
	double* vektor();//Metoda na vytvoøení vektoru
	double Ssoucin(double* p);//spoète skalární souèin
	double* normal(double* u);//spoète normálový vektor
	virtual double Angle(double* p);//spoète úhel mezi vektory
	Vektor();
	Vektor(int n);//Konstruktor na vytvoøení vektoru
	~Vektor();

	double* nVektor;//normálový vektor
	double* p;//vektor
	int n;//dimenze vektoru

	
private:
	double norma;
};

