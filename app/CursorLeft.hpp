#ifndef CURSORLEFT_HPP
#define CURSORLEFT_HPP

#include "Command.hpp"

class CursorLeft : public Command
{
public:
	virtual void execute(EditorModel& model) override;

	virtual void undo(EditorModel& model) override;
};

#endif //CURSORLEFT_HPP