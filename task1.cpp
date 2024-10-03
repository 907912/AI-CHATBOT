#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Function to analyze sentiment based on keywords
std::string analyzeSentiment(const std::string& input) {
    std::vector<std::string> positiveWords = {"happy", "good", "great", "love", "amazing", "excited"};
    std::vector<std::string> negativeWords = {"sad", "bad", "hate", "angry", "disappointed", "upset"};

    std::string lowerInput = input;
    std::transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);

    for (const auto& word : positiveWords) {
        if (lowerInput.find(word) != std::string::npos) {
            return "I'm glad you're feeling positive! What would you like to talk about?";
        }
    }

    for (const auto& word : negativeWords) {
        if (lowerInput.find(word) != std::string::npos) {
            return "I'm sorry to hear that. Can I help you with anything?";
        }
    }

    return "That's interesting! Tell me more.";
}

// Function to generate a simple response
std::string generateResponse(const std::string& input) {
    return analyzeSentiment(input);
}

int main() {
    std::string userInput;

    std::cout << "Hello! I'm a simple AI chatbot. How can I assist you today?" << std::endl;

    while (true) {
        std::cout << "You: ";
        std::getline(std::cin, userInput);

        if (userInput == "exit" || userInput == "quit") {
            std::cout << "Chatbot: Goodbye! Have a great day!" << std::endl;
            break;
        }

        std::string response = generateResponse(userInput);
        std::cout << "Chatbot: " << response << std::endl;
    }

    return 0;
}