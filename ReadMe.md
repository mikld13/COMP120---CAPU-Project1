Tic-Tac-Toe Code Explination

The objective of this project was to write a tic-tac-toe game where the user plays against the computer. The user plays as O and goes first, while X, the computer, picks its moves at random. 

Each number matches a /* n */ comment in my .c file.
1.	The board is stored as a row of 9 squares, numbered 0 to 8. When printed, it is split into three rows of three using /n so it looks like a proper  tic-tac-toe board.
2.	Names are given to the three options a square can hold. O is used for the user input and X is used for the computer’s moves, while the last option is empty. This is simply a readability for code lower in the file.
3.	init_board clears the board by setting every square back to empty and is called at the start of every game.
4.	display_board prints a copy of the board with placeholder values inserted so that the player is able to select their move easily, while maintaining empty/taken cell status. 
5.	is_winner checks whether a player has met one of tic-tac-toe’s win conditions.
6.	The first three check for horizontal wins: 0-1-2, 3-4-5 and 6-7-8.
7.	The next three are the vertical wins: 0-3-6, 1-4-7 and 2-5-8.
8.	The last two are the diagonals: 0-4-8 and 2-4-6.
9.	other_player enables turn switching by giving returning the opposite of the player who just took a turn. So, X if it is given O and O if it is given X. 
10.	get_human_move asks the user for a square and keeps asking until a viable answer is given. If the user types something invalid, like a non number character, an invalid number, or a square that is already taken, it tells them what went wrong and asks again.
11.	After every answer, whatever else the user typed on that line is thrown away. Without this, the program would keep reading the same bad input over and over.
12.	get_computer_move picks a random square. If that square is already taken, it just picks again until it finds an empty one, so the computer can never make an illegal move.
13.	take_turn handles a single move for the player and computer. For the user it asks for a square, and for the computer it picks one at random and prints which square it chose. Either way, the player's symbol is then placed on the board.
14.	play_game runs one full game. There are at most 9 turns since there are only 9 squares. On each turn the current player moves, the board is shown again, and then it checks if that player has won. If they have, the game ends early, and if not, the turn goes to the other player. Once the game is over it announces who won, or that it was a draw if the board filled up with no winner.
15.	play_again asks the user if they want to play another game, and keeps asking until they type y to play again or q to quit.
16.	This works the same as step 11. Anything extra the user typed is thrown away so it does not mess up the next question.
17.	main is where the program starts. It prints the title and then plays a game, and after each game it asks if the user wants to play again. A game is always played at least once, after which the loop repeats until the player chooses to quit.
18.	The computer's random choices are not truly random. They come from a sequence that depends on a starting number, so the user is asked to type any number here, which is then used as that starting point of randomization. 
