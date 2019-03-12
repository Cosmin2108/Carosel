#include <iostream>
#include<fstream>
using namespace std;
ifstream f("date_in.txt");
ofstream g("date_out.txt");


struct roata
{
    int nr_client;
    int nr_rotiri;
    int nr_cabina;
    struct roata *next;

};

void creare_roata(struct roata *&prim,int n)
{   struct roata *r=NULL, *ultim=NULL;
    int i;

    for(i=0;i<n;i++)
    {
        r= new struct roata;
        r->nr_client=0;
        r->nr_rotiri=0;
        r->nr_cabina=i;
        r->next=prim;
        if(prim==NULL)
           prim=ultim=r;
        else
        {
            ultim->next=r;
            ultim=r;
        }

    }

}

void invarte(struct roata *&r, int c, int i)
{
    int epty=0;

    while(epty==0)
    {
        if(r->nr_rotiri==0)
         {
             if(r->nr_client==0)
              {
                  r->nr_client=i;
                  r->nr_rotiri=c;
              }
             else
             {
                 g<<r->nr_client<<" ";
                 r->nr_client=i;
                 r->nr_rotiri=c;

             }

             epty=1;
             r=r->next;

          }
          else
          {
              r->nr_rotiri--;
              if(r->nr_rotiri==0)
              {
                 g<<r->nr_client<<" ";
                 r->nr_client=i;
                 r->nr_rotiri=c;

               epty=1;
              }
              r=r->next;
          }


    }

}

void sfarsit( struct roata *&r, int n)
{
    int nr=0;
    int last_c=0;
    while(nr!=n)
    {
        if(r->nr_rotiri==0)
        {
            nr++;
            if(r->nr_client!=0)
             {
             g<<r->nr_client<<" ";
             last_c=r->nr_cabina+1;
             r->nr_client=0;

             }
        }
        else
        {
            r->nr_rotiri--;
            nr=0;


         }
        r=r->next;

    }
     g<<"\n";
    g<<"Ultimul client "<<last_c<<"\n";
    cout<<"Roata goala\n";
}

int main()
{
   if(f==NULL)
   {cout<<"Nu"; return 0;}
   struct roata *prim=NULL;
   int n,p,c,i, money=0;
   f>>n>>p;
   creare_roata(prim,n);
   struct roata *r=prim;
   g<<"Ordinea coborarii clientilor este: ";
   for(i=1;i<=p;i++)
   {
      f>>c;
      money=money+c;
      invarte(r,c,i);
   }

   sfarsit(r,n);

   g<<"Suma castigata este: "<<money<<"\n";


   delete r;
    return 0;
}
