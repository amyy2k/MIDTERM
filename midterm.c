//Amy Nguyen MIDTERM 3/18/20


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

//1
void count() {
printf("Enter lines of text here: .../n");
FILE* fin;
int c = 0;
int nl = 0, nc = 0, nt = 0, nbackslash = 0;
while ((c = fgetc(fin)) != EOF) {
if (c == '\n') { ++nl; }
 else if (c == '\t') { ++nt;}
 else if (c == '\\') { ++nbackslash;}
 else if (isspace(c)) { ++nc; }
printf("lines: %d\n", nl);
printf("tabs: %d\n", nt);
printf("backslashes: %d\n", nbackslash);
printf("alphanumeric: %d\n", nc);
}
}

int main(int argc, const char* argv[]) {
count();
return 0;
}

//2
//fgetc(s);

//3
//size_t prefix = strcspn(ptr,t);

//4
//exit();

//5
//FILE *fin
//fin = fopen("midterm.txt", "r");

//6
size_t strcpy(char* s, const char* t){
  char* p = s;
  while((*s++ = *t++) != '\0') {}
  return p;
}

//7
char* strncat(char* s, const char* t, size_t n){
  char* p = s;
  while (*s != '\0') { ++s; }
  while (n-- > 0 && *t != '\0') {
    *s++ = *t++;
}

//8
int strcmp(const char* s, const char* t){
  while(*s !='\0' && *t != '\0' && *s == *t){
    ++s;
    ++t;
  }
  return *s - *t;
}

//9
typedef struct point point;
struct point {double x, y;};

typedef struct square square;
struct square { point ul; size_t side; };
square* square_init(double ulx, double uly, double side) {
  square* sqr = (square*)malloc(sizeof(square));
  sqr->ul.x = ulx;
  sqr->ul.y = uly;
  sqr->side.x = side;
  return sqr;

}
void square_delete(square* sq){
  memset(sq, 0, sizeof(sq));
}
void square_move(square* sq, double x, double y){
  sq->ul.x = x;
  sq->ul.y = y;
}
void square_expandby(square* sq, double expandby){
  sq->ul.x += expandby;
  sq->ul.y += expandby;
}
double square_area(square* sq){
  double length =  sq->ul.x;
  return length * length;
}
