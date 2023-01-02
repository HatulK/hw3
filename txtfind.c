//
// Created by amit on 12/26/22.
//
#include <string.h>
#include <malloc.h>
#include "stdio.h"

#define MAX_LINE 256
#define LINES 250
#define WORD 30
char text[LINES][MAX_LINE];
char word[WORD];
char line[MAX_LINE];

int getText() {
    memset(text, 0, sizeof(text));
    int i = 0;
    int j = 0;
    int c;
    while ((c = fgetc(stdin)) != EOF) {
        if (c != '\n') {
            text[i][j] = (char) c;
            j++;
        } else {
            i++;
            j = 0;
        }
    }
    return i;
}

//getLines returning the amount of words in the line
int getLine(int i) {
    memset(line, 0, sizeof(line));
    int counter = 0;
    for (int j = 0; j < MAX_LINE; j++) {
        line[j] = text[i][j];
        if (line[j] == ' ' || line[j] == '\t') counter++;
        if (line[j] == '\n' || line[j] == '\0') break;
    }
    return counter + 1;
}

//getWord is putting into global variant "word" the word in the i'th line and the j'th position in line.
//getWord returns the index in the line where the word starts.
int getWord(int i, int j) {
    memset(word, 0, sizeof(word));
    getLine(i);
    int wordcounter = 0;
    int charinline = 0;
    int charinword = 0;
    char temp = line[charinline];
    while (temp != '\n' && temp != '\0') {
        //
        if (wordcounter == j && temp != ' ' && temp != '\t') {
            word[charinword++] = temp;
        }
        if (wordcounter > j) break;
        if (temp == ' ' || temp == '\t') wordcounter++;
        charinline++;
        temp = line[charinline];
    }
    return charinword;
}

int substring(char *str1, char *str2) {
    char *a = str1; // bbbbc // bbc
    char *b = str2;
    int lastposind = 0;
    while ((*a != '\0') && (*b != '\0')) {
        if (*b == *a) {
            b++;
            a++;
            lastposind++;
        } else {
            b = str2;
            a = a - lastposind + 1;
            lastposind = 0;
        }
    }
    if (*b == '\0') return 1;
    else return 0;
}

int similar(char *str1, char *str2, int n) {
    if (strlen(str1) > strlen(str2) + n) return 0;
    char *a = str1; // bbbbc // bbc
    char *b = str2;
    int lastposind = 0;
    int misscounter = 0;
    while ((*a != '\0') && (*b != '\0')) {
        if (*b == *a) {
            b++;
            a++;
            lastposind++;
        } else if (misscounter <= n) {
            a++;
            misscounter++;
            lastposind++;
            continue;
        } else {
            b = str2;
            a = a - lastposind + 1;
            lastposind = 0;
        }
        if (misscounter > n) return 0;
    }
    if (*b == '\0') return 1;
    else return 0;
}

void print_similar_words(char *str) {
    for (int i = 2; i < 8; ++i) {
        int wordsAmount = getLine(i);
        for (int j = 0; j < wordsAmount; j++) {
            getWord(i, j);
//            printf("%s\n", word);
            if (similar(word, str, 1)) {
                printf("%s\n", word);
            }
        }
    }
}

void printLines(char *str) {
    for (size_t i = 2; i < LINES; i++) {
        getLine((int) i);
        if (substring(line, str)) {
            printf("%s\n", line);
        }
    }
}

int main() {
    getText();
    getWord(0, 1);
    char program = word[0];
    char search[WORD];
    getWord(0, 0);
    strcpy(search, word);
    if (program == 'a') {
        printLines(search);
    }
    if (program == 'b') {
        print_similar_words(search);
    }
}


