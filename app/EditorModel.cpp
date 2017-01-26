// EditorModel.cpp
//
// ICS 45C Fall 2016
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class


#include "EditorModel.hpp"
#include "EditorException.hpp"


EditorModel::EditorModel()
	: currentLine{1}, currentColumn{1}, totalLines{1}, currentError{""}, previousSubstr{""}
{
	completeText.push_back("");
}


int EditorModel::cursorLine() const
{
    return currentLine;
}


int EditorModel::cursorColumn() const
{
    return currentColumn;
}


int EditorModel::lineCount() const
{
    return totalLines;
}


const std::string& EditorModel::line(int lineNumber) const
{
	unsigned int index = lineNumber - 1;
    return completeText[index];
}


const std::string& EditorModel::currentErrorMessage() const
{
    return currentError;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
	currentError = errorMessage;
}


void EditorModel::clearErrorMessage()
{
	currentError = "";
}

void EditorModel::setCursorLine(unsigned int lineNumber)
{
	currentLine = lineNumber;
}

void EditorModel::setCursorColumn(unsigned int columnNumber)
{
	currentColumn = columnNumber;
}

void EditorModel::setTotalLines(unsigned int num)
{
	totalLines = num;
}

char EditorModel::getPreviousCharacter() const
{
	return previousCharacter;
}

std::string EditorModel::getPreviousSubstr() const
{
	return previousSubstr;
}


void EditorModel::moveRight()
{
	if (currentColumn > line(currentLine).size())
	{
		if (currentLine == totalLines)
		{
			EditorException error{"End of Text File"};
			setErrorMessage(error.getReason());
			throw error;
		}
		else
		{
			currentColumn = 1;
			currentLine++;
		}
	}
	else
	{
		currentColumn++;
		clearErrorMessage();
	}
}

void EditorModel::moveLeft()
{
	if (currentColumn == 1)
	{
		if (currentLine == 1)
		{
			EditorException error{"Beginning of Text File"};
			setErrorMessage(error.getReason());
			throw error;

		}
		else
		{
			currentLine--;
			currentColumn = line(currentLine).size() + 1;
		}
	}
	else
	{
		currentColumn--;
		clearErrorMessage();
	}
}

void EditorModel::moveDown()
{
	if (currentLine == totalLines)
	{
		EditorException error{"Reached Maximum Lines"};
		setErrorMessage(error.getReason());
		throw error;
	}
	else
	{
		if (currentColumn > line(currentLine + 1).size() + 1)
		{
			currentColumn = line(currentLine + 1).size() + 1;
		}
		currentLine++;
		clearErrorMessage();
	}

}

void EditorModel::moveUp()
{
	if (currentLine == 1)
	{
		EditorException error{"Reached Minimum Lines"};
		setErrorMessage(error.getReason());
		throw error;
	}
	else
	{
		if (currentColumn > line(currentLine - 1).size() + 1)
		{
			currentColumn = line(currentLine - 1).size() + 1;
		}
		currentLine--;
		clearErrorMessage();
	}
}

void EditorModel::moveHome()
{
	if (currentColumn == 1)
	{
		EditorException error{""};
		setErrorMessage(error.getReason());
		throw error;
	}
	else
	{
		currentColumn = 1;
	}
}

void EditorModel::moveEnd()
{
	if (currentColumn == line(currentLine).size() + 1)
	{
		EditorException error{""};
		setErrorMessage(error.getReason());
		throw error;
	}
	else
	{
		currentColumn = line(currentLine).size() + 1;
	}

}

void EditorModel::insertCharacter(char a)
{
	unsigned int lineIndex = currentLine - 1;
	unsigned int columnIndex = currentColumn - 1;

	completeText[lineIndex].insert(completeText[lineIndex].begin() + columnIndex, a);

	currentColumn++;

}

void EditorModel::backSpace()
{
	if (currentColumn == 1 and currentLine == 1)
	{
		EditorException error{"Cannot Backspace Anymore"};
		setErrorMessage(error.getReason());
		throw error;
	}
	else if (currentColumn == 1)
	{
		unsigned int lineIndex = currentLine - 1;

		currentColumn = completeText[lineIndex - 1].size() + 1;

		completeText[lineIndex - 1] += completeText[lineIndex];
		completeText[lineIndex] = "";

		totalLines--;
		currentLine--;

		if (currentColumn > 1)
		{
			unsigned int columnIndex = currentColumn - 2;

			previousCharacter = completeText[lineIndex - 1].at(columnIndex);
		}
			

	}
	else
	{
		unsigned int lineIndex = currentLine - 1;
		unsigned int columnIndex = currentColumn - 2;

		previousCharacter = completeText[lineIndex].at(columnIndex);
		completeText[lineIndex].erase(completeText[lineIndex].begin() + columnIndex);

		currentColumn--;

	}
}

void EditorModel::newLine()
{
	unsigned int lineIndex = currentLine - 1;
	unsigned int columnIndex = currentColumn - 1;
	unsigned int sizeOfString = completeText[lineIndex].size();

	previousSubstr = completeText[lineIndex].substr(columnIndex, sizeOfString - columnIndex);

	completeText[lineIndex].erase(columnIndex, sizeOfString - columnIndex);

	currentColumn = 1;
	currentLine++;
	totalLines++;
	
	completeText.insert(completeText.begin() + lineIndex + 1, previousSubstr); 
	
}

void EditorModel::undoNewLine(std::string& substr, unsigned int previousColumn)
{
	if (currentLine != 1)
	{
		unsigned int lineIndex = currentLine - 1;

		currentColumn = previousColumn;

		completeText.erase(completeText.begin() + lineIndex);

		currentLine--;
		totalLines--;

		completeText[lineIndex - 1] += substr;
	}
}

void EditorModel::deleteLine()
{
	unsigned int lineIndex = currentLine - 1;

	if (currentLine == 1 and totalLines == 1) // PREVENT DELETING IF NOTHINGS THERE
	{
		currentColumn = 1;
		completeText[0] = "";
	}
	else 
	{
		if (currentLine == totalLines)
		{
			currentLine--;
		}
		totalLines--;
		completeText.erase(completeText.begin() + lineIndex);
		if (line(currentLine).size() < currentColumn)
		{
			currentColumn = line(currentLine).size() + 1;
		}
	}
}

void EditorModel::undoDeleteLine(std::string& pline, unsigned int previousColumn, unsigned int previousLine)
{
	if (currentLine == 1 and totalLines == 1 and completeText[0] == "" and previousLine == 1)
	{
		completeText.insert(completeText.begin() + currentLine - 1, pline);
		currentColumn = previousColumn;
	}
	else
	{
		if (pline != "" and previousLine == 1)
		{
			if (line(currentLine) == "" and previousLine == 1 and totalLines == 1)
			{
				currentLine--;
				totalLines--;
			}
			else
			{
				unsigned int lineIndex = currentLine - 1;

				completeText.insert(completeText.begin() + lineIndex, pline);

				currentColumn = previousColumn;

				totalLines++;

			}
		}
		else if (previousLine < totalLines + 1)
		{
			totalLines++;
			unsigned int lineIndex = currentLine - 1;

			completeText.insert(completeText.begin() + lineIndex, pline);

			currentColumn = previousColumn;
		}
		else
		{
			currentLine++;
			totalLines++;

			unsigned int lineIndex = currentLine - 1;

			completeText.insert(completeText.begin() + lineIndex, pline);

			currentColumn = previousColumn;
		}
	}

}