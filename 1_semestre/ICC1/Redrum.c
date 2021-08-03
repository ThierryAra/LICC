//THIERRY DE SOUZA ARAUJO
//12681094

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int palindrome (char *text, int string_size, int start_string);
char *receive_text ();

int main () {

    char *text = receive_text();

    int string_size = strlen (text), start_string = 0;
    int palindrome_type = palindrome (text, string_size - 1, start_string);

    if ((palindrome_type % 2) != 0){
        printf ("Nao eh um palindrome\n"); // It's not a palindrome.
    } else if (palindrome_type == 0){
        printf ("Palindromo direto\n"); // Direct palindrome. 
    } else {
        printf ("Palindromo indireto\n"); // Indirect palindrome.
    }

    free (text);
    return 0;
}

int palindrome (char *text, int end, int start){
    int palindrome_type = 0;
    if (start != end && start < end){
        // Ignore the others characters
        if (!isalnum(text[start]) && text[start] != ' ' && text[start] != '/')
            return (palindrome_type += palindrome(text, end, start + 1));
        if (!isalnum(text[end]) && text[end] != ' ' && text[end] != '/')
            return (palindrome_type += palindrome(text, end - 1, start));

        // Check the equality between characters: (a,a), (A,a), (a,A)
        if ((text[start] == text[end]) || (text[start] == text[end] - 32) || (text[start] - 32 == text[end])) {
            palindrome_type = palindrome_type + palindrome(text, end - 1, start + 1);
            return (palindrome_type);
          // If text[stat/end] is '/' or ' ', it checks for equality with the next character
        } else if ((text[start] != text[end])){ 
            if ((text[end] == '/' || text[end] == ' ')){
                return (palindrome_type += 2 + palindrome(text, end - 1, start));
            } else if (text[start] == '/' || text[start] == ' '){
                return (palindrome_type += 2 + palindrome(text, end, start + 1));
            } else // If some of the characters are not the same, it becomes odd and the recursion ends
                return (1);
        } 
    } return (0);
}

char *receive_text () {
    char input;
    char *string = NULL;
    int i = 1;

    input = getchar();
    while (input != '\n' && input != '$') {
        string = (char*)realloc(string, i * sizeof(char *));
        *(string + (i - 1)) = input;
        i++;
        input = getchar();
    }

    // Adding '\0' at the end of the string
    string = realloc(string, i * sizeof(char *));
    *(string + (i - 1)) = '\0';
    return string;
}