#include<stdbool.h>
#include<stdio.h>

bool match(char* s, char* t, int m, int n)
// ============================================
{
     if(s == NULL || t == NULL || m <=0 || n <= 0)
	     return false;
     if( n > m )
	     return false;        

     int i, j;
     bool match = true;        
     for(i = 0; i < m - n; i++){
	     match = true;
	     for(j = 0; j < n; j++){
		     if(s[j + i] != t[j]){
			     if(t[j] == '.')
				     continue;        
			     else{
				     match = false;    
				     break;	
			     }
	     	     }
	     }

     	     if( match == true && j == n)
	             break;
     }
     return match;
}

void main(){
	int m, n;
	m = 10, n = 5;
	char s[10] = "asdfghjkla";
	char t[5] = "sd.gh";
	
	bool a;
	a = match(s,t,m,n);
	if( a == true)
		printf("match \n");	
}
