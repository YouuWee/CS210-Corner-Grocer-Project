/*
Developer: Yuvraj Sharma
Date: April 5, 2026
Purpose: Grocery Tracking Program
*/

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

class GroceryTracker {
private:
    map<string, int> itemFrequency;

public:
    void loadData() {
        ifstream inFile("CS210_Project_Three_Input_File.txt");
        string item;
        while (inFile >> item) {
            itemFrequency[item]++;
        }
        inFile.close();
    }

    void createBackupFile() {
        ofstream outFile("frequency.dat");
        for (auto& pair : itemFrequency) {
            outFile << pair.first << " " << pair.second << endl;
        }
        outFile.close();
    }

    void searchItem() {
        string item;
        cout << "Enter item: ";
        cin >> item;
        cout << item << " " << itemFrequency[item] << endl;
    }

    void printAll() {
        for (auto& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    void histogram() {
        for (auto& pair : itemFrequency) {
            cout << pair.first << " ";
            for (int i = 0; i < pair.second; i++) cout << "*";
            cout << endl;
        }
    }
};

int main() {
    GroceryTracker g;
    g.loadData();
    g.createBackupFile();

    int choice;
    do {
        cout << "\n1.Search\n2.Display\n3.Histogram\n4.Exit\n";
        cin >> choice;

        if (choice == 1) g.searchItem();
        else if (choice == 2) g.printAll();
        else if (choice == 3) g.histogram();

    } while (choice != 4);

    return 0;
}
