/*
ID: gauravrana05
TASK: lostcow 
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("lostcow.in");
    ofstream fout("lostcow.out");

    int x, y; fin >> x >> y; // Input

    int ans = 0, i = x, counter = 1, temp;

    while(true)
    {
    // Go in right of x
        temp = counter;
        while (temp--)
        {
            if (i == y) // cow found
                break;

            i++; ans++;
        }
        if( i == y)
            break;

        ans += i - x; i = x; //getting back to x
        counter *= 2; // doubling the moving distance
        
    //going to the left of x
        temp = counter;
        while (temp--)
        {
            if (i == y) //cow found
                break;
            i--; ans++;
        }
        if( i == y)
            break;
        ans += x - i;  i = x; // getting back to x
        counter *= 2; //doubling the moving distance again
    }
    fout<<ans<<endl;
    return 0;
}
