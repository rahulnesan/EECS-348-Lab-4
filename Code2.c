#include <stdio.h>

float celsius_to_fahrenheit(float celsius) {
    return (9.0 / 5.0) * celsius + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: It's freezing, stay warm.\n");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius >= 10 && celsius < 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius >= 25 && celsius < 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Stay hydrated, it's hot.\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors, it's extremely hot.\n");
    }
}

int main() {
    float temp, converted_temp;
    int input_scale, output_scale;

    while (1) {
        
        printf("Enter the temperature (or -100000 to exit): ");
        scanf("%f", &temp);

        if (temp == -100000) {
            break;  
        }

        
        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &input_scale);

        
        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &output_scale);

        
        if (input_scale == output_scale) {
            printf("Invalid conversion: Cannot convert to the same scale.\n");
            continue;
        }

        
        if (input_scale == 1) {
            if (output_scale == 2) {
                converted_temp = celsius_to_fahrenheit(temp);
                printf("Converted temperature: %.2f°F\n", converted_temp);
            } else if (output_scale == 3) {
                converted_temp = celsius_to_kelvin(temp);
                printf("Converted temperature: %.2fK\n", converted_temp);
            }
        } else if (input_scale == 2) {
            if (output_scale == 1) {
                converted_temp = fahrenheit_to_celsius(temp);
                printf("Converted temperature: %.2f°C\n", converted_temp);
            } else if (output_scale == 3) {
                converted_temp = fahrenheit_to_kelvin(temp);
                printf("Converted temperature: %.2fK\n", converted_temp);
            }
        } else if (input_scale == 3) {
            if (output_scale == 1) {
                converted_temp = kelvin_to_celsius(temp);
                printf("Converted temperature: %.2f°C\n", converted_temp);
            } else if (output_scale == 2) {
                converted_temp = kelvin_to_fahrenheit(temp);
                printf("Converted temperature: %.2f°F\n", converted_temp);
            }
        } else {
            printf("Invalid input scale.\n");
            continue;
        }

        
        if (output_scale == 1) {
            categorize_temperature(converted_temp); 
        } else if (output_scale == 2) {
            categorize_temperature(fahrenheit_to_celsius(converted_temp)); 
        } else if (output_scale == 3) {
            categorize_temperature(kelvin_to_celsius(converted_temp)); 
        }
    }

    return 0;
}
