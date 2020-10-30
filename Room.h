#pragma once
#include <string>
#include "Vector.h"
#include "Dates.h"
#include <fstream>
#include <cassert>
class Room {
private:
	size_t beds;
	int number;
	bool isAvailable; 
	D_array<Dates> datesBooked;
	D_array<Dates> archive;
public:
	Room();
	//const size_t & 
	Room(size_t _number,size_t numberOfBeds);
	
	bool checkRoomAvailable(size_t date[3]);
	void setNumber(size_t _number);
	void setBeds(size_t _beds);

	int getArchivSize();
	void getDatesFromTo(size_t from[3], size_t to[3]);
	void removeDate(size_t date[3]);
	void addDate(size_t from[3], size_t to[3], const std::string& note,size_t numberOfPeople);
	bool checkDate(size_t from[3], size_t to[3], size_t from2[3], size_t to2[3]);
	void bookRoom(size_t from[3], size_t to[3],const std::string& note,size_t numberOfPeople);
	


	void check(size_t date[3]);
	size_t getNumber() const;
	

	D_array<Dates> getDates() const;
	const size_t getBeds() const;


	void printRoom() const;
	void printDates(size_t date[3]) const;

	bool findHelper(size_t from[3], size_t to[3]);



	void saveRoom(const char* file);
	void readRoom(std::ifstream& file);


};