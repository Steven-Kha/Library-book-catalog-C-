#pragma once
#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

const Date time;

class Book{
	private:
		string firstName;
		string lastName;
		string title;
		Date  checkOut;
		Date	due;

		

	public:
		Book(string a = " ", string b = " ", string c = " ",
			Date x = time, Date y = time); // Put in default values 
		~Book();
		Book & setCheckOutDate(Date);//Just set checkout to be the date given.
		Book & setDueDate(Date); // Just set due to be the date given.
		Book & setFirstName(string);
		Book & setLastName(string);
		Book & setTitle(string);
		string getFirstName();
		string getLastName();
		string getTitle();
		Date getCheckOutDate();
		Date getDueDate();


};