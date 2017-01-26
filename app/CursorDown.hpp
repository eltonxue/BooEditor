#ifndef CURSORDOWN_HPP
#define CURSORDOWN_HPP

#include "Command.hpp"

class CursorDown: public Command
{
public:

	virtual void execute(EditorModel& model) override;

    virtual void undo(EditorModel& model) override;
  
private:
	unsigned int previousDownColumn;


};

#endif