#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <winbgim.h>
#include <stdlib.h>
#include <cstring>
#include <fstream>

void Start()
{
    int i;
    setcolor(WHITE);
    rectangle(200, 40, 1200, 130);
    settextstyle(9, 0, 5);
    outtextxy(700-textwidth("Derivare Formala")/2, 60, "Derivare Formala");
    rectangle(200, 180, 1200, 620);
    settextstyle(9, 0, 3);
    outtextxy(220, 200, "Introduceti functia:");
    rectangle(200, 650, 375, 700);
    settextstyle(9, 0, 1);
    outtextxy(210, 665, "Cititi din fisier");
    rectangle(475, 650, 650, 700);
    outtextxy(485, 665, "Salvati in fisier");
    rectangle(750, 650, 925, 700);
    outtextxy(840-textwidth("Info")/2, 665, "Info");
    rectangle(1025, 650, 1200, 700);
    outtextxy(1115-textwidth("Despre")/2, 665, "Despre");
}

bool click()
{
    int x, y;
    getmouseclick(WM_LBUTTONDOWN, x, y);
    if(x>200 &&  x<1200 && y>180 && y<620)
        return 1;
        else return 0;
}

void CitesteSir(int x, int y, char S[256] )
{
    char Enter = 13;
    char BackSpace = 8;
    char Escape = 27;
    char s2[2];
    s2[1]='\0';
    char MultimeDeCaractereAcceptabile[250]="0123456789abcdefghijklmnopqrstuvwxyz~!`@#$%+-^&*/\\()_=[],;.?<>:;{} ";
    char S_initial[256];
    char tasta=NULL;
    char S_[256];
    strcpy(S_initial,S);
    settextstyle(9,0,3);
    setcolor(WHITE);
    settextjustify(0,0);
    strcpy(S_,S);
    strcat(S_,"_");
    setcolor(BLACK);
    outtextxy(x,y,S_);
    s2[0]=tasta;
    strcat(S,s2);
    strcpy(S_,S);
    strcat(S_,"_");
    setcolor(WHITE);
    outtextxy(x,y,S_);

    do
    {
        tasta=getch();
        if (tasta==0)
        {
            tasta=getch();
            Beep(1000,500);
        }
        else if (strchr(MultimeDeCaractereAcceptabile, tasta))
        {
            strcpy(S_,S);
            strcat(S_,"_");
            setcolor(BLACK);
            outtextxy(x,y,S_);
            s2[0]=tasta;
            strcat(S,s2);
            strcpy(S_,S);
            strcat(S_,"_");
            setcolor(WHITE);
            outtextxy(x,y,S_);
        }
        if (tasta==BackSpace)
            if (!(strcmp(S,""))) Beep(500,100);
            else
            {
                setcolor(BLACK);
                outtextxy(x,y,S_);
                setcolor(WHITE);
                S[strlen(S)-1]='\0';
                strcpy(S_,S);
                strcat(S_,"_") ;
                outtextxy(x,y,S_);
                Beep(200,20);
            }
        else if (tasta!=Enter && tasta!=Escape)
        {
            Beep(200,20);
        }
    }
    while (tasta!=Enter && tasta!=Escape);
    if (tasta == Escape) strcpy(S,S_initial);
    setcolor(BLACK);
    outtextxy(x,y,S_);
    setcolor(WHITE);
    outtextxy(x,y,S);
}

void eroare(int x)
{
    settextstyle(9,0,2);
    setcolor(WHITE);
    switch(x)
    {
        case 1: outtextxy(220, 275, "Eroare: numarul de paranteze inchise nu este egal cu numarul de paranteze");
                outtextxy(220, 295, "deschise"); break;
        case 2: outtextxy(220, 275, "Eroare: numarul de paranteze deschise e mai mic decat cel al parantezelor");
                outtextxy(220, 295, "inchise"); break;
        case 3: outtextxy(220, 275, "Eroare: dupa operator nu urmeaza o variabila, o functie, o constanta sau");
                outtextxy(220, 295, "o paranteza deschisa"); break;
        case 4: outtextxy(220, 275, "Eroare: dupa o variabila nu urmeaza un operator sau o paranteza inchisa"); break;
        case 5: outtextxy(220, 275, "Eroare: dupa o constanta nu urmeaza un operator, o constanta sau");
                outtextxy(220, 295, "o paranteza inchisa"); break;
        case 6: outtextxy(220, 275, "Eroare: dupa un nume de functie nu urmeaza o paranteza deschisa"); break;
        case 7: outtextxy(220, 275, "Eroare: dupa paranteza deschisa nu urmeaza o alta paranteza deschisa,");
                outtextxy(220, 295, "un nume de functie, o variabila, o constanta sau chiar operatorul unar + sau -"); break;
        case 8: outtextxy(220, 275, "Eroare: dupa paranteza inchisa nu urmeaza o alta paranteza inchisa sau");
                outtextxy(220, 295, "un operator"); break;
    }
}

void stergeroare(int x)
{
    settextstyle(9,0,2);
    setcolor(BLACK);
    switch(x)
    {
        case 1: outtextxy(220, 275, "Eroare: numarul de paranteze inchise nu este egal cu numarul de paranteze");
                outtextxy(220, 295, "deschise"); break;
        case 2: outtextxy(220, 275, "Eroare: numarul de paranteze deschise e mai mic decat cel al parantezelor");
                outtextxy(220, 295, "inchise"); break;
        case 3: outtextxy(220, 275, "Eroare: dupa operator nu urmeaza o variabila, o functie, o constanta sau");
                outtextxy(220, 295, "o paranteza deschisa"); break;
        case 4: outtextxy(220, 275, "Eroare: dupa o variabila nu urmeaza un operator sau o paranteza inchisa"); break;
        case 5: outtextxy(220, 275, "Eroare: dupa o constanta nu urmeaza un operator, o constanta sau");
                outtextxy(220, 295, "o paranteza inchisa"); break;
        case 6: outtextxy(220, 275, "Eroare: dupa un nume de functie nu urmeaza o paranteza deschisa"); break;
        case 7: outtextxy(220, 275, "Eroare: dupa paranteza deschisa nu urmeaza o alta paranteza deschisa,");
                outtextxy(220, 295, "un nume de functie, o variabila, o constanta sau chiar operatorul unar + sau -"); break;
        case 8: outtextxy(220, 275, "Eroare: dupa paranteza inchisa nu urmeaza o alta paranteza inchisa sau");
                outtextxy(220, 295, "un operator"); break;
    }
}

struct arb
{
	char info[256];
	arb* stg;
	arb* dr;
};

struct arbore
{
	arb *rad;
}A1, A2;

void initializareArb1(arb*& rad)
{
	A1.rad = NULL;
}

void initializareArb2(arb*& rad)
{
	A2.rad = NULL;
}

struct nod
{
    char info;
    nod *urm;
};

struct stiva
{
    nod *varf;
    int nrElem;
};

bool esteVida(stiva S)
{
    if(S.nrElem==0)
        return 1;
    else
        return 0;
}

void initializare(stiva &S)
{
    S.varf=NULL;
    S.nrElem=0;
};

void pop(stiva &S)
{
    if (!esteVida(S))
    {
        nod* nou;
        nou=S.varf;
        S.varf=S.varf->urm;
        delete nou;
        S.nrElem--;
		}
}

void push(stiva &S, char s)
{
    nod * nou=new nod;
    if (esteVida(S))
    {
        S.nrElem=1;
        S.varf=nou;
        S.varf->info=s;
        S.varf->urm=NULL;
    }
    else
    {
        S.nrElem++;
        nou->info=s;
        nou->urm=S.varf;
        S.varf=nou;
    }
}

void strrev(char s[256])
{
    char c[256];
    int i, nr=0;
    for(i=strlen(s)-1;i>=0; i--)
    {
        c[nr]=s[i];
        nr++;
    }
    c[nr]=NULL;
    strcpy(s,c);
}

int priorit(char s)
{
    if(s=='(' || s==')') return 0;
        else if(s=='+' || s=='-') return 1;
                else if(s=='*' || s=='*') return 2;
                        else if(s=='^') return 3;
                                else if(s=='x') return 4;
                                        else return 5;
}

void Vectorizare(char s[], char cuv[256][256], int &n)
{
    int i,m;
    n=0;
    stiva S;
    initializare(S);

    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='x')
        {
            strcpy(cuv[n], "x");
            n++;
        }
        if(s[i]>='0' && s[i]<='9')
        {
            m=0;
            while(s[i]>='0' && s[i]<='9')
            {
                cuv[n][m]=s[i];
                m++;
                i++;
            }
            n++;
            i=i-1;
        }
        if(s[i]=='(') push(S,s[i]);
        if(s[i]==')')
        {
            while(S.varf->info!='(')
            {
                if(S.varf->info=='s') strcpy(cuv[n], "sin");
                else
                    if(S.varf->info=='c') strcpy(cuv[n], "cos");
                    else
                        if(S.varf->info=='t') strcpy(cuv[n], "tg");
                        else
                            if(S.varf->info=='g') strcpy(cuv[n], "ctg");
                            else
                                if(S.varf->info=='r') strcpy(cuv[n], "sqrt");
                                else
                                    if(S.varf->info=='l') strcpy(cuv[n], "ln");
                                    else cuv[n][0]=S.varf->info;
                n++;
                pop(S);
            }
            pop(S);
        }
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^' || (s[i]=='s' && s[i+1]=='i') || (s[i]=='c' && s[i+1]=='o') || (s[i]=='t' && s[i-1]!='c' && s[i-1]!='r') || (s[i]=='c' && s[i+1]=='t') || (s[i]=='s' && s[i+1]=='q') || s[i]=='l' || s[i]=='e')
        {
            while(S.varf != NULL && priorit(S.varf->info)>= priorit(s[i]))
            {
                if(S.varf->info=='s') strcpy(cuv[n], "sin");
                else
                    if(S.varf->info=='c') strcpy(cuv[n], "cos");
                    else
                        if(S.varf->info=='t') strcpy(cuv[n], "tg");
                        else
                            if(S.varf->info=='g') strcpy(cuv[n], "ctg");
                            else
                                if(S.varf->info=='r') strcpy(cuv[n], "sqrt");
                                else
                                    if(S.varf->info=='l') strcpy(cuv[n], "ln");
                                    else cuv[n][0]=S.varf->info;
                n++;
                pop(S);
            }
            if(s[i]=='s' && s[i+1]=='i') push(S, s[i]);
            else
                if(s[i]=='c' && s[i+1]=='o') push(S, s[i]);
                else
                    if(s[i]=='c' && s[i+1]=='t') push(S, s[i+2]);
                    else
                        if(s[i]=='s' && s[i+1]=='q') push(S, s[i+2]);
                        else push(S, s[i]);
        }
    }

    while(esteVida(S)==0)
    {
        if(S.varf->info=='s') strcpy(cuv[n], "sin");
                else
                    if(S.varf->info=='c') strcpy(cuv[n], "cos");
                    else
                        if(S.varf->info=='t') strcpy(cuv[n], "tg");
                        else
                            if(S.varf->info=='g') strcpy(cuv[n], "ctg");
                            else
                                if(S.varf->info=='r') strcpy(cuv[n], "sqrt");
                                else
                                    if(S.varf->info=='l') strcpy(cuv[n], "ln");
                                    else
                                    cuv[n][0]=S.varf->info;
        n++;
        pop(S);
    }
}

void Arborizare(char cuv[256][256], arb* &rad, int &n)
{
    arb* p= new arb;
    char cuvantActual[256];
    cuvantActual[0]=NULL;
    strcpy(cuvantActual, cuv[n]);
    if(cuv[n][0]=='x' || cuv[n][0]>='0' && cuv[n][0]<='9' || cuv[n][0]=='e')
    {
        strcpy(p->info, cuv[n]);
        n--;
        p->stg=NULL;
        p->dr=NULL;
        rad=p;
        return;
    }
    strcpy(p->info, cuv[n]);
    n--;
    Arborizare(cuv, p->dr, n);
    if(strcmp(cuvantActual, "sin")==0 || strcmp(cuvantActual, "cos")==0 || strcmp(cuvantActual, "tg")==0 || strcmp(cuvantActual, "ctg")==0 || strcmp(cuvantActual, "sqrt")==0 || strcmp(cuvantActual, "ln")==0)
    {
        p->stg=NULL;
        rad=p;
        return;
    }
    Arborizare(cuv, p->stg,n);
    rad=p;
}

void copie(arb* p1, arb *&p2)
{
    if(p1==NULL)
    {
        p2=NULL;
        return;
    }
    p2=new arb;
    strcpy(p2->info, p1->info);
    copie(p1->stg, p2->stg);
    copie(p1->dr, p2->dr);
}

void Derivare(arb *p1, arb *&p2)
{
    if(p1==NULL) return;
    if(p1->info[0]>='0' && p1->info[0]<='9')
    {
        arb* q=new arb;
        q->info[0]='0';
        q->info[1]=NULL;
        q->stg=NULL;
        q->dr=NULL;
        p2=q;
    }
    if(p1->info[0]=='x')
    {
        arb* q=new arb;
        q->info[0]='1';
        q->info[1]=NULL;
        q->stg=NULL;
        q->dr=NULL;
        p2=q;
    }
    if(p1->info[0]=='+' || p1->info[0]=='-')
    {
        arb* q=new arb;
        q->info[0]=p1->info[0];
        q->info[1]=NULL;
        Derivare(p1->stg, q->stg);
        Derivare(p1->dr, q->dr);
        p2=q;
    }
    if(p1->info[0]=='*')
    {
        arb* q1=new arb;
        q1->info[0]='+';
        q1->info[1]=NULL;
        arb* q2=new arb;
        q2->info[0]='*';
        q2->info[1]=NULL;
        arb* q3=new arb;
        q3->info[0]='*';
        q3->info[1]=NULL;
        Derivare(p1->stg, q2->stg);
        copie(p1->dr, q2->dr); //q2->dr=p1->dr;
        copie(p1->stg,q3->stg); //q3->stg=p1->stg;
        Derivare(p1->dr, q3->dr);
        q1->stg=q2;
        q1->dr=q3;
        p2=q1;
    }
    if(p1->info[0]=='/')
    {
        arb* q1= new arb;
        q1->info[0]='/';
        q1->info[1]=NULL;
        arb* q2= new arb;
        q2->info[0]='-';
        q2->info[1]=NULL;
        arb* q3= new arb;
        q3->info[0]='^';
        q3->info[1]=NULL;
        arb* q4= new arb;
        q4->info[0]='*';
        q4->info[1]=NULL;
        arb* q5= new arb;
        q5->info[0]='*';
        q5->info[1]=NULL;
        arb* q6= new arb;
        q6->info[0]='2';
        q6->info[1]=NULL;
        q1->stg=q2;
        q1->dr=q3;
        q2->stg=q4;
        q2->dr=q5;
        copie(p1->dr,q3->stg);
        q3->dr=q6;
        Derivare(p1->stg, q4->stg);
        copie(p1->dr,q4->dr); //q4->dr=p1->dr;
        copie(p1->stg,q5->stg); //q5->stg=p1->stg;
        Derivare(p1->dr, q5->dr);
        q6->stg=NULL;
        q6->dr=NULL;
        p2=q1;
    }
    if(p1->info[0]=='^' && p1->stg->info[0]!='e')
    {
        arb* q1=new arb;
        q1->info[0]='*';
        q1->info[1]=NULL;
        arb* q2=new arb;
        q2->info[0]='*';
        q2->info[1]=NULL;
        arb* q3=new arb;
        q3->info[0]='^';
        q3->info[1]=NULL;
        arb* q4=new arb;
        q4->info[0]='-';
        q4->info[1]=NULL;
        arb* q5=new arb;
        q5->info[0]='1';
        q5->info[1]=NULL;
        q1->stg=q2;
        Derivare(p1->stg, q1->dr);
        copie(p1->dr, q2->stg); //q2->stg=p1->dr;
        q2->dr=q3;
        copie(p1->stg,q3->stg); //q3->stg=p1->stg;
        q3->dr=q4;
        copie(p1->dr, q4->stg); //q4->stg=p1->dr;
        q4->dr=q5;
        q5->stg=NULL;
        q5->dr=NULL;
        p2=q1;
    }
    if(p1->info[0]=='^' && p1->stg->info[0]=='e')
    {
        arb* q1=new arb;
        q1->info[0]='*';
        q1->info[1]=NULL;
        arb* q2=new arb;
        q2->info[0]='^';
        q2->info[1]=NULL;
        q1->stg=q2;
        Derivare(p1->dr, q1->dr);
        copie(p1->stg, q2->stg); //q2->stg=p1->stg;
        copie(p1->dr,q2->dr); //q2->dr=p1->dr;
        p2=q1;
    }
    if(strcmp(p1->info, "sqrt")==0)
    {
        arb* q1=new arb;
        q1->info[0]='/';
        q1->info[1]=NULL;
        arb* q2=new arb;
        q2->info[0]='*';
        q2->info[1]=NULL;
        arb* q3=new arb;
        q3->info[0]='2';
        q3->info[1]=NULL;
        arb* q4=new arb;
        strcpy(q4->info, p1->info);
        Derivare(p1->dr, q1->stg);
        q1->dr=q2;
        q2->stg=q3;
        q2->dr=q4;
        q3->stg=NULL;
        q3->dr=NULL;
        q4->stg=NULL;
        copie(p1->dr, q4->dr); //q4->dr=p1->dr;
        p2=q1;
    }
    if(strcmp(p1->info, "ln")==0)
    {
        arb* q1=new arb;
        q1->info[0]='/';
        q1->info[1]=NULL;
        Derivare(p1->dr, q1->stg);
        copie(p1->dr, q1->dr); //q1->dr=p1->dr;
        p2=q1;
    }
    if(strcmp(p1->info, "sin")==0)
    {
        arb* q1=new arb;
        q1->info[0]='*';
        q1->info[1]=NULL;
        arb* q2=new arb;
        strcpy(q2->info, "cos");
        q1->stg=q2;
        Derivare(p1->dr, q1->dr);
        q2->stg=NULL;
        copie(p1->dr,q2->dr); //q2->dr=p1->dr;
        p2=q1;
    }
    if(strcmp(p1->info, "cos")==0)
    {
        arb* q1=new arb;
        q1->info[0]='*';
        q1->info[1]=NULL;
        arb* q2=new arb;
        q2->info[0]='-';
        q2->info[1]=NULL;
        arb* q3=new arb;
        q3->info[0]='0';
        q3->info[1]=NULL;
        arb* q4=new arb;
        strcpy(q4->info, "sin");
        q1->stg=q2;
        Derivare(p1->dr, q1->dr);
        q2->stg=q3;
        q2->dr=q4;
        q3->stg=NULL;
        q3->dr=NULL;
        q4->stg=NULL;
        copie(p1->dr,q4->dr); //q4->dr=p1->dr;
        p2=q1;
    }
    if(strcmp(p1->info, "tg")==0)
    {
        arb* q1=new arb;
        q1->info[0]='/';
        q1->info[1]=NULL;
        arb* q2=new arb;
        q2->info[0]='^';
        q2->info[1]=NULL;
        arb* q3=new arb;
        strcpy(q3->info, "cos");
        arb* q4=new arb;
        q4->info[0]='2';
        q4->info[1]=NULL;
        Derivare(p1->dr, q1->stg);
        q1->dr=q2;
        q2->stg=q3;
        q2->dr=q4;
        q3->stg=NULL;
        copie(p1->dr, q3->dr); //q3->dr=p1->dr;
        q4->stg=NULL;
        q4->dr=NULL;
        p2=q1;
    }
    if(strcmp(p1->info, "ctg")==0)
    {
        arb* q1=new arb;
        q1->info[0]='-';
        q1->info[1]=NULL;
        arb* q2=new arb;
        q2->info[0]='0';
        q2->info[1]=NULL;
        arb* q3=new arb;
        q3->info[0]='/';
        q3->info[1]=NULL;
        arb* q4=new arb;
        q4->info[0]='^';
        q4->info[1]=NULL;
        arb* q5=new arb;
        strcpy(q5->info,"sin");
        arb* q6=new arb;
        q6->info[0]='2';
        q6->info[1]=NULL;
        q1->stg=q2;
        q1->dr=q3;
        q2->stg=NULL;
        q2->dr=NULL;
        Derivare(p1->dr, q3->stg);
        q3->dr=q4;
        q4->stg=q5;
        q4->dr=q6;
        q5->stg=NULL;
        copie(p1->dr, q5->dr); //q5->dr=p1->dr;
        q6->stg=NULL;
        q6->dr=NULL;
        p2=q1;
    }
}

void sterge(arb *&p)
{
    if(p==NULL) return;
    sterge(p->stg);
    sterge(p->dr);
    delete p;
}

bool esteNumar(arb* p)
{
    if(p->info[0]>='1' && p->info[0]<='9')
        return 1;
    else
        return 0;
}

void Rafinare(arb *&p)
{
    arb *aux;
    if(p==NULL) return;
        else
        {
            Rafinare(p->stg);
            Rafinare(p->dr);
        }
    if(p->info[0]=='+')
    {
        if(p->stg->info[0]=='0')
        {
            sterge(p->stg);
            aux=p->dr;
            delete p;
            p=aux;;
            return;
        }
        if(p->dr->info[0]=='0')
        {
            sterge(p->dr);
            aux=p->stg;
            delete p;
            p=aux;
            return;
        }
        if(esteNumar(p->stg)!=0 && esteNumar(p->dr)!=0)
        {
            int nr1=0, nr2=0,i=0, nr=0, lg=0;
            while(p->stg->info[i]!=NULL)
            {
                nr1=nr1*10+(p->stg->info[i]-'0');
                i++;
            }
            i=0;
            while(p->dr->info[i]!=NULL)
            {
                nr2=nr2*10+(p->dr->info[i]-'0');
                i++;
            }
            nr=nr1+nr2;
            while(nr)
            {
                p->info[lg++]=nr%10+'0';
                nr=nr/10;
            }
            p->info[lg]=NULL;
            strrev(p->info);
            sterge(p->stg);
            sterge(p->dr);
            p->stg=NULL;
            p->dr=NULL;
            return;
        }
    }
    if(p->info[0]=='-')
    {
        if(p->stg->info[0]=='0')
        {
            sterge(p->stg);
            p->stg=NULL;
            return;
        }
        if(p->dr->info[0]=='0')
        {
            sterge(p->dr);
            aux=p->stg;
            delete p;
            p=aux;
            return;
        }
        if(esteNumar(p->stg)!=0 && esteNumar(p->dr)!=0)
        {
            int nr1=0, nr2=0,i=0, nr=0, lg=0;
            while(p->stg->info[i]!=NULL)
            {
                nr1=nr1*10+(p->stg->info[i]-'0');
                i++;
            }
            i=0;
            while(p->dr->info[i]!=NULL)
            {
                nr2=nr2*10+(p->dr->info[i]-'0');
                i++;
            }
            nr=nr1-nr2;
            if(nr>=0)
            {
                while(nr)
                {
                    p->info[lg++]=nr%10+'0';
                    nr=nr/10;
                }
                p->info[lg]=NULL;
                strrev(p->info);
                sterge(p->stg);
                sterge(p->dr);
                p->stg=NULL;
                p->dr=NULL;
                return;
            }
            else
            {
                nr=nr*(-1);
                sterge(p->stg);
                while(nr)
                {
                    p->dr->info[lg++]=nr%10+'0';
                    nr=nr/10;
                }
                p->info[lg]=NULL;
                strrev(p->dr->info);
                p->stg=NULL;
                return;
            }
        }
    }
    if(p->info[0]=='*')
    {
        if(p->stg->info[0]=='0' || p->dr->info[0]=='0')
        {
            sterge(p->stg);
            sterge(p->dr);
            p->info[0]='0';
            p->info[1]=NULL;
            p->stg=NULL;
            p->dr=NULL;
            return;
        }
        if(esteNumar(p->stg)!=0 && esteNumar(p->dr)!=0)
        {
            int nr1=0, nr2=0,i=0, nr=0, lg=0;
            while(p->stg->info[i]!=NULL)
            {
                nr1=nr1*10+(p->stg->info[i]-'0');
                i++;
            }
            i=0;
            while(p->dr->info[i]!=NULL)
            {
                nr2=nr2*10+(p->dr->info[i]-'0');
                i++;
            }
            nr=nr1*nr2;
            while(nr)
            {
                p->info[lg++]=nr%10+'0';
                nr=nr/10;
            }
            p->info[lg]=NULL;
            strrev(p->info);
            sterge(p->stg);
            sterge(p->dr);
            p->stg=NULL;
            p->dr=NULL;
            return;
        }
        if(strcmp(p->stg->info,"1")==0)
        {
            sterge(p->stg);
            aux=p->dr;
            delete p;
            p=aux;
            return;
        }
        if(strcmp(p->dr->info,"1")==0)
        {
            sterge(p->dr);
            aux = p->stg;
            delete p;
            p=aux;
            return;
        }
    }
    if(p->info[0]=='/')
    {
        if(p->stg->info[0]=='0')
        {
            sterge(p->stg);
            sterge(p->dr);
            p->info[0]='0';
            p->info[1]=NULL;
            p->stg=NULL;
            p->dr=NULL;
            return;
        }
        if(strcmp(p->dr->info,"1")==0)
        {
            sterge(p->dr);
            aux=p->stg;
            delete p;
            p=aux;
            return;
        }
    }
    if(p->info[0]=='^')
    {
        if(strcmp(p->stg->info,"1")==0)
        {
            sterge(p->dr);
            aux=p->stg;
            delete p;
            p=aux;
            return;
        }
        if(strcmp(p->dr->info,"1")==0)
        {
            sterge(p->dr);
            aux=p->stg;
            delete p;
            p=aux;
            return;
        }
        if(p->dr->info[0]=='0')
        {
            sterge(p->stg);
            sterge(p->dr);
            p->info[0]='1';
            p->info[1]=NULL;
            p->stg=NULL;
            p->dr=NULL;
            return;
        }
        if(p->stg->info[0]=='0')
        {
            sterge(p->stg);
            sterge(p->dr);
            p->info[0]='0';
            p->info[1]=NULL;
            p->stg=NULL;
            p->dr=NULL;
            return;
        }
    }
}

void SRD(arb *p, char s[256])
{
    if(p==NULL) return;
    if(p->stg!=NULL && priorit(p->info[0])> priorit(p->stg->info[0]))
        strcat(s, "(");
    SRD(p->stg, s);
    if(p->stg!=NULL && priorit(p->info[0])> priorit(p->stg->info[0]))
        strcat(s,")");
    strcat(s,p->info);
    if(p->dr!=NULL && priorit(p->info[0])> priorit(p->dr->info[0]))
        strcat(s,"(");
    SRD(p->dr,s);
    if(p->dr!=NULL && priorit(p->info[0])> priorit(p->dr->info[0]))
        strcat(s,")");
}

char s[256], v[256][256], d[256];

int main()
{

    initwindow(1400,800);
    Start();
    char var[100]="x", cons[12]="0123456789e" , op[6]="+-/*^";
    int i, nrinchise=0, nrdeschise=0, ok=1, nr=0, nre=0, ap=1, ap1=1;
    s[0]=NULL;
    while (true)
    {
        if (click())
        {
            if(nre!=0) stergeroare(nre);
            else
            {
                setcolor(BLACK);
                outtextxy(220, 290, "Derivata functiei:");
                outtextxy(250, 320, d);
            }
            CitesteSir(250,250,s);
            for(i=0; i<strlen(s); i++)
            {
                if(s[i]=='(')
                {
                    nrdeschise++;
                    if(nrinchise> nrdeschise)
                    {
                        ok=0;
                        nre=2;
                        eroare(2);
                    }
                    if(s[i+1]!='(' && s[i+1]!='+' && s[i+1]!='-' && strchr(var,s[i+1])==0 && strchr(cons, s[i+1])==0)
                        if(s[i+1]!='c' && s[i+2]!='t' && s[i+3]!='g')
                            if(s[i+1]!='t' && s[i+2]!='g')
                                if(s[i+1]!='c' && s[i+2]!='o' && s[i+3]!='s')
                                    if(s[i+1]!='s' && s[i+2]!='i' && s[i+3]!='n')
                                        if(s[i+1]!='l' && s[i+2]!='n')
                                        {
                                            ok=0;
                                            nre=7;
                                            eroare(7);
                                            break;
                                        }
                }
                else if(s[i]==')')
                {
                    nrinchise++;
                    if(s[i+1]!=')' && strchr(op,s[i+1])==0)
                    {
                        ok=0;
                        nre=8;
                        eroare(8);
                        break;
                    }
                }
                if(strchr(op,s[i])!=0)
                    if(strchr(var,s[i+1])==0 && strchr(cons,s[i+1])==0 && s[i+1]!='(')
                        if(s[i+1]!='c' && s[i+2]!='t' && s[i+3]!='g')
                            if(s[i+1]!='t' && s[i+2]!='g')
                                if(s[i+1]!='c' && s[i+2]!='o' && s[i+3]!='s')
                                    if(s[i+1]!='s' && s[i+2]!='i' && s[i+3]!='n')
                                        if(s[i+1]!='l' && s[i+2]!='n')
                                        {
                                            ok=0;
                                            nre=3;
                                            eroare(3);
                                            break;
                                        }
                if(strchr(var,s[i])!=0)
                    if(strchr(op,s[i+1])==0 && s[i+1]!=')')
                    {
                        ok=0;
                        nre=4;
                        eroare(4);
                        break;
                    }
                if(strchr(cons,s[i])!=0)
                    if(strchr(op, s[i+1])==0 && s[i+1]!=')' && strchr(cons,s[i+1])==0)
                    {
                        ok=0;
                        nre=5;
                        eroare(5);
                        break;
                    }
                if( (s[i]=='s' && s[i+1]=='i' && s[i+2]=='n') || (s[i]=='c' && s[i+1]=='o' && s[i+2]=='s') ||  (s[i]=='c' && s[i+1]=='t' && s[i+2]=='g'))
                    if(s[i+3]!='(')
                    {
                        ok=0;
                        nre=6;
                        eroare(6);
                        break;
                    }
                if(s[i]=='l' && s[i+1]=='n' || (s[i]=='t' && s[i+1]=='g'))
                    if(s[i+2]!='(')
                    {
                        ok=0;
                        nre=6;
                        eroare(6);
                        break;
                    }
            }
            if(nrinchise!=nrdeschise && i>=strlen(s))
            {
                ok=0;
                nre=1;
                eroare(1);
            }
            if(ok==1)
            {
                int nr;
                d[0]=NULL;
                Vectorizare(s,v,nr);
                nr--;
                initializareArb1(A1.rad);
                Arborizare(v, A1.rad, nr);
                initializareArb2(A2.rad);
                Derivare(A1.rad, A2.rad);
                Rafinare(A2.rad);
                SRD(A2.rad, d);
                setcolor(WHITE);
                outtextxy(220, 290, "Derivata functiei:");
                outtextxy(250, 320, d);
            }
        }
        int m,n;
        getmouseclick(WM_LBUTTONDOWN, m,n);
        if(m>200 && n>650 && m<375 && n<700)
        {
            FILE *fis;
            if ((fis = fopen(".\\citire.txt","r")) == NULL)
            {
                printf("Error! opening file");
            }
            fgets(s, 256, fis);
            settextstyle(9,0,3);
            outtextxy(250,225,s);
            for(i=0; i<strlen(s); i++)
            {
                if(s[i]=='(')
                {
                    nrdeschise++;
                    if(nrinchise> nrdeschise)
                    {
                        ok=0;
                        nre=2;
                        eroare(2);
                    }
                    if(s[i+1]!='(' && s[i+1]!='+' && s[i+1]!='-' && strchr(var,s[i+1])==0 && strchr(cons, s[i+1])==0)
                        if(s[i+1]!='c' && s[i+2]!='t' && s[i+3]!='g')
                            if(s[i+1]!='t' && s[i+2]!='g')
                                if(s[i+1]!='c' && s[i+2]!='o' && s[i+3]!='s')
                                    if(s[i+1]!='s' && s[i+2]!='i' && s[i+3]!='n')
                                        if(s[i+1]!='l' && s[i+2]!='n')
                                        {
                                            ok=0;
                                            nre=7;
                                            eroare(7);
                                            break;
                                        }
                }
                else if(s[i]==')')
                {
                    nrinchise++;
                    if(s[i+1]!=')' && strchr(op,s[i+1])==0)
                    {
                        ok=0;
                        nre=8;
                        eroare(8);
                        break;
                    }
                }
                if(strchr(op,s[i])!=0)
                    if(strchr(var,s[i+1])==0 && strchr(cons,s[i+1])==0 && s[i+1]!='(')
                        if(s[i+1]!='c' && s[i+2]!='t' && s[i+3]!='g')
                            if(s[i+1]!='t' && s[i+2]!='g')
                                if(s[i+1]!='c' && s[i+2]!='o' && s[i+3]!='s')
                                    if(s[i+1]!='s' && s[i+2]!='i' && s[i+3]!='n')
                                        if(s[i+1]!='l' && s[i+2]!='n')
                                        {
                                            ok=0;
                                            nre=3;
                                            eroare(3);
                                            break;
                                        }
                if(strchr(var,s[i])!=0)
                    if(strchr(op,s[i+1])==0 && s[i+1]!=')')
                    {
                        ok=0;
                        nre=4;
                        eroare(4);
                        break;
                    }
                if(strchr(cons,s[i])!=0)
                    if(strchr(op, s[i+1])==0 && s[i+1]!=')' && strchr(cons,s[i+1])==0)
                    {
                        ok=0;
                        nre=5;
                        eroare(5);
                        break;
                    }
                if( (s[i]=='s' && s[i+1]=='i' && s[i+2]=='n') || (s[i]=='c' && s[i+1]=='o' && s[i+2]=='s') ||  (s[i]=='c' && s[i+1]=='t' && s[i+2]=='g'))
                    if(s[i+3]!='(')
                    {
                        ok=0;
                        nre=6;
                        eroare(6);
                        break;
                    }
                if(s[i]=='l' && s[i+1]=='n' || (s[i]=='t' && s[i+1]=='g'))
                    if(s[i+2]!='(')
                    {
                        ok=0;
                        nre=6;
                        eroare(6);
                        break;
                    }
            }
            if(nrinchise!=nrdeschise && i>=strlen(s))
            {
                ok=0;
                nre=1;
                eroare(1);
            }
            if(ok==1)
            {
                int nr;
                d[0]=NULL;
                Vectorizare(s,v,nr);
                nr--;
                initializareArb1(A1.rad);
                Arborizare(v, A1.rad, nr);
                initializareArb2(A2.rad);
                Derivare(A1.rad, A2.rad);
                Rafinare(A2.rad);
                SRD(A2.rad, d);
                setcolor(WHITE);
                outtextxy(220, 290, "Derivata functiei:");
                outtextxy(250, 320, d);
            }
        }
        if(m>475 && n>650 && m<650 && n<700)
            {
                FILE *fis1;
                fis1=fopen(".\\salvare1.txt","w");
                if(fis1==NULL)
                {
                    printf("Error!");
                }
                fputs("Introduceti functia:\n", fis1);
                fputs(s, fis1);
                fputs("\nDerivata functiei:\n", fis1);
                fputs(d,fis1);
                fclose(fis1);
            }
        if(m>750 && n>650 && m<925 && n<700)
        {
            if(ap%2!=0)
            {
                setcolor(WHITE);
                ap++;
                settextstyle(9, 0, 2);
                outtextxy(200, 740,"Proiect realizat de Balteanu Sara si Blindu Andrada");
                outtextxy(200, 760,"Profesori coordonatori: dr. Patrut Bogdan, colab. Gorea Claudiu");
            }
            else
            {
                setcolor(BLACK);
                ap++;
                settextstyle(9, 0, 2);
                outtextxy(200, 740,"Proiect realizat de Balteanu Sara si Blindu Andrada");
                outtextxy(200, 760,"Profesori coordonatori: dr. Patrut Bogdan, colab. Gorea Claudiu");
            };
        }
        if(m>1025 && n>650 && m<1200 && n<700)
        {
            if(ap1%2!=0)
            {
                setcolor(WHITE);
                ap1++;
                settextstyle(9, 0, 2);
                outtextxy(200, 740,"La scrierea functiei se folosesc numere naturale, variabila 'x' si operatiile");
                outtextxy(200, 760,"+,-,*,/,^, sqrt(), ln(), e, sin(), cos(), tg(), ctg()");
            }
            else
            {
                setcolor(BLACK);
                ap1++;
                settextstyle(9, 0, 2);
                outtextxy(200, 740,"La scrierea functiei se folosesc numere naturale, variabila 'x' si operatiile");
                outtextxy(200, 760,"+,-,*,/,^, sqrt(), ln(), e, sin(), cos(), tg(), ctg()");
            };
        }
    }
    getch();
    closegraph();
    return 0;
}
