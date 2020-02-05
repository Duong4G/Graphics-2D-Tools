/* 
graphics in Dev-C++ - nguyenvanquan7826 
*/

#include <winbgim.h> 
#include <iostream>
#include <Math.h>
#include <mylib.h>
#include <conio.h>
#define PI 3.14159265

void Normal () {
	SetColor(15);
	SetBGColor(0);
}
void HighLight () {
	SetColor(15);
	SetBGColor(2);
}

using namespace std;
// Tao menu lenh
const int so_item1 = 8;
const int so_item2 = 6;
const int Up = 72;
const int Down = 80;

char thucdon1 [so_item1][50] = {"1. Ve DDA                ",
			                   "2. Ve bresenham          ",
			                   "3. Ve duong tron         ",
			                   "4. Ve da giac            ",
			                   "5. Cac phep bien doi     ",
			                   "6. Ve hinh               ",
			                   "7. Xoa mang hinh         ",
			                   "8.Ket thuc chuong trinh  "};

char thucdon2 [so_item2][50] = {"1.Tinh tien                ",
							   "2.Quay quanh diem bat ky   ",
							   "3.Ty le                    ",
							   "4.Doi xung qua goc toa do  ",
							   "5.Bo phep bien doi gan nhat",
							   "6.Thoat                    "};


int MenuDong(char td [][50],int item,int dong,int cot,int a){
  Normal();
  if(a==1) system("cls");
  int chon =0;
  int i,x,y; 
  for ( i=0; i< item ; i++)
  { gotoxy(cot, dong +i);
    cout << td[i];
  }
  HighLight();
  gotoxy(cot,dong+chon);
  cout << td[chon];
  char kytu;
do {
  kytu = getch();
  if (kytu==224) kytu = getch();
  switch (kytu) {
    case Up :if (chon >0)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon);cout << td[chon];
              	chon --;
              	HighLight();
              	gotoxy(cot,dong+chon); 	cout << td[chon];  				
  			  }
  			  else if(chon==0){
  			  	Normal();
  			  	gotoxy(cot,dong+chon);cout<< td[chon];
  			  	chon = item-1;
  			  	HighLight();
  			  	gotoxy(cot,dong+chon);cout<< td[chon]; 
				}
  			  break;
  	case Down :if (chon+1 <item)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon);	cout << td[chon];
              	chon ++;
              	HighLight();
              	gotoxy(cot,dong+chon); 	cout << td[chon];
  				
  			  }
  			  else if (chon+1==item){
  			  	Normal();
              	gotoxy(cot,dong+chon);	cout << td[chon];
              	chon = 0;
              	HighLight();
              	gotoxy(cot,dong+chon); 	cout << td[chon];
			}
  			  break;
  	case 13 : return chon+1;
  }  // end switch
  } while (1);
}

const int MAXX = 620;
const int MAXY = 480;

int Getx(int x){
	return (x - MAXX/2);
}
int Gety(int y){
	return (MAXY/2 - y);
}
void tructoado(){
	line(MAXX/2,0,MAXX/2,MAXY);
	line(0,MAXY/2,MAXX,MAXY/2);
}
int GetX(int x){
	return (MAXX/2 + x);
}
int GetY(int y){
	return (MAXY/2 - y);
}
void put8Pixel(int x, int y,int c,int a=0,int b=0){
	putpixel(GetX(x+a),GetY(y+b),c);
	putpixel(GetX(y+a),GetY(x+b),c);
	putpixel(GetX(y+a),GetY(-x+b),c);
	putpixel(GetX(x+a),GetY(-y+b),c);
	putpixel(GetX(-x+a),GetY(-y+b),c);
	putpixel(GetX(-y+a),GetY(-x+b),c);
	putpixel(GetX(-y+a),GetY(x+b),c);
	putpixel(GetX(-x+a),GetY(y+b),c);
}
void Bresenham(int x1,int y1,int x2,int y2){
	x1 = Getx(x1); x2 = Getx(x2); y1 = Gety(y1); y2 = Gety(y2);
	int deltaX,deltaY,p,t1,t2,x,y;
	double m;
	deltaX = x2 - x1;
	deltaY = y2 - y1;
	m = 1.0*deltaY/deltaX;
	
	x = x1;
	y = y1;
	putpixel(GetX(x),GetY(y),15);
	// x2 = x1
	if(deltaX==0){
		if(deltaY>0){
			while(y<y2){
				y = y + 1;
				putpixel(GetX(x),GetY(y),15);
			}	
		}else if(deltaY<0){
			while(y>y2){
				y = y - 1;
				putpixel(GetX(x),GetY(y),15);
			}
		}
	}
	// Tinh theo x
	// 0<m<=1     -1=<m<0
	if(m>=0&& m<=1){
		p = 2*deltaY - deltaX;
		t1 = 2*deltaY;
		t2 = 2*(deltaY - deltaX);
		if(deltaX>0){
			while(x<x2){
				if(p<0) p+=t1;
				else{
					p+=t2; y+=1;
				} 
				x+=1;
				putpixel(GetX(x),GetY(y),15);
			}
		}else if(deltaX<0){
			while(x>x2){
				if(p<0){
					p+=t2; y-=1;
				}else p+=t1;
				x-=1;
				putpixel(GetX(x),GetY(y),15);
			}
		}
	}
	if(m<0&& m>=-1){
		p = 2*deltaY + deltaX;
		t1 = 2*deltaY;
		t2 = 2*(deltaY + deltaX);
		if(deltaX>0){
			while(x<x2){
				if(p<0){
					y-=1;
					p+=t2;
				} 
				else
					p+=t1;
				
				x+=1;
				putpixel(GetX(x),GetY(y),15);
			}
		}else if(deltaX<0){
			while(x>x2){
				if(p<0)
					p+=t1;
				else{
					p+=t2;
					y+=1;
				}
				x-=1;
				putpixel(GetX(x),GetY(y),15);
			}
		}	
	}
	//Tinh theo y
	// m>1    m<-1
	if(m>1){
		p = 2*deltaX - deltaY;
		t1 = 2*deltaX;
		t2 = 2*(deltaX - deltaY);
		if(deltaX>0){
			while(y<y2){
				if(p<0) p+=t1;
				else{
					p+=t2;
					x+=1;
				}
				y+=1;
				putpixel(GetX(x),GetY(y),15);
			}
		}else if(deltaX<0){
			while(y>y2){
				if(p<0){
					p+=t2;
					x-=1;
				}else p+=t1;
				y-=1;
				putpixel(GetX(x),GetY(y),15);
			}
		}
	}
	if(m<-1){
		p = -2*deltaX - deltaY;
		t1 = -2*deltaX;
		t2 = -2*(deltaX + deltaY);
		if(deltaX>0){
			while(y>y2){
				if(p<0){
					p+=t2;
					x+=1;
				}
				else{
					p+=t1;
				}
				y-=1;
				putpixel(GetX(x),GetY(y),15);
			}
		}else if(deltaX<0){
			while(y<y2){
				if(p<0) p+=t1;
				else{
					p+=t2;
					x-=1;
				}
				y+=1;
				putpixel(GetX(x),GetY(y),15);
			}
		}
	}
	
}
void DDA(int x1,int y1, int x2, int y2){
	x1 = Getx(x1); x2 = Getx(x2); y1 = Gety(y1); y2 = Gety(y2);
	double deltaX,deltaY,m,y,x;
	deltaX = x2 - x1;
	deltaY = y2 - y1;
	m = deltaY/deltaX;
	
	x = x1;
	y = y1;
	putpixel(GetX(x),GetY(round(y)),15);
	
	// x2 = x1
	if(deltaX==0){
		if(deltaY>0){
			while(y<y2){
				y = y + 1;
				putpixel(GetX(x),GetY(round(y)),15);
			}	
		}else if(deltaY<0){
			while(y>y2){
				y = y - 1;
				putpixel(GetX(x),GetY(round(y)),15);
			}
		}
	}
	// Tinh theo x
	// 0<m<=1     -1=<m<0    
	if(m>=0&& m<=1){
		if(deltaX>0){
			while(x<x2){
				x = x + 1;
				y = y + m;
				putpixel(GetX(x),GetY(round(y)),15);
			}
		}else if(deltaX<0){
			while(x>x2){
				x = x - 1;
				y = y - m;
				putpixel(GetX(x),GetY(round(y)),15);
			}
		}
	}
	if(m<0&& m>=-1){
		if(deltaX>0){
			while(x<x2){
				x = x +1;
				y = y + m;
				putpixel(GetX(x),GetY(round(y)),15);
			}
		}else if(deltaX<0){
			while(x>x2){
				x = x -1;
				y = y - m;
				putpixel(GetX(x),GetY(round(y)),15);
			}
		}	
	}
			
	//Tinh theo y
	// m>1    m<-1
	if(m>=1){
		if(deltaX>0){
			while(y<y2){
				y = y + 1;
				x = x + 1/m;
				putpixel(GetX(round(x)),GetY(y),15);
			}
		}else if(deltaX<0){
			while(y>y2){
				y = y - 1;
				x = x - 1/m;
				putpixel(GetX(round(x)),GetY(y),15);
			}
		}
	}
	if(m<-1){
		if(deltaX>0){
			while(y>y2){
				y = y - 1;
				x = x - 1/m;
				putpixel(GetX(round(x)),GetY(y),15);
			}
		}else if(deltaX<0){
			while(y<y2){
				y = y + 1;
				x = x + 1/m;
				putpixel(GetX(round(x)),GetY(y),15);
			}
		}
	}
}
void duongTron(int x1,int y1,int x2,int y2){
	x1 = Getx(x1); x2 = Getx(x2); y1 = Gety(y1); y2 = Gety(y2);
	float r = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	int x,y;float p;
	p = 3 - 2*r;
	x = 0; y = r;
	putpixel(GetX(x1),GetY(y1),15);
	put8Pixel(x,y,15,x1,y1);
	while(x<y){
		if(p<0) p= p + 4*x + 6;
		else{
			p = p + 4*(x-y) + 10;
			y--;
		}
		x++;
		put8Pixel(x,y,15,x1,y1);
	}
}
void veDaGiac(int* A, int* B,int n){
	for(int i=0;i<n-1;i++){
        Bresenham(A[i],B[i],A[i+1],B[i+1]);
	}
	Bresenham(A[0],B[0],A[n-1],B[n-1]);
}
class MATRIX{
      int ROW,COL;
      float **M;
      public:
             MATRIX (int row, int col);
             ~MATRIX();
             void PutMatrix(int a,int b);
             float& operator() (int i, int j);
             MATRIX& operator* (MATRIX& m);
             MATRIX& operator= (MATRIX& B);
};
MATRIX::MATRIX(int row=3, int col=3){
                   ROW = row;
                   COL = col;
                   if(ROW*COL > 0) {
                              M = new float* [ROW];
                              for(int i=0;i<ROW;i++) M[i] = new float [COL];
                   }
}
MATRIX::~MATRIX(){
                  for(int i=0;i<ROW;i++) delete M[i];
                  delete M;
}
float& MATRIX::operator() (int i, int j){
                   return (M[i][j]);
}
void MATRIX::PutMatrix(int a,int b){
	int x=a,y=b;
	gotoxy(x,y);
	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			cout<<M[i][j];
			gotoxy(x+=17,y);
		}
		x = 40;
		gotoxy(x,y+=4);
	}
}
MATRIX& MATRIX::operator= (MATRIX& B){
        ROW = B.ROW;
        COL = B.COL;
        for(int i=0;i<ROW;i++){
               for(int j=0;j<COL;j++){
                       M[i][j] = B.M[i][j];   
               }
        }   
        return *this;
}
MATRIX& MATRIX::operator* (MATRIX& m){
        if(COL != m.ROW){
               static MATRIX m2(0,0);
               return m2;
        }
        static MATRIX m1(ROW,m.COL);
        for(int i=0;i<ROW;i++){
               for(int j=0;j<m.COL;j++){
                       m1.M[i][j]=0;   
                       for(int d=0;d<m.ROW;d++){
                               m1.M[i][j] += M[i][d]*m.M[d][j];
                       }
               }
        }   
        return m1;
}
class STACK{
	private:
		int sp,n;
		MATRIX* v;
	public:
		STACK(int N){
			n = N;
			sp = -1;
			v = new MATRIX[n];
		}
		int Empty(){
			if(sp == -1) return 1;
			return 0;
		}
		int Full(){
			if(sp == n - 1) return 1;
			return 0;
		}
		int Push(MATRIX& t){
			if(Full()) return 0;
			v[++sp] = t;
			return 1;
		}
		int Pop(MATRIX& t){
			if(Empty()) return 0;
			t = v[sp--];
			return 1;
		}
		int GetSoPhanTu(){
			return (sp);
		}
};
void BienDoiDiem(int &x,int &y,MATRIX& m){
	MATRIX m1(3,3); m1(0,0) = x; m1(0,1) = y; m1(0,2) = 1;
	m1 = m1 * m;
	x = m1(0,0); y = m1(0,1);
}
void ShowMaTran(int A[3][3]){
	int x=40,y=16;
	gotoxy(x,y);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<A[i][j];
			gotoxy(x+=5,y);
		}
		x = 40;
		gotoxy(x,y+=2);
	}
}
void Lammoi(){
	int x = 40, y =12; Normal();
	while(y<30){
		gotoxy(x,y++); cout<<"                                         ";
	}
}
const int SOLUONG = 20;

using namespace std;

int main(int argc, char *argv[])
{
	// now, you can run project
	initwindow(MAXX, MAXY);			// init window graphics
	setbkcolor(0);					// set background
   	cleardevice();
	setcolor(15);					// set text color
	
	int* mangX; int* mangY;
	int k,loai=0;
	int a,b,chon1,chon2;
	
	MATRIX MaTranBienDoi(3,3);
	MATRIX MaTranDonVi(3,3);
	MaTranDonVi(0,0) = 1;MaTranDonVi(0,1) = 0;MaTranDonVi(0,2) = 0;
	MaTranDonVi(1,0) = 0;MaTranDonVi(1,1) = 1;MaTranDonVi(1,2) = 0;
	MaTranDonVi(2,0) = 0;MaTranDonVi(2,1) = 0;MaTranDonVi(2,2) = 1;
	
	MATRIX MaTranTam1(3,3);
	MATRIX MaTranTam2(3,3);
	MaTranTam1 = MaTranDonVi;
	int tx,ty; int x,y,tamx,tamy; float sx,sy;
	double alpha,val=PI/180;
	
	while(1){
	chon1 = MenuDong(thucdon1,so_item1,1,5,1);
	if(chon1==1){
		mangX = new int[SOLUONG];
		mangY = new int[SOLUONG];
		k = 0; loai = 1;
		while(1){
			delay(0.001);
			tructoado();
			if(ismouseclick(WM_LBUTTONDOWN)){
				getmouseclick(WM_LBUTTONDOWN,mangX[k],mangY[k]);
				putpixel(mangX[k],mangY[k],15);
				k++;
				if(k==2){
					DDA(mangX[0],mangY[0],mangX[1],mangY[1]);
					k=0;
				}
			}
			if (ismouseclick(WM_RBUTTONDOWN)){
            	clearmouseclick(WM_RBUTTONDOWN);
            	break;
        	}
		} 	
	}
	if(chon1==2){
		mangX = new int[SOLUONG];
		mangY = new int[SOLUONG];
		k = 0; loai = 1;
		while(1){
			delay(0.001);
			tructoado();
			if(ismouseclick(WM_LBUTTONDOWN)){
				getmouseclick(WM_LBUTTONDOWN,mangX[k],mangY[k]);
				putpixel(mangX[k],mangY[k],15);
				k++;
				if(k==2){
					Bresenham(mangX[0],mangY[0],mangX[1],mangY[1]);
					k=0;
				}
			}
			if (ismouseclick(WM_RBUTTONDOWN)){
            	clearmouseclick(WM_RBUTTONDOWN);
            	break;
        	}
		} 	
	}
	if(chon1==3){
		mangX = new int[SOLUONG];
		mangY = new int[SOLUONG];
		k = 0; loai = 2;
		while(1){
			delay(0.001);
			tructoado();
			if(ismouseclick(WM_LBUTTONDOWN)){
				getmouseclick(WM_LBUTTONDOWN,mangX[k],mangY[k]);
				putpixel(mangX[k],mangY[k],15);
				k++;
				if(k==2){
					duongTron(mangX[0],mangY[0],mangX[1],mangY[1]);
					k=0;
				}
			}
			if (ismouseclick(WM_RBUTTONDOWN)){
            	clearmouseclick(WM_RBUTTONDOWN);
           	 break;
        	}
		} 
	}
	if(chon1==4){
		mangX = new int[SOLUONG];
		mangY = new int[SOLUONG];
		k = 0; loai = 3;
		while(1){
			delay(0.001);
			tructoado();
			if(ismouseclick(WM_LBUTTONDOWN)){
				getmouseclick(WM_LBUTTONDOWN,mangX[k],mangY[k]);
				putpixel(mangX[k],mangY[k],15);
				k++;
			}
			if (ismouseclick(WM_RBUTTONDOWN)){
            	clearmouseclick(WM_RBUTTONDOWN);
            	veDaGiac(mangX,mangY,k);
            	break;
        	}
		} 
	}
	if(chon1==5){
		STACK stack(30);
		stack.Push(MaTranDonVi);stack.Push(MaTranDonVi);
		while(1){
			if(loai==0){
				gotoxy(5,10);Normal(); cout<<"Ban phai ve hinh truoc!"; char c = getch();
				break;
			} 
			chon2 = MenuDong(thucdon2,so_item2,5,40,0);
			Normal();
			if(chon2==1){
				Lammoi();
				x = 40; y = 12;
				gotoxy(x,y++);
				cout<<"Nhap do doi x: "; cin>>tx;
				gotoxy(x,y++);
				cout<<"Nhap do doi y: "; cin>>ty;
				MaTranBienDoi(0,0) = 1;  MaTranBienDoi(0,1) = 0  ; MaTranBienDoi(0,2) = 0;
				MaTranBienDoi(1,0) = 0;  MaTranBienDoi(1,1) = 1  ; MaTranBienDoi(1,2) = 0;
				MaTranBienDoi(2,0) = tx; MaTranBienDoi(2,1) = ty ; MaTranBienDoi(2,2) = 1;
				stack.Pop(MaTranTam1);
				MaTranBienDoi = MaTranTam1*MaTranBienDoi;
				stack.Push(MaTranBienDoi);stack.Push(MaTranBienDoi);
				MaTranBienDoi.PutMatrix(40,17);
							
			}
			if(chon2==2){
				Lammoi();
				x = 40; y = 12;
				gotoxy(x,y++);
				cout<<"Nhap tam quay x: "; cin>>tamx;
				gotoxy(x,y++);
				cout<<"Nhap tam quay y: "; cin>>tamy;
				gotoxy(x,y++);
				cout<<"Nhap goc quay: "; cin>>alpha;
				MaTranTam1(0,0) = 1  ;MaTranTam1(0,1) = 0   ;MaTranTam1(0,2) = 0;
				MaTranTam1(1,0) = 0  ;MaTranTam1(1,1) = 1   ;MaTranTam1(1,2) = 0;
				MaTranTam1(2,0) =tamx;MaTranTam1(2,1) = tamy;MaTranTam1(2,2) = 1;
				
				MaTranTam2(0,0) = cos(alpha*val)   ;  MaTranTam2(0,1) = sin(alpha*val)  ; MaTranTam2(0,2) = 0;
				MaTranTam2(1,0) = sin(alpha*val)*-1;  MaTranTam2(1,1) = cos(alpha*val)  ; MaTranTam2(1,2) = 0;
				MaTranTam2(2,0) = 0                ;  MaTranTam2(2,1) = 0               ; MaTranTam2(2,2) = 1;
				
				MaTranTam1 = MaTranTam1 * MaTranTam2;
				
				MaTranTam2(0,0) = 1    ;MaTranTam2(0,1) = 0    ;MaTranTam2(0,2) = 0;
				MaTranTam2(1,0) = 0    ;MaTranTam2(1,1) = 1    ;MaTranTam2(1,2) = 0;
				MaTranTam2(2,0) = -tamx;MaTranTam2(2,1) = -tamy;MaTranTam2(2,2) = 1;
				
				MaTranTam2 = MaTranTam2 * MaTranTam1;
				stack.Pop(MaTranTam1);
				
				MaTranBienDoi = MaTranTam1 * MaTranTam2;
				stack.Push(MaTranBienDoi);stack.Push(MaTranBienDoi);
				MaTranBienDoi.PutMatrix(40,20);
			}
			if(chon2==3){
				Lammoi();
				x = 40; y = 12;
				gotoxy(x,y++);
				cout<<"Nhap do bien doi x: "; cin>>sx;
				gotoxy(x,y++);
				cout<<"Nhap do bien doi y: "; cin>>sy;
				MaTranBienDoi(0,0) = sx;  MaTranBienDoi(0,1) = 0  ; MaTranBienDoi(0,2) = 0;
				MaTranBienDoi(1,0) = 0 ;  MaTranBienDoi(1,1) = sy ; MaTranBienDoi(1,2) = 0;
				MaTranBienDoi(2,0) = 0 ;  MaTranBienDoi(2,1) = 0  ; MaTranBienDoi(2,2) = 1;
				stack.Pop(MaTranTam1);
				MaTranBienDoi = MaTranTam1*MaTranBienDoi;
				stack.Push(MaTranBienDoi);stack.Push(MaTranBienDoi);
				MaTranBienDoi.PutMatrix(40,17);
				
			}
			if(chon2==4){
				Lammoi();
				x = 40; y = 12;
				MaTranBienDoi(0,0) = -1;  MaTranBienDoi(0,1) = 0  ; MaTranBienDoi(0,2) = 0;
				MaTranBienDoi(1,0) = 0 ;  MaTranBienDoi(1,1) = -1 ; MaTranBienDoi(1,2) = 0;
				MaTranBienDoi(2,0) = 0 ; MaTranBienDoi(2,1) = 0   ; MaTranBienDoi(2,2) = 1;
				stack.Pop(MaTranTam1);
				MaTranBienDoi = MaTranBienDoi * MaTranTam1;
				stack.Push(MaTranBienDoi);stack.Push(MaTranBienDoi);
				MaTranBienDoi.PutMatrix(40,17);
			}
			if(chon2==5){
				Lammoi();
				stack.Pop(MaTranTam2);stack.Pop(MaTranTam2);
				stack.Pop(MaTranTam1);
				MaTranBienDoi = MaTranTam1;
				stack.Push(MaTranBienDoi);stack.Push(MaTranBienDoi);
				MaTranBienDoi.PutMatrix(40,17);
			}
			if(chon2==6){
				if(loai==1){
					mangX[0] = Getx(mangX[0]); mangY[0] = Gety(mangY[0]);
					mangX[1] = Getx(mangX[1]); mangY[1] = Gety(mangY[1]);
					BienDoiDiem(mangX[0],mangY[0],MaTranBienDoi);
					BienDoiDiem(mangX[1],mangY[1],MaTranBienDoi);
				}
				if(loai==2){
					mangX[0] = Getx(mangX[0]); mangY[0] = Gety(mangY[0]);
					mangX[1] = Getx(mangX[1]); mangY[1] = Gety(mangY[1]);
					BienDoiDiem(mangX[0],mangY[0],MaTranBienDoi);
					BienDoiDiem(mangX[1],mangY[1],MaTranBienDoi);
				}
				if(loai==3){
					for(int i=0;i<k;i++){
						mangX[i] = Getx(mangX[i]);
						mangY[i] = Gety(mangY[i]);
						BienDoiDiem(mangX[i],mangY[i],MaTranBienDoi);
					}
				}
				break;
			}
		}
	}
	if(chon1==6){
		while(1){
			delay(0.001);
			tructoado();
			if(loai==0){
				gotoxy(5,10);Normal(); cout<<"Khong co hinh de ve!"; char c = getch();
				break;
			}
			if(loai==1){
				DDA(GetX(mangX[0]),GetY(mangY[0]),GetX(mangX[1]),GetY(mangY[1]));
				break;
			}
			if(loai==2){
				duongTron(GetX(mangX[0]),GetY(mangY[0]),GetX(mangX[1]),GetY(mangY[1]));
				break;
			}
			if(loai==3){
				for(int i=0;i<k;i++){
					mangX[i] = GetX(mangX[i]);
					mangY[i] = GetY(mangY[i]);
				}
				veDaGiac(mangX,mangY,k);
				break;
			}
		}
		
	}
	if(chon1==7){
		cleardevice();
		tructoado();
	}
	if(chon1==8) break;
	}
	gotoxy(0,10);
	delete[] mangX; delete[] mangY;
	
	
			
	return 0;
}
