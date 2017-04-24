#include <stdio.h>
#include <stdlib.h>

int playerNum;
int roundNum;
int SEED;
int totalScore[5] ={0,0,0,0,0};
int currentRound = 1;
int currentPlayer =1;
int dices[5] = {-1, -1, -1, -1, -1};
int roundScores[5] = {0,0,0,0,0};
int sum ;
int timesToRoll =1;
int roundMax;
int roundMin;
int leader;

void clearBuffer();
void printTOTALSCORETable();
void printRoundTable();
void enterSEED();
void enterPlayerNum();
void enterRoundNum();
void prompt(int round, int player);
void prompt2();
void prompt3();
void game();
void inputR();
int rollDice(void);
void roll();
void drawDice(int dice1, int dice2, int dice3, int dice4, int dice5);

int main(){
	
	enterSEED();
	srand(SEED);
	enterPlayerNum();
	enterRoundNum();
	game();
	
	return 0;
}

void printTOTALSCORETable(){
	int i;
	printf("\n%s%d\n", "Round: ", currentRound);
	printf("%-18s", "Players:");
	for(i = 1; i <= playerNum; i++){
		printf("%-10d", i);
	}
	printf("\n%s","==============");
	for(i = 1; i <= playerNum; i++){
		printf("%s","==========");
	}
	printf("\n%-18s", "Round:");
	for( i = 0; i <  playerNum; i++){
		if(roundScores[i] == 0){
			printf("%-10s","-");
		}
		else {
			printf("%-10d", roundScores[i]);
		}
	}
	printf("\n%-18s", "Total:");
	for( i = 0; i <  playerNum; i++){
		printf("%-10d", totalScore[i]);
	}
	printf("\nPlayer %d is the leader\n", leader);
}

void printRoundTable(){
	int i;
	printf("\n%s%d\n", "Round: ", currentRound);
	printf("%-18s", "Players:");
	for(i = 1; i <= playerNum; i++){
		printf("%-10d", i);
	}
	printf("\n%s","==============");
	for(i = 1; i <= playerNum; i++){
		printf("%s","==========");
	}
	printf("\n%-18s", "Round:");
	for( i = 0; i <  playerNum; i++){
		if(roundScores[i] == 0){
			printf("%-10s","-");
		}
		else {
			printf("%-10d", roundScores[i]);
		}
	}
	printf("\n%-18s", "Total:");
	for( i = 0; i <  playerNum; i++){
		printf("%-10d", totalScore[i]);
	}
	printf("\n");
}

void enterSEED(){
	printf("\n%s", "Enter SEED: ");
	char term;
	if((scanf("%d%c", &SEED, &term)) != 2 || term != '\n'){
		printf("%s", "Input must be an unsigned integer, try again!\n");
		clearBuffer();
		enterSEED();
	}
	else if( SEED < 0){
		printf("%s", "Input must be an unsigned integer, try again!\n");
		enterSEED();
	}
	return;
}

void enterPlayerNum(){
	printf("%s", "\nEnter the number of players (2-5): ");
	char term;
	if( (scanf("%d%c", &playerNum, &term) != 2) || term != '\n'  ){
		printf("%s", "Input must be integer, and the range is 2-5!\n");	
		clearBuffer();
		enterPlayerNum();
	}
	else if ( playerNum<2 || playerNum>5){
		printf("%s", "Input must be integer, and the range is 2-5!\n");
		enterPlayerNum();
	}
	
}

void enterRoundNum(){
	printf("\n%s", "Enter the number of rounds to play (1-10): ");
	char term;
	if( (scanf("%d%c", &roundNum, &term) != 2) || term != '\n' ){
		printf("%s", "Input must be integer, and the range is 1-10!\n");
		clearBuffer();
		enterRoundNum();
	}
	else if( roundNum<1 || roundNum>10){
		printf("%s", "Input must be integer, and the range is 1-10!\n");
		enterRoundNum();
	}
}

void prompt(int round, int player){
	printf("%s%d%s\n", "\nRound ",round, ":");
	printf("%s %d %s\n", "Player", player, "Enter \"R \" To Roll The Dice.");
}

void inputR(void){
	char term;
	char charR;
	if( (scanf("%c%c", &charR, &term) != 2) || term != '\n'){
		printf("%s\n","Invalid input rather than \"R\", try again!");
		clearBuffer();
		inputR();
	}
	else if( charR != 'R' && charR != 'r' ){
		printf("%s\n","Invalid input rather than \"R\", try again!");
		inputR();
	}
	else{
		return ;
	}

}

int rollDice(void){
	return 1 + (int) (6.0 * rand() / (RAND_MAX + 1.0));
}

void roll(){
	if(timesToRoll == 1){
		drawDice( rollDice(), rollDice(), rollDice(), -1, -1);
	}
	else if(timesToRoll ==2){
		drawDice( rollDice(), rollDice(), rollDice(), rollDice(), -1);
	}
	else if(timesToRoll ==3){
		drawDice( rollDice(), rollDice(), rollDice(), rollDice(), rollDice());
	}
	else 
		return;
}

void drawDice(int dice1, int dice2, int dice3, int dice4, int dice5){
	int i ;
	sum =0;
	dices[0] = dice1;
	dices[1] = dice2;
	dices[2] = dice3;
	dices[3] = dice4;
	dices[4] = dice5;
	for(i = 0; dices[i] > 0 && i < 5; i++){
		printf("%s", "- - - - - - ");
	}
	printf("\n");
	for(i = 0; dices[i] > 0 && i< 5; i++){
		printf("%s%d%s", "|    ", dices[i], "    | ");
	}
	printf("\n");
	for(i = 0; dices[i] > 0 && i< 5; i++){
		printf("%s", "- - - - - - ");
	}
	for(i = 0; dices[i] > 0 && i < 5; i++){
		sum += dices[i];
	}
	printf("\n\n");
	printf("%s%d\n", "Current Total Sum: ",sum);
	roundScores[currentPlayer - 1 ] = sum;
	
}

void prompt2(){
	printf("%s\n","Enter \"R\" to roll again, \"H\" to hold, or \"T\" for round table.");
	char input;
	char term;
	if( (scanf("%c%c", &input, &term) != 2) || ( term != '\n')){
		printf("%s", "Input is invalid, try again!\n");
		clearBuffer();
		prompt2();
	}
	else if( (input != 'r') && (input != 'R') && (input != 'h') && (input != 'H' )&&(input != 't')&&( input != 'H')){
		printf("%s", "Input is invalid, try again\n");
		prompt2();
	}
	else{
		if((input == 'r') || (input == 'R')){
			timesToRoll++;
			roll();
			if(timesToRoll == 3){
				timesToRoll = 1;
				roundScores[currentPlayer-1] = sum;
				sum = 0;
				return;
			}
			else{
				prompt2();
			}
		}
		
		else if((input == 'h') ||( input == 'H')){
			timesToRoll = 1;
			roundScores[currentPlayer-1] = sum;
			sum = 0;
			return;
		}
		
		else if((input =='t')|| (input =='T')){
			printRoundTable();
			prompt2();
		}
	
	}
}

void prompt3(){
	char input1;
	char term1;
	int i;
	if((scanf("%c%c", &input1, &term1) != 2) || (term1 !='\n')){
		printf("%s","Invalid input, try again! \n");
		clearBuffer;
		prompt3();
	}
	else if( (input1 != 'p') && (input1 != 'P') && (input1 != 'q') && (input1 != 'Q')){
		printf("%s","Invalid input, try again! \n");
		prompt3();
	}
	else {
		if((input1 == 'q') || (input1 == 'Q')){
			exit(0);
		}
		else if((input1 == 'p') ||( input1 == 'P')){
			for(i=0; i<5; i++){
				totalScore[i] =0;
			}
			game();
		}
	
	}
}

void game(){
	for(currentRound = 1; currentRound <= roundNum; currentRound++){
		for(currentPlayer =1; currentPlayer <= playerNum; currentPlayer++){
			prompt(currentRound, currentPlayer);
			inputR();
			roll();
			prompt2();	
		}
		int winner = 0;
		roundMax = roundScores[0];
		roundMin = roundScores[0];
		int i;
			for(i=1; i < 5 && (roundScores[i] !=0); i++){
				if(roundMax < roundScores[i] ){
					roundMax = roundScores[i];
				}
		    }
			for(i=1; i < 5 && (roundScores[i] !=0); i++){
				if(roundMin > roundScores[i] && (roundScores[i] !=0)){
					roundMin = roundScores[i];
					winner = i;
				}
			}
		totalScore[winner] += roundMax - roundMin;
		leader = 0;
		int currentMax = totalScore[0];
		for(i = 1; i < 5 ; i++){
			if(currentMax < totalScore[i]){
			currentMax = totalScore[i];
			leader = i ;
			}
		}
		leader++;
		printTOTALSCORETable();
		
		for(i=0; i<5; i++){
			roundScores[i] =0;
		}
	}
	printf("\nCONGRATULATIONS Player %d, YOU WON!\n\nEnter \"P\" to Play again, or \"Q\" to Quit: ", leader);
	prompt3();
	
	
}






/**
* This method clears the input buffer.
*/
void clearBuffer(){
	while(getchar()!= '\n');
}

