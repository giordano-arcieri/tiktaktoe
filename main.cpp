#include <iostream>
#include <vector>

using namespace std;

enum Player{PLAYER1,PLAYER2};

class Board{
    vector<vector<int>> board; //board is a 3x3 vector of wich either has a 0(not yet used) a 1(belong to player 1) or a 2(belong to player 2)

public:
    Board();
    void print_board();
};

void welcome_players_to_game();
int instruct_player_and_get_their_move(Player player);
bool ask_to_play_again();

int main(){

    Board board;
    Player player = PLAYER1;
    int ans;

    welcome_players_to_game();
    ans = instruct_player_and_get_their_move(player);
    cout << ans << endl;
    player = PLAYER2;
    ans = instruct_player_and_get_their_move(player);
    cout << ans << endl;

    board.print_board();

    if(ask_to_play_again()){
        cout << "Play again!!" << endl;
    }





    return 0;
}

Board::Board(){
    board.resize(3, vector<int>(3));

}
void Board::print_board(){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j] == 1){
                cout << "x ";    
            }
            else if(board[i][j] == 2){
                cout << "o ";    
            }
            else if(board[i][j] == 0){
                cout << (i*3)+(j+1) << ' ';    
            }
            
        }
        cout << endl;
    }
}

void welcome_players_to_game(){
    cout << "Hello! welcome to tik tak toe!" << endl;
}
int instruct_player_and_get_their_move(Player player){
    int ans;
    cout << "Player " << player+1 << " select the cell you would like by enetring the number of the cell: ";
    cin >> ans;
    return ans;
}
bool ask_to_play_again(){
    bool ans;
    cout << "Would you like to play again?: ";
    cin >> ans;
    return ans;
}