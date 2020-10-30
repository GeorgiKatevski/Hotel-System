#include "Dates.h"

void Dates::setTo(size_t _to[3])
{
	if (_to[0] < 2020)
	{
		return;
	}
	else
	{
		to[0] = _to[0];
	}
	if (_to[1] < 1 || _to[1]>12)
	{
		return;
	}
	else
	{
		to[1] = _to[1];
	}
	if (_to[1] == 1 || _to[1]==3 || _to[1]==5 || _to[1]==7 || _to[1]==8 || _to[1]== 10 || _to[1]==12)
	{
		if (_to[2] > 31 || _to[2] < 1)
		{
			return;
		}
		else
		{
			to[2] = _to[2];
		}
	}
	if (_to[1] == 2)
	{
		if (_to[0] % 4 == 0)
		{
			if (_to[0] % 100 == 0)
			{
				if (_to[0] % 400 == 0)
					if (_to[2] > 29 || _to[2]<1)
					{
						return;
					}
					else
					{
						to[2] = _to[2];
					}
				else
					if (_to[2] > 28 || _to[2] < 1)
					{
						return;
					}
					else
					{
						to[2] = _to[2];
					}
			}
			else
				if (_to[2] > 28 || _to[2] < 1)
				{
					return;
				}
				else
				{
					to[2] = _to[2];
				}
		}
		else
			if (_to[2] > 28 || _to[2] < 1)
			{
				return;
			}
			else
			{
				to[2] = _to[2];
			}

	}

	if (_to[1] == 4 || _to[1] == 6 || _to[1] == 9 || _to[1] == 11)
	{
		if (_to[2] > 30 || _to[2] < 1)
		{
			return;
		}
		else
		{
			to[2] = _to[2];
		}
	}

}

void Dates::setFrom(size_t _to[3])
{
	if (_to[0] < 2020)
	{
		return;
	}
	else
	{
		from[0] = _to[0];
	}
	if (_to[1] < 1 || _to[1]>12)
	{
		return;
	}
	else
	{
		from[1] = _to[1];
	}
	if (_to[1] == 1 || _to[1] == 3 || _to[1] == 5 || _to[1] == 7 || _to[1] == 8 || _to[1] == 10 || _to[1] == 12)
	{
		if (_to[2] > 31 || _to[2] < 1)
		{
			return;
		}
		else
		{
			from[2] = _to[2];
		}
	}
	if (_to[1] == 2)
	{
		if (_to[0] % 4 == 0)
		{
			if (_to[0] % 100 == 0)
			{
				if (_to[0] % 400 == 0)
					if (_to[2] > 29 || _to[2] < 1)
					{
						return;
					}
					else
					{
						from[2] = _to[2];
					}
				else
					if (_to[2] > 28 || _to[2] < 1)
					{
						return;
					}
					else
					{
						from[2] = _to[2];
					}
			}
			else
				if (_to[2] > 28 || _to[2] < 1)
				{
					return;
				}
				else
				{
					from[2] = _to[2];
				}
		}
		else
			if (_to[2] > 28 || _to[2] < 1)
			{
				return;
			}
			else
			{
				from[2] = _to[2];
			}

	}

	if (_to[1] == 4 || _to[1] == 6 || _to[1] == 9 || _to[1] == 11)
	{
		if (_to[2] > 30 || _to[2] < 1)
		{
			return;
		}
		else
		{
			from[2] = _to[2];
		}
	}

}


void Dates::setNote(const std::string& _note)
{
	if (!_note.empty())
	{
		note = _note;
	}
}

void Dates::setNumberOfPeople(int _numberOfPeople)
{
	numberOfpeople = _numberOfPeople;
}



void Dates::print() const
{
	for (size_t i = 0; i <= 2; i++)
	{
		std::cout << from[i] << ",";
	}
	std::cout << std::endl;

		for (size_t i = 0; i <= 2; i++)
		{
			std::cout << to[i] << ",";
		}
		std::cout << std::endl;
		std::cout <<"Used by: "<<note << std::endl;
		if (from[1] == to[1])
		{
			std::cout << "Days: " << to[2] - from[2] << std::endl;
		}
		if (from[1] != to[1])
		{
			int days;
			if (from[1] == 1 || from[1] == 3 || from[1] == 5 || from[1] == 7 || from[1] == 8 || from[1] == 10 || from[1] == 12)
			{
				days = 31 - from[2];
				days += to[2];
				std::cout << "Days: " << days << std::endl;
			}
			if (from[1] == 2)
			{
				if (from[0] % 4 == 0)
				{
					if (from[0] % 100 == 0)
					{
						if (from[0] % 400 == 0)
						{
							days = 29 - from[2];
							days += to[2];
							std::cout << "Days: " << days << std::endl;
						}
						else
						{
							days = 28 - from[2];
							days += to[2];
							std::cout << "Days: " << days << std::endl;
						}
					}
					else
					{
						days = 28 - from[2];
						days += to[2];
						std::cout << "Days: " << days << std::endl;
					}
				}
				else
				{
					days = 28 - from[2];
					days += to[2];
					std::cout << "Days: " << days << std::endl;
				}
			}
			if (from[1] == 4 || from[1] == 6 || from[1] == 9 || from[1] == 11)
			{
				days = 30 - from[2];
				days += to[2];
				std::cout << "Days: " << days << std::endl;
			}
			
		}




}