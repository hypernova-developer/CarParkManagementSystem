#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
#include <locale>
#include <clocale>

using namespace std;

int getConclusion(int value1, int value2, int value3)
{
    int conclusion;
    conclusion = value1 + value2 - value3;
    return conclusion;
}

void mainFunction()
{
    ofstream file;
    file.open("bill.txt", ios::app);

    ofstream file2;
    file2.open("CarParkManagementSystem.txt", ios::app);

    cin.ignore();

    const int password = 123456789;
    const int daysperweek = 7;
    const int hoursperday = 24;
    const int maxCapacity = 100;
    const int minVehicleCount = 0;
    int gottenPassword = 0;
    int price = 0;
    int enteredcar = 0;
    int quittedcar = 0;
    int carcount = 0;
    int systemMode = 0;
    float timeSpent = 0.00;
    bool continue01 = false;
    string plate = "XX XXX XX";

    cout << "Parkplatzverwaltungssystem" << endl;

    while (true)
    {
        cout << "Bitte geben Sie das Passwort für Benutzer-1 ein:" << endl;
        cin >> gottenPassword;

        if (gottenPassword == password)
            break;
        else
            cout << "Falsches Passwort. Bitte erneut versuchen." << endl;
    }

    while (true)
    {
        cout << "Bitte wählen Sie den Systemmodus:\n"
             << "1 - Abrechnungssystem\n"
             << "2 - Parkplatzverwaltungssystem\n"
             << "3 - Beenden" << endl;
        cin >> systemMode;

        if (systemMode == 3)
            break;

        switch (systemMode)
        {
            case 1:
            cout << "Preisliste nach Parkdauer:" << endl;
            cout << "1 Stunde oder weniger => Kostenlos\n"
                 << "1-2 Stunden => 5 USD\n"
                 << "2-3 Stunden => 7 USD\n"
                 << "3-4 Stunden => 10 USD\n"
                 << "4-5 Stunden => 15 USD\n"
                 << "Mehr als 5 Stunden => 20 USD\n";

            while (true)
            {
                cout << "Bitte geben Sie das Kennzeichen des Fahrzeugs ein:" << endl;
                cin >> plate;

                cout << "Bitte geben Sie die Parkdauer ein (Format X.XX):" << endl;
                cin >> timeSpent;

                if (timeSpent < 1.00)
                    price = 0;
                else if (timeSpent < 2.00)
                    price = 5;
                else if (timeSpent < 3.00)
                    price = 7;
                else if (timeSpent < 4.00)
                    price = 10;
                else if (timeSpent < 5.00)
                    price = 15;
                else
                    price = 20;

                file << "Fahrzeug: " << plate
                     << "\nPreis: " << price << " USD\n\n";

                cout << "Möchten Sie fortfahren? (1 = Ja, 0 = Nein)" << endl;
                cin >> continue01;

                if (!continue01)
                {
                    cout << "Vorgang beendet." << endl;
                    Sleep(200);
                    cout << "Rechnung wurde erfolgreich gespeichert." << endl;
                    break;
                }
            }
            break;

            case 2:
            for (int i = 0; i < daysperweek; i++)
            {
                for (int j = 0; j < hoursperday; j++)
                {
                    while (true)
                    {
                        cout << "Stunde " << j + 1
                             << ": Anzahl der eingefahrenen Fahrzeuge:" << endl;
                        cin >> enteredcar;

                        if (enteredcar < minVehicleCount || enteredcar > maxCapacity)
                        {
                            cout << "Ungültiger Wert." << endl;
                            continue;
                        }

                        cout << "Stunde " << j + 1
                             << ": Anzahl der ausgefahrenen Fahrzeuge:" << endl;
                        cin >> quittedcar;

                        if (quittedcar < minVehicleCount || quittedcar > maxCapacity)
                        {
                            cout << "Ungültiger Wert." << endl;
                            continue;
                        }

                        carcount = getConclusion(carcount, enteredcar, quittedcar);

                        cout << "Aktuelle Fahrzeuge im Parkplatz: "
                             << carcount << endl;

                        file2 << "Tag " << i + 1
                              << " - Stunde " << j + 1
                              << " - Fahrzeuge: " << carcount << endl;

                        if (carcount == 0)
                            cout << "Der Parkplatz ist leer." << endl;
                        else if (carcount >= maxCapacity)
                            cout << "Der Parkplatz ist voll." << endl;
                        else if (carcount >= maxCapacity * 0.75)
                            cout << "Der Parkplatz ist fast voll." << endl;
                        else if (carcount >= maxCapacity / 2)
                            cout << "Der Parkplatz ist zur Hälfte belegt." << endl;

                        Sleep(300);
                        break;
                    }
                }

                cout << "Tag " << i + 1
                     << " abgeschlossen. Verbleibende Fahrzeuge: "
                     << carcount << endl;
            }
            break;
        }
    }

    file.close();
    file2.close();
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "German");

    system("color 0A");
    Sleep(300);

    mainFunction();

    system("pause");
    return 0;
}
