#include <iostream>
#include <fstream>
using namespace std;
int a[5001],T[5001],Sau[5001];
int n,m,MAXL,k,i,j;
int main()
{
    ifstream fin("INCSEQ.INP");
    ofstream fout("INCSEQ.OUT");
    fin>>n;
    for(i=1;i<=n;i++) fin>>a[i];
    /*>Tạo bảng phương án, tìm ra độ dài T[i] dài nhất và vị trí của nó<*/
    MAXL=1;
    for(i=n;i>=1;i--)
      {
        m=0;
        for(j=n;j>=i;j--)
            if(a[j]>a[i]&&T[j]>m)
            {
                m=T[j];
                Sau[i]=j;
            }
        T[i]=1+m;
        T[i]>MAXL?MAXL=T[i],k=i:0;
    }
    /*>In nghiệm<*/
    fout<<MAXL<<'\n';
    /*>Truy vét tìm lại các số trong đoạn tăng dài nhất<*/
    do
    {
        fout<<k<<' '<<a[k]<<'\n';
        k=Sau[k];
    } while (k!=0);
    fin.close();
    fout.close();
    return 0;
}
