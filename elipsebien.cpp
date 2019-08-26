#include<iostream>
#include<math.h>
#include<graphics.h>
#include<conio.h>
using namespace std;

class Elipse
{
  private:
  	float pi;
  	int x,y,a,b,visible;
  	int stangle,endangle;
  public:
  	//constructor (lleva el mismo nombre de la clase)
  	Elipse(int inic_x=100, int inic_y=200,int inic_a=50, int inic_b=50, int inic_stan=100, int inic_enda=100)
  	{
  		x=inic_x;
  		y=inic_y;
  		a=inic_a;
  		b=inic_b;
  		stangle=inic_stan;
  		endangle=inic_enda;
		pi=3.14;
  		visible=0;
  		
	}
	void calculaArea()//tiene acceso a las variables privadas ya que es una funcion de la misma clase
	{
		cout<<"\nEl area del circulo es "<<pi*a*b;
	}
	void calculaPerimetro()
	{
	    cout<<"\nEl perimetro del circulo es "<<2*pi*sqrt((pow(a,2)+pow(b,2))/2);
	}
	void pintaElipse()
	{
		visible=1;
		ellipse(x,y,stangle,endangle,a,b);
	}
	void ocultaElipse()
	{
		unsigned guardacolor=getcolor();//tomo el color que esta activo y lo guardo en get
		if(visible)
		{
			setcolor(getbkcolor());
			ellipse(x,y,stangle,endangle,a,b);
			visible=0;
			setcolor(guardacolor);
		}
	}
	void trasladaElipse(int nx, int ny)
	{
		if(visible)
		{
			ocultaElipse();
			x=nx;
			y=ny;
			pintaElipse();
		} else
		{
			x=nx;
			y=ny;
		}
	}
	int get_x()
	{ return x;}
	
	int get_y()
	{return y;}
	
	float get_radio()
	{return b;}
	
	float get_pi()
	{return pi;}
	
	int get_visible()
	{return visible;}
};

main()
{   //activamos los graficos:
	int monitor=DETECT;
	int modo;
	initgraph(&monitor,&modo,"c:\\TC\\BGI");
  	Elipse elipobj(350,280,70);
  	elipobj.calculaArea();
  	elipobj.calculaPerimetro();
  	elipobj.pintaElipse();
  	getch();
  	//cirobj.ocultaCirculo();
  	elipobj.trasladaElipse(80,80);
  	getch();
  	for(int i=1;i<100;i++)
  	{
	  elipobj.trasladaElipse(elipobj.get_x()+i,elipobj.get_y());
	  delay(500);
	  cout<<"..";
	}
	getch();
  	
  	Elipse c1(300,180);
	c1.pintaElipse();
	getch();
	
	Elipse c2(50);
	c2.pintaElipse();
	getch();
	
    Elipse c3;
    c3.pintaElipse();
    getch();
  	closegraph();
}
