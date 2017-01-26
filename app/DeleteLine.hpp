#ifndef DELETELINE_HPP
#define DELETELINE_HPP

#include "Command.hpp"
#include <string>

class DeleteLine : public Command
{
public:
	virtual void execute(EditorModel& model) override;

	virtual void undo(EditorModel& model) override;

private:
	std::string previousLine;
	unsigned int previousColumn;
	unsigned int previousLineNumber;

};

#endif