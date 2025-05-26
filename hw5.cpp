//
//Radhika Agrawal
//HW 5 titled Dungeons and Dragons
//

#include <iostream>
#include <cstdlib>
#include <time.h>


using namespace std;

int main(){
	
    srand(time(0));
    
	//Character creation phase 1 - Choosing character name
    cout << "Welcome! You are now playing 'Dungeons and Dragons'. Please enter a name for your character. ";
	string character_name;
	cin >> character_name;
    
    int character_strength = 0;
    int character_dexterity = 0;
    int character_vitality = 0;
    
    int choice = 0;
    
    for (int i = 0; i < 4; i++){
        //Character creation phase 2(a)  - Randomly generating stats for strength, dexterity, vitality between 1 and 20
        character_strength = rand() % 20 + 1;
        character_dexterity = rand() % 20 + 1;
        character_vitality = rand() % 20 + 1;
        
        cout << endl << "Hey " << character_name << "! Here are your stats: ";
        cout << endl << "Strength: " << character_strength;
        cout << endl << "Dexterity: " << character_dexterity;
        cout << endl << "Vitality: " << character_vitality;
        
        //Character creation phase 2(b)  - Letting user accept or reject the generated stats
        cout << endl << "Do you accept these stats for your character? Enter 1 for yes or 0 for no. ";
        cin >> choice;
    }
    
    cout << "No further choices are available, you will have to continue with the above stats.";
    
    //Character creation successful!
    cout << endl << character_name << " enters the dungeons!";
   
    int repeat = 0;
    
    while (repeat == 0){
        string monster[] = {"Goblin", "Goblin", "Goblin", "Goblin", "Goblin", "Goblin", "Orc", "Orc", "Orc", "Dragon"};
        int monster_index = rand() % 10;
        string monster_type = monster[monster_index];
        
        int monster_strength = 0;
        int monster_dexterity = 0;
        int monster_vitality = 0;
        
        //Randomly generating stats for strength, dexterity, vitality depending on the monster type chosen randomly above
        //
        //If monster type is goblin, the stats are randomly generated numbers between 1 and 10
        if(monster_type == "Goblin"){
            monster_strength = rand() % 10 + 1;
            monster_dexterity = rand() % 10 + 1;
            monster_vitality = rand() % 10 + 1;
        }
        //If monster type is orc, the stats are randomly generated numbers between 6 and 15
        else if(monster_type == "Orc"){
            monster_strength = rand() % 15 + 6;
            monster_dexterity = rand() % 15 + 6;
            monster_vitality = rand() % 15 + 6;
        }
        //If monster type is dragon, the stats are randomly generated numbers between 11 and 20
        else{
            monster_strength = rand() % 20 + 11;
            monster_dexterity = rand() % 20 + 11;
            monster_vitality = rand() % 20 + 11;
        }
        
        cout << endl << character_name << " encounters a " << monster_type << " with strength = " << monster_strength << ", dexterity = " << monster_dexterity << ", vitality = " << monster_vitality;
        
        cout << endl << "Do you want to fight or run? Enter 1 to fight or 0 to run. ";
        int choice_of_play;
        cin >> choice_of_play;
        
        // If user enters 0, we run and character loses gold.]
        if(choice_of_play == 0){
            cout << character_name << " runs and loses gold.";
            repeat = 0;
        }
        else{
            //Trying to debug using cout statement
            cout<< character_strength << " " << character_dexterity << " " << character_vitality << endl;
            
            int character_random_number = rand() % 10 + 1;
            
            int monster_random_number = rand() % 10 + 1;
            //Regenerating the random number for monster if in case it is the same as the random number generated for character
            if(character_random_number == monster_random_number)
            {
                monster_random_number = rand() % 10 + 1;
            }
            
            //Calculating the battle scores for both character and monster
            int character_battle_score = character_random_number + character_strength + character_dexterity + character_vitality;
            int monster_battle_score = monster_random_number + monster_strength + monster_dexterity + monster_vitality;
            
            //If character's battle score is less than that of monster, character loses and dies.
            if(character_battle_score < monster_battle_score){
                cout << character_name << " has lost and is dead.";
                repeat = 1;
            }
            //If character's battle score is more than that of monster, character wins and earns gold.
            else{
                cout << character_name << " has won and earned gold.";
                repeat = 0;
            }
        }
    }
	return 0;
}
