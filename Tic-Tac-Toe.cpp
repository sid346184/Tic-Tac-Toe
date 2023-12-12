    #include <iostream>
    using namespace std;

    char tic[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

    int row;
    int col;
    char token = 'X';
    bool tie;
    string n1 = "";
    string n2 = "";

    void gameBase()
    {
        cout << "    |    |    \n";
        cout << tic[0][0] << "   | " << tic[0][1] << "  | " << tic[0][2] << "  \n";
        cout << "____|____|____\n";
        cout << "    |    |    \n";
        cout << tic[1][0] << "   | " << tic[1][1] << "  | " << tic[1][2] << "  \n";
        cout << "____|____|____\n";
        cout << "    |    |    \n";
        cout << tic[2][0] << "   | " << tic[2][1] << "  | " << tic[2][2] << "  \n";
        cout << "    |    |    \n";
    }

    void function()
    {
        int digit;

        if (token == 'X')
        {
            cout << n1 << " enter the position: ";
            cin >> digit;
        }

        else if (token == 'O')
        {
            cout << n2 << " enter the position: ";
            cin >> digit;
        }

        if (digit == 1)
        {
            row = 0;
            col = 0;
        }
        else if (digit == 2)
        {
            row = 0;
            col = 1;
        }
        else if (digit == 3)
        {
            row = 0;
            col = 2;
        }
        else if (digit == 4)
        {
            row = 1;
            col = 0;
        }
        else if (digit == 5)
        {
            row = 1;
            col = 1;
        }
        else if (digit == 6)
        {
            row = 1;
            col = 2;
        }
        else if (digit == 7)
        {
            row = 2;
            col = 0;
        }
        else if (digit == 8)
        {
            row = 2;
            col = 1;
        }
        else if (digit == 9)
        {
            row = 2;
            col = 2;
        }

        else if(digit>9||digit<=0)
        {
            cout << "ERROR" << endl;
            gameBase();
            function();
        }

        if (token == 'X' && tic[row][col] != 'X' && tic[row][col] != 'O')
        {
            tic[row][col] = 'X';
            token = 'O';
        }

        else if (token == 'O' && tic[row][col] != 'X' && tic[row][col] != 'O')
        {
            tic[row][col] = 'O';
            token = 'X';
        }

        else if(tic[row][col] == 'X' || tic[row][col] == 'O')
        {
            cout << "Already done\n";
            gameBase();
            function();
        }
    }
    bool check()
    {
        for (int i = 0; i < 3; i++)
        {
            if (tic[i][0] == tic[i][1] && tic[i][0] == tic[i][2] || tic[0][i] == tic[1][i] && tic[0][i] == tic[2][i])
            {
                return true;
            }
        }
        if (tic[0][0] == tic[1][1] && tic[1][1] == tic[2][2] || tic[0][2] == tic[1][1] && tic[1][1] == tic[2][0])
        {
            return true;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (tic[i][j] != 'X' && tic[i][j] != 'O')
                {
                    return false;
                }
            }
        }
        tie = true;
        return false;
    }

    int main()
    {
        cout << "Enter name of first player: \n";
        getline(cin, n1);
        cout << "Enter name of second player: \n";
        getline(cin, n2);
        cout << n1 << " will play as X\n";
        cout << n2 << " will play as O\n";

        while (!check())
        {
            gameBase();
            function();
            check();
        }
        if (token == 'O' && tie == false)
        {
            cout << n1 << " wins!!!\n";
        }

        else if (token == 'X' && tie == false)
        {
            cout << n2 << " wins!!!\n";
        }

        else
        {
            cout << "It is a DRAW!!!";
        }
    }
