#include <iostream>
using namespace std;

class Vector {

private:
	const int id_unic;
	char* denumire;
	float* elemente;
	int nrElemente;
	string owner;
	static string supportGuy;

public:
	Vector()
		:id_unic(0) {
		this->denumire = nullptr;
		this->elemente = nullptr;
		this->nrElemente = 0;
		this->owner = "Test";
	}

	Vector(int id_unic, char* denumire, float* elemente, int nrElemente, string owner)
		: id_unic(id_unic), nrElemente(nrElemente), owner(owner){
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);

		this->elemente = new float[nrElemente];
		for (int i = 0; i < nrElemente;i++)
			this->elemente[i] = elemente[i];
	}

	Vector(float* elemente, int nrElemente, string owner)
		:nrElemente(nrElemente), owner(owner) , id_unic(0), denumire(nullptr){
		this->elemente = new float[nrElemente];
		for (int i = 0; i < nrElemente;i++)
			this->elemente[i] = elemente[i];
	}

	Vector(const Vector& v) 
		:id_unic(v.id_unic), nrElemente(v.nrElemente), owner(v.owner) {
		delete[] this->denumire;
		delete[] this->elemente;

		this->denumire = new char[strlen(v.denumire) + 1];
		strcpy_s(this->denumire, strlen(v.denumire) + 1, v.denumire);

		this->elemente = new float[v.nrElemente];
		for (int i = 0; i < v.nrElemente;i++)
			this->elemente[i] = v.elemente[i];
	}

	Vector& operator = (const Vector& v) {
	
		this->nrElemente = v.nrElemente;
		this->owner = v.owner;

		delete[] this->denumire;
		delete[] this->elemente;

		this->denumire = new char[strlen(v.denumire) + 1];
		strcpy_s(this->denumire, strlen(v.denumire) + 1, v.denumire);

		this->elemente = new float[v.nrElemente];
		for (int i = 0; i < v.nrElemente;i++)
			this->elemente[i] = v.elemente[i];

		return *this;
	}

	//setter
	void setOwner(string name) {
		owner = name;
	}

	void setElemente(float* elementeNoi, int nr) {
		nrElemente = nr;
		delete[] elemente;

		elemente = new float[nr];
		for (int i = 0; i < nrElemente; i++)
			elemente[i] = elementeNoi[i];
	}

	//getter

	string getOwner() {
		return owner;
	}

	float* getElemente() {
		float* copie = new float[nrElemente];
		for (int i = 0; i < nrElemente; i++)
			copie[i] = elemente[i];
		return copie;
	}

	friend ostream& operator << (ostream& out, Vector& v) {
		out << "Id unic: " << v.id_unic << endl;
		out << "Owner: " << v.owner << endl;
		out << "Denumire: " << v.denumire << endl;
		out << "Elemente: ";
		for (int i = 0; i < v.nrElemente; i++)
			out << v.getElemente()[i] << " ";
		

		return out;
	}

	friend istream& operator >> (istream& in, Vector& v) {
		cout << "Owner: ";
		in >> v.owner;
		cout << "Denumire: ";
		in >> v.denumire;
		cout << "Elemente: " << endl;
		delete[] v.elemente;
		v.elemente = new float[v.nrElemente];
		for (int i = 0; i < v.nrElemente; i++) {
			cout << i << ": ";
			in >> v.elemente[i];
		}
		return in;
	}

	Vector& operator()(int n) {
		for (int i = 0; i < nrElemente; i++)
			elemente[i] += n;
		return *this;
	}

	Vector& operator[](int i) {
		elemente[i] += 3;
		return *this;
	}

	Vector& operator +=(float element) {
		nrElemente += 1;
		float* copie = new float[nrElemente];
		for (int i = 0; i < nrElemente - 1; i++)
			copie[i] = elemente[i];
		copie[nrElemente - 1] = element;
		delete[] elemente;
		elemente = new float[nrElemente];
		elemente = copie;
		return *this;
	}

	Vector& operator --() {
		nrElemente -= 1;
		float* copie = new float[nrElemente];
		for (int i = 0; i < nrElemente ; i++)
			copie[i] = elemente[i];
		delete[] elemente;
		elemente = new float[nrElemente];
		elemente = copie;
		return *this;
	}

	~Vector() {
		delete[] denumire;
		delete[] elemente;
	}

};

int main()
{

	// Test parameterized constructor with id_unic
	float elements1[] = { 1.1, 2.2, 3.3 }, elements2[] = { 4.4, 5.5, 6.6 };
	Vector V1(1, (char*)"Vector1", elements1, 3, "User1"), V2;

	V2.setElemente(elements2, 3);
	for (int i = 0; i < 3; i++)
		cout << V2.getElemente()[i] << " ";
	cout << endl;

	V1(2);
	V1[2];
	V1 += 20;
	V1 += 30;
	--V1;
	--V1;
	
	cout << V1 << endl;

	return 0;
}


