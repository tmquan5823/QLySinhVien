#include"sinhvien.h"

class quanly{
    private:
        sinhvien *p;
        int length;
    public:
        quanly(int length);
        quanly(int length, ifstream&);
        int Length();
        void Length(int);
        void Insert(const sinhvien&, int);
        void Add(const sinhvien&);
        int indexOf(const sinhvien&);
        void removeAt(int);
        void Remove(const sinhvien&);
        void Update(int);
        void Write(ofstream&);
        void show();
        ~quanly();
};