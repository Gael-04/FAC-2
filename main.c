#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

float a, b, c, delta = 0, x1 = 0, x2 = 0;
char bool = 's';

int main()
{
    setlocale(LC_ALL, "Portuguese_Brasil");

    printf("\n*********************************************\n");
    printf("*   SIMPLIFICADOR DE EQUAÇÕES DE 2° GRAU    *\n");
    printf("*********************************************\n\n");

    while( (bool == 's' || bool == 'S') && (bool != 'n' && bool != 'N')){
        printf("Insira o valor do coeficiente a: \n");
        scanf("%f", &a);

        while(a == 0){
             printf("O valor do coeficiente 'a' deve ser diferente de 0, insira outro valor: \n");
             scanf("%f", &a);
        }
        

        printf("Insira o valor do coeficiente b: \n");
        scanf("%f", &b);
        printf("Insira o valor do coeficiente c: \n");
        scanf("%f", &c);

        if(b >= 0 && c >= 0){
            printf("\nA equação é: %.1fx² + %.1fx + %.1f\n", a, b, c);
        }
        else{
            if(b < 0 && c >= 0)
            {
                printf("\nA equação é: %.1fx² %.1fx + %.1f\n", a, b, c);
            }
            else{
                if(b < 0 && c < 0)
                {
                    printf("\nA equação é: %.1fx² %.1fx %.1f\n", a, b, c);
                }
                else{
                    printf("\nA equação é: %.1fx² + %.1fx %.1f\n", a, b, c);
                }

            }
        }

        delta = b*b + (4*a*c);

        if (delta < 0)
        {
            printf("\nDelta menor que 0, equação irredutível, não há raízes reais.");
        }
        else{
            x1 = ((-1*b) + pow (delta, 1/2) ) / 2*a;
            x2 = ((-1*b) - pow (delta, 1/2) ) / 2*a;

            if(x1 >= 0 && x2 >= 0){
                printf("\nA equação reduzida é: %.1f * (x - %.1f) * (x - %.1f)", a, x1, x2);
            }
            else{
                if (x1 < 0 && x2 >= 0)
                {
                    printf("\nA equação reduzida é: %.1f * (x - (%.1f)) * (x - %.1f)", a, x1, x2);
                }
                else{
                    if (x1 < 0 && x2 < 0)
                    {
                        printf("\nA equação reduzida é: %.1f * (x - (%.1f)) * (x - (%.1f))", a, x1, x2);
                    }
                    else{
                        printf("\nA equação reduzida é: %.1f * (x - %.1f) * (x - (%.1f))", a, x1, x2);
                    }
                    
                }
                
            }
        }
        printf("\n\n**************************************************************************\n");
        printf("*   Deseja calular outra equação? Digite 's' para sim e 'n' para não:    *\n");
        printf("**************************************************************************\n\n");
        scanf("%s", &bool);
    }

    return 0;
}