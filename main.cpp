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
#define PRIME1 11
#define PRIME2 13

unsigned int
sleep(unsigned int seconds);

//Public DEFINITION
long long ffpbb(long long x, long long y);
long long pangkatmod(long long a, long long b, long long ci);
long long gotdekripsi(long long x);
long long gotenkripsi(long long a);
bool cekprimes(long long x);
long long pangkatmin1(long long a, long long b, long long *x, long long *y);
int fpb(int a, int h);
double enkripRSA(double msg);
double dekripRSA(double ce);
void Lis(int x);
void Efek();
int ambilsaldo(int x);
int Log(char name[],int al);
void laz();

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
    char yyy[100],satu[100],dua[100],outp[100];
    strcpy(satu,"1");
    strcpy(satu,"2");
    strcpy(satu,"Logout");
    while(true){
    system("cls");
    p("Selamat Datang %s\n", name);
    p("Saldo Anda tersisa %d\n",al);
    Lis(2);
    p("Ketik 'Logout' untuk logout\n");
    sc(s,&yyy);
    if(strcmp(yyy,satu)==0) al=ambilsaldo(al);
	else if(strcmp(yyy,dua)==0) al=nambahsaldo(al);
	else if(strcmp(yyy,outp)==0) break;
	else p("Menu pilihan yang Anda inginkan tidak tersedia (press Enter)\n");
	sc(s,&t);
	}
    p("Terima kasih telah menggunakan aplikasi ini (under maintenance)\n");
	return al;
}

int main(){
	long long ree=54;
	p(d,gotenkripsi(ree));
	p("\n");
	p(d,gotdekripsi(gotenkripsi(ree)));
	p("\n");
	return 0; //My Flags
    int n=0;
    char Data1[100][100],Data2[100][100];
    double Data3[100], Data4[100];
    long long DataSa[100][6];
    int saldo[100];
    //Efek();
    while(true){
    int a;
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
        //int as = (((indenti[1]+indenti[3]+indenti[5]-48*3) % 10 ) * 10 + ((indenti[0]+indenti[2]+indenti[4]-48*3) % 10))%21;
        //temp = as;
        //Data3[n] = enkripRSA(temp);
        for(int i=0;i<6;i++) DataSa[n][i]=gotenkripsi(int(indenti[i]));
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
            if(strcmp(lop,kel)) break;
            p("PIN = \n");
            char indenti[100];
            sc(s, &indenti);
            bool ex=0;
            int yu;
            for(int i=0;i<n;i++){
                if(strcmp(Data1[i],lop)==0){
                    //double asp = Data3[i];
                    //asp = fmod(asp,21);
                    //int as = (((indenti[1]+indenti[3]+indenti[5]-48*3) % 10 ) * 10 + ((indenti[0]+indenti[2]+indenti[4]-48*3) % 10))%21;
                    //pot = as;
                    bool chop=0;
                    for(int j=0;j<6;j++){
						if(gotdekripsi(DataSa[i][j])!=int(indenti[j])){
							chop=true;
							break;
						} 
					} 
                	if(chop==false){p("Lah WKWKWKWKWK\n");ex=1;yu=i;}
                	else{p("Idont Know eerything\n");break;}
                    //if(dekripRSA(asp)==pot){ex=1;yu=i;}
                    //else break;
                }
            }
            if(ex){
                saldo[yu]=Log(lop,saldo[yu]);
                return 0;
            }
            else p("PIN anda salah atau anda belum mendaftar\n");
        }
    }
    else if(a==-99){
		break;
    }
    else{ 
		p("INPUTAN ANDA TIDAK VALID");
	}
	//laz();
	}
}

long long ffpbb(long long x, long long y){
	if(y==0) return x;
	else return ffpbb(y,x%y);
}
 
long long pangkatmin1(long long a, long long b, long long *x, long long *y) {
   if (a == 0) {
      *x = 0;
      *y = 1;
      return b;
   }
   long long x1, y1;
   long long gcd = pangkatmin1(b%a, a, &x1, &y1);
   *x = y1 - (b/a) * x1;
   *y = x1;
   return gcd;
} 
 
long long pangkatmod(long long a, long long b, long long ci){
	if(b==0) return 1;
	else {
		long long dc=pangkatmod(a,b/2,ci)%ci;
		dc=(dc*dc)%ci;
		if(b&1) return (dc*a)%ci;
		else return dc;
		
	}
}

bool cekprimes(long long x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return 0;
	}
	return 1;
}

long long gotenkripsi(long long a){
	long long x,y,z;
	x=PRIME1;
	y=PRIME2;
	long long h=(x-1)*(y-1);
	long long bagi=x*y;
	long long hex=h+1;
	while(!cekprimes(hex) or ffpbb(hex,h)!=1) hex++;
	//p("%d dek %d\n",hex,bagi);
	//int yu=a;
	//for(int i=0;i<hex;i++) yu=yu*a;
	//p("%d frea \n",yu);
	return pangkatmod(a,hex,bagi);
}

long long gotdekripsi(long long a){
	long long x,y,z;
	x=PRIME1;
	y=PRIME2;
	long long h=(x-1)*(y-1);
	long long bagi=x*y;
	long long hex=h+1;
	while(!cekprimes(hex) or ffpbb(hex,h)!=1) hex++;
	long long mo,mp;
	long long hum=pangkatmin1(hex,h,&mo,&mp);
	mo=(mo+h)%h;
	//p("%d\n",hex);
	//p("%d\n",mo);
	//p("%d\n",bagi);
	return pangkatmod(a,mo,bagi);
}

void Efek(){
	p("Loading .");
	sleep(1.0);
	p(" .");
	sleep(1.0);
	p(" .");
	sleep(1.0);
	system("cls");
	p("Loading .");
	sleep(1.0);
	p(" .");
	sleep(1.0);
	p(" .");
	sleep(1.0);
}

void laz(){
	p("Loading .");
		sleep(1.0);
		p(" .");
		sleep(1.0);
		p(" .");
		sleep(1.0);
		system("cls");
}
