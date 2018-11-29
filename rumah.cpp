#include <windows.h>
#include <GL\glut.h>
#include <stdlib.h>

int maju_mundur=0,maju_mundur1=180,kiri_kanan=0;
int keceptan_mobil=10,gerak_m=0;
int mm[] = {-50,120,230},mm1[]={250,-350,0},kk[] = {-90,190,0}; 
int mmb[] = {-50,120,230},mm1b[]={-150,350,150},kkb[] = {-90,190,0}; 
bool gerak_bus=false,gerak_mobil=false,gerak_mobilbiru=false;
float xyz = 600,minusy=400;

int toleh = 25;
void display();
void drawxy(int);
void pager();
void cylinder(float rbase,float rtop,float height);
void jalan_apartemen(float x,float y,float z);
void kaca(float);
void pintu(float,float,float);
void kaca_pintu(float,float);
void pagar_atas();
void Rumput(float x,float y,float z);
void tangga(float,float,float);
void rumah(float,float,float);
void trafficlight();
void rumah2();
void jalan_tepi(float,float,float);
void jalan_utama();
void bus();
void marka_jalan();
void zebracross();
void mobil(float,int);
void mobilbiru(float,int);
void mobil2(float x,float y,float z);
void mobil3(float x,float y,float z);
void awan();
void awan_tampil();
void tanaman();
void tampil_tanaman();
void pagar();
void bilah (float,float,float,int);
void kincir(float,float,float,float);
void pagar2();
void pohon(float x,float y,float z);
void batas_jalan();
void tampil_batas_jalan();
void jalan_tunanetra();
void tampil_jalan_tunanetra();
void jalan_tunanetra_warning();
void tong_sampah();
void kursi();
void tampil_kursi(float x,float y,float z);
void tampil_kursi2(float x,float y,float z);
void apartemen();
void init();

void blok(float tebal,int ratiol,int ratiop);

void pager(float x,float y,float z)
{
 //Pager      
	glEnable(GL_COLOR_MATERIAL);
	glPushMatrix();
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glTranslatef(x,y,z);
	glScalef(10,5,10);
	glTranslatef(7,-5.5,13);
	glColor3f(0.3,0.2,0);
	glScalef(15.75,0.5,0.75);
	glutSolidCube(1);
	glPopMatrix();
	glDisable(GL_COLOR_MATERIAL);
	
	glPushMatrix();
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	glTranslatef(x,y,z);
	glTranslatef(7,-0.5,13);
	glColor3f(1,0,0);
	glScalef(15.75,0.5,0.75);
	glutSolidCube(1);
	glPopMatrix();
 
 for (float dep=0.5;dep<13;dep+=2)
       {      
              glEnable(GL_COLOR_MATERIAL);
              glPushMatrix();
              glRotatef(90, 0.0f, 1.0f, 0.0f);
              glTranslatef(x,y,z);
              glScalef(10,5,10);
              glTranslatef(dep,-3,13);
              glColor3f(0.7,0.3,0);
              glScalef(1,7,0.5);
              glutSolidCube(1);
              glPopMatrix();
              glDisable(GL_COLOR_MATERIAL);
       }
 
 //pager depan kiri
              glPushMatrix();
              glRotatef(90, 0.0f, 1.0f, 0.0f);
              glTranslatef(x,y,z);
              glScalef(10,5,10);
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(-8,-5.5,13);
              glColor3f(0.3,0.2,0);
              glScalef(9.5,0.5,0.75);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();
               
              glPushMatrix();
              glRotatef(90, 0.0f, 1.0f, 0.0f);
              glTranslatef(x,y,z);
              glScalef(10,5,10);
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(-8,-0.5,13);
              glColor3f(1,0,0);
              glScalef(9.5,0.5,0.75);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();
 
  for (float dep2=-4;dep2>-12;dep2-=2)
       {
              glPushMatrix();
              glRotatef(90, 0.0f, 1.0f, 0.0f);
              glTranslatef(x,y,z);
              glScalef(10,5,10);
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(dep2,-3,13);
              glColor3f(0.7,0.3,0);
              glScalef(1,7,0.5);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();
       }
 
  //pagar belakang
              glPushMatrix();
              glRotatef(90, 0.0f, 1.0f, 0.0f);
              glTranslatef(x,y,z);
              glScalef(10,5,10);
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(1.2,-5.5,-13);
              glColor3f(0.3,0.2,0);
              glScalef(27.8,0.5,0.75);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();
               
              glPushMatrix();
              glRotatef(90, 0.0f, 1.0f, 0.0f);
              glTranslatef(x,y,z);
              glScalef(10,5,10);
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(1.2,-0.5,-13);
              glColor3f(1,0,0);
              glScalef(27.8,0.5,0.75);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();
 
  for (float dep=-10;dep<13;dep+=2)
       {
              glPushMatrix();
              glRotatef(90, 0.0f, 1.0f, 0.0f);
              glTranslatef(x,y,z);
              glScalef(10,5,10);
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(dep,-3,-13);
              glColor3f(0.7,0.3,0);
              glScalef(1,7,0.5);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();
       }
 
 //pagar samping kanan
              glPushMatrix();
              glRotatef(90, 0.0f, 1.0f, 0.0f);
              glTranslatef(x,y,z);
              glScalef(10,5,10);
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(14.2,-5.5,0);
              glColor3f(0.3,0.2,0);
              glScalef(0.75,0.5,28);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();
               
              glPushMatrix();
              glRotatef(90, 0.0f, 1.0f, 0.0f);
              glTranslatef(x,y,z);
              glScalef(10,5,10);
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(14.2,-0.5,0);
              glColor3f(1,0,0);
              glScalef(0.75,0.5,28);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();
 
  for (float samp=-13;samp<15;samp+=2)
       {
              glPushMatrix();
              glRotatef(90, 0.0f, 1.0f, 0.0f);
              glTranslatef(x,y,z);
              glScalef(10,5,10);
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(14.2,-3,samp);
              glColor3f(0.7,0.3,0);
              glScalef(0.5,7,1);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();
  }
//pagar samping
              glPushMatrix();
              glRotatef(90, 0.0f, 1.0f, 0.0f);
              glTranslatef(x,y,z);
              glScalef(10,5,10);
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(-12,-5.5,0);
              glColor3f(0.3,0.2,0);
              glScalef(0.75,0.5,28);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();
               
              glPushMatrix();
              glRotatef(90, 0.0f, 1.0f, 0.0f);
              glTranslatef(x,y,z);
              glScalef(10,5,10);
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(-12,-0.5,0);
              glColor3f(1,0,0);
              glScalef(0.75,0.5,28);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();
 
  for (float samp=-13;samp<15;samp+=2)
       {
              glPushMatrix();
              glRotatef(90, 0.0f, 1.0f, 0.0f);
              glTranslatef(x,y,z);
              glScalef(10,5,10);
              glEnable(GL_COLOR_MATERIAL);
              glTranslatef(-12,-3,samp);
              glColor3f(0.7,0.3,0);
              glScalef(0.5,7,1);
              glutSolidCube(1);
              glDisable(GL_COLOR_MATERIAL);
              glPopMatrix();
                }
}



void Rumput(float x,float y,float z)
{
    glPushMatrix();
    	glColor3f(0,1,0.3);
    	glTranslatef(x,y,z);
    	glScaled(10,0.01,2.5);
    	glutSolidCube(100);
    glPopMatrix();
}

void pohon(float x,float y,float z)
{
	
//batang
GLUquadricObj *pObj;
pObj =gluNewQuadric();
gluQuadricNormals(pObj, GLU_SMOOTH);
 
glEnable(GL_COLOR_MATERIAL);
glPushMatrix();
glTranslatef(x,y,z);
glScalef(7,7,7);
glColor3f(0.7,0.3,0);
glRotatef(270,1,0,0);
gluCylinder(pObj, 1, 0.7, 10, 20, 15);
glPopMatrix();
glDisable(GL_COLOR_MATERIAL);
 
//ranting
 
glPushMatrix();
glTranslatef(x,y,z);
glRotatef(180, 0.0f, 1.0f, 0.0f);
glScalef(7,7,7);
glColor3ub(104,70,14);
glTranslatef(0,7,0);
glRotatef(330,1,0,0);
gluCylinder(pObj, 0.6, 0.1, 7, 25, 25);
glPopMatrix();


//ranting
 
glPushMatrix();
glTranslatef(x,y,z);
glScalef(7,7,7);
glColor3ub(104,70,14);
glTranslatef(0,7,0);
glRotatef(330,1,0,0);
gluCylinder(pObj, 0.6, 0.1, 7, 25, 25);
glPopMatrix();

//daun
glEnable(GL_COLOR_MATERIAL);
glPushMatrix();
glTranslatef(x,y,z);
glRotatef(180, 0.0f, 1.0f, 0.0f);
glScalef(7,7,7);
glColor3f(0,1,0.3);
glScaled(4, 3, 5);
glTranslatef(0,4.7,0.4);
glutSolidDodecahedron();
glPopMatrix();
glDisable(GL_COLOR_MATERIAL);

  
//daun
glEnable(GL_COLOR_MATERIAL);
glPushMatrix();
glTranslatef(x,y,z);
glScalef(7,7,7);
glColor3f(0,1,0.3);
glScaled(4, 3, 5);
glTranslatef(0,4.7,0.4);
glutSolidDodecahedron();
glPopMatrix();
glDisable(GL_COLOR_MATERIAL);
} 


void matahari(){
 
//matahari
 glPushMatrix();
 glEnable(GL_COLOR_MATERIAL);
 glTranslatef(-100,280,-250);
 glColor3f(1,1,0);
 glScalef(13,13,13);
 glutSolidSphere(2.0,100,10);
 glDisable(GL_COLOR_MATERIAL);
 glPopMatrix();
}       
 
void display(void)
{
    //glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_COLOR_MATERIAL); //mengaktifkan fungsi untuk memberikan warna pada material
	glColorMaterial(GL_FRONT, GL_DIFFUSE); //parameter-parameter fungsi warna material 
    
    drawxy(500);
	rumah(0,0,-90);
    rumah(-350,0,-90);
    Rumput(-78,1,-100);
	jalan_tepi(-78,0,50);
    jalan_utama();
    jalan_apartemen(-78,0,350);
	jalan_tepi(-78,0,290);
	bus();
	zebracross();
	for(int i=1;i<3;i++){
		mobilbiru(19,i);	
	}
	for(int i=0;i<3;i++){
		mobil(19,i);	
	}
	trafficlight();
	awan_tampil();
	pohon(300,0,-100);
	pohon(300,0,-200);
	pohon(-550,0,-200);
	pohon(-550,0,-100);
	pohon(-420,0,430);
	pohon(-420,0,530);
	tampil_tanaman();
	matahari();
	pagar2();
	batas_jalan();
	tampil_batas_jalan();
	jalan_tunanetra();
    tampil_jalan_tunanetra();
    jalan_tunanetra_warning();
	tong_sampah();
	tampil_kursi(0,0,0);
	tampil_kursi2(0,0,550);
	apartemen();
    pager(90,33,-310);
	kincir(0,20,70,-90);
    kincir(-40,20,70,90);
    glDisable(GL_COLOR_MATERIAL); //menonaktifkan fungsi untuk memberikan warna pada material 
	glFlush();
	glutPostRedisplay(); 
}

void kincir(float x,float y,float z,float arah)
{
	const double t= glutGet(GLUT_ELAPSED_TIME)/2000.0; 
	glPushMatrix();
		glTranslatef(x,y,z);
		glColor3ub(255,255,255);
		glPushMatrix();
			glScaled(.1,2,.1);
			glutSolidCube(20);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0,18,0);
			cylinder(1,1,5);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0,-20,0);
			glScaled(.3,.05,.3);
			glutSolidCube(20);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0,18,3);
			glRotatef(t*arah,0.0,0.0,1);
			bilah(2,25,3,5);
		glPopMatrix();
	glPopMatrix();
}

void bilah (float r_inner,float r_outer,float tebal,int batang)
	{
	float i;
	glPushMatrix();
	glTranslatef(0.0,0.0,-tebal/4);
	cylinder(r_inner,r_inner,tebal);
	glTranslatef(0.0,0.0,tebal/2);
	glRotatef(90,0.0,1.0,0.0);
	for(i=0;i<batang;i++)
	{
	glTranslatef(0.0,0.0,r_inner);
	glRotatef(315,0.0,0.0,1.0);
	blok(0.5,r_inner*4.5,(r_outer-r_inner+(r_inner/4))*2);
	glRotatef(45,0.0,0.0,1.0);
	glTranslatef(0.0,0.0,-r_inner);
	glRotatef(360/batang,1.0,0.0,0.0);
	}
	glPopMatrix();
	}

//tampil tanaman pagar
void tampil_tanaman()
{
	//tanaman rumah 1
	glPushMatrix();
		tanaman();	
	glPopMatrix();
	//tanaman rumah 2
	glPushMatrix();
		glTranslatef(-350.5,1.5,3);
		tanaman();	
	glPopMatrix();
	//tanaman rumah 2
	glPushMatrix();
		glTranslatef(-135,0,-220);
		glScaled(0.55,1 ,1 );
		tanaman();	
	glPopMatrix();
}

//tanaman pagar
void tanaman()
{
	//tanaman1
    glPushMatrix();
	    glColor3ub(18,118,13);
	    glScaled(60.5, 5, 5);
	    glTranslatef(0.25,1.5,3);//geser
	    glutSolidCube(3);
    glPopMatrix();
}

//tampil awan
void awan_tampil()
{
	//awan1	
	glPushMatrix();
		glTranslatef(200,250,-50);
		awan();	
	glPopMatrix();
	//awan2
	glPushMatrix();
		glTranslatef(10,300,-150);
		awan();	
	glPopMatrix();
	//awan3
	glPushMatrix();
		glTranslatef(-350,270,-100);
		awan();	
	glPopMatrix();
}

//awan
void awan()
{
	glPushMatrix();
		glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
		glColor3ub(153, 223, 255);
		glutSolidSphere(20, 50, 50);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(25,0,1);
		glutSolidSphere(10, 50, 50);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-20,6,-2);
		glutSolidSphere(14, 50, 50);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-30,-3,0);
		glutSolidSphere(14, 50, 50);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(15,-2,2);
		glutSolidSphere(14, 50, 50);
	glPopMatrix();
}

//pagar
void pagar2()
{
	//tiang pagar 1
	glPushMatrix();
		glColor3f(1,1,1);
	 	glScaled(4, 10, 4);
	    glTranslatef(69,1,5);//geser
	    glutSolidCube(2);
	glPopMatrix();
   	//tiang pagar 2
	glPushMatrix();
		glColor3f(1,1,1);
	 	glScaled(4, 10, 4);
	    glTranslatef(69,1,-48);//geser
	    glutSolidCube(2);
	glPopMatrix();
	//tiang pagar 3
	glPushMatrix();
		glColor3f(1,1,1);
	 	glScaled(4, 10, 4);
	    glTranslatef(-19,1,-48);//geser
	    glutSolidCube(2);
	glPopMatrix();
	//tiang pagar 4
	glPushMatrix();
		glColor3f(1,1,1);
	 	glScaled(4, 10, 4);
	    glTranslatef(-19,1,-35);//geser
	    glutSolidCube(2);
	glPopMatrix();
	//dinding pagar 1
	glPushMatrix();
		glColor3f(0.1,0.1,0.1);
	 	glScaled(1, 8, -105);
	    glTranslatef(275,1,0.8);//geser
	    glutSolidCube(2);
	glPopMatrix();
	//dinding pagar 2
	glPushMatrix();
		glRotatef(90, 0.0f, 1.0f, 0.0f);
		glColor3f(0.1,0.1,0.1);
	 	glScaled(1, 8, -176);
	    glTranslatef(192,1,-0.55);//geser
	    glutSolidCube(2);
	glPopMatrix();
	//dinding pagar 3
	glPushMatrix();
		glColor3f(0.1,0.1,0.1);
	 	glScaled(1, 8, -25);
	    glTranslatef(-77,1,6.5);//geser
	    glutSolidCube(2);
	glPopMatrix();
}

void tong_sampah()
{
	//tong sampah 1
	glPushMatrix();
		glRotatef(90, 1.0f, 0.0f, 0.0f);
		glTranslatef(295,15,-23);
		glColor3f(0, 0, 0);
		cylinder(10,6,20);
	glPopMatrix();
	//tong sampah 2
	glPushMatrix();
		glRotatef(90, 1.0f, 0.0f, 0.0f);
		glTranslatef(-470,15,-23);
		glColor3f(0, 0, 0);
		cylinder(10,6,20);
	glPopMatrix();
	//tong sampah 3
	glPushMatrix();
		glRotatef(90, 1.0f, 0.0f, 0.0f);
		glTranslatef(-95,-30,-23);
		glColor3f(0, 0, 0);
		cylinder(10,6,20);
	glPopMatrix();
}

void tampil_kursi(float x,float y,float z)
{
	glPushMatrix();
		glTranslatef(x,y,z);
		//kursi1
		glPushMatrix();
			glTranslatef(330,12,-540); 
			glScalef(30, 20, 15);
			kursi();
		glPopMatrix();
		//kursi2
		glPushMatrix();
			glTranslatef(-520,12,-540); 
			glScalef(20, 20, 15);
			kursi();
		glPopMatrix();
		//kursi3
		glPushMatrix();
			glTranslatef(-150,12,-525); 
			glScalef(20, 20, 15);
			kursi();
		glPopMatrix();
	glPopMatrix();
	
}

void tampil_kursi2(float x,float y,float z)
{
	glPushMatrix();
		glTranslatef(x,y,z);
		//kursi1
		glPushMatrix();
			glTranslatef(330,12,-540); 
			glScalef(30, 20, 15);
			kursi();
		glPopMatrix();
		//kursi2
		glPushMatrix();
			glTranslatef(-350,12,-525); 
			glScalef(20, 20, 15);
			kursi();
		glPopMatrix();
	glPopMatrix();
}

void kursi()
{
	// Batang Tiang Kanan
	glPushMatrix();
		glScaled(0.06, 0.2,0.06);
		glTranslatef(43, 0,380.5); 
		//glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
		glColor3f(1,1,1); 
		glutSolidCube(5.0);
	glPopMatrix(); 
	
	
	// Batang Tiang Kiri
	glPushMatrix();
		glScaled(0.06, 0.2,0.06);
		glTranslatef(3, 0,380.5); 
		//glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
		glColor3f(1,1,1); 
		glutSolidCube(5.0);
	glPopMatrix(); 
	
	// Batang depan knan
	glPushMatrix();
		glScaled(0.06, 0.2,0.06);
		glTranslatef(43, 0,390.5); 
		//glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
		glColor3f(1,1,1);
		glutSolidCube(5.0);
	glPopMatrix(); 
	
	// Batang Depan Kiri
	glPushMatrix();
		glScaled(0.06, 0.2,0.06);
		glTranslatef(3, 0,390.5); 
		//glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
		glColor3f(1,1,1); 
		glutSolidCube(5.0);
	glPopMatrix();     
	
	// atas kursi
	glPushMatrix();
		glScaled(0.6, 0.05,0.3);
		glTranslatef(2.4,8,77); 
		//glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
		glColor3f(1.0000, 0.5252, 0.0157);
		glutSolidCube(5.0);
	glPopMatrix();  
   
}


void batas_jalan()
{
   glPushMatrix();
	    glTranslatef(416,20,265); 
		glScaled(2,8,2);
		glColor3f(0,0,0);	
		glutSolidCube(5); 
   glPopMatrix();
   /////
   glPushMatrix();
    glTranslatef(374,30,265); 
	glScaled(15,2,2);
	glColor3f(1.0,0,0);	
	glutSolidCube(5); 
   glPopMatrix();
   glPushMatrix();
    glTranslatef(374,13,265); 
	glScaled(15,2,2);
	glColor3f(1.0,0,0);	
	glutSolidCube(5); 
   glPopMatrix();
}

void tampil_batas_jalan()
{
	glPushMatrix();
		glTranslatef(-85,0,0); 
		batas_jalan();
		glTranslatef(-85,0,0); 
		batas_jalan();
		glTranslatef(-85,0,0); 
		batas_jalan();
		glTranslatef(-85,0,0); 
		batas_jalan();
		glTranslatef(-85,0,0); 
		batas_jalan();
		glTranslatef(-85,0,0); 
		batas_jalan();
		glTranslatef(-85,0,0); 
		batas_jalan();
		glTranslatef(-85,0,0); 
		batas_jalan();
	glPopMatrix();
	
	//tiang keluar zebra cross
	glPushMatrix();
    glTranslatef(-348,20,265); 
	glScaled(2,8,2);
	glColor3f(0,0,0);	
	glutSolidCube(5); 
   glPopMatrix();
   
   //tiang lanjutan
   glPushMatrix();
		glTranslatef(-842,0,0); 
		batas_jalan();
		glTranslatef(-85,0,0); 
		batas_jalan();
	glPopMatrix();
}
//tampilan jalan untuk tunanetra
void jalan_tunanetra()
{
	//tembok kiri bawah
     glPushMatrix();
    	glColor3f(225,225,0);
    	glTranslatef(395,1,294);
    	glScaled(8,0.1,8);
    	glutSolidCube(5);
    glPopMatrix();
    
    glPushMatrix();
    	glColor3f(2,2,2);
    	glTranslatef(395,2,281);
    	glScaled(6,0.1,1);
    	glutSolidCube(5);
    glPopMatrix();
    
    glPushMatrix();
    	glColor3f(2,2,2);
    	glTranslatef(395,2,290);
    	glScaled(6,0.1,1);
    	glutSolidCube(5);
    glPopMatrix();
    
    glPushMatrix();
    	glColor3f(2,2,2);
    	glTranslatef(395,2,299);
    	glScaled(6,0.1,1);
    	glutSolidCube(5);
    glPopMatrix();

	glPushMatrix();
    	glColor3f(2,2,2);
    	glTranslatef(395,2,308);
    	glScaled(6,0.1,1);
    	glutSolidCube(5);
    glPopMatrix();
}


void jalan_tunanetra_warning()
{
	//tembok kiri bawah
     glPushMatrix();
    	glColor3f(225,0,0);
    	glTranslatef(395,1,294);
    	glScaled(8,0.1,8);
    	glutSolidCube(5);
    glPopMatrix();
}

void tampil_jalan_tunanetra()
{
	glPushMatrix();
		glTranslatef(-40,0,0); 
		jalan_tunanetra();
		glTranslatef(-40,0,0); 
		jalan_tunanetra();
		glTranslatef(-40,0,0); 
		jalan_tunanetra();
		glTranslatef(-40,0,0); 
		jalan_tunanetra();
		glTranslatef(-40,0,0); 
		jalan_tunanetra();
		glTranslatef(-40,0,0); 
		jalan_tunanetra();
		glTranslatef(-40,0,0); 
		jalan_tunanetra();
		glTranslatef(-40,0,0); 
		jalan_tunanetra();
		glTranslatef(-40,0,0); 
		jalan_tunanetra();
		glTranslatef(-40,0,0); 
		jalan_tunanetra();
		glTranslatef(-40,0,0); 
		jalan_tunanetra();
		glTranslatef(-40,0,0); 
		jalan_tunanetra();
		glTranslatef(-40,0,0); 
		jalan_tunanetra();
		glTranslatef(-40,0,0); 
		jalan_tunanetra();
		glTranslatef(-40,0,0); 
		jalan_tunanetra();
		glTranslatef(-40,0,0); 
		jalan_tunanetra();
		glTranslatef(-40,0,0); 
		jalan_tunanetra();
		glTranslatef(-40,0,0); 
		jalan_tunanetra();
		glTranslatef(-40,0,0); 
		jalan_tunanetra_warning();
		glTranslatef(-40,0,0); 
		jalan_tunanetra_warning();
		glTranslatef(-40,0,0); 
		jalan_tunanetra();
		glTranslatef(-40,0,0); 
		jalan_tunanetra();	
		glTranslatef(-40,0,0); 
		jalan_tunanetra();	
		glTranslatef(-40,0,0); 
		jalan_tunanetra();		
	glPopMatrix();

}



void trafficlight()
{
	glPushMatrix();
		glTranslatef(-450,0,-330);
		glRotatef(90, 0.0f, 1.0f, 0.0f);
		glPushMatrix();
			glColor3f(0.1,0.1,0.1);
			glTranslatef(-400,55,-3);
			glScaled(.25,.5,0.22);
			glutSolidCube(100);
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(-400,30,-3);
			glColor3f(1,1,1);
			glScaled(.1,.5,.1);
			glutSolidCube(100);
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(-400,5,-3);
			glScaled(.3,.1,.2);
			glutSolidCube(100);
		glPopMatrix();
		
		glPushMatrix();
			glColor3f(1,0,0);
			glTranslatef(-400,70,2);
			glScaled(.1,.1,.2);
		glutSolidSphere(70,100,50);
		glPopMatrix();
		
		glPushMatrix();	
			glColor3f(1,1,0);
			glTranslatef(-400,55,2);
			glScaled(.1,.1,.2);
			glutSolidSphere(70,100,50);
		glPopMatrix();
		
		glPushMatrix();	
			glColor3f(0,1,0);
			glTranslatef(-400,40,2);
			glScaled(.1,.1,.2);
			glutSolidSphere(70,100,50);
			
		glPopMatrix();
	glPopMatrix();
}


void bus()
{
	glPushMatrix();
		glTranslatef(maju_mundur1,40,maju_mundur);
		glTranslatef(10,0,-80);
		glScalef(2,1.5,2);
		glRotated(kiri_kanan,0,1,0);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
			glVertex3f(10,20,50);
			glVertex3f(10,20,-50);
			glVertex3f(10,-20,-50);
			glVertex3f(10,-20,50);
		glEnd();	
		
		
		//kiri
		glBegin(GL_POLYGON);
			glVertex3f(-10,20,50);
			glVertex3f(-10,20,-50);
			glVertex3f(-10,-20,-50);
			glVertex3f(-10,-20,50);
		glEnd();	
		
		//atas
		glColor3f(0.4, 1.0, 1.0);
		glBegin(GL_POLYGON);
			glVertex3f(10,20,50);
			glVertex3f(10,20,-50);
			glVertex3f(-10,20,-50);
			glVertex3f(-10,20,50);
		glEnd();	
		
		//bawah
		glColor3f(0.4, 1.0, 1.0);
		glBegin(GL_POLYGON);
			glVertex3f(10,-20,50);
			glVertex3f(10,-20,-50);
			glVertex3f(-10,-20,-50);
			glVertex3f(-10,-20,50);
		glEnd(); 
		
		//belakang
		glColor3f(0.4, 0.5, 1.0);
		glBegin(GL_POLYGON);
			glVertex3f(10,20,-50);
			glVertex3f(10,-20,-50);
			glVertex3f(-10,-20,-50);
			glVertex3f(-10,20,-50);
		glEnd();   
		
		//depan bawah dikit
		glColor3f(1, 1, 0.7);
		glBegin(GL_POLYGON);
			glVertex3f(-10,-5,50);
			glVertex3f(10,-5,50);
			glVertex3f(10,-20,50);
			glVertex3f(-10,-20,50);
		glEnd(); 
		
		//depan bawah dikit
		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
			glVertex3f(10,20,50);
			glVertex3f(-10,20,50);
			glVertex3f(-10,-5,50);
			glVertex3f(10,-5,50);
		glEnd();      
		
		//kaca depan
		glPushMatrix();
			glColor3f(0.1, 0.1, 0.1);
			glTranslatef(0.0, 8, 50);
			glScaled(1,1,0.1);  
			glutSolidCube(20);
		glPopMatrix();
		
		//kaca kiri	
		glPushMatrix();
			glColor3f(0.1, 0.1, 0.1);
			glTranslatef(10.3,8,-4);
			glScaled(0.1,1,4);
			//glRotated(180,0,1,0);  
			glutSolidCube(20);
		glPopMatrix();	
		
		//kaca kanan	
		glPushMatrix();
			glColor3f(0.1, 0.1, 0.1);
			glTranslatef(-10.3,8,-4);
			glScaled(0.1,1,4);
			//glRotated(180,0,1,0);  
			glutSolidCube(20);
		glPopMatrix();
		
		//pintu kaca kiri
		glPushMatrix();
			glColor3f(0.1, 0.1, 0.1);
			glTranslatef(10.8,8,43);
			glScaled(0.1,1,0.4);
			//glRotated(180,0,1,0);  
			glutSolidCube(20);
		glPopMatrix();
		
		//pintu kaca kanan
		glPushMatrix();
			glColor3f(0.1, 0.1, 0.1);
			glTranslatef(-10.8,8,43);
			glScaled(0.1,1,0.4);
			//glRotated(180,0,1,0);  
			glutSolidCube(20);
		glPopMatrix();
		
		glBegin(GL_LINES);
			glColor3f(0, 0, 0);
			glVertex3f(-10,20,45.5);
			glVertex3f(-10,-20,45.5);
		glEnd();
		
		//roda belakang kiri
		glPushMatrix();
			glTranslatef(10,-20,-30);
			glRotated(90,0,1,0);
			glColor3f(0, 0, 0);
			cylinder(6,6,2);
			glTranslatef(0,0,-5);
			cylinder(6,6,2);
			glColor3f(1, 1, 1);
			glTranslatef(0,0,7);
			cylinder(3,3,1);
		glPopMatrix();
		
		//roda belakang kanan
		glPushMatrix();
			glTranslatef(-10,-20,-30);
			glRotated(90,0,1,0);
			glColor3f(0, 0, 0);
			cylinder(6,6,2);
			glTranslatef(0,0,5);
			cylinder(6,6,2);
			glColor3f(1, 1, 1);
			glTranslatef(0,0,-7);
			cylinder(3,3,1);
		glPopMatrix();
		
		//roda depan kanan
		glPushMatrix();
			glTranslatef(-10,-20,30);
			glRotated(90,0,1,0);
			glColor3f(0, 0, 0);
			cylinder(6,6,2);
			glColor3f(1, 1, 1);
			glTranslatef(0,0,-3);
			cylinder(3,3,1);
		glPopMatrix();		
		
		//roda depan kiri
		glPushMatrix();
			glTranslatef(10,-20,30);
			glRotated(90,0,1,0);
			glColor3f(0, 0, 0);
			cylinder(6,6,2);
			glColor3f(1, 1, 1);
			glTranslatef(0,0,3);
			cylinder(3,3,1);
		glPopMatrix();	
		
		//lambu depan
		glPushMatrix();
			glColor3f(0.5, 0.5, 0.5);
			glTranslatef(-5,-10,50);
			glutSolidCube(4);
			glColor3f(1, 1, 0);
			glTranslatef(-3,0,0);
			glutSolidCube(4);
		glPopMatrix();
		
		//lambu depan
		glPushMatrix();
			glColor3f(0.5, 0.5, 0.5);
			glTranslatef(5,-10,50);
			glutSolidCube(4);
			glColor3f(1, 1, 0);
			glTranslatef(3,0,0);
			glutSolidCube(4);
		glPopMatrix();
		
	glPopMatrix();
}

void apartemen()
{
	//glPushMatrix();
	  //  glColor3ub(255, 223, 255);
	  //  glScaled(70, 26,10);//ukur
	    //glTranslatef(0,5,-50);//geser
	    //glutSolidCube(10);
    //glPopMatrix();
  glPushMatrix();
  glRotatef(90, 0.0f, 1.0f, 0.0f);
  glRotatef(90, 0.0f, 1.0f, 0.0f);
  glTranslatef(0,0,35); 
    glPushMatrix();//gedungkiri
	    glColor3ub(255, 223, 255);
	    glScaled(50, 26,10);//ukur
	    glTranslatef(-2,5,-50);//geser
	    glutSolidCube(10);
    glPopMatrix();
    
     glPushMatrix();//gedungkiri
	    glColor3ub(255, 223, 255);
	    glScaled(20, 13.5,10);//ukur
	    glTranslatef(13,12,-50);//geser
	    glutSolidCube(10);
    glPopMatrix();
    
    glPushMatrix();//pintu
	    glColor3ub(1, 1, 1);
	    glScaled(10, 15,10);
	    glTranslatef(11,2.5,-47);//geser
	    glutSolidCube(5);
    glPopMatrix();
    glPushMatrix();//ataspintu
	    glColor3ub(1, 1, 1);
	    glScaled(20, 40,10);
	    glTranslatef(5.5,5,-45);//geser
	    glutSolidCube(5);
    glPopMatrix();
    glPushMatrix();//atap pintu
	    glColor3ub(1, 1, 1);
	    glScaled(20, 2,20);
	    glTranslatef(5.5,50,-20);//geser
	    glutSolidCube(5);
    glPopMatrix();
    glPushMatrix();//bawah atap pintu
	    glColor3ub(1, 1, 1);
	    glScaled(20, 2,20);
	    glTranslatef(5.5,0,-20);//geser
	    glutSolidCube(5);
    glPopMatrix();
    glPushMatrix();//tiang pintu
	    glColor3ub(4, 4, 4);
	    glScaled(2, 20,2);
	    glTranslatef(35,2.5,-180);//geser
	    glutSolidCube(5);
    glPopMatrix();
    glPushMatrix();//tiang pintu
	    glColor3ub(4, 4, 4);
	    glScaled(2, 20,2);
	    glTranslatef(75,2.5,-180);//geser
	    glutSolidCube(5);
    glPopMatrix();
    
    glPushMatrix();
	    glColor3ub(1, 1, 1);
	    glScaled(4, 50,10);
	    glTranslatef(-85,2.5,-47);//geser
	    glutSolidCube(5);
    glPopMatrix();
    glPushMatrix();
	    glColor3ub(1, 1, 1);
	    glScaled(4, 50,10);
	    glTranslatef(-60,2.5,-47);//geser
	    glutSolidCube(5);
    glPopMatrix();
    glPushMatrix();
	    glColor3ub(1, 1, 1);
	    glScaled(4, 50,10);
	    glTranslatef(-35,2.5,-47);//geser
	    glutSolidCube(5);
    glPopMatrix();
    glPushMatrix();
	    glColor3ub(1, 1, 1);
	    glScaled(4, 50,10);
	    glTranslatef(-10,2.5,-47);//geser
	    glutSolidCube(5);
    glPopMatrix();
    glPushMatrix();
	    glColor3ub(1, 1, 1);
	    glScaled(4, 50,10);
	    glTranslatef(15,2.5,-47);//geser
	    glutSolidCube(5);
    glPopMatrix();
    glPushMatrix();
	    glColor3ub(1, 1, 1);
	    glScaled(4, 50,10);
	    glTranslatef(40,2.5,-47);//geser
	    glutSolidCube(5);
    glPopMatrix();
    ////glPushMatrix();
	//    glColor3ub(1, 1, 1);
	//    glScaled(4, 50,10);
	///    glTranslatef(65,2.5,-47);//geser
	//    glutSolidCube(5);
   /// glPopMatrix();
    glPushMatrix();
	    glColor3ub(1, 1, 1);
	    glScaled(4, 45,10);
	    glTranslatef(90,2.5,-47);//geser
	    glutSolidCube(5);
    glPopMatrix();
    
    glPushMatrix();//belakang gedung
	    glColor3ub(1, 1, 1);
	    glScaled(4, 45,10);
	    glTranslatef(90,2.5,-55);//geser
	    glutSolidCube(5);
    glPopMatrix();
    
    glPushMatrix();//bawah1
	    glColor3ub(1, 1, 1);
	    glScaled(10, 10,10);
	    glTranslatef(-29,6,-47);//geser
	    glutSolidCube(5);
    glPopMatrix();
    glPushMatrix();//bawah2
	    glColor3ub(1, 1, 1);
	    glScaled(10, 10,10);
	   glTranslatef(-19,6,-47);//geser
	   glutSolidCube(5);
    glPopMatrix();
     // glPushMatrix();//gednonjolkiri
	  //  glColor3ub(255, 223, 255);
	 ////   glScaled(20, 52,25);
	 ///   glTranslatef(-9.5,2.5,-17.7);//geser
	 ///   glutSolidCube(5);
   /// glPopMatrix();
    glPushMatrix();//bawah3
	    glColor3ub(1, 1, 1);
	    glScaled(10, 10,10);
	    glTranslatef(-9,6,-47);//geser
	    glutSolidCube(5);
    glPopMatrix();
    glPushMatrix();//bawah
	    glColor3ub(1, 1, 1);
	    glScaled(10, 10,10);
	    glTranslatef(1,6,-47);//geser
	    glutSolidCube(5);
    glPopMatrix();
    glPushMatrix();//bawah
	    glColor3ub(1, 1, 1);
	    glScaled(10, 10,10);
	    glTranslatef(11,6,-47);//geser
	    glutSolidCube(5);
    glPopMatrix();
  //  glPushMatrix();//bawah
//	    glColor3ub(1, 1, 1);
//	    glScaled(10, 10,10);
//	    glTranslatef(21,6,-47);//geser
//	    glutSolidCube(5);
 //   glPopMatrix();
   // glPushMatrix();//bawah
//	    glColor3ub(1, 1, 1);
//	    glScaled(10, 10,10);
//	    glTranslatef(31,6,-47);//geser
//	    glutSolidCube(5);
   // glPopMatrix();
    
    glPushMatrix();//atas2
	    glColor3ub(1, 1, 1);
	    glScaled(10, 10,10);
	    glTranslatef(-29,14,-47);//geser
	    glutSolidCube(5);
    glPopMatrix();
    glPushMatrix();//atas2
	    glColor3ub(1, 1, 1);
	    glScaled(10, 10,10);
	    glTranslatef(-19,14,-47);//geser
	    glutSolidCube(5);
    glPopMatrix();
    glPushMatrix();//atas2
	    glColor3ub(1, 1, 1);
	    glScaled(10, 10,10);
	    glTranslatef(-9,14,-47);//geser
	    glutSolidCube(5);
    glPopMatrix();
    glPushMatrix();//atas2
	    glColor3ub(1, 1, 1);
	    glScaled(10, 10,10);
	    glTranslatef(1,14,-47);//geser
	    glutSolidCube(5);
    glPopMatrix();
     glPushMatrix();//atas2
	    glColor3ub(1, 1, 1);
	    glScaled(10, 10,10);
	    glTranslatef(11,14,-47);//geser
	    glutSolidCube(5);
    glPopMatrix();
   // glPushMatrix();//atas2
//	    glColor3ub(1, 1, 1);
//	    glScaled(10, 10,10);
//	    glTranslatef(21,14,-47);//geser
//	    glutSolidCube(5);
 //   glPopMatrix();
  //  glPushMatrix();//atas2
//	    glColor3ub(1, 1, 1);
//	    glScaled(10, 10,10);
//	    glTranslatef(31,14,-47);//geser
//	    glutSolidCube(5);
  //  glPopMatrix();
   
   glPushMatrix();//atas3
	    glColor3ub(1, 1, 1);
	    glScaled(10, 10,10);
	    glTranslatef(-29,22,-47);//geser
	    glutSolidCube(5);
    glPopMatrix();
    glPushMatrix();//atas3
	    glColor3ub(1, 1, 1);
	    glScaled(10, 10,10);
	    glTranslatef(-19,22,-47);//geser
	    glutSolidCube(5);
    glPopMatrix();
    glPushMatrix();//atas3
	    glColor3ub(1, 1, 1);
	    glScaled(10, 10,10);
	    glTranslatef(-9,22,-47);//geser
	    glutSolidCube(5);
    glPopMatrix();
    glPushMatrix();//atas3
	    glColor3ub(1, 1, 1);
	    glScaled(10, 10,10);
	    glTranslatef(1,22,-47);//geser
	    glutSolidCube(5);
    glPopMatrix();
    glPushMatrix();//atas3
	    glColor3ub(1, 1, 1);
	    glScaled(10, 10,10);
	    glTranslatef(11,22,-47);//geser
	    glutSolidCube(5);
    glPopMatrix();
   // glPushMatrix();//atas3
//	    glColor3ub(1, 1, 1);
//	    glScaled(10, 10,10);
//	    glTranslatef(21,22,-47);//geser
	//    glutSolidCube(5);
  //  glPopMatrix();
    //glPushMatrix();//atas3
	 //   glColor3ub(1, 1, 1);
	//    glScaled(10, 10,10);
	 //   glTranslatef(31,22,-47);//geser
	//    glutSolidCube(5);
   // glPopMatrix();
    
glPushMatrix();//banner
	   glColor3ub(1, 1, 1);
	  glScaled(27, 20,10);
	   glTranslatef(9.5,8,-47);//geser
	   glutSolidCube(5);
    glPopMatrix();

    glPushMatrix();//dasar
	    glColor3ub(1, 1, 1);
	    glScaled(150, 2,24);
	    glTranslatef(0.05,0,-20);//geser
	    glutSolidCube(5);
    glPopMatrix();
    

    //glPushMatrix();//atap
	    //glColor3ub(1, 1, 1);
	    //glScaled(150, 5,24);
	   // glTranslatef(0.05,52,-20);//geser
	  //  glutSolidCube(5);
    //glPopMatrix();
    
    glPushMatrix();//atap
	    glColor3ub(1, 1, 1);
	    glScaled(105, 5,24);
	    glTranslatef(-1,52,-20);//geser
	    glutSolidCube(5);
    glPopMatrix();
    
    glPushMatrix();//atapkananatas
	    glColor3ub(1, 1, 1);
	    glScaled(50, 5,24);
	    glTranslatef(5,45,-20);//geser
	    glutSolidCube(5);
    glPopMatrix();
    glPushMatrix();//atapkananbawah
	    glColor3ub(1, 1, 1);
	    glScaled(50, 2,24);
	    glTranslatef(5,45,-20);//geser
	    glutSolidCube(5);
    glPopMatrix();
    glPopMatrix();
   
}
void jalan_apartemen(float x,float y,float z)
{
    glPushMatrix();
    	glColor3f(0,1,0.3);
    	glTranslatef(x,y,z);
    	glScaled(10,0.01,.6);
    	glutSolidCube(100);
    glPopMatrix();
}


void jalan_tepi(float x,float y,float z)
{
    glPushMatrix();
    	glColor3f(0.1,0.1,0.1);
    	glTranslatef(x,y,z);
    	glScaled(10,0.01,.6);
    	glutSolidCube(100);
    glPopMatrix();
}

void jalan_utama()
{
    glPushMatrix();
    	glColor3f(0.3,0.3,0.3);
    	glTranslatef(-78,0,50);
    	glTranslatef(0,0,120);
    	glScaled(10,0.01,1.7);
    	glutSolidCube(100);
    glPopMatrix();
}

void marka_jalan	()
{
    glPushMatrix();
    	glColor3f(1.,1,1);
    	glTranslatef(-78,0,50);
    	glTranslatef(-240,2,120);
    	glScaled(0.5,0.01,0.1);
    	glutSolidCube(100);
    glPopMatrix();
    
    glPushMatrix();
    	glColor3f(1,1,1);
    	glTranslatef(-78,0,50);
    	glTranslatef(-160,2,120);
    	glScaled(0.5,0.01,0.1);
    	glutSolidCube(100);
    glPopMatrix();
    
    glPushMatrix();
    	glColor3f(1,1,1);
    	glTranslatef(-78,0,50);
    	glTranslatef(-80,2,120);
    	glScaled(0.5,0.01,0.1);
    	glutSolidCube(100);
    glPopMatrix();
    
    glPushMatrix();
    	glColor3f(1,1,1);
    	glTranslatef(-78,0,50);
    	glTranslatef(0,2,120);
    	glScaled(0.5,0.01,0.1);
    	glutSolidCube(100);
    glPopMatrix();
    
    glPushMatrix();
    	glColor3f(1.,1,1);
    	glTranslatef(-78,0,50);
    	glTranslatef(240,2,120);
    	glScaled(0.5,0.01,0.1);
    	glutSolidCube(100);
    glPopMatrix();
    
    glPushMatrix();
    	glColor3f(1.,1,1);
    	glTranslatef(-78,0,50);
    	glTranslatef(320,2,120);
    	glScaled(0.5,0.01,0.1);
    	glutSolidCube(100);
    glPopMatrix();
    
    glPushMatrix();
    	glColor3f(1.,1,1);
    	glTranslatef(-78,0,50);
    	glTranslatef(400,2,120);
    	glScaled(0.5,0.01,0.1);
    	glutSolidCube(100);
    glPopMatrix();
    
    glPushMatrix();
    	glColor3f(1,1,1);
    	glTranslatef(-78,0,50);
    	glTranslatef(160,2,120);
    	glScaled(0.5,0.01,0.1);
    	glutSolidCube(100);
    glPopMatrix();
    
    glPushMatrix();
    	glColor3f(1,1,1);
    	glTranslatef(-78,0,50);
    	glTranslatef(80,2,120);
    	glScaled(0.5,0.01,0.1);
    	glutSolidCube(100);
    glPopMatrix();
}

void zebracross()
{
	   glPushMatrix();
    	glColor3f(1,1,1);
    	glTranslatef(0,1,50);
    	glTranslatef(-385,0,120);
    	glScaled(0.1,0.01,1.7);
    	glutSolidCube(100);
    glPopMatrix();
	
    glPushMatrix();
    	glColor3f(1,1,1);
    	glTranslatef(0,1,50);
    	glTranslatef(-420,0,140);
    	glScaled(0.5,0.01,0.1);
    	glutSolidCube(100);
    glPopMatrix();
    
    glPushMatrix();
    	glColor3f(1,1,1);
    	glTranslatef(0,1,50);
    	glTranslatef(-420,0,160);
    	glScaled(0.5,0.01,0.1);
    	glutSolidCube(100);
    glPopMatrix();
    
    glPushMatrix();
    	glColor3f(1,1,1);
    	glTranslatef(0,1,50);
    	glTranslatef(-420,0,180);
    	glScaled(0.5,0.01,0.1);
    	glutSolidCube(100);
    glPopMatrix();
    
    glPushMatrix();
    	glColor3f(1,1,1);
    	glTranslatef(0,1,50);
    	glTranslatef(-420,0,200);
    	glScaled(0.5,0.01,0.1);
    	glutSolidCube(100);
    glPopMatrix();
    
	glPushMatrix();
    	glColor3f(1,1,1);
    	glTranslatef(0,1,50);
    	glTranslatef(-420,0,120);
    	glScaled(0.5,0.01,0.1);
    	glutSolidCube(100);
    glPopMatrix();
    
    glPushMatrix();
    	glColor3f(1,1,1);
    	glTranslatef(0,1,50);
    	glTranslatef(-420,0,100);
    	glScaled(0.5,0.01,0.1);
    	glutSolidCube(100);
    glPopMatrix();
    
    glPushMatrix();
    	glColor3f(1,1,1);
    	glTranslatef(0,1,50);
    	glTranslatef(-420,0,80);
    	glScaled(0.5,0.01,0.1);
    	glutSolidCube(100);
    glPopMatrix();
    
    glPushMatrix();
    	glColor3f(1,1,1);
    	glTranslatef(0,1,50);
    	glTranslatef(-420,0,60);
    	glScaled(0.5,0.01,0.1);
    	glutSolidCube(100);
    glPopMatrix();
    
    glPushMatrix();
    	glColor3f(1,1,1);
    	glTranslatef(0,1,50);
    	glTranslatef(-420,0,40);
    	glScaled(0.5,0.01,0.1);
    	glutSolidCube(100);
    glPopMatrix();

}

void rumah(float x,float y,float z)
{
	glPushMatrix();
	    glTranslatef(x,y,z);
	    //bawah lantai
	    glBegin(GL_POLYGON);
	    	glColor3f(0.3,0.3,0.3);
	    	glVertex3f(200,0,80);
	    	glVertex3f(200,0,-50);
	    	glVertex3f(-80,0,-50);
	    	glVertex3f(-80,0,80);
	    glEnd();
	    
	    //tembok kiri bawah
	    glPushMatrix();
	    	glColor3f(0.3,0.5,0);
	    	glTranslatef(-78,4,15);
	    	glScaled(0.05,0.08,1.3);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    //tembox kiri atas
	    glPushMatrix();
	    	glColor3f(0.9,0.9,0.65);
	    	glTranslatef(-78,69,-12.5);
	    	glScaled(0.05,1.22,0.75);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    
	    //pagar depan
	    glPushMatrix();
		    glTranslatef(0,0,35);
			//tembok kiri depan
		    glPushMatrix();
		    	glTranslatef(-78,16,20);
		    	glScaled(0.05,0.16,.6);
		    	glutSolidCube(100);
		    glPopMatrix();
		    
		    glPushMatrix();
		    	glColor3f(0.8,0.8,0.8);
		    	glTranslatef(13.9,4,48);
				glScaled(1.9,0.08,0.05);
		    	glutSolidCube(100);
		    glPopMatrix();
		    
		    //tembox depan bawah
			glPushMatrix();
		    	glColor3f(0.9,0.9,0.65);
		    	glTranslatef(13.9,9,48);
				glScaled(1.9,0.02,0.05);
		    	glutSolidCube(100);
		    glPopMatrix();
			
			//tembok depan bawah
			glPushMatrix();
		    	glColor3f(0.4,0.4,0.4);
		    	glTranslatef(16,17,45);
				glScaled(1.83,0.15,0.05);
		    	glutSolidCube(100);
		    glPopMatrix();
			
			glPushMatrix();
		    	glColor3f(0.9,0.9,0.65);
		    	glTranslatef(108,17,48);
				glScaled(0.02,0.16,0.05);
		    	glutSolidCube(100);
		    glPopMatrix();
		    
		    glPushMatrix();
		    	glColor3f(1,0,0);
		    	glTranslatef(69,25.5,48);
				glScaled(.8,0.02,0.05);
		    	glutSolidCube(100);
		    glPopMatrix();
		    
		    glPushMatrix();
		    	glColor3f(1,0,0);
		    	glTranslatef(30,17,48);
				glScaled(0.02,0.17,0.05);
		    	glutSolidCube(100);
		    glPopMatrix();
		    
		    glPushMatrix();
		    	glColor3f(1,0,0);
		    	glTranslatef(25,18,48);
				glScaled(0.02,0.17,0.05);
		    	glutSolidCube(100);
		    glPopMatrix();
			
			glPushMatrix();
		    	glColor3f(1,0,0);
		    	glTranslatef(20,18,48);
				glScaled(0.02,0.17,0.05);
		    	glutSolidCube(100);
		    glPopMatrix();
			
			glPushMatrix();
		    	glColor3f(1,1,1);
		    	glTranslatef(82.5,22,48);
				glScaled(0.5,0.02,0.05);
		    	glutSolidCube(100);
		    glPopMatrix();
			
			glPushMatrix();
		    	glColor3f(1,1,1);
		    	glTranslatef(82.5,18,48);
				glScaled(0.5,0.02,0.05);
		    	glutSolidCube(100);
		    glPopMatrix();
	    glPopMatrix();
		
		glPushMatrix();
	    	glColor3f(1,0,0);
	    	glTranslatef(-72,65,20);
			glScaled(0.07,1.3,0.11);
	    	glutSolidCube(100);
	    glPopMatrix();	
		
		glPushMatrix();
	    	glColor3f(1,0,0);
	    	glTranslatef(-23,126.5,20);
			glScaled(1.05,0.07,0.11);
	    	glutSolidCube(100);
	    glPopMatrix(); 
		
		glPushMatrix();
	    	glColor3f(1,0,0);
	    	glTranslatef(-35,115,20);
			glScaled(0.8,0.07,0.11);
	    	glutSolidCube(100);
	    glPopMatrix(); 
		
		glPushMatrix();
	    	glColor3f(1,0,0);
	    	glTranslatef(-44,104,20);
			glScaled(0.5,0.07,0.11);
	    	glutSolidCube(100);
	    glPopMatrix();
		
		//box hitam di belakang garis merah atas
		glPushMatrix();
	    	glColor3f(0.3,0.3,0.3);
	    	glTranslatef(-25,113,-18);
			glScaled(2.2,0.66,1.3);
	    	glutSolidCube(50);
	    glPopMatrix();    
		
		//garis putih di bawah kotak hitam kiri
		glPushMatrix();
	    	glColor3f(1,1,1);
	    	glTranslatef(38,96,-18);
			glScaled(5,0.04,1.5);
	    	glutSolidCube(50);
	    glPopMatrix();
	    
	    //box hitam di atas garis putih
		glPushMatrix();
	    	glColor3f(0.3,0.3,0.3);
	    	glTranslatef(78,100,-18);
			glScaled(1.5,0.15,1.3);
	    	glutSolidCube(50);
	    glPopMatrix();
	    
	    
	    
	    //garis putih di atas garus putih kotak hitam kiri
		glPushMatrix();
	    	glColor3f(1,1,1);
	    	glTranslatef(80,98,-1);
			glScaled(2,0.04,1.8);
	    	glutSolidCube(50);
	    glPopMatrix();
	    
	    //garis putih di atas garus putih kotak hitam kiri
		glPushMatrix();
	    	glColor3f(1,1,1);
	    	glTranslatef(80,105,-15);
			glScaled(1.8,0.1,1.5);
	    	glutSolidCube(50);
	    glPopMatrix();
	    
	    //tembok depan warna hijau
		glPushMatrix();
	    	glColor3f(0.2,0.7,0.2);
	    	glTranslatef(-37,48,-18);
			glScaled(1.55,1.9,1.3);
	    	glutSolidCube(50);
	    glPopMatrix();
	    
	    //garis putih di kaca depan tembok hijau
	    glPushMatrix();
	    	glColor3f(1,1,1);
	    	glTranslatef(-37,85,19);
			glScaled(1,0.04,0.2);
	    	glutSolidCube(50);
	    glPopMatrix();
	    
	     //garis putih di kaca depan tembok hijau
	    glPushMatrix();
	    	glColor3f(1,1,1);
	    	glTranslatef(-61,60,19);
	    	glRotated(90,0,0,1);
			glScaled(1,0.04,0.2);
	    	glutSolidCube(50);
	    glPopMatrix();
	    
	    //garis putih di kaca depan tembok hijau
	    glPushMatrix();
	    	glColor3f(1,1,1);
	    	glTranslatef(-37,35,19);
			glScaled(1,0.04,0.2);
	    	glutSolidCube(50);
	    glPopMatrix();
	    
	     //garis putih di kaca depan tembok hijau
	    glPushMatrix();
	    	glColor3f(1,1,1);
	    	glTranslatef(-13,60,19);
	    	glRotated(90,0,0,1);
			glScaled(1,0.04,0.2);
	    	glutSolidCube(50);
	    glPopMatrix();
	    
	    //bg abu pada kaca dalam tembok hijau
	    glPushMatrix();
	    	glColor3f(0.3,.3,.3);
	    	glTranslatef(-37,60,13);
			glScaled(.91,.95,0.1);
	    	glutSolidCube(50);
	    glPopMatrix();
	    
	    glPushMatrix();
		    kaca(1);
		glPopMatrix();
	    
	    glPushMatrix();
		    glTranslatef(23,0,0);
		    kaca(1);
	    glPopMatrix();
	    
	    //garis merah
	    glPushMatrix();
	    	glColor3f(1,0,0);
	    	glTranslatef(15,91,20);
			glScaled(0.4,0.07,0.11);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    //garis merah
	    glPushMatrix();
	    	glColor3f(1,0,0);
	    	glTranslatef(31,45,20);
			glScaled(0.08,0.89,0.11);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    //tembok abu
	    glPushMatrix();
	    	glColor3f(0.5,.5,.5);
	    	glTranslatef(15,44,16);
			glScaled(0.26,0.87,0.11);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    //kaca pada tembok abu
	    glPushMatrix();
	    	glColor3f(0,.7,1);
	    	glTranslatef(15,80,18);
			glScaled(1.5,1,1);
	    	glutSolidCube(10);
	    glPopMatrix();
	    
	    //kaca pada tembok abu
	    glPushMatrix();
	    	glColor3f(0,.7,1);
	    	glTranslatef(15,65,18);
			glScaled(1.5,1,1);
	    	glutSolidCube(10);
	    glPopMatrix();
	    
	    //kaca pada tembok abu
	    glPushMatrix();
	    	glColor3f(0,.7,1);
	    	glTranslatef(15,50,18);
			glScaled(1.5,1,1);
	    	glutSolidCube(10);
	    glPopMatrix();
	    
	    //kaca pada tembok abu
	    glPushMatrix();
	    	glColor3f(0,.7,1);
	    	glTranslatef(15,35,18);
			glScaled(1.5,1,1);
	    	glutSolidCube(10);
	    glPopMatrix();
	    
	    //garis orange atas
	    glPushMatrix();
	    	glColor3f(1,.6,0);
	    	glTranslatef(80,94,30);
			glScaled(.9,0.02,0.19);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    //garis orange bawah
	    glPushMatrix();
	    	glColor3f(1,.6,0);
	    	glTranslatef(80,67.5,30);
			glScaled(.9,0.05,0.19);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    //garis orange pinggir kiri
	    glPushMatrix();
	    	glColor3f(1,.6,0);
	    	glTranslatef(37,80,20);
			glScaled(0.08,0.3,0.05);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    //garis orange pinggir kiri
	    glPushMatrix();
	    	glColor3f(1,.6,0);
	    	glTranslatef(37,80,40);
			glScaled(0.08,0.3,0.05);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    //garis orange pinggir kiri
	    glPushMatrix();
	    	glColor3f(1,.6,0);
	    	glTranslatef(38,90,30);
			glScaled(0.08,0.1,0.2);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    //garis orange pinggir kiri
	    glPushMatrix();
	    	glColor3f(1,.6,0);
	    	glTranslatef(38,70,30);
			glScaled(0.08,0.1,0.2);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    //garis orange pinggir kanan
	    glPushMatrix();
	    	glColor3f(1,.6,0);
	    	glTranslatef(121,79,30);
			glScaled(0.08,0.28,0.2);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    //tembok depan crime
	    glPushMatrix();
	    	glColor3f(0.9,0.9,0.75);
	    	glTranslatef(80,79,10);
			glScaled(0.8,0.28,0.2);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    //kaca depan
	    glPushMatrix();
	  		glTranslatef(35,106,28);
	    	kaca(-0.4);
	    glPopMatrix(); 
		
		//kaca depan
	    glPushMatrix();
	  		glTranslatef(50,106,28);
	    	kaca(-0.4);
	    glPopMatrix(); 
		
		//kaca depan
	    glPushMatrix();
	  		glTranslatef(65,106,28);
	    	kaca(-0.4);
	    glPopMatrix();  
	    
	    pintu(101,79,18);
	    pagar_atas();
	    
	    //tembok depan crime
	    glPushMatrix();
	    	glColor3f(0.9,0.9,0.75);
	    	glTranslatef(60,50,10);
			glScaled(0.8,0.3,0.2);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    //pintu bawah
	    pintu(78,46,18);
	    //kaca bawah
	    //kaca depan
	    glPushMatrix();
	  		glTranslatef(40,74,30);
	    	kaca(-0.4);
	    	glTranslatef(-8,0,0);
	    	kaca(-0.4);
	    	glTranslatef(-8,0,0);
	    	kaca(-0.4);
	    glPopMatrix();
		
		//garsi putih bawah depan crime
	    glPushMatrix();
	    	glColor3f(1,1,1);
	    	glTranslatef(36,43,24);
			glScaled(0.03,0.02,0.2);
	    	glutSolidCube(100);
	    glPopMatrix();
		
		//garsi hitam bawah depan crime
	    glPushMatrix();
	    	glColor3f(0.3,0.3,.3);
	    	glTranslatef(36,35,24);
			glScaled(0.03,0.15,0.2);
	    	glutSolidCube(100);
	    glPopMatrix(); 
	    
	    //garsi hitam putih bawah kiri depan crime
	    glPushMatrix();
	    	glColor3f(0.8,0.9,9);
	    	glTranslatef(36,14,24);
			glScaled(0.03,0.28,0.2);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    //garsi putih bawah depan crime
	    glPushMatrix();
	    	glColor3f(1,1,1);
	    	glTranslatef(49.5,43,34);
			glScaled(0.3,0.02,0.03);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    //garsi hitam bawah depan crime
	    glPushMatrix();
	    	glColor3f(0.3,.3,.3);
	    	glTranslatef(49.5,35,34);
			glScaled(0.3,0.15,0.03);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    //garsi hitam putih bawah depan crime
	    glPushMatrix();
	    	glColor3f(0.9,0.9,0.9);
	    	glTranslatef(68,14,34);
			glScaled(0.63,0.28,0.03);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    //garsi putih bawah depan crime
	    glPushMatrix();
	    	glColor3f(1,1,1);
	    	glTranslatef(87,43,34);
			glScaled(0.26,0.02,0.03);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    //garsi putih bawah depan pinggir kanan crime
	    glPushMatrix();
	    	glColor3f(1,1,1);
	    	glTranslatef(98.5,43,24);
			glScaled(0.03,0.02,0.2);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    //garsi hitam bawah pinggir kanan crime
	    glPushMatrix();
	    	glColor3f(0.3,0.3,0.3);
	    	glTranslatef(98.5,35,24);
			glScaled(0.03,0.15,0.2);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    //garsi hitam putih bawah pinggir kanan crime
	    glPushMatrix();
	    	glColor3f(0.8,0.9,.9);
	    	glTranslatef(98.5,14,24);
			glScaled(0.03,0.28,0.2);
	    	glutSolidCube(100);
	    glPopMatrix();
		
		  
	    
	    //garis hitam bawah depan crime
	    glPushMatrix();
	    	glColor3f(0.3,0.3,0.3);
	    	glTranslatef(87,35,34);
			glScaled(0.26,0.15,0.03);
	    	glutSolidCube(100);
	    glPopMatrix();
	      
	    //bawah depan crime
	    glPushMatrix();
	    	glColor3f(0,0.9,0.75);
	    	glTranslatef(67,33.9,24.5);
			glScaled(0.6,0.02,0.2);
	    	glutSolidCube(100);
	    glPopMatrix();
	    tangga(69,32,37);
	    
	    glPushMatrix();
	    	glRotated(90,0,1,0);
	    	tangga(-65,15,78);
	    glPopMatrix();
	    
	    //tembok smaping abu 
	    glPushMatrix();
	    	glColor3f(0.5,0.5,0.5);
	    	glTranslatef(112,78,9);
			glScaled(0.25,0.33,0.21);
	    	glutSolidCube(100);
	    	glTranslatef(0,-100,10);
	    	glScaled(1,1.2,1.5);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    //tembox kiri atas kanan
	    glPushMatrix();
	    	glColor3f(0.9,0.9,0.65);
	    	glTranslatef(140,60,-12.5);
	    	glScaled(.3,0.7,0.75);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    //tembok kanan depan
	    glPushMatrix();
	    	glTranslatef(152.5,12.8,10);
	    	glScaled(0.05,0.26,1.2);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	    /*---Garis Putih---*/
	    //garis putih di kaca depan tembok hijau
	    glPushMatrix();
	    	glColor3f(1,1,1);
	    	glTranslatef(145,85,30);
			glScaled(.6,0.04,0.2);
	    	glutSolidCube(50);
	    glPopMatrix();
	    
	    glPushMatrix();
	    	glColor3f(1,1,1);
	    	glTranslatef(145,26,30);
			glScaled(.6,0.04,0.2);
	    	glutSolidCube(50);
	    glPopMatrix();
	    
	    glPushMatrix();
	    	glColor3f(1,1,1);
	    	glTranslatef(157,26,15);
			glScaled(.2,0.04,0.8);
	    	glutSolidCube(50);
	    glPopMatrix();
	    
	    glPushMatrix();
	    	glColor3f(1,1,1);
	    	glTranslatef(157,85,15);
			glScaled(.2,0.04,0.8);
	    	glutSolidCube(50);
	    glPopMatrix();
	    
	    //garis putih di kaca depan tembok hijau
	    glPushMatrix();
	    	glColor3f(1,1,1);
	    	glTranslatef(131,55,30);
			glScaled(0.04,1.2,0.2);
	    	glutSolidCube(50);
	    glPopMatrix();
	   
	   //garis putih di kaca depan tembok crem
	    glPushMatrix();
	    	glColor3f(1,1,1);
	    	glTranslatef(155,55,-4);
			glScaled(0.2,1.2,0.04);
	    	glutSolidCube(50);
	    glPopMatrix(); 
	    /*---Garis Putih---*/
	    
	    //kaca kanan
	    glPushMatrix();
	    	glColor3f(.3,.96,1);
	    	glTranslatef(144,55.5,12);
			glScaled(0.55,1.14,0.6);
	    	glutSolidCube(50);
	    glPopMatrix();
	    
	    //garis putih
	    glPushMatrix();
	    	glColor3f(1,1,1);
	    	glTranslatef(130,25,43);
			glScaled(1.2,.04,0.2);
	    	glutSolidCube(50);
	    glPopMatrix();
		
		//garis putih
	    glPushMatrix();
	    	glColor3f(1,1,1);
	    	glTranslatef(130,25,55);
			glScaled(1.2,.04,0.2);
	    	glutSolidCube(50);
	    glPopMatrix(); 
	    
	    //garis putih
	    glPushMatrix();
	    	glColor3f(1,1,1);
	    	glTranslatef(130,25,67);
			glScaled(1.2,.04,0.2);
	    	glutSolidCube(50);
	    glPopMatrix();
	    
	    //tembok kanan depan
	    glPushMatrix();
	    	glColor3f(0.9,0.9,0.75);
	    	glTranslatef(35,48.1,-50);
	    	glScaled(2.3,.95,0.05);
	    	glutSolidCube(100);
	    glPopMatrix();
	    
	glPopMatrix();
}


void tangga(float x,float y, float z)
{
	for(int i=0;i<4;i++)
	{
		glPushMatrix();
	    	glColor3f(.8,0.8,0.8);
	    	glTranslatef(x,y-i*4,z+i*6);
			glScaled(0.1,0.06,0.1);
	    	glutSolidCube(100);
	    glPopMatrix();
	}
	
	
}

void pagar_atas(void)
{
	for(int i=0;i<=5;i++)
	{
		glPushMatrix();
			glColor3f(0,0,0);
			glTranslatef(120-i*13,74,38);
			glScaled(.02,.16,0.05);
			glutSolidCube(50);
		glPopMatrix();
	}
	
	for(int i=0;i<7;i++)
	{
		glPushMatrix();
			glColor3f(0,0,0);
			glTranslatef(80,77-i,38);
			glScaled(1.52,.007,0.1);
			glutSolidCube(50);
		glPopMatrix();	
	}
	
	
}

void pintu(float x,float y,float z)
{
	//pintu depan atas
    glPushMatrix();
    	glTranslatef(x,y,z);
    	glColor3f(0.9,0.4,0);
		glScaled(0.2,0.22,0.05);
    	glutSolidCube(100);
    glPopMatrix();
	//kaca kiri	
	for(int i=1;i<=4;i++){
		kaca_pintu(x-5.5,y+11-i*4);	
	}
	//kaca kanan
	for(int i=1;i<=4;i++){
		kaca_pintu(x+5.5,y+11-i*4);	
	}
	//gagang pintu
	glPushMatrix();
		glColor3f(.8,1,.8);
		glTranslatef(x-0.8,y+1,19);
		glScaled(.02,.15,0.1);
		glutSolidCube(50);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(.8,1,.8);
		glTranslatef(x+1.2,y+1,19);
		glScaled(.02,.15,0.1);
		glutSolidCube(50);
	glPopMatrix();
}

void kaca_pintu(float x,float z)
{
	glPushMatrix();
		glColor3f(.8,1,.8);
		glTranslatef(x,z,19);
		glScaled(.15,.02,0.1);
		glutSolidCube(50);
	glPopMatrix();
}


void kaca(float k)
{
		//kaca depan kecil
	    glPushMatrix();
	    	
	    	glScaled(k,k,k);
			//bingkai kaca depan tembok hijau
		    glPushMatrix();
		    	glColor3f(0.5,.5,0);
		    	glTranslatef(-48,82,20);
				glScaled(.3,0.05,0.1);
		    	glutSolidCube(50);
		    glPopMatrix();
		    
		    //bingkai kaca depan tembok hijau
		    glPushMatrix();
		    	glColor3f(0.5,.5,0);
		    	glTranslatef(-53.4,60,20);
				glScaled(.09,0.9,0.1);
		    	glutSolidCube(50);
		    glPopMatrix();
		    
		    //bingkai kaca depan tembok hijau
		    glPushMatrix();
		    	glColor3f(0.5,.5,0);
		    	glTranslatef(-48,38,20);
				glScaled(.3,0.05,0.1);
		    	glutSolidCube(50);
		    glPopMatrix();
						  
			//bingkai kaca depan tembok hijau
		    glPushMatrix();
		    	glColor3f(0.5,.5,0);
		    	glTranslatef(-42.4,60,20);
				glScaled(.09,0.9,0.1);
		    	glutSolidCube(50);
		    glPopMatrix();
		    
		    glPushMatrix();
		    	glColor3f(.8,1,.8);
		    	glTranslatef(-48,60,20);
				glScaled(.15,.83,0.1);
		    	glutSolidCube(50);
		    glPopMatrix();
	    glPopMatrix();	
}

void cylinder(float rbase,float rtop,float height)
{
	float i;
	glPushMatrix();
	glTranslatef(0.0,0.0,-rbase/4);
	glutSolidCone(rbase,0,32,4);
	for(i=0;i<=height;i+=rbase/8)
	{
		glTranslatef(0.0,0.0,rbase/8);
		glutSolidTorus(rbase/4,rbase-((i*(rbase-rtop))/height),16,16);
	}
	glTranslatef(0.0,0.0,rbase/4);
	glutSolidCone(rtop,0,32,4);
	glPopMatrix();
}


void drawxy(int x)
{
	glBegin(GL_LINES);
		glColor3f(1,0,0);//merah sumbux
		glVertex3f(x,0,0);
		glVertex3f(-x,0,0);
		glColor3f(0,1,0);// hijau sumbuy
		glVertex3f(0,x,0);
		glVertex3f(0,-x,0);
		glColor3f(0,0,1);//biru sumbuz
		glVertex3f(0,0,x);
		glVertex3f(0,0,-x);
	glEnd();	
}

void keyboard_s(int key,int x,int y)
{
	switch(key)
	{
		case GLUT_KEY_RIGHT:
			glRotated(-1,0,1,0);
			break;
		case GLUT_KEY_LEFT:
			glRotated(1,0,1,0);				
			break;
		case GLUT_KEY_UP:
			glRotated(-1,1,0,0);	
			break;
		case GLUT_KEY_DOWN:
			glRotated(1,1,0,0);
			break;
		case GLUT_KEY_PAGE_UP:
			xyz-=10;
			init();
			break;
		case GLUT_KEY_PAGE_DOWN:
			xyz+=10;
			init();
			break;
	}
	glutPostRedisplay();
}
void mobilbiru(float y,int i)
{
	glPushMatrix();
 	glPushMatrix();
	  	glTranslatef(mm1b[i],y,mmb[i]);// besar kecilnya mobil
		glScaled(1.3,1.3,1.3);
		glRotatef(kkb[i], 0.0f, 1.0f, 0.0f);
		glPushMatrix();//body
			//glpushmatrix();
			glColor3f(0.0,0.0,9.0);
			blok(10, 3, 2);
			
			glTranslatef(0, 9, 0);
			blok(10, 3, 2);
			glTranslatef(10, -10,0);
			blok(10, 5.5, 2);
			glRotatef(-35, 0, 0, 15);
			glTranslatef(0, 7,0);
			blok(10, 2, 2);
			glTranslatef(2, 4.9,-2.5);
			glColor3f(0.9,0.9,0.9);// warna kaca
			blok(0.5, 20, 31);
			
			glRotatef(180, 45, -45, 0);
			//glTranslatef(0, 10,0);
			//blok(3, 2, 5);
			//cylinder(2,2,30);
			//glTranslatef(-10, -10,0);
			//glRotatef(90, 45,-45, 0);
			//cylinder(2,2,30);
			//glRotatef(90, -45, 90, 90);
			//blok(5, 3, 2);
			
		glPopMatrix();	
			
		glPushMatrix();//roda
			glColor3f(0.0,0.0,0.0);
			glTranslatef(20, -8,-7);
			cylinder(5, 5,3);
			
			glColor3f(0.0,0.0,0.0);
			glTranslatef(-20, 8,7);
			glTranslatef(-5, -8,-7);
			cylinder(5, 5,3);
			
			glColor3f(0.0,0.0,0.0);
			glTranslatef(5, 8,7);
			glRotatef(180,0,180,0);
			glTranslatef(3,-8,-17);
			cylinder(5, 5,3);
			
			glColor3f(0.0,0.0,0.0);
			glTranslatef(-3,8,17);
			glTranslatef(-22,-8,-17);
			cylinder(5, 5,3);
			
			glColor3f(1.0,1.0,1.0);
			
			glRotatef(90,1,0,0);
			glTranslatef(8, 2.5,-15);
			blok(2, 4, 5);
			
			
			glRotatef(90,0,1,0);
			glTranslatef(0,-0.2,7);
			blok(2, 4, 8);
			
			
			glRotatef(0,0,0,0);
			glTranslatef(0,19.2,0);
			blok(2, 4, 8);
			
			glRotatef(90,0,1,0);
			glTranslatef(7, 0,-8);
			blok(2, 4, 5);
			
			glColor3f(9.9,9.9,0.0);//lampu
			glRotatef(90,0,1,0);
			glTranslatef(0,-3,20);
			cylinder(2, 2,3);
			
			glColor3f(9.9,9.9,0.0);//lampu
			glRotatef(0,0,0,0);
			glTranslatef(0,-12,0);
			cylinder(2, 2,3);
			
			glColor3f(0.0,0.0,0.0);//knalpot
			glRotatef(0,0,0,0);
			glTranslatef(0,0,-52);
			cylinder(1, 1,3);
			
			glColor3f(1.0,1.0,1.0);
			glRotatef(90,1,0,0);
			glTranslatef(-8,3.5,-12);
			blok(2, 4, 8);
			
			glColor3f(9.0,0.0,0.0);//lampu atas
			glRotatef(0,0,0,0);
			glTranslatef(-8,28,0);
			cylinder(1, 1,12);
		glPopMatrix();
	glPopMatrix();
	glPopMatrix();
 //glFlush();
 //glutSwapBuffers();
}


void keyboard(unsigned char key,int x, int y)
{
	switch(key)
	{
		case 'a' :
			if(gerak_bus==true)
			{
				kiri_kanan=-90;
				maju_mundur1--;
			}else if(gerak_mobil==true){
				mm1[gerak_m]-=keceptan_mobil;
				kk[gerak_m]=-180;
		    }else if(gerak_mobilbiru==true){
				mm1b[gerak_m]-=keceptan_mobil;
				kkb[gerak_m]=-180;
			}else{
				glTranslatef(-10,0,0);
			}
			break;
		case 'd' :
			if(gerak_bus==true){
				kiri_kanan=90;
				maju_mundur1++;
			}else if(gerak_mobil==true){
				mm1[gerak_m]+=keceptan_mobil;
				kk[gerak_m]=0;
		 	}else if(gerak_mobilbiru==true){
				mm1b[gerak_m]+=keceptan_mobil;
				kkb[gerak_m]=0;
			}else{
				glTranslatef(10,0,0);
			}
			break;
		case 'w' :
			if(gerak_bus==true){
				kiri_kanan=0;
				maju_mundur++;
			}else if(gerak_mobil==true){
				mm[gerak_m]+=keceptan_mobil;
				kk[gerak_m]=-90;
			}else if(gerak_mobilbiru==true){
			mmb[gerak_m]+=keceptan_mobil;
				kkb[gerak_m]=-90;
			}else{
				glTranslatef(0,0,-10);	
			}
			
			break;
		case 's' :
			if(gerak_bus==true)
			{
				kiri_kanan=180;
				maju_mundur--;
			}else if(gerak_mobil==true){
				mm[gerak_m]-=keceptan_mobil;
				kk[gerak_m]=90;
			}else if(gerak_mobilbiru==true){
				mmb[gerak_m]-=keceptan_mobil;
				kkb[gerak_m]=90;
			}else{
				glTranslatef(0,0,10);
			}	
			break;
		case '+' :
			glTranslatef(0,10,0);
			break;
		case '-' :
			glTranslatef(0,-10,0);
			break;
		case 'b':
			if(gerak_bus==true)
				gerak_bus=false;
			else
				gerak_bus=true;
			break;
		case 'm':
			if(gerak_mobil==false){
				gerak_mobil=true;
			}else{
				gerak_mobil=false;
			}
		case 'v':
				if(gerak_mobilbiru==false){
				gerak_mobilbiru=true;
			}else{
				gerak_mobilbiru=false;
			}
			break;
		case '1' :
			if(gerak_mobil==true)
				gerak_m=0;
			
			else 
				gerak_m=0;
				
			break;
		case '2' :
			if(gerak_mobil==true)	
				gerak_m=1;
			break;
		case '3' :
			gerak_m=2;
			break;
			
		case '4' :
			if(gerak_mobilbiru==true)
				gerak_m=1;
			
			else
				gerak_m=1;
				
			break;
		case '5' :
			if(gerak_mobilbiru==true)	
				gerak_m=2;
			break;
	
			
	}
	glutPostRedisplay();
}

void mobil(float y,int i)
{
 	glPushMatrix();
	  	glTranslatef(mm1[i],y,mm[i]);// besar kecilnya mobil
		glScaled(1.3,1.3,1.3);
		glRotatef(kk[i], 0.0f, 1.0f, 0.0f);
		glPushMatrix();//body
			//glpushmatrix();
			glColor3f(1.0,0.0,0.0);
			blok(10, 3, 2);
			
			glTranslatef(0, 9, 0);
			blok(10, 3, 2);
			glTranslatef(10, -10,0);
			blok(10, 5.5, 2);
			glRotatef(-35, 0, 0, 15);
			glTranslatef(0, 7,0);
			blok(10, 2, 2);
			glTranslatef(2, 4.9,-2.5);
			glColor3f(0.9,0.9,0.9);// warna kaca
			blok(0.5, 20, 31);
			
			glRotatef(180, 45, -45, 0);
			//glTranslatef(0, 10,0);
			//blok(3, 2, 5);
			//cylinder(2,2,30);
			//glTranslatef(-10, -10,0);
			//glRotatef(90, 45,-45, 0);
			//cylinder(2,2,30);
			//glRotatef(90, -45, 90, 90);
			//blok(5, 3, 2);
			
		glPopMatrix();	
			
		glPushMatrix();//roda
			glColor3f(0.0,0.0,0.0);
			glTranslatef(20, -8,-7);
			cylinder(5, 5,3);
			
			glColor3f(0.0,0.0,0.0);
			glTranslatef(-20, 8,7);
			glTranslatef(-5, -8,-7);
			cylinder(5, 5,3);
			
			glColor3f(0.0,0.0,0.0);
			glTranslatef(5, 8,7);
			glRotatef(180,0,180,0);
			glTranslatef(3,-8,-17);
			cylinder(5, 5,3);
			
			glColor3f(0.0,0.0,0.0);
			glTranslatef(-3,8,17);
			glTranslatef(-22,-8,-17);
			cylinder(5, 5,3);
			
			glColor3f(1.0,1.0,1.0);
			
			glRotatef(90,1,0,0);
			glTranslatef(8, 2.5,-15);
			blok(2, 4, 5);
			
			
			glRotatef(90,0,1,0);
			glTranslatef(0,-0.2,7);
			blok(2, 4, 8);
			
			
			glRotatef(0,0,0,0);
			glTranslatef(0,19.2,0);
			blok(2, 4, 8);
			
			glRotatef(90,0,1,0);
			glTranslatef(7, 0,-8);
			blok(2, 4, 5);
			
			glColor3f(9.9,9.9,0.0);//lampu
			glRotatef(90,0,1,0);
			glTranslatef(0,-3,20);
			cylinder(2, 2,3);
			
			glColor3f(9.9,9.9,0.0);//lampu
			glRotatef(0,0,0,0);
			glTranslatef(0,-12,0);
			cylinder(2, 2,3);
			
			glColor3f(0.0,0.0,0.0);//knalpot
			glRotatef(0,0,0,0);
			glTranslatef(0,0,-52);
			cylinder(1, 1,3);
			
			glColor3f(1.0,1.0,1.0);
			glRotatef(90,1,0,0);
			glTranslatef(-8,3.5,-12);
			blok(2, 4, 8);
			
			glColor3f(9.0,0.0,0.0);//lampu atas
			glRotatef(0,0,0,0);
			glTranslatef(-8,28,0);
			cylinder(1, 1,12);
		glPopMatrix();
	glPopMatrix();

 //glFlush();
 //glutSwapBuffers();

}

void blok(float tebal,int ratiol,int ratiop)
{
 float i,j;
 glPushMatrix();
 for(i=0;i<ratiop;i++)
 {
  glTranslatef(-(ratiol+1)*tebal/2,0.0,0.0);
  for(j=0;j<ratiol;j++)
  {
   glTranslatef(tebal,0.0,0.0);
   glutSolidCube(tebal);
  }
  glTranslatef(-(ratiol-1)*tebal/2,0.0,tebal);
 }
 glPopMatrix();
}

void kerucut(float ngisor, float nduwur, float dowo)
{
 float i;
 glPushMatrix();
 glTranslatef(1.0,0.0,ngisor/24);
 glutSolidCone(ngisor,0,32,4);
 for(i=0;i<=dowo;i+=ngisor/24)
 {
  glTranslatef(0.0,0.0,ngisor/24);
  glutSolidTorus(ngisor/4,ngisor-((i*(ngisor-nduwur))/dowo),16,16);
 }
 glTranslatef(0.0,0.0,ngisor/4);
 glutSolidCone(nduwur,0,20,1);
 glColor3f(0.,1.,1.);
 glPopMatrix();
}

void reshape (int w, int h) 
{ 
	glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
	glMatrixMode (GL_PROJECTION); 
	glLoadIdentity(); 
	glOrtho(-xyz, xyz, -minusy, xyz, -xyz, xyz); 
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 
	gluLookAt (0, 5, 0, 0, 0, 100.0, 0.0, 1.0, 0.0); 
	//gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 10.0, 0.0); 
} 

void init(void)
{
	/*
    GLfloat mat_specular[] = { 2.0, 1.0, 1.0, 1.0 }; //parameter cahaya specular 
	GLfloat mat_shininess[] = { 100.0 }; //parameter shininess 
	GLfloat light_position[] = { 1.0, 0.5, 1.0, 1.0 }; //parameter posisi pencahayaan 
	glClearColor (0.0, 0.5, 0.5, 0.0);
	//glShadeModel (GL_SMOOTH); //mengaktifkan shade model 
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); 
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess); 
	glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
	glEnable(GL_LIGHTING); //mengaktifkan pencahayaan 
	glEnable(GL_LIGHT0); //mengaktifkan sumber cayaha 
	glEnable(GL_NORMALIZE); 
	glShadeModel(GL_SMOOTH); //add positioned light 
	GLfloat lightColor0[] = {0.7f, 0.7f, 0.7f, 1.0f}; 
	GLfloat lightPos0[] = {5.0f, 7.0f, 5.0f, 1.0f}; 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0); 
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0); 
	glPopMatrix(); 
	glEnable(GL_DEPTH_TEST);
	*/
	
	glClearColor (0.0, 0.5, 0.5, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-xyz, xyz, -xyz, xyz, -xyz, xyz);
    glMatrixMode(GL_MODELVIEW);
    
    
    glShadeModel (GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); 
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("TUBES-GPC RUMAH IDAMAN");
    glutSpecialFunc(keyboard_s);
    glutKeyboardFunc(keyboard);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape); 
    glutMainLoop();
    return 0;
 }



