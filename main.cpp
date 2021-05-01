#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include <unistd.h>
#include<math.h>

#define p printf
#define sc scanf
#define d "%d"
#define c "%c"
#define s "%s"

unsigned int
sleep(unsigned int seconds);

//Public DEFINITION
int fpb(int a, int h);
double enkripRSA(double msg);
double dekripRSA(double ce);
void Lis(int x);
int ambilsaldo(int x);
int Log(char name[],int al);
bool strcmpk(char x[],char y[]);

int fpb(int a, int h){
    int temp;
    while(1)
    {
        temp = a%h;
        if(temp==0)
        return h;
        a = h;
        h = temp;
    }
}

double enkripRSA(double msg){
    double p = 3;
    double q = 7;
    double n=p*q;
    double acount;
    double totient = (p-1)*(q-1);

    double e=2;

    while(e<totient){
    acount = fpb(e,totient);
    if(acount==1)
        break;
    else
        e++;
    }

    double de;

    double k = 2;

    de = (1 + (k*totient))/e;

    double ce = pow(msg,e);
    ce=fmod(ce,n);

    return ce;
}

double dekripRSA(double ce){
    double p = 3;
    double q = 7;
    double n=p*q;
    double acount;
    double totient = (p-1)*(q-1);

    double e=2;

    while(e<totient){
    acount = fpb(e,totient);
    if(acount==1)
        break;
    else
        e++;
    }

    double de;

    double k = 2;

    de = (1 + (k*totient))/e;

    double m = pow(ce,de);
    m=fmod(m,n);

    return m;
}

void Lis(int x){
    if(x==1){
        p("Selamat datang di beranda. Aplikasi ini mensimulasikan enkripsi RSA pada login page.\nPilih menu yang ingin anda pilih (-99 untuk keluar).\n");
        p("1. Buat Rekening\n");
        p("2. Login Rekening\n");
    }
    else{
        p("1. Menarik saldo\n");
        p("2. Mengisi Saldo\n");
    }
}

int ambilsaldo(int x){	
	int y;
	char t='y';
	do{
		system("cls");
		p("Berapa Sekiranya saldo yang anda ingin ambil?\n");
		p("Sisa Saldo anda sekarang adalah %d\n",x);
		sc(d,&y);	
		if(y<=x){
			p("Selamat uang anda berhasil ditarik>.<\n");
			x=x-y;
			p("Saldo anda tersisa %d\n",x);
		}
		else p("Maaf Saldo anda tidak mencukupi untuk melakukan penarikan ini");
		p("Ingin mengambil saldo kembali? [Y/N]\n");
		t=getchar();
	}while(t=='y' or t=='Y');
	return x;
}

int nambahsaldo(int x){
	int y;
	char t='y';
	do{
		system("cls");
		p("Masukkan Nominal Uang yang ingin anda tabung kan = ");
		sc(d,&y);
		if(y==0){
			p("Keinginan anda diCancel(press enter)\n");
			t=getchar();
			return x;
		}
		p("Saldo anda sebesar %d, Anda ingin menabung sebanyak %d\n",x,y);
		p("Anda Yakin dengan keputusan anda? [Y/N]\n");
	}while(t=='y' or t=='Y');
	p("Saldo anda sekarang %d\n",x+y);
	p("Terimakasih telah menggunakan menggunakan jasa penyimpanan kami\n(press Enter)");
	t=getchar();
	return x+y;
}

int Log(char name[],int al){
	char t[100];
    char yyy[100],satu[100],dua[100],outp[100];;
    while(true){
    system("cls");
    p("Selamat Datang %s\n", name);
    p("Saldo Anda tersisa %d\n",al);
    Lis(2);
    p("Ketik 'Logout' untuk logout\n");
    sc(s,&yyy);
    if(strcmp(yyy,satu)) al=ambilsaldo(al);
	else if(strcmp(yyy,dua)) al=nambahsaldo(al);
	else if(strcmp(yyy,outp)) break;
	else p("Menu pilihan yang Anda inginkan tidak tersedia (press Enter)\n");
	sc(s,&t);
	}
    p("Terima kasih telah menggunakan aplikasi ini (under maintenance)\n");
	return al;
}

bool strcmpk(char x[],char y[]){
    for(int i=0;i<100;i++){
        if(x[i]!=y[i]) return 0;
    }
    return 1;
}

int main(){
    int n=0;
    char Data1[100][100],Data2[100][100];
    double Data3[100], Data4[100];
    int saldo[100];
    while(true){
    int a;
    p("Loading...\n");
    sleep(1.5);
    system("cls");
    Lis(1);
    sc(d,&a);
    if(a==1){
        char indenti[100];
        double temp;
        p("Masukkan Nama anda\n");
        sc(s,&indenti);
        for(int i=0;i<sizeof(indenti);i++) Data1[n][i]=indenti[i];
        p("Nomer identitas\n");
        sc(s,&indenti);
        for(int i=0;i<sizeof(indenti);i++) Data2[n][i]=indenti[i];
        p("Masukkan PIN (HARUS 6 DIGIT)\n");
        sc(s, &indenti);
        int as = (((indenti[1]+indenti[3]+indenti[5]-48*3) % 10 ) * 10 + ((indenti[0]+indenti[2]+indenti[4]-48*3) % 10))%21;
        temp = as;
        Data3[n] = enkripRSA(temp);
        p("Terima Kasih anda berhasil Register\n");
        n++;
    }
    else if(a==2){
        char lop[100];
        double pot;
        while(true){
            p("Siapa Nama Anda?(ketik 'keluar' untuk keluar dari login page)\n");
            sc(s,&lop);
            char kel[100] = "keluar";
            if(strcmpk(lop,kel)) break;
            p("PIN = \n");
            char indenti[100];
            sc(s, &indenti);
            bool ex=0;
            int yu;
            for(int i=0;i<n;i++){
                if(strcmpk(Data1[i],lop)==1){
                    double asp = Data3[i];
                    asp = fmod(asp,21);
                    int as = (((indenti[1]+indenti[3]+indenti[5]-48*3) % 10 ) * 10 + ((indenti[0]+indenti[2]+indenti[4]-48*3) % 10))%21;
                    pot = as;
                    if(dekripRSA(asp)==pot){ex=1;yu=i;}
                    else break;
                }
            }
            if(ex){
                saldo[yu]=Log(lop,saldo[yu]);
                return 0;
            }
            else p("PIN anda salah atau anda belum mendaftar\n");
        }
    }
    else p("INPUTAN ANDA TIDAK VALID");
    if(a==-99) break;
    }
}
