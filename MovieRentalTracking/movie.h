// ------------------------------- movie.h ----------------------------------
//
// Programmer Name: Satine Paronyan
// Course Section Number: CSS 502A
// Created: 02/23/2019
// Modified: 03/17/2019
//
//
// --------------------------------------------------------------------------
// PURPOSE:
// Represents a movie object for the rental store. This class will be
// used as a base class for Classics, Drama and Comedy classes.
// --------------------------------------------------------------------------
// Notes:
// Virtual methods must be overriden in the subclasses in order to perform
// the correct comparison operation.
// --------------------------------------------------------------------------

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <vector>

// ------------------------------ class Movie --------------------------------
// Description:
// Represent a movie object. The class it used as base class for the Classics,
// Drama and Comedy movies. It also public contains mutator and accessor
// methods as well as virtual.
// ---------------------------------------------------------------------------
class Movie {

private:
    char genre;
    int stock;
    std::string director;
    std::string title;
    int releaseYear;

    // FOR Classics
    // can have more than one major actor
    // for comparisons and sorting actors[0] element is used
    std::vector<std::string> actors;   //new element is added to the back
    int releaseMonth;


public:
    // movie genres and their denotation
    const static char COMEDY = 'F';
    const static char DRAMA = 'D';
    const static char CLASSICS = 'C';

    // ---------------------- Movie Constructor -------------------------
    // Description:
    // Constructs and initializes Movie object.
    // ------------------------------------------------------------------
    Movie();

    // ---------------------- Movie Destructor --------------------------
    // Description:
    // Destroys Movie object.
    // ------------------------------------------------------------------
    virtual~Movie();


    // ======================================================================
    // ==================   Accessor and Mutator methods   ==================
    // ======================================================================

    // --------------------------- setGenre -----------------------------
    // Description:
    // Sets genre of this Movie to the given char (either 'F' for comedy,
    // 'D' for drama or 'C' for classics.
    // ------------------------------------------------------------------
    void setGenre(const char &val);

    // --------------------------- getGenre -----------------------------
    // Description:
    // Returns a char value representing the genre of this Movie
    // ('F' for comedy, 'D' for drama or 'C' for classics.
    // ------------------------------------------------------------------
    char getGenre() const;


    // --------------------------- setStock -----------------------------
    // Description:
    // Sets the stock of the movie to the given integer value.
    // ------------------------------------------------------------------
    void setStock(const int &val);


    // --------------------------- getStock -----------------------------
    // Description:
    // Returns the integer value representing the stock of this movie.
    // ------------------------------------------------------------------
    int getStock() const;


    // ------------------------- setDirector ----------------------------
    // Description:
    // Sets the Director full name of the movie to the given string value.
    // The full name should be in the format: first name then last name,
    // separated by space.
    // ------------------------------------------------------------------
    void setDirector(const std::string &val);

    // ------------------------- getDirector ----------------------------
    // Description:
    // Returns the Director full name of the movie.
    // The full name is in the format: first name then last name,
    // separated by space.
    // ------------------------------------------------------------------
    std::string getDirector() const;


    // ---------------------------- setTitle ----------------------------
    // Description:
    // Sets the Title of the movie to the given string value.
    // ------------------------------------------------------------------
    void setTitle(const std::string &val);

    // ---------------------------- getTitle ----------------------------
    // Description:
    // Returns the Title of the movie.
    // ------------------------------------------------------------------
    std::string getTitle() const;


    // ------------------------- setReleaseYear --------------------------
    // Description:
    // Sets the release year of the movie to the given (four digit) int value.
    // ------------------------------------------------------------------
    void setReleaseYear(const int &val);

    // ------------------------- getReleaseYear -------------------------
    // Description:
    // Returns the release year of the movie (four digit int value).
    // ------------------------------------------------------------------
    int getReleaseYear() const;


    // --------------------------- addActor -----------------------------
    // Description:
    // Adds the given major actor's name for the Classics movie.
    // ------------------------------------------------------------------
    void addActor(const std::string &val);


    // --------------------------- getActor -----------------------------
    // Description:
    // Returns the major actor's name for the Classics movie (if there more
    // than one major actor, then will return the first read one).
    // ------------------------------------------------------------------
    std::string getActor() const;


    // ---------------------- getVectorOfActors -------------------------
    // Description:
    // Returns a vector of the major actors's for the Classics movie.
    // ------------------------------------------------------------------
    std::vector<std::string> getVectorOfActors() const;


    // ------------------------- containsActor --------------------------
    // Description:
    // Returns a vector of the major actors's for the Classics movie.
    // ------------------------------------------------------------------
    bool containsActor(const std::string &name) const;


    // ------------------------ setReleaseMonth -------------------------
    // Description:
    // Sets the release month of the movie to the given int value.
    // The value representing month must be without preceding 0s, for example,
    // to pass March -> 3 is passed instead of 03.
    // ------------------------------------------------------------------
    void setReleaseMonth(const int &val);

    // ------------------------ getReleaseMonth -------------------------
    // Description:
    // Returns the release month of the movie.
    // ------------------------------------------------------------------
    int getReleaseMonth() const;


    // ======================================================================
    // ====================      Virtual Methods      =======================
    // ======================================================================


    // -------------------------  operator==   -------------------------
    // Description:
    // Returns true if two Movie objects are equal false otherwise.
    // Movie objects are equal if they have the same title and release
    // in the same year.
    // ------------------------------------------------------------------
    virtual bool operator==(const Movie& other) const;



    // ---------------------------- operator> ----------------------------
    // Description:
    // Returns true if this Movie is greater than the other passed
    // argument Movie, false otherwise. This Movie objects is grater that the
    // other movie, if this movie is released later, in case their release
    // dates are equal, then the title's strings are compared.
    // ------------------------------------------------------------------
    virtual bool operator>(const Movie& other) const;


    // -------------------------- operator< ------------------------------
    // Description:
    // Returns true if this Movie is less than the other passed
    // argument Movie, false otherwise. This Movie objects is less that the
    // other movie, if this movie is released earlier, in case their release
    // dates are equal, then the title's (strings) are compared.
    // ------------------------------------------------------------------
    virtual bool operator<(const Movie& other) const;


};

#endif //MOVIE_H
