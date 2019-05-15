//Code by Abhishek Tiwari
//Hackerearth : https://www.hackerearth.com/@become
//Github :https://github.com/becomeahacker

#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
using namespace std;
char b[3][3];
bool player1_is_human=true;
bool player2_is_human=true;
int moves[2]={1,1}; // Count the number of moves.

void delay(unsigned int miliseconds)
{
    clock_t goal=miliseconds+clock();
    while(goal>clock());
}
void Draw_menu()
{
    M:
    system("cls");
    player1_is_human=true;
    player2_is_human=true;
    moves[0]=1;
    moves[1]=1;

    cout<<"\n\n\t\t\tT i c    T a c   T o e\n\n\n";
    cout<<"\t1. Human     VS      Human\n";
    cout<<"\t2. Human     VS   Computer\n";
    cout<<"\t3. Computer  VS      Human\n";
    cout<<"\t4. Computer  VS   Computer\n";
    cout<<"\t5. QUIT\n\n";
    cout<<"Enter your choice\n";
    int user_choice;
    cin>>user_choice;
    if(user_choice<1 || user_choice>5)
    {
        cout<<"Invalid Choice!!!!\n";
        delay(1250);
        goto M;
    }

    if(user_choice==1)
        {
            player1_is_human=true;
            player2_is_human=true;
        }
    if(user_choice==2)
        {
            player1_is_human=true;
            player2_is_human=false;
        }
    if(user_choice==3)
        {
            player1_is_human=false;
            player2_is_human=true;
        }
    if(user_choice==4)
        {
            player1_is_human=false;
            player2_is_human=false;
        }

        if(user_choice==5)
        {
        cout<<"Are you sure you want to quit the game ?\n(y/n)";
        char confirm='n';
        cin>>confirm;
        if(confirm=='Y' || confirm=='y')
            {

                system("cls");
                cout<<"\n\n\n\n\n\n\n\t\t\t\tG A M E O V E R\n";
                delay(1250);;
                exit(0);
            }
        else
            goto M;
        }
}
void Draw_board()
{
    system("cls");
    cout<<"\n\n\t\t\tT i c    T a c   T o e\n";
    cout<<"\tPlayer1 [X] \n";
    cout<<"\tPlayer2 [O] \n\n";

    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<b[0][0]<<"  |  "<<b[0][1]<<"  |  "<<b[0][2]<<"  \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<b[1][0]<<"  |  "<<b[1][1]<<"  |  "<<b[1][2]<<"  \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<b[2][0]<<"  |  "<<b[2][1]<<"  |  "<<b[2][2]<<"  \n";
    cout<<"\t\t     |     |     \n";

}

int get_player_choice(int chance)
{
    char player;
    char opponent;
    int choice;
    if(chance==1)
        {
            player='X';
            opponent='O';
            if(player1_is_human)
            {

                cout<<"Enter your choice Player 1 \n";
                cin>>choice;
                return choice;
            }

        }
    else
        {
            player='O';
            opponent='X';
            if(player2_is_human)
            {

                cout<<"Enter your choice Player 2 \n";
                cin>>choice;
                return choice;
            }
        }

        // If control is here means Player is Computer
        // If its first move then choose corner or middle place
        // First check if player can win in this chance then try to block opponent then try random move

        if(moves[chance-1]==1 && moves[2-chance]==2) // if this is the first move of player
        {
            if(b[1][1]!=opponent)
            {
                cout<<"Player "<<chance<<"  choose 5 \n";
                delay(1250);;
                return 5;
            }
            else
            {
                int random_corner=rand()%4;
                int corners[4]={1,3,7,9};
                cout<<"Player "<<chance<<"  choose "<<corners[random_corner]<<"\n";
                delay(1250);;
                return corners[random_corner];
            }
        }
        else
        {

            // create another board player=1 empty=0 opponent=-1
                int sum[3][3];
                for(int i=0;i<3;++i)
                for(int j=0;j<3;++j)
                    if(b[i][j]==player)
                        sum[i][j]=1;
                    else
                        {
                            if(b[i][j]==opponent)
                            sum[i][j]=-1;
                            else
                            sum[i][j]=0;
                        }

                int hsums[3];
                int vsums[3];
                int dsums[2];

                // sum of 2 means 2 player pieces + 1 empty place
                hsums[0]=sum[0][0]+sum[0][1]+sum[0][2];
                hsums[1]=sum[1][0]+sum[1][1]+sum[1][2];
                hsums[2]=sum[2][0]+sum[2][1]+sum[2][2];

                vsums[0]=sum[0][0]+sum[1][0]+sum[2][0];
                vsums[1]=sum[0][1]+sum[1][1]+sum[2][1];
                vsums[2]=sum[0][2]+sum[1][2]+sum[2][2];

                dsums[0]=sum[0][0]+sum[1][1]+sum[2][2];
                dsums[1]=sum[0][2]+sum[1][1]+sum[2][0];

            // check if player can win
                    for(int i=0;i<3;++i)
                    {
                        if(hsums[i]==2)
                        {
                            for(int j=0;j<3;++j)
                            if(sum[i][j]==0)
                            {
                                cout<<"Player "<<chance<<"  choose "<<i*3+j+1<<"\n";
                                delay(1250);;
                                return i*3+j+1;
                            }
                        }

                    }

                    for(int i=0;i<3;++i)
                    {
                        if(vsums[i]==2)
                        {
                            for(int j=0;j<3;++j)
                            if(sum[j][i]==0)
                            {
                                cout<<"Player "<<chance<<"  choose "<<j*3+i+1<<"\n";
                                delay(1250);;
                                return j*3+i+1;
                            }
                        }

                    }

                    if(dsums[0]==2)
                    {
                        if(sum[0][0]==0)
                            {
                                cout<<"Player "<<chance<<"  choose 1"<<"\n";
                                delay(1250);;
                                return 1;
                            }
                        if(sum[1][1]==0)
                            {
                                cout<<"Player "<<chance<<"  choose 5"<<"\n";
                                delay(1250);;
                                return 5;
                            }
                        if(sum[2][2]==0)
                            {
                                cout<<"Player "<<chance<<"  choose 9"<<"\n";
                                delay(1250);;
                                return 9;
                            }
                    }

                    if(dsums[1]==2)
                    {
                        if(sum[0][2]==0)
                            {
                                cout<<"Player "<<chance<<"  choose 3"<<"\n";
                                delay(1250);;
                                return 3;
                            }
                        if(sum[1][1]==0)
                            {
                                cout<<"Player "<<chance<<"  choose 5"<<"\n";
                                delay(1250);;
                                return 5;
                            }
                        if(sum[2][0]==0)
                            {
                                cout<<"Player "<<chance<<"  choose 7"<<"\n";
                                delay(1250);;
                                return 7;
                            }
                    }



                //Control here means player cant win means block opponent

                    for(int i=0;i<3;++i)
                    {
                        if(hsums[i]==-2)
                        {
                            for(int j=0;j<3;++j)
                            if(sum[i][j]==0)
                            {
                                cout<<"Player "<<chance<<"  choose "<<i*3+j+1<<"\n";
                                delay(1250);;
                                return i*3+j+1;
                            }
                        }

                    }

                    for(int i=0;i<3;++i)
                    {
                        if(vsums[i]==-2)
                        {
                            for(int j=0;j<3;++j)
                            if(sum[j][i]==0)
                            {
                                cout<<"Player "<<chance<<"  choose "<<j*3+i+1<<"\n";
                                delay(1250);;
                                return j*3+i+1;
                            }
                        }

                    }

                    if(dsums[0]==-2)
                    {
                        if(sum[0][0]==0)
                            {
                                cout<<"Player "<<chance<<"  choose 1"<<"\n";
                                delay(1250);;
                                return 1;
                            }
                        if(sum[1][1]==0)
                            {
                                cout<<"Player "<<chance<<"  choose 5"<<"\n";
                                delay(1250);;
                                return 5;
                            }
                        if(sum[2][2]==0)
                            {
                                cout<<player<<chance<<"  choose 9"<<"\n";
                                delay(1250);;
                                return 9;
                            }
                    }

                    if(dsums[1]==-2)
                    {
                        if(sum[0][2]==0)
                            {
                                cout<<"Player "<<chance<<"  choose 3"<<"\n";
                                delay(1250);;
                                return 3;
                            }
                        if(sum[1][1]==0)
                            {
                                cout<<"Player "<<chance<<"  choose 5"<<"\n";
                                delay(1250);;
                                return 5;
                            }
                        if(sum[2][0]==0)
                            {
                                cout<<"Player "<<chance<<"  choose 7"<<"\n";
                                delay(1250);;
                                return 7;
                            }
                    }

            int my_move;

            //EDGE CASE WHEN OPPONENT GETS TWO CORNERS AND PLAYER HAS CENTRE
            if(moves[chance-1]==2 && moves[2-chance]==3)
            {
                if((sum[0][2]==-1 && sum[1][1]==1 && sum[2][0]==-1) || (sum[0][0]==-1 && sum[1][1]==1 && sum[2][2]==-1))
                {int edges[4] = {2,4,6,8};
                my_move = edges[rand()%4];
                cout<<"Player "<<chance<<" choose "<<my_move<<"\n";
                delay(1250);
                return my_move;
                }

            }


            // Control reaches here means cannot win cannot block hence play random
            my_move=1+rand()%9;
            while(  (b[my_move/3][my_move%3-1]=='X') || (b[my_move/3][my_move%3-1]=='O') )
            {
                my_move=1+rand()%9;
                //cout<<my_move<<" "<<flush;
            }
            cout<<"Player "<<chance<<"  choose "<<my_move<<"\n";
            delay(1250);;
             return my_move;

        }
}

int check_won()
{
    char p='X';
    // CHECK IF PLAYER 1 [X] HAS WON
    for(int i=0;i<3;++i)
    if(b[i][0]==p && b[i][1]==p && b[i][2]==p)
        return 1;

    for(int i=0;i<3;++i)
    if(b[0][i]==p && b[1][i]==p && b[2][i]==p)
        return 1;

    if(b[0][0]==p && b[1][1]==p && b[2][2]==p)
        return 1;

    if(b[0][2]==p && b[1][1]==p && b[2][0]==p)
        return 1;

    //CHECK IF PLAYER 2 [O] HAS WON
    p='O';

    for(int i=0;i<3;++i)
    if(b[i][0]==p && b[i][1]==p && b[i][2]==p)
        return 2;

    for(int i=0;i<3;++i)
    if(b[0][i]==p && b[1][i]==p && b[2][i]==p)
        return 2;

    if(b[0][0]==p && b[1][1]==p && b[2][2]==p)
        return 2;

    if(b[0][2]==p && b[1][1]==p && b[2][0]==p)
        return 2;

    //CHECK FOR A DRAW
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
        if(b[i][j]<='9' && b[i][j]>='1')
        return 0; // No One has won game continues

    return -1; // DRAW
}
int main()
{
S:
    system("cls");
    Draw_menu();
        for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
        b[i][j]=(i*3+j)+'1';

        Draw_board();
        bool flag=true;
        int chance=1;
        int choice;
        while(flag)
        {

            A:

                choice=get_player_choice(chance);

            if(b[choice/3][choice%3-1]=='X' || b[choice/3][choice%3-1]=='O')
                {
                cout<<"Already occupied!!! Enter other place\n";
                goto A;
                }

            if(chance==1)
                ++moves[0];
            else
                ++moves[1];

            if(chance==1)
                {
                    b[choice/3][choice%3-1]='X';
                    chance=2;
                }
            else
                {
                    b[choice/3][choice%3-1]='O';
                    chance=1;
                }
            Draw_board();

        int result=check_won();
        if(result==-1)
        {
            cout<<"DRAW!!!\n";
            flag=false;
        }
        if(result==1)
        {
            cout<<"Player 1 Won!!!\n";
            flag=false;
        }
        if(result==2)
        {
            cout<<"Player 2 Won!!!\n";
            flag=false;
        }


        }
        delay(1250);;
        delay(1250);;
        goto S; // Restart the Game


return 0;
}
