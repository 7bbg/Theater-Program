#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;
#include"AnthonyNwafor_TicketManagerClassT.h"



TicketManager::TicketManager()
{
	ifstream seatPrice, seatAvaliability;
	seatAvaliability.open("SeatAvailability.dat");
	seatPrice.open("SeatPrices.dat");
	seat_sold=0;
	total_money_collected=0.0;
	double pri=0.0;
	if(!seatAvaliability&&!seatPrice)
	{
		cout<<"Error opening files. \n";
		cout<<endl;
	}
	else
	{
		for (int i = 0 ;i < 15; i++)
		{
			seatPrice>>pri;
			seat[i][0].price=pri;
    		for (int j = 0; j < 30; j++)
    		{
        		seatAvaliability>>seat[i][j].avalability;
    		}
		}
		/*for (int i = 0 ;i < 15; i++)
		{
			seatPrice>>seat[i][0].price;
		}*/
		
		seatAvaliability.close();
		seatPrice.close();
	}
	
	
}

//Destructor
/*
The program needs to be able to write the updated seat availability data back out 
to the file. The obvious place to do this is in the TicketManager destructor.

*/
TicketManager::~TicketManager()		//detructor
{
	ofstream seatAvaliability;
	seatAvaliability.open("SeatAvailability.dat");
	
	if(!seatAvaliability)
	{
		cout<<"Error opening file. \n";
	}
	else
	{
		for (int i = 0 ;i < 15; i++)
		{
    		for (int j = 0; j < 30; j++)
    		{
        		seatAvaliability<<seat[i][j].avalability;
    		}
    		seatAvaliability<<endl;
		}
		seatAvaliability.close();
	}
	
}

/*

When the user selects the display seats menu option, a TicketManager function 
should be called that creates and returns a string holding a chart, similar to 
the one shown here. It should indicate which seats are already sold (*) and 
which are still available for purchase (#) .The client program shou ld th en 
display the string.

*/

void TicketManager::displaySeat()
{
	cout<<"	123456789012345678901234567890"<<endl;
	for (int i = 0;i < 15; i++)
	{
		cout<<"Row "<<(i+1)<<"	";
    	for (int j = 0; j < 30; j++)
    	{
        	cout<<seat[i][j].avalability;
    	}
    	cout<<endl;
	}
	cout<<endl;
}

/*

A TicketManager ticket request function should then be called and passed this information so that it can handle the 
ticket request. If any of the requested seats do not exist, or are not available, 
an appropriate message should be returned to be displayed by the client 
program. 

*/
bool TicketManager::requestTicket(int num_seat, int row_num, int starting_num)
{
	bool availiablity=true;
	for (int j =starting_num ; j < 30; j++)
    {
        if(seat[row_num][j].avalability=='*')
        {	
        	availiablity=false;
        	j=30;
		}
    }
    if(availiablity)
    {
    	return availiablity;
	}
	else
	{
		return availiablity;
	}
    
	
	
}

/*
If the patron indicates they do want to buy the requested seats , a 
TicketManager purchase tickets module should be called to handle the actua l 
sale. This module must be able to accept money, ensure that it is sufficient to 
continue with the sale, and if it is, mark the seat(s) as sold, and create and 
return a string that includes a ticket for each seat sold (with the correct row, 
seat number, and price on it).
*/
void TicketManager::PurchaseTicket(int num_seat, int row_num, int starting_num)
{
	int seat_count=0;	//This count the number of seat for it to display
	double transaction=0.0;
	double change=0.0;
	cout<<"Enter amount of money for the transaction(): ";
	cin>>transaction;
	cout<<"Tshhs"<<seat[row_num][0].price<<endl;
	while(transaction<(seat[row_num][0].price*num_seat))
	{
		cout<<"Invalid.. pLease enter an amount greater than or equal to "<<seat[row_num][0].price*num_seat<<endl<<endl;
	}
	for (int j = 0; j < num_seat; j++)
	{
		seat[row_num][starting_num+j].avalability=='*';//This marks the seats as sold
			
   	}
   	total_money_collected+=(seat[row_num][0].price*num_seat);	//To keep track of the total amount that was collected.
   	seat_sold+=num_seat;		//To collected to total number of seat sold.
   	//change=(seat[row_num][0].price*num_seat)-(transaction);
   	
   	for (int j = starting_num;  seat_count<num_seat; j++)
	{
		cout<<"\nRow "<<row_num+1<<" seat "<<j+1<<endl;
		seat_count++;
	}
}

/*
When the user selects the sales report menu option , a TicketManager report 
module should be called. This module must create and return a string holding 
a report that tells how many seats have been sold, how many are still 
available, and how much money has been collected so far for the sold seats. 
Think about how your team will either calculate or collect and store this 
information so that it will be available when it is needed for the report. 
*/

void TicketManager::salesReport()
{
	cout<<"\n\n";
	cout<<setw(50)<<right<<"SALES REPORT "<<endl;
	cout<<setw(50)<<right<<"The number of sold seat is: "<<seat_sold<<endl;
    cout<<setw(50)<<right<<"The number of avalable seat is: "<<450-seat_sold<<endl;
    cout<<setw(51)<<fixed<<showpoint<<setprecision(2)<<right<<"The number of money collected so far is: $"<<total_money_collected<<endl;
    cout<<endl;
}










