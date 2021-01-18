#include<iostream>
#include<string>
using namespace std;



class Film
{
private:
	char* denumireFilm;
    static string gen; 
	int durata; //durata filmului
	int* oreRuleaza; //la ce ora ruleaza
	const int ziRuleaza; //de cate ori pe zi ruleaza filmul

public:
	Film() : ziRuleaza(5)
	{
		denumireFilm = new char[] {"Necunoscut"};
		durata = 0;
		oreRuleaza = nullptr;

	}

	Film(const Film& f) : ziRuleaza(f.ziRuleaza)
	{
		if (f.denumireFilm != nullptr)
		{
			this->denumireFilm = new char[strlen(f.denumireFilm) + 1];
			strcpy_s(this->denumireFilm, strlen(f.denumireFilm) + 1, f.denumireFilm);
		}
		else
		{
			this->denumireFilm = nullptr;
		}

		this->durata = f.durata;

		if (f.oreRuleaza != nullptr && f.ziRuleaza != 0)
		{
			this->oreRuleaza = new int[f.ziRuleaza];
			for (int i = 0; i < f.ziRuleaza; i++)
			{
				this->oreRuleaza[i] = f.oreRuleaza[i];
			}
		}
		else
		{
			this->oreRuleaza = nullptr;
		}
	}

	~Film()
	{
		if (denumireFilm != nullptr)
		{
			delete[] denumireFilm;
		}

		if (oreRuleaza != nullptr)
		{
			delete[] oreRuleaza;
		}
	}

	Film& operator=(const Film& f)
	{
		if (denumireFilm != nullptr)
		{
			delete[] denumireFilm;
		}

		if (oreRuleaza != nullptr)
		{
			delete[] oreRuleaza;
		}

		if (f.denumireFilm != nullptr)
		{
			this->denumireFilm = new char[strlen(f.denumireFilm) + 1];
			strcpy_s(this->denumireFilm, strlen(f.denumireFilm) + 1, f.denumireFilm);
		}
		else
		{
			this->denumireFilm = nullptr;
		}

		if (f.oreRuleaza != nullptr && f.ziRuleaza != 0)
		{
			this->oreRuleaza = new int[f.ziRuleaza];
			for (int i = 0; i < f.ziRuleaza; i++)
			{
				this->oreRuleaza[i] = f.oreRuleaza[i];
			}
		}
		else
		{
			this->oreRuleaza = nullptr;
		}

		this->durata = f.durata;

		return *this;
	}

	char* getdenumireFilm() 
	{
	    return denumireFilm;
	}

	void denumire_Film(const char* noua_denumire)
	{
		if (noua_denumire != nullptr)
		{
			if (denumireFilm != nullptr)
			{
				delete[] denumireFilm;
			}

			denumireFilm = new char[strlen(noua_denumire) + 1];
			strcpy_s(denumireFilm, strlen(noua_denumire) + 1, noua_denumire);
		}
		
	}

	static string getgen()
	{
		return gen;
	}

	static void setgen(string gen)
	{
		Film::gen = gen;
	}

	int getdurata()
	{
		return durata;
	}

	void setdurata(int durata)
	{
		if (durata > 0)
		{
			this->durata = durata;
		}
	}

	int* getoreRuleaza()
	{
		if (oreRuleaza != nullptr)
		{
			int* copie = new int[ziRuleaza];
			for (int i = 0; i < ziRuleaza; i++)
			{
				copie[i] = oreRuleaza[i];

			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}

	void setoreRuleaza(int* oreRuleaza)
	{
		if (oreRuleaza != nullptr && ziRuleaza != 0)
		{

			if (this->oreRuleaza != nullptr)
			{
				delete[] this->oreRuleaza;

			}
			this->oreRuleaza = new int[ziRuleaza];
			for (int i = 0; i < ziRuleaza; i++)
			{
				this->oreRuleaza[i] = oreRuleaza[i];
			}
		}
	}

	int getziRuleaza()
	{
		return ziRuleaza;
	}

	int operator[](int index)//operator index cu rol de citire
	{
		if (index >= 0 && index < ziRuleaza)
		{
			return oreRuleaza[index];
		}
		else
		{
			return -1;
		}
	}

	
	Film operator+(int valoare)//operator + 
	{
		Film copie = *this;
		copie.durata += valoare;
		return copie;
	}

	
	Film operator++()//operatorul de preincrementare
	{
		this->durata++;
		return *this;
	}

	
	Film operator++(int i)//operatorul de postincrementare
	{
		Film copie = *this;
		this->durata++;
		return copie;
	}

	
	explicit operator int()//operator de cast la int explicit
	{
		return durata;
	}
	
	bool operator!()//operatorul de negatie
	{
		return ziRuleaza > 0;
	}

	bool operator<(Film f)//operator conditional
	{
		return this->durata < f.durata;
	}

	friend ostream& operator<<(ostream&, Film);
	friend istream& operator>>(istream&, Film&);
};
string Film::gen = "Necunoscut";


ostream& operator<<(ostream& out, Film f)
{
	out << "Numele filmului: ";
	if (f.denumireFilm != nullptr)
	{
		out << f.denumireFilm;
	}
	out << endl;
	out << "Genul filmului: " << f.gen << endl; 
	out << "Durata filmului(minute): " << f.durata << endl;
	out << "Filmul ruleaza la orele: ";
	if (f.oreRuleaza != nullptr)
	{
		for (int i = 0; i < f.ziRuleaza; i++)
		{
			out << f.oreRuleaza[i] << " ";
		}
		out << endl;
	}
	out << "*************************************" << endl;
	return out;
}

istream& operator>>(istream& in, Film& f)
{
	char buffer[100];
	cout << "Introduceti numele filmului: ";
	in >> ws;
	in.getline(buffer, 99);
	if (f.denumireFilm != nullptr)
	{
		delete[] f.denumireFilm;
	}
	f.denumireFilm = new char[strlen(buffer) + 1];
	strcpy_s(f.denumireFilm, strlen(buffer) + 1, buffer);
	cout << "Introduceti genul filmului: ";
	in >> f.gen;
	cout << "Introduceti durata filmului(minute): ";
	in >> f.durata;
	cout << "Introduceti orele la care o sa ruleze filmul(5) :" << endl;
	if (f.oreRuleaza != nullptr)
	{
		delete[] f.oreRuleaza;
	}
	if (in.good() && f.ziRuleaza > 0)//validare biti bad si fail stream de intrare
	{
		f.oreRuleaza = new int[f.ziRuleaza];
		for (int i = 0; i < f.ziRuleaza; i++)
		{
			cout << "Ora " << i + 1 << " = ";
			in >> f.oreRuleaza[i];
		}
	}
	else
	{
		f.oreRuleaza = nullptr;
	}
	return in;
}

/*class Sala
{
private:
	const int locuriTotal;
	int* locuri;
	char* denumireSala;
	int intrari_iesiri;


};*/

int main()
{
	//Proba pentru clasa Film
	Film f;//proba getteri si setteri
	cout << f.getdenumireFilm() << endl;
	cout << f.getdurata() << endl;
	cout << f.getgen() << endl;
	cout << f.getziRuleaza() << endl;
	cout << f.getoreRuleaza() << endl;

	cout << endl;

	f.denumire_Film("Iron Man");
	cout << f.getdenumireFilm() << endl;
	f.setdurata(120);
	cout << f.getdurata() << endl;
	f.setgen("Comedie");
	cout << f.getgen() << endl;
	int ore[] = { 7, 9, 11, 13, 19 };
	f.setoreRuleaza(ore); //trebuiesc introduse 5 ore 
	int* x = f.getoreRuleaza();
	if (x != nullptr)
	{
		for (int i = 0; i < f.getziRuleaza(); i++)
		{
			cout << x[i] << " ";
		}
	}

	Film f1,f2;
	f1 = f; //proba constructor copiere
	cout << endl;
	cout << endl;
	cout << f1.getdenumireFilm() << endl;
	cout << f1.getdurata() << endl;
	cout << f1.getgen() << endl;
	cout << f1.getziRuleaza() << endl;
	int* y = f1.getoreRuleaza();
	if (y != nullptr)
	{
		for (int i = 0; i < f1.getziRuleaza(); i++)
		{
			cout << y[i] << " ";
		}
	}
	cout << endl;

	cout << f1 << endl; //proba ostream
	cin >> f2;//proba istream
	cout << f2 << endl;
	cout << f2[3] << endl;//proba operator indexare
	//Aici se termina proba pt clasa Film


}
