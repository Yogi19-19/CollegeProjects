#include <iostream>
using namespace std;

class Vapor {

private:
    static int nrVapoare;
    int capacitate, nrPersoaneImbarcate;
    int* varstePasageri;

public:
    Vapor() {
    
    }

    Vapor(int capacitate, int nrPersoaneImbarcate, int* varstePasageri) 
    :capacitate(capacitate), nrPersoaneImbarcate(nrPersoaneImbarcate){
        this->varstePasageri = new int[nrPersoaneImbarcate];
        for (int i = 0; i < nrPersoaneImbarcate; i++)
            this->varstePasageri[i] = varstePasageri[i];
    }

    Vapor(const Vapor& v) :capacitate(v.capacitate), nrPersoaneImbarcate(v.nrPersoaneImbarcate) {
        varstePasageri = new int[v.nrPersoaneImbarcate];
        for (int i = 0; i < v.nrPersoaneImbarcate; i++)
            varstePasageri[i] = v.varstePasageri[i];
    }

   

    //setter
    void setNrPersoaneImbarcate(int value) {
        this->nrPersoaneImbarcate = value;
    }

    void setCapacitate(int value) {
        capacitate = value;
    }

    //getter
    int getNrPersoaneImbarcate() {
        return this->nrPersoaneImbarcate;
    }

    int getCapacitate() {
        return capacitate;
    }

    int* getVarstePasageri() {
        int* copie = new int[this->nrPersoaneImbarcate];
        for (int i = 0; i < this->nrPersoaneImbarcate; i++)
            copie[i] = this->varstePasageri[i];
        return copie;
    }

    Vapor& operator = (const Vapor & vapor){
        this->capacitate = vapor.capacitate;
        this->nrPersoaneImbarcate = vapor.nrPersoaneImbarcate;
        this->varstePasageri = new int[vapor.nrPersoaneImbarcate];
        for (int i = 0; i < vapor.nrPersoaneImbarcate; i++)
            varstePasageri[i] = vapor.varstePasageri[i];
        return *this;
    }

    friend ostream& operator << (ostream& out, const Vapor& V)
    {
        out << V.capacitate << "; " << V.nrPersoaneImbarcate << "; ";
        for (int i = 0; i < V.nrPersoaneImbarcate; i++)
            out << V.varstePasageri[i] << "; ";
        out << endl;
        return out;
    }

    Vapor & operator ++(int) {

        Vapor tmp(*this);

        if (nrPersoaneImbarcate == capacitate)
            return tmp;

        nrPersoaneImbarcate += 1;

        int* copie = new int[nrPersoaneImbarcate];
        for (int i = 0; i < nrPersoaneImbarcate-1; i++)
            copie[i] = varstePasageri[i];
        copie[nrPersoaneImbarcate - 1] = 0;
        
        delete[] varstePasageri;
        varstePasageri = copie;

        return tmp;
    }

    Vapor& operator --(int) {

        Vapor tmp(*this);

        if (nrPersoaneImbarcate == 0)
            return tmp;

        nrPersoaneImbarcate -= 1;

        int* copie = new int[nrPersoaneImbarcate];
        for (int i = 0; i < nrPersoaneImbarcate ; i++)
            copie[i] = varstePasageri[i];

        delete[] varstePasageri;
        varstePasageri = copie;

        return tmp;
    }

    Vapor operator-() {
        Vapor V(-capacitate, nrPersoaneImbarcate, varstePasageri);
        return V;
    }

    double calculareVarstaMedie() {
        double sum = 0;
        for (int i = 0; i < nrPersoaneImbarcate; i++)
            sum += varstePasageri[i];
        return (nrPersoaneImbarcate > 0) ? sum / nrPersoaneImbarcate : 0;

    }

    ~Vapor() {
        delete[] varstePasageri;
    }

};

int Vapor::nrVapoare = 0;

int main()
{
    int varste_1[4] = { 1,2,3,4 }, varste_2[3] = { 6,7,9};
    Vapor A(10, 4, varste_1), B(8, 3, varste_2);

    A = B;
    cout << A.getNrPersoaneImbarcate() << endl;
    for (int i = 0; i < A.getNrPersoaneImbarcate(); i++)
        cout << A.getVarstePasageri()[i] << " ";
    cout << endl;
    cout << A;

    /*A++;
    for (int i = 0; i < A.getNrPersoaneImbarcate(); i++)
        cout << A.getVarstePasageri()[i] << " ";
    cout << endl;

    A--;
    for (int i = 0; i < A.getNrPersoaneImbarcate(); i++)
        cout << A.getVarstePasageri()[i] << " ";
    cout << endl;

    cout << (-A).getCapacitate() << endl;

    cout << "Media varstelor: " << A.calculareVarstaMedie() << endl;*/

}
