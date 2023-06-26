#include <iostream>

using namespace std;

char arr [3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char player_order='X';
void Draw();
void Play();
char Winner();

int main()
{

    while(1)
    {
        system("cls");
        Draw();
        Play();
        char check =Winner();
        if(check=='O')
        {
            cout<<"Great, player O wins \n";
            break;
        }
        else if(check=='X')
        {
            cout<<"Great, player X wins \n";
            break;
        }
        else if(check=='T')
        {
            cout<<"Great, no winner, case of tie \n";
            break;
        }
        else
            continue;

    }





    return 0;
}


void Draw()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<arr[i][j]<<"    ";
        }
        cout<<"\n";
    }
}

void Play()
{
    cout<<"Enter your position player : "<<player_order<<"\n";
    char pos; cin>>pos;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]==pos)
            {
                arr[i][j]=player_order;
                player_order=(player_order=='X')?'O':'X';
                break;
            }
        }
    }
}


char Winner()
{
    // winner through row
    int x=0,o=0;
    for(int i=0;i<3;i++)
    {
        x=0,o=0;
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]=='O')
                o++;
            else if(arr[i][j]=='X')
                x++;
        }
        if(x==3)
            return 'X';
        else if(o==3)
            return 'O';
    }

    // winner through column
    for(int i=0;i<3;i++)
    {
        x=0,o=0;
        for(int j=0;j<3;j++)
        {
            if(arr[j][i]=='X')
                x++;
            else if(arr[j][i]=='O')
                o++;
        }
        if(x==3)
            return 'X';
        else if(o==3)
            return 'O';
    }

    // winner across the main diameter
    o=0,x=0;
    for(int i=0;i<3;i++)
    {
        if(arr[i][i]=='O')
            o++;
        else if(arr[i][i]=='X')
            x++;
    }
    if(x==3)
        return 'X';
    else if(o==3)
        return 'O';
    // winner across the sub diameter
    x=0,o=0;
    for(int i=0;i<3;i++)
    {
        if(arr[i][3-i+1]=='O')
            o++;
        else if(arr[i][3-i+1]=='O')
            x++;
    }
    if(x==3)
        return 'X';
    else if(o==3)
        return 'O';

    // in case of tie
    int cnt=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]=='X'||arr[i][j]=='O')
                cnt++;
        }
    }
    if(cnt==9)
        return 'T';  // finish
    else
        return 'C';  // continue

}
