#pragma once
#include "Enemy.h"

class CharacterNode
{
public:
	CharacterNode(Enemy &enemy, CharacterNode* pNext = nullptr);
	~CharacterNode();
	CharacterNode *next() { return _pNext; };
	Enemy getEnemy() { return _enemy;};

private:
	Enemy _enemy;
	CharacterNode* _pNext;
};

