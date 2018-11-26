#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

int maju_mundur=0,maju_mundur1=180,kiri_kanan=0;
bool gerak_bus=false;
int screen_width=500;//mengatur lebar screen
int screen_height=600;//mengatur tinggi screen

int toleh = 25;
void display();
void drawxy(int);
void cylinder(float rbase,float rtop,float height);
void kaca(float);
void pintu(float,float,float);
void kaca_pintu(float,float);
void pagar_atas();
void tangga(float,float,float);
void rumah();
void jalan();
void bus();

//GLfloat ambient_light[]={0.3,0.3,0.45,1.0};
GLfloat ambient_light[]={0.0,0.0,0.45,1.0};//GL_LIGHT0, GL_LIGHT1, GL_LIGHT2, GL_LIGHT3
//GLfloat  source_light[]={0.9,0.8,0.8,1.0};
GLfloat  source_light[]={0.8,0.8,0.8,1.0};
//GLfloat     light_pos[]={7.0,0.0,1.0,1.0};
GLfloat     light_pos[]={5.0,0.0,6.0,1.0};
 
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    //drawxy(200);
    rumah();
    jalan();
	bus();
    glFlush();
}

void bus()
{
	glPushMatrix();
		glTranslatef(maju_mundur1,27,maju_mundur);
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

void jalan()
{
	//tembok kiri bawah
    glPushMatrix();
    	glColor3f(0.1,0.1,0.1);
    	glTranslatef(-78,0,110);
    	glScaled(6,0.01,.6);
    	glutSolidCube(100);
    glPopMatrix();
}

void rumah()
{
	glPushMatrix();
	    
	    glTranslatef(0,0,0);
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

void init(void)
{
    glClearColor (0.0, 0.5, 0.5, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-200.0, 200.0, -50.0, 200.0, -200.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
    
    /*
    glEnable (GL_LIGHTING); // pemanggilan parameter lihghting
	glLightModelfv  (GL_LIGHT_MODEL_AMBIENT,ambient_light);
	//glLightfv (GL_LIGHT0,GL_DIFFUSE,source_light);
	//glLightfv (GL_LIGHT0,GL_POSITION,light_pos);
	glEnable (GL_LIGHT0);
	glEnable (GL_COLOR_MATERIAL);
	glColorMaterial (GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
    */
    glShadeModel (GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
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
	}
	glutPostRedisplay();
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
			}else{
				glTranslatef(-1,0,0);
			}
			break;
		case 'd' :
			if(gerak_bus==true)
			{
				kiri_kanan=90;
				maju_mundur1++;
			}else{
				glTranslatef(1,0,0);
			}
			break;
		case 'w' :
			if(gerak_bus==true)
			{
				kiri_kanan=0;
				maju_mundur++;
			}else{
				glTranslatef(0,0,-1);	
			}
			
			break;
		case 's' :
			if(gerak_bus==true)
			{
				kiri_kanan=180;
				maju_mundur--;
			}else{
				glTranslatef(0,0,1);
			}	
			break;
		case '+' :
			glTranslatef(0,1,0);
			break;
		case '-' :
			glTranslatef(0,-1,0);
			break;
		case 'b':
			if(gerak_bus==true){
				gerak_bus=false;
			}else{
				gerak_bus=true;
			}
			//++;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bus");
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard_s);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    return 0;
 }