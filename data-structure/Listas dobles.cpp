//LISTAS DOBLE LIGADURA

#include <A.h>

struct NODO
{	int info;
	NODO *sig, *ant;
};

class LD
{	private:
		NODO *Primero, *Ultimo;
	public:
		LD(){Primero=Ultimo=NULL;}
		void insinicio(int);
		void insfinal(int);
		void insord(int);
		void visualiza();
		int delinicio();
};

void LD::insord(int x)
{	if(!Primero)
		insinicio(x);
	else
	{	NODO *p=Primero, *q=NULL;
		if(!p->sig)
		{	if(x<p->info)
				insinicio(x);
			else
				insfinal(x);
		}
		if(x<p->info)
			insinicio(x);
		else
		{	NODO *r=new NODO;
			r->info=x;
			while(x<p->info && p->sig)
			{	q=p; p=p->sig;
			}
			q->sig=r;	r->ant=q;
			r->sig=p;	p->ant=r;
		}
	}
}

void LD::insfinal(int x)
{	if(!Primero)
		insinicio(x);
	else
	{	NODO *p=new NODO;
		p->info=x;
		p->sig=NULL;
		p->ant=Ultimo;
		Ultimo->sig=p;
		Ultimo=p;
	}
}


void LD::insinicio(int x)
{	NODO *p=new NODO;
	p->info=x;
	p->ant=NULL;
	if(Primero)
	{	p->sig=Primero;
		Primero->ant=p;
		Primero=p;
	}
	else
	{	p->sig=NULL;
		Primero=Ultimo=p;
	}
}

void LD::visualiza()
{	if(!Primero)
		cout<<"NO EXISTE LISTA";
	else
	{	NODO *p=Primero;
		cout<<"Primero->";
		while(p)
		{	cout<<p->info<<"->";
			p=p->sig;
		}
		cout<<"NULL";
	}
}

int LD::delinicio()
{	int x=-1;
	if(!Primero)
		cout<<"NO HAY LISTA";
	else
	{       NODO *p=Primero;
		x=p->info;
		if(Primero==Ultimo)
		{	Primero=Ultimo=NULL;
		}
		else
		{       Primero=Primero->sig;
			Primero->ant=NULL;
		}
		delete p;
	}
	return x;
}






void main()
{	LD L1;         int x;
	clrscr();
	L1.insinicio(15); L1.insinicio(10); L1.insinicio(5);
	L1.visualiza();		cout<<endl;
	//x=L1.delinicio();
	//L1.visualiza();         cout<<endl;
	L1.insfinal(20);
	L1.visualiza();           cout<<endl;
	L1.insord(25); L1.visualiza();
	getchar();
}