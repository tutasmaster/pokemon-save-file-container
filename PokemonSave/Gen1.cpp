#include "Gen1.h"

void Gen1::SaveFile::ProcessData()
{
	//PLAYER_NAME LOADING
	for (auto i = 0; i < 0xB; i++)
		player_data.raw_name[i] = data[Address::player_name + i];
	ConvertName(player_data.raw_name,player_data.name);

	//RIVAL_NAME LOADING
	for (auto i = 0; i < 0xB; i++)
		player_data.raw_rival_name[i] = data[Address::rival_name + i];
	ConvertName(player_data.raw_rival_name, player_data.rival_name);

	//MONEY LOADING
	for (auto i = 0; i < 0x3; i++)
	{
		for(auto j = 0; j < 0x2; j++)
		{
			//PATCHING
			
			char cur = (data[Address::money + (0x2 - i)] >> (4 * j)) & 0b1111;
			int val = (cur) * pow(10, j + (i * 2));
			player_data.money += val;
		}
	}

	//POKEMON LOADING
	party_size = data[Address::party_data];
	for(auto i = 0; i < party_size; i++)
	{
		int offset = (0x2C * i);
		int nick_offset = 0xB * i;
		party_data[i].id =					data[Address::party_pokemon + offset + 0];
		party_data[i].hp =					(data[Address::party_pokemon + offset + 1] << 8) | data[Address::party_pokemon + (0x2C * i) + 2];
		party_data[i].level =				data[Address::party_pokemon + offset + 3];
		party_data[i].status_condition =	data[Address::party_pokemon + offset + 4];
		party_data[i].type1 =				(RAW_Pokemon::Type)data[Address::party_pokemon + offset + 5];
		party_data[i].type2 =				(RAW_Pokemon::Type)data[Address::party_pokemon + offset + 6];
		party_data[i].catch_rate =			data[Address::party_pokemon + offset + 7];
		party_data[i].move1 =				data[Address::party_pokemon + offset + 8];
		party_data[i].move2 =				data[Address::party_pokemon + offset + 9];
		party_data[i].move3 =				data[Address::party_pokemon + offset + 10];
		party_data[i].move4 =				data[Address::party_pokemon + offset + 11];
		party_data[i].trainer_id =			0x0; //TODO ADD THE CORRECT VALUE
		party_data[i].exp_points =			data[Address::party_pokemon + offset + 16]; //TODO FIX/ADD MORE BYTES (3 BYTES TOTAL)
		party_data[i].evs.hp =				(data[Address::party_pokemon + offset + 17] << 8) | data[Address::party_pokemon + offset + 18];
		party_data[i].evs.atk =				(data[Address::party_pokemon + offset + 19] << 8) | data[Address::party_pokemon + offset + 20];
		party_data[i].evs.def =				(data[Address::party_pokemon + offset + 21] << 8) | data[Address::party_pokemon + offset + 22];
		party_data[i].evs.spd =				(data[Address::party_pokemon + offset + 23] << 8) | data[Address::party_pokemon + offset + 24];
		party_data[i].evs.spc =				(data[Address::party_pokemon + offset + 25] << 8) | data[Address::party_pokemon + offset + 26];
		party_data[i].evs.hp_val =			data[Address::party_pokemon + offset + 17];
		party_data[i].evs.atk_val =			data[Address::party_pokemon + offset + 19];
		party_data[i].evs.def_val =			data[Address::party_pokemon + offset + 21];
		party_data[i].evs.spd_val =			data[Address::party_pokemon + offset + 23];
		party_data[i].evs.spc_val =			data[Address::party_pokemon + offset + 25];
		party_data[i].ivs.iv =				(data[Address::party_pokemon + offset + 28] << 8) | (data[Address::party_pokemon + offset + 27] & 0xFF); //Returning random values with some pokemon????
		party_data[i].ivs.spd =				(party_data[i].ivs.iv & 0xF000) >> 12;
		party_data[i].ivs.spc =				(party_data[i].ivs.iv & 0x0F00) >> 8;
		party_data[i].ivs.atk =				(party_data[i].ivs.iv & 0x00F0) >> 4;
		party_data[i].ivs.def =				(party_data[i].ivs.iv & 0x000F);
		party_data[i].ivs.hp =				((party_data[i].ivs.atk & 1) << 3) |
											((party_data[i].ivs.def & 1) << 2) |
											((party_data[i].ivs.spd & 1) << 1) |
											((party_data[i].ivs.spc & 1));
		party_data[i].move1_pp =			data[Address::party_pokemon + offset + 29];
		party_data[i].move2_pp =			data[Address::party_pokemon + offset + 30];
		party_data[i].move3_pp =			data[Address::party_pokemon + offset + 31];
		party_data[i].move4_pp =			data[Address::party_pokemon + offset + 32];
		party_data[i].level =				data[Address::party_pokemon + offset + 33];
		party_data[i].hp =					(data[Address::party_pokemon + offset + 34] << 8) | data[Address::party_pokemon + offset + 35];
		party_data[i].atk =					(data[Address::party_pokemon + offset + 36] << 8) | data[Address::party_pokemon + offset + 37];
		party_data[i].def =					(data[Address::party_pokemon + offset + 38] << 8) | data[Address::party_pokemon + offset + 39];
		party_data[i].spd =					(data[Address::party_pokemon + offset + 40] << 8) | data[Address::party_pokemon + offset + 41];
		party_data[i].spc =					(data[Address::party_pokemon + offset + 42] << 8) | data[Address::party_pokemon + offset + 43];

		//GET POKEMON NICK
		for(auto j = 0; j < 0xB; j++)
			party_data[i].raw_name[j] = data[Address::party_names + nick_offset + j];
		ConvertName(party_data[i].raw_name, party_data[i].name);

		//GET OT
		for (auto j = 0; j < 0xB; j++)
			party_data[i].raw_trainer_name[j] = data[Address::party_trainers + nick_offset + j];
		ConvertName(party_data[i].raw_trainer_name, party_data[i].trainer_name);
	}
	
}

void Gen1::SaveFile::ConvertName(char* name, char* result)
{
	for(auto i = 0; i < 0xB; i++)
	{
		auto v = name[i];
		if (IsCharacterValid(v))
			result[i] = character_map[(unsigned char)v];
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

