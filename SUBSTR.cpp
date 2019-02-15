#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
char A[5001],B[5001];
int T[5001][5001];
int m,n,i,j;
int main()
{
    ifstream fin("SUBSTR.INP");
    ofstream fout("SUBSTR.OUT");
    fin.getline(A,5001);
    fin.getline(B,5001);
    m=strlen(A);
    n=strlen(B);
    /*>Khởi tạo cơ sở cho Quy Hoạch Động<*/
    for(i=1;i<=n;i++) T[i][n]=0;
    for(j=1;j<=m;j++) T[m][j]=0;
    /*>Tạo bảng phương án<*/
    for(i=m-1;i>=0;i--)
        for(j=n-1;j>=0;j--)
        if(A[i]==B[j]) T[i][j]=T[i+1][j+1]+1;
            else T[i][j]=max(T[i][j+1],T[i+1][j]);
    /*>In nghiệm<*/
    fout<<T[0][0]<<'\n';
    /*>Truy vét tìm ra các kí tự chung, chính là xâu con chung dài nhất<*/
    i=0;
    j=0;
    while(i<=m-1&&j<=n-1)
    if(A[i]==B[j])
    {
        fout<<A[i];
        i++;
        j++;
    }
    else
        T[i+1][j]>T[i][j+1]?i++:j++;
    fin.close();
    fout.close();
    return 0;
}
