#include "Room.h"


Room::Room():number(100), beds(4), isAvailable(true){}

Room::Room(size_t _number, size_t _beds) {
	setNumber(_number);
	setBeds(_beds);
}
void Room::setBeds(size_t _number)
{
	beds = _number;
}


int Room::getArchivSize()
{
	int m = archive.getSize();
	return m;
}

void Room::getDatesFromTo(size_t from[3], size_t to[3])
{
	for (size_t i = 0; i < archive.getSize(); i++)
	{
		if (from[0] <= archive[i].from[0] && to[0] >= archive[i].to[0])
		{

			if (from[1] < archive[i].from[1] && to[1] > archive[i].to[1])
			{
					archive[i].print();
			}
			if (from[1] == archive[i].from[1] && to[1] == archive[i].to[1])
			{
				if (from[2] <= archive[i].from[2] && to[2] >= archive[i].to[2])
				{
							

					archive[i].print();
				}
					
			}
			if (from[1] < archive[i].from[1] && to[1] == archive[i].to[1])
			{
				if (to[2] >= archive[i].to[2])
				{
					archive[i].print();
				}
			}
			if (from[1] == archive[i].from[1] && to[1] > archive[i].to[1])
			{
				if (from[2] <= archive[i].from[2])
				{
					archive[i].print();
				}
			}

		}

	}



}

void Room::removeDate(size_t date[3])
{
	int index = 0;
	bool flag = false;
	for (size_t i = 0; i < datesBooked.getSize(); i++)
	{
		if (datesBooked[i].from[0] == date[0] && datesBooked[i].to[0] == date[0])
		{
			if (datesBooked[i].from[1] == date[1] && datesBooked[i].to[1] == date[1])
			{
				if (date[2]<datesBooked[i].from[2] || date[2]>datesBooked[i].to[2])
				{
					flag = true;
				}
				else
				{
					flag = false;
					index = i;
					break;
				}
			}

			if (datesBooked[i].from[1] == date[1] && datesBooked[i].to[1] != date[1])
			{
				if (date[2] < datesBooked[i].from[2])
				{
					flag = true;
				}
				else
				{
					flag = false;
					index = i;
					break;
				}

			}
			if (datesBooked[i].from[1] != date[1] && datesBooked[i].to[1] == date[1])
			{
				if (date[2] > datesBooked[i].to[2])
				{
					flag = true;
				}
				else
				{
					flag = false;
					index = i;
					break;
				}
			}
			if (datesBooked[i].from[1] != date[1] && datesBooked[i].to[1] != date[1])
			{
				flag = true;
			}

		}
		if (datesBooked[i].from[0] != date[0] && datesBooked[i].to[0] == date[0])
		{
			if (datesBooked[i].to[1] < date[1])
			{
				flag = true;
			}
			else
			{
				if (datesBooked[i].to[1] == date[1])
				{
					if (date[2] > datesBooked[i].to[2])
					{
						flag = true;
					}
					else
					{
						flag = false;
						index = i;
						break;
					}
				}

			}


		}
		if (datesBooked[i].from[0] == date[0] && datesBooked[i].to[0] != date[0])
		{
			if (datesBooked[i].from[1] > date[1])
			{
				flag = true;
			}
			else
			{
				if (date[1] == datesBooked[i].from[1])
				{
					if (date[2] < datesBooked[i].from[2])
					{
						flag = true;
					}
					else
					{
						flag = false;
						index = i;
						break;
					}
				}
				else
				{
					flag = false;
					index = i;
					break;
				}
			}


		}
		if (datesBooked[i].from[0] != date[0] && datesBooked[i].to[0] != date[0])
		{
			flag = true;
		}

	}

	if (flag == true)
	{
		std::cout << "Wrong date--------------------" << std::endl;
	}
	else
	{
		datesBooked.remove(index);
	}




}

void Room::addDate(size_t from[3], size_t to[3], const std::string& note,size_t number)
{
	Dates date;
	date.setFrom(from);
	date.setTo(to);
	date.setNote(note);
	assert(number <= beds && "More people than bed in the room");
	date.setNumberOfPeople(number);
	datesBooked.pushBack(date);
	archive.pushBack(date);
}

bool Room::checkRoomAvailable(size_t date[3])
{
	bool flag = false;
	if (datesBooked.getSize() == 0)
	{
		return true;
	}
	for (size_t i = 0; i < datesBooked.getSize(); i++)
	{
		if (datesBooked[i].from[0] == date[0] && datesBooked[i].to[0] == date[0])
		{
			if (datesBooked[i].from[1] == date[1] && datesBooked[i].to[1] == date[1])
			{
				if (date[2]<datesBooked[i].from[2] || date[2]>datesBooked[i].to[2])
				{
					flag = true;
				}
				else
				{
					flag = false;
					break;
				}
			}

			if (datesBooked[i].from[1] == date[1] && datesBooked[i].to[1] != date[1])
			{

				if (date[2] < datesBooked[i].from[2])
				{
					flag = true;
				}
				else
				{
					flag = false;
					break;
				}

			}
			if (datesBooked[i].from[1] != date[1] && datesBooked[i].to[1] == date[1])
			{
				if (date[2] > datesBooked[i].to[2])
				{
					flag = true;
				}
				else
				{
					flag = false;
					break;
				}
			}
			if (datesBooked[i].from[1] != date[1] && datesBooked[i].to[1] != date[1])
			{
				flag = true;
			}

		}
		if (datesBooked[i].from[0] != date[0] && datesBooked[i].to[0] == date[0])
		{
			if (datesBooked[i].to[1] < date[1])
			{
				flag = true;
			}
			else
			{
				if (datesBooked[i].to[1] == date[1])
				{
					if (date[2] > datesBooked[i].to[2])
					{
						flag = true;
					}
					else
					{
						flag = false;
						break;
					}
				}

			}


		}
		if (datesBooked[i].from[0] == date[0] && datesBooked[i].to[0] != date[0])
		{
			if (datesBooked[i].from[1] > date[1])
			{
				flag = true;
			}
			else
			{
				if (date[1] == datesBooked[i].from[1])
				{
					if (date[2] < datesBooked[i].from[2])
					{
						flag = true;
					}
					else
					{
						flag = false;
						break;
					}
				}
				else
				{
					flag = false;
					break;
				}
			}


		}
		if (datesBooked[i].from[0] != date[0] && datesBooked[i].to[0] != date[0])
		{
			flag = true;
		}

	}

	return flag;
}

void Room::setNumber(size_t _number)
{
	number = _number;
}
//this function checks if the range of dates are different 
//used in many functions for example 
//if we checkin we have to check if this date is free 
bool Room::checkDate(size_t from[3], size_t to[3], size_t from2[3], size_t to2[3])
{
	if (from[0] == from2[0] && to[0] == to2[0])
	{
		if (from[1] == from2[1] && to[1] == to2[1])
		{
			if (from2[2] < from[2])
			{
				return to2[2] < from[2];
				
				
			}
			if (from2[2] > to[2])
			{
				return true;
			}

			return false;
		}


		if (from[1] == from2[1] && to[1] != to2[1])
		{
			if (to[1] > to2[1])
			{
				return false;
			}
			else
			{
				return to[2] < from2[2];
				
			}

		}

		if (from[1] != from2[1] && to[1] == to2[1])
		{
			if (from[1] < from2[1])
			{
				if (to[1] == to2[1])
				{
					//TO DO NA EDIN RED
					return to[2] < from2[2];
				
				}
			}
			if (from[1] > from2[1])
			{
				if (to[1] == to2[1])
				{
					//TO DO NA EDIN RED
					return to2[2] < from[2];
					
				}
			}

			return false;
		}

		if (from[1] != from2[1] && to[1] != to2[1])
		{
			if (from[1] < from2[1] && to[1] < from2[1])
			{
				return true;
			}
			if (from[1] > to2[1] && to[1] > to2[2])
			{
				return true;
			}
			if (from2[1] < from[1] && to2[1] < from[1])
			{
				return true;
			}
			if (from2[1] > to[1] && to2[1] > to[2])
			{
				return true;
			}
			if (to[2] < from2[2])
			{
				return true;
			}
			else
			{
				if (to2[2] < from[2])
				{
					return true;
				}
				return false;
			}

		}
	}


	if (from[0] != from2[0] && to[0] == to2[0])
	{

		if (to[1] == from2[1])
		{
			//TO DO NA EDIN RED
			if (to[2] < from2[2])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (to[1] < from2[1])
			{
				std::cout <<"--------------------"<< to[1] << "  "<< from2[1];
				return true;
			}
			else
			{
				return false;
			}
		}


	}
	if (from[0] == from2[0] && to[0] != to2[0])
	{
		if (to[1] == from2[1])
		{
			//TO DO NA EDIN RED
			if (to[2] < from2[2])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (to[1] < from2[1])
			{
				std::cout << "dasdasdasdasd" << to[1] << " " << from2[1];
				return true;
			}
			else
			{
				return false;
			}
		}

	

	}




	//ako dvete godini sa razlichni 
	if (from[0] != from2[0] && to[0] != to2[0])
	{
		
		if (to[0] < from2[0])
		{
			return true;
		}
		else
		{
			//TO DO NA EDIN RED
			return to2[0] < from[0];
			
		}

	}



	return false;



	
	}



//this function will be used for function checkin
void Room::bookRoom(size_t from[3], size_t to[3],const std::string& note,size_t numberOfPeople)
{
	bool flag = false;
	if (datesBooked.getSize() == 0)
	{
		Dates date;
		date.setFrom(from);
		date.setTo(to);
		date.setNote(note);
		assert(date.from[2] != 0 && "Invalid date");
		assert(date.to[2] != 0 && "Invalid date");
		assert(date.from[1] != 0 && "Invalid date");
		assert(date.to[1] != 0 && "Invalid date");
		assert(numberOfPeople <= beds && "More people than bed in the room");
		date.setNumberOfPeople(numberOfPeople);
		datesBooked.pushBack(date);
		archive.pushBack(date);
		addDate(from, to,note,numberOfPeople);
		
	}
	else
	{
		
		for (size_t i = 0; i < datesBooked.getSize(); i++)
		{
			if (!checkDate(from, to, datesBooked[i].from, datesBooked[i].to) || !checkDate(datesBooked[i].from, datesBooked[i].to, from,to ))
			{
				flag = true;
				break;
			}
		
		}
		if (flag == false)
		{
			Dates date;
			date.setFrom(from);
			date.setTo(to);
			date.setNote(note);
			assert(date.from[2] != 0 && "Invalid date");
			assert(date.to[2] != 0 && "Invalid date");
			assert(date.from[1] != 0 && "Invalid date");
			assert(date.to[1] != 0 && "Invalid date");
			assert(numberOfPeople <= beds && "More people than bed in the room");
			date.setNumberOfPeople(numberOfPeople);
			datesBooked.pushBack(date);
			archive.pushBack(date);
		}
		else
		{
			std::cout << "Dates are not available" << std::endl;
		}
	}
}

void Room::check(size_t date[3])
{
	bool flag = false;
	
}

size_t Room::getNumber() const
{
	return number;
}

D_array<Dates> Room::getDates() const
{
	return datesBooked;
}

const size_t Room::getBeds() const
{
	return beds;
}

void Room::printRoom() const
{
	std::cout << "Number: " << number << " " << "Number of Beds: " << beds << " " << "Note: " << std::endl;
	std::cout << "Booked dates: " << std::endl;
	for (size_t i = 0; i < datesBooked.getSize(); i++)
	{
		std::cout << "From: " << datesBooked[i].from[0] << "-" << datesBooked[i].from[1] << "-" << datesBooked[i].from[2] <<std::endl;
		std::cout << "To: " << datesBooked[i].to[0] << "-" << datesBooked[i].to[1] << "-" << datesBooked[i].to[2] << std::endl;
		std::cout << "Note: " << datesBooked[i].note << std::endl;
	}


}

//function to print if the room is free in a definite date;
//will be used in HotelSystem  for function available<date> 
void Room::printDates(size_t date[3]) const
{
	bool flag = false;
	for (size_t i = 0; i < datesBooked.getSize(); i++)
	{
		if(datesBooked[i].from[1] > date[1] || datesBooked[i].to[1]<date[1])
		{
			flag = true;		
		}
		else
		{
			if (date[1] == datesBooked[i].from[1])
			{
				if (date[2]<datesBooked[i].from[2])
				{
					flag = true;
					
				}
				else
				{
					if (date[1]==datesBooked[i].to[1] && date[2] > datesBooked[i].to[2])
					{
						flag = true;
					}
					else
					{
						flag = false;
						break;
					}
				
				}
			}
			
			
		}
		
		}
	if (flag == true)
	{
		std::cout << "Number: " << number << " " << "Number of Beds: " << beds  << std::endl;
	}
}

bool Room::findHelper(size_t from[3], size_t to[3])
{
	if (datesBooked.getSize() == 0)
	{
		return true;
	}
	else
	{
	
		for (size_t i = 0; i < datesBooked.getSize(); i++)
		{
			if (!checkDate(from, to, datesBooked[i].from, datesBooked[i].to))
			{
				return false;
				break;
			}

		}
	}
	return true;


}



void Room::saveRoom(const char* file1)
{

	
		std::ofstream file(file1, std::ios::out | std::ios::app);
		if (!file)
		{
			std::cout << "Cannot open the file" << std::endl;
			return;
		}

		file << "Room:" << " " << number << " " << beds << " ";
		for (size_t i = 0; i < archive.getSize(); i++)
		{
			for (size_t j = 0; j < 3; j++)
			{
				file << archive[i].from[j] << " ";
			}
			for (size_t j = 0; j < 3; j++)
			{
				file << archive[i].to[j] << " ";
			}
			file << archive[i].note<<" ";

		}
		file.close();

	
}

void Room::readRoom(std::ifstream& file)
{
	if (!file)
	{
		std::cout << "Cannot open the file." << std::endl;
		return;
	}
	std::string r;
	
	size_t date_from[3];
	size_t date_to[3];
	std::string note;
	std::string str;
	
	int count=0;
	bool flag = false;
	while (!file.eof())
	{
	
		file >> str;
		if (str == "Room:")
		{
			if (count != 0)
			{
				break;
			}
			else
			{
				count++;
				file >> number >> beds;
				
				file >> str;
				if (str == "Room:")
				{
					break;
					}
				else
				{
					date_from[0] = stoi(str);
				}
			}
		}
		else
		{
			if (flag == false)
			{
				count++;
				number = std::stoi(str);
				file >> beds;
				file >> str;
				if (str == "Room:")
				{
					break;
				}
				{
					if (stoi(str) >= 2020 && stoi(str) <= 2100)
					{
						date_from[0] = stoi(str);
					}
					else
					{
						break;
					}
				}
				}
			else
			{
				date_from[0] = stoi(str);
			}
		}
		for (size_t j = 1; j < 3; j++)
		{
			file >> date_from[j];
		}
		for (size_t j = 0; j < 3; j++)
		{
			file >> date_to[j];
		}
		file >> note;
		Dates date;
		date.setFrom(date_from);
		date.setTo(date_to);
		date.setNote(note);
		archive.pushBack(date);
		datesBooked.pushBack(date);
		flag = true;
	}
	


}
