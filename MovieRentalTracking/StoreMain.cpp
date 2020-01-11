// ---------------------------- StoreMain.cpp --------------------------------
//
// Programmer Name: Satine Paronyan
// Course Section Number: CSS 502A
// Created: 02/23/2019
// Modified: 03/17/2019
//
//
// --------------------------------------------------------------------------
// PURPOSE:
// Driver of the program (rental store tracking system). Reads and processes
// three files with different formating. The first file is to read all the
// store inventroy (rental movies); the second file is to read all the store
// customers's data and the third file to read in the commands and perford
// operations like print the inventory, print a specific customer's transaction
// history and borrow of return a movie.
// --------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// It is critical that all the files to be read in in the required order:
// - all the store inventory
// - all the customer data
// - the commands
//
// The inventory and command files may have invalid format, the program will
// process all the lines of the input and notify user with error message about
// this invalid inputs
// --------------------------------------------------------------------------

#include<string>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <utility>

#include "movie.h"
#include "classics.h"
#include "drama.h"
#include "comedy.h"
#include "inventoryDB.h"
#include "customerDB.h"
#include "action.h"

using namespace std;

// used to read in the classic movies into map
struct ClassicsKey
{
    std::string directorName;
    std::string movieTitle;
    int month;
    int year;

    ClassicsKey ()
    {
        directorName = "";
        movieTitle = "";
        month = 0;
        year = 0;
    }


    bool operator==(const ClassicsKey &other) const
    {
        return (this->directorName == other.directorName &&
            this->movieTitle == other.movieTitle &&
            this->month == other.month &&
            this->year == other.year);
    }
};

// Needed in order for the hash map to be able to store
// Classics movies with key ClassicsKey.
namespace std {
    template <> struct hash<ClassicsKey>
    {
        size_t operator()(const ClassicsKey & x) const
        {
            return 17 * hash<std::string>()(x.directorName) +
                19 * hash<std::string>()(x.movieTitle) +
                23 * x.month + 29 * x.year;
        }
    };
};


// Drives the program
int main() {
    // ----------------------------------------------------------------------
    // ----------------- read inventory into store data base  ---------------
    // ----------------------------------------------------------------------
   std::string fName = "data4movies.txt";
    //std::string fName = "movies4.txt";

    fstream moviesFile(fName);
    if (moviesFile.fail())
    {
        cerr << "\nCan't find movie file: " << fName << endl;
        return 1;
    }

    InventoryDB storeInventoryDB;  // inventory data base for movies

    std::string movieItem;   // holds movie items (read line by line)
    std::string movieGenre;  // holds first element of the string

    // needed to be able to process multiple lines of the same
    // classic movie with the different major actors
    unordered_map<ClassicsKey, Classics> classicsMap;

     while (!moviesFile.eof())
     {
         getline(moviesFile, movieItem);
         movieGenre = movieItem.substr(0, movieItem.find(',')); // needed for switch

         if (movieItem.empty())
         {  // if the read string is empty then do go into switch statements
             continue;
         }

         switch (movieItem.at(0))
         {
             case 'F':
             {
                 Comedy comedy(movieItem);
                 storeInventoryDB.addComedyInventory(comedy);
                 break;
             }
             case 'D':
             {
                 Drama drama(movieItem);
                 storeInventoryDB.addDramaInventory(drama);
                 break;
             }
             case 'C':
             {
                 Classics cl(movieItem);
                 ClassicsKey k1;
                 k1.directorName = cl.getDirector();
                 k1.movieTitle = cl.getTitle();
                 k1.month = cl.getReleaseMonth();
                 k1.year = cl.getReleaseYear();
                 auto it = classicsMap.find (k1);  // returns reference to element
                 if (it == classicsMap.end())
                 { // if key is not in a map
                     classicsMap.insert(std::make_pair(k1, cl));
                 }
                 else
                 { // update stock number of the existing classics movie
                     int oldStock = it->second.getStock();
                     it->second.setStock(oldStock + cl.getStock());

                     // if the major actor for the same classics differ
                     // then add a new actor to the existing classics
                     std::string actor = cl.getActor();
                     if (actor != it->second.getActor())
                     {
                         it->second.addActor(actor);
                     }
                 }
                 break;
             }
             default:
                 //movie type is incorrect
                 cout << endl;
                 cerr << "\nUnknown movie genre: " << movieItem << endl;

         } // end of switch

     } // end of while

     // copy elements from map to inventoryDB
     for (auto element : classicsMap)
     {
         storeInventoryDB.addClassicsInventory(element.second);
     }

     moviesFile.close();   // end of reading from data4movies.txt


    // ----------------------------------------------------------------------
    // -------------- read customers into customers data base  --------------
    // ----------------------------------------------------------------------
    std::string cFileName = "data4customers.txt";
    //std::string cFileName = "customers.txt";
    fstream customersFile(cFileName);

    if (customersFile.fail())
    {
        cerr << "Can't find customers file: " << cFileName << endl;
        return 1;
    }

    CustomerDB storeCustomersData;

    std::string newCustomer;

    while (!customersFile.eof())
    {
        getline(customersFile, newCustomer);

        if (newCustomer.empty())
        {  // if the read string is empty then do go into switch statements
            continue;
        }
        Customer customer(newCustomer);
        storeCustomersData.addNewCustomer(customer);

    }

    customersFile.close(); // end of reading from data4customers.txt


    // ----------------------------------------------------------------------
    // ---------------- read customers into customers data base  ------------
    // ----------------------------------------------------------------------
     std::string commandsFileName = "data4commands.txt";
     Action action;
     action.processCommands(commandsFileName, storeInventoryDB, storeCustomersData);


    return 0;
} // end of main
