//Name: Mohammad Kamal Sarwari
//ID: 05178353
//Project: Room Reservation - Multidimensional Array  

#include <iostream>
#include <iomanip>
using namespace std;

void p(string arr[][5], int r) {
    for (int i = 0; i < r; i++) {
        cout << left;
        cout << setw(10) << "Floor Number " << i + 1 << ": ";
        for (int j = 0; j <5; j++) {
            cout << setw(10) << arr[i][j] << "      ";
        }
        cout << endl;
    }
}

int main() {
    string re_selection = "y";
    string loop = "y";
    bool stop = false;
    int fr, rm;
    string ap[10][5];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            ap[i][j] = to_string(j+1);
        }
    }

    main_loop:
    while (loop == "y") {
        cout << "Hello, welcome to Five Star Hotel." << endl;
        cout << "Pls check the menu for reservation of our rooms" << endl << endl;

        p(ap, 10);

        cout << endl;
        cout << "Floor Number: ";
        cin >> fr;
        cout << "room Number: ";
        cin >> rm;

        for (int i = 0; i < 2 && stop != true; i++) {
            for (int j = 0; j < 3; j++) {
                if (ap[fr-1][rm-1] == "Reserved") {
                    cout << "Sorry the floor " << fr << " room " << rm << " already exists." << endl;
                    cout << "Do you want to reserve another roo?(y/n): ";
                    cin >> re_selection;
                        if (re_selection == "y") {
                            goto main_loop;
                        }else {
                            continue;
                        }
                    stop = true;
                    break;
                }else {
                    ap[fr-1][rm-1] = "Reserved";
                    cout << "Congrats the floor " << fr << " room " << rm << " is reserved successfully!!!" << endl;
                    stop = true;
                    break;
                }
            }
        }


        p(ap, 10);
        cout << endl;
        cout << "Do you want to continue reservation?(y/n): ";
        cin >> loop;
        stop = false;
    }
}

