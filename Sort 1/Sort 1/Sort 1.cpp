#include "pch.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Punkt
{
private:
	string nazwa;
	int a;
	int b;
	float odleglosc;

	friend bool sortowanie(const Punkt& lhs, const Punkt& rhs);

public:
	string getNazwa(){
		return nazwa;};
	int getA(){
		return a;};
	int getB(){
		return b;};
	float getOdleglosc(){
		return odleglosc;};

	Punkt(){};

	Punkt(string nazwa, int a, int b, float odleglosc){
		this->nazwa = nazwa;
		this->a = a;
		this->b = b;
		this->odleglosc = odleglosc;};

	~Punkt(){};
};

bool sortowanie(const Punkt& lhs, const Punkt& rhs)
{
	return lhs.odleglosc < rhs.odleglosc;
}

void fillVector(vector<Punkt>& nowePunkty)
{
	string nazwa;
	int a;
	int b;
	float odleglosc;

	int ile_punktow;
	cin >> ile_punktow;

	for (int i = 0; i < ile_punktow; i++)
	{
		cin >> nazwa >> a >> b;
		float odleglosc = sqrtf(pow(a, 2) + pow(b, 2));

		Punkt nowyPunkt(nazwa, a, b, odleglosc);
		nowePunkty.push_back(nowyPunkt);
		cout << " " << endl;
	}
}

int main()
{
	int ile_razy;
	cin >> ile_razy;

	for (int i = 0; i < ile_razy; i++)
	{
		vector<Punkt>punkty;

		fillVector(punkty);

		sort(punkty.begin(), punkty.end(), sortowanie);

		for (int k = 0; k < punkty.size(); k++)
		{
			cout << punkty[k].getNazwa() << " " << punkty[k].getA() << " " << punkty[k].getB() << endl;
			cout << " " << endl;
		}
	}
	return 0;
}