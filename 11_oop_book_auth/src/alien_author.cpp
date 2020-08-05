#include "alien_author.h"

AlienAuthor::AlienAuthor(enum AlienSkinType skinType, const std::string& name)
	: skinType(skinType),
	 Author(name)
{

}

AlienAuthor::~AlienAuthor()
{

}

std::string AlienAuthor::toString() const
{
	std::string result;
	if (skinType == AlienSkinType::SCALY)
	{
		result = "Scalibus: " + this->name;
	}
	else if (skinType == AlienSkinType::SLIMEY)
	{
		result = "His royal slimeness: " + this->name;
	}
	else 
	{
		result = this->name;
	}
	return result;
}