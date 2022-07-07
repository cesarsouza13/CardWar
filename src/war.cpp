#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

//Class Player
class Player{
    
    private:
    vector<string> deck;
    public:
   void InsertCards(string card){ //insert cards of the deck
       
    card.pop_back();
        
        if(card.front() == 'J'){
            card = "11";
        }
        if(card.front() == 'Q'){
            card = "12";
        }
        if(card.front() == 'K'){
            card = "13";
        }
        if(card.front() == 'A'){
            card = "14";
        }
        auto it = this->deck.begin();
        this->deck.insert(it, card);

    }

    void InsertFront(string card){  //insert cards at the begnning of the deck
        auto it = this->deck.begin();
        this->deck.insert(it, card);
    }

    



    //method responsible for war in between cards, return the current round
    int War(Player &p, int war, int count){ 

        int severalWars = war;
        auto it1 = next(this->deck.end(), -severalWars);
        auto it2 = next(p.deck.end(), -severalWars);
        string card1 = *it1;
        string card2 = *it2;
        int num1 = stoi(card1);
        int num2 = stoi(card2);
     
        if(num1 > num2){
      
            for(int i = 0; i < severalWars; i++){
                card1 = this->deck.back();
                this->InsertFront(card1);
                this->deck.pop_back();
            }

             for(int i = 0; i < severalWars; i++){             
                card2 = p.deck.back();
                this->InsertFront(card2);
                p.deck.pop_back();
            }
             severalWars = 1;
             count++;
        }

         if(num1 < num2){
         
            for(int i = 0; i < severalWars; i++){
              card1 = this->deck.back();
              p.InsertFront(card1);
              this->deck.pop_back();
            }

            for(int i = 0; i < severalWars; i++){             
               card2 = p.deck.back();
               p.InsertFront(card2);
               p.deck.pop_back();
            } 
            severalWars = 1;
            count++;
        }

        return count;

    }
      
         
    //method responsible for battle in between cards, return the resulto of game
    string Atack(Player& p){
 

        int count = 0;
        int war = 1;
        string result;
        while((this->deck.size() > 0) && (p.deck.size() > 0)){//game ends when deck equal at 0
            
            string card1 = this->deck.back();
            string card2 = p.deck.back();
            int num1 = stoi(card1);
            int num2 = stoi(card2);

            if(num1 > num2){          
                this->InsertFront(card1);
                this->InsertFront(card2);
                this->deck.pop_back();
                p.deck.pop_back(); 
                war = 1;
                count++;
            }
            
            if(num1 < num2){             
                p.InsertFront(card1);
                p.InsertFront(card2);
                p.deck.pop_back(); 
                this->deck.pop_back();
                war = 1;
                count++;
            }

            if(num1 == num2){           
                war += 4;

                if((this->deck.size() > 4) && (p.deck.size() > 4)){
                    count = this->War(p, war, count);
                }

                else{
                    result = "PAT";
                    return result;
                }
            
            }

        

                
        }

            //if deck  size equal at 0, transform number rounds in string
            if(p.deck.size() == 0){
                result = "1 "+ to_string(count);
            }
            else if(this->deck.size() == 0){
                result = "2 "+ to_string(count);
            }
            
                return result;
    }  
    
};



int main()
{   
    int n; // the number of cards for player 1
    cin >> n; cin.ignore();
    Player p1; //created object player
    Player p2;
    
    for (int i = 0; i < n; i++) {
        string cardp_1; // the n cards of player 1
        cin >> cardp_1; cin.ignore();

        p1.InsertCards(cardp_1);
    }
    int m; // the number of cards for player 2
    cin >> m; cin.ignore();
    for (int i = 0; i < m; i++) {
        string cardp_2; // the m cards of player 2
        cin >> cardp_2; cin.ignore();
        p2.InsertCards(cardp_2);

        
    }

    
  

    string result = p1.Atack(p2); //Player1 atack Player 2, get answer in string
  
   



  

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << result << endl;
}




