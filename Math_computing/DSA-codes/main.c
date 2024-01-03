#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "libs/listgen.h"
#include "libs/listfun.h"
int main()
{
	int k=2;
	int m=2;
	int n=1;

	//Load matrix
	avyuh *a=loadList("a.dat",m,n);		//vector a
	avyuh *b=loadList("b.dat",m,n);		//vector b

	//calculating points P,Q,R
	avyuh *P=Listadd(Listscale(a,2),b);
	avyuh *Q=Listsub(a,Listscale(b,3));

	avyuh *R=Listscale(Listsub(Q,Listscale(P,k)),1/1-k);

	//printing Lists
	printf("a=\n");
	printList(a);
	printf("b=\n");
	printList(b);
	printf("P=\n");
	printList(P);
	printf("Q=\n");
	printList(Q);
	printf("R=\n");
	printList(R);
}
