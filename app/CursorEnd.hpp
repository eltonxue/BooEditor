#ifndef CURSOREND_HPP
#define CURSOREND_HPP

#include "Command.hpp"

class CursorEnd : public Command
{
public:
	virtual void execute(EditorModel& model) override;

	virtual void undo(EditorModel& model) override;

private:
	unsigned int previousColumn;

};





#endif

