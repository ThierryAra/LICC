#include<stdio.h>

int main () {

    int players, rounds, position_pingu, pinguins = 0, current_round = 1, turn = 1;

    scanf ("%i %i %i", &rounds, &players, &position_pingu);

    // Checking input restrictions
    if (position_pingu < 1 || position_pingu > players || players < 2 || rounds < 1){
        return 0;
    }

    // While is kept as long as the number of rounds is less than the number of rounds, to keep the for's repeating
    while (current_round <= rounds)
    {
        for (int i = 0; i < turn; i++)
        {
            // While check inside the for's because the round counter is inside the for, so it can extrapolate before returning to the while
            if (current_round > rounds) return 0; 

            // If the round is equal to position_pingu (turn in first round) + players*pinguim (multiples of pingu's turn), then he must play
            if (current_round == (position_pingu + (players * pinguins))) {
                if (turn == 1){
                    printf ("1 pinguim\n");
                } else {
                    printf ("%i pinguins\n", turn);
                }
            }

            // If the round is a multiple of the number of players it means that everyone has already played the turn
            if ((current_round % players) == 0) {
                pinguins++;
            }
            
            current_round++;
        }


        for (int i = 0; i < turn; i++)
        {
            if (current_round > rounds) return 0;

            if (current_round == (position_pingu + (players * pinguins)))
                printf ("no gelo\n");

            if ((current_round % players) == 0) {
                pinguins++;
            }

            current_round++;
        }
        for (int i = 0; i < turn; i++)
        {
            if (current_round > rounds) return 0;

            if (current_round == (position_pingu + (players * pinguins)))
                printf ("uhuu!\n");
            

            if ((current_round % players) == 0) {
                pinguins++;
            }

            current_round++;
        }
        
        turn++;
    }
    
    return 0;
}