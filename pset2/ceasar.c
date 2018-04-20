/*
    Author - Simon Sisay
     CS50 problem set2
      Ceasar Cypher
*/
#include <ctype.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, string argv[])
{

    //check if the user eneterd a valid input(command-line arguments

    if(argc !=2 || atoi(argv[1]) < 0 || !isdigit(argv[1]))
    {
        printf("Command-line arguments must be no more or less than 2 \n second argument should be greater than 0 \n");
        return 1;
    }

    int key = atoi(argv[1]);
    string text = get_string("Plain text: ");
    int n = strlen(text);

    printf("Cypher text: ");

    //Go through each letter and check if its uppercase, lowercase or niether

    for(int i = 0; i < n; i++)
    {
        if(isupper(text[i]) && isalpha(text[i]))
        {
            if(text[i] + key <= 'Z')
            {
                printf("%c", text[i]+key);
            }
            else
            {
                //if adding the cypher key exceeds the limit(above Z), we have to continue
                // from 'A' to avoid printing other characters

                printf("%c",(text[i]+key)%26 + 65);
            }
        }

        //if the ith letter is lower case
        else if(islower(text[i]) && isalpha(text[i]))
        {
            if(text[i] + key <= 'z')
            {
                printf("%c", text[i] + key);
            }
            else
            {
                printf("%c", (text[i] + key ) %26 + 97);
            }
        }

        //If the ith letter in the text is not a letter then make no changes
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n\n");


    return 0;
}

