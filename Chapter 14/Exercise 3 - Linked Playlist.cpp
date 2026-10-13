// Exercise 3 - Linked Playlist (MEDIUM)
// Goal: Build and traverse a chain of objects with Node* next.
//
// Tasks:
// 1. Connect first -> second -> third using the next pointers.
// 2. Traverse the chain with a SongNode* cursor and print each title.
// 3. Delete all three nodes using a loop, without losing track of next.
//
// Expected output:
// Intro
// Chorus
// Outro
//
// Hint for cleanup: Before deleting cursor, save cursor->next.
// Note: SongNode does NOT delete next automatically in its destructor.

#include <iostream>
#include <string>

class SongNode {
public:
    SongNode(std::string songTitle) : title(songTitle), next(nullptr) {}

    std::string title;
    SongNode* next;
};

int main() {
    SongNode* first = new SongNode("Intro");
    SongNode* second = new SongNode("Chorus");
    SongNode* third = new SongNode("Outro");

    // TODO 1: Connect first to second and second to third.
    first->next = second;
    second->next = third;

    SongNode* cursor = first;
    while (cursor != nullptr) {
        // TODO 2: Print cursor's title and move cursor forward.
        std::cout << cursor->title << std::endl;

        // Important: Advance cursor so this loop does not run forever.
        cursor = cursor->next; // Keep this line when you add printing.
    }

    cursor = first;
    while (cursor != nullptr) {
        // TODO 3: Save the next pointer, delete cursor, then advance.
        SongNode* temp = cursor->next;
        delete cursor;

        // Replace this temporary line once you implement cleanup.
        cursor = temp;
    }

    return 0;
}
