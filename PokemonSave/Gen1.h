#pragma once

#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <string>
#include "Gen1Moves.h"
#include "Gen1Items.h"



namespace Gen1
{
	/* CHARACTER_CODES
	 * 0x01 == JUNK
	 * 0x02 == CTRL_PKDEX_PAGE
	 * 0x03 == CTRL_CONT
	 * 0x04 == CTRL_AUTOCONT
	 * 0x05 == CTRL_NEXT_LINE
	 * 0x06 == CTRL_BOTTOM_LINE
	 * 0x07 == CTRL_END
	 * 0x08 == CTRL_PARAGRAPH
	 * 0x09 == CTRL_CONT
	 * 0x0A == CTRL_DONE
	 * 0x0B == CTRL_PROMPT
	 * 0x0C == CTRL_DEX
	 * 0x0D == VAR_PLAYER_NAME
	 * 0x0E == VAR_RIVAL_NAME
	 * 0x0F == VAR_TARGET
	 * 0x10 == VAR_USER
	 * 0x11 == TXT_PKMN
	 * 0x12 == TXT_POKE
	 * 0x13 == TXT_ELIPSES
	 * 0x14 == TXT_PC
	 * 0x15 == TXT_TM
	 * 0x16 == TXT_TRAINER
	 * 0x17 == TXT_ROCKET
	 * 0x18 == TXT_BORDER
	 */
	const char character_map[0x100] = {
	0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x11, 0x03, 0x04, 0x00, 0x05, 0x06,
	0x00, 0x08, 0x0D, 0x0E, 0x01, 0x09, 0x12, 0x0A, 0x0B, 0x0F, 0x10, 0x14, 0x15, 0x16, 0x17, 0x0C, //address 0x50 = 0x07->0x00 for the sake of simplicity
	 'A',  'B',  'C',  'D',  'E',  'F',  'G',  'H',  'I',  'V',  'S',  'L',  'M',  ':', 0x01, 0x01,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
	 'A',  'B',  'C',  'D',  'E',  'F',  'G',  'H',  'I',  'J',  'K',  'L',  'M',  'N',  'O',  'P',
	 'Q',  'R',  'S',  'T',  'U',  'V',  'W',  'X',  'Y',  'Z',  '(',  ')',  ':',  ';',  '[',  ']',
	 'a',  'b',  'c',  'd',  'e',  'f',  'g',  'h',  'i',  'j',  'k',  'l',  'm',  'n',  'o',  'p',
	 'q',  'r',  's',  't',  'u',  'v',  'w',  'x',  'y',  'z',  'e',  'd',  'l',  's',  't',  'v',
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
	'\'', 0x01, 0x01,  '-',  'r',  'm',  '?',  '!',  '.', 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,  'M',
	 '$',  '*',  '.',  '/',  ',',  'F',  '0',  '1',  '2',  '3',  '4',  '5',  '6',  '7',  '8',  '9'};

	const char valid_characters[0x4F] = {
		0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F,
		0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x99,0x9A,0x9B,0x9C,0x9D,0x9E,0x9F,
		0xA0,0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,0xAA,0xAB,0xAC,0xAD,0xAE,0xAF,
		0xB0,0xB1,0xB2,0xB3,0xB4,0xB5,0xB6,0xB7,0xB8,0xB9,
		0xE3,0xE6,0xE7,0xE8,0xEF,0xF1,0xF2,0xF3,0xF4,0xF5,
		0xF6,0xF7,0xF8,0xF9,0xFA,0xFB,0xFC,0xFD,0xFE,0xFF,0x50
	};

	struct Address{
		static const int player_name = 0x2598;
		static const int rival_name = 0x25F6;
		static const int money = 0x25F3;
		static const int party_data = 0x2F2C;
		static const int party_pokemon = party_data + 0x8;
		static const int party_trainers = 0x303C;
		static const int party_names = 0x307E;
		static const int bag_items = 0x25C9;
	};
	
	struct RAW_Pokemon
	{
		enum Type : uint8_t
		{
			Normal		= 0x0,
			Fight		= 0x1,
			Flying		= 0x2,
			Poison		= 0x3,
			Ground		= 0x4,
			Rock		= 0x5,
			Bug			= 0x7,
			Ghost		= 0x8,
			Fire		= 0x14,
			Water		= 0x15,
			Grass		= 0x16,
			Electric	= 0x17,
			Psychic		= 0x18,
			Ice			= 0x19,
			Dragon		= 0x1A
		};
		
		uint8_t id = 0x0;
		uint16_t hp = 0x0;
		uint8_t level = 0x0;
		uint8_t status_condition = 0x0;
		Type type1 = Type::Normal;
		Type type2 = Type::Normal;
		uint8_t catch_rate = 0x0;
		uint8_t held_item = 0x0;
		uint8_t move1 = 0x0, move2 = 0x0, move3 = 0x0, move4 = 0x0;
		uint16_t trainer_id = 0x0;
		int32_t exp_points = 0x0;
		struct EVs
		{
			uint16_t hp = 0x0, atk = 0x0, def = 0x0, spd = 0x0, spc = 0x0;
			uint8_t hp_val = 0x0, atk_val = 0x0, def_val = 0x0, spd_val = 0x0, spc_val = 0x0;
		}evs;
		struct IVs
		{
			uint16_t iv = 0x0;
			uint8_t hp = 0x0, atk = 0x0, def = 0x0, spd = 0x0, spc = 0x0;
		}ivs;
		uint8_t move1_pp = 0x0, move2_pp = 0x0, move3_pp = 0x0, move4_pp = 0x0;
		//uint8_t level; REPEATED VALUE
		uint16_t max_hp = 0x0, atk = 0x0, def = 0x0, spd = 0x0, spc = 0x0;
		char raw_name[12] = "";
		char name[12] = "";
		char raw_trainer_name[12] = "";
		char trainer_name[12] = "";
	};

	struct RAW_Item
	{
		uint8_t id = 0;
		uint8_t quantity = 0;
	};

	inline bool IsCharacterValid(char c)
	{
		for (auto i = 0; i < 0x4F; i++)
		{
			if (c == valid_characters[i])
				return true;
		}
		return false;
	}
	
	class SaveFile
	{
	public:
		struct PlayerData
		{
			char raw_name[12] = "";
			char name[12] = "";
			int  money = 0;
			char raw_rival_name[12] = "";
			char rival_name[12] = "";
		}player_data;

		std::array<RAW_Pokemon, 6> party_data;
		uint8_t party_size = 0;

		std::array<RAW_Item, 20> bag_data;
		uint8_t bag_size = 0;

		void ProcessData()
		{
			//PLAYER_NAME LOADING
			for (auto i = 0; i < 0xB; i++)
				player_data.raw_name[i] = data[Address::player_name + i];
			ConvertName(player_data.raw_name, player_data.name);

			//RIVAL_NAME LOADING
			for (auto i = 0; i < 0xB; i++)
				player_data.raw_rival_name[i] = data[Address::rival_name + i];
			ConvertName(player_data.raw_rival_name, player_data.rival_name);

			//MONEY LOADING
			for (auto i = 0; i < 0x3; i++)
			{
				for (auto j = 0; j < 0x2; j++)
				{
					//PATCHING

					char cur = (data[Address::money + (0x2 - i)] >> (4 * j)) & 0b1111;
					int val = (cur)*pow(10, j + (i * 2));
					player_data.money += val;
				}
			}

			//POKEMON LOADING
			party_size = data[Address::party_data];
			for (auto i = 0; i < party_size; i++)
			{
				int offset = (0x2C * i);
				int nick_offset = 0xB * i;
				party_data[i].id = data[Address::party_pokemon + offset + 0];
				party_data[i].hp = (data[Address::party_pokemon + offset + 1] << 8) | data[Address::party_pokemon + (0x2C * i) + 2];
				party_data[i].level = data[Address::party_pokemon + offset + 3];
				party_data[i].status_condition = data[Address::party_pokemon + offset + 4];
				party_data[i].type1 = (RAW_Pokemon::Type)data[Address::party_pokemon + offset + 5];
				party_data[i].type2 = (RAW_Pokemon::Type)data[Address::party_pokemon + offset + 6];
				party_data[i].catch_rate = data[Address::party_pokemon + offset + 7];
				party_data[i].move1 = data[Address::party_pokemon + offset + 8];
				party_data[i].move2 = data[Address::party_pokemon + offset + 9];
				party_data[i].move3 = data[Address::party_pokemon + offset + 10];
				party_data[i].move4 = data[Address::party_pokemon + offset + 11];
				party_data[i].trainer_id = 0x0; //TODO ADD THE CORRECT VALUE
				party_data[i].exp_points = data[Address::party_pokemon + offset + 16]; //TODO FIX/ADD MORE BYTES (3 BYTES TOTAL)
				party_data[i].evs.hp = (data[Address::party_pokemon + offset + 17] << 8) | data[Address::party_pokemon + offset + 18];
				party_data[i].evs.atk = (data[Address::party_pokemon + offset + 19] << 8) | data[Address::party_pokemon + offset + 20];
				party_data[i].evs.def = (data[Address::party_pokemon + offset + 21] << 8) | data[Address::party_pokemon + offset + 22];
				party_data[i].evs.spd = (data[Address::party_pokemon + offset + 23] << 8) | data[Address::party_pokemon + offset + 24];
				party_data[i].evs.spc = (data[Address::party_pokemon + offset + 25] << 8) | data[Address::party_pokemon + offset + 26];
				party_data[i].evs.hp_val = data[Address::party_pokemon + offset + 17];
				party_data[i].evs.atk_val = data[Address::party_pokemon + offset + 19];
				party_data[i].evs.def_val = data[Address::party_pokemon + offset + 21];
				party_data[i].evs.spd_val = data[Address::party_pokemon + offset + 23];
				party_data[i].evs.spc_val = data[Address::party_pokemon + offset + 25];
				party_data[i].ivs.iv = (data[Address::party_pokemon + offset + 28] << 8) | (data[Address::party_pokemon + offset + 27] & 0xFF); //Returning random values with some pokemon????
				party_data[i].ivs.spd = (party_data[i].ivs.iv & 0xF000) >> 12;
				party_data[i].ivs.spc = (party_data[i].ivs.iv & 0x0F00) >> 8;
				party_data[i].ivs.atk = (party_data[i].ivs.iv & 0x00F0) >> 4;
				party_data[i].ivs.def = (party_data[i].ivs.iv & 0x000F);
				party_data[i].ivs.hp = ((party_data[i].ivs.atk & 1) << 3) |
					((party_data[i].ivs.def & 1) << 2) |
					((party_data[i].ivs.spd & 1) << 1) |
					((party_data[i].ivs.spc & 1));
				party_data[i].move1_pp = data[Address::party_pokemon + offset + 29];
				party_data[i].move2_pp = data[Address::party_pokemon + offset + 30];
				party_data[i].move3_pp = data[Address::party_pokemon + offset + 31];
				party_data[i].move4_pp = data[Address::party_pokemon + offset + 32];
				party_data[i].level = data[Address::party_pokemon + offset + 33];
				party_data[i].hp = (data[Address::party_pokemon + offset + 34] << 8) | data[Address::party_pokemon + offset + 35];
				party_data[i].atk = (data[Address::party_pokemon + offset + 36] << 8) | data[Address::party_pokemon + offset + 37];
				party_data[i].def = (data[Address::party_pokemon + offset + 38] << 8) | data[Address::party_pokemon + offset + 39];
				party_data[i].spd = (data[Address::party_pokemon + offset + 40] << 8) | data[Address::party_pokemon + offset + 41];
				party_data[i].spc = (data[Address::party_pokemon + offset + 42] << 8) | data[Address::party_pokemon + offset + 43];

				//GET POKEMON NICK
				for (auto j = 0; j < 0xB; j++)
					party_data[i].raw_name[j] = data[Address::party_names + nick_offset + j];
				ConvertName(party_data[i].raw_name, party_data[i].name);

				//GET OT
				for (auto j = 0; j < 0xB; j++)
					party_data[i].raw_trainer_name[j] = data[Address::party_trainers + nick_offset + j];
				ConvertName(party_data[i].raw_trainer_name, party_data[i].trainer_name);
			}

			//BAG LOADING
			bag_size = data[Address::bag_items];
			for(int i = 0; i < bag_size; i++)
			{
				int offset = (0x2 * i) + 1;
				bag_data[i].id = data[Address::bag_items + offset];
				bag_data[i].quantity = data[Address::bag_items + offset + 1];
			}
		}
		static void ConvertName(char* name, char* result)
		{
			for (auto i = 0; i < 0xB; i++)
			{
				auto v = name[i];
				if (IsCharacterValid(v))
					result[i] = character_map[(unsigned char)v];
			}
		}
		
	private:
		std::vector<char> data;
		friend class SaveFileReader;
	};

	class SaveFileReader
	{
	public:
		static int ReadToFile(SaveFile &sf, char const* filename)
		{
			std::ifstream file(filename,std::ios::binary|std::ios::ate);
			std::ifstream::pos_type pos = file.tellg();
			std::vector<char> result(pos);
			file.seekg(0, std::ios::beg);
			file.read(&result[0], pos);
			sf.data = result;
			file.close();
			sf.ProcessData();
			return 0;
		}
	};
}