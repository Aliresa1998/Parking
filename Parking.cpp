#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
using namespace std;

//Declear Structs :
struct date {
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
};

struct car {
	int id;
	string plate;
	string model;
	string color;
	date enter;
	date exit;
	string driver;
	string Operator;
};

struct bill {
	int id;
	int carid;
	string date;
	string price;
	string Operator;
};

struct Operator {
	string name;
	string username;
	string password;
};

//Global Variables :
Operator Operators[100];
car cars[100];
int carlen = 0;
int OperatorId = 0;
string basepayment;
string hours;
float baseprice = 8000;
float hourprice = 1000;

//Declear Functions : 
int Login();
void setting();
void getCar();
void showcar();
void showcaroperator();
//Functions : 
int Login(string username,string password) {
	int n = 0;//Number of operators
	ifstream myfile;
	myfile.open("operator.txt");
	myfile >> n;

	for (int i = 0; i < n; i++) {
		myfile >> Operators[i].name;
		myfile >> Operators[i].username;
		myfile >> Operators[i].password;
	}

	for (int i = 0; i < n; i++) {
		if (username == Operators[i].username)
			if (password == Operators[i].password) {
				OperatorId = i;
				return 1;
			}				
	}

	myfile.close();

	return 0;
}

void setting() {
	cout << "Hour price : " << hourprice <<endl;
	cout << "Base price : " << baseprice;
	cout << "\n------\n";
	cout << "New Base Price : " << endl;
	cin >> baseprice;

	cout << "New Hour Price : " << endl;
	cin >> hourprice;

	cout << "\nDone!\n";
}

void getCar() {
	ifstream myfile;
	myfile.open("car.txt");
	myfile >> carlen;

	for (int i = 0; i < carlen; i++) {
		myfile >> cars[i].id;
		myfile >> cars[i].plate;
		myfile >> cars[i].model;
		myfile >> cars[i].color;
		myfile >> cars[i].enter.year;
		myfile >> cars[i].enter.month;
		myfile >> cars[i].enter.day;
		myfile >> cars[i].enter.hour;
		myfile >> cars[i].enter.month;
		myfile >> cars[i].enter.second;
		myfile >> cars[i].exit.year;
		myfile >> cars[i].exit.month;
		myfile >> cars[i].exit.day;
		myfile >> cars[i].exit.hour;
		myfile >> cars[i].exit.month;
		myfile >> cars[i].exit.second;
		myfile >> cars[i].driver;
		myfile >> cars[i].Operator;
	}

	myfile.close();
}

void showcar() {
	getCar();
	for (int i = 0; i < carlen; i++) {
		cout << "id : " << cars[i].id <<endl;
		cout << "plate : " << cars[i].plate << endl;
		cout << "model : " << cars[i].model << endl;
		cout << "color : " << cars[i].color << endl;
		cout << "Enter : " << cars[i].enter.year << "/" << cars[i].enter.month << "/" << cars[i].enter.day << " - " ;
		cout << cars[i].enter.hour << ":" << cars[i].enter.minute << ":" << cars[i].enter.second<<endl;
		cout << "Exit : " << cars[i].exit.year << "/" << cars[i].exit.month << "/" << cars[i].exit.day << " - " ;
		cout << cars[i].exit.hour << ":" << cars[i].exit.minute << ":" << cars[i].exit.second << endl;
		cout << "driver : " << cars[i].driver << endl;
		cout << "Operator : " << cars[i].Operator << endl;
	}
}

void showcaroperator() {
	string name;
	int flag = 0;
	cout << "Enter operator name : ";
	cin >> name;
	getCar();
	for (int i = 0; i < carlen; i++) {
		if (cars[i].Operator == name) {
			flag = 1;
			cout << "id : " << cars[i].id << endl;
			cout << "plate : " << cars[i].plate << endl;
			cout << "model : " << cars[i].model << endl;
			cout << "color : " << cars[i].color << endl;
			cout << "Enter : " << cars[i].enter.year << "/" << cars[i].enter.month << "/" << cars[i].enter.day << " - ";
			cout << cars[i].enter.hour << ":" << cars[i].enter.minute << ":" << cars[i].enter.second << endl;
			//cout << "Exit : " << cars[i].exit.year << "/" << cars[i].exit.month << "/" << cars[i].exit.day << " - ";
			//cout << cars[i].exit.hour << ":" << cars[i].exit.minute << ":" << cars[i].exit.second << endl;
			cout << "driver : " << cars[i].driver << endl;
			cout << "Operator : " << cars[i].Operator << endl;
		}
	}
	if (flag == 0) {
		cout << "ther is no car by operator " + name << endl;
	}
}

int main() {
	string username, password;

	cout << "Welcome To Parking System Management";
	cout << "\n ------------------ \n";
	cout << "Enter username : ";
	cin >> username;
	cout << "Enter password : ";
	cin >> password;
	int Start = Login(username, password);

	if (Start == 1) {
		while (true) {
			system("cls");

			int choice = 0;

			cout << "Welcome Dear : " + Operators[OperatorId].name;
			cout << "\n---\n";
			cout << "1.Add car\n2.Show Cars\n3.Show Cars By operator\n4.Billing\n";
			cout << "5.Show Bills sort by date\n6.Show Bills By operator\n7.Setting\n8.Exit\n";
			cout << "\n ----------\n";

			cout << "Enter any item from above list : ";
			cin >> choice;

			if (choice < 1 || choice >= 8) {
				cout << "bye!";
				break;
			}
			if (choice == 1) {
				//Addcar()
				system("pause");
			}
			else if (choice == 2) {
				showcar();
				system("pause");
			}
			else if (choice == 3) {
				showcaroperator();
				system("pause");
			}
			else if (choice == 4) {
				//Billing()
				system("pause");
			}
			else if (choice == 5) {
				//BillBydate()
				system("pause");
			}
			else if (choice == 6) {
				//BillByoperator()
				system("pause");
			}
			else if (choice == 7) {
				setting();
				system("pause");
			}
		}
	
	}

	return 0;
}