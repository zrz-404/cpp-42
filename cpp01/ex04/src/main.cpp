/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:02:13 by zrz               #+#    #+#             */
/*   Updated: 2025/05/28 11:24:18 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream> // For std::ifstream and std::ofstream
#include <string>


std::string replaceString(const std::string& input, const std::string& s1, const std::string& s2) {
    if (s1.empty()) { // Edge case if s1 is empty, return original to avoid infinite loop
        return input;
    }

    std::string result = "";
    std::string::size_type pos = 0;
    std::string::size_type found_pos;

    while ((found_pos = input.find(s1, pos)) != std::string::npos) {
        result.append(input, pos, found_pos - pos); // Append part before s1
        result.append(s2);                          // Append s2
        pos = found_pos + s1.length();              // Move past the found s1
    }
    result.append(input, pos, std::string::npos); // Append the rest of the string

    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: The string to be replaced (s1) cannot be empty." << std::endl;
        return 1;
    }

    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file '" << filename << "'" << std::endl;
        return 1;
    }

    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create output file '" << outputFilename << "'" << std::endl;
        inputFile.close();
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        outputFile << replaceString(line, s1, s2) << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "File processed successfully. Output written to '" << outputFilename << "'" << std::endl;
    return 0;
}