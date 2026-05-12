#include <iostream>
#include <string>
using namespace std;

class Song
{
public:
    int songID;
    string songName;
    float duration;
    Song* next;
    Song* prev;

    Song(int id, string name, float dur)
    {
        songID = id;
        songName = name;
        duration = dur;
        next = nullptr;
        prev = nullptr;
    }
};

class Playlist
{
private:
    Song* head;
    Song* tail;
    Song* current;

public:
    Playlist()
    {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }

    void addSong(int id, string name, float dur)
    {
        Song* newSong = new Song(id, name, dur);

        if (head == nullptr)
        {
            head = tail = current = newSong;
            return;
        }

        tail->next = newSong;
        newSong->prev = tail;
        tail = newSong;
    }

    void deleteSong(string name)
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty\n";
            return;
        }

        Song* temp = head;

        while (temp != nullptr)
        {
            if (temp->songName == name)
            {
                break;
            }

            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Song not found\n";
            return;
        }

        if (head == tail)
        {
            head = tail = current = nullptr;
        }
        else if (temp == head)
        {
            head = head->next;
            head->prev = nullptr;
        }
        else if (temp == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        if (current == temp)
        {
            current = head;
        }

        delete temp;

        cout << "Song deleted successfully\n";
    }

    void playCurrent()
    {
        if (current == nullptr)
        {
            cout << "No song available\n";
            return;
        }

        cout << "Now Playing: " << current->songName << endl;
    }

    void playNext()
    {
        if (current == nullptr)
        {
            cout << "Playlist is empty\n";
            return;
        }

        if (current->next == nullptr)
        {
            cout << "This is the last song\n";
            return;
        }

        current = current->next;

        cout << "Now Playing: " << current->songName << endl;
    }

    void playPrevious()
    {
        if (current == nullptr)
        {
            cout << "Playlist is empty\n";
            return;
        }

        if (current->prev == nullptr)
        {
            cout << "This is the first song\n";
            return;
        }

        current = current->prev;

        cout << "Now Playing: " << current->songName << endl;
    }

    void reversePlaylist()
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty\n";
            return;
        }

        Song* temp = nullptr;
        Song* currentNode = head;

        while (currentNode != nullptr)
        {
            temp = currentNode->prev;
            currentNode->prev = currentNode->next;
            currentNode->next = temp;
            currentNode = currentNode->prev;
        }

        temp = head;
        head = tail;
        tail = temp;

        current = head;

        cout << "Playlist reversed successfully\n";
    }

    void displayPlaylist()
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty\n";
            return;
        }

        Song* temp = head;

        cout << "\nPlaylist:\n\n";

        while (temp != nullptr)
        {
            cout << "Song ID: " << temp->songID << endl;
            cout << "Song Name: " << temp->songName << endl;
            cout << "Duration: " << temp->duration << " mins\n";
            cout << "------------------------\n";

            temp = temp->next;
        }
    }
};

int main()
{
    Playlist p;

    p.addSong(101, "Shape of You", 4.2);
    p.addSong(102, "Blinding Lights", 3.5);
    p.addSong(103, "Perfect", 4.8);
    p.addSong(104, "Levitating", 3.9);

    p.displayPlaylist();

    cout << "\n";
    p.playCurrent();

    cout << "\nPlaying Next Songs:\n";
    p.playNext();
    p.playNext();

    cout << "\nPlaying Previous Song:\n";
    p.playPrevious();

    cout << "\nDeleting a Song:\n";
    p.deleteSong("Perfect");

    p.displayPlaylist();

    cout << "\nReversing Playlist:\n";
    p.reversePlaylist();

    p.displayPlaylist();

    return 0;
}