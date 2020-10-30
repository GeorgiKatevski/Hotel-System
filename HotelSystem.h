#pragma once
#include "Vector.h"
#include "Room.h"
#include <ctime>
#include <direct.h>
#pragma warning(disable:4996)
class HotelSystem
{
private:
	size_t today_date[3] = { 0,0,0 };
	D_array<Room> rooms;
	const char* Inputfile = nullptr;
public:
	
	
	HotelSystem(std::ifstream&);
	HotelSystem(const char* fileName);
	HotelSystem(const std::string& directory);
	HotelSystem() {}

	//for function checkout
	void getTm(int& year, int& month, int& day);
	void takeRealDate();

	//HotelSystem(const HotelSystem& other) = delete;
	//HotelSystem& operator=(const HotelSystem& other) = delete;
	//void checkIn(size_t room, size_t from[3], size_t to[3], std::string note);

	void checkIn(size_t room, size_t from[3], size_t to[3], const std::string& note, size_t numberOfguests);
	
	void checkIn(size_t number, size_t from[3], size_t to[3], const std::string& note);
	//D_array<Room> availability(size_t date[3]); 

	void availability(size_t date[3]);

	void availability();

	void checkOut(size_t room);

	void report(size_t from[3], size_t to[3]);

	void find(size_t beds, size_t from[3], size_t to[3]);

	//finding place for VIP
	void findSpecialGuest(size_t numberOfbeds, size_t from[3], size_t to[3]);

	void unavailable(size_t room, size_t from[3], size_t to[3], const std::string& note);

	void addRoom(const Room& room);

	void printHotel() const;


	void saveSystem(const char* file);
	void readSystem(std::ifstream& file);


	const char* getInputFile() const;

	void save();

	void saveas(const char* file);
	
	void change_directory(const std::string& str);
};