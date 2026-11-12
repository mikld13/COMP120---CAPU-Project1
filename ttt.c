/* 1 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 2 */
const char EMPTY    = ' ';
const char HUMAN    = 'O';
const char COMPUTER = 'X';

/* 3 */
void init_board(char board[])
{
    for (int i = 0; i < 9; i++) {
        board[i] = EMPTY;
}
}

/* 4 */
void display_board(const char board[])
{
    char c[9];

    for (int i = 0; i < 9; i++) {
        if (board[i] == EMPTY) {
            c[i] = '0' + i;
}       else {
            c[i] = board[i];
}
}

    printf("\n");
    printf(" %c | %c | %c\n", c[0], c[1], c[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", c[3], c[4], c[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", c[6], c[7], c[8]);
    printf("\n");
}

/* 5 */
bool is_winner(const char board[], char p)
{
    return (board[0] == p && board[1] == p && board[2] == p) ||   /* 6 */
           (board[3] == p && board[4] == p && board[5] == p) ||
           (board[6] == p && board[7] == p && board[8] == p) ||
           (board[0] == p && board[3] == p && board[6] == p) ||   /* 7 */
           (board[1] == p && board[4] == p && board[7] == p) ||
           (board[2] == p && board[5] == p && board[8] == p) ||
           (board[0] == p && board[4] == p && board[8] == p) ||   /* 8 */
           (board[2] == p && board[4] == p && board[6] == p);
}

/* 9 */
char other_player(char player)
{
    if (player == HUMAN) {
        return COMPUTER;
}
    return HUMAN;
}

/* 10 */
int get_human_move(const char board[])
{
    int square = -1;
    bool valid = false;

    while (!valid) {
        printf("Your turn (O). Enter a square number (0-8): ");

        if (scanf("%d", &square) != 1) {
            printf("  That is not a number. Enter a number from 0 to 8.\n");
}       else if (square < 0 || square > 8) {
            printf("  %d?!? Enter a number from 0 to 8.\n", square);
}       else if (board[square] != EMPTY) {
            printf("  TAKEN. Choose an empty one.\n");
}       else {
            valid = true;
}

        while (getchar() != '\n') {
            /* 11 */
}
}
    return square;
}

/* 12 */
int get_computer_move(const char board[])
{
    int square;

    do {
        square = rand() % 9;
    } while (board[square] != EMPTY);

    return square;
}

/* 13 */
void take_turn(char board[], char player)
{
    int square;

    if (player == HUMAN) {
        square = get_human_move(board);
        board[square] = HUMAN;
}   else {
        printf("Hmmmmmmmmm...\n");
        square = get_computer_move(board);
        board[square] = COMPUTER;

        printf("I choose %d.", square);
        if (!is_winner(board, COMPUTER)) {
            printf(" Bet you didnt expect that! Your move!");
}
        printf("\n");
}
}

/* 14 */
void play_game(void)
{
    char board[9];
    char player = HUMAN;
    bool game_over = false;

    init_board(board);
    printf("\nYou are O and can start. I will play as X.\n");
    printf("On your turn, type the number of an empty square:\n");
    display_board(board);

    for (int turn = 0; turn < 9 && !game_over; turn++) {
        take_turn(board, player);
        display_board(board);

        if (is_winner(board, player)) {
            game_over = true;
}       else {
            player = other_player(player);
}
}

    if (!game_over) {
        printf("Tie!\n");
}   else if (player == HUMAN) {
        printf("What! How did I miss that. Congratulations I guess...\n");
}   else {
        printf("HAHA. Better luck next time!\n");
}
}

/* 15 */
bool play_again(void)
{
    char answer = ' ';

    while (answer != 'y' && answer != 'q') {
        printf("\nDo you want to run it back? Press y to keep going or q to quit: ");
        scanf(" %c", &answer);

        while (getchar() != '\n') {
            /* 16 */
}

        if (answer != 'y' && answer != 'q') {
            printf("  Please type y or q.\n");
}
}
    return answer == 'y';
}

/* 17 */
int main(void)
{
    int seed = 0;

    printf("=====================================\n");
    printf("        TIC-TAC-TOE vs COMPUTER\n");
    printf("=====================================\n");

    /* 18 */
    printf("Type a number to randomize my moves: ");
    scanf("%d", &seed);
    srand(seed);

    do {
        play_game();
}         while (play_again());

    printf("\nThat was fun! GGs.\n");
    return 0;
}
