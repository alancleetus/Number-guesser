// Number guesser
//20 February, 2014

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

main(){
	
	int gameType, userGuess, aiGuess, high=100, low=0, i=0;
	char ch;
	char ready;
	
	cout<<"1. Player guess."<<endl<<"2. Computer guess."<<endl<<"3. Quit."<<endl<<endl;
	cout<<"Enter a number here : ";
	cin>>gameType;
	
	switch(gameType)
	{
		//Player guess
		case 1:{
			
			unsigned seed = time(0);
	
			srand(seed);
			
			aiGuess = rand()%100;
			
			do{
				cout<<endl<<"Enter a guess : ";
				cin>>userGuess;
				
				i++;
				
				if(userGuess<aiGuess){
					
					cout<<endl<<"Too low"<<endl;
					
				}else if(userGuess>aiGuess){
					
					cout<<endl<<"Too high"<<endl;
					
				}else{
					
					cout<<endl<<"You Got It !!!"<<endl;
				}
					
			}while(userGuess != aiGuess);
			
			break;
		}
		//Computer guess
		case 2:{
			cout<<endl<<"RULES :"<<endl<<"If AI guess is too low enter the letter  'L'."<<endl;
			cout<<"If AI guess is too high enter the letter 'H'."<<endl;
			cout<<"If AI guess is correct enter the letter  'C'."<<endl; 
			
			cout<<endl<<"Think of a number between 0 and 100 ."<<endl;
			cout<<"When ready press letter 'R', or press letter 'Q' to quit."<<endl;
			cin>>ready;
			
			if(ready == 'r' || ready == 'R'){
				
				do{
				
				aiGuess=((high-low)/2)+low;
				cout<<endl<<"Is the number : "<<aiGuess<< "\n too high, too low , or correct : ";
				cin>>ch;
				
				i++;
				
				switch(ch) {
					
					case 'l':
					case 'L':{
						
						low = aiGuess;
						
						break;
					}
					
					case 'h':
					case 'H':{
						
						high = aiGuess;
						
						break;
					}
					
					case 'c':
					case 'C':{
						
						cout<<endl<<"THANK YOU FOR PLAYING !!!"<<endl;
						
						break;
					}
					
					default:cout<<"Invalid input.";
					}
					}while(ch!='c' && ch !='C' );
					
			// using if statemets		
			//	if(ch == 'l' || ch == 'L' ){
			//		
			//		low = aiGuess;
			//		
			//	}else if(ch == 'h' || ch== 'H'){
			//		
			//		high = aiGuess;
			//	
			//	}else if (ch=='C'||ch=='c'){
			//		
			//		cout<<endl<<"THANK YOU FOR PLAYING !!!"<<endl;
			//		
			//	}else{
			//		cout<<"Invalid character.";
			//	}
			//	
			}else if(ready== 'q' || ready == 'Q'){
				return 3;
			}else {
				cout<<"invalid"<<endl;
			}
			break;
		}
		//Quit
		case 3:return 2;
			   break;
		//Input error
		default:cout<<"invalid number."<<endl;
		
	}
	
	cout<<endl<<"Number of Guesses : "<<i<<endl;
	
	return 0;
}