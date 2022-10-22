#include<iostream>
#include<fstream>
#include"quanly.h"

using namespace std;

int main(){
    ifstream ifs("Data.txt",ios::in);
    int n;
    ifs>>n;
    // cout<<"Nhap so luong sinh vien: ";
    // cin>>n;
    quanly ql(n,ifs);
    ifs.close();
    sinhvien sv(102212155,"Nguyen Van A","21NHAT2");
    ql.Insert(sv,1);
    ql.Add(sv);
    cout<<"====Cap Nhat lai thong tin sinh vien===="<<endl;
    ql.Update(102210369);
    ql.show();
    //cout<<"Vi tri: "<<ql.indexOf(sv)<<endl;
    // ql.removeAt(2);
    // ql.Remove(sv);
    // ql.show();
    ofstream fileOut("OutPut.txt",ios::out);
    ql.Write(fileOut);
    fileOut.close();
    return 0;
}