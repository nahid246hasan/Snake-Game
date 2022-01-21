#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int wow,count=0,qs,row=20,column=20;
int x,y,fruitx,fruity,score,gameover;
int tailx[100],taily[100],counttail=0,flag=0;
void level()
{
    system("cls");
    int l,t;
    for(l=0; l<row; l++)
    {
        for(t=0; t<column; t++)
        {
            if(l==0||t==0||l==row-1||t==column-1)
            {
                printf("#");
            }
            else
            {
                if(l==3&&t==5)
                {
                    printf("Game Level");
                    t+=9;
                }
                else if(t==3&&l==7)
                {
                    printf("1. Easy");
                    t+=6;

                }
                else if(t==3&&l==9)
                {
                    printf("2. Midium");
                    t+=8;
                }
                else if(t==3&&l==11)
                {
                    printf("3. Hard");
                    t+=6;
                }
                else if(t==3&&l==13)
                {
                    printf("4. Exit");
                    t+=6;
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

}
void setup()
{
    gameover=0;
    x=row/2;
    y=column/2;
lebel1:
    fruitx=rand()%20;
    if(fruitx==0)
        goto lebel1;
lebel2:
    fruity=rand()%20;
    if(fruity==0)
        goto lebel2;
    score=0;
}
void draw()// It is the structure of the game
{
    int j,i,k;
    system("cls");
    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
        {
            if(i==row-1||i==0||j==0||j==column-1)
                printf("#");
            else
            {
                if(i==x&&j==y)
                {
                    printf("O");
                }
                else if(i==fruitx&&j==fruity)
                    printf("X");
                else
                {
                    int ch=0;
                    for(k=0; k<counttail; k++)
                    {
                        if(i==tailx[k]&&j==taily[k])
                        {
                            printf("o");
                            ch=1;
                        }
                    }
                    if(ch==0)
                    {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
    printf("\n   >>:::::::::::::>>\n=>  %d",score);
}

void input()
{
    if(kbhit())
    {
        //there used 4 button name a,d,w,s.
        //for go right left up down.
        switch(getch())
        {
        case 'a':
            flag=1;
            break;
        case 'd':
            flag=2;
            break;
        case 'w':
            flag=3;
            break;
        case 's':
            flag=4;
            break;
        case 'x':
            gameover=1;
            break;

        }
    }
}
void logic()
{
    int i;
    int prevx=tailx[0],prevy=taily[0],prev2x,prev2y;
    tailx[0]=x;
    taily[0]=y;

    for(i=1; i<counttail; i++)
    {
        prev2x=tailx[i];
        prev2y=taily[i];
        tailx[i]=prevx;
        taily[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;

    }

    switch(flag)
    {
    case 1:
        y--;
        break;
    case 2:
        y++;
        break;
    case 3:
        x--;
        break;
    case 4:
        x++;
        break;
    default:
        break;
    }
    if(x<0||x>row||y<0||y>column)
        gameover=1;
    for(i=0; i<counttail; i++)
    {
        if(x==tailx[i]&&y==taily[i])
        {
            gameover=1;
        }
    }

    if(x==fruitx&&y==fruity)
    {
lebel3:
        fruitx=rand()%20;
        if(fruitx==0)
            goto lebel3;
lebel4:
        fruity=rand()%20;
        if(fruity==0)
            goto lebel4;
        score+=10;
        counttail++;
    }
}
void fortune()
{
    int l,t;
    for(l=0; l<row; l++)
    {
        for(t=0; t<column; t++)
        {
            if(l==0||t==0||l==row-1||t==column-1)
            {
                printf("#");
            }
            else
            {
                if(l==3&&t==5)
                {
                    printf("Wellcome");
                    t+=7;
                }
                else if(t==3&&l==7)
                {
                    printf("1. Start game");
                    t+=12;

                }
                else if(t==3&&l==9)
                {
                    printf("2. Game level");
                    t+=12;
                }
                else if(t==3&&l==11)
                {
                    printf("3. Help");
                    t+=6;
                }
                else if(t==3&&l==13)
                {
                    printf("4. Exit");
                    t+=6;
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

}
void topup()
{
    int i,j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
        {
            if(i==0||j==0||i==row-1||j==column-1)
            {
                printf("#");
            }
            else
            {
                if(i==8&&j==3)
                {
                    printf("1. Continue");
                    j+=10;
                }
                else if(i==10&&j==3)
                {
                    printf("2. First page");
                    j+=12;
                }
                else if(i==12&&j==3)
                {
                    printf("3. Exit");
                    j+=6;
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}
void turkey()
{
    int i,j,row=20,column=20;
    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
        {
            if(i==0||j==0||i==row-1||j==column-1)
            {
                printf("#");
            }
            else
            {
                if(i==2&&j==4)
                {
                    printf("Help center");
                    j+=10;
                }
                else if(i==3&&j==4)
                {
                    printf("-----------");
                    j+=10;
                }
                else if(i==6&&j==3)
                {
                    printf("For Right 'd'");
                    j+=12;
                }
                else if(i==8&&j==3)
                {
                    printf("For Left 'a'");
                    j+=11;
                }
                else if(i==10&&j==3)
                {
                    printf("For Up 'w'");
                    j+=9;
                }
                else if(i==12&&j==3)
                {
                    printf("For Down 's'");
                    j+=11;
                }
                else if(i==16&&j==5)
                {
                    printf("Thank you");
                    j+=8;
                }
                else if(i==17&&j==5)
                {
                    printf("---------");
                    j+=8;
                }
                else if(i==18&&j==3)
                {
                    printf("Back? (Press 1)");
                    j+=14;
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("\n   >>:::::::::::::>>\n=>  ");
}
void first()
{
    int i,j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
        {
            if(i==0||j==0||i==row-1||j==column-1)
            {
                printf("#");
            }
            else
            {
                if(i==2&&j==1)
                {
                    printf("Note:");
                    j+=4;
                }
                else if(i==4&&j==3)
                {
                    printf("At first");
                    j+=7;
                }
                else if(i==6&&j==3)
                {
                    printf("go to the");
                    j+=8;
                }
                else if(i==8&&j==3)
                {
                    printf("Help center");
                    j+=10;
                }
                else if(i==10&&j==3)
                {
                    printf("To know about");
                    j+=12;
                }
                else if(i==12&&j==3)
                {
                    printf("The Game rule");
                    j+=12;
                }
                else if(i==15&&j==4)
                {
                    printf("Hit (Enter)");
                    j+=10;
                }else if(i==16&&j==3)
                {
                    printf("To Get in the");
                    j+=12;
                }else if(i==17&&j==5)
                {
                    printf("<<Game>>");
                    j+=7;
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("\n   >>:::::::::::::>>\n=>  ");
}


int main()
{
    int m,n,a,q,asus=10000,rog=10000,komola=1000,kanto=1000;
    char in[100],bro;
    first();
    gets(in);
school:
    asus=10000;
    rog=10000;
    komola=1000;
    kanto=1000;
first1:
    system("cls");
    fortune();
    printf("\n   >>:::::::::::::>>\n=>  ");
    scanf("%d",&wow);
    if(wow==1)
    {
        system("cls");
lebel5:
        setup();
        while(1)
        {
            draw();
            input();
            logic();
            if(gameover==1)
            {
                break;
            }
            for(m=0; m<asus; m++) //use for speed down;
            {
                for(n=0; n<rog; n++)
                {

                }
            }
            for(m=0; m<komola; m++)// use for speed down;
            {
                for(n=0; n<kanto; n++)
                {

                }
            }
        }
        system("cls"); //use for clear screen;
        topup();
        printf("\n   >>:::::::::::::>>\n=>  ");
        scanf("%d",&a);
        if(a==1)
        {
            goto lebel5;
        }
        else if(a==2)
        {
            system("cls");
            goto school;
        }
        else
        {
            return 0;
        }
    }
    if(wow==2)
    {
        int x1;
        level();
        scanf("%d",&x1);
        if(x1==2)
        {
            asus-=3000;
            rog-=3000;
            komola-=500;
            kanto-=500;
            goto first1;
        }
        else if(x1==3)
        {
            asus-=5000;
            rog-=5000;
            komola-=1000;
            kanto-=1000;
            goto first1;
        }
        else
            goto school;

    }
    if(wow==3)
    {
        system("cls");
        turkey();
        scanf("%d",&qs);
        if(qs==1)
        {
            system("cls");
            goto first1;
        }
    }
    return 0;
}

