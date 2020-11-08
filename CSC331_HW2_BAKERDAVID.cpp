// CSC331_HW2_BAKERDAVID.cpp : This file contains the 'main' function. Program execution begins and ends there.
// David Baker
// Add, delete, and list transactioms

#include <iostream>
#include <string>

struct listNames
{
    std::string name;
    int age;
    listNames* link;
};

listNames switchptr(listNames* ptr, listNames* nptr);
void insert(listNames* current, std::string userName, int userAge);
void displayList(listNames* current);
bool found(listNames* current, std::string userConvert);
bool deleteName(listNames* head, std::string userConvert);

listNames* buildList()
{
    listNames *newNode, *current;
    std::string userInput;
    std::string quit = "Q";

    std::cout << "Enter a list of people. Use 'A' to add person(s), 'D' to delete person(s), \nand 'L' to display list.";
    std::cout << "Use 'Q' to quit anytime.\n\n";

    std::cin >> userInput;

    current = NULL;

    while (userInput != quit)
    {
        std::string userName;
        int pos1, pos2, nameLen, userAge, userAgestoi;
        pos1 = 1; pos2 = userInput.find(' ', pos1 + 1);
        nameLen = pos2 - pos1 - 1;
        userName = userInput.substr(nameLen);
        userAge = std::stoi(userInput.substr( + 2)); //A Dav

        if (userInput.substr(0) == "A")
        {
            current->name = userName;
            current->age = userAge;
            insert(current, userName, userAge);
        }
        else if(userInput.substr(0) == "D")
        {
            deleteName(current, userName);
            std::cout << "Name deleted\n";
        }
        else if (userInput.substr(0) == "L")
        {
            displayList(current);
        }
        std::cout << current->name;
        std::cin >> userInput;
        return current;
    }
    
}


int main()
{
    listNames *head;
    head = buildList();
    return 0;
}

void sort(listNames **head)
{
    int swap, index;
    listNames* ptr, *nptr, *first;

    nptr = NULL;
    first = *head;

    if (first == NULL)
    {
        return;
    }

    do
    {
        swap = 0;
        ptr = first;

        while (ptr->link != nptr)
        {
            if (ptr->age > ptr->link->age)
            {
                switchptr(ptr, ptr->link);
                swap = 1;
            }
            ptr = ptr->link;
        }
        nptr = ptr;
    } while (swap);
}

listNames switchptr(listNames* ptr, listNames* nptr)
{
    listNames* newNode;
    newNode = ptr;
    ptr = nptr;
    nptr = newNode;
    ptr->link = nptr;
    return *ptr;
}

bool found(listNames *current, std::string userConvert)
{
    listNames *first;
    first = current;
    while (first != NULL)
    {
        if (userConvert == first->name)
        {
            return true;
        }
        first = first->link;
    }
    return false;
}

void displayList(listNames* current)
{
    listNames* start = current;

    while (start != NULL)
    {
        std::cout << start->name << start->age << std::endl;
        start = start->link;
    }
    std::cout << std::endl;
}

void insert(listNames *current, std::string userName, int userAge)
{
    listNames *newNode, *node;
    node = current;
    node->name = current->name;
    if (node == NULL)
    {
        node = new listNames;
        node->name = userName;
        node->age = userAge;
        node->link = NULL;
        std::cout << "Name added.\n";
        return;
    }
    else if (found(node, userName))
    {
        std::cout << "Name not added, it is already in the list." << std::endl;
        return;
    }
    else
    {
        newNode = new listNames;
        newNode->name = userName;
        newNode->age = userAge;
        newNode->link = NULL;
        node->link = newNode;
        return;
    }
    std::cout << std::endl;
}


bool deleteName(listNames* current, std::string userConvert)
{
    listNames* first, * tail, * newNode;
    first = current;
    int done = 1;
    while (!done)
    {
        if (userConvert == first->name)
        {
            newNode = first;
            first = first->link;
            delete newNode;
            return done;
        }
        first = first->link;
    }
    done;
}
