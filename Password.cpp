#include <iostream>
#include <fstream>

using namespace std;

int main() {
    while (true) {
        int choice, i;
        int users[100];
        int passwords[100];

        ifstream BD("BD.txt");

        for (i = 0; true; i++) {
            BD >> users[i] >> passwords[i];
            if (BD.eof()) break;
        }

        BD.close();

        cout << "All bd:" << endl;
        for (int j = 0; j < i; j++) {
            cout << users[j] << " - " << passwords[j] << endl;
        } cout << endl;

        cout << "[1]register\n[2]login\n - ";
        cin >> choice;

        if (choice == 1) {
            int login, password, j;
            do {
                cout << "Enter you login - ";
                cin >> login;

                for (j = 0; j < i; j++) {
                    if (login == users[j]) break;
                }if (login != users[j]) break;

                cout << "this login is wrong!" << endl;

            } while (true);

            do {
                cout << "Enter you password - ";
                cin >> password;
                int pass = password, len;

                for (len = 0; pass > 0; len++) {
                    pass /= 10;
                }

                if (len > 4 && len < 12) break;

                cout << "this password is wronng!" << endl;

            } while (true);

            ofstream BD("BD.txt", ios::app);
            BD << login << " " << password << endl;
            BD.close();
        }

        if (choice == 2) {
            int login, password;
            int j;

            do {
                cout << "Enter you login - ";
                cin >> login;

                for (j = 0; j < i; j++) {
                    if (login == users[j]) break;
                } if (login == users[j]) break;

                cout << endl << "this login is wrong!" << endl;
            } while (true);

            do {
                cout << "Enter you password - ";
                cin >> password;

                if (password == passwords[j]) break;

                cout << endl << "this password is wrong!" << endl;
            } while (true);

            cout << "succeful login!" << endl;
            break;

        }
    }
}
