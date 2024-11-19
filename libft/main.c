#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <bsd/string.h>
#include <ctype.h>
#include <strings.h>
#include <memory.h>
#include "libft.h"

char ft_change_case(unsigned int i, char c)
{
    if (i % 2 == 0)
        return ft_toupper(c);
    else
        return ft_tolower(c);
}

char ft_mapi_func(unsigned int i, char c)
{
    (void) i;
    return c + 1;
}

void ft_print_char_index(unsigned int i, char *c)
{
    printf("%d, %c\n", i, *c);
}

void    read_file(const char * filename)
{
    int fd;

    fd = open(filename, O_RDWR, S_IRWXU | S_IRWXG);
    if (fd == -1)
    {
        perror("Error");
        return ;
    }
    char buf[100];
    ssize_t bytes_read;
    while ((bytes_read = read(fd, buf, sizeof(buf))))
        write(STDOUT_FILENO, buf, bytes_read);
    if (bytes_read == -1)
    {
        perror("Error");
        close(fd);
        return ;
    }
    if (close(fd) == -1)
    {
        perror("Error");
        return ;
    }
}

int main () 
{
    printf("\n\tMAIN_CTYPE TESTING PROGRAM\n\t**************************\n");

   char c1 = 'H';
   char c2 = 'e';
   char c3 = '\t';
   char c4 = '1';
   char c5 = '0';
   char c6 = '~';
   char c7 = '4';

    printf("-------------------------------------------\n");
    printf("TEST FT_ISALPHA\n");
   printf("Test of ft_isalpha // isalpha: \n");
   printf("1st: %c, ft_isalpha: %d\n", c1, ft_isalpha(c1));
   printf("2nd: %c, ft_isalpha: %d\n", c2, ft_isalpha(c2));
   printf("3nd: %c, ft_isalpha: %d\n", c3, ft_isalpha(c3));
   printf("4th: %c, ft_isalpha: %d\n", c4, ft_isalpha(c4));
   printf("5th: %c, ft_isalpha: %d\n", c5, ft_isalpha(c5));
   printf("6th: %c, ft_isalpha: %d\n", c6, ft_isalpha(c6));
   printf("1st: %c, isalpha: %d\n", c1, isalpha(c1));
   printf("2nd: %c, isalpha: %d\n", c2, isalpha(c2));
   printf("3rd: %c, isalpha: %d\n", c3, isalpha(c3));
   printf("4th: %c, isalpha: %d\n", c4, isalpha(c4));
   printf("5th: %c, isalpha: %d\n", c5, isalpha(c5));
   printf("6th: %c, isalpha: %d\n", c6, isalpha(c6));

    printf("-------------------------------------------\n");
    printf("TEST FT_ISDIGIT\n");
   printf("1st: %c, ft_isdigit: %d\n", c1, ft_isdigit(c1));
   printf("2nd: %c, ft_isdigit: %d\n", c2, ft_isdigit(c2));
   printf("3nd: %c, ft_isdigit: %d\n", c3, ft_isdigit(c3));
   printf("4th: %c, ft_isdigit: %d\n", c4, ft_isdigit(c4));
   printf("5th: %c, ft_isdigit: %d\n", c5, ft_isdigit(c5));
   printf("6th: %c, ft_isdigit: %d\n", c6, ft_isdigit(c6));
   printf("7th: %c, ft_isdigit: %d\n", c7, ft_isdigit(c7));
   printf("1st: %c, isdigit: %d\n", c1, isdigit(c1));
   printf("2nd: %c, isdigit: %d\n", c2, isdigit(c2));
   printf("3rd: %c, isdigit: %d\n", c3, isdigit(c3));
   printf("4th: %c, isdigit: %d\n", c4, isdigit(c4));
   printf("5th: %c, isdigit: %d\n", c5, isdigit(c5));
   printf("6th: %c, isdigit: %d\n", c6, isdigit(c6));
   printf("7th: %c, isdigit: %d\n\n", c7, isdigit(c7));

    printf("-------------------------------------------\n");
    printf("TEST FT_ISALNUM\n");
   printf("1st: %c, ft_isalnum: %d\n", c1, ft_isalnum(c1));
   printf("2nd: %c, ft_isalnum: %d\n", c2, ft_isalnum(c2));
   printf("3nd: %c, ft_isalnum: %d\n", c3, ft_isalnum(c3));
   printf("4th: %c, ft_isalnum: %d\n", c4, ft_isalnum(c4));
   printf("5th: %c, ft_isalnum: %d\n", c5, ft_isalnum(c5));
   printf("6th: %c, ft_isalnum: %d\n", c6, ft_isalnum(c6));
   printf("7th: %c, ft_isalnum: %d\n", c7, ft_isalnum(c7));
   printf("1st: %c, isalnum: %d\n", c1, isalnum(c1));
   printf("2nd: %c, isalnum: %d\n", c2, isalnum(c2));
   printf("3rd: %c, isalnum: %d\n", c3, isalnum(c3));
   printf("4th: %c, isalnum: %d\n", c4, isalnum(c4));
   printf("5th: %c, isalnum: %d\n", c5, isalnum(c5));
   printf("6th: %c, isalnum: %d\n", c6, isalnum(c6));
   printf("7th: %c, isalnum: %d\n\n", c7, isalnum(c7));

    printf("-------------------------------------------\n");
    printf("TEST FT_ISASCII\n");
   printf("1st: %c, ft_isascii: %d\n", c1, ft_isascii(c1));
   printf("2nd: %c, ft_isascii: %d\n", c2, ft_isascii(c2));
   printf("3nd: %c, ft_isascii: %d\n", c3, ft_isascii(c3));
   printf("4th: %c, ft_isascii: %d\n", c4, ft_isascii(c4));
   printf("5th: %c, ft_isascii: %d\n", c5, ft_isascii(c5));
   printf("6th: %c, ft_isascii: %d\n", c6, ft_isascii(c6));
   printf("7th: %c, ft_isascii: %d\n", c7, ft_isascii(c7));
   printf("1st: %c, isascii: %d\n", c1, isascii(c1));
   printf("2nd: %c, isascii: %d\n", c2, isascii(c2));
   printf("3rd: %c, isascii: %d\n", c3, isascii(c3));
   printf("4th: %c, isascii: %d\n", c4, isascii(c4));
   printf("5th: %c, isascii: %d\n", c5, isascii(c5));
   printf("6th: %c, isascii: %d\n", c6, isascii(c6));
   printf("7th: %c, isascii: %d\n\n", c7, isascii(c7));

    printf("-------------------------------------------\n");
    printf("TEST FT_ISPRINTn");
   printf("1st: %c, ft_isprint: %d\n", c1, ft_isprint(c1));
   printf("2nd: %c, ft_isprint: %d\n", c2, ft_isprint(c2));
   printf("3nd: %c, ft_isprint: %d\n", c3, ft_isprint(c3));
   printf("4th: %c, ft_isprint: %d\n", c4, ft_isprint(c4));
   printf("5th: %c, ft_isprint: %d\n", c5, ft_isprint(c5));
   printf("6th: %c, ft_isprint: %d\n", c6, ft_isprint(c6));
   printf("7th: %c, ft_isprint: %d\n", c7, ft_isprint(c7));
   printf("1st: %c, isprint: %d\n", c1, isprint(c1));
   printf("2nd: %c, isprint: %d\n", c2, isprint(c2));
   printf("3rd: %c, isprint: %d\n", c3, isprint(c3));
   printf("4th: %c, isprint: %d\n", c4, isprint(c4));
   printf("5th: %c, isprint: %d\n", c5, isprint(c5));
   printf("6th: %c, isprint: %d\n", c6, isprint(c6));
   printf("7th: %c, isprint: %d\n\n", c7, isprint(c7));

   printf("-------------------------------------------\n");
   printf("TEST FT_TOUPPER\n");
   printf("1st: %c, ft_toupper: %c\n", c1, (char)ft_toupper(c1));
   printf("2nd: %c, ft_toupper: %c\n", c2, (char)ft_toupper(c2));
   printf("3nd: %c, ft_toupper: %d\n", c3, ft_toupper(c3));
   printf("4th: %c, ft_toupper: %d\n", c4, ft_toupper(c4));
   printf("5th: %c, ft_toupper: %d\n", c5, ft_toupper(c5));
   printf("6th: %c, ft_toupper: %d\n", c6, ft_toupper(c6));
   printf("7th: %c, ft_toupper: %d\n", c7, ft_toupper(c7));
   printf("1st: %c, toupper: %c\n", c1, (char)toupper(c1));
   printf("2nd: %c, toupper: %c\n", c2, (char)toupper(c2));
   printf("3rd: %c, toupper: %d\n", c3, toupper(c3));
   printf("4th: %c, toupper: %d\n", c4, toupper(c4));
   printf("5th: %c, toupper: %d\n", c5, toupper(c5));
   printf("6th: %c, toupper: %d\n", c6, toupper(c6));
   printf("7th: %c, toupper: %d\n\n", c7, toupper(c7));

    printf("-------------------------------------------\n");
    printf("TEST FT_TOLOWER\n");
   printf("1st: %c, ft_tolower: %c\n", c1, (char)ft_tolower(c1));
   printf("2nd: %c, ft_tolower: %c\n", c2, (char)ft_tolower(c2));
   printf("3nd: %c, ft_tolower: %d\n", c3, ft_tolower(c3));
   printf("4th: %c, ft_tolower: %d\n", c4, ft_tolower(c4));
   printf("5th: %c, ft_tolower: %d\n", c5, ft_tolower(c5));
   printf("6th: %c, ft_tolower: %d\n", c6, ft_tolower(c6));
   printf("7th: %c, ft_tolower: %d\n", c7, ft_tolower(c7));
   printf("1st: %c, tolower: %c\n", c1, (char)tolower(c1));
   printf("2nd: %c, tolower: %c\n", c2, (char)tolower(c2));
   printf("3rd: %c, tolower: %d\n", c3, tolower(c3));
   printf("4th: %c, tolower: %d\n", c4, tolower(c4));
   printf("5th: %c, tolower: %d\n", c5, tolower(c5));
   printf("6th: %c, tolower: %d\n", c6, tolower(c6));
   printf("7th: %c, tolower: %c\n\n", c7, tolower(c7));
   
printf("\tMAIN_MEMORY TESTING PROGRAM\n\t***************************\n");

    int array[5];
    int array2[5];
    char str[10];
    char str2[10];

    printf("TEST FOR MEMSET\n");
    memset(array, 1, sizeof(array));
    printf("Array with memset: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", array[i]);
    printf("\n");
    ft_memset(array2, 1, sizeof(array2));
    printf("Array with ft_memset: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", array2[i]);
    printf("\n");
    memset(str, 'A', sizeof(str));
    printf("String with memset: ");
    for (int i = 0; i < 5; i++)
        printf("%c", str[i]);
    printf("\n");
    ft_memset(str2, 'A', sizeof(str2));
    printf("String with ft_memset: ");
    for (int i = 0; i < 5; i++)
        printf("%c", str2[i]);
    printf("\n\n");

    printf("-----------------------------------\n");
    printf("TEST FOR BZERO\n");
    bzero(str, sizeof(str));
    printf("With bzero: %s, size: %ld\n", str, sizeof(str));
    ft_bzero(str2, sizeof(str2));
    printf("With ft_bzero: %s, size: %ld\n\n", str2, sizeof(str2));

    printf("-----------------------------------\n");
    printf("TEST FOR MEMCPY\n");
    int src_mem[5] = {1,2,3,4,5};
    int dest_mem[5] = {};
    char src2_mem[12] = "Hello World";
    char dest2_mem[6] = "";
    int src3_mem[5] = {1,2,3,4,5};
    int dest3_mem[5] = {};
   char src4_mem[12] = "Hello World";
   char dest4_mem[6] = "";
    
    printf("Array with memcpy: ");
    memcpy(dest_mem, src_mem, sizeof(src_mem));
    int length1 = sizeof(dest_mem)/sizeof(dest_mem[0]); 
    for (int i = 0; i < length1; i++)
        printf("%d ", dest_mem[i]);
    printf("\n");
    printf("Array with ft_memcpy: ");
    ft_memcpy(dest3_mem, src3_mem, sizeof(src3_mem));
    int length2 = sizeof(dest3_mem)/sizeof(dest3_mem[0]); 
    for (int i = 0; i < length2; i++)
        printf("%d ", dest3_mem[i]);
    printf("\n");
    printf("String with memcpy: ");
    memcpy(dest2_mem, src2_mem, (size_t)strlen(src2_mem));
	printf("%s\n", dest2_mem);    
    printf("String with ft_memcpy: ");
 ft_memcpy(dest4_mem, src4_mem, ft_strlen(src4_mem));
   printf("%s\n\n", dest4_mem);

    printf("-----------------------------------\n");
    printf("TEST FOR MEMMOVE\n");
    int ar_mem[5] = {1,2,3,4,5};
    int ar2_mem[5] = {1,2,3,4,5};
    char s_mem[12] = "Hello World";
    char s2_mem[12] = "Hello World";

    printf("Array with memmove: ");
    length1 = sizeof(ar_mem)/sizeof(ar_mem[0]);    
    memmove(ar_mem, ar_mem + 3, (length1 - 3) * sizeof(int));
    for (int i = 0; i < length1; i++)
        printf("%d ", ar_mem[i]);
    printf("\n");
    printf("Array with ft_memmove: ");
    length2 = sizeof(ar2_mem)/sizeof(ar2_mem[0]); 
    ft_memmove(ar2_mem, ar2_mem + 3, (length2 - 3) * sizeof(int));
    for (int i = 0; i < length2; i++)
        printf("%d ", ar2_mem[i]);
    printf("\n");
    printf("String with memmove: ");
    int len = strlen(s_mem);
    memmove(s_mem, s_mem + 6, (len - 6));
    printf("%s\n", s_mem);    
    printf("String with ft_memmove: ");
    int len2_mem = ft_strlen(s2_mem);
   ft_memmove(s2_mem, s2_mem + 6, (len2_mem - 6));
    printf("%s\n\n", s2_mem);

    printf("-----------------------------------\n");
    printf("TEST FOR MEMCMP\n");
    int ar_cmp[5] = {1,2,3,4,5};
    int ar_cmp2[5] = {1,2,3,6,7};
    char s_cmp[12] = "Hello World";
    char s_cmp2[12] = "HeLLo World";

    int result1_cmp = memcmp(ar_cmp, ar_cmp2, 4 *sizeof(int));
    printf ("Array with memcmp: %d\n", result1_cmp);
    result1_cmp = ft_memcmp(ar_cmp, ar_cmp2, 4 *sizeof(int));
    printf ("Array with ft_memcmp: %d\n", result1_cmp);
    result1_cmp = memcmp(s_cmp, s_cmp2, 11);
    printf ("string with memcmp: %d\n", result1_cmp);
    result1_cmp = ft_memcmp(s_cmp, s_cmp2, 11);
    printf ("string with ft_memcmp: %d\n\n", result1_cmp);

    printf("-----------------------------------\n");
    printf("TEST FOR MEMCHR\n");
    int ar_chr[5] = {1,2,3,4,5};
    char s_mchr[12] = "Hello World";

    printf("Array with memchr: ");
    length1 = sizeof(ar_chr); 
    int *ptr_mchr = (int *)memchr(ar_chr, 3, length1);
    printf("%d\n", *ptr_mchr);
    printf("Array with ft_memchr: ");
    int *ptr2_mchr = (int *)ft_memchr(ar_chr, 3, length1);
    printf("%d\n", *ptr2_mchr);
    printf("String with memchr: ");
    len = strlen(s_mchr);
    char *result_mchr = (char *)memchr(s_mchr, 'o', len);
    printf("%s\n", result_mchr);  
   printf("String with ft_memchr: ");
   len = ft_strlen(s_mchr);
   result_mchr = (char *)ft_memchr(s_mchr, 'o', len);
   printf("%s\n", result_mchr);
    
printf("\n\tMAIN_STDLIB TESTING PROGRAM\n\t***************************\n");

    printf("TEST OF CALLOC\n");
    int arr[5] = {1,2,3,4,5};
    size_t siz = sizeof(arr);
    size_t len2 = siz/sizeof(arr[0]);
    int *ptr2_cal = (int *)calloc(len2, siz);
    printf("Array with calloc: \n");
    for (size_t i = 0; i< len2; i++)
        printf("%d", ptr2_cal[i]);
    printf("\n");
    int *ptr3_cal = (int *)ft_calloc(len2, siz);
    printf("Array with ft_calloc: \n");
    for (size_t i = 0; i< len2; i++)
        printf("%d", ptr3_cal[i]);
    printf("\n");

    char s_cal[12] = "Hello World";
    siz = sizeof(s_cal);
    len = strlen(s_cal);
    printf("String with calloc: \n");
    char *ptr4_cal = (char *)calloc(5, siz);
    printf("'%s'\n", ptr4_cal);
    printf("%ld\n", sizeof(ptr4_cal));
    printf("String with ft_calloc: \n");
    char *ptr5_cal = (char *)ft_calloc(5, siz);
    printf("'%s'\n", ptr5_cal);
    printf("%ld\n", sizeof(ptr5_cal));
    free(ptr2_cal);
    free(ptr3_cal);
    free(ptr4_cal);
    free(ptr5_cal);

    printf("-----------------------------------\n");
    printf("TEST OF STRDUP\n");
    char s_dup[12] = "Hello World";
    char s_dup2[3] = "lo";
    char s_dup3[450] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    printf("With strdup: \n%s\n", strdup(s_dup));
    printf("%s\n", strdup(s_dup2));    
    printf("%s\n", strdup(s_dup3));    
   printf("With ft_strdup: \n%s\n", ft_strdup(s_dup));
    printf("%s\n", ft_strdup(s_dup2)); 
    printf("%s\n", ft_strdup(s_dup3));

printf("\n\tMAIN_STDLIB_PERSONALISED TESTING PROGRAM\n\t****************************************\n");

   printf("TEST FT_SUBSTR\n");
    char sub[] = "Hello World";
    char *result_sub;
    char *result1_sub;
    char *result2_sub;
    char *result3_sub;

    result_sub = ft_substr(sub, 6, ft_strlen(sub));
    result1_sub = ft_substr(sub, 2, ft_strlen(sub));
    result2_sub = ft_substr(sub, 10, ft_strlen(sub));
    result3_sub = ft_substr(sub, 11, ft_strlen(sub));
    printf("%s\n", result_sub);
    printf("%s\n", result1_sub);
    printf("%s\n", result2_sub);
    printf("%s\n\n", result3_sub);

    free(result_sub);
    free(result1_sub);
    free(result2_sub);
    free(result3_sub);

    printf("-------------------------------------------\n");
    printf("TEST FT_STRJOIN\n");
    char s_join[] = "Hello ";
    char s2_join[] = "World";
    char s3_join[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    char s4_join[] = " Ut enim ad minim Veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";
    char s5_join[] = "***123----";
    char s6_join[] = "++456&^@@$#";
    char *result4_join;
    char *result5_join;
    char *result6_join;

    result4_join = ft_strjoin(s_join, s2_join);
    result5_join = ft_strjoin(s3_join, s4_join);
    result6_join = ft_strjoin(s5_join, s6_join);
    printf("%s\n", result4_join);
    printf("%s\n", result5_join);
    printf("%s\n\n", result6_join);

    free(result4_join);
    free(result5_join);
    free(result6_join);

    printf("-------------------------------------------\n");
    printf("TEST FT_STRTRIM\n");
    char s7_trim[] = "  Hello World  ";
    char set_trim[] = " ";
    char *result7_trim;

    result7_trim = ft_strtrim(s7_trim, set_trim);
    printf("'%s'\n", result7_trim);
    printf("%lu\n\n", ft_strlen(result7_trim));

    free(result7_trim);

    printf("-------------------------------------------\n");
    printf("TEST FT_SPLIT\n");
    char s8_split[] = "Hello World Hola Amigos  123 ^ 45   WERTS!&^^";
    char c_split = ' ';
    char **result8_split;

    result8_split = ft_split(s8_split, c_split);
    for (int i = 0; i < 8; i++)
        printf("'%s'\n\n", result8_split[i]);
    
    for (int i = 0; result8_split[i]; i++)
        free(result8_split[i]);
    free(result8_split); 

    printf("-------------------------------------------\n");
    printf("TEST FT_ITOA\n");
    int nb_itoa = 456;
    int nb2_itoa = 2547893;
    int nb3_itoa = -559988;
    int nb4_itoa = -2147483648;
    int nb5_itoa = 2147483647;
    int nb6_itoa = 0;

    printf("nb: %d, ft_itoa: %s\n", nb_itoa, ft_itoa(nb_itoa));
    printf("nb: %d, ft_itoa: %s\n", nb2_itoa, ft_itoa(nb2_itoa));
    printf("nb: %d, ft_itoa: %s\n", nb3_itoa, ft_itoa(nb3_itoa));
    printf("nb: %d, ft_itoa: %s\n", nb4_itoa, ft_itoa(nb4_itoa));
    printf("nb: %d, ft_itoa: %s\n", nb5_itoa, ft_itoa(nb5_itoa));
    printf("nb: %d, ft_itoa: %s\n", nb6_itoa, ft_itoa(nb6_itoa));

    printf("-------------------------------------------\n");
  	 printf("TEST FT_STRMAPI\n");
    char s_mapi[] = "he11o w@rLd";
    char s_mapi2[] = "abc123-+";
    char *output1_mapi = ft_strmapi(s_mapi, ft_change_case);
    char *output2_mapi = ft_strmapi(s_mapi2, ft_mapi_func);

    printf("str1: %s become %s\n", s_mapi, output1_mapi);
    printf("str2: %s become %s\n", s_mapi2, output2_mapi);

    free(output1_mapi);
    free(output2_mapi);

    printf("-------------------------------------------\n");
    printf("TEST FT_STRITERI\n");

    char s_iteri[] = "Hello";

    ft_striteri(s_iteri,&ft_print_char_index);

	printf("\n\tMAIN_STRING TESTING PROGRAM\n\t***************************\n");

    printf("TEST OF FT_STRLCPY\n");    
    char dt[] = "Hello ";
    char sr[6] = "World";
    char dt2[6] = " +-&1";
    char sr2[9] = "###\t456";
    char dt3[] = "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    char sr3[232] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";
    char dt4[] = "Hello ";
    char sr4[6] = "World";
    char dt5[6] = " +-&1";
    char sr5[9] = "###\t456";
    char dt6[] = "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    char sr6[232] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";
       
    printf("\twith strlcpy\n");
    printf("strlcpy result: %lu\n", strlcpy(dt, sr, 5));
    printf("new string: %s\n", dt);
    printf("strlcpy result: %lu\n", strlcpy(dt2, sr2, 10));
    printf("new string: %s\n", dt2);
    printf("strlcpy result: %lu\n", strlcpy(dt3, sr3, 124));
    printf("new string: %s\n\n", dt3);
    printf("\twith ft_strlcpy\n");
    printf("ft_strlcpy result: %lu\n", ft_strlcpy(dt4, sr4, 5));
    printf("new string: %s\n", dt4);
    printf("ft_strlcpy result: %lu\n", ft_strlcpy(dt5, sr5, 10));
    printf("new string: %s\n", dt5);
    printf("ft_strlcpy result: %lu\n", ft_strlcpy(dt6, sr6, 124));
    printf("new string: %s\n\n", dt6);

    printf("----------------------------------------------\n");
    printf("TEST OF FT_STRLCAT\n");    
    char dest[6] = "Hola ";
    char src[] = "World";
    char dest2[6] = "Hola ";
    char src2[] = "World";
    char dest3[6] = "Hola ";
    char src3[] = "World";
    char dest4[6] = "Hola ";
    char src4[] = "World";
    char dest5[6] = "Hola ";
    char src5[] = "World";
    char dest6[6] = "Hola ";
    char src6[] = "World";

    printf("\twith strlcat\n");
    printf("strlcat result: %lu\n", strlcat(dest, src, 11));
    printf("new string: %s\n", dest);
    printf("strlcat result: %lu\n", strlcat(dest2, src2, 8));
    printf("new string: %s\n", dest2);
    printf("strlcat result: %lu\n", strlcat(dest3, src3, 6));
    printf("new string: %s\n\n", dest3);
    printf("\twith ft_strlcat\n");
    printf("ft_strlcat result: %lu\n", ft_strlcat(dest4, src4, 11));
    printf("new string: %s\n", dest4);
    printf("ft_strlcat result: %lu\n", ft_strlcat(dest5, src5, 8));
    printf("new string: %s\n", dest5);
    printf("ft_strlcat result: %lu\n", ft_strlcat(dest6, src6, 6));
    printf("new string: %s\n\n", dest6);

    printf("----------------------------------------------\n");
    printf("TEST OF FT_STRCHR\n");
    char s_chr[] = "Hello World";
    char s_chr2[] = "1233456";
    char s_chr3[] = "  ++*&^@@$#";
    char s_chr4[] = "1";
    char s_chr5[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";

    printf("\tWith strchr:\n");
    printf("%s\n", strchr(s_chr, 'o'));
    printf("%s\n", strchr(s_chr2, '3'));
    printf("%s\n", strchr(s_chr3, '@'));
    printf("%s\n", strchr(s_chr4, '1'));
    printf("%s\n\n", strchr(s_chr5, ','));
    printf("\tWith ft_strchr:\n");
    printf("%s\n", ft_strchr(s_chr, 'o'));
    printf("%s\n", ft_strchr(s_chr2, '3'));
    printf("%s\n", ft_strchr(s_chr3, '@'));
    printf("%s\n", ft_strchr(s_chr4, '1'));
    printf("%s\n\n", ft_strchr(s_chr5, ','));

    printf("----------------------------------------------\n");
    printf("TEST OF FT_STRRCHR\n");
    char s_rchr[] = "Hello World";
    char s_rchr2[] = "1233456";
    char s_rchr3[] = "  ++*&^@@$#";
    char s_rchr4[] = "1";
    char s_rchr5[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";

    printf("\tWith strrchr:\n");
    printf("%s\n", strrchr(s_rchr, 'o'));
    printf("%s\n", strrchr(s_rchr2, '3'));
    printf("%s\n", strrchr(s_rchr3, '@'));
    printf("%s\n", strrchr(s_rchr4, '1'));
    printf("%s\n\n", strrchr(s_rchr5, ','));
    printf("\tWith ft_strrchr:\n");
    printf("%s\n", ft_strrchr(s_rchr, 'o'));
    printf("%s\n", ft_strrchr(s_rchr2, '3'));
    printf("%s\n", ft_strrchr(s_rchr3, '@'));
    printf("%s\n", ft_strrchr(s_rchr4, '1'));
    printf("%s\n\n", ft_strrchr(s_rchr5, ','));

    printf("----------------------------------------------\n");
    printf("TEST OF FT_STRNCMP\n");    
    char s_ncmp[] = "Hello World  ++456&^@@$#";
    char s_ncmp2[] = "Hello World  ++456&^@$#";
    char s_ncmp3[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim Veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";
    char s_ncmp4[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";


    printf("\tWith strncmp:\n");
    printf("%d\n", strncmp(s_ncmp, s_ncmp2, strlen(s_ncmp)));
    printf("%d\n", strncmp(s_ncmp2, s_ncmp, strlen(s_ncmp2)));
    printf("%d\n", strncmp(s_ncmp, s_ncmp2, 20));
    printf("%d\n", strncmp(s_ncmp3, s_ncmp4, strlen(s_ncmp3)));
    printf("%d\n", strncmp(s_ncmp4, s_ncmp3, strlen(s_ncmp4)));
    printf("%d\n\n", strncmp(s_ncmp3, s_ncmp4, 141));            
    printf("\tWith ft_strncmp:\n");
    printf("%d\n", ft_strncmp(s_ncmp, s_ncmp2, ft_strlen(s_ncmp)));
    printf("%d\n", ft_strncmp(s_ncmp2, s_ncmp, ft_strlen(s_ncmp2)));
    printf("%d\n", ft_strncmp(s_ncmp, s_ncmp2, 20));
    printf("%d\n", ft_strncmp(s_ncmp3, s_ncmp4, ft_strlen(s_ncmp3)));
    printf("%d\n", ft_strncmp(s_ncmp4, s_ncmp3, ft_strlen(s_ncmp4)));
    printf("%d\n\n", ft_strncmp(s_ncmp3, s_ncmp4, 141));

    printf("----------------------------------------------\n");
    printf("TEST OF FT_STRNSTR\n");       
    char s_nstr[] = "Hello World  ++45++457&++456&^@@$#";
    char s_nstr2[] = "World";
    char s_nstr3[] = "+456&";
    char s_nstr4[] = "";
    char s_nstr5[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim Veniam.";
    char s_nstr6[] = "enim";
    char s_nstr7[] = "ut e";
    char s_nstr8[] = "Ut e"; 


    printf("\tWith strnstr:\n");
    printf("%s\n", strnstr(s_nstr, s_nstr2, 34));
    printf("%s\n", strnstr(s_nstr, s_nstr3, 34));
    printf("%s\n", strnstr(s_nstr, s_nstr4, 34));
    printf("%s\n", strnstr(s_nstr5, s_nstr6, 148));
    char * result1 = strnstr(s_nstr5, s_nstr7, 200);
    printf("Result: %s\n", (result1 != NULL) ? result1 : "Needle not found");
    char * result2 = strnstr(s_nstr5, s_nstr8, 123);
    printf("Result: %s\n", (result2 != NULL) ? result2 : "Needle not found");
    printf("%s\n\n", strnstr(s_nstr5, s_nstr8, 200));             
    printf("\tWith ft_strnstr:\n");
    printf("%s\n", ft_strnstr(s_nstr, s_nstr2, 34));
    printf("%s\n", ft_strnstr(s_nstr, s_nstr3, 34));
    printf("%s\n", ft_strnstr(s_nstr, s_nstr4, 34));
    printf("%s\n", ft_strnstr(s_nstr5, s_nstr6, 148));
    char * result3 = ft_strnstr(s_nstr5, s_nstr7, 200);
    printf("Result: %s\n", (result3 != NULL) ? result3 : "Needle not found");
    char * result4 = ft_strnstr(s_nstr5, s_nstr8, 123);
    printf("Result: %s\n", (result4 != NULL) ? result4 : "Needle not found");
    printf("%s\n\n", ft_strnstr(s_nstr5, s_nstr8, 200));  

    printf("----------------------------------------------\n");
    printf("TEST OF FT_ATOI\n");
    char input1[] = "00012345";
	char input4[] = "123abc456";
	char input5[] = "-0";
	char input6[] = "2147483647";
	char input7[] = "-2147483648";
	char input8[] = "   2147483648";
	char input9[] = "-2147483649";
	char input10[] = "";
	char input11[] = "abc123";
	char input12[] = "-*&^$-123";
	char input13[] = "  ---+--+1234ab567";
	char input14[] = "1 2 3 4 5 6 7 8 9 0 a b c d e f g h i j k l m n o p q r s t u v w x y z";

    printf("\tWith atoi\n");
	printf("%d\n", atoi(input1));
	printf("%d\n", atoi(input4));	
	printf("%d\n", atoi(input5));	
	printf("%d\n", atoi(input6));	
	printf("%d\n", atoi(input7));	
	printf("%d\n", atoi(input8));	
	printf("%d\n", atoi(input9));	
	printf("%d\n", atoi(input10));	
	printf("%d\n", atoi(input11));	
	printf("%d\n", atoi(input12));	
	printf("%d\n", atoi(input13));	
	printf("%d\n\n", atoi(input14));	
    printf("\tWith ft_atoi\n");
    printf("%d\n", ft_atoi(input1));
	printf("%d\n", ft_atoi(input4));	
	printf("%d\n", ft_atoi(input5));	
	printf("%d\n", ft_atoi(input6));	
	printf("%d\n", ft_atoi(input7));	
	printf("%d\n", ft_atoi(input8));	
	printf("%d\n", ft_atoi(input9));	
	printf("%d\n", ft_atoi(input10));	
	printf("%d\n", ft_atoi(input11));	
	printf("%d\n", ft_atoi(input12));	
	printf("%d\n", ft_atoi(input13));	
	printf("%d\n", ft_atoi(input14));

printf("\n\tMAIN_WRITE TESTING PROGRAM\n\t**************************\n");
    
    int fd;
    const char *filename;

    fd = open("temp_file.txt", O_CREAT | O_WRONLY | O_TRUNC);
    filename = "temp_file.txt";
    printf("---------------------------------------\n");
    printf("TEST OF FT_PUTCHAR_FD\n\n");
    char s_fd[] = "Hello World, how are you?";
    int i;

    i = 0;
    while (s_fd[i] != '\0')
    {
        ft_putchar_fd(s_fd[i], fd);
        i++;
    }
    read_file(filename); 

    printf("\n---------------------------------------\n");
    printf("TEST OF FT_PUTSTR_FD\n\n");
    char s2_fd[] = "\nI'm fine and you?";
    fd = open("temp_file.txt", O_RDWR | O_APPEND);

    ft_putstr_fd(s2_fd, fd);
    read_file(filename);

    printf("\n---------------------------------------\n");
    printf("TEST OF FT_PUTENDL_FD\n\n");
    char s3_fd[] = "\nAll good, thanks!";
    fd = open("temp_file.txt", O_RDWR | O_APPEND);

    ft_putendl_fd(s3_fd, fd);
    read_file(filename);

    printf("\n---------------------------------------\n");
    printf("TEST OF FT_PUTNBR_FD\n\n");
    int s4_fd = 256;
    fd = open("temp_file.txt", O_RDWR | O_APPEND);

    ft_putnbr_fd(s4_fd, fd);
    read_file(filename);

    printf("\n---------------------------------------\n");
    printf("\n---------------------------------------\n");
	int count;

	ft_printf("TEST FOR %%\n***********\n\n");
	count = ft_printf("%%\n");
	printf("count with my printf: %d\n", count);
	count = printf("%%\n");
	printf("count with printf: %d\n\n", count);

	ft_printf("TEST FOR CHAR\n***********\n\n");
	char one = 'a';
	char two = '6';
	char three = '*';
	char four = '\n';

	ft_printf("With ft_printf: \n");
	count = ft_printf("%c\n", one);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%c\n", two);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%c\n", three);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%c\n", four);
	printf("count with my printf: %d\n\n", count);

	ft_printf("With printf: \n");
	count = printf("%c\n", one);
	printf("count with my printf: %d\n", count);
	count = printf("%c\n", two);
	printf("count with my printf: %d\n", count);
	count = printf("%c\n", three);
	printf("count with my printf: %d\n", count);
	count = printf("%c\n", four);
	printf("count with my printf: %d\n\n", count);

	ft_printf("TEST FOR STRING\n***********\n\n");
	char a[] = "Hello";
	char b[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
	char c[] = "123456789@@@@@@@@@        $$$$$$)()()(**AGSFDNWnvivbor)))";
	char d[] = "";

	ft_printf("With ft_printf: \n");
	count = ft_printf("%s\n", a);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%s\n", b);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%s\n", c);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%s\n", d);
	printf("count with my printf: %d\n", count);


	ft_printf("With printf: \n");
	count = printf("%s\n", a);
	printf("count with printf: %d\n", count);
	count = printf("%s\n", b);
	printf("count with my printf: %d\n", count);
	count = printf("%s\n", c);
	printf("count with my printf: %d\n", count);
	count = printf("%s\n", d);
	printf("count with my printf: %d\n\n", count);



	ft_printf("TEST FOR DIGIT\n***********\n\n");
	i = 145;
	int j = 0;
	int k = 100000;
	int l = -2147483648;

	ft_printf("With ft_printf: \n");
	count = ft_printf("%d\n", i);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%d\n", j);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%i\n", k);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%i\n", l);
	printf("count with my printf: %d\n\n", count);

	ft_printf("With printf: \n");
	count = printf("%d\n", i);
	printf("count with printf: %d\n", count);
	count = printf("%d\n", j);
	printf("count with printf: %d\n", count);
	count = printf("%i\n", k);
	printf("count with printf: %d\n", count);
	count = printf("%i\n", l);
	printf("count with printf: %d\n\n", count);
 
	ft_printf("TEST FOR HEXADIGIT LOWER\n***********\n\n");
	//same integer example use for digit
	int m = -1;
	int n = 15;
	int o = -101;

	ft_printf("With ft_printf: \n");
	count = ft_printf("%x\n", i);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%x\n", j);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%x\n", k);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%x\n", l);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%x\n", m);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%x\n", n);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%x\n", o);
	printf("count with my printf: %d\n\n", count);


	ft_printf("With printf: \n");
	count = printf("%x\n", i);
	printf("count with printf: %d\n", count);
	count = printf("%x\n", j);
	printf("count with printf: %d\n", count);
	count = printf("%x\n", k);
	printf("count with printf: %d\n", count);
	count = printf("%x\n", l);
	printf("count with printf: %d\n", count);
	count = printf("%x\n", m);
	printf("count with printf: %d\n", count);
	count = printf("%x\n", n);
	printf("count with printf: %d\n", count);
	count = printf("%x\n", o);
	printf("count with printf: %d\n\n", count);

	ft_printf("TEST FOR HEXADIGIT UPPER\n***********\n\n");
	//same integer example use for digit

	ft_printf("With ft_printf: \n");
	count = ft_printf("%X\n", i);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%X\n", j);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%X\n", k);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%X\n", l);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%X\n", m);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%X\n", n);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%X\n", o);
	printf("count with my printf: %d\n\n", count);


	ft_printf("With printf: \n");
	count = printf("%X\n", i);
	printf("count with printf: %d\n", count);
	count = printf("%X\n", j);
	printf("count with printf: %d\n", count);
	count = printf("%X\n", k);
	printf("count with printf: %d\n", count);
	count = printf("%X\n", l);
	printf("count with printf: %d\n", count);
	count = printf("%X\n", m);
	printf("count with printf: %d\n", count);
	count = printf("%X\n", n);
	printf("count with printf: %d\n", count);
	count = printf("%X\n", o);
	printf("count with printf: %d\n\n", count);

	ft_printf("TEST FOR UNSIGNED DIGIT\n*****************\n\n");
	int	p = 42;
	int q = 65535;
	unsigned int r = 100000000;
	unsigned int s = 4294967295;

	ft_printf("With ft_printf: \n");
	count = ft_printf("%u\n", i);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%u\n", j);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%u\n", k);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%u\n", l);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%u\n", o);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%u\n", p);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%u\n", q);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%u\n", r);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%u\n", s);
	printf("count with my printf: %d\n\n", count);

	ft_printf("With printf: \n");
	count = printf("%u\n", i);
	printf("count with printf: %d\n", count);
	count = printf("%u\n", j);
	printf("count with printf: %d\n", count);
	count = printf("%u\n", k);
	printf("count with printf: %d\n", count);
	count = printf("%u\n", l);
	printf("count with printf: %d\n", count);
	count = printf("%u\n", o);
	printf("count with printf: %d\n", count);
	count = printf("%u\n", p);
	printf("count with printf: %d\n", count);
	count = printf("%u\n", q);
	printf("count with printf: %d\n", count);
	count = printf("%u\n", r);
	printf("count with printf: %d\n", count);
	count = printf("%u\n", s);
	printf("count with printf: %d\n\n", count);

	ft_printf("TEST FOR POINTER\n*************\n\n");
	int t = 16;
	int u = 0;
	char v[] = "hello";
	char w[] = "lol";
	void *ptr = NULL;
	unsigned long *ptr1 = NULL;

	ft_printf("With ft_printf: \n");
	count = ft_printf("%p\n", &t);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%p\n", &u);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%p\n", v);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%p\n", w);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%p\n", ptr);
	printf("count with my printf: %d\n", count);
	count = ft_printf("%p\n", ptr1);
	printf("count with my printf: %d\n\n", count);

	ft_printf("With printf: \n");
	count = printf("%p\n", &t);
	printf("count with printf: %d\n", count);
	count = printf("%p\n", &u);
	printf("count with printf: %d\n", count);
	count = printf("%p\n", v);
	printf("count with printf: %d\n", count);
	count = printf("%p\n", w);
	printf("count with printf: %d\n", count);
	count = printf("%p\n", ptr);
	printf("count with printf: %d\n", count);
	count = printf("%p\n", ptr1);
	printf("count with printf: %d\n\n", count);

   return(0);
}
