#include <bits/stdc++.h>

using namespace std;

struct Lich{
    int ngay, thang, nam;
    bool calender (Lich lich){
        return this->thang = lich.thang && this->nam = lich.nam;
    }
    Lich(int ngay, int thang, int nam){
        this->ngay = ngay;
        this->thang = thang;
        this->nam = nam;
    }
    friend istream &operator >> (istream& is, Lich& lich){
        cout<<"Nhap ngay: "; is>>lich.ngay;
        cout<<"Nhap thang: "; is>>lich.thang;
        cout<<"Nhap nam: "; is>>lich.nam;
        return is;
    }
    Lich(){}
    friend ostream &operator << (ostream& os, Lich lich){ //Co the dung noi chuoi duoc khong nhi?
        os<<lich.ngay<<"/"
          <<lich.thang<<"/"
          <<lich.nam<<"/";
          return os;
    }
};

Lich base(){
    Lich x(1,1,1);
    return x;
}

class Khach_hang{
    private:
    string ma_khach_hang;
    protected:
    string ho_ten;
    Lich ngay_ra_hoa_don;
    double so_luong_tieu_thu;
    double don_gia;
    public:
    Khach_hang(string ma_khach_hang = " ", string ho_ten = " ", Lich ngay_ra_hoa_don = base(), 
    double so_luong_tieu_thu = 0, double don_gia = 0){
        this->ma_khach_hang = ma_khach_hang;
        this->ho_ten = ho_ten;
        this->ngay_ra_hoa_don = ngay_ra_hoa_don;
        this->so_luong_tieu_thu = so_luong_tieu_thu;
        this->don_gia = don_gia;
    }
    ~Khach_hang(){}
    virtual void nhap(istream& is) = 0;
    virtual void in(ostream& os) = 0;
    friend istream &operator >> (istream &is, Khach_hang &Khach){
        return is;
    }
    friend ostream &operator << (ostream& os, Khach_hang& Khach){
        return os;
    }
};

enum Doi_tuong_khach_hang{
    sinh_hoat = 1,
    kinh_doanh = 2,
    san_xuat = 3
}

class Khach_Viet_Nam : public Khach_hang{
    protect:
    Doi_tuong_khach_hang doiTuong;
    double dinh_muc;
    public:
    Khach_Viet_Nam (string ma_khach = " ", string ho_ten = " ", Lich ngay_ra_hoa_don = base(), double so_luong_tieu_thu = 0, double don_gia = 0,
    Doi_tuong_khach_hang doiTuong = sinh_hoat, double dinh_muc = 0):Khach_hang(ma_khach, ho_ten, ngay_ra_hoa_don, so_luong_tieu_thu, don_gia){
        this -> doiTuong = doiTuong;
        this -> dinh_muc = dinh_muc;
    }
    ~Khach_Viet_Nam(){}
    void nhap(istream& is){
        cout<<"Nhap ma khach hang: "; getline(is, ma_khach);
        cout<<"Nhap ho ten khach hang: "; getline(is, ho_ten);
        cout<<"Nhap ngay thang nam: "; is>>ngay_ra_hoa_don;
        cout<<"Nhap so luong tieu thu: "; is>>so_luong_tieu_thu;
        cout<<"Nhap don gia: "; is>>don_gia;
        cin.ignore();
        cout<<"Nhap doi tuong khach hang: \n";
        cout << "1. Ho gia dinh sinh hoat\n";
        cout << "2. Ho gia dinh kinh doanh\n";
        cout << "3. Ho gia dinh san xuat\n";
			int chon;
			do{
				is >> chon;
			}while(chon != 1 && chon != 2 && chon != 3);
			doiTuong = (DoiTuongKhachHang)chon;
		}

        void in(ostream& os){
            os<<ma_khach
            <<ho_ten
            <<ngay_ra_hoa_don
            <<so_luong_tieu_thu
            <<don_gia
            
        }
};







int main(){


    system("pause");
    return 0;
}