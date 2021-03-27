//ordinea operatiilor
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void e(char c[]);
int val(char c);
int main() {
    char c[101];
    scanf("%s",&c);
    e(c);
}
int val(char c)
{
    if(c=='#')
        return 0;
    else if(c=='+' || c=='-')
        return 1;
    else if(c=='/' || c=='*')
        return 2;
}
void e(char c[]) {
    int t = 0, nr_v = 0, v[100];
    char d[100] ="#", s1[100], s2[100], aux[2];
    aux[1] = '\0';
    strcpy(d+strlen(d), c);
    strcpy(d+strlen(d), "#"); //adaugam la inceput si sfarsit #
    strcpy(c,d);
    char op[] = "#+-*/";
    s1[0]='\0';s2[0]='\0';
    printf("%s\n",c);
    for (int i = 0; i < strlen(c); i++) //parcurgem sirul si facem stivele
    {
        if (strchr(op, c[i]) != NULL) {
            if (strlen(s1) == 0) {
                v[t] = val(c[i]) + nr_v;
                aux[0] = c[i];
                strcpy(s1+strlen(s1), aux);
                //strcpy(s1,s1);
            } else {
                if ((val(c[i]) + nr_v) <= v[t]) {
                    while ((val(c[i]) + nr_v) <= v[t] && t>=0) {
                        printf("%s%c   %s\n",s1,c[i],s2);
                        for (int k = strlen(s2) - 1; k > 0; k--)
                            if (!strchr(op, s2[k]) && !strchr(op, s2[k - 1])) {
                                char u[100];
                                strcpy(u, s2 + k); // copiem de la pozitia k+1
                                aux[0] = s1[t];
                                strcpy(s2 + k, aux);//adaugam la primele k caractere din s2 operatorul
                                strcat(s2, u);//actualizam stiva
                                strcpy(s2,s2);
                                s1[t] = '\0';
                                break;
                            }
                        t--;
                    }
                    t++;
                    v[t] = val(c[i]) + nr_v;
                    aux[0] = c[i];
                    strcpy(s1+strlen(s1), aux);
                }
                else
                {
                    t++;
                    v[t] = val(c[i]) + nr_v;
                    aux[0] = c[i];
                    strcpy(s1+strlen(s1), aux);
                    strcpy(s1,s1);
                }
            }
        }
        else
        if(c[i]=='(')
            nr_v+=10;
        else
        if(c[i]==')')
            nr_v-=10;
        else
        {
            aux[0] = c[i];
            strcpy(s2+strlen(s2), aux);
        }
    }
}
