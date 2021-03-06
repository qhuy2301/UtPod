#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main()//int argc, char *argv[])
{
    int size = 600;
    cout << "\n1. Testing: Memory size: " << size << endl;
    UtPod t(size);
    
    Song s1("Beatles", "Hey Jude", 4);
    int result = t.addSong(s1);
    Song s2("John Legend", "All of Me", 5);
    result = t.addSong(s2);
    Song s3("Backstreet Boys", "I Want It That Way", 6);
    result = t.addSong(s3);
    Song s4("Elvis Presley", "Can't Help Falling In Love", 7);
    result = t.addSong(s4);
    Song s5("Michael Jackson", "Thriller", 3);
    result = t.addSong(s5);

    cout << "UtPod is preloaded with 5 songs" << endl;
    t.showSongList();
    cout << endl;

    cout << "2. Testing: Adding song" << endl;
    cout << "Charlie Puth - We Don't Talk Anymore - 4" << endl;
    cout << "Backstreet Boys - Drowning - 5" << endl;
    Song s6("Charlie Puth", "We Don't Talk Anymore", 4);
    Song s7("Backstreet Boys", "Drowning", 5);
    result = t.addSong(s6);
    result = t.addSong(s7);
    t.showSongList();
    cout << endl;

    cout << "3. Testing: Add a song that is already in UtPod" << endl;
    cout << "John Legend - All of Me - 5" << endl;
    Song s8("John Legend", "All of Me", 5);
    result = t.addSong(s8);
    t.showSongList();
    cout << endl;

    cout << "4. Testing: Add a song whose size is larger than remaining memory" << endl;
    cout << "Luis Fonsi - Despacito - 500" << endl;
    Song s9("Luis Fonsi", "Despacito", 500);
    result = t.addSong(s9);
    if (result == -1) cout << "Not enough memory" << endl;
    t.showSongList();
    cout << endl;

    cout << "5. Testing: Shuffle" << endl;
    t.shuffle();
    t.showSongList();
    cout << endl;

    cout << "6. Testing: Ascending Sort" << endl;
    t.sortSongListA();
    t.showSongList();
    cout << endl;

    cout << "7. Testing: Descending Sort" << endl;
    t.sortSongListD();
    t.showSongList();
    cout << endl;

    cout << "8. Testing: Delete a song" << endl;
    cout << "Delete Beatles - Hey Jude - 4" << endl;
    result = t.removeSong(s1);
    t.showSongList();
    cout << endl;

    cout << "9. Testing: Delete a song not in UtPod" << endl;
    cout << "Delete michael Jackson - Thriller - 3" << endl;
    Song s10("michael Jackson", "Thriller", 3);
    result = t.removeSong(s10);
    if (result == -2) cout << "Song not found" << endl;
    t.showSongList();
    cout << endl;

    cout << "10. Testing: Memory Test" << endl;
    cout << "Total memory: " << t.getTotalMemory() << endl;
    cout << "Remaining memory: " << t.getRemainingMemory() << endl;
    cout << endl;
    cout << "All test cases completed" << endl;

}