#pragma once
#include "Book.h"
#include <iostream>
#include <string>


Book::Book(string firstName, string lastName, string title,
	Date checkOut, Date due) : firstName(firstName), lastName(lastName),
	title(title), checkOut(checkOut), due(due) {};
Book::~Book()
{
}


Book &Book::setLastName(string x)
{
	lastName = x;
	return *this;
}

Book &Book::setFirstName(string x)
{
	firstName = x;
	return *this;
}

Book &Book::setTitle(string x)
{
	title = x;
	return *this;
}

Book &Book::setCheckOutDate(Date x)
{
	checkOut = x;
	return *this;
}

Book &Book::setDueDate(Date x){

	due= x;
	return *this;
}

string Book::getFirstName(){

	return firstName;
}

string Book::getLastName(){

	return lastName;
}

string Book::getTitle(){

	return title;
}

Date Book::getCheckOutDate(){
	return checkOut;
}

Date Book::getDueDate(){
	return due;
}