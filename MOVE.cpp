#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int a[5003][5003];
int m,n,tmp,MAX,x,i,j;
int main()
{
    ifstream fin("MOVE.INP");
    ofstream fout("MOVE.OUT");
    fin>>m>>n;
    for(i=1;i<=m;i++)
      for(j=1;j<=n;j++) fin>>a[i][j];
    /*>Tạo bảng phương án<*/
    for(j=n-1;j>=1;j--)
      for(i=1;i<=m;i++)
    {
        tmp=a[i][j+1];
        if(i>1&&a[i-1][j+1]>tmp) tmp=a[i-1][j+1];
        if(i<m&&a[i+1][j+1]>tmp) tmp=a[i+1][j+1];
        a[i][j]+=tmp;
    }
    /*>Tìm con đường đi có giá trị lớn nhất<*/
    MAX=a[1][1];
    x=1;
    for(i=2;i<=m;i++)
    if(MAX<a[i][1])
    {
        MAX=a[i][1];
        x=i;
    }
    /*>In nghiệm<*/
    fout<<MAX<<'\n'<<i<<' ';
    /*>Truy vét tìm lại các ô của con đường<*/
    i=x;
    for(j=2;j<=n;j++)
    {
        x=i;
        if(i>1&&a[i-1][j]>a[i][j]) x=i-1;
        if(i<m&&a[i+1][j]>a[i][j]) x=i+1;
        i=x;
        fout<<i<<' ';
    }
    fin.close();
    fout.close();
    return 0;
}
