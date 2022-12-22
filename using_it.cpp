#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
	char tree[15][30];
	ifstream seatPrice;
	ifstream seatAvaliability;
	seatAvaliability.open("SeatAvailability.txt");
	seatPrice.open("SeatPrices.txt");
	if(!seatAvaliability&&!seatPrice)
	{
		cout<<"Error opening files. \n";
		cout<<endl;
	}
	else
	{
		for (int i = 0 ;i < 15; i++)
		{
    		for (int j = 0; j < 30; j++)
    		{
        		seatAvaliability>>tree[i][j];
    		}
		}
		/*for (int i = 0 ;i < 15; i++)
		{
			seatPrice>>s[i][0].price;
		}*/
		for (int i = 0 ;i < 15; i++)
	{
    	for (int j = 0; j < 30; j++)
    	{
        	cout<<tree[i][j];
    	}
    	cout<<endl;
	}
		seatAvaliability.close();
		seatPrice.close();
	}
	
}
