#include "temperature.h"

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0f / 5.0f) + 32.0f;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0f) * 5.0f / 9.0f;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15f;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15f;
}


float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}


#ifndef TESTING
void categorize_temperature(float celsius) {
    printf("Temperature category: ");
    if (celsius < 0) {
        printf("Freezing\nWeather advisory: Stay warm.\n");
    } else if (celsius < 10) {
        printf("Cold\nWeather advisory: Wear a jacket.\n");
    } else if (celsius < 25) {
        printf("Comfortable\nWeather advisory: None. Enjoy the Weather!.\n");
    } else if (celsius < 35) {
        printf("Hot\nWeather advisory: Stay hydrated.\n");
    } else {
        printf("Extreme Heat\nWeather advisory: Stay indoors to avoid heatstroke.\n");
    }
}

int main() {
    float temperature, converted_temp;
    int input_scale, output_scale;
    
    printf("Enter the temperature: ");
    while (scanf("%f", &temperature) != 1) {
        printf("Invalid input. Please enter a numeric value: ");
        while (getchar() != '\n'); //clearing the buffer
    }

    printf("Choose your temperature's scale: (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    while (scanf("%d", &input_scale) != 1 || input_scale < 1 || input_scale > 3) {
        printf("Invalid choice. Enter 1, 2, or 3: ");
        while (getchar() != '\n');
    }

    printf("Choose the scale to convert to: (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    while (scanf("%d", &output_scale) != 1 || output_scale < 1 || output_scale > 3 || output_scale == input_scale) {
        printf("Invalid choice. Enter 1, 2, or 3 (different from input scale): ");
        while (getchar() != '\n');
    }

    //Conversions
    if (input_scale == 1) { //Celsius
        if (output_scale == 2) converted_temp = celsius_to_fahrenheit(temperature);
        else converted_temp = celsius_to_kelvin(temperature);
    } else if (input_scale == 2) { //Fahrenheit
        if (output_scale == 1) converted_temp = fahrenheit_to_celsius(temperature);
        else converted_temp = fahrenheit_to_kelvin(temperature);
    } else { //Kelvin
        if (temperature < 0) {
            printf("Error: Kelvin temperature cannot be negative.\n");
            return 1;
        }
        if (output_scale == 1) converted_temp = kelvin_to_celsius(temperature);
        else converted_temp = kelvin_to_fahrenheit(temperature);
    }
    
    //Printing results
    printf("Converted temperature: %.2f %s\n", converted_temp, 
           (output_scale == 1) ? "C" : (output_scale == 2) ? "F" : "K");
    
    categorize_temperature((output_scale == 1) ? converted_temp :
                           (output_scale == 2) ? fahrenheit_to_celsius(converted_temp) :
                           kelvin_to_celsius(converted_temp));
    
    return 0;
}
#endif