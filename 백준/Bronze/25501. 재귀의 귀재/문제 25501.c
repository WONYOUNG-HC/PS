#include <stdio.h>
#include <string.h>

int cnt;

int recursion(const char *s, int l, int r) {
  cnt++;
  if (l >= r)
    return 1;
  else if (s[l] != s[r])
    return 0;
  else
    return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char *s) {
  cnt = 0;
  return recursion(s, 0, strlen(s) - 1);
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    char str[1010];
    scanf("%s", str);
    int p = isPalindrome(str);
    printf("%d %lld\n", p, cnt);
  }
}