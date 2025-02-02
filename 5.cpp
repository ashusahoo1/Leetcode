// 5.longest palindromic substring
//below function is used to check right left of a index and chek if right left are equal if they are it is palindrome

int expandAroundCenter(char* s, int left, int right) {
    while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;  //length of the palindrome
}

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n == 0) return "";
    
    int start = 0, maxLength = 1;
    
    for (int i = 0; i < n; i++) {
        // Check for odd-length palindromes (centered at one character)
        int len1 = expandAroundCenter(s, i, i);
        // Check for even-length palindromes (centered between two characters)
        int len2 = expandAroundCenter(s, i, i + 1);
        
        // Get the longer palindrome
        int len = len1 > len2 ? len1 : len2;
        
        // Update the start and maxLength if a longer palindrome is found
        if (len > maxLength) {
            start = i - (len - 1) / 2;
            maxLength = len;
        }
    }
    
    // Create the longest palindrome substring
    char* result = (char*)malloc((maxLength + 1) * sizeof(char));
    strncpy(result, &s[start], maxLength);
    result[maxLength] = '\0';  // Null-terminate the string
    
    return result;
}
