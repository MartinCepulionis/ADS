//Programa, kuri isdesto sachmatu lentoje 5 karalienes taip, kad kiekvienas langelis butu kontroliuojamas bent vienos is ju.
#include <iostream>
#define N 8
using namespace std;

int lenta[N][N]= {0};
int queen=0;

void Spausdinti()
{
    cout << "  1  2  3  4  5  6  7  8  " << endl;
    for(int i=0; i<N; i++)
    {
        cout << i+1 << " ";
        for(int j=0; j<N; j++)
        {
            if(lenta[i][j]>=50)
                cout << lenta[i][j] << "  ";
            else
                cout << lenta[i][j] << "  ";

        }
        cout << endl;
    }
    cout << endl;

    cout << endl;
    cout << "  1  2  3  4  5  6  7  8  " << endl;
    for(int i=0; i<N; i++)
    {
        cout << i+1 << " ";
        for(int j=0; j<N; j++)
        {
            if(lenta[i][j]>=50)
                cout << "Q" << "  ";
            else
                cout << "_" << "  ";

        }
        cout << endl;
    }
    cout << endl;
}

void Atstatyti()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            lenta[i][j]=0;
        }
    }
    queen=0;

}

bool Patikrinti()
{

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(lenta[i][j]==0)
                return false;
        }

    }

    return true;

}

void Atimti(int row, int col)
{
    int i, j;

    // Up
    for (i = 0; i < row; i++)
        lenta[i][col]--;

    // Down
    for (i = row; i < N; i++)
        lenta[i][col]--;

    // Left
    for (i = 0; i < col; i++)
        lenta[row][i]--;

    // Right
    for (i = col; i < N; i++)
        lenta[row][i]--;

    //North-west
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        lenta[i][j]--;

    //South-west
    for (i=row, j=col; j>=0 && i<N; i++, j--)
        lenta[i][j]--;

    //South-east
    for (i=row, j=col; j<N && i<N; i++, j++)
        lenta[i][j]--;

    //North-east
    for (i=row, j=col; j<N && i>=0; i--, j++)
        lenta[i][j]--;

}

void Prideti(int row, int col)
{
    int i, j;

    // Up
    for (i = 0; i < row; i++)
        lenta[i][col]++;

    // Down
    for (i = row; i < N; i++)
        lenta[i][col]++;

    // Left
    for (i = 0; i < col; i++)
        lenta[row][i]++;

    // Right
    for (i = col; i < N; i++)
        lenta[row][i]++;

    //North-west
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        lenta[i][j]++;

    //South-west
    for (i=row, j=col; j>=0 && i<N; i++, j--)
        lenta[i][j]++;

    //South-east
    for (i=row, j=col; j<N && i<N; i++, j++)
        lenta[i][j]++;

    //North-east
    for (i=row, j=col; j<N && i>=0; i--, j++)
        lenta[i][j]++;

}

bool TikrintiKaralienes(int lenta[N][N], int row, int col)
{
    int i, j;

    // Up
    for (i = 0; i < row; i++)
        if (lenta[i][col]>=50)
            return false;

    // Down
    for (i = row; i < N; i++)
        if (lenta[i][col]>=50)
            return false;

    // Left
    for (i = 0; i < col; i++)
        if (lenta[row][i]>=50)
            return false;

    // Right
    for (i = col; i < N; i++)
        if (lenta[row][i]>=50)
            return false;

    //North-west
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (lenta[i][j]>=50)
            return false;

    //South-west
    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (lenta[i][j]>=50)
            return false;

    //South-east
    for (i=row, j=col; j<N && i<N; i++, j++)
        if (lenta[i][j]>=50)
            return false;

    //North-east
    for (i=row, j=col; j<N && i>=0; i--, j++)
        if (lenta[i][j]>=50)
            return false;

    return true;
}

bool Ieskoti(int lenta[N][N],int col)
{

    if(Patikrinti()==true && queen==6)
        return true;

    for (int i = 0; i < N; i++)
    {
        //Patikrinti ar galima pastatyti karaliene lenta[i][col] langelyje
        if(TikrintiKaralienes(lenta, i, col))
        {
            //Pastatyti karaliene sitam langely
            lenta[i][col] += 50;
            queen++;
            Prideti(i,col);

            //Rekursyviai pastatyti kitas karalienes

            for(int k=col+1;k<N-(5-queen);k++)
            {
                if(Ieskoti(lenta,k))
                    return true;
            }


            //Jeigu nepriejo sprendimo, pasalinti pastatyta karaliene
            lenta[i][col] -=50;
            queen--;
            Atimti(i,col);
        }
    }


    return false;
}

void Spresti()
{
    for(int i=0; i<4; i++)
    {
        if (Ieskoti(lenta,i))
        {
            cout <<endl<< " Sprendimas #" << i+1 << endl;
            Spausdinti();
            Atstatyti();
            //break;
        }
        else
            cout << " Nera sprendimo";
    }
}

int main()
{
    Spausdinti();
    Spresti();
    return 0;
}
