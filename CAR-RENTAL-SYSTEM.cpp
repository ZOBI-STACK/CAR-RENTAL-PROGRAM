#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct luxuryCarDetails {
    string luxury[5] = {"BMW", "Audi", "Mercedes", "Lexus", "Jaguar"};
    string luxuryname[5] = {"i8", "etron", "C 180", "lX 570", "F-PACE"};
    int luxuryprice[5] = {15000, 15000, 10000, 20000, 12000};
};

struct basicCarDetails {
    string basic[5] = {"Toyota", "Honda", "Hyundai", "Suzuki", "Nissan"};
    string basicname[5] = {"Grande", "Civic", "Elantra", "Wagon R", "NOTE"};
    int basicprice[5] = {5000, 6000, 7000, 4000, 6000};
};

void Details(int choice) {
    luxuryCarDetails luxuryCars;
    basicCarDetails basicCars;

    if (choice == 1) {
        cout << "\n\t\t\tLuxury Cars Available:\n";
        for (int i = 0; i < 5; ++i) {
            cout << "\t\t\t" << i + 1 << ". " << luxuryCars.luxury[i] << " - " << luxuryCars.luxuryname[i] << " (Rs " << luxuryCars.luxuryprice[i] << ")\n";
        }
    } else if (choice == 2) {
        cout << "\n\t\t\tBasic Cars Available:\n";
        for (int i = 0; i < 5; ++i) {
            cout << "\t\t\t" << i + 1 << ". " << basicCars.basic[i] << " - " << basicCars.basicname[i] << " (Rs " << basicCars.basicprice[i] << ")\n";
        }
    } else {
        cout << "\n\t\t\tInvalid choice!\n";
    }
}

int carSelection(int carnum, int userchoice) {
    luxuryCarDetails luxuryCars;
    basicCarDetails basicCars;
    ofstream file;
    file.open("invoice.txt", ios::app);

    int carprice = 0;
    if (userchoice == 1) {
        carnum -= 1;
        cout << "\t\t\tMake: " << luxuryCars.luxury[carnum] << endl;
        cout << "\t\t\tModel: " << luxuryCars.luxuryname[carnum] << endl;
        cout << "\t\t\tRent per day: Rs " << luxuryCars.luxuryprice[carnum] << endl;
        file << "\t\t\tMake: " << luxuryCars.luxury[carnum] << endl;
        file << "\t\t\tModel: " << luxuryCars.luxuryname[carnum] << endl;
        file << "\t\t\tRent per day: Rs " << luxuryCars.luxuryprice[carnum] << endl;
        carprice = luxuryCars.luxuryprice[carnum];
    } else if (userchoice == 2) {
        carnum -= 1;
        cout << "\t\t\tMake: " << basicCars.basic[carnum] << endl;
        cout << "\t\t\tModel: " << basicCars.basicname[carnum] << endl;
        cout << "\t\t\tRent per day: Rs " << basicCars.basicprice[carnum] << endl;
        file << "\t\t\tMake: " << basicCars.basic[carnum] << endl;
        file << "\t\t\tModel: " << basicCars.basicname[carnum] << endl;
        file << "\t\t\tRent per day: Rs " << basicCars.basicprice[carnum] << endl;
        carprice = basicCars.basicprice[carnum];
    } else {
        cout << "\t\t\tInvalid choice!";
    }
    file.close();
    return carprice;
}

int rentaldays(int carprice, int days) {
    int totalrent = carprice * days;
    cout << "\t\t\tThe total rent for " << days << " days is: Rs " << totalrent << endl;
    return totalrent;
}

void pickupdate(int date, int month, int year) {
    ofstream file;
    file.open("invoice.txt", ios::app);
    cout << "\n\n\t\t\tThe date scheduled for pickup is: " << date << "-" << month << "-" << year << endl;
    file << "\n\n\t\t\tThe date scheduled for pickup is: " << date << "-" << month << "-" << year << endl;
    file.close();
}

void chaufferservice(int& chaufferbill, int days) {
    ofstream file;
    file.open("invoice.txt", ios::app);
    chaufferbill *= days;
    cout << "\n\n\t\t\tThe bill for chauffer for " << days << " days is: Rs " << chaufferbill << endl;
    file << "\n\n\t\t\tChauffer bill: Rs " << chaufferbill << endl;
    file.close();
}

void totalbillinvoice(int totalbill) {
    cout << "\n\n\t\t\t************************************************************" << endl;
    ofstream file;
    file.open("invoice.txt", ios::app);
    file << "\n\n\t\t\tTotal bill: Rs " << totalbill << endl;
    file.close();
}

void couponcode(int& totalbill) {
    cout << "\n\n\t\t\t************************************************************" << endl;
    string couponcode;
    cout << "\n\t\t\tEnter coupon code, if no coupon code enter NO: ";
    cin >> couponcode;
    if (couponcode == "venom") {
        ofstream file;
        file.open("invoice.txt", ios::app);
        int discount = totalbill * 20 / 100;
        cout << "\n\t\t\tTotal discount: Rs " << discount << endl;
        file << "\n\t\t\tTotal discount: Rs " << discount << endl;
        totalbill -= discount;
        cout << "\n\t\t\tThe total bill after 20% discount is: Rs " << totalbill << endl;
        file << "\n\t\t\tThe total bill after 20% discount is: Rs " << totalbill << endl;
        file.close();
    }
}

void printinvoice(const string& filename) {
    cout << "\n\n\t\t\t************************************************************" << endl;
    ifstream file(filename);
    string line;
    cout << "\t\t\tContents of " << filename << ":\n";
    while (getline(file, line)) {
        cout << line << "\n";
    }
    file.close();
}

int main() {
    cout << "\t\t\t----------------------------------------------\n";
    cout << "\t\t\t\tSIMPLE CAR RENTAL SYSTEM \n";
    cout << "\t\t\tWelcome to Our Company, Choose a Car Category:\n";
    cout << "\t\t\t----------------------------------------------\n";
    cout << "\t\t\t1 - Luxury Cars\n";
    cout << "\t\t\t2 - Basic Cars\n";

    string decide = "yes";
    while (decide != "no") {
        int categoryChoice;
        cout << "\n\n\t\t\tEnter Your Choice: ";
        cin >> categoryChoice;

        Details(categoryChoice);

        int carNo, day, carprice, totalrent;
        cout << "\n\n\t\t\tSelect the car you want: ";
        cin >> carNo;

        carprice = carSelection(carNo, categoryChoice);
        if (carprice == -1) continue;

        cout << "\n\t\t\tHow many days do you want the car for? ";
        cin >> day;

        totalrent = rentaldays(carprice, day);

        int date, month, year;
        cout << "\n\n\t\t\tSchedule a date for car pickup:\n";
        cout << "\t\t\tEnter date: ";
        cin >> date;
        cout << "\t\t\tEnter month: ";
        cin >> month;
        cout << "\t\t\tEnter year: ";
        cin >> year;
        pickupdate(date, month, year);

        int chaufferbill = 2000;
        string des;
        cout << "\n\n\t\t\tDo you want chauffer services (Rs 2000/day)? yes/no: ";
        cin >> des;
        if (des == "yes") {
            chaufferservice(chaufferbill, day);
        } else {
            chaufferbill = 0;
        }

        int totalbill = totalrent + chaufferbill;
        totalbillinvoice(totalbill);

        string filename = "invoice.txt";
        printinvoice(filename);

        couponcode(totalbill);
        totalbillinvoice(totalbill);  // Print the total bill again after applying the coupon

        cout << "\n\n\t\t\tDo you want to continue? (yes/no): ";
        cin >> decide;

        for (int i = 0; i < 5; ++i) {
            cout << "\n";
        }
    }

    return 0;
}
