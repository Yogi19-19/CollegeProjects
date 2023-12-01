#include <iostream>

using namespace std;

class Fractie {
private:
    int numarator, numitor;
public:
    void afiseaza() 
    {
        cout << numarator << "/" << numitor << endl;
    }
    Fractie(int a = 0, int b = 1) 
    {
        if (b < 0)
            a = -a, b = -b;
        numarator = a, numitor = b;
    }
    Fractie operator+ (Fractie F)
    {  
        Fractie R;
        R.numarator = numarator * F.numitor + numitor * F.numarator;
        R.numitor = numitor * F.numitor;
        return R;
    }
    friend Fractie operator+ (int n, Fractie F)
    {   
        Fractie R;
        R.numarator = F.numarator + n * F.numitor;
        R.numitor = F.numitor;
        return R;
    }
    Fractie operator + (int n)
    {  
        Fractie R;
        R.numarator = numarator + n * numitor;
        R.numitor = numitor;
        return R;
    }
};

int main() {
    Fractie X(1, 4), Y(2, 3);
    Fractie R = X + Y;
    R.afiseaza();
    R = X + 2;
    R.afiseaza();
    R = 2 + X;
    R.afiseaza();
    return 0;
}
