#include <stdio.h>

void calculation();
void getCalculationType(int option);
void calculateDensity(void);
void calculateVolume(void);
void calculateMass(void);
int exitProgram();

int option;

int density;
int volume;
int mass;

int main(void)
{
    printf("\t\t\t\t%s\t\t\t\t", "Density Calculator");

    calculation();

    printf_s("\n\n\n\n");
    return 0;
}

void calculation(void)
{
    option = 0;

    printf_s("%s", "What would you like to calculate\n\n");
    printf_s("%s", "1. Calculate for density\n");
    printf_s("%s", "2. Calculate for Volume\n");
    printf_s("%s", "3. Calculate for Mass\n");
    printf_s("%s", "4. Exit\n\n");

    scanf_s("%d", &option);

    getCalculationType(option);
}

void getCalculationType(int option)
{
    switch(option)
    {
    case 1:
        calculateDensity();
        break;

    case 2:
        calculateVolume();
        break;

    case 3:
        calculateMass();
        break;

    case 4:
        exitProgram();
        break;
    }
}

void calculateDensity(void)
{


    printf_s("%s", "Mode now set for density calculation\n\n");
    printf_s("%s", "Enter a value for the volume\n");

    scanf_s("%i", &volume);

    printf_s("%s", "Enter a value for the mass\n");

    scanf_s("%i", &mass);

    density = mass / volume;

    printf_s("%s", "Density = ");
    printf_s("%i", density);
}

void calculateVolume(void)
{
    printf_s("%s", "Mode now set for volume calculation\n\n");
    printf_s("%s", "Enter a value for the mass\n");

    scanf_s("%i", &mass);

    printf_s("%s", "Enter a value for the density\n");

    scanf_s("%i", &density);

    volume = mass / density;

    printf_s("%s", "Volume = ");
    printf_s("%i", volume);
}

void calculateMass(void)
{
    printf_s("%s", "Mode now set for mass calculation\n\n");
    printf_s("%s", "Enter a value for the density\n");

    scanf_s("%i", &density);

    printf_s("%s", "Enter a value for the volume\n");

    scanf_s("%i", &volume);

    mass = density * volume;

    printf_s("%s", "Density = ");
    printf_s("%i", mass);
}

int exitProgram()
{
    return 0;
}


