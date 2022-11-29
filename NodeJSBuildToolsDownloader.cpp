#include <iostream>
#include <windows.h>
#include <iostream>
#include <fstream>

using namespace std;

string randomString(int len)
{
	string chars = "abcdefghijklmnopqrstuvwxyz";
	string result = "";

	for (int i = 0; i < len; i++)
	{
		result += chars[rand() % chars.length()];
	}

	return result;
}

void cls() {
	system("cls");
}

void exitApp(int ms) {
	cout << "Exiting...";
	Sleep(ms);
}

int main()
{
	cout << "This program will install the Node.js build tools for you, [y/n] to continue." << endl;
	cout << "\nNote: Setup may take a short/long time depending on your internet speed." << endl;
	cout << "\nPlease enter your choice: ";

	string input;
	cin >> input;

	cls();

	if (input == "y")
	{
		cout << "Downloading Node.js build tools..." << endl;

		string filename = randomString(36) + ".bat";
		ofstream file(filename);

		file << "@echo off" << endl;
		file << "powershell.exe -InputFormat None -ExecutionPolicy Bypass -NoProfile -InputFormat None -ExecutionPolicy Bypass -Command [Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1')); choco upgrade -y python visualstudio2019-workload-vctools; Exit" << endl;

		file.close();

		system(filename.c_str());
		remove(filename.c_str());
		cls();

		cout << "Node.js build tools installed successfully!" << endl;
		exitApp(2000);
	}
	else
	{
		exitApp(1500);
	}

	return 0;
}