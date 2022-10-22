#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class sinhvien {
    private:
        int mssv;
        string ten;
        string lop;
    public:
        sinhvien(){
        }
        sinhvien(int mssv, string ten, string lop){
            this->mssv = mssv;
            this->ten = ten;
            this->lop = lop;
        }
        void setMSSV(int msv){
            this->mssv = msv;
        }
        void Show(){
            cout<<this->ten<<" "<<this->mssv<<" "<<this->lop<<endl;
        }
        void Nhap(){
            cout<<"Nhap ma sinh vien: ";
            cin>>this->mssv;
            cout<<"Nhap ten sv: ";
            fflush(stdin);
            getline(cin, this->ten);
            cout<<"Nhap lop cua sv: ";
            fflush(stdin);
            getline(cin,this->lop);
        }
        int getMSSV() const{
            return mssv;
        }
        void read(ifstream &ifs){
            ifs >> this->mssv;
            string ss;
            getline(ifs, ss);
            getline(ifs,this->ten);
            getline(ifs,this->lop);
        }
        void update(){
            cout<<"Nhap lai ten: ";
            fflush(stdin);
            getline(cin,this->ten);
            cout<<"Nhap lai lop: ";
            fflush(stdin);
            getline(cin,this->lop);
        }
        void write(ofstream &out){
            out<<this->ten<<" - "<<this->mssv<<" - "<<this->lop<<endl;
        }
        ~sinhvien(){}
};