#include <iostream>
#include <cstring>
using namespace std;    

int hash(char* str) {
  int h = 0;
  int x = 17;
  int M = 2333;

  for (int i=strlen(str)-1; i>=0; i--) {
  	h = h*x + int(str[i]);
	h = h % M;
  }
  return h;
}

char *strStr(char *haystack, char *needle) {
  if (haystack==NULL) return NULL;
  if (needle==NULL) return haystack;
 
  int len_haystack = strlen(haystack);
  int len_needle = strlen(needle); 
  char str[len_needle+1];
  int i;
  for (i=0; i<=(len_haystack-len_needle); ++i) {
    strncpy(str, haystack+i, len_needle); 
    str[len_needle] = '\0';
    if ( hash(needle) == hash(str) ) return haystack+i;
  }
  return NULL;
}

char *strStr2(char *haystack, char *needle) {
  if (haystack==NULL) return NULL;
  if (needle==NULL) return haystack;

  bool find = true;
  int i, j;
  for (i=0; i!=strlen(haystack); ++i) {
    find = true;
    int k = i;
    //cout << *(haystack+i) << endl;
    for (j=0; j!=strlen(needle);) {
      //cout << *(haystack+k) << " " << *(needle+j) << endl;
      if ( *(haystack+k)==*(needle+j) ) { ++k; ++j;}
      else {find=false; break;}
    }
    if (find) break;  
  }  
  if (find) return haystack+i;
  else return NULL;
}



int main()
{
  char str1[] = "hello world";
  char str2[] = "world";

  char *p = strStr(str1, str2);
  //cout << endl;
  cout << *p << endl;
}

