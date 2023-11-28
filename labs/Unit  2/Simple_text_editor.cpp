#include <iostream>
#include <stack>
#include <string>

class CustomStack
{
private:
    std::stack<std::string> textStack;
    std::stack<std::string> undoStack;

public:
    void insert(const std::string &value)
    {
        textStack.push(value);
        undoStack.push("2 " + std::to_string(value.length()));
    }

    void deleteChars(int value)
    {
        std::string deletedChars;
        while (value > 0 && !textStack.empty())
        {
            std::string &top = textStack.top();
            int len = top.length();
            if (len <= value)
            {
                deletedChars += top;
                textStack.pop();
                value -= len;
            }
            else
            {
                deletedChars += top.substr(len - value);
                top.erase(len - value);
                value = 0;
            }
        }
        undoStack.push("1 " + deletedChars);
    }

    void get(int value)
    {
        if (value >= 0 && value < textStack.size())
        {
            std::string result;
            std::stack<std::string> tempStack = textStack;
            while (!tempStack.empty())
            {
                result += tempStack.top();
                tempStack.pop();
            }
            std::cout << result[value] << std::endl;
        }
        else
        {
            std::cout << "Invalid index" << std::endl;
        }
    }

    void undo()
    {
        if (!undoStack.empty())
        {
            std::string lastCommand = undoStack.top();
            undoStack.pop();

            char operation = lastCommand[0];
            std::string value = lastCommand.substr(2);

            if (operation == '1')
            {
                textStack.push(value);
            }
            else if (operation == '2')
            {
                deleteChars(std::stoi(value));
            }
        }
    }
};

int main()
{
    CustomStack customStack;
    std::string input;
    std::getline(std::cin, input);

    size_t pos = 0;
    while ((pos = input.find(',')) != std::string::npos)
    {
        std::string command = input.substr(0, pos);
        input.erase(0, pos + 1);

        char operation = command[0];
        std::string value = command.substr(2);

        switch (operation)
        {
        case '1':
            customStack.insert(value);
            break;
        case '2':
            customStack.deleteChars(std::stoi(value));
            break;
        case '3':
            customStack.get(std::stoi(value));
            break;
        case '4':
            customStack.undo();
            break;
        default:
            std::cout << "Invalid command: " << command << std::endl;
            break;
        }
    }

    return 0;
}