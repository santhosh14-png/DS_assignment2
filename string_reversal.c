#include<stdio.h>
#include<string.h>

char stack[100];      
int top=-1;                             //global declaration

void push(char ch){                    //push function  
    if (top==99){
        printf("Stack overflow");      //check for overflow
        return;
    }

    top++;
    stack[top]=ch;                     //store in stack
} 

void pop(){                            //pop function
    if(top==-1){
        printf("Stack underflow");     //underflow condition
    } 
    else{
        printf("%c", stack[top]);
        top--;
    }
}

int main(){

    char word[100];
    printf("Enter a word: ");
    scanf("%s", word);
 
    int len=strlen(word);

    for(int i=0;i<len;i++){
        push(word[i]);                //pushes to stack letter by letter
    }

    for(int i=0;i<len;i++){
        pop();                       //prints top element
    }  

    return 0;
}