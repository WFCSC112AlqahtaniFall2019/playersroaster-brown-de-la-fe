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

   /* cout << "with struct" << endl;
    for (i = 0; i < jerseyNums.size(); ++i) {
        cout << "Player " << i + 1 << " -- Name: " << playerInfo.at(i).Names << " -- Jersey number: "
        << playerInfo.at(i).jerseyNums << ", Rating: " << playerInfo.at(i).ratingNums << endl;
    }
    cout << endl;*/

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

        if (menuOp == 'a') {
            addPlayer(playerInfo, )
        }
        else if (menuOp == 'd') {
            deletePlayer();
        }

        else if (menuOp == 'u') {
            updateRating();
        }

            // > Rating
        else if (menuOp == 'r') {
            aboveRating();

        }

        //output
        else if (menuOp == 'o') {
            output()
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
void addPlayer(vector<Player>& v, Player player1) {
//Add
    int playerJersey
        cout << "Enter a new player's jersey number:" << endl;
        cin >>  playerJersey;
        v.jerseyNums.push_back(playerJersey);


        cout << "Enter the player's rating:" << endl;
        cin >> playerRating;
        ratingNums.push_back(playerRating);
        cout << endl;

}
void deletePlayer(vector<Player>& v, int playerNumber) {
//Delete

    cout << "Enter a jersey number:" << endl;
    cin >> playerJersey;
//find the player using her/his jersey number
    for (int i = 0; i < v.jerseyNums.size(); ++i) {

        if (playerJersey == jerseyNums.at(i)) {
            playerJersey = i;
        }
    }
//shift the vectors' elements up to remove the element
    for (int i = 0; i < jerseyNums.size() - 1; ++i) {
        if (i >= playerJersey) {
            Names.at(i) = Names.at(i + 1);
            jerseyNums.at(i) = jerseyNums.at(i + 1);
            ratingNums.at(i) = ratingNums.at(i + 1);
        }
    }
    v.pop_back().Names;
    v.pop_back().jerseyNums;
    ratingNums.pop_back();
    cout << endl;
}

void updateRating(vector<Player>& v, int playerNumber, int rating) {
//update
    cout << "Enter a jersey number:" << endl;
   int playerJersey;
    cin >> playerJersey;

    cout << "Enter a new rating for player:" << endl;
    int playerRating;
    cin >> playerRating;

    for (int i = 0; i < v.size(); ++i) {
        if (v.at(i).jerseyNums == playerJersey) {
            v.at(i).ratingNums = playerRating;
        }
    }
    cout << endl;
}

void aboveRating(const vector<Player>& v, int rating){
// > Rating
        cout << "Enter a rating:" << endl;
    int playerRating;
        cin >>  playerRating;
        cout << endl;

        cout << "ABOVE " << playerRating << endl;
        for (int i = 0; i < v.size(); ++i) {
            if (v.at(i).ratingNums > v.at(i).ratingNums) {
                cout << "Player " << i + 1 << " -- Jersey number: "
                     << v.at(i).jerseyNums << ", Rating: "
                     << v.at(i).ratingNums << endl;
            }
        }
        cout << endl;
    }

void output(const vector<Player>& v){
cout << "ROSTER" << endl;
for (int i = 0; i < v.size(); ++i) {
cout << "Player " << i + 1 << " -- Name: " <<v.at(i).Names<<" -- Jersey number: "
<< v.at(i).jerseyNums << ", Rating: " << v.at(i).ratingNums << endl;
}
cout << endl;
}

