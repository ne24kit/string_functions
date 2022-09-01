#include <stdio.h>
#include <string.h>

int StrLen(const char *str);

char * StrCpy(char *p_to, const char * p_from);

char * StrChr(const char * str, int c);

int StrCmp(const char * cs, const char * ct);

char * StrCat(char * s, const char * ct);



int main()
{

    char s1[] = "ABCD";
    const char *p1  = "ABC";

    printf("%p\n", "ABCD");
    printf("%p\n", "ABC");

    printf("%p\n", &s1);
    printf("%p\n", &p1);

    printf("%p\n", s1);
    printf("%p\n", p1);
    printf("Testing functions\n");

    printf("%d\n", StrLen(s1));
    printf("%d\n", strlen(s1));

    printf("%d\n", StrLen(p1));
    printf("%d\n", strlen(p1));

    const char * p_from = "MNK";
    char p_to[] = "ABC";

    printf("%s\n", StrCpy(p_to, p_from));
    printf("%s\n", strcpy(p_to, p_from));

    char s2[] = "ABCBCDEF";

    printf("%s\n", StrChr(p1, 'B'));
    printf("%s\n", strchr(p1, 'B'));

    printf("%s\n", StrChr(s2, 'X'));
    printf("%s\n", strchr(s2, 'X'));

    printf("%d\n", StrCmp(s1, s2));
    printf("%d\n", strcmp(s1, s2));

    printf("%d\n", StrCmp("CVB", "CVB"));
    printf("%d\n", strcmp("CVB", "CVB"));

    printf("%s\n", StrCat(s1, s2));
    printf("%s\n", strcat(s1, s2));

    return 0;
}

int StrLen(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;

    return i;
}

char * StrCpy(char *p_to, const char * p_from)
{
    int i = 0;

    while (p_from[i] != '\0')
    {
        p_to[i] = p_from[i];
        i++;
    }

    p_to[i] = '\0';

    return p_to;
}

char * StrChr(const char * str, int c)
{
    int i = 0;

    for(; str[i] != '\0' && str[i] != c; i++)
        continue;

    return str[i] == c ? const_cast<char*> (&str[i]) : NULL; // TOASK: Why NULL doesn`t prtints "(null)"?
    // UNDERSTOOD(TODO:             ^~~~~~~~~~~~~~~~~ special C++ construction for removing const from a type
    // (unsafe, but only way to get C-style function working without warning here))
    // ME: I also can use (char *) but with warning :(
}

int StrCmp(const char * cs, const char * ct)
{
    int len_cs = StrLen(cs);
    int len_ct = StrLen(ct);

    if (len_cs == len_ct)
    {
        int i = 0;
        while (cs[i] == ct[i] && cs[i] != '\0') i++;
        if(cs[i] == ct[i])
            return 0;
        return cs[i] - ct[i] > 0 ? 1 : -1;
    }
    else
        return len_ct - len_cs > 0 ? 1 : -1;

    // DONE(TODO: equal length doesn't mean equal strings)
}

char * StrCat(char * s, const char * ct)
{
    int i = StrLen(s);
    StrCpy(&s[i], ct);
                        // DONE(TODO: this is strcpy! Should extract!)
    return s;
}
