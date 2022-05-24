#include <iostream>

using namespace std;

string date_format[7] = { "Sun" , "Mon" , "Tue" , "Wed" , "Thu" , "Fri" , "Sat" };
string blank = "\t";
string months_of_year[12] = { "January" , "February" , "March" , "April" , "May" , "June" , "July" , "August" , "September" , "October" , "November" , "December" };
int no_of_days[13] = { 0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
int no_of_days_leap[13] = { 0 , 31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };

// Sun 1 Mon 2 Tue 3 Wed 4 Thu 5 Fri 6 Sat 7

bool isLeap(int yearf)
{
	if((yearf % 4 == 0 && yearf % 100 != 0) || yearf % 400 == 0){
		return true;
	} else {
		return false;
	}
}

int getFirstDayOfYear(int yearf)
{	
	int first_day_of_year = (yearf + yearf/4 - yearf/100 + yearf/400)%7;
	if(!isLeap(yearf)){
		first_day_of_year = (first_day_of_year+1)%7;
	}
	return first_day_of_year;
}

int day_number (int dayf, int monthf, int yearf, bool msg)
{	
	int i;
	int a = 0;
	for(i = 1; i <= monthf-1; i++)
	{
		if((yearf % 4 == 0 && yearf % 100 != 0) || yearf % 400 == 0){
			a += no_of_days_leap[i];
		} else {
			a += no_of_days[i];
		}
		
	}
	if(msg){
		if(isLeap(yearf)){
			cout << "Thang " << monthf << " co " << no_of_days_leap[monthf] << " ngay" << "\n";
		} else {
			cout << "Thang " << monthf << " co " << no_of_days[monthf] << " ngay" << "\n";
		}
	}
		
	a += dayf;
	
	return a;
}

int getDate(int firstDay, int dayNumber)
{
	int date = firstDay;
	
	date += dayNumber % 7;
	date -= 2;
	if(date >= 7) {
		date -= 7;
	} else if (date <= 0) {
		date += 7;
	}
	
	return date;
}

int printCal(int month, int year)
{
	
	cout << blank + blank + blank + months_of_year[month-1] << "\n";
	
	for (int i = 1; i <= 7; i++)
	{
		cout << date_format[i%7] + blank;
	}
	cout << "\n";
	
	int counter = 1;
	int max = no_of_days_leap[month];
	
	int nothing = (getDate(getFirstDayOfYear(year), day_number(1, month, 2020, false))+6)%7;
	for (int i = 1; i <= nothing; i++)
	{
		cout << "   " << blank;
	}
	
	for(int i = 1 ; i <= max ;  i++ )
	{
		int sth = getDate(getFirstDayOfYear(year), day_number(i, month, 2020, false));
		cout << i << blank;
		if(sth == 0) cout << "\n";
		
	}
	
	cout << "\n-------------------------------------------------------------\n";
	
	return 0;
}

int main() 
{		
	int year;
	cout << "Nhap vao nam: ";
	cin >> year;
	
	cout << "\n-------------------------------------------------------------\n";
	
	for(int i = 1; i <= 12; i++){
		printCal(i, year);	
	}
	
}
