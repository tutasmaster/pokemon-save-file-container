#pragma once

#include <array>

namespace Gen1
{
	struct Pokemon
	{
		std::string Name = "Missingno";
	};
	const Pokemon Pokemon_List[] = {
		{"Rhydon"},		{"Kangaskhan"},		{"Nidoran (F)"},		{"Clefairy"},
		{"Spearow"},	{"Voltorb"},		{"Nidoking"},			{"Slowbro"},
		{"Ivysaur"},	{"Exeggutor"},		{"Lickitung"},			{"Exeggute"},
		{"Grimer"},		{"Gengar"},			{"Nidoram (M)"},		{"Nidoqueen"},
		{"Cubone"},		{"Rhyhorn"},		{"Lapras"},				{"Arcanine"},
		{"Mew"},		{"Gyarados"},		{"Shellder"},			{"Tentacool"},
		{"Gastly"},		{"Scyther"},		{"Staryu"},				{"Blastoise"},
		{"Pinsir"},		{"Tangela"},		{},						{},
		{"Growlithe"},	{"Onix"},			{"Fearow"},				{"Pidgey"},
		{"Slowpoke"},	{"Kadabra"},		{"Graveler"},			{"Chansey"},
		{"Machoke"},	{"Mr. Mime"},		{"Hitmonlee"},			{"Hitmonchan"},
		{"Arbok"},		{"Parasect"},		{"Psyduck"},			{"Drowzee"},
		{"Golem"},		{},					{"Magmar"},				{},
		{"Electabuzz"},	{"Magneton"},		{"Koffin"},				{},
		{"Mankey"},		{"Seel"},			{"Diglett"},			{"Tauros"},
		{},				{},					{},						{"Farfetch'd"},
		{"Venonat"},	{"Dragonite"},		{},						{},
		{},				{"Duduo"},			{"Poliwag"},			{"Jynx"},
		{"Moltres"},	{"Articuno"},		{"Zapdos"},				{"Ditto"},
		{"Meowth"},		{"Krabby"},			{},						{}
	};
}