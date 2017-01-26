#ifndef BACKSPACE_HPP
#define BACKSPACE_HPP

#include "Command.hpp"

class BackSpace : public Command
{
public:

	virtual void execute(EditorModel& model) override;

	virtual void undo(EditorModel& model) override;

private:
	char character;
	unsigned int previousColumn;



};

#endif