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

        Player player1;

        if (menuOp == 'a') {
            addPlayer(playerInfo,player1);
        }
        else if (menuOp == 'd') {
            cout<<"Enter jersey number: "<<endl;
            int jers;
            cin>>jers;
            deletePlayer(playerInfo,jers);
        }

        else if (menuOp == 'u') {
            cout<<"Enter jersey number: "<<endl;
            int jers;
            cin>>jers;
            cout<<"Enter new rating: "<<endl;
            int rate;
            cin>>rate;
            updateRating(playerInfo,jers,rate);
        }

            // > Rating
        else if (menuOp == 'r') {
            cout<<"Enter rating: "<<endl;
            int aboveRate;
            cin>>aboveRate;
            aboveRating(playerInfo,aboveRate);
        }

            //output
        else if (menuOp == 'o') {
            cout<<"Roster: "<<endl;
            output(playerInfo);
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
    string playerNameIn;
    int playerJerseyIn;
    int playerRatingIn;

    cout << "Enter a new player's Name:" << endl;
    cin >>  playerNameIn;
    player1.Names= playerNameIn;
    //v.jerseyNums.push_back(playerJersey);

    cout << "Enter the player's number:" << endl;
    cin>>playerJerseyIn;
    player1.jerseyNums=playerJerseyIn;

    cout << "Enter the player's rating:" << endl;
    cin >> playerRatingIn;
    player1.ratingNums=playerRatingIn;


}
void deletePlayer(vector<Player>& v, int playerNumber) {
//Delete

//find the player using her/his jersey number
    for (int i = 0; i < v.size()-1; ++i) {
        if (playerNumber == v[i].jerseyNums) {
            playerNumber = i;
        }
    }
//shift the vectors' elements up to remove the element
    for (int i = 0; i < v.size() - 1; ++i) {
        if (i >= playerNumber) {
            v[i].Names.at(i) = v[i].Names.at(i + 1);
            v[i].jerseyNums = v[i+1].jerseyNums;
            v[i].ratingNums = v[i+1].ratingNums;
        }
    }
    v.pop_back();
    cout << endl;
}

void updateRating(vector<Player>& v, int playerNumber, int rating) {
//update

    for (int i = 0; i < v.size(); ++i) {
        if (v.at(i).jerseyNums == playerNumber) {
            v.at(i).ratingNums = rating;
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
        if (v.at(i).ratingNums > rating) {
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


