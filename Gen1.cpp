#include "Gen1.h"

void Gen1::SaveFile::ProcessData()
{
	//PLAYER_NAME LOADING
	for (auto i = 0; i < 0xB; i++)
		player_data.raw_name[i] = data[0x2598 + i];
	ConvertName();

	for (auto i = 0; i < 0x3; i++)
	{
		for(auto j = 0; j < 0x2; j++)
		{
			char cur = (data[0x25F3 + i] >> (4 * j)) & 0b1111;
			int val = (cur) * ((pow(100, i)) * pow(10, i));
			player_data.money += val;
		}
	}
}

void Gen1::SaveFile::ConvertName()
{
	for(auto i = 0; i < 0xB; i++)
	{
		auto v = player_data.raw_name[i];
		if (IsCharacterValid(v))
			player_data.name[i] = character_map[(unsigned char)v];
	}
}

bool Gen1::IsCharacterValid(char c)
{
	for(auto i = 0; i < 0x4F; i++)
	{
		if (c == valid_characters[i])
			return true;
	}
	return false;
}

