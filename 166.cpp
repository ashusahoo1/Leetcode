// 166. Fraction to Recurring Decimal


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string result;
        if ((numerator < 0) ^ (denominator < 0)) {
            result += "-";
        }

        long long num = abs((long long)numerator);
        long long denom = abs((long long)denominator);
        long long remainder = num % denom;

        result += to_string(num / denom);

        if (remainder == 0) {
            return result;
        }

        result += ".";
        unordered_map<long long, int> map;
        
        while (remainder != 0) {
            if (map.find(remainder) != map.end()) {
                result.insert(map[remainder], "(");
                result += ")";
                break;
            }

            map[remainder] = result.size();

            remainder *= 10;
            result += to_string(remainder / denom);
            remainder %= denom;
        }

        return result;
    }
};
