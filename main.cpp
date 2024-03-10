#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    int request;
    std::cout << "Enter your request (1,2,3)" << std::endl;
    std::cout << "1. Add phone number and surname to directory;" << std::endl;
    std::cout << "2. Find name by phone number;" << std::endl;
    std::cout << "3. find phone by last name: " << std::endl;
    std::cin >> request;

    std::map<std::string, std::string> NumberToSurname;

    NumberToSurname["2-50-50"] = "Ivanov";
    NumberToSurname["8-906-256-00-63"] = "Petrov";
    NumberToSurname["8-456-223-14-14"] = "Sidorov";
    NumberToSurname["8-965-777-77-77"] = "Ivanov";

    std::map<std::string, std::vector<std::string>> SurnameToNumber {
            {"Ivanov", {"2-50-50", "8-965-777-77-77"}},
            {"Petrov", {"8-906-256-00-63"}},
            {"Sidorov", {"8-456-223-14-14"}}
    };


    std::string phone_number;
    std::string surname;
    if (request == 1)
    {
        std::cout << "Enter phone number: ";
        std::cin >> phone_number;
        std::cout << "Enter last name: ";
        std::cin >> surname;

        NumberToSurname.insert(std::pair<std::string, std::string>(phone_number, surname));
        SurnameToNumber[surname].push_back(phone_number);
    }

    if (request == 2)
    {
        std::cout << "Enter phone number:";
        std::cin >> phone_number;

        std::map<std::string, std::string>::iterator it = NumberToSurname.find(phone_number);
        if (it == NumberToSurname.end()) std::cout << "Not found" << std::endl;
        else std::cout << "Find the contact: " << it->second << std::endl;
    }

    if (request == 3)
    {
        std::cout << "Enter last name: ";
        std::cin >> surname;

        std::map<std::string, std::vector<std::string>>::iterator it = SurnameToNumber.find(surname);
        if (it == SurnameToNumber.end()) std::cout << "Not found" << std::endl;
        else {
            for (std::vector<std::string>::iterator sit = it->second.begin();
                 sit != it->second.end(); ++sit)
            {
                std::cout << *sit << " ";
            }
            std::cout << std::endl;
        }
    }
}
