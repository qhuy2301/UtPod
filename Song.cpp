#include <iostream>
#include "Song.h"
#include <string>

using namespace std;

//Constructor
Song::Song() {
    this->title = " ";
    this->artist = " ";
    this->size = 0;
}
/*
Song::Song(string title) {
    title = title;
    artist = " ";
    size = 0;
}

Song::Song(string artist, string title) {
    title = title;
    artist = artist;
    size = 0;
}
*/

// Set Title, Artist, and Size of song
Song::Song(string artist, string title, int size) {
    this->setTitle(title);
    this->setArtist(artist);
    this->setSize(size);
}

// Return Artist of song
string Song::getArtist() const {
    return this->artist;
}

// Set Artist of Song
void Song::setArtist(string a) {
    this->artist = a;
}

// Return Title of Song
string Song::getTitle() const {
    return this->title;
}

// Set Title of Song
void Song::setTitle(string t) {
    this->title = t;
}

// Return Size of Song
int Song::getSize() const {
    return this->size;
}

// Set Size of Song
void Song::setSize(int s)
{
    this->size = s;
}

// Overide operator ==
// Checking if contents of two song class are the same
// Input parameter: Reference of song on right hand side
// Output parameter: returns true or false
bool Song::operator ==(Song const &rhs) {
    return (this->artist == rhs.artist &&
            this->title == rhs.title &&
            this->size == rhs.size);
}

// Overide operator >
// Checking the alphabetic order of two song classes
bool Song::operator >(Song const &rhs) {
    if (this->artist > rhs.artist) return true;
    else if (this->artist < rhs.artist) return false;
    else {
        if (this->title > rhs.title) return true;
        else if (this->title < rhs.title) return false;
        else {
            if (this->size > rhs.size) return true;
            else return false;
        }
    }
}

// Overide operator <
// Checking the alphabetic order of two song classes
bool Song::operator <(Song const &rhs) {
    if (this->artist < rhs.artist) return true;
    else if (this->artist > rhs.artist) return false;
    else {
        if (this->title < rhs.title) return true;
        else if (this->title > rhs.title) return false;
        else {
            if (this->size < rhs.size) return true;
            else return false;
        }
    }
}

// Overide operator !=
// Checking if the contents of two song classes are not equal
bool Song::operator !=(Song const &rhs) {
    if (this->artist != rhs.artist ||
        this->title != rhs.title ||
        this->size != rhs.size) return true;
    else return false;
}

//Song::~Song(){

//}