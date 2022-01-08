#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[]) {
    if (argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else {
        string key = argv[1];
        for (int i = 0, n = strlen(key); i< n; i++) {
            if (key[i] > 122 || key[i] < 65) {
                printf("Key needs to only contain letters.\n");
                return 1; 
            }
            for (int j = 0; j < n - i; j++) {
                if (key[i] == key[j+i+1]) {
                    printf("How the fuck is key supposed to work with duplicate characters.\n");
                    return 1;
                }
            }
        }
        if (strlen(key) != 26) {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else {
            printf("wow you know how to use this program you doofus\n");
            int numkey[26] = {};
            for (int i = 0, n = strlen(key); i < n; i++) {
                if (isupper(key[i])) {
                    key[i] = key[i] + 32;
                }
                numkey[i] = key[i] - 97 - i;
            }  //process key into all lower case and gets an array of numbers to shift the chars the correct way
            string input = get_string("plaintext:  ");
            string output = input;
            for (int i = 0, n = strlen(input); i < n; i++) {
                if (input[i] > 64 && input[i] < 91) {
                    output[i] = input[i] + numkey[input[i]-65];
                }
                else if (input[i] > 96 && input[i] < 123) {
                    output[i] = input[i] + numkey[input[i]-97];
                }
            }
            printf("ciphertext: %s\n", output);
            return 0;
        }
    }
}