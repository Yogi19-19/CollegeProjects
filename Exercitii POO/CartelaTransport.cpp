#include <iostream>

using namespace std;

class CartelaTransport {

private:
    const string serieCartela;
    string numePosesor;
    char* producatorCartela;
    int nrZileUtilizare, nrCalatorii;
    float sumaPortofel;
    float* valoriCalatorii;
    static float valoareMinCalatorie;

public:
    CartelaTransport(): serieCartela("") {
        this->numePosesor = "Merge";
        this->producatorCartela = nullptr;
        this->nrZileUtilizare = 0;
        this->nrCalatorii = 0;
        this->sumaPortofel = 0;
        this->valoriCalatorii = nullptr;
    }

    CartelaTransport(string numePosesor, float sumaPortofel, float* valoriCalatorii, int nrCalatorii)
    :producatorCartela(nullptr), nrZileUtilizare(0), serieCartela("") {
        this->numePosesor = numePosesor;

        if(nrCalatorii >= 0)
            this->nrCalatorii = nrCalatorii;
        else
            this->nrCalatorii = 0;

        if (sumaPortofel >= 0)
            this->sumaPortofel = sumaPortofel;
        else
            this->sumaPortofel = 0;
        
        if (valoriCalatorii != nullptr) {
            this->valoriCalatorii = new float[nrCalatorii];
            for (int i = 0; i < nrCalatorii; i++)
                this->valoriCalatorii[i] = valoriCalatorii[i];
        }
        else
            this->valoriCalatorii = nullptr;
    }

    CartelaTransport(const CartelaTransport& ct)
        :producatorCartela(ct.producatorCartela), nrZileUtilizare(ct.nrZileUtilizare), serieCartela(ct.serieCartela) {
        numePosesor = ct.numePosesor;

        if (nrCalatorii >= 0)
            nrCalatorii = ct.nrCalatorii;
        else
            nrCalatorii = 0;

        if (sumaPortofel >= 0)
            sumaPortofel = ct.sumaPortofel;
        else
            sumaPortofel = 0;

        if (valoriCalatorii != nullptr) {
            valoriCalatorii = new float[ct.nrCalatorii];
            for (int i = 0; i < ct.nrCalatorii; i++)
                valoriCalatorii[i] = ct.valoriCalatorii[i];
        }
        else
            valoriCalatorii = nullptr;
    }

    ~CartelaTransport() {
        delete[] producatorCartela;
        delete[] valoriCalatorii;
    }

    //setter
    void setNumePosesor(string nume) {
        if(nume != "")
            numePosesor = nume;
    }

    void setValoriCalatorii(float* valori, int nrValori) {
        if (valori != nullptr) {
            delete[] valoriCalatorii;
            valoriCalatorii = new float[nrValori];
            for (int i = 0; i < nrValori; i++)
                valoriCalatorii[i] = valori[i];
            nrCalatorii = nrValori;
        }
    }

    //getter
    string getNumePosesor() {
        return numePosesor;
    }

    float* getValoriCalatorii() {
        float* copie = new float[nrCalatorii];
        for (int i = 0; i < nrCalatorii; i++)
            copie[i] = valoriCalatorii[i];
        return copie;
    }

    int getNrCalatorii() {
        return nrCalatorii;
    }

    CartelaTransport& operator=(CartelaTransport& ct) {
        //serieCartela??
        numePosesor = ct.numePosesor;
        producatorCartela = ct.producatorCartela;
        nrZileUtilizare = ct.nrZileUtilizare;
        nrCalatorii = ct.nrCalatorii;
        sumaPortofel = ct.sumaPortofel;
        valoriCalatorii = new float[ct.nrCalatorii];
        for (int i = 0; i < ct.nrCalatorii; i++)
            valoriCalatorii[i] = ct.valoriCalatorii[i];
        return *this;
    }

    friend ostream& operator<<(ostream& out, CartelaTransport& ct) {
        out << "Nume: " << ct.numePosesor << endl;
        out << "Suma: " << ct.sumaPortofel << endl;
        return out;
    }

    friend istream& operator>>(istream& in, CartelaTransport& ct) {
        cout << "Nume nou: ";
        in >> ct.numePosesor;
        cout << "Suma noua:";
        in >> ct.sumaPortofel;
        return in;
    }
   
    CartelaTransport& operator+=(const int& n) {
        if (sumaPortofel - n*valoareMinCalatorie >= 0) {
            nrCalatorii += n;
            float* copie = new float[nrCalatorii];
            for (int i = 0; i < nrCalatorii; i++)
                if(i < nrCalatorii - n)
                    copie[i] = valoriCalatorii[i];
                else
                    copie[i] = valoareMinCalatorie;
           
            delete[] valoriCalatorii;
            valoriCalatorii = copie;
        }
        return *this;
    }

    friend bool operator >(CartelaTransport& A, CartelaTransport& B) {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < A.nrCalatorii; i++)
            sum1+= A.valoriCalatorii[i];
        for (int i = 0; i < B.nrCalatorii; i++)
            sum2 += B.valoriCalatorii[i];
        return sum1 > sum2;
    }


};

float CartelaTransport::valoareMinCalatorie = 3;
int main()
{
    float istoric_1[4] = { 1,2,3,4 }, istoric_2[5] = { 6,7,8,9,10 };
    CartelaTransport A("Vlad", 50, istoric_2, 4), B("Vlad", 50, istoric_1, 4);

    //operator +=
    A += 2;
    for (int i = 0; i < A.getNrCalatorii(); i++)
        cout << A.getValoriCalatorii()[i] << " ";
    cout << endl;
    cout << (A > B);



    
}

