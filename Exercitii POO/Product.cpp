#include <iostream>
#include <string.h>

using namespace std;

class Product
{
    int id;
    char* name;
    char* description;
    double price;
    double* priceHistory;
    int priceHistorySize;

public:
    Product(int id, const char* name, const char* description, double price, const double* priceHistory, int priceHistorySize)
        : id(id), price(price), priceHistorySize(priceHistorySize) {
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);

        this->description = new char[strlen(description) + 1];
        strcpy_s(this->description, strlen(description) + 1, description);


        this->priceHistory = new double[priceHistorySize + 1];
        for (int i = 0; i < priceHistorySize; i++) {
            this->priceHistory[i] = priceHistory[i];
        }

        this->priceHistory[priceHistorySize++] = price;
        this->priceHistorySize++;
    }

    Product(const Product& otherProduct)
        : id(otherProduct.id), price(otherProduct.price), priceHistorySize(otherProduct.priceHistorySize)
    {
        name = new char[strlen(otherProduct.name) + 1];
        strcpy_s(name, strlen(otherProduct.name) + 1, otherProduct.name);

        description = new char[strlen(otherProduct.description) + 1];
        strcpy_s(description, strlen(otherProduct.description) + 1, otherProduct.description);

        priceHistory = new double[priceHistorySize];
        for (int i = 0; i < priceHistorySize; i++) {
            priceHistory[i] = otherProduct.priceHistory[i];
        }
    }

    //all setters

    void setPrice(double newPrice) {
        double* newHistory = new double[priceHistorySize + 1];
        for (int i = 0; i < priceHistorySize; i++) {
            newHistory[i] = priceHistory[i];
        }
        newHistory[priceHistorySize++] = newPrice; 
        delete[] priceHistory;
        priceHistory = newHistory;
        price = newPrice;
    }

    //all getters

    int getId() { 
        return this->id; }
    char* getName(){ 
        return this->name; }
    char* getDescription() { 
        return this->description; }
    double getPrice() { 
        return this->price; }
    double* getPriceHistory() { 
        return this->priceHistory; }
    int getPriceHistorySize() {
        return this->priceHistorySize;
    }
    

    double getPriceAverage() const {
        double sum = 0.0;
        for (int i = 0; i < priceHistorySize; i++) {
            sum += priceHistory[i];
        }
        return (priceHistorySize > 0) ? sum / priceHistorySize : 0;
    }

    ~Product(){
        delete[] this->name;
        delete[] this->description;
        delete[] this->priceHistory;
    }
};

int main() {
    double priceHistory[] = {1};
    string name, description;
    int pret, newPrice, id;

    cout << "Id produs: ";
    cin >> id;

    cout << "Nume produs: ";
    cin >> name;
    char* name_ptr = new char[name.length() + 1];
    strcpy_s(name_ptr, name.length() + 1, name.c_str());

    cout << "Descriere produs: ";
    cin >> description;
    char* description_ptr = new char[description.length() + 1];
    strcpy_s(description_ptr, description.length() + 1, description.c_str());

    cout << "Pret produs: ";
    cin >> pret;

    Product product(id, (char*)name_ptr, (char*)description_ptr, pret, (double*)priceHistory, 0);
    delete[] name_ptr;
    delete[] description_ptr;

    

    do{
        cout << "Schimba pretul(0 ca sa inchizi): ";
        cin >> newPrice;
        if(newPrice != 0)
            product.setPrice(newPrice);
    } while (newPrice != 0);
    
    cout << "Id:" << product.getId() << endl;

    cout << "Nume: " << product.getName() << endl;

    cout << "Description: " << product.getDescription() << endl;

    cout << "Pret: " << product.getPrice() << endl;

    cout << "Istoric:" << endl;
    for (int i = 0; i < product.getPriceHistorySize(); i++) {
        cout << product.getPriceHistory()[i] << " ";
    }
    cout << endl;

    cout << "Marime istoric: " << product.getPriceHistorySize() << endl;

    cout << "Media preturilor: " << product.getPriceAverage();


}