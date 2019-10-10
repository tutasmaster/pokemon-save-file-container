#pragma once

#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <string>



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

	const int valid_characters[0x4F] = {
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
		Type type1 = Type::Normal, type2 = Type::Normal;
		uint8_t catch_rate = 0x0;
		uint8_t held_item = 0x0;
		uint8_t move1 = 0x0, move2 = 0x0, move3 = 0x0, move4 = 0x0;
		uint16_t trainer_id = 0x0;
		int32_t exp_points = 0x0;
		struct EVs
		{
			uint16_t hp = 0x0, atk = 0x0, def = 0x0, spd = 0x0, spc = 0x0, iv = 0x0;
		}evs;
		uint8_t move1_pp = 0x0, move2_pp = 0x0, move3_pp = 0x0, move4_pp = 0x0;
		//uint8_t level; REPEATED VALUE
		uint16_t max_hp = 0x0, atk = 0x0, def = 0x0, spd = 0x0, spc = 0x0;
	};

	const std::array<Pokemon, 0x100> Pokemon_List;
	
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

		void ProcessData();
		static void ConvertName(char* name, char* result);
		
	private:
		std::vector<char> data;
		friend class SaveFileReader;
	};

	bool IsCharacterValid(char c);

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