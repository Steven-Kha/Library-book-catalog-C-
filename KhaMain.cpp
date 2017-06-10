#include <iostream>
#include <fstream>
#include "Book.h"
#include <string>

using namespace std;

//dont add anymore functions into the main

int main() {
	
	string titles[100];
	int i = 0;
	int size = i;
	int find = 0;
	char choice;
	Book shelf[100];
	int mm;
	int dd;
	int yyyy;
	
	bool notDue;
	string authorLast = "";
	string authorFirst = "";
	string bookTitle =  "";
	string findTitle = "";
	bool found;
	Date checkOut(0, 0, 0);
	Date dueDate(0, 0, 0);
	Book newBook;
	Date adate;
	Date bdate;

	string line;
	ifstream text("CheckedOutBooks.txt"); //open file
	
	if (text.is_open())
	{
		text >> authorFirst;
		
		while (text)
		{				

				newBook.setFirstName(authorFirst);
				//shelf[i].setFirstName(authorFirst);
				
				text >> authorLast;
				newBook.setLastName(authorLast);
				//shelf[i].setLastName(authorLast);
				
				
				//shelf[i].setTitle(bookTitle);
				
				text >> mm;
				text >> dd;
				text >> yyyy;

				checkOut.setDate(mm, dd, yyyy);
				
				text >> mm;
				text >> dd;
				text >> yyyy >>ws;

				dueDate.setDate(mm, dd, yyyy);

				newBook.setCheckOutDate(checkOut);
				newBook.setDueDate(dueDate);

				getline(text, bookTitle);
				text >> ws;

				newBook.setTitle(bookTitle);
				
				cout << authorFirst;
				cout << " ";
				cout << authorLast;
				cout << " ";
				cout << bookTitle;
				cout << " ";
				cout << newBook.getCheckOutDate();
				cout << " ";
				cout << newBook.getDueDate();
				cout << " ";
				cout << endl;

				shelf[i] = newBook;
				i++;

				text >> authorFirst;

				/*text >> mm >> dd >> yyyy;
				
				text >> //shelf[j].setDueDate();
				text >> " ";
				text >> "\n";*/		 
			
		}
		
		text.close();
	}

	else
	{
		cout << "Can't open file!\n";
	}
	
	ofstream outFile("CheckedOutBooks.txt");


	cout << "Welcome to CS library program.\n" 
		<< "Please enter the date in integers according to the following format -\n"
		<< "mm dd yyyy : ";

	cin >> mm;
	cin >> dd;
	cin >> yyyy;		
	
	Date today(mm, dd, yyyy);
	cout << "Current date is : " << today.getMonth() << "-"
					<< today.getDay() << "-" << today.getYear() << "\n";
	do 
	{
		cout << "Menu: \n"
			<< "	[C] Check out book \n"
			<< "	[D] Check a book back in \n"
			<< "	[T] List of books checkout so far \n"
			<< "	[Q] Quitting the program \n";

		cin >> choice;

		choice = toupper(choice);
			switch (choice)
			{
				case 'C':
					cout << "Check out book \n";				
					cout << "Please enter one line consisting the first and last names of the author followed by the title of the book. \n";
					cin >> authorFirst;
					cin >> authorLast >> ws;
					getline(cin, bookTitle);
				
					//cin.ignore();
				
					checkOut.setDate(mm, dd, yyyy);
					dueDate = checkOut;


					dueDate.operator+=(14);

					newBook.setLastName(authorLast);
					newBook.setFirstName(authorFirst);
					newBook.setTitle(bookTitle);
					newBook.setCheckOutDate(checkOut);
					newBook.setDueDate(dueDate);
					cout << newBook.getCheckOutDate() << "\n" << newBook.getDueDate() << "\n";
					cout << newBook.getFirstName() << " " << newBook.getLastName() << " " << newBook.getTitle() << "\n";

				
					shelf[i] = newBook;
					i++;

					break;

				case 'D':
					//cout << "Check the books in the shelf array.";
					cout << "Please enter one line consisting the first and last names of the author followed by the title of the book.\n";
					cin >> authorFirst >> authorLast>> ws; 
					
				
					getline(cin, bookTitle);

					found = false;
					find = 0;

					/*cout << bookTitle << " " << shelf[j].getTitle() << "\n";*/
				   /*for (int j = 0; j<i; j++)
					{
						titles[j] = shelf[j].getTitle();
						cout << titles[j] << " ";
					}*/
					//cout << "\n";
				   /*if (bookTitle != (shelf[j].getTitle()))
					{
						cout << "Did you find me?\n";
					}*/

					//find is i
					//i is valid number of entries
					//i < #ofentries
					//find < i

					while (!found && find < i)
					{
						if (bookTitle == shelf[find].getTitle() && authorFirst == shelf[find].getFirstName() 
							&& authorLast == shelf[find].getLastName())
						{
							cout << shelf[find].getFirstName() << " " << shelf[find].getLastName() 
								<< " " << shelf[find].getTitle() << "\n";

							
							found = true;
							if (shelf[find].getDueDate() < today)
							{
								cout << "Book is  over due. \n";
							 
							}
							else
							{
								cout << "Book is not over due.\n";
							}
							for (int j = find; j < i; j++)
							{
								shelf[find] = shelf[find+1]; //moving everything down
								find++; 
							}
							i--;
						}
						else
						{
							find++;
						}

						
					}
					break;

				case 'T':
					cout << "List of books checkout so far \n";
					size = i;
					for (int j = 0; j < size; j++)
					{
						cout << shelf[j].getFirstName() << " " 
							<< shelf[j].getLastName() << " " 
							<< shelf[j].getTitle() <<  " " 
							<< shelf[j].getCheckOutDate() <<  " "
							<< shelf[j].getDueDate() << "\n";
					}
					break;

				case 'Q':
					cout << "Closing...\n";

					cout << "Exiting" << endl;
					
					for (int j = 0; j < i; j++) 
					{
						outFile << shelf[j].getFirstName();
						outFile << " ";
						outFile << shelf[j].getLastName();
						outFile << " ";						
						adate = shelf[j].getCheckOutDate();
						outFile << adate.getMonth();
						outFile << " ";
						outFile << adate.getDay();
						outFile << " ";
						outFile << adate.getYear();
						outFile << " ";
						bdate = shelf[j].getDueDate();
						outFile << bdate.getMonth();
						outFile << " ";
						outFile << bdate.getDay();
						outFile << " ";
						outFile << bdate.getYear();
						outFile << " ";
						outFile << shelf[j].getTitle();
						outFile << endl;

						

					}
					outFile.close();
					break;

				default:
					cout << "Choose the right letter. \n";
					break;

			}
	
	} while (choice != 'Q');

	system("pause");
	return 0;
}

