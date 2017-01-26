#ifndef CURSORHOME_HPP
#define CURSORHOME_HPP

#include "Command.hpp"

class CursorHome : public Command
{
public:
	virtual void execute(EditorModel& model) override;

	virtual void undo(EditorModel& model) override;

private:
	unsigned int previousColumn;

};





#endif

