#include<iostream>
using namespace std;
int SJF_tab[10][6];

//Function to sort in ascending of arrival time
void sortAT(int SJF_tab[][6],int n)
{
  for (int i=0;i<n;i++)
  {
        for (int j=0;j<n-i-1;j++)
        {
            if (SJF_tab[j][1]>SJF_tab[j+1][1])
            {
                for (int k=0;k<3;k++) 
                {
                    swap(SJF_tab[j][k],SJF_tab[j+1][k]);
                }
            }
        }
    }
   
}

//Funtion to calculate completion time,turn around time and burst time
//4th column has completion time
//5th column has Turn around time
//6th column has Waiting Time
void calculate(int SJF_tab[][6],int n)
{
    SJF_tab[0][3]=SJF_tab[0][1]+SJF_tab[0][2];            //completion time of process arriving first
    SJF_tab[0][4]=SJF_tab[0][3]-SJF_tab[0][1];            //Turn around time of process arriving first
    SJF_tab[0][5]=SJF_tab[0][4]-SJF_tab[0][2];            //Waiting time of process arriving first
    int prevCT,val;
    for(int i=1;i<n;i++)
    {
      prevCT=SJF_tab[i-1][3];                 //Completion time of previous process
      int lowBT=SJF_tab[i][2];                //Burst Time of current process
      
       /*Check if any of the next processes have arrived before
       completion of the current process and has lowest burst time*/              
      for(int j=i;j<n;j++)
      {
          if(prevCT>=SJF_tab[j][1] && lowBT>=SJF_tab[j][2])  
        {                                                        
            lowBT=SJF_tab[j][2];
            val=j;
        }
      }
        SJF_tab[val][3] = prevCT+ SJF_tab[val][2]; //update the process details with next lowest burst time
        SJF_tab[val][4] = SJF_tab[val][3] - SJF_tab[val][1];
        SJF_tab[val][5] = SJF_tab[val][4] - SJF_tab[val][2];
        for (int k = 0; k < 6; k++) {
            swap(SJF_tab[val][k], SJF_tab[i][k]);   //reordering based on execution of process
        }
    }
}

int main()
{
  int n,sumTAT=0,sumWT=0;
  cout<<"Enter the number of processes:";     //input for number of processes
  cin>>n;
  for(int i=0;i<n;i++)
  {
     cout<<"Enter the arrival time and burst time for P"<<i+1<<":"; //input of arrival and burst time
     SJF_tab[i][0]=i+1;
     cin>>SJF_tab[i][1];
     cin>>SJF_tab[i][2];
  }
   cout<<"ProcessID\tArrival Time\tBurst Time\n"; //display the input 
  for(int i=0;i<n;i++)
  {
   cout<<SJF_tab[i][0]<<"\t\t"<<SJF_tab[i][1]<<"\t\t"<<SJF_tab[i][2]<<endl;
  }
  cout<<endl;
   sortAT(SJF_tab,n);    //sorting input based on ascending order of arrival time         
   calculate(SJF_tab,n); //calculate the completion time,turn around time and waiting time
   cout<<"ProcessID\tArrival Time\tBurst Time\tCompletion Time\tTurnAround Time\tWaiting Time\n";
   //display the table after all the calculations
  for(int i=0;i<n;i++)
  {
   cout<<SJF_tab[i][0]<<"\t\t"<<SJF_tab[i][1]<<"\t\t"<<SJF_tab[i][2]<<"\t\t"<<SJF_tab[i][3]<<"\t\t"<<SJF_tab[i][4]<<"\t\t"<<SJF_tab[i][5]<<endl;
  }
  for(int i=0;i<n;i++)
    {
        sumTAT+=SJF_tab[i][4];         //summation of turn around time
        sumWT+=SJF_tab[i][5];          //summation of waiting time
    }
    
  cout<<"Average Turn Around Time="<<sumTAT/(float)n<<"ms"<<endl; //display average turn around time
  cout<<"Average Waiting Time="<<sumWT/(float)n<<"ms"<<endl;      //display average waiting time
  return 0;
}