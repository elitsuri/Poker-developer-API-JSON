#include <iostream>
#include <fstream>
#include <json/json.h>
#include <json/value.h>
#include <windows.h>
#pragma comment(lib, "Urlmon.lib")

using namespace std;

int main()
{
	string cur;
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

	cout << "Enter sum: ";
	cin >> num;
	cout << "  1) EUR - Euro \n"
			"  2) GBP - British Pound \n"
			"  3) DKK - Danish Krone \n"
			"  4) CZK - Czech Koruna \n"
			"  5) RON - Romanian Leu \n";
	cin >> cur;

	if (cur == "1")
		cout << num << cur <<" in USD: " << num * actu["EUR"].asInt() * << " EURO";
	if (cur == "2")
		cout << num << cur << " in USD: " << num * actu["GBP"].asInt() << " EURO";
	if (cur == "3")
		cout << num << cur << " in USD: " << num * actu["DKK"].asInt() << " EURO";
	if (cur == "4")
		cout << num << cur << " in USD: " << num * actu["CZK"].asInt() << " EURO";
	if (cur == "5")
		cout << num << cur << " in USD: " << num * actu["RON"].asInt() << " EURO";

	cin.get(); cin.get();
	return 0;
}