#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::vector<bool> BINARY(int num) {
    std::vector<bool> binary;

    while (num > 0) {
        binary.push_back(num % 2);
        num /= 2;
    }
    std::reverse(binary.begin(), binary.end());
    return binary;
}

std::string CONVERT_TO_STRING(std::vector<bool> binary) {
    std::string bin("");
    for (bool b : binary) {
        bin += std::to_string(b);
    }
    return bin;
}

int main() {
    setlocale(LC_ALL, "ru");

    printf("������� �����: ");
    int num = 0;
    std::cin >> num;
    std::vector<bool> bin = BINARY(num);
    std::reverse(bin.begin(), bin.end());

    for (int i = 0; i <= (int)sqrt(bin.size()); i++) {
        bin.insert(bin.begin() + pow(2, i) - 1, 0);
    }

    printf("�������� ������������������: %s\n", CONVERT_TO_STRING(bin).c_str());
    
    // ������������ �������������� �����
    int temp = 0;
    for (int i = 0; i < bin.size(); i++) {
        if (bin[i] == 1) {
            temp ^= i + 1;
        }
    }
    std::vector<bool> additional_bits = BINARY(temp);
    std::reverse(additional_bits.begin(), additional_bits.end());
    printf("�������������� ����: %s\n", CONVERT_TO_STRING(additional_bits).c_str());

    for (int i = 0, j = 0; i <= (int)sqrt(bin.size()); i++) {
        bin[pow(2, i) - 1] = additional_bits[j++];
    }

    printf("������������ ������������������: %s\n", CONVERT_TO_STRING(bin).c_str());

    bin[2] = !bin[2];

    printf("������������������ � �������: %s\n", CONVERT_TO_STRING(bin).c_str());

    temp = 0;
    for (int i = 0; i < bin.size(); i++) {
        if (bin[i] == 1) {
            temp ^= i + 1;
        }
    }

    printf("������� ���������� ����: %d\n", temp - 1);

    bin[temp - 1] = !bin[temp - 1];

    printf("������������ ������������������: %s\n", CONVERT_TO_STRING(bin).c_str());
	return 0;
}