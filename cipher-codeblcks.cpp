#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
int i=0,j=0,n,l,v,q=0,flag = -1,up;
int po(int n)
{
if(n%2==0)
return 1;
else
return -1;
}
long double det(int n, long double *M)
{

long double *A,d=0;

int a=-1,b=0;
A= new long double[n*n];

if(n==1)
{
return (M[0]);

}
else
if(n==2)
{
return M[0]*M[3] - M[1]*M[2];
}
else
{

for(int p=0;p<n;p++)
{
	a=-1;
	for(int i=0;i<n;i++)
	{   b=0;
		for(int j=0 ;j<n;j++)
		{

		if(i!=0 && j!=p)
		{
		A[a*(n-1)+b] = M[i*n+j];
		b++;
		}
			}
			a++;
			}



		d  = d+ po(p)*M[p]*det(n-1,A);
		}

		return d;
		}
		}
int main()
{

system("cls");

srand( time( NULL ) );
char filename[20],ch,word[100];
string text,pass;
  int control;
long double *b, *a,*c,*d,*e,*f,*g,r,*x;

do{


cout<<"\n\n\t\t\t WELCOME TO CIPHER";
cout<<"\n****************************************************************************";
cout<<"\n\n\n\t\t\tMAIN MENU";
cout<<"\n\n\t\t\t1.Create a file\n\t\t\t2.Open a file\n\t\t\t3.Encrypt a file\n\t\t\t4.Decrypt a file\n\t\t\t5.Exit\n";

cout<<"\nEnter your choice(1-7):";
cin>>control;
switch(control)
{
case 1 :   {system("cls");
	cout<<"\n\n\t\t\t\t CREATE A FILE";
	cout<<"\n\n\t\tEnter the name of file to be created:\n";
		cin>>filename;
		ofstream fo(filename);
		cout<<"\n\t\tYour file is created\n\n";
		cout<<"\t\tEnter your text\n";
		cin.get();
		getline(cin, text);





		//	     	CREATING A FILE......

		fo.write(text.c_str(),strlen(text.c_str()));


		//	CALCULATING ORDER OF MATRIX FROM STRING LENGTH

		n = sqrt(strlen(text.c_str()));
		if(n*n < strlen(text.c_str()) )

		l=n+1;

		else

		l = n;

		//		DYNAMIC INTIALISATION OF TEXTARRAY A
		a= new long double[l*l];


		fo.close();
		}
		break;

case 2:		{    system("cls");
		cout<<"\n\n\t\t\t\t OPEN A FILE";

		//		OPENING A FILE..........

		cout<<"\n\n\t\tEnter the name of file to be opened:\n";
		cin>>filename;
		ifstream fin(filename);

		cout<<" \n\t\tyour text :\n";

		//	CONVERTING TEXT TO MATRIX

		while(!fin.eof())
		{

		fin.get(ch);

		cout<<ch;



		}

			fin.close();      }
			break;






case 3:		{   system("cls");//encryption
		cout<<"\n\n\t\t\t\t ENCRYPT A FILE";
			ifstream fin(filename);

		//	CONVERTING TEXT TO MATRIX

		while(!fin.eof())
		{
		fin.get(ch);

		cout<<ch;
		a[q++] = (int)ch;
			 }


		 q--;


			for(j=q;j<l*l;j++)
		 {

		  a[j] = 32;

			 }

			fin.close();


		//INTIALISING DECODING MATRIX


			 b = new long double[l*l];

			for(i=0;i<l;i++)
			  b[i]=rand()%10 + 1;


			i=1;
			for(j=0;j<l;j++)
			b[i*l+j] =b[j]*b[j==l-1? 0:j+1];

			i=2;
			for(j=0;j<l;j++)
			b[i*l+j] =b[j]+b[j==l-1? 0:j+1];

			 up=0;
			if(l>3)
			{
				for(i =3 ;i<l;i++)
			{         up =(i-2)*l;
				for(j=0;j<l;j++)
			       {

				  b[i*l+j] = b[up]*b[up+1];
				  up++;

						 }


						  }           }


			c= new long double[l*l];

		for(i=0;i<l;i++)
		{
			for(j=0;j<l;j++)
			{
				c[i*l+j]=0;

			for(int k=0;k<l;k++)
		     {

		c[i*l +j] = c[i*l +j]+ a[i*l +k]*b[k*l+j];
					}
						}
						}


	  cout<<"\n\t\tb\n" ;


	/*		for( i=0;i<l;i++)
			 {
			     cout<<"\n";
			   for(int j=0;j<l;j++)

			     cout<<b[i*l+j]<<" ";

					 }              system("pause");*/
					 ofstream fout;


			 fout.close();

				       remove(filename);
		  cout<<"\n\t\tEncryption of file data on progress....\n";

			 fout.open(filename,ios::out);
			 for(i=0;i<l;i++)
		       {
		       for(j=0 ;j<l;j++)
		       fout<<c[i*l +j]<<" ";
		       fout<<"\n";

			 }

			 fout.close();



			 cout<<"\n\t\t Encryption complete";


			x= new long double [l];

        cout<<"\n\n\t\tYour password is :\n\t";

        for(i=0;i<l;i++)
        cout<<b[i]<<" ";









			 }
			 break;

//INTERMISSION#####################################################

case 4:		{   system("cls");
			cout<<"\n\n\t\t\t\t DECRYPT A FILE";

			cout<<"\n\t\t\t Please enter your PASSWORD:\n";

            cout<<"\n\n**Press enter for spaces in your password**\n ";
			for(i=0;i<l;i++)
		       {
			cin>>x[i];
			if(x[i]!=b[i])
			flag=1;
			}


		if(flag==1)
{ cout<<"\n\t\t\tINVALID PASSWORD\n\n\t\t\tFILE PROTECTED\n\n\t\t<<<<<<<<<<<Terminating>>>>>>>>";

  exit(0);
			}


  else
  {


			r=det(l,b);
			//cout<<"DEt\t"<<r;
			if(r)
		{
			d=new long double[l*l];
			e=new long double[l*l];

			for(int z=0;z<l;z++)
		{
			for(int p=0;p<l;p++)
		{

			for(int i=0;i<l;i++)
			{

				for(int j=0 ;j<l;j++)
				{
					if(i!=z && j!=p)
						{
						d[v] = b[i*l+j];
						v=v+1;
						}
				}

			}


		e[z*l+p]=po(p+z)*det(l-1,d);
		v=0;
		}
	}
	   /*  cout<<"\n\t cofactor of decoding Matrix\n\n";

		for( i=0;i<l;i++)
		 {
		  cout<<"\n";
			for(int j=0;j<l;j++)
		 cout<<e[i*l+j]<<" ";
				 }
					     */		}

else
{
cout<<"!!!!!!!!!!!DETERMINANT ZER0";
}


		f= new long double[l*l];

		cout<<"\n\n";
		//adjoint found!!!!!!!!!!!!!!!

		for(int i=0;i<l;i++)
	{
		for(int j=0;j<l;j++)
	{
		f[i*l+j]=e[j*l + i];
		}
		}





//adjoint



		      /*	cout<<"\n\t\tADJOINT of decode. matrix";

			 for( i=0;i<l;i++)
	 { 	 cout<<"\n";
			 for(int j=0;j<l;j++)
			 cout<<f[i*l+j]<<" ";
		 }   */

		       g = new long double[l*l];

		       for(int i=0;i<l;i++)
		{
			for(j=0;j<l;j++)
			{
				g[i*l+j]=0;

			for(int k=0;k<l;k++)
		     {

		g[i*l +j] = g[i*l +j]+ c[i*l +k]*f[k*l+j];
					}
						}
						}


	   /*	cout<<"/n/n";

			 for( i=0;i<l;i++)
	 { 	 cout<<"\n";
			 for(int j=0;j<l;j++)
			 cout<<g[i*l+j]<<" ";
		 }                      */





				for(int i=0;i<l;i++)
		{
			for(int j=0;j<l;j++)
		{
			g[i*l+j]= g[i*l+j]/r;
			}
			}

      /*
		cout<<"\n\t\tYour text converted to matrix:\n";

	 for( i=0;i<l;i++)
	 {
	 cout<<"\n";
		 for(int j=0;j<l;j++)

			 cout<<a[i*l+j]<<" ";
			 }



			cout<<"\n\n\tDecrypted matrix  ";

			 for( i=0;i<l;i++)
	 {               cout<<"\n";
			 for(int j=0;j<l;j++)
			 cout<<g[i*l+j]<<" ";
		 }
			     */

		/*	cout<<"\n\n\tDecrypted text :  ";

			 for(int i=0;i<l;i++)
	 {
			 for(int j=0;j<l;j++)
			 cout<<(char)g[i*l+j];
		 }
*/
			     ofstream fout;

				       remove(filename);
		  cout<<"\n\n\n\t\tDecryption of file data on progress....\n";
		  cout<<"\n\n\t\t Decryption complete\n";

			 fout.open(filename,ios::out);
			 for(int i=0;i<l;i++)
		       {
		       for(j=0 ;j<l;j++)
		       fout<<(char)g[i*l +j];


			 }

			 fout.close();
  }
			       	     }



break;










case 5:		{

		exit(0);
		}


		break;

default: 	cout<<"\nEnter a valid choice";
			break;
				}


				}while(control);

 delete[]a,b,c,d,e,f,g,x;


return 0;
}
