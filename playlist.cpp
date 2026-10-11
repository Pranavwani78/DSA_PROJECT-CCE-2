#include <iostream>
#include <string>
using namespace std;

struct Song {
    string name;
    Song* next;
};

Song* head = nullptr;
Song* tail = nullptr;

void addSong(string name) {
    Song* newSong = new Song;
    newSong->name = name;
    newSong->next = nullptr;

    if (head == nullptr) {
        head = tail = newSong;
    } else {
        tail->next = newSong;
        tail = newSong;
    }

    cout << "Song added: " << name << endl;
}

void displayPlaylist() {
    if (head == nullptr) {
        cout << "Playlist is empty!\n";
        return;
    }

    Song* temp = head;
    int i = 1;

    cout << "\n--- Music Playlist ---\n";
    while (temp != nullptr) {
        cout << i++ << ". " << temp->name << endl;
        temp = temp->next;
    }
}

void playPlaylist() {
    if (head == nullptr) {
        cout << "Playlist is empty!\n";
        return;
    }

    Song* current = head;
    char repeat;

    cout << "\nRepeat mode enabled.\n";

    do {
        cout << "Now Playing: " << current->name << endl;

        if (current->next != nullptr) {
            current = current->next;
        } else {
            current = head;
            cout << "Reached the end. Restarting playlist.\n";
        }

        cout << "Play next song? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    cout << "Playlist stopped.\n";
}

int main() {
    int choice;
    string name;

    do {
        cout << "\n===== MUSIC PLAYLIST =====\n";
        cout << "1. Add Song\n";
        cout << "2. Display Playlist\n";
        cout << "3. Play Playlist (Repeat Mode)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter song name: ";
                getline(cin >> ws, name);
                addSong(name);
                break;

            case 2:
                displayPlaylist();
                break;

            case 3:
                playPlaylist();
                break;

            case 4:
                cout << "Thank you for using Music Playlist!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    while (head != nullptr) {
        Song* temp = head;
        head = head->next;
        delete temp;
    }

    tail = nullptr;
    return 0;
}
