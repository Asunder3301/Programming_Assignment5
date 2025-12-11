//Miguel Bautista
//CISP 1010-W01
//Programming Assignment 5
//27 October 2025
//Description: 
#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
void printMenu();
double getPrice();
bool priceInvalid(double price);
void printInfo(double total, double counter);

int main() {
    //Variables
    int choice;
    double price, counter = 0, total = 0;
    bool quit = false;

    do {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            price = getPrice(); 
            counter++;
            total += price;
            break;
        case 2:
            quit = true;
            break;
        default:
            cout << "Enter 1 or 2" << endl;
            break;
        }
    } while (!quit);

    printInfo(total, counter);
    return 0;
}

void printMenu() {
    cout << "1.Enter another item" << endl;
    cout << "2.Quit" << endl;
}

double getPrice() {
    double price;
    do {
        cout << "Enter the amount for the item: ";
        cin >> price;
        if (priceInvalid(price)) {
            cout << "Invalid amount. Must be greater than 0" << endl;
        }
    } while (priceInvalid(price));
    return price;
}

bool priceInvalid(double price) {
    return price <= 0;
}

void printInfo(double total, double counter) {
    cout << "You purchased " << counter << " items" << endl;
    cout << "The total for this purchase is $" << fixed << setprecision(2) << total << " before tax" << endl;

    if (counter > 0) {
        cout << "The average amount per item for this purchase was $" << fixed << setprecision(2) << (total / counter) << endl;
    }
    else {
        cout << "No items were purchased." << endl;
    }
}