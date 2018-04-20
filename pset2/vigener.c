/*
    Author: Simon Sisay
       CS50 Pset2
    Vigener encryption method

*/
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //checks if the the arguments are not more or less than 2
    if(argc != 2)
    {
        printf("Please enter a valid argument second should be a letter or a word \n\n");
        return 1;
    }

    //Go through each letter in the second argument to check
    // if the user hasnt entered a non -alphabetic character
    for (int i = 0; i < strlen(argv[1]); i ++)
    {
        if(!isalpha(argv[1][i]))
        {
            printf("Please do not enter a number or a string with no space \n\n");
            return 1;
        }
    }


    string text = get_string("Enter text:");
    string word = argv[1];
    int n = strlen(text);

    printf("Cypher text: ");

    //check if the letters are upper case , lower case or niether
    //and print the the encryption of the letter

    for(int i = 0; i < n; i++)
    {
        //checks if the ith letter of the text is upper case
        if(isupper(text[i]))
        {
            if(word[i] + text[i] <= 'Z')
            {
                printf("%c", word[i] + text[i]);
            }
            else
            {
                //if the some of the ith letter word and ith letter in word
                //exceed above 'Z' do not let it print the next character instead restart from "A"

                printf("%c", (word[i] + text[i])%26 + 65);
            }

        }
        else if(islower(text[i]))
        {
                if(word[i] + text[i] <= 'z')
                {
                    printf("%c", word[i] + text[i]);
                }
                else
                {

                //if the some of the ith letter word and ith letter in word
                //exceed above 'z' do not let it print the next character instead restart from "a"

                    printf("%c", (word[i] + text[i])%26 + 97);
                }
        }

        else
        {
            //if the ith letter is a charachter(not a letter) print with out making no change
            printf("%c", text[i]);
        }
    }
    printf("\n\n");
    return 0;

}
