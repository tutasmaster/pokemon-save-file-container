#pragma once

#include <array>

namespace Gen1
{
	struct Pokemon
	{
		std::string Name = "Missingno";
		uint32_t National_Dex = 0;
		uint8_t hp = 0, atk = 0, def = 0, spd = 0, spc = 0;
	};
	const Pokemon Pokemon_List[] = {
		{},
		{"Rhydon",112,105,130,120,40,45},
		{"Kangaskhan",115,95,80,90,40},
		{"Nidoran (F)",29,55,47,52,41,40},
		{"Clefairy",35,70,45,48,35,60},
		{"Spearow",21,40,60,30,70,31},
		{"Voltorb",100,40,30,50,100,55},
		{"Nidoking",34,81,92,77,85,75},
		{"Slowbro",80,65,100,70,105,80},
		{"Ivysaur",2,60,62,63,60,80},
		{"Exeggutor",103,95,95,85,55,125},
		{"Lickitung",108,90,55,75,30,60},
		{"Exeggute",102,60,40,80,40,60},
		{"Grimer",88,80,80,50,25,40},
		{"Gengar",94,60,65,60,110,130},
		{"Nidoram (M)",32,46,57,40,50,40},
		{"Nidoqueen",31,90,82,87,76,75},
		{"Cubone",105,50,50,95,35,40},
		{"Rhyhorn",111,80,85,95,25,30},
		{"Lapras",131,130,85,80,60,95},
		{"Arcanine",59,90,110,80,95,80},
		{"Mew",151,100,100,100,100,100},
		{"Gyarados",130,95,125,79,81,100},
		{"Shellder",90,30,65,100,40,45},
		{"Tentacool",72,40,40,35,70,100},
		{"Gastly",92,30,35,30,80,100},
		{"Scyther",123,70,110,80,105,55},
		{"Staryu",120,30,45,55,85,70},
		{"Blastoise",6,79,83,100,78,85},
		{"Pinsir",127,65,125,100,85,55},
		{"Tangela",114,65,55,115,60,100},
		{},
		{},
		{"Growlithe",58,55,70,45,60,50},
		{"Onix",95,35,45,160,70,30},
		{"Fearow",22,65,90,65,100,61},
		{"Pidgey",16,40,45,40,56,35},
		{"Slowpoke",79,90,65,65,15,40},
		{"Kadabra",64,40,35,30,105,120},
		{"Graveler",75,55,95,115,35,45},
		{"Chansey",112,250,5,5,50,105},
		{"Machoke",67,80,100,70,45,50},
		{"Mr. Mime",122,40,45,65,90,100},
		{"Hitmonlee",106,50,120,53,87,35},
		{"Hitmonchan",107,50,105,79,76,35},
		{"Arbok",24,60,85,69,80,65},
		{"Parasect",47,35,70,55,25,55},
		{"Psyduck",54},
		{"Drowzee",96,60,48,45,42,90},
		{"Golem",76,80,110,13},
		{},
		{"Magmar",126},
		{},
		{"Electabuzz",125,65,83,57,105,85},
		{"Magneton",82,50,60,95,70,120},
		{"Koffing",109,40,65,95,35,60},
		{},
		{"Mankey",56,40,80,35,70,35},
		{"Seel",86,65,45,55,45,70},
		{"Diglett",50,10,55,25,95,45},
		{"Tauros",128,75,100,95,110,70},
		{},
		{},
		{},
		{"Farfetch'd",83,52,65,55,60,58},
		{"Venonat",48,60,55,50,45,40},
		{"Dragonite",149,91,134,95,80,100},
		{},
		{},
		{},
		{"Duduo",84,35,85,45,75,35},
		{"Poliwag",60,40,50,40,90,40},
		{"Jynx",124,65,50,35,95,95},
		{"Moltres",146,90,100,90,90,125},
		{"Articuno",144,90,85,100,85,125},
		{"Zapdos",145,90,90,85,100,125},
		{"Ditto",132,48,48,48,48,48},
		{"Meowth",52,40,45,35,90,40},
		{"Krabby",98,30,105,90,50,25},
		{},
		{},
		{},
		{"Vulpix",37,38,41,40,65,65},
		{"Ninetales",38,73,76,75,100,100},
		{"Pikachu",25,35,55,30,90,50},
		{"Raichu",26,60,90,55,100,90},
		{},
		{},
		{"Dratini",147,41,64,45,50,50},
		{"Dragonair",148,61,84,65,70,70},
		{"Kabuto",140,30,80,90,55,45},
		{"Kabutops",141,60,115,105,80,70},
		{"Horsea",116,30,40,70,60,70},
		{"Seadra",117,55,65,95,85,95},
		{},
		{},
		{"Sandshrew",27,50,75,85,40,30},
		{"Sandslash",28,75,100,110,65,55},
		{"Omanyte",138,35,40,100,35,90},
		{"Omastar", 139,70,60,125,55,115},
		{"Jigglypuff",39,115,45,20,20,25},
		{"Wigglytuff",40,140,70,45,45,50},
		{"Eevee",133,55,55,50,55,65},
		{"Flareon",136,65,130,60,65,110},
		{"Jolteon",135,65,65,60,130,110},
		{"Vaporeon",134,130,65,60,65,110},
		{"Machop",66,70,80,50,35,35},
		{"Zubat",41,40,45,35,55,40},
		{"Ekans",23,35,60,44,55,40},
		{"Paras",46},
		{"Poliwhirl",61,65,65,65,90,50},
		{"Poliwrath",62,90,85,95,70,70},
		{"Weedle",13,40,35,30,50,20},
		{"Kakuna",14,45,25,50,35,25},
		{"Beedrill",15,65,80,40,75,45},
		{},
		{"Dodrio",85,60,110,70,100,60},
		{"Primeape",57,65,105,60,95,60},
		{"Dugtrio",51,35,80,50,120,70},
		{"Venomoth",49,70,65,60,90,90},
		{"Dewgong",87,90,70,80,70,95},
		{},
		{},
		{"Caterpie",10,45,30,35,45,20},
		{"Metapod",11,50,20,55,30,25},
		{"Butterfree",12,60,45,50,70,80},
		{"Machamp",68,90,130,80,55,65},
		{},
		{"Golduck",55,80,82,78,85,80},
		{"Hypno",97,85,73,70,67,115},
		{"Golbat",42,75,80,70,90,75},
		{"Mewtwo",150,106,110,90,130,154},
		{"Snorlax",143,160,110,65,30,65},
		{"Magikarp",129,20,10,55,80,20},
		{},
		{},
		{"Muk",89,105,105,75,50,65},
		{},
		{"Kingler",99,55,130,115,75,50},
		{"Cloyster",91,50,95,180,70,85},
		{},
		{"Electrode",101,60,50,70,140,80},
		{"Clefable",36,95,70,73,60,85},
		{"Weezing",110,65,90,120,60,85},
		{"Persian",53},
		{"Marowak",105,60,80,110,45,50},
		{},
		{"Haunter",93,45,50,45,95,115},
		{"Abra",63,25,20,15,90,105},
		{"Alakazam",65,55,50,45,120,135},
		{"Pidgeotto",17,63,60,55,71,50},
		{"Pidgeot",18,83,80,75,91,70},
		{"Starmie",121,60,75,85,115,100},
		{"Bulbasaur",1,45,49,49,45,65},
		{"Venusaur",3,80,82,83,80,100},
		{"Tentacruel",73,80,70,65,100,120},
		{},
		{"Goldeen",118,45,67,60,63,50},
		{"Seaking",119,80,92,65,68,80},
		{},
		{},
		{},
		{},
		{"Ponyta",77,50,85,55,90,65},
		{"Rapidash",78,65,100,70,105,80},
		{"Rattata",19,30,56,35,72,25},
		{"Raticate",20,55,81,60,97,50},
		{"Nidorino",33,61,72,57,65,55},
		{"Nidorina",30,70,62,67,56,55},
		{"Geodude",74,40,80,100,20,30},
		{"Porygon",137,65,60,70,40,75},
		{"Aerodactyl",142,80,105,65,130,60},
		{},
		{"Magnemite",81,25,35,70,45,95},
		{},
		{},
		{"Charmander",4,39,52,43,65,50},
		{"Squirtle",7,44,48,65,43,50},
		{"Charmeleon",5,58,64,58,80,65},
		{"Wartotle",8,59,63,80,58,65},
		{"Charizard",6,78,84,78,100,85},
		{},
		{},
		{},
		{},
		{"Oddish",43,45,50,55,30,75},
		{"Gloom",44,60,65,70,40,85},
		{"Vileplume",45,75,80,85,50,100},
		{"Bellsprout",69,50,75,35,40,70},
		{"Weepinbell",70,65,90,50,55,85},
		{"Victreebell",71,80,105,65,70,100}
	};
}