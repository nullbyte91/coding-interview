# include <stdio.h>
# include <string.h>

void 
shifS(char s[], char shiftS[], int N, int k){
    for (int i=0; i<N; i++){
        int idx = (i+k) % N;
        shiftS[idx] = s[i];
    }

    for (int i=0; i<N; i++){
        printf("%c", shiftS[i]);
    }
}

int 
main(int argc, char** argcv){
    char s[] = "hacker";
    char shiftS[6];
    int len = strlen(s);
    shifS(s, shiftS, len, 2);
    return 0;
}