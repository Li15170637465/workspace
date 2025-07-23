// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #include<math.h>

// typedef struct{
//     float x;
//     float y;
// } Point;

// float Distance(float diffx,float diffy){
//     float diffx2 = diffx * diffx;
//     float diffy2 = diffy * diffy;
//     float diffx2y2 = diffx2 + diffy2;
//     float distancexy = 0.0;
//     distancexy = sqrt(diffx2y2);
//     return distancexy;
// }

// float diffX(float x1, float x2){
//     return (x1 - x2);
// }
// float diffY(float y1, float y2){
//     return (y1 - y2);
// }

// int main(){
//     Point point1 = {1.0, 2.0};
//     Point point2 = {3.5, 4.2};
//     printf("%.2f,%.2f", point1.x, point1.y);
//     printf("%.2f,%.2f", point2.x, point2.y);
//     float diffx = diffX(point1.x, point2.x);
//     float diffy = diffY(point1.y, point2.y);
//     float distance = Distance(diffx, diffy);
//     printf("\n%.2f", distance);
//     return 0;
// }

/

#include <stdio.h>

struct Dog
{
    char *name;
    int age;
    double weight;
};

char *say(struct Dog dog)
{
    static info[50];
    sprintf(info, "name=%s age=%d weight=%.2f", dog.name, dog.age, dog.weight);
    return info;
}

int main()
{
    struct Dog dog;
    char *info = NULL;
    dog.name = "wa";
    dog.age = 1;
    dog.weight = 3.1;
    info = say(dog);
    printf("dog:%s\n", info);
    return 0;
}


#include<stdio.h>
#include<stdlib.h>
int *random(int (*p)()){
    int num = (*p)();
    return num;
}

int main(){
    int (*p)() = rand;
    int *randomnum=random(p);
    printf("%d\n", &randomnum);

    return 0;
}