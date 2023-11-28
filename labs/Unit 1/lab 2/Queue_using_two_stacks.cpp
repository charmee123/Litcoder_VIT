#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

class CustomQueue
{
public:
    void enqueue(int element)
    {
        stack1.push(element);
    }

    int dequeue()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if (!stack2.empty())
        {
            int front_element = stack2.top();
            stack2.pop();
            return front_element;
        }

        return -1; // or any suitable value to indicate an empty queue
    }

    int front()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if (!stack2.empty())
        {
            return stack2.top();
        }

        return -1; // or any suitable value to indicate an empty queue
    }

private:
    std::stack<int> stack1; // For enqueue operation
    std::stack<int> stack2; // For dequeue operation
};

void process_queries(const std::vector<std::string> &queries)
{
    CustomQueue custom_queue;
    for (const auto &query : queries)
    {
        std::istringstream iss(query);
        int query_type;
        iss >> query_type;

        if (query_type == 1)
        {
            int element;
            iss >> element;
            custom_queue.enqueue(element);
        }
        else if (query_type == 2)
        {
            custom_queue.dequeue();
        }
        else if (query_type == 3)
        {
            int front_element = custom_queue.front();
            if (front_element != -1)
            {
                std::cout << front_element << std::endl;
            }
        }
    }
}

int main()
{
    // Example usage for Exercise-1
    std::vector<std::string> exercise_1_input = {"1 42", "2", "1 14", "3"};
    process_queries(exercise_1_input);

    // Example usage for Exercise-2
    std::vector<std::string> exercise_2_input = {"1 23", "2", "1 14", "3", "2", "1 78", "3"};
    process_queries(exercise_2_input);

    return 0;
}