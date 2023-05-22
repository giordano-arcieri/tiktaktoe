#include <iostream>
#include <vector>

using namespace std;

enum Player{ PLAYER1,PLAYER2 }; //used to know whos turn it is.

enum Results{ PLAYER1_WINS,PLAYER2_WINS,TIE,UNKNOWN }; //used to keep playing while results are unknown and once known display correct results.

enum Return_Statement_For_Board_Push{ CANNOT,WON,SUCCESS }; //when a player tries to occupy a cell they either cant, won the game, or game moves on.
class Board{
    vector<vector<int>> board; //board is a 3x3 vector of wich either has a 0(not yet used) a 1(belong to player 1) or a 2(belong to player 2).

public:
    Board(); //constructor
    void print_board();
    Return_Statement_For_Board_Push push(int cell, Player player);
    bool result();
};

void welcome_players_to_game();
int instruct_player_and_get_their_move(Player player);
bool ask_to_play_again();

int main(){

    Board board;
    Player player;
    Results result = UNKNOWN;
    Return_Statement_For_Board_Push temp;
    bool play_again = true;
    int ans;

    welcome_players_to_game();
    board.print_board();
    while(play_again){

        while(result == UNKNOWN){

            player = PLAYER1; //ask player for their move. Modify board and print board.
            ans = instruct_player_and_get_their_move(player);
            temp = board.push(ans, player);
            while(temp == CANNOT){
                ans = instruct_player_and_get_their_move(player);
                temp = board.push(ans, player);
            }
            board.print_board();
            if(temp == WON){
                result = PLAYER1_WINS;
                break;
            }

            player = PLAYER2; //ask player for their move. Modify board and print board.
            ans = instruct_player_and_get_their_move(player);
            temp = board.push(ans, player);
            while(temp == CANNOT){
                ans = instruct_player_and_get_their_move(player);
                temp = board.push(ans, player);
            }
            board.print_board();
            if(temp == WON){
                result = PLAYER2_WINS;
                break;
            }
        }
        cout << "Congrats Player " << result + 1 << "! You have won the game!" << endl;

        play_again = ask_to_play_again();
        result = UNKNOWN;
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
Return_Statement_For_Board_Push Board::push(int cell, Player player){
    //check if we can modify the cell.
    if(cell > 9 || cell < 1 || board[(cell-1)/3][(cell-1)%3]){ //if the cell the user wants to modify doesnt exits or is taken we return an error. This will not go out of bounce because of short circut evaluation.
        return CANNOT;
    }
    //modify cell.
    board[(cell-1)/3][(cell-1)%3] = player + 1;
    //check if the game is won
    if(this->result()){
        return WON;
    }
    return SUCCESS;
    
}
bool Board::result(){
    //if any row is full of 1/2 or any col or either diagano return true
    int temp = -1;
    for(int row = 0; row < board.size(); row++){
        for(int i = 0; i < board.size(); i++){
            if(temp == -1){
                temp = board[row][i];
            }
            else if(temp != board[row][i]){
                break;
            }
            else if(i+1 == board.size()){
                return true;
            }
        }
    }

    for(int col = 0; col < board.size(); col++){
        for(int i = 0; i < board.size(); i++){
            if(temp == -1){
                temp = board[i][col];
            }
            else if(temp != board[i][col]){
                break;
            }
            else if(i+1 == board.size()){
                return true;
            }
        }
    }
    if(board[1][1] != 0){
        temp = board[1][1];
    }
    if(temp == board[0][0] && temp == board[2][2]) {
        return true;
    }
    if(temp == board[0][2] && temp == board[2][0]) {
        return true;
    }
    return false;
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
