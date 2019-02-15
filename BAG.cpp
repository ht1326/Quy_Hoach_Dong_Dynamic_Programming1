#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int W[1001],V[1001],A[1001],T[1001][1001];
int n,m,k,i,j;
int main()
{
    ifstream fin("BAG.INP");
    ofstream fout("BAG.OUT");
    fin>>n>>m;
    for(i=1;i<=n;i++) fin>>W[i]>>V[i];
    /*>Khởi tạo cơ sở cho Quy Hoạch Động<*/
    for(i=1;i<=n;i++) T[i][0]=0;
    for(j=1;j<=m;j++) T[0][j]=0;
    /*>Tạo bảng phương án<*/
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    if(j<W[i]) T[i][j]=T[i-1][j];
    else
        T[i][j]=max(T[i-1][j-W[i]]+V[i],T[i-1][j]);
    /*>In nghiệm<*/
    fout<<T[n][m]<<'\n';
    /*>Truy vét tìm lại các gói hàng<*/
    i=n;
    j=m;
    k=0;
    while(i!=0)
    {
        if(T[i][j]!=T[i-1][j])
        {
            k++;
            A[k]=i;
            j-=W[i];
        }
        i--;
    }
    for(i=k;i>=1;i--) fout<<A[i]<<' ';
    fin.close();
    fout.close();
    return 0;
}
