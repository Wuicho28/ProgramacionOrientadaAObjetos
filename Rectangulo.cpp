#include<iostream>
#include<graphics.h>
using namespace std;
class Rectangulo
{
	private: 
	   float base, altura;
	   int x, y, vis;
	public:
	   Rectangulo(int, int, float, float);
	  void calculaArea();
	  void calculaPerimetro(); 
	  void pintaRectangulo();
	  void ocultaRectangulo();
	  void trasladaRectangulo(int, int);
};

Rectangulo::Rectangulo(int inicx=100, int inicy=150, float inicbase=100, float inicaltura=80)
{
	this->x=inicx;
	this->y=inicy;
	this->base=inicbase;
	this->altura= inicaltura;
	this->vis=0;
}
void Rectangulo::calculaArea()
{
	cout<<"\n\tEl area del rectangulo es: "<<this->base*this->altura;
}
void Rectangulo::calculaPerimetro()
{
	cout<<"\n\tEl perimetro del rectangulo es: "<<2*this->base*2*this->altura;
}
void Rectangulo::pintaRectangulo()
{
	this->vis=1;
	rectangle(this->x, this->y, this->x+this->base, this->y+this->altura);
}
void Rectangulo::ocultaRectangulo()
{
	unsigned guardarColor= getcolor();
	if(this->vis)
	{
		setcolor(getbkcolor());
		rectangle(this->x, this->y,this->x+this->base, this->y+this->altura);
		
		vis= 0;
		setcolor(guardarColor);
	}
}
void Rectangulo::trasladaRectangulo(int nx, int ny)
{
	if(this->vis)
	{
		ocultaRectangulo();
		x=nx;
		y=ny;
		pintaRectangulo();
	}
	else 
	{
	    x=nx;
		y=ny;	
	}
}
main()
{
	int pantalla = DETECT;
	int modo;
	initgraph(&pantalla, &modo, "c:\\TC\\BGI");
	Rectangulo objR1(300,350,180,95);
	objR1.calculaArea();
	objR1.calculaPerimetro();
	objR1.pintaRectangulo();
	getch();
	objR1.trasladaRectangulo(500,100);
	getch();
	closegraph();
}

