#include <iostream>
using namespace std;

class TrotinetaElectrica {
private:
    string model;
    float nivelBaterie;
    const float consumPerKm;
    float* kmPerSesiuneIncarcare;
    int nrSesiuniInchiriere;
    static int NIVEL_MAXIM_BATERIE;
public:
    TrotinetaElectrica()
        :model(""), nivelBaterie(0), consumPerKm(0), nrSesiuniInchiriere(0), kmPerSesiuneIncarcare(nullptr) {
    }

    TrotinetaElectrica(string model, float nivelBaterie, const float consumPerKm, float* kmPerSesiuneIncarcare, int nrSesiuniInchiriere)
        : model(model), nivelBaterie(nivelBaterie), consumPerKm(consumPerKm), nrSesiuniInchiriere(nrSesiuniInchiriere) {
        if (this->kmPerSesiuneIncarcare != nullptr)
            delete[] this->kmPerSesiuneIncarcare;
        if (kmPerSesiuneIncarcare != nullptr && nrSesiuniInchiriere != 0) {
            this->kmPerSesiuneIncarcare = new float[nrSesiuniInchiriere];
            for (int i = 0; i < nrSesiuniInchiriere; i++)
                this->kmPerSesiuneIncarcare[i] = kmPerSesiuneIncarcare[i];
        }
        else
            this->kmPerSesiuneIncarcare = nullptr;
    }

    TrotinetaElectrica(const TrotinetaElectrica& T)
        : model(T.model), nivelBaterie(T.nivelBaterie), consumPerKm(T.consumPerKm), nrSesiuniInchiriere(T.nrSesiuniInchiriere) {
        if (this->kmPerSesiuneIncarcare != nullptr)
            delete[] this->kmPerSesiuneIncarcare;
        if (T.kmPerSesiuneIncarcare != nullptr && T.nrSesiuniInchiriere != 0) {
            this->kmPerSesiuneIncarcare = new float[T.nrSesiuniInchiriere];
            for (int i = 0; i < T.nrSesiuniInchiriere; i++)
                this->kmPerSesiuneIncarcare[i] = T.kmPerSesiuneIncarcare[i];
        }
        else
            this->kmPerSesiuneIncarcare = nullptr;
    }

    TrotinetaElectrica& operator =(const TrotinetaElectrica& T) {
        model = T.model;
        nivelBaterie = T.nivelBaterie;
        nrSesiuniInchiriere = T.nrSesiuniInchiriere;
        if (T.kmPerSesiuneIncarcare != nullptr && T.nrSesiuniInchiriere != 0) {
            this->kmPerSesiuneIncarcare = new float[T.nrSesiuniInchiriere];
            for (int i = 0; i < T.nrSesiuniInchiriere; i++)
                this->kmPerSesiuneIncarcare[i] = T.kmPerSesiuneIncarcare[i];
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, TrotinetaElectrica& T) {
        out << T.model << " " << T.nivelBaterie << " " << T.consumPerKm << " " << T.nrSesiuniInchiriere;
        return out;

    }

    friend istream& operator>>(istream& in, TrotinetaElectrica& T) {
        in >> T.model >> T.nivelBaterie >> T.nrSesiuniInchiriere;
        return in;

    }

    friend TrotinetaElectrica operator +(float n ,TrotinetaElectrica T) {
        TrotinetaElectrica R;
        T.nrSesiuniInchiriere += 1;
        float* copie = new float[T.nrSesiuniInchiriere];
        for (int i = 0; i < T.nrSesiuniInchiriere-1; i++)
            copie[i] = T.kmPerSesiuneIncarcare[i];
        copie[T.nrSesiuniInchiriere - 1] = n;
        delete[] T.kmPerSesiuneIncarcare;
        T.kmPerSesiuneIncarcare = new float[T.nrSesiuniInchiriere];
        T.kmPerSesiuneIncarcare = copie;
        return R;
    }

    ~TrotinetaElectrica() {
        delete[] kmPerSesiuneIncarcare;
    }

    void utilizareTrotineta(int km) {
        nrSesiuniInchiriere += 1;
        float* copie = new float[nrSesiuniInchiriere];
        for (int i = 0; i < nrSesiuniInchiriere - 1; i++)
            copie[i] = kmPerSesiuneIncarcare[i];
        copie[nrSesiuniInchiriere - 1] = km;
        delete[] kmPerSesiuneIncarcare;
        kmPerSesiuneIncarcare = new float[nrSesiuniInchiriere];
        kmPerSesiuneIncarcare = copie;
    }

    int operator ()(int a, int b) {
        int sum = 0;
        for (int i = a; i < b; i++)
            sum += kmPerSesiuneIncarcare[i];
        return sum; 
    }



    //getter
    string getModel() {
        return model;
    }

    int getSesiuniInchiriere() {
        return nrSesiuniInchiriere;
    }

    float getNivelBaterie() {
        return nivelBaterie;
    }
};

int main()
{
    // Test default constructor
    TrotinetaElectrica trotineta1;

    // Test parameterized constructor
    float kmPerSesiune1[] = { 10, 15, 20 };
    TrotinetaElectrica trotineta2("Model1", 80.0, 0.5, kmPerSesiune1, 3);
    trotineta2 = 10 + trotineta2;
    cout << trotineta2(0, 3) << endl;

    // Test copy constructor
    TrotinetaElectrica trotineta3 = trotineta2;

    // Test assignment operator
    TrotinetaElectrica trotineta4;
    trotineta4 = trotineta2;

    // Test utilization of the trotineta
    trotineta2.utilizareTrotineta(5);
    trotineta2.utilizareTrotineta(8);

    // Test overloaded function call operator
    int totalKm = trotineta2(0, trotineta2.getSesiuniInchiriere());
    cout << "Total kilometers used: " << totalKm << " km" << endl;

    // Test getter methods
    cout << "Model: " << trotineta2.getModel() << endl;
    cout << "Number of rental sessions: " << trotineta2.getSesiuniInchiriere() << endl;
    cout << "Battery level: " << trotineta2.getNivelBaterie() << "%" << endl;

    // Test input and output operators
    cout << "Enter details for a trotineta: ";
    cin >> trotineta1;
    cout << "Details entered: " << trotineta1 << endl;

    return 0;
}