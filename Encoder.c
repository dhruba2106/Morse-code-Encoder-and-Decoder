//This is the code for Morse code encoder.
//It takes a string as input and returns the Morse code equivalent of the string.

#include <stdio.h>
#include <string.h>

char *morse_code[] = { ".-",   // A
                      "-...",  // B
                     "-.-.",  // C
                     "-..",   // D
                     ".",     // E
                     "..-.",  // F
                     "--.",   // G
                     "....",  // H
                     "..",    // I
                     ".---",  // J
                     "-.-",   // K
                     ".-..",  // L
                     "--",    // M
                     "-.",    // N
                     "---",   // O
                     ".--.",  // P
                     "--.-",  // Q
                     ".-.",   // R
                     "...",   // S
                     "-",     // T
                     "..-",   // U
                     "...-",  // V
                     ".--",   // W
                     "-..-",  // X
                     "-.--",  // Y
                     "--..", // Z
                     ".----",//1
                     "..---",//2
                     "...--",//3
                     "....-",//4
                     ".....",//5
                     "-....",//6
                     "--...",//7
                     "---..",//8
                     "----.",//9
                     "-----",//0
        };

char words[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

int main() {
    char str[100];

    printf("Press 1 for Encoding and press 2 for Decoding: ");
    int choice;
    scanf("%d", &choice);

    // choice for encoding;
    if (choice == 1) {
        printf("Enter the string to be encoded: ");
        scanf(" %[^\n]", str);  // use scanf with space to consume newline character
        int i = 0;
        while (str[i] != '\0') {
            for (int j = 0; j < 26; j++) {
                if (str[i] == words[j] || str[i] == words[j] + 32) {  // check for both uppercase and lowercase
                    printf("%s ", morse_code[j]);
                    break;
                }
            }
            i++;
        }
        printf("\n");
    }
    // choice for decoding;
    else if (choice == 2) {
        printf("Enter the string to be decoded: ");
        scanf(" %[^\n]", str);  // use scanf with space to consume newline character
        char temp[3];  // to store morse code
        int i = 0, j = 0;
        while (str[i] != '\0') {
            while (str[i] != ' ' && str[i] != '\0') {
                temp[j++] = str[i++];
            }
            temp[j] = '\0';
            for (int k = 0; k < 26; k++) {
                if (strcmp(temp, morse_code[k]) == 0) {
                    printf("%c", words[k]);
                    break;
                }
            }
            i++;  // to skip the space
            j = 0;  // reset j
        }
        printf("\n");
    }
    else {
        printf("Invalid choice\n");
    }

    return 0;
}