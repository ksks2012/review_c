#include <stdio.h>
// time O(n)
// space O(1)

void ReplaceBlank(char* string, int length) {
	if (string == NULL || length <= 0)
		return;
	// count blank
	int count = 0;
	for (int i = 0; i < length; i++) {
		if(string[i] == ' ')
			count++;
	}
	printf("%d\n", count);
	int new_len = length + count * 2;
	int cur_length = length;
	while (cur_length >= 0 && new_len > cur_length)
	{
		printf("%d %d\n", new_len, cur_length);
		printf("%c %d\n", string[cur_length], string[new_len]);
		if(string[cur_length] == ' ') {
			string[new_len--] = '0';
			string[new_len--] = '2';
			string[new_len--] = '%';
		}
		else {
			string[new_len--] = string[cur_length];
		}
		cur_length--;
	}
}

int main() {
	char input[20] = "We are Happy!";
	ReplaceBlank(input, 14);
	printf("%s\n", input);
}
