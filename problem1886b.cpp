#include<bits/stdc++.h>
using namespace std;
double px,py,ax,ay,bx,by;
int t;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>px>>py>>ax>>ay>>bx>>by;
		double a=sqrt(ax*ax+ay*ay);
        double b=sqrt(bx*bx+by*by);
        double c=sqrt((ax-px)*(ax-px)+(ay-py)*(ay-py));
        double d=sqrt((bx-px)*(bx-px)+(by-py)*(by-py));
		double r=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))/2.0;
		double x=max(a,c),y=max(b,d),z=max({r,a,d}),z2=max({r,b,c});
		double ans=min({x,y,z,z2});
		printf("%.7lf\n",ans);
	}
}