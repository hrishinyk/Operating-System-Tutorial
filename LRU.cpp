#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int pages_num, frame_num, page[50],i ,count=0;
    cout<<"\nEnter the number of pages:"; 
    cin>> pages_num;  //it will store the number of Pages
    cout<<"\nEnter the Reference String:";
    for(i=0;i< pages_num;i++)
    { 
        cin>>page[i];
    }
    cout<<"\nEnter the number of frames:"; 
    cin>> frame_num;
    cout<<endl;
    int frame[frame_num],fcount[frame_num];
    for(i=0;i< frame_num;i++)
    {
        frame[i]=-1;
        fcount[i]=0; //it will keep the track of when the page was last used
    }
    i=0;
    while(i< pages_num)
    {
        int j=0,flag=0;
        while(j< frame_num)
        {
            if(page[i]==frame[j]) //it will check whether the page already exist in frames or not
            {  
                flag=1;
                fcount[j]=i+1;
            }
            j++;
        }
        j=0;
        if(flag == 1)
        {
            while(j< frame_num)
            {
                cout<<"\t|"<<frame[j]<<"|";    //display the frame contents for current hit iteration
                j++;
            }
            cout<<endl;
        }
        j=0;
        if(flag==0)                //if page is not present
        {
            int min=0,k=0;
            while(k<frame_num-1) 
            { 
                if(fcount[min]>fcount[k+1]) //It will calculate the page which is least recently used
                    min=k+1;
                k++;
            }
            frame[min]=page[i]; 
            fcount[min]=i+1;  //Increasing the time
            count++;           //it will count the total Page Fault
            while(j< frame_num)
            {
                cout<<"\t|"<<frame[j]<<"|";    //display the frame contents for current miss iteration
                j++;
            }
            cout<<endl;
        }
        i++; 
    }
    int hit; 
    float r_miss, r_hit;
    hit = pages_num-count;
    r_miss = ((count/(float)pages_num)*100);
    r_hit = ((hit/(float)pages_num)*100);
    cout<<"\nPage Fault: "<<count<<endl;
    cout<<"Number of Hits: "<<hit<<endl;
    cout<<"Miss Ratio: "<<fixed<<setprecision(3)<<r_miss<<"%"<<endl;
    cout<<"Hit Ratio: "<<fixed<<setprecision(3)<<r_hit<<"%"<<endl;
    return 0;
}
