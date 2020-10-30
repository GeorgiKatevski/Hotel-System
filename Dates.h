#pragma once
#include <iostream>
#include <string>



struct Dates
{
	Dates(){}


	size_t from[3] = {0,0,0};

	size_t to[3] = {0,0,0};


	int numberOfpeople=0;

	std::string note = "";
	void setFrom(size_t from[3]);
	void setTo(size_t to[3]);
	void setNote(const std::string& _note);
	void setNumberOfPeople(int _numberOfPeople);
	void print() const;

};