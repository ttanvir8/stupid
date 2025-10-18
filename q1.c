#include <stdio.h>
#include <string.h>

int is_prime(int N);
int count_start(char str[]);
void is_Spell(char str[]);

int is_prime(int N) {
    int i;

    if (N <= 1) {
        return 0;
    }

    for (i = 2; i < N; i++) {
        if (N % i == 0) {
            return 0;
        }
    }

    return 1;
}

int count_start(char str[]) {
    int count = 0;
    int i;
    int len = strlen(str);

    if (str[0] == 'a') {
        count++;
    }

    for (i = 1; i < len; i++) {
        if (str[i-1] == ' ' && str[i] == 'a') {
            count++;
        }
    }

    return count;
}

void is_Spell(char str[]) {
    int word_count = count_start(str);
    int prime_check = is_prime(word_count);

    if (prime_check == 1) {
        printf("ABRA KADABRA - This is a SPELL\n");
    } else {
        printf("WHOOSHH - Try Again!!!\n");
    }
}

int main() {
    char str[200];
    gets(str);
    int a_word_count = count_start(str);
    printf("%d ", a_word_count);
    is_Spell(str);

    return 0;
}