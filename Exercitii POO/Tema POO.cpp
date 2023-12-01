
#include <iostream>
#include <string.h>
using namespace std;

class Product {

private:
    string name;
    int price, priceHistory, numberOfPrices;
    float sumOfPrices;

public:
    Product() {

    }

    Product(string name, int price) {
        this->name = name;
        this->price = price;
        this->priceHistory = price;
        this->sumOfPrices = price;
        this->numberOfPrices = 1;
    }

    Product(const Product& product) {
    
    }

    //Setter
    void newPrice(int newPrice) {
        sumOfPrices += newPrice;
        numberOfPrices += 1;
        priceHistory = price;
        price = newPrice;
    }

    //Getter
    int getPrice() {
        return price;
    }

    float averageOfPrices() {
        return sumOfPrices / numberOfPrices;
    }

    ~Product() {
        cout << "Stergere completa" << endl;
    }

    };

int main()
{
    string productName;
    int productPrice;

    cout << "Introdu numele unui produs: ";
    cin >> productName;
    cout << "Introdu pretul produsului: ";
    cin >> productPrice;
    cout << "Ai ales produsul " << productName << " cu pretul de " << productPrice << " lei.\n\n";

    Product product(productName, productPrice);

    cout << "Introdu un nou pret pentru produs (0 ca sa inchizi): ";
    cin >> productPrice;

    while (productPrice != 0){
        product.newPrice(productPrice);
        cout << "Introdu un nou pret pentru produs (0 ca sa inchizi): ";
        cin >> productPrice;
    }

    cout << "\nUltimul pret pentru " << productName << " este de " << product.getPrice() << " lei.\n\n";

    Product productCopy;
    productCopy = product;

    cout << "Media aritmetica a preturilor produsului din productCopy este " << productCopy.averageOfPrices() << " lei.\n\n";
}


