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
    file.open("fatura.txt", ios::app);

    ofstream file2;
    file2.open("OtoparkYonetimSistemi.txt", ios::app);

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

    cout << "OTOPARK YÖNETİM SİSTEMİ" << endl;

    while (true)
    {
        cout << "Kullanıcı-1 için şifreyi giriniz: " << endl;
        cin >> gottenPassword;

        if (gottenPassword == password)
        {
            break;
        }
        else
        {
            cout << "Hatalı şifre. Lütfen tekrar deneyiniz." << endl;
        }
    }

    while (true)
    {
        cout << "Sistem modunu seçiniz." << endl;
        cout << "1: Faturalandırma Sistemi" << endl;
        cout << "2: Otopark Yönetim Sistemi" << endl;
        cout << "3: Çıkış" << endl;
        cin >> systemMode;

        if (systemMode == 3)
        {
            break;
        }

        switch (systemMode)
        {
            case 1:
                cout << "Otopark Ücretlendirme Tarifesi:" << endl;
                cout << "1 saat veya daha az => Ücretsiz\n";
                cout << "1-2 saat => 5 USD\n";
                cout << "2-3 saat => 7 USD\n";
                cout << "3-4 saat => 10 USD\n";
                cout << "4-5 saat => 15 USD\n";
                cout << "5 saatten fazla => 20 USD\n";

                while (true)
                {
                    cout << "Araç plakası giriniz: " << endl;
                    cin >> plate;

                    cout << "Araç otoparkta kalma süresini giriniz (X.XX formatında): " << endl;
                    getline(cin, plate);

                    if (timeSpent <= 1.00)
                        price = 0;
                    else if (timeSpent <= 2.00)
                        price = 5;
                    else if (timeSpent <= 3.00)
                        price = 7;
                    else if (timeSpent <= 4.00)
                        price = 10;
                    else if (timeSpent <= 5.00)
                        price = 15;
                    else
                        price = 20;

                    file << "Araç Plakası: " << plate << "\nÜcret: " << price << " USD\n\n";

                    cout << "Devam etmek istiyor musunuz? (1: Evet, 0: Hayır)" << endl;
                    cin >> continue01;

                    if (!continue01)
                    {
                        cout << "İşlem sonlandırıldı." << endl;
                        Sleep(200);
                        cout << "Fatura program dizinine kaydedildi." << endl;
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
                            cout << "Saat " << j + 1 << ": Giren araç sayısını giriniz: " << endl;
                            cin >> enteredcar;

                            if (enteredcar >= minVehicleCount && enteredcar <= maxCapacity)
                                break;
                            else
                                cout << "Geçersiz değer. Tekrar giriniz." << endl;
                        }

                        while (true)
                        {
                            cout << "Saat " << j + 1 << ": Çıkan araç sayısını giriniz: " << endl;
                            cin >> quittedcar;

                            if (quittedcar >= minVehicleCount && quittedcar <= maxCapacity)
                                break;
                            else
                                cout << "Geçersiz değer. Tekrar giriniz." << endl;
                        }

                        carcount = getConclusion(carcount, enteredcar, quittedcar);
                        cout << "Otoparkta bulunan araç sayısı: " << carcount << endl;

                        file2 << "Saat: " << j + 1 << "\nAraç Sayısı: " << carcount << "\n\n";
                        Sleep(500);

                        if (carcount == maxCapacity)
                            cout << "Otopark DOLU!" << endl;
                        else if (carcount >= maxCapacity - 20)
                            cout << "Otopark dolmak üzere!" << endl;
                        else if (carcount >= maxCapacity / 2)
                            cout << "Otopark yarıdan fazla dolu." << endl;
                        else if (carcount >= maxCapacity / 4)
                            cout << "Otoparkın dörtte biri dolu." << endl;
                        else if (carcount > 0)
                            cout << "Otoparkta az sayıda araç var." << endl;
                        else
                            cout << "Otopark boş." << endl;
                    }

                    cout << "Gün " << i + 1 << " tamamlandı. Toplam araç: " << carcount << endl;
                    file2 << "Gün " << i + 1 << " sonunda araç sayısı: " << carcount << "\n";
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
    setlocale(LC_ALL, "Turkish");

    system("color 0A");
    cin.ignore();
    Sleep(500);
    mainFunction();
    Sleep(500);

    system("pause");
    return 0;
}
