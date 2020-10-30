#include "HotelSystem.h"

HotelSystem::HotelSystem(std::ifstream& file)
{
readSystem(file);

}

HotelSystem::HotelSystem(const char* fileName)
{
	this->Inputfile = fileName;
	std::ifstream file(fileName);
	readSystem(file);
}

HotelSystem::HotelSystem(const std::string& directory)
{
	
	
	change_directory(directory);

}

void HotelSystem::getTm(int& year, int& month, int& day)
{
		time_t tt;
		time(&tt);
		tm TM = *localtime(&tt);
		year = TM.tm_year + 1900;
		month = TM.tm_mon + 1;
		day = TM.tm_mday;
}

void HotelSystem::takeRealDate()
{
	int year, month, day;
	getTm(year, month, day);
	today_date[0] = year;
	today_date[1] = month;
	today_date[2] = day;
	std::cout << day << " " << month << " " << year << '\n';
}

void HotelSystem::checkIn(size_t room, size_t from[3], size_t to[3],const std::string& note, size_t numberOfguests)
{
	bool isValidRoom = false;
	for (size_t i = 0; i < rooms.getSize(); i++)
	{
		if (rooms[i].getNumber() == room)
		{
			isValidRoom = true;
			rooms[i].bookRoom(from, to, note,numberOfguests);
			break;
		}
	}
	if (!isValidRoom)
	{
		std::cout << "Invalid Room" << std::endl;
	}
}

void HotelSystem::checkIn(size_t number, size_t from[3], size_t to[3], const std::string& note)
{
	
	bool isValidRoom = false;
	size_t bedsInRoom = 0;
	for (size_t i = 0; i < rooms.getSize(); i++)
	{
		if (rooms[i].getNumber() == number)
		{
			isValidRoom = true;
			bedsInRoom=rooms[i].getBeds();
		}
	}
	if (!isValidRoom)
	{
		std::cout << "Invalid Room" << std::endl;
		return;
	}
	checkIn(number, from, to, note, bedsInRoom);


}

void HotelSystem::availability(size_t date[3])
{

	for (size_t i = 0; i < rooms.getSize(); i++)
	{
		if (rooms[i].checkRoomAvailable(date))
		{
			rooms[i].printRoom();
		}
	}

}

void HotelSystem::availability()
{
	takeRealDate();
	availability(today_date);
}

void HotelSystem::checkOut(size_t room)
{
	takeRealDate();
	bool isValidRoom = false;
	for (size_t i = 0; i < rooms.getSize(); i++)
	{

		if (room == rooms[i].getNumber())
		{
			isValidRoom = true;
			rooms[i].removeDate(today_date);
			break;
		}
	}
	if (!isValidRoom)
	{
		std::cout << "Invalid room" <<std::endl;
	}
}

void HotelSystem::report(size_t from[3], size_t to[3])
{
	std::cout << "Report for all rooms in the hotel" << std::endl;
	for (size_t i = 0; i < rooms.getSize(); i++)
	{
		std::cout << "Room number: " << rooms[i].getNumber() << std::endl;
		rooms[i].getDatesFromTo(from, to);
	}
}

void HotelSystem::find(size_t beds, size_t from[3], size_t to[3])
{
	D_array<Room> rs;
	for (size_t i = 0; i < rooms.getSize(); i++)
	{
		if (rooms[i].getBeds() >= beds)
		{
				if (rooms[i].findHelper(from, to))
				{
					rs.pushBack(rooms[i]);
				}
			
		}

	}
	if (rs.getSize() != 0)
	{
		Room room = rs[0];
		for (size_t i = 1; i < rs.getSize(); i++)
		{
			if (rs[i].getBeds() < room.getBeds())
			{
				room = rs[i];
			}
		}

		room.printRoom();
	}
	else
	{
		std::cout << "There is no room with this number of beds" << std::endl;
	}
}

void HotelSystem::findSpecialGuest(size_t numberOfbeds, size_t from[3], size_t to[3])
{
	//-----недовършена

	/*
	D_array<Room> freeRooms;
	//people in rooms with more beds
	D_array<Room> lessPeopleRooms;
	bool flagIsValid = true;
	for (size_t j = 0; j < rooms.getSize(); j++)
	{
		for (size_t i = 0; i < rooms[j].getDates().getSize(); i++)
		{
			
			if (!rooms[j].checkDate(from, to, rooms[j].getDates()[i].from, rooms[j].getDates()[i].to) || !rooms[j].checkDate(rooms[j].getDates()[i].from, rooms[j].getDates()[i].to, from, to))
			{

				if(rooms[j].getDates()[i].numberOfpeople<rooms[j].getBeds())
				{
					lessPeopleRooms.pushBack(rooms[j]);
				}
				flagIsValid = false;
				break;
			}

		}
		if (flagIsValid ==true)
		{
			freeRooms.pushBack(rooms[j]);
			flagIsValid = false;
		}

	}

	/*
	for (size_t  i = 0; i < lessPeopleRooms.getSize(); i++)
	{
		if (lessPeopleRooms[i].getBeds() < numberOfbeds)
		{
		
		}

	}

	*/



}

void HotelSystem::unavailable(size_t room, size_t from[3], size_t to[3], const std::string& note)
{
	bool isValidRoom = false;
	for (size_t i = 0; i < rooms.getSize(); i++)
	{
		if (rooms[i].getNumber() == room)
		{
			isValidRoom = true;
			rooms[i].bookRoom(from, to, note,0);
			break;
		}
	}
	if (!isValidRoom)
	{
		std::cout << "Invalid Room" << std::endl;
	}
}

void HotelSystem::addRoom(const Room& room)
{
	rooms.pushBack(room);
}

void HotelSystem::printHotel() const
{

	for (size_t i = 0; i < rooms.getSize(); i++)
	{
		rooms[i].printRoom();
	}
}

void HotelSystem::saveSystem(const char*file1)
{
	std::ofstream file(file1);
	if (!file)
	{
		std::cout << "Cannot open the file" << std::endl;
		return;
	}
	
	if (file.is_open())
	{
		for (size_t i = 0; i < rooms.getSize(); i++)
		{
			rooms[i].saveRoom(file1);
		}
	}
	file.close();
}

void HotelSystem::readSystem(std::ifstream& file)
{

	if (!file)
	{
		std::cout << "Cannot open the file" << std::endl;
		return;
	}

	while (!file.eof())
	{
		Room room;
		room.readRoom(file);
		rooms.pushBack(room);
	}

	file.close();


}

const char* HotelSystem::getInputFile() const
{
	
		return  Inputfile;
	
}

void HotelSystem::save()
{
	saveSystem(getInputFile());
}

void HotelSystem::saveas(const char* file)
{
	saveSystem(file);
}

void HotelSystem::change_directory(const std::string& str)
{
	
	
		//"C:\\Users\\Georgi\\Desktop\\Test.txt"
		std::string str2 = str;

		int count = 0;
		for (size_t i = 0; i < str2.length(); i++)
		{

			if (str2[i] == '\\')
			{
				count++;

			}

		}
		std::cout << count << std::endl;
		int count1 = 0;

		std::string str3 = "";
		std::string str4 = "";
		for (size_t i = 0; i < str2.length(); i++)
		{
			if (count == count1)
			{
				str3 += str2[i];
			}
			if (str2[i] == '\\')
			{
				count1++;
			}
			if (count != count1)
			{
				str4 += str2[i];
			}
		}

		std::cout << str3 << " " << str4;
		const char* directory = str4.c_str();
		//--https://docs.microsoft.com/ru-ru/cpp/c-runtime-library/reference/chdir-wchdir?view=vs-2019
		const char* file = str3.c_str();
		if (_chdir(directory))
		{
			switch (errno)
			{
			case ENOENT:
				printf("Unable to locate the directory: %s\n", directory);
				break;
			case EINVAL:
				printf("Invalid buffer.\n");
				break;
			default:
				printf("Unknown error.\n");
			}
		}
		else {
			std::ifstream file1(file);
			if (!file1)
			{
				std::cout << "error" << std::endl;
			}
			else
			{
				std::cout << "File loaded successfully" << std::endl;
			}

			//--//--https://docs.microsoft.com/ru-ru/cpp/c-runtime-library/reference/chdir-wchdir?view=vs-2019
			HotelSystem system(file1);
			//system.setAdmin(1);
			//system.setFlag(1);
			//system.booksAll();
		}

	





}
