#pragma once
#include "CharacterNode.h"

/**
contains a single linked list of characters in a given room of the dungeon

**/


class CharacterList
{
public:
	CharacterList(int capacity, CharacterNode* node);
	~CharacterList();

	int numberCharacters;
	int maxCapacity;
	CharacterNode* pHead;
};

