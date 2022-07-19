#include <iostream>
#include <fstream>
#include <json/json.h>
#include <json/value.h>
#include <windows.h>
#pragma comment(lib, "Urlmon.lib")

using namespace std;

int main()
{
	string option;
	int num;

	const wchar_t* srcURL = L"https://api.exchangerate.host/latest?base=USD";
	const wchar_t* destFile = L"chip value.json";
	if (S_OK == URLDownloadToFile(NULL, srcURL, destFile, 0, NULL))
		cout << ("Saved to 'myfile.txt'\n\n");
	else
	{
		cout << ("Failed");
		return -1;
	}
	Json::Value actu;
	Json::Reader reader;

	ifstream file("chip value.json");
	reader.parse(file, actu);
	
	cout << actu;
	cout << "Enter sum for conversion: ";
	cin >> num;
	cout << "  1) EUR - Euro \n"
		"  2) GBP - British Pound \n"
		"  3) DKK - Danish Krone \n"
		"  4) CZK - Czech Koruna \n"
		"  5) RON - Romanian Leu \n\n";

	cout << "Select a number for a currency representation: ";
	cin >> option;

	
	if (option == "1")
		cout << num << " " << "EUR" << " in USD: " << num * actu["EUR"].asDouble();
	if (option == "2")
		cout << num << " " << "GBP" << " in USD: " << num * actu["GBP"].asDouble();
	if (option == "3")
		cout << num << " " << "DKK" << " in USD: " << num * actu["DKK"].asDouble();
	if (option == "4")
		cout << num << " " << "CZK" << " in USD: " << num * actu["CZK"].asDouble();
	if (option == "5")
		cout << num << " " << "RON" << " in USD: " << num * actu["RON"].asDouble();

	cin.get(); cin.get();
	return 0;
}