
#include <iostream>
using namespace std;

class Player
{
public:
    int playerID;
    int score;
    Player* next;

    Player(int id, int s)
    {
        playerID = id;
        score = s;
        next = nullptr;
    }
};

class Game
{
private:
    Player* tail;
    Player* current;

public:
    Game()
    {
        tail = nullptr;
        current = nullptr;
    }

    void addPlayer(int id, int score)
    {
        Player* newPlayer = new Player(id, score);

        if (tail == nullptr)
        {
            tail = newPlayer;
            tail->next = tail;
            current = tail;
        }
        else
        {
            newPlayer->next = tail->next;
            tail->next = newPlayer;
            tail = newPlayer;
        }

        cout << "Player " << id << " added\n";
    }

    void displayPlayers()
    {
        if (tail == nullptr)
        {
            cout << "No players in the game\n";
            return;
        }

        Player* temp = tail->next;

        cout << "\nPlayers in Game:\n\n";

        do
        {
            cout << "Player ID: " << temp->playerID << endl;
            cout << "Score: " << temp->score << endl;
            cout << "-------------------\n";

            temp = temp->next;
        } while (temp != tail->next);
    }

    void nextTurn()
    {
        if (current == nullptr)
        {
            cout << "No players available\n";
            return;
        }

        cout << "Current Turn: Player " << current->playerID << endl;

        current = current->next;
    }

    void skipPlayer()
    {
        if (current == nullptr)
        {
            cout << "No players available\n";
            return;
        }

        cout << "Skipping Player " << current->playerID << endl;

        current = current->next;

        cout << "Next Turn: Player " << current->playerID << endl;

        current = current->next;
    }

    void removePlayer(int id)
    {
        if (tail == nullptr)
        {
            cout << "No players to remove\n";
            return;
        }

        Player* currentNode = tail->next;
        Player* previous = tail;

        do
        {
            if (currentNode->playerID == id)
            {
                break;
            }

            previous = currentNode;
            currentNode = currentNode->next;
        } while (currentNode != tail->next);

        if (currentNode->playerID != id)
        {
            cout << "Player not found\n";
            return;
        }

        if (currentNode == tail && currentNode->next == tail)
        {
            tail = nullptr;
            current = nullptr;

            delete currentNode;

            cout << "Player removed\n";
            return;
        }

        previous->next = currentNode->next;

        if (currentNode == tail)
        {
            tail = previous;
        }

        if (current == currentNode)
        {
            current = currentNode->next;
        }

        delete currentNode;

        cout << "Player removed\n";
    }

    void checkWinner()
    {
        if (tail == nullptr)
        {
            cout << "No players in game\n";
            return;
        }

        if (tail == tail->next)
        {
            cout << "\nWinner is Player " << tail->playerID << endl;
        }
        else
        {
            cout << "\nGame is still running\n";
        }
    }
};

int main()
{
    Game g;

    g.addPlayer(1, 100);
    g.addPlayer(2, 150);
    g.addPlayer(3, 120);
    g.addPlayer(4, 180);

    g.displayPlayers();

    cout << "\nTurn Rotation:\n";
    g.nextTurn();
    g.nextTurn();

    cout << "\nSkipping a Player:\n";
    g.skipPlayer();

    cout << "\nRemoving Player 3:\n";
    g.removePlayer(3);

    g.displayPlayers();

    cout << "\nRemoving Player 2:\n";
    g.removePlayer(2);

    cout << "\nRemoving Player 4:\n";
    g.removePlayer(4);

    g.displayPlayers();

    g.checkWinner();

    return 0;
}
