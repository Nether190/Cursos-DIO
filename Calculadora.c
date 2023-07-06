#include <stdio.h>

int main()
{   
    int loop = 1;
    while(loop){
    int op;
    printf("Operações:\n1)Somar\n2)Subtrair\n3)Multiplicar\n4)Dividir\n\n");
    scanf("%d", &op);
    
    double num1, num2;
    printf("Digite os dois números: ");
    scanf("%lf %lf", &num1, &num2);
    
    double resposta;
    switch(op){
        case 1:
            resposta = num1 + num2;
            break;
        case 2:
            resposta = num1 - num2;
            break;
        case 3:
            resposta = num1 * num2;
            break;
        case 4:
            resposta = num1 / num2;
            break;
    }
    
    printf("a resposta é %g.\nDeseja continuar? y/n ", resposta);
    char continuar;
    scanf(" %c", &continuar);
    loop = continuar == 'y' ? 1 : 0;
    }
    return 0;
}
