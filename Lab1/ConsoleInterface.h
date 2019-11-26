//
// Created by tmyro on 18.11.2019.
//

#ifndef LAB1_CONSOLEINTERFACE_H
#define LAB1_CONSOLEINTERFACE_H

#include <string>
#include <random>

#include "List/Vector.h"
#include "List/List.h"
#include "List/LibVector.h"
#include "Address/IPv4.h"
#include "Address/MAC.h"
#include "List/Sort/MergeSort.h"
#include "List/Sort/QuickSort.h"
#include "List/Sort/InsertionSort.h"
#include "CustomSort.h"

/**
 * Implements console interface.
 *
 * Object that contains base list ptr and can manipulate it via parsed
 * commands. Contains methods to parse and execute commands.
 *
 * @tparam T Type of elements in the list.
 */
template <typename T>
class ConsoleInterface {
private:
    /**
     * Base list ptr to the list currently working with
     */
    BaseList<T>* list = nullptr;

    /**
     * Gets first word from string and removes it.
     *
     * Returns the first word in the input string. Words are divided with
     * spaces. The word is removed from input string.
     *
     * @param str Input string.
     * @return First word in the input string.
     */
    std::string extractWord(std::string& str);

    /**
     * Generate a random T value.
     *
     * The template is specialised for int, double, string, IPv4, IPv6, MAC.
     *
     * @return Random value of T type.
     */
    T rand_val();

    /**
     * Parses T value from string.
     *
     * The template is specialised for int, double, string, IPv4, IPv6, MAC.
     *
     * @param str Input string.
     *
     * @return T value from the string given.
     */
    T concrete_val(const std::string& str);

    /**
     * Prints given T type value.
     *
     * The template is specialised for int, double, string, IPv4, IPv6, MAC.
     *
     * @param val Parsed value.
     */
    void print(const T &val, bool spec = false);

    /**
     * Checks if the address is in subnet.
     *
     * The template is specialised for int, double, string, IPv4, IPv6, MAC. Uses
     * extractWord to parse string.
     *
     * @param str The string where the first word is index of address in the array,
     *  and the second is the address in string form.
     */
    void inSubnet(std::string& str);

    /**
     * Prints command list and description.
     */
    void help();
public:
    /**
     * Creates console interface without a list..
     */
    ConsoleInterface() = default;

    /**
     * Executes command from string.
     *
     * The main method of the class. Carses given command and executes it.
     * Supported commands:
     *  Vector
     *  List
     *  LibVector
     *  push_back
     *  pop_back
     *  push_front
     *  pop_front
     *  insert
     *  remove
     *  size
     *  print
     *  sort
     *  set_algo
     *  in_subnet
     *
     * @param str The input string.
     */
    void parse(std::string str);
};

/**
 * Calculates the polynomial hash of given string.
 *
 * @param str The input string.
 * @param n Recursion parameter. 0 By default.
 *
 * @return Hash of given string.
 */
constexpr unsigned int hash(const char *str, int n = 0) {
    return str[n] ? (hash(str, n+1) * ('z'+1)) + str[n] : 0;
}

template<typename T>
std::string ConsoleInterface<T>::extractWord(std::string &str) {
    auto n = str.find(' ');
    auto res = str.substr(0, n);
    if(n == std::string::npos) str.erase();
    else str.erase(0, n+1);
    return res;
}

template<typename T>
void ConsoleInterface<T>::parse(std::string str) {
    std::string temp_str;
    T temp_T;
    int index;
    if (!list) {
        switch (hash(extractWord(str).c_str())) {
            //Creates Vector list.
            case hash("ArrayList"):
                list = new Vector<T>;
                temp_str = extractWord(str);
                index = (temp_str.empty()) ? 0 : std::stoi(temp_str);
                for (int i = 0; i < index; i++)
                    list->push_back(rand_val());
                break;
            //Creates linked list.
            case hash("LinkedList"):
                list = new List<T>;
                temp_str = extractWord(str);
                index = (temp_str.empty()) ? 0 : std::stoi(temp_str);
                for (int i = 0; i < index; i++)
                    list->push_back(rand_val());
                break;
            //Creates LibVector list.
            case hash("VectorList"):
                list = new LibVector<T>;
                temp_str = extractWord(str);
                index = (temp_str.empty()) ? 0 : std::stoi(temp_str);
                for (int i = 0; i < index; i++)
                    list->push_back(rand_val());
                break;
            default:
                std::cout << "Create list first.\n";
                break;
        }
    }
    else{
        switch (hash(extractWord(str).c_str())) {
            //Replaces list with vector.
            case hash("ArrayList"):
                delete list;
                list = new Vector<T>;
                temp_str = extractWord(str);
                index = (temp_str.empty()) ? 0 : std::stoi(temp_str);
                for (int i = 0; i < index; i++)
                    list->push_back(rand_val());
                break;
            //Replaces list with List.
            case hash("LinkedList"):
                delete list;
                list = new List<T>;
                temp_str = extractWord(str);
                index = (temp_str.empty()) ? 0 : std::stoi(temp_str);
                for (int i = 0; i < index; i++)
                    list->push_back(rand_val());
                break;
            //Replaces list with LibVector.
            case hash("VectorList"):
                delete list;
                list = new LibVector<T>;
                temp_str = extractWord(str);
                index = (temp_str.empty()) ? 0 : std::stoi(temp_str);
                for (int i = 0; i < index; i++)
                    list->push_back(rand_val());
                break;

            case hash("push_back"):
                temp_str = extractWord(str);
                if (temp_str == "") list->push_back(rand_val());
                else list->push_back(concrete_val(temp_str));
                break;

            case hash("push_front"):
                temp_str = extractWord(str);
                if (temp_str == "") list->push_front(rand_val());
                else list->push_front(concrete_val(temp_str));
                break;

            case hash("pop_back"):
                list->pop_back();
                break;

            case hash("pop_front"):
                list->pop_front();
                break;

            case hash("insert"):
                index = std::stoi(extractWord(str));
                if (index < 0 || index > list->size()) std::cout << "Wrong index.\n";
                else {
                    temp_str = extractWord(str);
                    if(temp_str.empty())  list->insert(list->begin() + index, rand_val());
                    else list->insert(list->begin() + index, concrete_val(temp_str));
                }
                break;

            case hash("remove"):
                index = std::stoi(extractWord(str));
                if (index < 0 || index >= list->size()) std::cout << "Wrong index.\n";
                else list->extract(list->begin() + index);
                break;

            case hash("print"):
                if(list->empty()) {
                    std::cout<<"The list is empty\n";
                    break;
                }
                temp_str = extractWord(str);
                if (temp_str == "all") for (auto i : *list) print(i);
                else {
                    index = std::stoi(temp_str);
                    if (index < 0 || index >= list->size()) std::cout << "Wrong index.";
                    else print(*(list->begin() + index));
                }
                std::cout << "\n";
                break;

            case hash("sort"):
                if(extractWord(str) == "custom") list -> sort (&customComparator);
                else list->sort();
                break;

            case hash("set_algo"):
                switch (hash(extractWord(str).c_str())) {
                    case hash("merge"):
                        list->setSortAlgo(new MergeSort<T>);
                        break;
                    case hash("quick"):
                        list->setSortAlgo(new QuickSort<T>);
                        break;
                    case hash("insertion"):
                        list->setSortAlgo(new InsertionSort<T>);
                        break;
                    case hash("custom"):
                        list->setSortAlgo(new CustomSort<T>);
                        break;
                    default:
                        std::cout<<"Unknown algorithm.\n";
                }
                break;

            case hash("size"):
                std::cout<<"Size: "<<list->size()<<"\n";
                break;

            case hash("in_subnet"):
                inSubnet(str);
                break;
            case hash("help"):
                help();
                break;
            default:
                std::cout << "Unknown command.\n";
        }
    }
}

template <typename T>
void ConsoleInterface<T>::help() {
    std::cout<<"\n\n"<<
             "ArrayList [n]\n\tChange current list to Array List filled with n random values.\n\t"<<
             "n Can be ignored. In this case empty list is created."<<"\n\n\n"<<
             "LinkedList [n]\n\tChange current list to Linked List filled with n random values.\n\t"<<
             "n Can be ignored. In this case empty list is created."<<"\n\n\n"<<
             "VectorList [n]\n\tChange current list to Vector List filled with n random values.\n\t"<<
             "n Can be ignored. In this case empty list is created."<<"\n\n\n"<<
             "push_back [<val>]\n\tAdds new element in the end of the list. If <val> is given\n\t"<<
             "takes it as new value, otherwise adds a random value."<<"\n\n\n"<<
             "push_front [<val>]\n\tAdds new element in the front of the list. If <val> is given\n\t"<<
             "takes it as new value, otherwise adds a random value."<<"\n\n\n"<<
             "pop_back \n\tRemoves the last element in current list."<<"\n\n\n"<<
             "pop_front \n\tRemoves the first element in current list."<<"\n\n\n"<<
             "insert <index> [<val>] \n\tInserts the element in current list on the given index.\n\t"<<
             "If value - <val> is given, inserts it, otherwise uses random value."<<"\n\n\n"<<
             "remove <index> \n\tRemoves the element on the <index> in current list."<<"\n\n\n"<<
             "size \n\tPrints current size of the list"<<"\n\n\n"<<
             "print <index> \n\tPrints element on the given index in current list."<<"\n\n\n"<<
             "print all \n\tPrints all elements in current list in a row."<<"\n\n\n"<<
             "sort [<comp>] \n\tSorts list with current algorithm and given comparator."<<"\n\t"<<
             "<comp>:\n\t\t(Ignored): Default comparator.\n\t\tcustom: Reverse comparator.\n\n\n"<<
             "set_algo <name> \n\tChanges current list sorting algo."<<"\n\t"<<"<name>:\n\t\t"<<
             "merge: Merge sort.\n\t\tqsort: Quick sort\n\t\tinsertion: Insertion sort\n\t\tcustom: Bubble sort\n\n\n"<<
             "in_subnet <n> <subnet>\n\tChecks if addresses number <n> in list is in given subnet.\n\n";

}

#endif //LAB1_CONSOLEINTERFACE_H
