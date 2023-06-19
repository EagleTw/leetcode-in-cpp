bool isPalindrome(char * s) {
    char *begin, *end;
    size_t len = strlen(s);

    if (len == 0) return true;

    begin = s;
    end = s + len - 1;

    while (begin <= end) {
        if (!isalnum(*begin)) { begin++; continue; }
        if (!isalnum(*end)) { end--; continue; }
        if (tolower(*begin++) != tolower(*end--)) return false;
    }

    return true;
}
