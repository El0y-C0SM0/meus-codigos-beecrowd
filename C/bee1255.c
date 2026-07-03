#include <stdio.h>
#include <string.h>

void torna_minuscula(char *a) {
    if (*a >= 'A' && *a <= 'Z') *a += 32;
}

int e_letra(char a) {
    if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
        return 1;
    return 0;
}

int main() {
    int n;
    char s[200+1];

    scanf("%d", &n);

    while(n--) {
        scanf(" %[^\n]s", s);
        int t = strlen(s);
        int freq[26] = {0};
        int maior = 0;

        for (int i = 0; i < t; i++) { 
            if (!e_letra(s[i])) continue;
            torna_minuscula(&s[i]);

            freq[s[i] - 'a']++;
            maior = (maior < freq[s[i] - 'a']) ? freq[s[i] - 'a'] : maior;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] == maior)
                printf("%c", i + 'a');
        }
        printf("\n");
    }

    return 0;
}
