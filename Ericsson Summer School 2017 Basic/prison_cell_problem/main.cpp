#include <iostream>
using namespace std;

/*
Prisoners Cell Problem
C++Summer School


Functions:

fn_all_doors_closet(wsk); //start table bool with all doors closet

fn_guards_opening_or_closing_doors(wsk,i_wsk); //calculations for guards and doors

fn_show_actual_status(wsk); // show status of all doors

fn_show_number_opened_cells(b_cells); //show numbers of opened doors


Author: Lukasz Janus
18-07-2017

*/

/*==========================================================*/

void fn_all_doors_closet(bool *doors)
{
    for (int i=1; i<101; i++)
    {
        doors[i]=false;
    }
    cout<<"All doors closet!\n";
}

/*==========================================================*/

void fn_show_actual_status(bool *doors)
{
    cout<< "door no: "<<" status:\n";
    for (int i=1; i<=25; i++)
    {
        if (i<=9) cout<<" ";
        cout<<i<<": "<<doors[i]<<", "<<i+25<<": "<<doors[i+25]<<", "<<i+50<<": "<<doors[i+50]<<", "<<i+75<<": "<<doors[i+75]<<endl;
    }
}

/*==========================================================*/

void fn_guards_opening_or_closing_doors(bool *doors, int *n)
{
    cout<<" wsk "<<*n<<endl;
    int temp=1;
    for (int i=1; i<*n; i++)
    {

        for (int j=0; j<=100; j=j+temp)
        {

            if (doors[j]==false)
            {

                doors[j]=true;
            }
            else
            {
                doors[j]=false;
            }
        }
        temp++;
    }
}

/*==========================================================*/
int check(int i_g)
{
    for (;;)
    {
        if (i_g<0 || i_g>100)
        {
            cout<<"\nWrong number of guards!! Try again!!\n";
            cin>>i_g;
        }
        else return i_g;
    }



}
/*==========================================================*/

void fn_show_number_opened_cells(bool *doors)
{
    cout<<"\nLucky prisoners - they are in cells: \n\n";
    for (int i=1; i<=100; i++)
    {
        if (doors[i]==true)
        {
            cout<<i<<" ";
        }
    }
}

/*==========================================================*/

void start()
{
    cout<<"Type number of guards (from 0 to 100): ";

    int i_g; //number of guards
    cin>>i_g;

    i_g=check(i_g);

    i_g+=1;
    int *i_wsk=&i_g;
    bool b_cells[101]; //cells, easier was +1, because in loop counter=0 (b_cells[0] not work correctly.
    bool *wsk=b_cells;

    fn_all_doors_closet(wsk); //all doors closet
//   fn_show_actual_status(wsk); //show all doors
    fn_guards_opening_or_closing_doors(wsk,i_wsk);
    fn_show_actual_status(wsk); //all show all doors again - after calculating
    fn_show_number_opened_cells(b_cells);
    cout<<endl;
}

/*==========================================================*/

int main()
{
    start();
    return 0;
}
