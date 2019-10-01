#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Player {
    string Names;
    int jerseyNums;
    int ratingNums;
  /*your code here*/
};

void initialize(vector<Player>& v);
void output(const vector<Player>& v);
void addPlayer(vector<Player>& v, Player player1);
void deletePlayer(vector<Player>& v, int playerNumber);
void updateRating(vector<Player>& v, int playerNumber, int rating);
void aboveRating(const vector<Player>& v, int rating);

int main() {

    vector<string> Names(5);
    vector<int> jerseyNums(5);
    vector<int> ratingNums(5);

    vector <Player> playerInfo(5);


    unsigned int i;
    string playerName;
    int playerJersey;
    int playerRating;
    char menuOp;


    cout << "ROSTER" << endl;
    initialize(playerInfo);

    cout << "with struct" << endl;
    for (i = 0; i < jerseyNums.size(); ++i) {
        cout << "Player " << i + 1 << " -- Name: " << playerInfo.at(i).Names << " -- Jersey number: "
        << playerInfo.at(i).jerseyNums << ", Rating: " << playerInfo.at(i).ratingNums << endl;
    }
    cout << endl;

   /* cout << "without struct" << endl;
    for (i = 0; i < jerseyNums.size(); ++i) {
        cout << "Player " << i + 1 << " -- Name: " <<Names.at(i)<<" -- Jersey number: "
             << jerseyNums.at(i) << ", Rating: " << ratingNums.at(i) << endl;
    }*/

    do {
        cout << "MENU" << endl;
        cout << "a - Add player" << endl;
        cout << "d - Remove player" << endl;
        cout << "u - Update player rating" << endl;
        cout << "r - Output players above a rating" << endl;
        cout << "o - Output roster" << endl;
        cout << "q - Quit" << endl << endl;

        cout << "Choose an option:" << endl;
        cin >> menuOp;

        //Add
        if (menuOp == 'a') {
            cout << "Enter a new player's jersey number:" << endl;
            cin >> playerJersey;
            jerseyNums.push_back(playerJersey);


            cout << "Enter the player's rating:" << endl;
            cin >> playerRating;
            ratingNums.push_back(playerRating);
            cout << endl;
        }

            //Delete
        else if (menuOp == 'd') {
            cout << "Enter a jersey number:" << endl;
            cin >> playerJersey;
            //find the player using her/his jersey number
            for (i = 0; i < jerseyNums.size(); ++i) {

                if (playerJersey == jerseyNums.at(i)) {
                    playerJersey = i;
                }
            }
            //shift the vectors' elements up to remove the element
            for (i = 0; i < jerseyNums.size() - 1; ++i) {
                if (i >= playerJersey) {
                    Names.at(i) = Names.at(i + 1);
                    jerseyNums.at(i) = jerseyNums.at(i + 1);
                    ratingNums.at(i) = ratingNums.at(i + 1);
                }
            }
            Names.pop_back();
            jerseyNums.pop_back();
            ratingNums.pop_back();
            cout << endl;
        }

            //Update
        else if (menuOp == 'u') {
            cout << "Enter a jersey number:" << endl;
            cin >> playerJersey;

            cout << "Enter a new rating for player:" << endl;
            cin >> playerRating;

            for (i = 0; i < jerseyNums.size(); ++i) {
                if (jerseyNums.at(i) == playerJersey) {
                    ratingNums.at(i) = playerRating;
                }
            }
            cout << endl;
        }

            // > Rating
        else if (menuOp == 'r') {
            cout << "Enter a rating:" << endl;
            cin >> playerRating;
            cout << endl;

            cout << "ABOVE " << playerRating << endl;
            for (i = 0; i < jerseyNums.size(); ++i) {
                if (ratingNums.at(i) > playerRating) {
                    cout << "Player " << i + 1 << " -- Jersey number: "
                         << jerseyNums.at(i) << ", Rating: "
                         << ratingNums.at(i) << endl;
                }
            }
            cout << endl;

        }

        //output
        else if (menuOp == 'o') {
            cout << "ROSTER" << endl;
            for (i = 0; i < jerseyNums.size(); ++i) {
                cout << "Player " << i + 1 << " -- Name: " <<Names.at(i)<<" -- Jersey number: "
                     << jerseyNums.at(i) << ", Rating: " << ratingNums.at(i) << endl;
            }
            cout << endl;
        }

    } while(menuOp != 'q');

    return 0;
}

void initialize(vector<Player>& v){
    //initialize the roasters

    for (int i = 0; i < v.size(); ++i) {

        cout << "Enter player " << i + 1 << "'s name:" << endl;
        cin >> v.at(i).Names;


        cout << "Enter player " << i + 1 << "'s jersey number:" << endl;
        cin >> v.at(i).jerseyNums;

        cout << "Enter player " << i + 1 << "'s rating:" << endl;
        cin >> v.at(i).ratingNums;
        cout << endl;
    }
}
