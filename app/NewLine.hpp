#ifndef NEWLINE_HPP
#define NEWLINE_HPP

#include "Command.hpp"
#include <string>

class NewLine : public Command
{
public:
	virtual void execute(EditorModel& model) override;

	virtual void undo(EditorModel& model) override;

private:
	std::string previousSubstr;
	unsigned int previousColumn;

};

#endif