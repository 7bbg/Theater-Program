									// Part 1 - Identification / Algorithm
/*
Anthony Ikenna Nwafor
Date Submitted: 10/23/2022
Due Date: 10/21/2022
CS204 1 - Computer Programming II

Program: This program is to to display a ticket of the menu get the input from the user validate the input then perform the operation that needs to be perfromed based on what the user enter.

***Design(Pseudocode/Algorithm)***

Step 1: Start.
Step 2: Create variables and function prototypes for the program.
Step 3: Print the menu and ask user for thier choice then validate and store user choice.
Step 4: Use a switch statement to perform the choices of the user
Step 5: End.

*/
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;

#include"AnthonyNwafor_TicketManagerClassT.h"


//Function prototypes.
void Menu_display();
void UserRequest_TicketFunction(int &num_seat,int &row_num,int &starting_num);
void request_TicketFunction(TicketManager object, int number, bool return_test, int row_num, int starting_num);

int main()
{
	TicketManager Object;		//Tickmanager object.
	
	int choice=0;	//This stores user choice.
	int num_seat=0;
	int row_num=0;
	int starting_num=0;
	bool return_test=false;
	
	
	do
	{
		Menu_display();// Call the menu display funtions.
		cout<<"Enter choice: ";
		cin>>choice;	// This stores user choice for the menu.
		
		
		//This loop is to validate the user choice.
		while(choice<1 || choice>4)
		{
			cout<<"please enter your valid choice for the ticket menu between (1 and 4): ";
			cin>>choice;
		}
		
		// This is operates based on the valid user choice. 
		switch(choice)
		{
			case 1: Object.displaySeat();
					break;
			case 2:	
					UserRequest_TicketFunction(num_seat,row_num,starting_num);	//This call the ask the user funtion.
					
					return_test=Object.requestTicket(num_seat,row_num-1,starting_num-1); //This call the user Ticket manager funtion to check if the seat are valiable.
					
					request_TicketFunction(Object, num_seat,return_test, row_num,starting_num); //This this ask the user if he or she want to continue if the Ticket manager funtion that is being called returns true.
					
					break;
					
			case 3:	
					Object.salesReport(); //This call the Ticket manager funtion to get sales report.	
					break;
		}
		
	}while(choice!=4);
	Object.~TicketManager();
	return 0;
}


/*
The client program should be a menu-driven program that provides the user 
with a menu of box office options, accepts and validates user inputs, and calls 
appropria te class functions to carry out desired tasks. The menu should have 
options to display the seating chart, request tickets, print a sales report, and exit 
the program.
*/

void Menu_display()
{
	
	
	cout<<setw(20)<<"Ticket Menu"<<endl;
	cout<<"Enter (1) to see seat chart"<<endl;
	cout<<"Enter (2) to request tickets"<<endl;
	cout<<"Enter (3) to print sales report "<<endl;
	cout<<"Enter (4) to exit"<<endl;
}

/*
 The program should prompt for the number of seats the patron wants, the desired row number, 
and the desired starting seat number.
*/
void UserRequest_TicketFunction(int &num_seat,int &row_num,int &starting_num)	//This function ask the user for the desired ticket number and others
{
	const int ROW=15;
	const int COL=30;
	
	cout<<"Enter the number of seat you want: ";
	cin>>num_seat;
	while(num_seat<1 || num_seat>COL)
	{
		cout<<"Invalid... Please enter the right number of seat (between 1 and 15): ";
		cin>>num_seat;
	}
	cout<<"Enter the row number that you want (between 1 and 15): ";
	cin>>row_num;
	while(row_num<1 || row_num>ROW)
	{
		cout<<"Invalid... please enter a valid row (between 1 and 15) ";
		cin>>row_num;
	}
	cout<<"Enter the your desired starting seat number that you want (between 1 and 30): ";
	cin>>starting_num;
	while(starting_num<1 || starting_num>COL)
	{
		cout<<"Invalid.. please enter a valid starting number (between 1 and 30): ";
		cin>>starting_num;
	}
}

/*
 If the seats exist and are available, a string shou ld be created and 
returned that lists the number of requested seats, the price per seat in the 
requested row, and the total price for the seats. Then the user program should 
ask if the patron wishes to purchase these seats.

If the patron indicates they do want to buy the requested seats , a 
Ti cketManager purchase tickets module should be called to handle the actua l 
sale. This module must be able to accept money, ensure that it is sufficient to 
continue with the sale, and if it is, mark the seat(s) as sold, and create and 
return a string that includes a ticket for each seat sold (with the correct row, 
seat number, and price on it).

*/
void request_TicketFunction(TicketManager object, int number, bool return_test, int row_num, int starting_num)
{
	
	if(return_test)
    {
    	char choice;
		cout<<"The number of requested seats is: "<<number<<endl;
    	cout<<"The price per seat in the requested row "<<row_num<<" is: "<<object.seat[row_num-1][0].price<<endl;
    	cout<<"The total price for the seats is: "<<(object.seat[row_num-1][0].price*number)<<endl;
    	cout<<endl;
    	cout<<"Do you wish to purchase the seats (enter Y or N): "<<endl;
    	cin>>choice;
    	choice=toupper(choice);		//give choice the capitalized value of user answer.
    	while (choice!= 'Y' && choice!= 'N' )
    	{
    		cout<<"Please enter a valid choice (enter Y or N): "<<endl;
    		cin>>choice;
    		choice=toupper(choice);
		}
						
		if(choice=='Y')
		{
			object.PurchaseTicket(number, row_num-1, starting_num-1);
		}
	}
	else
	{
		cout<<"\nSorry, but Row "<<row_num<<" doesn't have "<<number<<" available seats together at the starting Seat "<<starting_num<<endl;
	}
		
}
/*		
								//verification
								
	
         Ticket Menu
Enter (1) to see seat chart
Enter (2) to request tickets
Enter (3) to print sales report
Enter (4) to exit
Enter choice: 4


         Ticket Menu
Enter (1) to see seat chart
Enter (2) to request tickets
Enter (3) to print sales report
Enter (4) to exit
Enter choice: 3


                                     SALES REPORT
                      The number of sold seat is: 0
                  The number of avalable seat is: 450
         The number of money collected so far is: $0.00
							
//It is displaying this and i don't know why.								
         Ticket Menu
Enter (1) to see seat chart
Enter (2) to request tickets
Enter (3) to print sales report
Enter (4) to exit
Enter choice: 1
        123456789012345678901234567890
Row 1   ##############################
Row 2   ##############################
Row 3   ##############################
Row 4   ##############################
Row 5   ##############################
Row 6   ##############################
Row 7   ##############################
Row 8   ##############################
Row 9   ##############################
Row 10  ##############################
Row 11  ##############################
Row 12  ##############################
Row 13  ##############################
Row 14  ##############################
Row 15  ##############################
				
															
*/
