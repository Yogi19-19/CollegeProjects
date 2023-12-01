#include <iostream>
using namespace std;

class ProfilInfluencer {
private:
    string numeCont;
    long int numarUrmaritori;
    int numarPostari;
    int* aprecieriPostari;
public:
    ProfilInfluencer()
        :numeCont("Merge"), numarUrmaritori(0), numarPostari(0), aprecieriPostari(nullptr){
    }

    ProfilInfluencer(string numeCont, long int numarUrmaritori, int numarPostari, int* aprecieriPostari)
        :numeCont(numeCont), numarPostari(numarPostari) {
        if (numarUrmaritori > 1000)
            this->numarUrmaritori = numarUrmaritori;
        else
            this->numarUrmaritori = 0;

        if (aprecieriPostari != nullptr && numarPostari != 0) {
            this->aprecieriPostari = new int[numarPostari];
            for (int i = 0; i < numarPostari; i++)
                this->aprecieriPostari[i] = aprecieriPostari[i];
        }
        else
            this->aprecieriPostari = nullptr;

    }

    ProfilInfluencer(const ProfilInfluencer& pi)
        :numeCont(pi.numeCont), numarPostari(pi.numarPostari) {
        if (pi.numarUrmaritori > 1000)
            this->numarUrmaritori = pi.numarUrmaritori;
        else
            this->numarUrmaritori = 0;

        if (pi.aprecieriPostari != nullptr && pi.numarPostari != 0) {
            this->aprecieriPostari = new int[pi.numarPostari];
            for (int i = 0; i < pi.numarPostari; i++)
                this->aprecieriPostari[i] = pi.aprecieriPostari[i];
        }
        else
            this->aprecieriPostari = nullptr;

    }

    ProfilInfluencer& operator =(ProfilInfluencer& pi){
        numeCont = pi.numeCont; 
        numarPostari = pi.numarPostari;

        if (pi.numarPostari > 1000)
            this->numarUrmaritori = pi.numarUrmaritori;
        else
            this->numarUrmaritori = 0;

        if (pi.aprecieriPostari != nullptr && pi.numarPostari != 0) {
            this->aprecieriPostari = new int[pi.numarPostari];
            for (int i = 0; i < pi.numarPostari; i++)
                this->aprecieriPostari[i] = pi.aprecieriPostari[i];
        }
        else
            this->aprecieriPostari = nullptr;
        return *this;
    }



    //setter
    void setNumeCont(string nume) {
        numeCont = nume;
    }

    void setNumarUrmaritori(long int nr) {
        if(nr > 1000)
        numarUrmaritori = nr;
    }

    //getter
    string getNumeCont() {
        return numeCont;
    }

    long int getNumarUrmaritori() {
        return numarUrmaritori;
    }

    void adaugaPostare(int aprecieri) {
        numarPostari += 1;
        int* copie = new int[numarPostari];
        for (int i = 0; i < numarPostari - 1; i++)
            copie[i] = aprecieriPostari[i];
        copie[numarPostari - 1] = aprecieri;
        delete[] aprecieriPostari;
        aprecieriPostari = new int[numarPostari];
        aprecieriPostari = copie; 
    }

    friend ostream& operator <<(ostream& out, ProfilInfluencer& pi) {
        out << "Nume cont: " << pi.numeCont << endl;
        out << "Numar urmaritori: " << pi.numarUrmaritori << endl;
        out << "Numar postari:" << pi.numarPostari << endl;
        out << "Aprecieri pe postare: ";
        for (int i = 0; i < pi.numarPostari; i++)
            out << pi.aprecieriPostari[i] << " ";
        out << endl;
        return out;
    }

    friend istream& operator >>(istream& in, ProfilInfluencer& pi) {
        cout << "Nume cont: ";
        in >> pi.numeCont;
        cout << "Numar urmaritori: ";
        in >> pi.numarUrmaritori;
        if (pi.numarUrmaritori <= 1000)
            pi.numarUrmaritori = 0;
        cout << "Numar postari:";
        in >> pi.numarPostari;
        cout << "Aprecieri pe postare: " << endl;
        delete[] pi.aprecieriPostari;
        pi.aprecieriPostari = new int[pi.numarPostari];
        for (int i = 0; i < pi.numarPostari; i++) {
            cout << "Postarea " << i << ": ";
            in >> pi.aprecieriPostari[i];
        }
        return in;
    }

    friend bool operator <(ProfilInfluencer p1, ProfilInfluencer p2) {
        return p1.numarUrmaritori < p2.numarUrmaritori;
    }

    operator int() {
        int sum = 0;
        for (int i = 0; i < numarPostari; i++)
            sum += aprecieriPostari[i];
        return sum;
    }

    int operator[](int i) {
        return aprecieriPostari[i];
    }
    ~ProfilInfluencer() {
        delete[] aprecieriPostari;
    }
};

int main()
{
    int aprecieri1[] = { 10, 20 }, aprecieri2[] = { 240, 80 ,50 };
    ProfilInfluencer P1("Yogi", 1200, 2, aprecieri1), P2;
    
    cout << P1.getNumeCont() << endl;
    cout << P1.getNumarUrmaritori() << endl;
    cout << endl;
    
    cout << (P2 < P1) << endl;
    cout << (int)P1 << endl;
    cout << P1[0];
    

    /*P2.setNumeCont("Yogi2");
    P2.setNumarUrmaritori(100000);
    cout << P2.getNumeCont() << endl;
    cout << P2.getNumarUrmaritori() << endl;*/

}

