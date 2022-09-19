#include<bits/stdc++.h>
using namespace std;
int const N = 5;
int const EPS = 1e-6;
#define low left
#define high right
#define sq(x) ((x) * (x))

class point{
public:
    double x,y;
    point(int x,int y){
        this->x = x;
        this->y = y;
    }
    point(){}
};

class line{
public:
    double x,y,c;
    line(int x,int y,int c){
        x = x;
        c = c;
        y = y;
    }
    line(){}
};

double getDist(int x,int y,point p){
    return sqrt(sq(x-p.x) + sq(y-p.y));
}

double compute(double x,point p[],line lineEq,int n){

    double y = -1 * ((lineEq.x * x) + lineEq.c);

    double distance = 0 ;
    for(int i=0;i<n;i++){
        distance += getDist(x,y,p[i]);
    }

    return distance;
}
double findMinDist(point p[], int n, line lineEq)
{
    double low = -1e6;
    double high = 1e6;

    while ((high - low) > EPS) {

        double mid1 = low + (high - low) / 3;
        double mid2 = high - (high - low) / 3;
 
      
        double dist1 = compute(mid1, p, lineEq, n);
        double dist2 = compute(mid2, p, lineEq, n);
 
        if (dist1 < dist2)
            high = mid2;
 
        else
            low = mid1;
    }
 
    return compute((left+right)/2,p,lineEq,n);
}


int main(){
    point p[N];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        p[i] = point(x,y);
    }

    int x,y,c;
    cin>>x>>y>>c;
    line lineEq = line(x,y,c);

    cout<<findMinDist(p,n,lineEq);


    return 0;
}



/*

input

5
-3 -2
-1 0
-1 2
1 2 
3 4
1 -1 -3


*/