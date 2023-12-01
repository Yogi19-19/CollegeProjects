#include <iostream>
#include <string.h>
using namespace std;

class Fisier {
    const int codFisier;
    string numeFisier;
    int nrAccesari;
    string* editori;
public:
    Fisier() :codFisier(0), numeFisier(""), nrAccesari(0), editori(nullptr) {

    }

    Fisier(int codFisier, string numeFisier, int nrAccesari, const string* editori) 
        :codFisier(codFisier), nrAccesari(nrAccesari){

        if (numeFisier.length() > 5)
            this->numeFisier = numeFisier;
        else
            this->numeFisier = "";

        if (editori != nullptr && nrAccesari > 0) {
            this->editori = new string[nrAccesari];
            for (int i = 0; i < nrAccesari; i++)
                this->editori[i] = editori[i];
        }
        else {
            this->editori = nullptr;
        }
    }

    Fisier(const Fisier& F)
        : Fisier(F.codFisier, F.numeFisier, F.nrAccesari, F.editori) {

    }

    //setter
    void setEditori(string* _editori, int _nr) {
        if (_editori != nullptr && _nr > 0) {
            string* copie = new string[_nr];
            for (int i = 0; i < _nr; i++)
                copie[i] = _editori[i];
            delete[] editori;
            editori = new string[_nr];
            editori = copie;
        }
    }

    //getter
    string* getEditori() {
        if (editori != nullptr && nrAccesari > 0) {
            string* copie = new string[nrAccesari];
            for (int i = 0; i < nrAccesari; i++)
                copie[i] = editori[i];
            return copie;
        }
    }

    Fisier& operator=(const Fisier& F) {
        if (this == &F)
            return *this;
         
        delete[] this->editori;
        editori = new string[F.nrAccesari];
        for (int i = 0; i < F.nrAccesari; i++)
            this->editori[i] = F.editori[i];
        this->nrAccesari = F.nrAccesari;
        this->numeFisier = F.numeFisier;
        return *this;
      
    }

    friend ostream& operator<<(ostream& out, Fisier& F) {
        out << "Cod fisier: " << F.codFisier << endl;
        out << "Nume: " << F.numeFisier << endl;
        out << "Nr: " << F.nrAccesari << endl;
        out << "Editori:";
        for (int i = 0; i < F.nrAccesari; i++)
            out << F.editori[i] << " ";
        out << endl;

        return out;
    }

    friend istream& operator>>(istream& in, Fisier& F) {
        
        char nume[256];
        in.getline(nume, 256);
        F.numeFisier = (string) nume;

        in >> F.nrAccesari;
        delete[] F.editori;
        in.getline(nume, 256);
        
        F.editori = new string[F.nrAccesari];
        for (int i = 0; i < F.nrAccesari; i++) {
            in.getline(nume, 256);
            F.editori[i] = (string)nume;
        }
        return in;
    }

    bool operator >(Fisier& F) {
        return numeFisier.size() > F.numeFisier.size();
    }

    string& operator[](int i) {
        return editori[i];
    }


    ~Fisier() {
        delete[] this->editori;
    }

    Fisier& operator ++() {
        nrAccesari++;
        string* copie = new string[nrAccesari];
        for (int i = 0; i < nrAccesari - 1; i++)
            copie[i] = editori[i];
        copie[nrAccesari - 1] = "Merge";
        delete[] editori;
        editori = new string[nrAccesari];
        editori = copie;
        cout << nrAccesari;
        
        return *this;
    }

    Fisier operator ++(int) {
        Fisier copie1;
        nrAccesari++;
        string* copie = new string[nrAccesari];
        for (int i = 0; i < nrAccesari-1; i++)
            copie[i] = editori[i];
        copie[nrAccesari - 1] = "Merge";
        delete[] editori;
        editori = new string[nrAccesari];
        editori = copie;
        cout << nrAccesari;
        return copie1;
    }

    friend Fisier operator+(string nume, Fisier F) {
        F.nrAccesari++;
        string* copie = new string[F.nrAccesari];
        for (int i = 0; i < F.nrAccesari - 1; i++)
            copie[i] = F.editori[i];
        copie[F.nrAccesari - 1] = nume;
        delete[] F.editori;
        F.editori = new string[F.nrAccesari];
        F.editori = copie;
        cout << F.nrAccesari;

        return F;
    }

    Fisier operator +=(string nume) {
        Fisier copie1;
        nrAccesari++;
        string* copie = new string[nrAccesari];
        for (int i = 0; i < nrAccesari - 1; i++)
            copie[i] = editori[i];
        copie[nrAccesari - 1] = nume;
        delete[] editori;
        editori = new string[nrAccesari];
        editori = copie;
        cout << nrAccesari;
        return copie1;
    }

    Fisier operator --(int) {
        Fisier copie1;
        nrAccesari--;
        string* copie = new string[nrAccesari];
        for (int i = 0; i < nrAccesari ; i++)
            copie[i] = editori[i];
        delete[] editori;
        editori = new string[nrAccesari];
        editori = copie;
        cout << nrAccesari;
        return copie1;
    }

    string operator !() {
        return numeFisier;
    }

};

int main() {
    // Example data for the first file
    string editori1[] = { "Editor1", "Editor2", "Editor3" };
    Fisier fisier1(1, "File1.txt", 3, editori1);
    Fisier  fisier2(2, "File1.txt", 3, editori1);

    fisier2 = fisier1++; 
    fisier2 = "Marcel" + fisier1;
    cout << fisier1 << endl;
    cout << fisier2;
  
   

    // Example data for the second file
    
    return 0;
}

