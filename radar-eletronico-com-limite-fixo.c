#include <stdio.h>

void main() {
	float velcarro, valmulta;

	// Variavel de entrada
	printf("Informe a velocidade do carro:");
	scanf("%f", &velcarro);

	if (velcarro > 80)
	{
		// Carro esta acima do limite, calcula o valor da multa
		valmulta = 7 * (velcarro - 80);
		printf("\nValor da multa: R$ %.2f", valmulta);
	}
	else
	{
		// Carro esta dentro do limite
		printf("\nVeiculo dentro do limite de velocidade");
	}

}
