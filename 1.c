#include <iostream>
#include <math.h>

using namespace std;

int main(){
	float c,a,b,n,m;

	cout <<"Enter numbers for A and B\n";
    cin >> a;
    cin >> b;
    c=a-b;
	if(a>=b){
		n=pow(c, 1./3);
		cout << n <<"\n";	
	}	
	else
	if(a<b){
		n=a*a+(a-b)/sinl(a*b);
		cout << n <<"\n";
	}
	if(n<b){
		m=(n-a)/(-b)+pow((pow((sinl(a)),2)-cosl(n)), 1./2);
		cout << m <<"\n";
	}
	else
	if(n==b){
		m=b*b+tan(n*a);
		cout << m <<"\n";
	}
	else
	if(n>b){
		m=pow(b,3)+n*a*a;
		cout << m <<"\n";
	}
	cout << "a="<< a <<"\n";
	cout << "b="<< b <<"\n";
	cout << "m="<< m <<"\n";
	cout << "n="<< n <<"\n";
	
	
  
  
  
  
	
	
	return 0;
}

#include <iostream>
#include <math.h>

using namespace std;
 int main(){
 	float a,b,z,t,c;
 	cout <<"Enter a\n";
 	cin >> a;
 	cout << "Enter b\n";
 	cin >> b;
 	c=a*a-b*b;
 	c=sqrt(pow(c, 2));
 	cout << c;
 	
 	if(a<b){
 		z=pow(c, 1./2);
 		
	 }
	 else
	 if(a>=b){
	 	z=1-2*cosl(a)*sinl(b);
     }
     if(z<b){
     	t=pow((z+a*a*b), 1./3);
	 }
     else
     if(z==b){
     	t=1-log10(z)+cosl(a*a*b);
	 }
     else
     if(z>b){
     	t=1/cosl(z*a);
	 }
     cout << "a="<< a <<"\n";
     cout << "b="<< b <<"\n";
	 cout << "z="<< z <<"\n";
	 cout << "t="<< t <<"\n";
     return 0;}
     
     
     
     
     
     
     
     
     
     
     #include <iostream>
#include <math.h>

using namespace std;
 int main(){
 	float a,b,y,t,aa,bb;
 	cout <<"Enter a\n";
 	cin >> a;
 	cout << "Enter b\n";
 	cin >> b;

 	if(a<=b){
 		y=((a-b)/(a+b))*((a=b)/a*a-a*b+b*b);
 		
	 }
	 else
	 if(a>b){
	 	y=a+log(b*b);
     }
     if(y<b){
     	t=(2*y+pow((y*y-a), 1./2))/(2*b-pow((a*a-y), 1./2));
	 }
     else
     if(y==b){
     	t=sinl(y)*sinl(y)+1/(tan(a-b));
	 }
     else
     if(y>b){
     	aa=cbrt(y*sinl(a));
     	bb=sqrt(y*cosl(b));
     	cout << aa<<"\n";
     	cout << bb<<"\n";
     	t=cbrt(y*sinl(a))+1/sqrt(y*cosl(b));
     //	t=cbrt(aa)+1/bb;
	 }
     cout << "a="<< a <<"\n";
     cout << "b="<< b <<"\n";
	 cout << "y="<< y <<"\n";
	 cout << "t="<< t <<"\n";
     return 0;}
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      #include <iostream>
#include <math.h>

using namespace std;
 int main(){
 	float a,x,y,t;
    a = 3.5; x = -0.5; 
    if(a<=b){
 		y=
 		
	 }
	 else
	 if(a>b){
	 	y=a+log(b*b);
     }
     if(y<b){
     	t=(2*y+pow((y*y-a), 1./2))/(2*b-pow((a*a-y), 1./2));
	 }
     else
     if(y==b){
     	t=sinl(y)*sinl(y)+1/(tan(a-b));
	 }
     else
     if(y>b){
     	t=cbrt(y*sinl(a))+1/pow(y*cosl(b), 1./2);
     //	t=cbrt(aa)+1/bb;
	 }

     cout << "b="<< b <<"\n";
	 cout << "y="<< y <<"\n";
	 cout << "t="<< t <<"\n";
     return 0;}
