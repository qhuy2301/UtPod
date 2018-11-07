#ifndef SONG_H
#define SONG_H
#include <string>

using namespace std;

class Song
{
    private:
        string artist;
        string title;
        int size;

    public:
        Song();
        Song(string artist, string title, int size);

        //Artist
        string getArtist() const;
        void setArtist(string a);

        //Title
        string getTitle() const;
        void setTitle(string t);

        //Size
        int getSize() const;
        void setSize(int s);

        bool operator ==(Song const &rhs);
        bool operator >(Song const &rhs);
        bool operator <(Song const &rhs);
        bool operator !=(Song const &rhs);

        //void swap(Song &s2);

        //~Song();

};

#endif