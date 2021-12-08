#include <iostream>
using namespace std;

int main() {
    int need[10][10], completed[10], safeSequence[10];
    int alloc[5][3], Max[5][3], avail[3];
    int p, r, i, j, process, count =0;


    cout<<"ENTER THE NUMBER OF PROCESSES : ";
    cin>>p;

    for(i = 0; i< p; i++)
        completed[i] = 0;

    cout<<"\n\nENTER THE NUMBER OF RESOURCES : ";
    cin>>r;

    cout<<"\n\nENTER THE MAX RESOURCES NEEDED FOR EACH PROCESS : ";
    for(i = 0; i < p; i++)
    {
        cout<<"\nFOR PROCESS "<<i <<" : ";
        for(j = 0; j < r; j++)
            cin>>Max[i][j];
    }

    cout<<"\n\nENTER THE ALLOCATION FOR EACH PROCESS : ";
    for(i = 0; i < p; i++)
    {
        cout<<"\nFOR PROCESS "<<i + 1<<" : ";
        for(j = 0; j < r; j++)
            cin>>alloc[i][j];
    }

    cout<<"\n\nENTER AVAILABLE RESOURCES: ";
    for(i = 0; i < r; i++)
        cin>>avail[i];



    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
            need[i][j] = Max[i][j] - alloc[i][j];

    cout<<"Initial situation"<<endl;

    do
    {
        int c=0;
        cout<<"\nProcess:\t MAX MATRIX:\tALLOCATION MATRIX:\t\t  NEED:\t\t   Available:\n";
        for(i = 0; i < p; i++)
        {
            cout<<"  P"<<i;
            cout<<"\t\t  ";
            for( j = 0; j < r; j++)
                cout<<Max[i][j]<<"  ";
            cout<<"\t\t\t";
            for( j = 0; j < r; j++)
                cout<<alloc[i][j]<<"  ";
            cout<<"\t\t\t";
            for( j=0; j<r; j++)
                cout<<need[i][j]<<"  ";
            cout<<"\t\t";
            if (c==0){
                for(j=0;j<r;j++)
                    cout<<(avail[j])<<" ";
                c = c+1;
            }
            cout<<"\n";

        }

        process = -1;

        for(i = 0; i < p; i++)
        {
            if(completed[i] == 0)//if not completed
            {
                process = i ;
                for(j = 0; j < r; j++)
                {
                    if(avail[j] < need[i][j])
                    {
                        process = -1;
                        break;
                    }
                }
            }
            if(process != -1)
                break;
        }

        if(process != -1)
        {
            cout<<"\nPROCESS "<<process<<" RUNS TO COMPLETION !!\n";
            safeSequence[count] = process;
            count++;
            for(j = 0; j < r; j++)
            {
                avail[j] += alloc[process][j];
                alloc[process][j] = 0;
                Max[process][j] = 0;
                completed[process] = 1;
            }
        }
    }while(count != p && process != -1);

    if(count == p)
    {
        cout<<"\nTHE SYSTEM IS IN SAFE STATE !!\n";
        cout<<"SAFE SEQUENCE : { ";
        for( i = 0; i < p-1; i++)
            cout<<"P"<<safeSequence[i]<<"->";
        cout<<"P"<<safeSequence[i];
        cout<<" }\n";
    }
    else
        cout<<"\nTHE SYSTEM IS IN AN UNSAFE STATE !!";

}
