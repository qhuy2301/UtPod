//DOCUMENT HERE

#ifndef UTPOD_H
#define UTPOD_H
#include "Song.h"

//UtPod class declaration
class UtPod
{
    private:
        static const int MAX_MEMORY = 512;
        static const int SUCCESS = 0;
        static const int NO_MEMORY = -1;
        static const int NOT_FOUND = -2;

        struct SongNode {
            Song s;
            SongNode *next;
        };

        SongNode *songs;  //the head pointer

        int memSize;

        void swap(Song &s1, Song &s2);

        int numSong();

        int dupSong(Song const &s);


    public:
        //Default constructor
        //set the memory size to MAX_MEMORY
        UtPod();

        //Constructor with size parameter
        //The user of the class will pass in a size.
        //If the size is greater than MAX_MEMORY or less than or equal to 0,
        //set the size to MAX_MEMORY.
        UtPod(int size);

        /* FUNCTION - int addSong
        * attempts to add a new song to the UtPod
           o returns a 0 if successful
           o returns -1 if not enough memory to add the song

        precondition: s is a valid Song

        input parms - reference the points to the song wanting to add

        output parms - SUCCESS or NO_MEMORY is returned
        */

        int addSong(Song const &s);


        /* FUNCTION - int removeSong
        * attempts to remove a song from the UtPod
        * removes the first instance of a song that is in the the UtPod multiple times
           o returns 0 if successful
           o returns -2 if nothing is removed


         input parms - reference that points to the song wanting to remove

         output parms - SUCCESS or NOT_FOUND is returned
        */

        int removeSong(Song const &s);


        /* FUNCTION - void shuffle
        *  shuffles the songs into random order
          o will do nothing if there are less than two songs in the current list

         input parms - nothing is passed. The UtPod class is calling this function

         output parms - nothing. UtPod class has been shuffled
        */

        void shuffle();


        /* FUNCTION - void showSongList
        * prints the current list of songs in order from first to last to standard output
        * format - Title, Artist, size in MB (one song per line)

         input parms - nothing is passed. The UtPod class is calling this function

         output parms - nothing is returned. Print songs in UtPod class in the function
       */

        void showSongList();


        /* FUNCTION - void sortSongList
         *  sorts the songs in ascending order
          o will do nothing if there are less than two songs in the current list

         input parms - nothing is passed. The UtPod class is calling this function

         output parms - nothing is returned. Sort songs in UtPod class in the function
        */

        void sortSongListA();           // Sorts in ascending order

        void sortSongListD();           // Sorts in descending order


        /* FUNCTION - void clearMemory
         * clears all the songs from memory

           input parms - nothing is passed. The UtPod class is calling this function

         output parms - nothing is returned. Everything in UtPod class is cleared
        */
        void clearMemory();


        /* FUNCTION - int getTotalMemory
         *  returns the total amount of memory in the UtPod
          o will do nothing if there are less than two songs in the current list

         input parms - nothing is passed. The UtPod class is calling this function

         output parms - returns total memory in UtPod class
        */

        int getTotalMemory() {
             return memSize;
        }



      /* FUNCTION - int getRemainingMemory
       *  returns the amount of memory available for adding new songs

         input parms - nothing is passed. The UtPod class is calling this function

         output parms - returns remaining memory in UtPod class
      */

        int getRemainingMemory();

        ~UtPod();               // destructor that clears UtPod

};



#endif