#pragma once

#include "author.h"

enum AlienSkinType
{
	SCALY = 0,
	SLIMEY = 1
};

class AlienAuthor : public Author
{
private:
	enum AlienSkinType skinType;

public:
	AlienAuthor(enum AlienSkinType skinType, const std::string& name="anon");
	virtual ~AlienAuthor();
	virtual std::string toString() const;
};
