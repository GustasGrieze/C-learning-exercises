#include <stdio.h>
#include <stdbool.h>

int isInRange(int number, int low, int high){

if(low <= high)
{
    if((number >= low) && (number <= high))
    {
        return true;
    }
}
return false;

}

int main(){

int number, low, high;

printf("Enter 3 integers: ");
scanf("%d%d%d", &number, &low, &high);

int anwser = isInRange(number, low, high);
if(anwser == 1)
{
    printf("True");
}
else
{
    printf("False");
}


return 0;
}
