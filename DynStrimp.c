#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>


                             //Scaning array


void scar(char* ptr){

fgets(ptr, 21, stdin);

int size = strlen(ptr)-1;

if(ptr[size] == '\n'){ptr[size] = '\0'; }



}


                            //Copying functions
char* my_strcpy(char *dest, const char *src){

int slen = strlen(src)+1;//1 for \0

dest = realloc(dest, slen);
//checking
if(dest == NULL){

perror("That's sad but there's an reallocing error");
exit(1);

}


//proccess of copying
for(int i = 0 ; i < slen ; ++i){

dest[i] = src[i];

}

return dest;

}

char* my_strncpy(char *dest, const char *src, size_t n){


 
dest = realloc(dest, n+1);
//checking
if(dest == NULL){
  
  perror("That's sad but there's an reallocing error");
  exit(1);
  
}

//cover the case if src < n
if(strlen(src) < n){

n = strlen(src);

}  
  
//proccess of copying
for(int i = 0 ; i < n ; ++i){
  
dest[i] = src[i];
  
}

dest[n] = '\0';

  
return dest;

}

                              //Concatination 

char* my_strcat(char *dest, const char *src){
//if dest is NULL realloc'll act as a malloc
if(dest ==NULL){
perror("Dest is NULL pointer");
exit(1);

}


int dlen = strlen(dest);
int slen = strlen(src);

dest = realloc(dest, dlen+slen+1);
if(dest == NULL){
perror("Error while reallocing");
exit(1);
}

for(int i = 0 ; i <= slen ; ++i, ++dlen){

dest[dlen] = src[i];

}

return dest;

}


char* my_strncat(char *dest, const char *src, size_t n){

if(dest == NULL) {
        perror("Dest is NULL pointer");
        exit(1);
    }

    int dlen = strlen(dest);
    int slen = strlen(src);

    dest = realloc(dest, dlen + n + 1);
    if(dest == NULL) {
        perror("Error while reallocing");
        exit(1);
    }

	if(slen < n){

			n = slen;

		}

    for(int i = 0; i < n ; ++i) {
        dest[dlen+i] = src[i];
    }

	dest[dlen + n] = '\0';

    return dest;


}


 				//Comparing FUNCTIONS

int my_strncmp(const char *str1, const char *str2, size_t n){

int i;

int fsize = strlen(str1);
int lsize = strlen(str2);

if(fsize >= n){n = fsize;}

if(lsize >= n){n = lsize;}

for(i = 0 ; i < n  ; ++i){

if(str1[i] > str2[i]){return 1;}

else if(str1[i] < str2[i]){return -1;}

}

return 0;
}

int my_strcmp(const char *str1, const char *str2) {
    int i;
	int fsize = strlen(str1);
	int lsize = strlen(str2);
   for (i = 0; i < fsize && i < lsize; ++i) {
      if (str1[i] > str2[i]) {
            return 1; 
       } else if (str1[i] < str2[i]) {
            return -1; 
        }
    }

    
if (str1[i] != '\0') {
        return 1;  // str1 is longer
    } else if (str2[i] != '\0') {
        return -1; // str2 is longer
    }

    return 0; 
}

			//FINDING SIIZE

size_t my_strlen(const char *str){

size_t size = 0;

for(int i = 0; str[i] != '\0' ; ++i){

size++;

}

return size;

}


 			//STRING SEARCHING

const char* my_strchr(const char *str, int c){



for(int i = 0 ; str[i] != '\0'; ++i ){

if(str[i] == c){

const char* ptr = &str[i];

return ptr;


}



}
return NULL;

}

const char* my_strrchr(const char *str, int c){

int size = strlen(str);

const char* ptr = NULL;
 
if(c == '\0'){

ptr = &str[size];
return ptr;

}

for(int i = 0 ; str[i] != '\0'; ++i){

if(str[i] == c){

ptr = &str[i];

}

}
return ptr;
}

const char* my_strstr(const char *str, const char *substr){

int i = 0;

while(str[i] != '\0'){


if(str[i] == substr[0]){
int i2 = i;

for(int j = 0; str[i2] == substr[j]; ++i2, ++j){

if(str[i2] != substr[j]){
i2 = 0;
break;

}

}
if(i2 != 0){

const char* ptr = &str[i];
return ptr;
}
}
++i;
}
return NULL;
}
//That's it!
