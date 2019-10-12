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
		static const int box_items = 0x27E6;
		static const int pokemon_box_1 = 0x4000;
		static const int pokemon_box_7 = 0x6000;
		static const int current_box = 0x284C;
		static const int current_box_data = 0x30C0;
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

		struct Item_Box
		{
			std::array<RAW_Item, 50> data;
			uint8_t size = 0;
		}item_box;

		struct Pokemon_Box
		{
			uint8_t size = 0;
			std::array<RAW_Pokemon, 20> data;
		};

		std::array<RAW_Pokemon, 6> party_data;
		uint8_t party_size = 0;

		std::array<RAW_Item, 20> bag_data;
		uint8_t bag_size = 0;

		std::array<Pokemon_Box, 12> box_data;
		uint8_t current_box = 0;

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
				GetPokemonFromAddress(
					Address::party_pokemon + offset, 
					party_data[i], 
					Address::party_trainers + nick_offset, 
					Address::party_names + nick_offset
				);
			}

			//BAG LOADING
			bag_size = data[Address::bag_items];
			for(int i = 0; i < bag_size; i++)
			{
				int offset = (0x2 * i) + 1;
				bag_data[i].id = data[Address::bag_items + offset];
				bag_data[i].quantity = data[Address::bag_items + offset + 1];
			}
			//ITEM BOX LOADING
			item_box.size = data[Address::box_items];
			for(int i = 0; i < item_box.size; i++)
			{
				int offset = (0x2 * i) + 1;
				item_box.data[i].id = data[Address::box_items + offset];
				item_box.data[i].quantity = data[Address::box_items + offset + 1];
			}

			//LOADING POKEMON BOXES FROM BANK 2
			for(int i = 0; i < 6; i++)
			{
				int offset = 0x462 * i;
				int pokemon_offset = offset + 0x16;

				box_data[i].size = data[Address::pokemon_box_1 + offset] > 20 ? 0 : data[Address::pokemon_box_1 + offset];
				for(int j = 0; j < box_data[i].size; j++)
				{
					int pk_offset = (0x21 * j) + pokemon_offset + Address::pokemon_box_1;
					int nick_offset = 0xB * j;
					GetPokemonFromAddress(
						pk_offset,
						box_data[i].data[j],
						Address::pokemon_box_1 + offset + 0x2AA + (j * 0xB),
						Address::pokemon_box_1 + offset + 0x386 + (j * 0xB)
					);
				}
			}

			//LOADING POKEMON BOXES FROM BANK 3
			for (int i = 7; i < 12; i++)
			{
				int offset = 0x462 * (i-7);
				int pokemon_offset = offset + 0x16;

				box_data[i].size = data[Address::pokemon_box_7 + offset] > 20 ? 0 : data[Address::pokemon_box_7 + offset];
				for (int j = 0; j < box_data[i].size; j++)
				{
					int pk_offset = (0x21 * j) + pokemon_offset + Address::pokemon_box_7;
					int nick_offset = 0xB * j;
					GetPokemonFromAddress(
						pk_offset,
						box_data[i].data[j],
						Address::pokemon_box_7 + offset + 0x2AA + (j * 0xB),
						Address::pokemon_box_7 + offset + 0x386 + (j * 0xB)
					);
				}
			}

			current_box = (unsigned) data[Address::current_box] & 0b01111111;
			box_data[current_box].size = data[Address::current_box_data];
			for(int i = 0; i < box_data[current_box].size; i++)
			{
				int offset = (0x21 * i) + 0x16;
				GetPokemonFromAddress(
					Address::current_box_data + offset,
					box_data[current_box].data[i],
					Address::current_box_data + 0x2AA + (i * 0xB),
					Address::current_box_data + 0x386 + (i * 0xB)
				);
			}
		}

		void GetPokemonFromAddress(int address, RAW_Pokemon &p, int ot_addr, int name_addr)
		{
			p.id = data[address + 0];
			p.hp = (data[address + 1] << 8) | data[address + 2];
			p.level = data[address + 3];
			p.status_condition = data[address + 4];
			p.type1 = (RAW_Pokemon::Type)data[address + 5];
			p.type2 = (RAW_Pokemon::Type)data[address + 6];
			p.catch_rate = data[address + 7];
			p.move1 = data[address + 8];
			p.move2 = data[address + 9];
			p.move3 = data[address + 10];
			p.move4 = data[address + 11];
			p.trainer_id = 0x0; //TODO ADD THE CORRECT VALUE
			p.exp_points = (data[address + 16] << 16) | (data[address + 15] << 8) | data[address + 14];
			p.evs.hp = (data[address + 17] << 8) | data[address + 18];
			p.evs.atk = (data[address + 19] << 8) | data[address + 20];
			p.evs.def = (data[address + 21] << 8) | data[address + 22];
			p.evs.spd = (data[address + 23] << 8) | data[address + 24];
			p.evs.spc = (data[address + 25] << 8) | data[address + 26];
			p.evs.hp_val = data[address + 17];
			p.evs.atk_val = data[address + 19];
			p.evs.def_val = data[address + 21];
			p.evs.spd_val = data[address + 23];
			p.evs.spc_val = data[address + 25];
			p.ivs.iv = (data[address + 28] << 8) | (data[address + 27] & 0xFF); //Returning random values with some pokemon????
			p.ivs.spd = (p.ivs.iv & 0xF000) >> 12;
			p.ivs.spc = (p.ivs.iv & 0x0F00) >> 8;
			p.ivs.atk = (p.ivs.iv & 0x00F0) >> 4;
			p.ivs.def = (p.ivs.iv & 0x000F);
			p.ivs.hp = ((p.ivs.atk & 1) << 3) |
				((p.ivs.def & 1) << 2) |
				((p.ivs.spd & 1) << 1) |
				((p.ivs.spc & 1));
			p.move1_pp = data[address + 29];
			p.move2_pp = data[address + 30];
			p.move3_pp = data[address + 31];
			p.move4_pp = data[address + 32];
			//p.level = data[address + 33];
			p.hp = (data[address + 34] << 8) | data[address + 35];
			p.atk = (data[address + 36] << 8) | data[address + 37];
			p.def = (data[address + 38] << 8) | data[address + 39];
			p.spd = (data[address + 40] << 8) | data[address + 41];
			p.spc = (data[address + 42] << 8) | data[address + 43];

			for (auto j = 0; j < 0xB; j++)
				p.raw_name[j] = data[name_addr + j];
			ConvertName(p.raw_name, p.name);

			//GET OT
			for (auto j = 0; j < 0xB; j++)
				p.raw_trainer_name[j] = data[ot_addr + j];
			ConvertName(p.raw_trainer_name, p.trainer_name);

			CalculateStats(p);
		}

		void CalculateStats(RAW_Pokemon &p)
		{
			Pokemon curPokemon = Pokemon_List[p.id];

			p.hp = ((((curPokemon.hp + p.ivs.hp) * 2 + (sqrt(p.evs.hp) / 4)) * p.level) / 100) + p.level + 10;
			p.atk = ((((curPokemon.atk + p.ivs.atk) * 2 + (sqrt(p.evs.atk) / 4)) * p.level) / 100) + 5;
			p.def = ((((curPokemon.def + p.ivs.def) * 2 + (sqrt(p.evs.def) / 4)) * p.level) / 100) + 5;
			p.spc = ((((curPokemon.spc + p.ivs.spc) * 2 + (sqrt(p.evs.spc) / 4)) * p.level) / 100) + 5;
			p.spd = ((((curPokemon.spd + p.ivs.spd) * 2 + (sqrt(p.evs.spd) / 4)) * p.level) / 100) + 5;
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