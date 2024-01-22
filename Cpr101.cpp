#include <iostream>	
#include <stdio.h>
#include <string>
#include <fstream>	
#include <conio.h>

using namespace std;
string telephone_number();
string tc_no();

string tc_no()
{

	string identity;
	do {
		printf("Lutfen 11 Haneli TC Kimlik Numaranýzý Girin: ");
		cin >> identity;
	} while (identity.length() != 11);


	return identity;
}

string telephone_number()
{
	string number;

	do {
		printf("Lutfen '0' olmadan telefon numarýnýzý gýrýn : ");
		cin >> number;
	} while (number.length() != 10 );

	return  number;
}

void ReadPatient(fstream& DRead)
{
	int patientAge;
	string TcNo, Telephone;
	char patientName[30], patientSurname[20], patientGender[15];
	while (DRead >> TcNo >> patientName >> patientSurname >> patientAge >> Telephone >> patientGender) 
	{
		cout << "---------------------------------------\n";
		cout << "TC Kimlik No :" << TcNo << endl;
		cout << "Adý :" << patientName << endl;
		cout << "Soyadý :" << patientSurname << endl;
		cout << "Yasý :" << patientAge << endl;
		cout << "Telefonu :" << Telephone << endl;
		cout << "Cinsiyetý:" << patientGender << endl;
		cout << "---------------------------------------\n";
	}
}

void InspectionInquiry(fstream& DRead, string HSorgu)
{
	int counter = 0;
	int patientAge;
	string TcNo, Telephone;
	char patientName[30], patientSurname[20], patientGender[15], Date[30], DoctorName[30], Diagnosis[20];
	while (DRead >> TcNo >> patientName >> patientSurname >> patientAge >> Telephone >> patientGender >> Date >> DoctorName >> Diagnosis ) 
	{
		if (HSorgu == TcNo)
		{
			counter++;
			cout << "----------------------------------------------------\n";
			cout << "Hastanýn TC Kimlik Numarasý: " << TcNo << endl;
			cout << "----------------------------------------------------\n";

			cout << "\n                Hasta Bilgileri      \n";
			cout << "\n----------------------------------------------------\n";
			cout << "Hasta Adý :" << patientName << endl;
			cout << "Hasta Soyadý :" << patientSurname << endl;
			cout << "Hasta Yasý :" << patientAge << endl;
			cout << "Telefonu :" << Telephone << endl;
			cout << "Cinsiyeti:" << patientGender << endl;

			cout << "\n             Randevu Bilgileri             \n";
			cout << "\n------------------------------------------------------\n";
			cout << "\n Tarih: " << Date;
			cout << "\n Doktor Adý: " << DoctorName;
			cout << "\n Teshis: " << Diagnosis;
			cout << "\n                                                       \n";
			break;
		}
	}
	if (counter == 0)
	{
	}
	
}

int main()
{
	
	setlocale(LC_ALL, "turkish"); 

	int choose;
	string patientName;
	string patientSurname;
	string TcNo;
	string identity;
	string areaCode;
	string number;
	string Telephone;


	int KayitNo;
	int patientAge;
	string patientGender;
	char transaction;
	string TC;

	fstream DRead;

	string Date;
	string DoctorName;
	string Diagnosis;
	string Medicine;
	string Hour;
	string Assay;
	char Answer;

	do {
		system("cls");
		cout << "	Hastane Randevu Sistemi  " << "\n";
		cout << "Lutfen Yapýlacak Islemi Secin...." << "\n";
		cout << "--------------------------------------------" << "\n";
		cout << "1- Sisteme Hasta Kayýt Etme" << endl; 
		cout << "2- Hasta Kaydý Silme" << endl;
		cout << "3- Sistemdeki Hasta Listesi" << endl;
		cout << "4- Randevu Alma" << endl;
		cout << "5- Randevu Silme " << endl;
		cout << "-----------------------------------------------------" << "\n";
		cout << "Yapmak istediginiz islemin numarasýný secin: ";
		cin >> choose;
		system("cls");
		switch (choose)
		{
		case 1:
		{
			cout << "1- Sisteme Hasta Kayýt Etme" << endl; 

			ofstream DosyaYaz;
			DosyaYaz.open("Hasta.txt", ios::app);
			do
			{
				cout << "\n Hasta TC :"; TcNo = tc_no();
				cout << "\n Hasta Adi :"; cin >> patientName;
				cout << "\n Hasta Soyadi :"; cin >> patientSurname;
				cout << "\n Hasta Yasi :"; cin >> patientAge;
				cout << "\n Telefonu :"; Telephone = telephone_number();
				cout << "\n Cinsiyeti :"; cin >> patientGender;

				DosyaYaz << TcNo << " " << patientName << ' ' << patientSurname << ' ' << patientAge << ' ' << Telephone << ' ' << patientGender << endl;
				cout << "Dosyaya yazim tamamlandý." << endl;

				cout << "\n Baska kayit yapacak misiniz?(y/Y: Yeni Kayýt Ekler) (t/T: Kayýdý Tamamlar) "; cin >> Answer;
				system("cls");
				cout << "1- Sisteme Hasta Kayýt Etme \n";

			} while (Answer == 'y' || Answer == 'Y');

			DosyaYaz.close();
			cout << "Dosyaya yazim tamamlandi." << endl;

			break;
		}
		case 2:
		{
			 cout << "calýsmýyor!!!" << endl; break;
		}
		case 3:
		{
			cout << "3- Sistemdeki Hasta Lýstesý" << endl;
			DRead.open("Hasta.txt", ios::in);
			ReadPatient(DRead);
			DRead.close();
			system("pause"); break;
		}
		case 4:
		{
			cout << "4- Randevu Alma" << endl;

			cout << " Randevu Alýnacak Hastanýn Tc Kimlik Numarasý :"; cin >> TC;

			ifstream DosyaOku("Hasta.txt");
			while (!DosyaOku.eof())
			{
				DosyaOku >> TcNo >> patientName >> patientSurname >> patientAge >> Telephone >> patientGender;
				if (TC == TcNo)
				{
					cout << "\n-----------------------------------------" << endl;
					cout << "          Hasta Bilgileri           \n";
					cout << "TC no :" << TcNo << endl;
					cout << "Adý :" << patientName << endl;
					cout << "Soyadý :" << patientSurname << endl;
					cout << "Yasý :" << patientAge << endl;
					cout << "Telefonu :" << Telephone << endl;
					cout << "Cinsiyeti:" << patientGender << endl;
					cout << "------------------------------------------" << endl;
					cout << "Randevu istiyor mu? (e/h): ";
					cin >> Answer;
					if (Answer == 'e' || Answer == 'E')
					{
						DosyaOku.close();
						ofstream DosyaYaz;
						DosyaYaz.open("RandevuAl.txt", ios::app);
						cout << "--------------------------------------" << endl;
						cout << "     Randevu Bilgileri     \n";
						cout << "Tarih :"; cin >> Date;
						cout << "Doktor Adi :"; cin >> DoctorName;
						cout << "Teshis :"; cin >> Diagnosis;
						cout << "\n----------------------------------" << endl;
						cout << "Randevu Alýndý." << endl;
						DosyaYaz << TcNo << " " << patientName << ' ' << patientSurname << ' ' << patientAge << ' ' << Telephone << ' ' << patientGender << ' ' << Date << ' ' << DoctorName << ' ' << Diagnosis << ' ' << "\n";
						DosyaYaz.close();
						system("cls");
						cout << "Randevu sisteme Kaydedildi." << endl;
					}
				}
			} break;
		}
		case 5:
		{
			cout << "Calýsmýyor" << endl; break;
		}
		}
		cout << "Islem yapmaya devam etmek istiyor musunuz? (m/M: Ana Menuye Doner!) (c/C: Programdan Cýkar!)";
		cin >> transaction;
	} while (transaction == 'm' || transaction == 'M'); 
	cout << endl;

	exit(0);
}
