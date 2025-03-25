//Program Name: EECS 348 Lab 7 problem 2
//Program Discription and Purpose: converting temp from one unit to another based on user choice
//Input: provided by user (user is prompted)
//Output: converted temp and weather advisory
//Collaborators: no collaborators
//Sources: ChatGPT (used chatgpt for error checking and some print statments)
//Author Name: Rund Al-kofahi
//Creation Date: 3/23/2025

#include "temperature.h"

float celsius_to_fahrenheit(float celsius) {  //function to convert a C temp to F
    return (celsius * 9.0f / 5.0f) + 32.0f;  //returns the converted value (the conversion is done following the formula given)
}

float fahrenheit_to_celsius(float fahrenheit) {  //function to convert a F temp to C
    return (fahrenheit - 32.0f) * 5.0f / 9.0f;  //returns the converted value (the conversion is done following the formula given)
}

float celsius_to_kelvin(float celsius) {  //function to convert a C temp to K
    return celsius + 273.15f;  //returns the converted value (the conversion is done following the formula given)
}

float kelvin_to_celsius(float kelvin) {  //function to convert a K temp to C
    return kelvin - 273.15f;  //returns the converted value (the conversion is done following the formula given)
}


float fahrenheit_to_kelvin(float fahrenheit) {  //function to convert a F temp to K
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));  //returns the converted value (the conversion is done following the formula given)
}

float kelvin_to_fahrenheit(float kelvin) {  //function to convert a K temp to F
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));  //returns the converted value (the conversion is done following the formula given)
}

void categorize_temperature(float celsius) {  //function to categorize the temp. It takes in a temp in C and prints the category and a weather advisory
    printf("Temperature category: ");
    if (celsius < 0) { //if temp in C < 0,
        printf("Freezing\nWeather advisory: Stay warm.\n");  //this is the category and advisory
    } else if (celsius < 10) {  //if temp in 0 < C < 10,
        printf("Cold\nWeather advisory: Wear a jacket.\n");  //this is the category and advisory
    } else if (celsius < 25) {  //if temp in 10 < C < 25,
        printf("Comfortable\nWeather advisory: None. Enjoy the Weather!.\n");  //this is the category and advisory
    } else if (celsius < 35) {  //if temp in 25 < C < 35,
        printf("Hot\nWeather advisory: Stay hydrated.\n");  //this is the category and advisory
    } else {  //if temp is more
        printf("Extreme Heat\nWeather advisory: Stay indoors to avoid heatstroke.\n");  //this is the category and advisory
    }
}

int main() {
    float temperature, converted_temp;  //initilizing temps
    int input_scale, output_scale;  //and scales
    
    printf("Enter the temperature: ");
    while (scanf("%f", &temperature) != 1) {  //scanning user input for temp and checking if it is valid
        printf("Invalid input. Please enter a numeric value: ");  //if invalid, print that they are invalid
        while (getchar() != '\n'); //clearing the buffer
    }

    printf("Choose your temperature's scale: (1) Celsius, (2) Fahrenheit, (3) Kelvin: "); 
    while (scanf("%d", &input_scale) != 1 || input_scale < 1 || input_scale > 3) {  //scanning user input for their temp scale and checking if it is valid
        printf("Invalid choice. Enter 1, 2, or 3: ");  //if invalid, print that they are invalid
        while (getchar() != '\n');  //clearing the buffer
    }

    printf("Choose the scale to convert to: (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    while (scanf("%d", &output_scale) != 1 || output_scale < 1 || output_scale > 3 || output_scale == input_scale) {  //scanning user input for the  scale they want their temp converted to and checking if it is valid
        printf("Invalid choice. Enter 1, 2, or 3 (different from input scale): ");  //if invalid, print that they are invalid
        while (getchar() != '\n');  //clearing the buffer
    }

    //Conversions
    if (input_scale == 1) { //Celsius
        if (output_scale == 2) converted_temp = celsius_to_fahrenheit(temperature);  //if output scale is F, convert temp to F
        else converted_temp = celsius_to_kelvin(temperature);  //else, convert it to K
    } else if (input_scale == 2) { //Fahrenheit
        if (output_scale == 1) converted_temp = fahrenheit_to_celsius(temperature); //if output scale is C, convert temp to C
        else converted_temp = fahrenheit_to_kelvin(temperature);  //else, convert it to K
    } else { //Kelvin
        if (temperature < 0) {  //for K, a negative temp would be invalid. If user input - temp,
            printf("Error: Kelvin temperature cannot be negative.\n");  //print that they did
            return 1;  //end program
        }
        if (output_scale == 1) converted_temp = kelvin_to_celsius(temperature);  //if output scale is C, convert temp to C
        else converted_temp = kelvin_to_fahrenheit(temperature);  //if output scale is F, convert temp to F
    }
    
    //Printing results
    printf("Converted temperature: %.2f %s\n", converted_temp, 
           (output_scale == 1) ? "C" : (output_scale == 2) ? "F" : "K");  //to print converted temp
    
    categorize_temperature((output_scale == 1) ? converted_temp :  //to print its category
                           (output_scale == 2) ? fahrenheit_to_celsius(converted_temp) :  //categprize_temp takes in C temps, so conversions to C are needed
                           kelvin_to_celsius(converted_temp));
    
    return 0;
}

// I ran the workflow and it passed without adding main. The exe works as intended.