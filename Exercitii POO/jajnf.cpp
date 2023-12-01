// jajnf.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
using namespace std;

class Masina {
private:
    string marca, nr_inmatriculare;
    char* model;
    static int total_masini_fabricate;

public:
    Masina(string marca, char* model, string nr_inmatriculare) {
        this->marca = marca;

        this->model = new char[strlen(model) + 1];
        strcpy_s(this->model, strlen(model) + 1, model);

        this->nr_inmatriculare = nr_inmatriculare;
        increment();
    }

    static void increment() {

        Masina::total_masini_fabricate++;
    }

    //setter
    void setMarca(string marca) {
        this->marca = marca;
    }

    void setModel(char* model) { 
        this->model = new char[strlen(model) + 1];
        strcpy_s(this->model, strlen(model) + 1, model);

    }

    void setNrInmatriculare(string nr_inmatriculare) {
        this->nr_inmatriculare = nr_inmatriculare;
    }

    void setTotalMasiniFabricate(int total_masini_fabricate) {
        this->total_masini_fabricate = total_masini_fabricate;
    }

    //getter
    string getMarca() {
        return this->marca;
    }

    char* getModel() {
        char* copy = new char[strlen(this->model) + 1];
        strcpy_s(copy, strlen(this->model) + 1, this->model);
        return copy;

    }

    string getNrInmatriculare() {
        return this->nr_inmatriculare;
    }

    int totalMasiniFabricate() {
        return this->total_masini_fabricate;
    }
};
int Masina::total_masini_fabricate = 0;

int main()
{
    Masina m("Dacia", (char*)"Spring", "B200VVV");
    Masina m1("Dacia", (char*)"Logan", "B333GGG");
    cout << m.totalMasiniFabricate() << endl;

    char* ceva = m1.getModel();
    cout << ceva;
    delete[] ceva;
}


