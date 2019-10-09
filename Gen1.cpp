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
		char v = player_data.raw_name[i];
		if(v >= (char)0x80 && v < (char)0x9A)		//UPPER-CASE
			player_data.name[i] = v - 0x80 + 0x41;
		else if(v >= (char)0xA0 && v <= (char)0xBA) //LOWER-CASE
			player_data.name[i] = v - 0xA0 + 0x61;
		else if(v == 0x50)							//NULL TERMINATOR
			player_data.name[i] = 0x00;
		else{
			switch(v)
			{
			case (char)0x9A:
				player_data.name[i] = '(';
				break;
			case (char)0x9B:
				player_data.name[i] = ')';
				break;
			case (char)0x9C:
				player_data.name[i] = ':';
				break;
			case (char)0x9D:
				player_data.name[i] = ';';
				break;
			case (char)0x9E:
				player_data.name[i] = '[';
				break;
			case (char)0x9F:
				player_data.name[i] = ']';
				break;
			case (char)0xE3:
				player_data.name[i] = '-';
				break;
			case (char)0xE6:
				player_data.name[i] = '?';
				break;
			case (char)0xE7:
				player_data.name[i] = '!';
				break;
			case (char)0xF3:
				player_data.name[i] = '/';
				break;
			case (char)0xF2:
				player_data.name[i] = '.';
				break;
			case (char)0xF4:
				player_data.name[i] = ',';
				break;
			case (char)0xF1:
				player_data.name[i] = '*';
				break;
			case (char)0xEF: //MALE SYMBOL
				player_data.name[i] = '#';
				break;
			case (char)0xF5: //FEMALE SYMBOL
				player_data.name[i] = '$';
				break;
			case (char)0xE1: //PK SYMBOL
				player_data.name[i] = '%';
				break;
			case (char)0xE2: //MN SYMBOL
				player_data.name[i] = '&';
				break;
			}
		}
		
	}
}
