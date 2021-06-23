/*
RpgLog.c
---------------------------------------------------------------------------------------------------
   author: José Maia da Silva Neto
   e-mail : maianeto2014@gmail.com
---------------------------------------------------------------------------------------------------
    This program produces a simple rpg log based on Dungeons and Dragons 2nd edition
    It simulates a combat between the user and a monster    
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int dice;

struct Adventurer {
    char Name [30];
    char Class [7];
    int HitPoints;
    int strenght;
    int dexterity;
    int constitution;
    int wisdom;
    int intelligence;
    int charisma;
    int money;
    int AC;
    int THAC0;
    int damage;
};

struct Monster {
    char Name [30];
    int HitPoints;
    int strenght;
    int AC;
    int THAC0;
    int damage;
};

int main()

{
    //int dice;
    bool possible = true;
    time_t t;
    int selection;

    srand((unsigned) time(&t));

    struct Monster orc;
    orc.strenght = rand()%16 + 3;
    orc.AC = 8;
    orc.HitPoints = rand()%20 + 1;
    orc.THAC0 = 17;
    orc.damage = rand()%6 + 1;

    struct Adventurer player1;
    player1.strenght = rand()%16 + 3;
    player1.dexterity = rand()%16 + 3;
    player1.constitution = rand()%16 + 3;
    player1.wisdom = rand()%16 + 3;
    player1.intelligence = rand()%16 + 3;
    player1.charisma = rand()%16+ 3;
    player1.AC = 10;
    player1.THAC0 = 17;
    player1.damage = rand()%8 + 1;

    printf("Character stats:\n");
    printf("%d\n", player1.strenght);
    printf("%d\n", player1.dexterity);
    printf("%d\n", player1.constitution);
    printf("%d\n", player1.wisdom);
    printf("%d\n", player1.intelligence);
    printf("%d\n", player1.charisma);

    if(player1.strenght >= 9 && player1.wisdom >= 9 && player1.intelligence >= 9) {
        printf("Available Classes:\nFighter\nWizard\nCleric\n");
    }else if(player1.strenght >= 9 && player1.wisdom >= 9){
        printf("Available Classes:\nFighter\nCleric\n");
    }else if(player1.strenght >= 9 && player1.intelligence >= 9){
        printf("Available Classes:\nFighter\nWizard\n");
    }else if(player1.wisdom >= 9 && player1.intelligence >= 9){
        printf("Available Classes:\nCleric\nWizard\n");
    }else if(player1.strenght >= 9) {
             printf("Available Classes:\nFighter\n");
    }else if(player1.wisdom >= 9){
            printf("Available Classes:\nCleric\n");
    }else if(player1.intelligence >= 9){
            printf("Available Classes:\nWizard\n");
    }else if(player1.strenght < 9 && player1.wisdom < 9 && player1.intelligence < 9) {
        printf("Impossible character\n");
        possible = false;
    }

    if(possible){
        printf("Select a Class\nType 1 for Fighter\n");
        printf("Select a Class\nType 2 for Wizard\n");
        printf("Select a Class\nType 3 for Cleric\n");

        scanf("%d", &selection);

        switch(selection) {
        case 1 :
            if(player1.strenght >= 9) {
                strcpy(player1.Class, "Fighter");
                printf("Class selected: %s\n", player1.Class);
                player1.HitPoints = rand()%10 + 1;
                player1.money = (rand()%16 + 5)*10;
                //printf("%d\n", player1.money);
                //printf("%d\n", player1.HitPoints);
            }else {
                printf("Not available class\n");
            }
            break;
        case 2 :
            if(player1.intelligence >= 9) {
                strcpy(player1.Class, "Wizard");
                printf("Class selected: %s\n", player1.Class);
                player1.HitPoints = rand()%4 + 1;
                player1.money = ((rand()%4 + 1) + 1)*10;
                //printf("%d\n", player1.money);
                //printf("%d\n", player1.HitPoints);
            }else {
                printf("Not available class\n");
            }
            break;
        case 3 :
            if(player1.wisdom >= 9) {
                strcpy(player1.Class, "Cleric");
                printf("Class selected: %s\n", player1.Class);
                player1.HitPoints = rand()%8 + 1;
                player1.money = (rand()%16 + 3)*10;
                //printf("%d\n", player1.money);
                //printf("%d\n", player1.HitPoints);
            }else {
                printf("Not available class\n");
            }
            break;
    }

        printf("What is thy name?:\n");
        scanf("%s", &player1.Name);
        printf("Character sheet:\n");
        printf("Name: %s\n", player1.Name);
        printf("Strenght: %d\n", player1.strenght);
        printf("Dexterity: %d\n", player1.dexterity);
        printf("Constitution: %d\n", player1.constitution);
        printf("Wisdom: %d\n", player1.wisdom);
        printf("Intelligence: %d\n", player1.intelligence);
        printf("Charisma: %d\n", player1.charisma);
        printf("Armor Class: %d\n", player1.AC);
        printf("Hit points: %d\n", player1.HitPoints);
        printf("Money: %d\n", player1.money);

        printf("\n\n\n");

        while(player1.HitPoints > 0 && orc.HitPoints > 0){
            dice = rand()%20 + 1;
            if(dice >= ((player1.THAC0)-(orc.AC))) {
                orc.HitPoints = orc.HitPoints - player1.damage;
            }
            printf("Roll: %d\n", dice);
            printf("Enemy hit points: %d\n", orc.HitPoints);
        }
        if(player1.HitPoints <= 0){
            printf("GAME OVER");
        }else if(orc.HitPoints <= 0) {
            printf("You defeated the orc.");
        }

    }

    return 0;
}