#ifndef CURSORUP_HPP
#define CURSORUP_HPP

#include "Command.hpp"


class CursorUp: public Command
{
public:

	virtual void execute(EditorModel& model) override;

    virtual void undo(EditorModel& model) override;
    
private:
	unsigned int previousUpColumn;
};



#endif