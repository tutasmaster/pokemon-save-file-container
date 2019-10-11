#pragma once

#include "Gen1Pokemon.h"

namespace Gen1
{
	struct Move
	{
		enum Category
		{
			Physical,
			Special,
			Status
		};
		std::string name = "MissingNo";
		Pokemon::Type type = Pokemon::None;
		Category category;
		uint8_t max_pp = 0;
		uint8_t power = 0;
		uint8_t accuracy = 0;
	};

	const Move Move_List[] =
	{
		{"Pound", Pokemon::Normal, Move::Physical, 35, 40, 100},
		{"Karate Chop", Pokemon::Normal,Move::Physical, 25, 50, 100},
		{"Double Slap", Pokemon::Normal, Move::Physical, 10, 15, 85},
		{"Comet Punch", Pokemon::Normal,Move::Physical,15,18,85},
		{"Mega Punch", Pokemon::Normal, Move::Physical, 20,80,85},
		{"Pay Day", Pokemon::Normal,Move::Physical,20,40,100},
		{"Fire Punch", Pokemon::Fire,Move::Physical,15,75,100},
		{"Ice Punch",Pokemon::Ice,Move::Physical,15,75,100},
		{"Thunder Punch",Pokemon::Electric,Move::Physical,15,75,100},
		{"Scratch", Pokemon::Normal, Move::Physical, 15, 75, 100},
		{"Vice Grip", Pokemon::Normal, Move::Physical, 30,55,100},
		{"Guillotine", Pokemon::Normal, Move::Physical,5,0,30},
		{"Razor Wind", Pokemon::Normal, Move::Special,10,80,75},
		{"Swords Dance",Pokemon::Normal, Move::Status,30,0,0},
		{"Cut", Pokemon::Normal,Move::Physical,30,50,95},
		{"Gust",Pokemon::Normal,Move::Special,35,40,100},
		{"Wing Attack", Pokemon::Flying, Move::Physical, 35, 35, 100},
		{"Whirlwind", Pokemon::Normal, Move::Status, 20, 0, 85},
		{"Fly", Pokemon::Flying,Move::Physical,15,90,95},
		{"Bind", Pokemon::Normal, Move::Physical, 20, 15, 75},
		{"Slam", Pokemon::Normal, Move::Physical, 20, 80, 75},
		{"Vine Whip", Pokemon::Grass, Move::Physical, 10, 35, 100},
		{"Stomp", Pokemon::Normal,Move::Physical,20,65,100},
		{"Double Kick",Pokemon::Fight, Move::Physical, 30, 30, 100},
		{"Mega Kick", Pokemon::Normal, Move::Physical, 5, 120, 75},
		{"Jump Kick", Pokemon::Fight, Move::Physical,25,70,95},
		{"Rolling Kick", Pokemon::Fight, Move::Physical,15,60,85},
		{"Sand Attack", Pokemon::Normal,Move::Status,15,0,100},
		{"Headbutt",Pokemon::Normal, Move::Physical,15,70,100},
		{"Horn Attack",Pokemon::Normal,Move::Physical, 25, 65, 100},
		{"Fury Attack",Pokemon::Normal,Move::Physical, 20, 15, 85},
		{"Horn Drill",Pokemon::Normal,Move::Physical, 5, 0, 30},
		{"Tackle",Pokemon::Normal,Move::Physical, 35, 40, 100},
		{"Body Slam",Pokemon::Normal,Move::Physical, 15, 85, 100},
		{"Wrap",Pokemon::Normal,Move::Physical, 20, 15, 85},
		{"Take Down",Pokemon::Normal,Move::Physical, 20, 90, 85},
		{"Thrash",Pokemon::Normal,Move::Physical, 20, 90, 100},
		{"Double-Edge",Pokemon::Normal,Move::Physical, 15, 100, 10},
		{"Tail Whip", Pokemon::Normal, Move::Status, 30, 0, 100},
		{"Poison Sting",Pokemon::Poison, Move::Physical, 35, 15, 100},
		{"Twineedle", Pokemon::Bug, Move::Physical, 20, 25, 100},
		{"Pin Missile", Pokemon::Bug, Move::Physical, 20, 25, 95},
		{"Leer",Pokemon::Normal, Move::Status, 30, 0, 100},
		{"Bite",Pokemon::Normal, Move::Status, 15,60, 100},
		{"Growl", Pokemon::Normal, Move::Status, 40,0, 100},
		{"Roar", Pokemon::Normal, Move::Status, 20, 0, 100},
		{"Sing",Pokemon::Normal,Move::Status,15,55},
		{"Supersonic",Pokemon::Normal,Move::Status,20,55},
		{"Sonic Boom",Pokemon::Normal,Move::Special,20,0,90},
		{"Disable",Pokemon::Normal,Move::Status,20,0,55}
	};
}