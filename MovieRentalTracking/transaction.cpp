// ---------------------------- transaction.cpp -----------------------------
//
// Programmer Name: Satine Paronyan
// Course Section Number: CSS 502A
// Created: 02/23/2019
// Modified: 03/17/2019
//
//
// --------------------------------------------------------------------------
// PURPOSE:
// Represents Borrow or Return transaction. The object is created when the
// valid input is read from a file. Transaction is used to modify the
// InventoryDB and CustomerDB. The valid transactions will be assigned to
// the customer it is associated with.
//
// If valid borrow then the inventory stock for the specified movie will
// be decreased by one. If valid return the inventory stock for the specified
// movie will be increased by one.
// --------------------------------------------------------------------------
// Notes:
// Uses a friend factory function to process the input and if valid then
// initialize Transaction.
// --------------------------------------------------------------------------

#include <sstream> // to use stream
#include <iomanip>  // using to format output
#include "transaction.h"



// ---------------------- Transaction constructors ------------------
// Description:
// Constructs and initializes Transaction object.
// ------------------------------------------------------------------
Transaction::Transaction()
{

}


// Copy constructor
Transaction::Transaction(const Transaction &tr)
{
    this->idNumber = tr.idNumber;
    this->actionType = tr.actionType;
    this->mediaType = tr.mediaType;
    this->movieGenre = tr.movieGenre;
    this->movieTitle = tr.movieTitle;
    this->releaseYear = tr.releaseYear;
    this->releaseMonth = tr.releaseMonth;
    this->majorActor = tr.majorActor;
    this->director = tr.director;
}


// ------------------------ Transaction Destructor ------------------
// Description:
// Destroys transaction object.
// ------------------------------------------------------------------
Transaction::~Transaction()
{

}


// ------------------------ getCustomerIdNumber ---------------------
// Description:
// Returns a 4 digit integer representing a customer id number, which
// is associated with this Transaction.
// ------------------------------------------------------------------
int Transaction::getCustomerIdNumber() const
{
    return idNumber;
}


// ------------------------- getActionType --------------------------
// Description:
// Returns a string representing transaction type (Borrow or Return).
// ------------------------------------------------------------------
char Transaction::getActionType() const
{
    return actionType;
}


// -------------------------- getMediaType --------------------------
// Description:
// Returns a string representing the media type (DVD)
// ------------------------------------------------------------------
char Transaction::getMediaType() const
{
    return mediaType;
}


// -------------------------- getMovieType --------------------------
// Description:
// Returns a string representing a movie genre (Comedy, Drama or
// Classics).
// ------------------------------------------------------------------
char Transaction::getMovieGenreType() const
{
    return movieGenre;
}


// ------------------------- getMovieTitle --------------------------
// Description:
// Returns a string representing the movie title.
// ------------------------------------------------------------------
std::string Transaction::getMovieTitle() const
{
    return movieTitle;
}


// ------------------------ getReleaseYear --------------------------
// Description:
// Returns a string representing the movie release year.
// ------------------------------------------------------------------
int Transaction::getReleaseYear() const
{
    return releaseYear;
}


// ------------------------ getReleaseMonth -------------------------
// Description:
// Returns a string representing the movie release month.
// ------------------------------------------------------------------
int Transaction::getReleaseMonth() const
{
    return releaseMonth;
}


// ------------------------ getMajorActor --------------------------
// Description:
// Returns a string representing the name of the movie's major actor.
// ------------------------------------------------------------------
std::string Transaction::getMajorActor() const
{
    return majorActor;
}


// ----------------------- getMovieDirector -------------------------
// Description:
// Returns a string representing the movie director's name.
// ------------------------------------------------------------------
std::string Transaction::getMovieDirector() const
{
    return director;
}



// ------------------------- getTransactionInfo  ----------------------
// Description:
// Returns a string representing this transaction. Used to output customer
// transaction history.
// ------------------------------------------------------------------
std::string  Transaction::getTransactionInfo() const
{
    std::stringstream result;

    std::string action;
    if (actionType == 'B')
    {
        action = "Borrow";
    }
    else
    {
        action = "Return";
    }

    std::string media;
    if (mediaType == 'D')
    {
        media = "DVD";
    }


    switch (movieGenre)
    {
        case 'C':
        {
            result << std::setw(3) << action << std::setw(7) << media <<
                   std::setw(11) << "Classic" << std::setw(34) << movieTitle
                   << std::setw(5) << releaseMonth << " " << releaseYear
                   << std::setw(20) << majorActor << " (actor)";
            break;
        }
        case 'D':
        {
            result << std::setw(3) << action << std::setw(7) << "DVD" <<
                   std::setw(9) << "Drama" << std::setw(36) << movieTitle
                    << std::setw(10) << releaseYear
                    << std::setw(20) << director << " (director)";
            break;
        }
        case 'F':
        {


            result << std::setw(3) << action << std::setw(7) << media <<
                    std::setw(10) << "Comedy" << std::setw(35) << movieTitle
                     << std::setw(10) << releaseYear;
            break;
        }
        default:
            break;
    }

    return result.str();  //converts the stream buffer into a string
}


// ---------------------- getComedyMovieCommand ---------------------
// Description:
// Returns a string representing the command received for comedy movie
// to perform transaction.
// @pre - Transaction for comedy movie is created successfully.
// ------------------------------------------------------------------
std::string Transaction::getComedyMovieCommand() const
{
    std::stringstream result;
    result << actionType << " " << idNumber << " "
        << mediaType << " " << movieGenre << " "
        << movieTitle << ", " << releaseYear << std::endl;
    return result.str();
}


// ----------------------- getDramaMovieCommand ---------------------
// Description:
// Returns a string representing the command received for drama movie
// to perform transaction.
// @pre - Transaction for drama movie is created successfully.
// ------------------------------------------------------------------
std::string Transaction::getDramaMovieCommand() const
{
    std::stringstream result;
    result << actionType << " " << idNumber << " "
           << mediaType << " " << movieGenre << " "
           << director << ", " << movieTitle << ", " << std::endl;
    return result.str();
}


// -------------------- getClassicsMovieCommand ---------------------
// Description:
// Returns a string representing the command received for classics
// movie to perform transaction.
// @pre - Transaction for classics movie is created successfully.
// ------------------------------------------------------------------
std::string Transaction::getClassicsMovieCommand() const
{
    std::stringstream result;
    result << actionType << " " << idNumber << " "
              << mediaType << " " << movieGenre << " "
              << releaseMonth << " " << releaseYear << " "
              << majorActor << std::endl;
    return result.str();
}

void Transaction::setMovieTitle(const std::string &title)
{
    this->movieTitle = title;
}


void Transaction::setReleaseYear(const int &val)
{
    this->releaseYear = val;
}



// ------------------------ createTransaction -----------------------
// Description:
// Factory function to create a Transaction object if the received
// command line if valid, returns true in this case, othewise the object
// is not created and false is returned.
// ------------------------------------------------------------------
bool createTransaction(Transaction &T, const std::string &line,
                        char action, int id)
{
    if (action != 'B' && action != 'R')
    {
        std::cerr << "\nInvalid transaction type: " << action  << std::endl;
        return false;
    }

    std::string idNum;
    char mdType;
    char movGenre;
    std::string title;
    int year = 0;
    int month = 0; // only for classics
    std::string mjActor;  //only for classic movies
    std::string directorName;

    std::stringstream str(line);

    str >> idNum >> mdType;
    if (mdType != 'D')
    {
        std::cerr << "\nInvalid Command type: "
                  << action  << " " << line
                  << "\nMedia type: \'" << mdType << "\'" << std::endl;
        return false;
    }

    str >>movGenre;

    switch (movGenre)
    {
        case 'C':
        {
            std::string temp;
            // read release month and year
            str >> temp;
            month = std::stoi(temp);
            str >> temp;
            year = std::stoi(temp);

            // read major actors full name
            str >> temp;
            std::string temp2;
            str >> temp2;
            mjActor += temp + " " + temp2;
            break;

        }
        case 'F':
        {
            std::string token;
            // read the movie title
            std::getline(str, token, ',');
            title = token.substr(1, token.length());
            str >> token;
            year = std::stoi(token);
            break;;
        }
        case 'D':
        {
            std::string token;
            // read director's name
            std::getline(str, token, ',');
            directorName = token.substr(1, token.length());

            // read movie title
            std::getline(str, token, ',');
            title = token.substr(1, token.length());
            break;
        }
        default:
            std::cerr << "\nInvalid transaction: " << action << " " << line
                      << "\nMovie genre: \'"
                      << movGenre  << "\'" << std::endl;
            return false;
    } // end of switch

    T.actionType = action;
    T.idNumber = id;
    T.mediaType = mdType;
    T.movieGenre = movGenre;
    T.movieTitle = title;
    T.releaseYear = year;
    T.releaseMonth = month;
    T.majorActor = mjActor;
    T.director = directorName;
    return true;  //object created

} // end of createTransaction