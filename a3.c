#include<stdio.h>

void accept(int m[20][20], int r, int c );
void display(int m[20][20], int r, int c);
void gcomp(int m[20][20], int r, int c, int comp[20][3]);
void gdisplay(int comp[20][3], int k, int c);
void stran(int comp[20][3]);
void ftran(int comp[20][3]);

void main(){

	int m[20][20],comp[20][3];
	int r,c,ch;

	printf("\n\t Enter no. of rows : ");
	scanf("%d",&r);
	printf("\n\t Enter no. of columns : ");
	scanf("%d",&c);

	accept(m,r,c);

    do{
    	printf("\n\t\t\t Menu ");
    	printf("\n\t 1. Display Matrix");
    	printf("\n\t 2. Simple Transpose of Matrix");
    	printf("\n\t 3. Fast Transpose of Matrix");
    	printf("\n\t 4. Exit");

    	printf("\n\t Please Enter your choice : ");
    	scanf("%d",&ch);

    	switch(ch){
    	case 1 : display(m,r,c);
    		     break;

    	case 2 : gcomp(m,r,c,comp);
    		     stran(comp);
    	     	 break;
    	case 3 :  gcomp(m,r,c,comp);
    		 	  ftran(comp);
    	 	 	  break;
    	case 4 : printf("\n\t Thank You.");
    			 break;
    	default :  printf("\n\t Invalid Choice. Please ReEnter ");
        		   break;
    	}
    }while(ch!=4);

}

void accept(int m[20][20], int r, int c){
	int i,j;

	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("\n\t Enter value : ");
			scanf("%d",&m[i][j]);
		}
	}

}

void display(int m[20][20], int r, int c){

	int i,j;
	printf("\n\t Matrix is ");
	for(i=0;i<r;i++){
		printf("\n");
		for(j=0;j<c;j++){
			printf("\t %d",m[i][j]);
		}
	}
}

void gcomp(int m[20][20], int r, int c, int comp[20][3]){
	int i,j,k;
	k=1;

	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(m[i][j]!=0){
				comp[k][0]=i;
				comp[k][1]=j;
				comp[k][2]=m[i][j];
			    k++;
			}
		}
	}
	comp[0][0]=r;
	comp[0][1]=c;
	comp[0][2]=k-1;
	printf("\n\t Compact Matrix is ");
	gdisplay(comp,k,3);

}

void gdisplay(int comp[20][3], int k, int c){
	int i,j;

	for(i=0;i<k;i++){
		printf("\n");
		for(j=0;j<3;j++){
			printf("\t %d",comp[i][j]);
		}
	}

}

void stran(int comp[20][3]){
	int i,j,k=1;
	int trans[20][3];

	for(i=0;i<comp[0][1];i++){
		for(j=1;j<=comp[0][2];j++){
			if(comp[j][1]==i){
				trans[k][0]=comp[j][1];
				trans[k][1]=comp[j][0];
				trans[k][2]=comp[j][2];
			    k++;
			}
		}
	}
    trans[0][0]=comp[0][1];
    trans[0][1]=comp[0][0];
    trans[0][2]=comp[0][2];

	printf("\n\t Simple Transpose of compact Matrix is ");
    gdisplay(trans,k,3);
}

void ftran(int comp[20][3]){
	int i,rterm[20],rpos[20],loc,tran[20][3];

	for(i=0;i<comp[0][1];i++){
	rterm[i]=0;
	}
	for(i=1;i<=comp[0][2];i++){
		rterm[comp[i][1]]++;
	}
	rpos[0]=1;
	for(i=1;i<comp[0][1];i++){
		rpos[i]=rterm[i-1]+rpos[i-1];
		}

		for(i=1;i<=comp[0][2];i++){
			loc=rpos[comp[i][1]];
			tran[loc][0]=comp[i][1];
			tran[loc][1]=comp[i][0];
			tran[loc][2]=comp[i][2];
			rpos[comp[i][1]]++;
		}

	tran[0][0]=comp[0][1];
	tran[0][1]=comp[0][0];
	tran[0][2]=comp[0][2];

	printf("\n\t Fast Transpose of Compact Matrix is ");
	gdisplay(tran,tran[0][2]+1,3);
}
