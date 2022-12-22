#ifndef TICKETMANAGER_H
#define TICKETMANAGER_H
#ifndef SEATSTRUCTURES_H

#define SEATSTRUCTURES_H


class TicketManager
{
	private:
		double total_money_collected;
		int seat_sold;
		/*The theater's auditorium has 15 rows, with 30 seats in each row. To represent the 
			seats, the Ti cketManager class should have a two-dimensional array of 
			SeatStructures. Each of these structures should have data members to keep 
			track of the seat's price and whether or not it is available or already sold. 
		*/
				
	public:
		struct SeatStructures
		{
			double price;	//This keeps track of the set's price
			char avalability;		// Thsi checks wheather the seat is avaliable or not;
	
		};
		SeatStructures seat[15][30];
		TicketManager();
		~TicketManager();
		void displaySeat();
		bool requestTicket(int number, int row_num, int starting_num);
		void PurchaseTicket(int number, int row_num, int starting_num);
		void salesReport();
};
#endif
#endif
