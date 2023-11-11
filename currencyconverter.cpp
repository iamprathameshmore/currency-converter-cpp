#include <iostream>
#include <map>
#include <string>

// Function to convert currency
double convertCurrency(double amount, double rate) {
    return amount * rate;
}

int main() {
    std::map<std::string, double> exchangeRates = {
        {"USD", 1.0},   // Base rate (USD)
        {"EUR", 0.85},  // Sample rates for demonstration purposes
        {"GBP", 0.73},
        // Add more currencies and their respective rates
    };

    std::string fromCurrency, toCurrency;
    double amount;

    std::cout << "Enter the currency to convert from (e.g., USD, EUR, GBP): ";
    std::cin >> fromCurrency;

    std::cout << "Enter the currency to convert to (e.g., USD, EUR, GBP): ";
    std::cin >> toCurrency;

    std::cout << "Enter the amount: ";
    std::cin >> amount;

    if (exchangeRates.find(fromCurrency) != exchangeRates.end() && exchangeRates.find(toCurrency) != exchangeRates.end()) {
        double rateFrom = exchangeRates[fromCurrency];
        double rateTo = exchangeRates[toCurrency];

        // Convert to base currency first, then to the target currency
        double amountInUSD = amount / rateFrom;
        double convertedAmount = convertCurrency(amountInUSD, rateTo);

        std::cout << amount << " " << fromCurrency << " is equal to " << convertedAmount << " " << toCurrency << std::endl;
    } else {
        std::cout << "Currency not found or supported." << std::endl;
    }

    return 0;
}
