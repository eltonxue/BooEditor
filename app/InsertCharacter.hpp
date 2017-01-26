#ifndef INSERTCHARACTER_HPP
#define INSERTCHARACTER_HPP

#include "Command.hpp"

class InsertCharacter: public Command
{
public:
	InsertCharacter(char a)
		: character{a}
	{
	}

	virtual void execute(EditorModel& model) override;

	virtual void undo(EditorModel& model) override;

private:
	char character;

};

#endif //INSERTCHARACTER_HPP