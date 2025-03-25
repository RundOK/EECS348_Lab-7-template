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

