#include"quanly.h"
#include<fstream>
#include<iostream>
using namespace std;

quanly::quanly(int length){
    this->length = length;
    this->p = new sinhvien[length];
    for(int i=0;i<length;i++){
        cout<<"=====Nhap thong tin sinh vien "<<i+1<<"===="<<endl;
        (p+i)->Nhap();
    }
}

quanly::quanly(int length, ifstream &in){
    this->length = length;
    this->p = new sinhvien[length];
    for(int i=0;i<length;i++){
        (p+i)->read(in);
    }
}

int quanly::Length(){
    return length;
}

void quanly::Length(int n){
    this->length = n;
}

quanly::~quanly(){
    this->p = 0;
    delete[] p;
}
void quanly::show(){
    for(int i=0;i<this->length;i++){
        (p+i)->Show();
    }
}
void quanly::Insert(const sinhvien &sv, int index){
    this->length++;
    sinhvien *q = new sinhvien[length];
    for(int i = 0;i<length-1;i++){
        *(q+i)=*(p+i);
    }
    for(int i = length - 1;i>index;i--){
        *(q+i) = *(q+i-1);
    }
    *(q+index) = sv;
    delete[] p;
    p = new sinhvien[length];
    for(int i = 0;i<length;i++){
        *(p+i)=*(q+i);
    }
    delete[] q;
}

void quanly::Add(const sinhvien &sv){
    this->Insert(sv, length);
}

int quanly::indexOf(const sinhvien &sv){
    for(int i=0;i<length;i++){
        if((p+i)->getMSSV()==sv.getMSSV()) return i;
    }
    return -1;
}


void quanly::removeAt(int index){
    sinhvien *q = new sinhvien[length];
    for(int i=0;i<length;i++){
        *(q+i)=*(p+i);
    }
    delete[] p;
    for(int i=index;i<length-1;i++){
        *(q+i)=*(q+i+1);
    }
    this->length--;
    sinhvien *p = new sinhvien[length];
    for(int i=0;i<length;i++){
        *(p+i)=*(q+i);
    }
}

void quanly::Remove(const sinhvien &sv){
    for(int i=0;i<length;i++){
        if((p+i)->getMSSV()==sv.getMSSV()) this->removeAt(i);
    }
}

void quanly::Write(ofstream &out){
    out.clear();
    for(int i=0;i<length;i++){
        (p+i)->write(out);
    }
}

void quanly::Update(int msv){
    for(int i =0;i<length;i++){
        if((p+i)->getMSSV()==msv) {
            (p+i)->update();
        }
    }
}