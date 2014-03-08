#include<iostream>
using namespace std;
char arr[55][55];
int fr,bk,vis[55][55],qx[3000],qy[3000];
void explore(int rw,int cl,char ch)
{
        if(arr[rw-1][cl-1]==char(ch+1) && !vis[rw-1][cl-1])
                {
                        vis[rw-1][cl-1]=1;
                        qx[bk]=rw-1;
                        qy[bk++]=cl-1;
                }
                if(arr[rw-1][cl]==char(ch+1) && !vis[rw-1][cl])
                {
                        vis[rw-1][cl]=1;
                                                qx[bk]=rw-1;
                        qy[bk++]=cl;
                }
                if(arr[rw-1][cl+1]==char(ch+1) && !vis[rw-1][cl+1])
                {
                        vis[rw-1][cl+1]=1;
                                                qx[bk]=rw-1;
                        qy[bk++]=cl+1;
                }
                if(arr[rw][cl-1]==char(ch+1) && !vis[rw][cl-1])
                {
                        vis[rw][cl-1]=1;
                                        qx[bk]=rw;
                        qy[bk++]=cl-1;
                }
                if(arr[rw][cl+1]==char(ch+1) && !vis[rw][cl+1])
                {
                        vis[rw][cl+1]=1;
                                                qx[bk]=rw;
                        qy[bk++]=cl+1;
                }
                if(arr[rw+1][cl-1]==char(ch+1) && !vis[rw+1][cl-1])
                {
                        vis[rw+1][cl-1]=1;
                                                qx[bk]=rw+1;
                        qy[bk++]=cl-1;
                }
                if(arr[rw+1][cl]==char(ch+1) && !vis[rw+1][cl])
                {
                        vis[rw+1][cl]=1;
                                                qx[bk]=rw+1;
                        qy[bk++]=cl;
                }
                if(arr[rw+1][cl+1]==char(ch+1) && !vis[rw+1][cl+1])
                {
                        vis[rw+1][cl+1]=1;
                                                qx[bk]=rw+1;
                        qy[bk++]=cl+1;
                }                                                                                                       
}
int main()
{
        int rows,columns,count=0;
        while(1)
        {
                cin>>rows>>columns;
                if(rows==0)
                break;
                fr=0; bk=0;
                count++;
        for(int i=0;i<=columns+1;i++)
        arr[0][i]=arr[rows+1][i]='0';
        for(int i=0;i<=rows+1;i++)
        arr[i][0]=arr[i][columns+1]='0';
        for(int i=1;i<=rows;i++)
        for(int j=1;j<=columns;j++)
        {
                cin>>arr[i][j];
                vis[i][j]=0;
                if(arr[i][j]=='A')
        {
                qx[bk]=i;
                qy[bk++]=j;             
        }
        }
        for(int i=0;i<bk&&arr[qx[i]][qy[i]]!='Z';i++)
        {
        explore(qx[i],qy[i],arr[qx[i]][qy[i]]);        	
       // cout<<i<<". "<<arr[qx[i]][qy[i]]<<" "<<qx[i]<<" "<<qy[i]<<endl;
		}
        if(bk==0)
        cout<<"Case "<<count<<": 0"<<endl;
        else if(bk!=0)
        cout<<"Case "<<count<<": "<<int(arr[qx[bk-1]][qy[bk-1]]-'A'+1)<<endl;
        //for(int i=0;i<bk;i++)
        //cout<<i<<". "<<arr[qx[i]][qy[i]]<<endl;
       // cout<<"loc "<<qx[bk-1]<<" "<<qy[bk-1]<<endl;
        }
}
