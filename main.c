//sirul polonez
#include <stdio.h>
#include <string.h>
int val(char c);
void p(char c[]);
void transf2(char c[]);
int main() {
    char c[100],aux[2],u[100];
    aux[1]='\0';
    scanf("%s",&c);
    printf("Sirul polonez:\n");
    p(c);
    printf("\nStivele din sirul polonez:\n");
    strcpy(u,c);
    transf2(u);
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

void p(char c[])
{
    char s1[strlen(c)],s2[strlen(c)],aux[2];
    aux[1]='\0';s1[0]='\0';s2[0]='\0';
    char op[] = "+-*/";
    int retine[100],poz=0,q=-1;
    printf("C1    C2\n");
    for(int i=0;i<strlen(c);i++)
    {
        if (strchr(op, c[i]) != NULL) {
            if (strlen(s1) == 0)
            {
                aux[0] = c[i];
                strcpy(s1+strlen(s1), aux);
                //strcpy(s1,s1);
            }
            else
            if(s1[strlen(s1)-1]=='(')
            {
                aux[0] = c[i];
                strcpy(s1+strlen(s1), aux);
                q=q+1;
                retine[q]=strlen(s1)-1;
            } else
            if(s1[strlen(s1)-1]!=')') {
                if (val(c[i]) <= val(s1[strlen(s1) - 1])) {
                    while (val(c[i]) <= val(s1[strlen(s1) - 1]) && c[i] != '(' && s1[0]!='\0' && s1[strlen(s1)-1]!='(') {
                        printf("%s    %s%c\n",s2,s1,c[i]);
                        aux[0] = s1[strlen(s1) - 1];
                        strcpy(s2+strlen(s2), aux);
                        s1[strlen(s1)-1] ='\0';
                        poz=strlen(s1)-1;
                    }
                    aux[0] = c[i];
                    strcpy(s1+strlen(s1), aux);
                } else {
                    aux[0] = c[i];
                    strcat(s1, aux);
                    printf("%s    %s\n",s2,s1);
                }
            }
        } else
        if(c[i]=='(')
        {
            aux[0]=c[i];
            strcpy(s1+strlen(s1),aux);
        } else
        if(c[i]==')')
        {
            printf("%s    %s%c\n",s2,s1,c[i]);
            strcat(s2,strrev(s1+retine[q]));
            s1[retine[q]-1]='\0';
            q=q-1;
            poz=strlen(s1)-1;
        } else
        {
            aux[0] = c[i];
            strcpy(s2+strlen(s2), aux);
        }

    }
    printf("%s   %s\n",s2,s1);
    strcpy(s2+strlen(s2),strrev(s1));
    printf("\nSirul polonez: %s\n",s2);
    strcpy(c,s2);
}
void transf2(char c[]) {
    char op[4] = "+/-*", aux[2], s2[strlen(c)];
    aux[1] = '\0';
    s2[0] = '\0';
    int poz1 = 0;
    for (int i = 0; i < strlen(c); i++) {
        if (c[i]!='*' && c[i]!='/' && c[i]!='-' && c[i]!='+')
        {
            aux[0] = c[i];
            strcpy(s2 + strlen(s2), aux);
        }
        else
        {
            poz1 = 0;
            for (int o = 0; o < strlen(s2) - 1; o++)
                if ((s2[o]!='+' && s2[o]!='-' && s2[o]!='/' && s2[o]!='*') && (s2[o+1]!='*' && s2[o+1]!='+' && s2[o+1]!='/' && s2[o+1]!='-'))
                    poz1 = o;
            char u[strlen(s2)];
            printf("%s    %c\n",s2,c[i]);
            aux[0] = c[i];
            strcpy(u, s2 + poz1+1);
            strcpy(s2 + poz1+1, aux);
            strcpy(s2 + strlen(s2), u);
            //printf("%s\n",s2);
        }
    }
    printf("%s",s2);
}