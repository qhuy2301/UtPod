#include <iostream>
#include <string>
#include <cstdlib>
#include "UtPod.h"

using namespace std;

UtPod::UtPod(){
    memSize = MAX_MEMORY;
    songs = NULL;
}

UtPod::UtPod(int size) {
    if ((0 < size) && (size <= MAX_MEMORY)) memSize = size;
    else {
        memSize = MAX_MEMORY;
        cout << "Invalid size. Size is set to 512MB" << endl;
        songs = NULL;
    }
    
}

int UtPod::numSong() {
    int numSong = 0;
    SongNode *p = songs;
    while (p != NULL){
        numSong++;
        p = p->next;
    }
    return numSong;
}

int UtPod::addSong(Song const &s) {
    int remMem = getRemainingMemory();
    if (s.getSize() > remMem) return NO_MEMORY;
    else {
        int dup = dupSong(s);
        if (dup == 1){
            removeSong(s);
            cout << "Duplicated song found and deleted" << endl;
            SongNode *temp = new SongNode;
            temp->s = s;
            temp->next = songs;
            songs = temp;
            return SUCCESS;
        } else {
            SongNode *temp = new SongNode;
            temp->s = s;
            temp->next = songs;
            songs = temp;
            return SUCCESS;
        }
    }
}

int UtPod::removeSong(Song const &s) {
    int remMem = getRemainingMemory();
    if (remMem == 0) return NO_MEMORY;
    else {
        SongNode *p = songs;
        SongNode *trail = NULL;
        while (p != NULL && p->s != s) {
            trail = p;
            p = p->next;
        }
        if (p == NULL) return NOT_FOUND;
        else {
            if (trail == NULL) {
                songs = p->next;
                delete p;
                return SUCCESS;
            } else {
                trail->next = p->next;
                delete p;
                return SUCCESS;
            }
        }

    }
}

void UtPod::shuffle() {
    int num = numSong();
    if (num < 2) return;
    else {
        for (int j = 0; j < 2*num; j++) {
            int n1 = rand() % num;
            int n2 = rand() % num;
            Song s1;
            Song s2;
            SongNode *p1 = songs;
            for (int i = 0; i < n1; i++) {
                p1 = p1->next;
            }
            s1 = p1->s;
            SongNode *p2 = songs;
            for (int i = 0; i < n2; i++) {
                p2 = p2->next;
            }
            s2 = p2->s;
            swap(s1, s2);
            p1->s = s1;
            p2->s = s2;
        }
    }
}

void UtPod::swap(Song &s1, Song &s2) {
    Song temp = s1;
    s1 = s2;
    s2 = temp;
}

void UtPod::showSongList() {
    cout << "Welcome to UtPod" << endl;
    cout << "Total Memory: " << getTotalMemory() << "    " << "Remaining Memory: " << getRemainingMemory() << endl;
    cout << "Number of Songs: " << numSong() << endl;
    SongNode *p = songs;
    int k = 1;
    while (p != NULL) {
        cout << k << " - " << p->s.getArtist() << " - " << p->s.getTitle() << " - " << p->s.getSize() << "MB"<< endl;
        k++;
        p = p->next;
    }
}

void UtPod::sortSongListA() {
    int num = numSong();
    for (int i = 0; i < num; i++) {
        SongNode *p = songs;
        while (p != NULL) {
            if (p->next != NULL) {
                SongNode *p2 = p->next;
                if (p->s > p2->s) {
                    swap(p->s, p2->s);
                    p = p->next;
                } else {
                    p = p->next;
                }
            }
            else p = NULL;
        }
    }
}

void UtPod::sortSongListD() {
    int num = numSong();
    for (int i = 0; i < num; i++) {
        SongNode *p = songs;
        while (p != NULL) {
            if (p->next != NULL) {
                SongNode *p2 = p->next;
                if (p->s < p2->s) {
                    swap(p->s, p2->s);
                    p = p->next;
                } else {
                    p = p->next;
                }
            }
            else p = NULL;
        }
    }
}

void UtPod::clearMemory() {
    SongNode *p = songs;
    while (songs != NULL){
        p = songs;
        songs = songs->next;
        delete p;
    }
}

int UtPod::getRemainingMemory() {
    SongNode *p = songs;
    int usedMem = 0;
    while (p != NULL) {
        usedMem = usedMem + p->s.getSize();
        p = p->next;
    }
    int remMem = memSize - usedMem;
    return remMem;
}

/*Song UtPod::findSong(int songNumber) {
    SongNode *p = songs;
    for (int i = 1; i < songNumber; i++) {
        p = p->next;
    }
    return p->s;

}*/

int UtPod::dupSong(Song const &s) {
    SongNode *p = songs;
    while (p != NULL) {
        if (p->s == s) {
            removeSong(p->s);
            return 1;
        }
        else p = p->next;
    }
    return 0;
}

UtPod::~UtPod() {
    clearMemory();
    songs = NULL;
}

