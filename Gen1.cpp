#include "Gen1.h"

void Gen1::SaveFile::ProcessData()
{
	//PLAYER_NAME LOADING
	for (auto i = 0; i < 0xB; i++)
		player_data.raw_name[i] = data[0x2598 + i];
	ConvertName();
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

