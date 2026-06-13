//DECODE STRING
class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> strings;

        string current = "";
        int number = 0;

        for (char ch : s) {

            if (isdigit(ch)) {
                number = number * 10 + (ch - '0');
            }

            else if (ch == '[') {
                counts.push(number);
                strings.push(current);

                number = 0;
                current = "";
            }

            else if (ch == ']') {
                int repeat = counts.top();
                counts.pop();

                string previous = strings.top();
                strings.pop();

                while (repeat--) {
                    previous += current;
                }

                current = previous;
            }

            else {  // letter
                current += ch;
            }
        }

        return current;
    
    }
};