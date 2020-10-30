// Hotel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "Dates.h"
#include "Room.h"
#include "Vector.h"
#include <ctime>
#include <string>
#include "HotelSystem.h"
#include  <conio.h>
#include <string>
//#include "windows.h"
using namespace std;


void help()
{
	std::cout << "The following commands are supported:" << std::endl;
	std::cout << "open <file>        opens <file>" << std::endl;
	std::cout << "close              closes currently opened file" << std::endl;
	std::cout << "save               saves the currently open file" << std::endl;
	std::cout << "saveas <file>      saves the currently open file in <file>" << std::endl;
	std::cout << "help               prints this information" << std::endl;
	std::cout << "exit	           exists the program" << std::endl;

}


void test()
{
	std::cout << "Write open to begin" << std::endl;
	std::string command;
	getline(std::cin,command);

	if (command == "open")
	{
		std::cout << "Choose between 3 ways to start the project" << std::endl;
		std::cout << "1-with directory but you have to use Windows" << std::endl;
		std::cout << "2-with a file in the project's directory" << std::endl;
		std::cout << "3-without files" << std::endl;
		HotelSystem hotelsystem;
		int number;
		cin >> number;
		if (number == 1)
		{
			std::cout << "Choose directory:" << std::endl;	
			HotelSystem hotelSystem("C:\\Users\\Georgi\\Desktop\\OOP\\Hotel\\Hotel\\File4.txt");
			//hotelsystem.printHotel();
			hotelsystem = hotelSystem;
			std::cout << "Choose between commands" << std::endl;
		}
		else if (number == 2)
		{
	
			HotelSystem hotelSystem("File4.txt");
			//hotelsystem.printHotel();
			hotelsystem = hotelSystem;

		}
		else if (number == 3)
		{
			
			HotelSystem hotelSystem;
			Room room100(100, 3);
			Room room101(101, 3);
			Room room102(102, 5);
			Room room103(103, 5);
			Room room104(104, 6);
			Room room105(105, 1);
			hotelSystem.addRoom(room100);
			hotelSystem.addRoom(room101);
			hotelSystem.addRoom(room102);
			hotelSystem.addRoom(room103);
			hotelSystem.addRoom(room104);
			hotelSystem.addRoom(room105);
			size_t data[3] = { 2020,5,25 };
			size_t data2[3] = { 2020,5,28 };
			size_t data3[3] = { 2020,6,25 };
			size_t data4[3] = { 2020,6,28 };
			size_t data5[3] = { 2020,7,25 };
			size_t data6[3] = { 2020,7,28 };
			hotelSystem.checkIn(100, data, data2, "mizernici");
			hotelSystem.checkIn(101, data, data2, "mizernici");
			hotelSystem.checkIn(102, data, data2, "mizernici");
			hotelSystem.checkIn(103, data, data2, "mizernici");
			hotelSystem.checkIn(105, data, data2, "mizernici",1);
			hotelSystem.printHotel();
			hotelsystem = hotelSystem;
			std::cout << "Choose between commands" << std::endl;
		}

		std::string validCommand;
		getline(::cin, validCommand);
		while (validCommand != "exit")
		{
			getline(::cin, validCommand);
			if (validCommand == "exit")
			{
				break;
			}


			if (validCommand == "checkin")
			{

				std::cout << "Room: ";
				int room;
				cin >> room;
				std::cout << std::endl;
				std::cout << "Date from: ";
				size_t from[3];
				for (size_t i = 0; i < 3; i++)
				{
					cin >> from[i];
				}
				std::cout << "Date to: ";
				size_t to[3];
				for (size_t i = 0; i < 3; i++)
				{
					cin >> to[i];
				}
				cin.ignore();
				std::string note;
				getline(std::cin, note);

				std::cout << "Default number of guests? Write yes/no." << std::endl;
				std::string yes;
				getline(std::cin, yes);

				if (yes == "yes")
				{
					hotelsystem.checkIn(room, from, to, note);
				}
				else
				{
					int numberOfGuests;
					cin >> numberOfGuests;
					hotelsystem.checkIn(room, from, to, note, numberOfGuests);

				}
				hotelsystem.printHotel();


			}
	
			if (validCommand == "checkout")
			{
				int roomNumber;
				std::cout << "RoomNumber: ";
				cin >> roomNumber;
				hotelsystem.checkOut(roomNumber);

			}

			if (validCommand == "availability")
			{
				std::cout << "Do you want definite date?";

				std::string answer;
				getline(std::cin, answer);
				if (answer == "yes")
				{
					size_t date[3];
					for (size_t i = 0; i < 3; i++)
					{
						cin >> date[i];
					}
					hotelsystem.availability(date);
					break;
				}
				else
				{
					hotelsystem.availability();
				}
			}
			if (validCommand == "find")
			{

				std::cout << "Date from: ";
				size_t from[3];
				for (size_t i = 0; i < 3; i++)
				{
					cin >> from[i];
				}
				std::cout << "Date to: ";
				size_t to[3];
				for (size_t i = 0; i < 3; i++)
				{
					cin >> to[i];
				}
				cin.ignore();
				hotelsystem.find(4, from, to);

			}
			if (validCommand == "unavailable")
			{
				std::cout << "Date from: ";
				size_t from[3];
				for (size_t i = 0; i < 3; i++)
				{
					cin >> from[i];
				}
				std::cout << "Date to: ";
				size_t to[3];
				for (size_t i = 0; i < 3; i++)
				{
					cin >> to[i];
				}
				cin.ignore();
				hotelsystem.unavailable(100, from, to, "Under Construction");


			}
			if (validCommand == "report")
			{
				std::cout << "Date from: ";
				size_t from[3];
				for (size_t i = 0; i < 3; i++)
				{
					cin >> from[i];
				}
				std::cout << "Date to: ";
				size_t to[3];
				for (size_t i = 0; i < 3; i++)
				{
					cin >> to[i];
				}
				cin.ignore();
				hotelsystem.report(from, to);
			}


			if (validCommand == "close")
			{
				std::cout << "close" << std::endl;
				
			}

			if (validCommand == "save")
			{
				hotelsystem.save();
			}
			if (validCommand == "saveas")
			{
				std::string fileToSafe;
				getline(std::cin, fileToSafe);
				const char* file = fileToSafe.c_str();
				hotelsystem.saveas(file);
			}
		}

	}

}





int main()

{
	
	test();
	//if something happens to test()and something is not compiling.
	//There are many test and it doesnt compile please check the tests below
	
	/*
	HotelSystem hotel;
	Room room100(100, 3);
	Room room101(101, 3);
	Room room102(102, 5);
	Room room103(103, 5);
	Room room104(104, 6);
	Room room105(105, 1);
	hotel.addRoom(room100);
	hotel.addRoom(room101);
	hotel.addRoom(room102);
	hotel.addRoom(room103);
	hotel.addRoom(room104);
	hotel.addRoom(room105);
	*/



	/*
	Room room100(100, 3);
	size_t data[3] = { 2020,5,25 };
	size_t data2[3] = { 2020,5,28 };
	Dates date;
	date.setFrom(data);
	date.setTo(data2);
	room100.bookRoom(data, data2,"mizernik",2);
	room100.printRoom();
	std::ofstream file("File4.txt");
	room100.saveRoom(file);
	*/
	
	//Room room200;
	//std::ifstream file2("File4.txt");
	/*room200.readRoom(file2);
	room200.printRoom();
	std::cout << room200.getArchivSize();
	*/
	//HotelSystem system("C:\\Users\\Georgi\\Desktop\\OOP\\Hotel\\Hotel\\File4.txt");
	//system.printHotel();
	/*
	HotelSystem hotel;
	 Room room100(100, 3);
	 Room room101(101, 3);
	 Room room102(102, 5);
	 Room room103(103, 5);
	 Room room104(104, 6);
	 Room room105(105, 1);
	
	 hotel.addRoom(room101);
	 hotel.addRoom(room102);
	 hotel.addRoom(room103);
	 hotel.addRoom(room104);
	 hotel.addRoom(room105);
	 size_t data[3] = { 2020,5,25 };
	 size_t data2[3] = { 2020,5,28 };
	 Dates date;
	 date.setFrom(data);
	 date.setTo(data2);
	 room100.bookRoom(data, data2, "mizernik", 2);
	 hotel.addRoom(room100);
	 hotel.saveSystem("File33.txt");
	 hotel.printHotel();*/
	/*
	std::ifstream file("File33.txt");
	 HotelSystem system2("File33.txt");
	 system2.printHotel();


	 std::string str = "sadasdas";
	 const char* ss = "sdsd";
	 str = ss;
	 */
	//test();
	/*
	Dates date;
	size_t data[3] = { 2021,4,20 };
	size_t data2[3] = { 2021,5,5 };
	size_t data3[3] = { 2021,5,6 };
	size_t data4[3] = { 2021,5,9 };
	date.setFrom(data);
	date.setTo(data2);
	date.print();
	Room room(105, 6);
	room.bookRoom(data, data2, "sdsd", 5);
	room.bookRoom(data3, data4, "data,2", 5);
	room.printRoom();
	
	room.printRoom();
	*/
	/*
	size_t data3[3] = { 2020,4,20 };
	size_t data4[3] = { 2020,4,22 };
	size_t data5[3] = { 2020,5,20 };
	size_t data6[3] = { 2020,5,25 };
	std::string note = "Simpsons";
	room.bookRoom(data5, data6, "data5,6",5);
	room.bookRoom(data3, data4,note,5);
	room.printRoom();
	std::cout << room.findHelper(data, data2);
	std::cout << "__---------------"<< std::endl;
	std::cout << room.getArchivSize() << std::endl;
	room.getDatesFromTo(data, data2);
	HotelSystem hotel;
	hotel.addRoom(room);
	hotel.report(data, data2);
	std::cout << "-----------" << std::endl;
	hotel.find(4, data, data2);
	*/
	/*
//std::cout<<room.checkRoomAvailable(data);
	std::cout << "------" << std::endl;
	room.removeDate(data);
	room.printRoom();
	std::cout << "---" << std::endl;
	std::cout <<"Hotel: "<< std::endl;
	HotelSystem hotel;
	hotel.addRoom(room);
	//hotel.checkOut(105);
	hotel.printHotel();
	std::cout << "------" << std::endl;
	//hotel.availability(data);
	//hotel.availability();
	int year = 0;
	int day = 0;
	int month = 0;
	
	//hotel.takeRealDate();

	/*
	std::cout << "--------------------" << std::endl;
	Room room5(106, 4);
	size_t d1[3] = { 2020,7,23 };
	size_t d2[3] = { 2020,7,26 };
	size_t d10[3] = { 2020,8,23 };
	size_t d11[3] = { 2020,8,26 };
	//room5.bookRoom(d1, d2, "TheSimpsons");
	//room5.bookRoom(d10, d11, "The Simp2");
	//room5.bookRoom(d10, d11, "sdsd");
	room5.printRoom();
	Room room6(107, 4);
	size_t d4[3] = { 2020,8,20 };
	size_t d5[3] = { 2020,8,22 };
//room6.bookRoom(d4, d5, "TheSimpsons");
	room6.printRoom();
	std::cout << "------------------" << std::endl;
	HotelSystem hotel;
	hotel.addRoom(room5);
	hotel.addRoom(room6);
	hotel.printHotel();


*/






}
