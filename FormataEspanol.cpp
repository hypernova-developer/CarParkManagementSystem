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

    cout << "Sistema de Gestión de Estacionamiento" << endl;

    while (true)
    {
        cout << "Ingrese la contraseña para el usuario-1:" << endl;
        cin >> gottenPassword;

        if (gottenPassword == password)
            break;
        else
            cout << "Contraseña incorrecta. Intente nuevamente." << endl;
    }

    while (true)
    {
        cout << "Seleccione el modo del sistema:\n"
             << "1 - Sistema de facturación\n"
             << "2 - Sistema de gestión del estacionamiento\n"
             << "3 - Salir" << endl;
        cin >> systemMode;

        if (systemMode == 3)
            break;

        switch (systemMode)
        {
            case 1:
            cout << "Tarifas por tiempo de permanencia:" << endl;
            cout << "1 hora o menos => Gratis\n"
                 << "1-2 horas => 5 USD\n"
                 << "2-3 horas => 7 USD\n"
                 << "3-4 horas => 10 USD\n"
                 << "4-5 horas => 15 USD\n"
                 << "Más de 5 horas => 20 USD\n";

            while (true)
            {
                cout << "Ingrese la matrícula del vehículo:" << endl;
                getline(cin, plate);

                cout << "Ingrese el tiempo de permanencia (formato X.XX):" << endl;
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

                file << "Vehículo: " << plate << "\nPrecio: " << price << " USD\n\n";

                cout << "¿Desea continuar? (1 = Sí, 0 = No)" << endl;
                cin >> continue01;

                if (!continue01)
                {
                    cout << "Proceso finalizado." << endl;
                    Sleep(200);
                    cout << "Factura guardada correctamente." << endl;
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
                        cout << "Hora " << j + 1 << ": Vehículos que ingresaron:" << endl;
                        cin >> enteredcar;

                        if (enteredcar < minVehicleCount || enteredcar > maxCapacity)
                        {
                            cout << "Valor inválido." << endl;
                            continue;
                        }

                        cout << "Hora " << j + 1 << ": Vehículos que salieron:" << endl;
                        cin >> quittedcar;

                        if (quittedcar < minVehicleCount || quittedcar > maxCapacity)
                        {
                            cout << "Valor inválido." << endl;
                            continue;
                        }

                        carcount = getConclusion(carcount, enteredcar, quittedcar);

                        cout << "Vehículos actuales en el estacionamiento: "
                             << carcount << endl;

                        file2 << "Día " << i + 1
                              << " - Hora " << j + 1
                              << " - Vehículos: " << carcount << endl;

                        if (carcount == 0)
                            cout << "El estacionamiento está vacío." << endl;
                        else if (carcount >= maxCapacity)
                            cout << "El estacionamiento está lleno." << endl;
                        else if (carcount >= maxCapacity * 0.75)
                            cout << "El estacionamiento está casi lleno." << endl;
                        else if (carcount >= maxCapacity / 2)
                            cout << "La mitad del estacionamiento está ocupada." << endl;

                        Sleep(300);
                        break;
                    }
                }

                cout << "Día " << i + 1
                     << " finalizado. Vehículos restantes: "
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
    setlocale(LC_ALL, "Spanish");

    system("color 0A");
    Sleep(300);

    mainFunction();

    system("pause");
    return 0;
}
