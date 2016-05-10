#pragma once
#include "button.h"

class spellButton:public button
{
public:
	spellButton(std::string path1,std::string path2,int spellName);
	~spellButton();
	int sName;

	void update();


};